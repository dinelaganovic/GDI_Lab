/* 2. Napraviti funkciju koja ce pritiskom na desni klik misa otvoriti meni za
   promenu boje kvadrata
*/
#include <GL/glut.h>
#include <stdlib.h>

float local_rotate=0; // Globalne promenljive koje cemo da koristimo u dve funkcije:
float global_rotate=0;// u display(); i kbd();
float x_translate=0;
float y_translate=0;
// Boje za meni
float R=1;
float G=0;
float B=0;

void X_osa ()// Funkcija za crtanje X-ose koordinatnog sistema
{
     glBegin(GL_LINES);
         glVertex2f(-10, 0);
         glVertex2f(10, 0);
         glEnd();

}

void Y_osa ()// Funkcija za crtanje Y-ose koordinatnog sistema
{
     glBegin(GL_LINES);
         glVertex2f(0, 10);
         glVertex2f(0, -10);
         glEnd();

}



//Funkcija sa parametrima koja crta kvadrat
void kvadrat (GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2)
{

      glBegin(GL_POLYGON);

         glVertex2f(x1, y1);
         glVertex2f(x2, y1);
         glVertex2f(x2, y2);
         glVertex2f(x1, y2);
         glEnd();

}


//Funkcija koja boji poligon na osnovu unetog broja
void boja (GLfloat b)
{

     if (b==1)
        glColor3f(1.0, 0.0, 0.0 );//Red
     if (b==2)
        glColor3f(0.0, 1.0, 0.0 );//Green
     if (b==3)
        glColor3f(0.0, 0.0, 1.0 );//Blue
     if (b==4)
        glColor3f(1.0, 1.0, 0.0 );//Yellow
     if (b==5)
        glColor3f(1.0, 0.0, 1.0 );//Magenta
     if (b==6)
        glColor3f(0.0, 1.0, 1.0 );//Cyan
     if (b==7)
        glColor3f(1.0, 1.0, 1.0 );//White

}

// Callback funkcija za tastaturu
void kbd(unsigned char key, int x, int y) {
    if (key==27) exit(0);// izlazi iz programa

    if(key==101) local_rotate--; // "e" key
    if(key==113) local_rotate++; // "q" key

    if(key==43) global_rotate--; // "+" key
    if(key==45) global_rotate++; // "-" key

    if(key==97) x_translate-= 0.3; //"a" key
    if(key==100) x_translate+= 0.3; //"d" key

    if(key==119) y_translate+= 0.3; //"w" key
    if(key==115) y_translate-= 0.3; //"s" key

    glutPostRedisplay();// refreshuje sliku posle svake promene stepena
}

static void Resize(int width, int height){ // funkcija za promenu prozora
     glViewport(0,0,width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     float aspect = (float)width/(float)height; //odnos duzine i visine
     gluPerspective(60, aspect, 0.0, 10.0);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     }

static void  idle(void)
{
    glutPostRedisplay();
}

//ovu funkciju prosledjujemo u glutCreateMenu();
void menu (int b)
{
     if(b==1)
     {
        R=1;
        G=0;
        B=0;
     }
     if(b==2)
     {
        R=0;
        G=2;
        B=0;
     }
     if(b==3)
     {
        R=0;
        G=0;
        B=1;
     }
}

// ovu funkciju moramo da pozovemo u main
void kreirajMeni()
{
     glutCreateMenu(menu);
     glutAddMenuEntry("Crvena",1);
     glutAddMenuEntry("Zelena",2);
     glutAddMenuEntry("Plava",3);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//Funkcija koja prikazuje sve sto je nacrtano
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);
     glPushMatrix();
     glTranslatef(0.0, 0.0, -10.0);
     boja(7.0);
     X_osa();
     glLineWidth(2.0); // Debvljina linije
     glLineStipple(1, 0x0101); // Patern linije
     Y_osa();
     glPopMatrix();

     glPushMatrix();
     glTranslatef(x_translate, y_translate, -15.0);
     glColor3f(R,G,B);
     kvadrat(-1.0,1.0,-1.0,1.0);
     glPopMatrix();

      glutSwapBuffers(); // kad se vrse transformacije, ne secka
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(200, 200);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH); // kad se vrse transformacije, ne secka
    glutCreateWindow("cetvorougao");
    glutDisplayFunc(display);
    kreirajMeni();
    glutReshapeFunc(Resize);// Funkcija omogucava da se prozor menja a da objekat ostane zadri proporcije
    glutIdleFunc(idle);//
    glutKeyboardFunc(kbd);//omugucava rad sa tastaturom
    glutMainLoop();
}

//============================================================================================

