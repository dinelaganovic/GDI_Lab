
// Zadatak 4. Zarotiraj svaki kvadrat oko svoje ose za 45 stepeni
//            koristeci glPushMatrix(); i glPopMatrix();



#include <GL/glut.h>

#include <stdlib.h>



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

    glPolygonMode(GL_FRONT, GL_LINE); //U funkciji za iscrtavanje kvadrata dodajemo
    glPolygonMode(GL_BACK, GL_POLYGON); // funkciju za model poligona
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

//Funkcija koja prikazuje sve sto je nacrtano
void display()
{

     glClear(GL_COLOR_BUFFER_BIT);
     glEnable(GL_LINE_STIPPLE); // Omogucuje rad stilova linija
     glEnable(GL_POLYGON_STIPPLE); // Omogucuje rad stilova poligona

     boja(7.0);
     X_osa();
     glLineWidth(2.0); // Depvljina linije
     glLineStipple(1, 0x0101); // Patern linije
     Y_osa();


     glPushMatrix();                // Za razliku od predhodnog zadatka, glPushMatrix(); i glPopMatrix();
     boja(1.0);//red                // omugogucava da se koordinatni sistem vraca na prvobitno stanje
     glTranslatef(-1.5, 1.5, 0.0);  // i tako svaki objekat se rotira za sebe.
     glRotatef(45.0, 0.0, 0.0, 1.0);
     kvadrat(-1.0,1.0,-1.0,1.0);
     glPopMatrix();

     glPushMatrix();
     boja(2.0);//green
     glTranslatef(1.5, 1.5, 0.0);
     glRotatef(45.0, 0.0, 0.0, 1.0);
     kvadrat(-1.0,1.0,-1.0,1.0);
     glPopMatrix();

     glPushMatrix();
     boja(3.0);//blue
     glTranslatef(1.5, -1.5, 0.0);
     glRotatef(45.0, 0.0, 0.0, 1.0);
     kvadrat(-1.0,1.0,-1.0,1.0);
     glPopMatrix();

     glPushMatrix();
     boja(4.0);//yellow
     glTranslatef(-1.5, -1.5, 0.0);
     glRotatef(45.0, 0.0, 0.0, 1.0);
     kvadrat(-1.0,1.0,-1.0,1.0);
     glPopMatrix();



     glDisable(GL_POLYGON_STIPPLE);
      glFlush();
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(200, 200);
    glutCreateWindow("cetvorougao");
    glOrtho(-6.0, 6.0, -6.0, 6.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
}

//======================
