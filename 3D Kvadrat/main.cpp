/* 1. Uz pomoc funkcije glutWireCube(GLdouble size) napraviti pravougaonik koji
   treba da bude jednake dubine i visine, a 3 puta vece sirine.
   Podignuti kameru tako da se vidi da je objekat 3D
             a) prosirie zadatak tako da se kvadrat rotira oko Z ose
                na strelice
             b)Pomeriti centar rotiranja sa sredine objekta na njegovu ivicu
               sa ciljem formiranja ramena
             c)Kreirati podlakticu koja ce da se nalazu do kraja nadlaktice
               sirine 2, koja ce imati svoj stepen rotacije. ona se rotirana
               strelice: Gore, dole


*/
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

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
         glVertex3f(-100, 0, 0);
         glVertex3f(100, 0, 0);
         glEnd();

}

void Z_osa ()// Funkcija za crtanje Y-ose koordinatnog sistema
{
     glBegin(GL_LINES);
         glVertex3f(0, 0, 100);
         glVertex3f(0, 0, -100);
         glEnd();

}

void Y_osa ()// Funkcija za crtanje Y-ose koordinatnog sistema
{
     glBegin(GL_LINES);
         glVertex3f(0, 100, 0);
         glVertex3f(0, -100, 0);
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

    if(key==114){
                 global_rotate=0; // "r" key
                 local_rotate=0;
                 }
    if(key==97) x_translate-= 0.3; //"a" key
    if(key==100) x_translate+= 0.3; //"d" key

    if(key==119) y_translate+= 0.3; //"w" key
    if(key==115) y_translate-= 0.3; //"s" key




    glutPostRedisplay();// refreshuje sliku posle svake promene stepena
}


// nova callback fukncija za koriscenje strelica
void specialKeys(int key, int x, int y){
     if(key==GLUT_KEY_RIGHT){
                             global_rotate-=6 % 360;
                             }
     if(key==GLUT_KEY_LEFT){
                             global_rotate+=6 % 360;
                             }
     if(key==GLUT_KEY_UP){
                             local_rotate+=6 % 360;
                             }
     if(key==GLUT_KEY_DOWN){
                             local_rotate-=6 % 360;
                             }

     glutPostRedisplay();
}
static void Resize(int width, int height){ // funkcija za promenu prozora
     glViewport(0,0,width, height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     float aspect = (float)width/(float)height; //odnos duzine i visine
     gluPerspective(60, aspect, 0.0, 10.0);
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

void inic(){ // inicijalizacija kamere
     glShadeModel(GL_FLAT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     gluLookAt(-3,1,1,  0,0,0,   0,1,0);
//            cam pos, look at,  where up
}
//Funkcija koja prikazuje sve sto je nacrtano
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);

     glPushMatrix();
     glTranslatef(0.0, 0.0, -10.0);
     boja(7.0);
     X_osa();
     Y_osa();
     Z_osa();
     glPopMatrix();



     glPushMatrix();

       glColor3f(R,G,B);
       glRotatef(global_rotate,0,0,1);
       glTranslatef(-1.5, y_translate, -10);

     glPushMatrix();
       glScalef(2,1,1);
       glutWireCube (1);
     glPopMatrix();

       glTranslatef(-5.0, 0, -10);
       glRotatef(local_rotate,0,0,1);
       glTranslatef(-1.0, 0, -10);

     glPushMatrix();
       glScalef(2,0.7,1);
       glutWireCube (1);
     glPopMatrix();

     glPopMatrix();

      glutSwapBuffers(); // kad se vrse transformacije, ne secka
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH); // kad se vrse transformacije, ne secka
    glutCreateWindow("cetvorougao");
    glutDisplayFunc(display);
    kreirajMeni();
    glutReshapeFunc(Resize);// Funkcija omogucava da se prozor menja a da objekat ostane zadri proporcije
    inic();
    glutIdleFunc(idle);//
    glutKeyboardFunc(kbd);//omugucava rad sa tastaturom
    glutSpecialFunc(specialKeys);
    glutMainLoop();
}
