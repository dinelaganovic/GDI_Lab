/* 1. Zadatal: Kreirati casovnik sa kazaljkama za sekundu, minutu,
  sat koje se krecu 10 puta brze od realnih. Funkcija koja uzima proteklo vreme
  je glutGet(GLUT_ELAPSED_TIME).
     a) Kazaljke se krecu glatko
     b) Kazaljke se krecu u taktu
*/
#include <GL/glut.h>
#include <stdlib.h>

float local_rotate=0; // Globalne promenljive koje cemo da koristimo u dve funkcije:
float global_rotate=0;// u display(); i kbd();
float x_translate=0;
float y_translate=0;
float x_scale=1;
float y_scale=1;


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

void sat()
{
     glBegin(GL_POLYGON);
     int i;
     for (i=0; i<58; i++)
     {

         glColor3f(1.0, 1.0, 1.0 );
         glVertex2f(-0.2,0.0);
         glVertex2f(0.2, 0.0);
         glVertex2f(0.2, 1.0);
         glVertex2f(-0.2,1.0);
         glTranslatef(0.0, 3.0, -15.0);
         glRotatef(i*6, 0.0, 0.0, 1.0);

       }
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

    if(key==103){ x_scale++; y_scale++;} //"g" key
    if(key==102){x_scale--; y_scale--;}//"f" key


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

//Funkcija koja prikazuje sve sto je nacrtano
void display()
{

/* glutGet(GLUT_ELAPSED_TIME) / 1000;<- 1 sekunda
   glutGet(GLUT_ELAPSED_TIME) / 100 ;<- 1 milisekunda
*/

/*
     const float t= glutGet(GLUT_ELAPSED_TIME) / 10.0;
     const float sec=-t*6;            // a) Da bi se kazaljke kretale glato
     const float min=(-t/60)*6;       //    treba da postoji jedna konstanta (t)
     const float h=((-t/60)/60)*30;   //    od koje ce da zavise sve tri kazaljke.
*/

// b) Da bi se kazaljke kretale u taktu, svaka kazaljka mora da je konstanta za sebe

     const double sec=-(glutGet(GLUT_ELAPSED_TIME)/10)*6;          //  *6, jer svaka sekunda se rotira za 6 stepeni
     const double min=-((glutGet(GLUT_ELAPSED_TIME)/10)/60)*6;     //  /60, tj. usporavamo vreme 60 puta u odnosu na sec i to nam predstavlja vreme za 1 min, a zatim *6 jer i kazaljka za min se torita za 6 stepeni
     const double h=-(((glutGet(GLUT_ELAPSED_TIME)/10)/60)/60)*30; //  opet /60, usporavamo vreme 60 puta u odnosu na min i to nam predstavlja vreme za 1 sat, i * 30, jer se kazaljka za sat rotira za 30 stepeni

     glClear(GL_COLOR_BUFFER_BIT);
     sat();
     glPushMatrix();
     glTranslatef(0.0, 0.0, -10.0);
     boja(7.0);
     X_osa();
     glLineWidth(2.0); // Debvljina linije
     glLineStipple(1, 0x0101); // Patern linije
     Y_osa();
     glPopMatrix();


    glPushMatrix();
     boja(1.0);//red
     glTranslatef(x_translate, y_translate, -15.0);   // z= -15 zato sto ako je na 0, u istoj ravni je sa kamerom
     glRotatef(sec, 0.0, 0.0, 1.0);
     kvadrat(-0.25,0.25,7.0,0.0); //sekunde
     glPopMatrix();

     glPushMatrix();
     boja(2.0);//green
     glTranslatef(x_translate, y_translate, -15.0);
     glRotatef(min, 0.0, 0.0, 1.0);
     kvadrat(-0.25,0.25,7.0,0.0); //minuti
     glPopMatrix();

     glPushMatrix();
     boja(3.0);//blue
     glTranslatef(x_translate, y_translate, -15.0);
     glRotatef(h, 0.0, 0.0, 1.0);
     kvadrat(-0.25,0.25,5.0,0.0); //sat
     glPopMatrix();

      glutSwapBuffers(); // kad se vrse transformacije, ne secka
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(200, 200);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH); // kad se vrse transformacije, ne secka
    glutCreateWindow("cetvorougao");
 // glOrtho(-6.0, 6.0, -6.0, 6.0, -1.0, 1.0);//glOrtho vise nije potreban, jer u funkciji resize se koristi gluPerspective();
    glutDisplayFunc(display);
    glutReshapeFunc(Resize);// Funkcija omogucava da se prozor menja a da objekat ostane zadri proporcije
    glutIdleFunc(idle);//
    glutKeyboardFunc(kbd);//omugucava rad sa tastaturom
    glutMainLoop();
}

//============================================================================================

