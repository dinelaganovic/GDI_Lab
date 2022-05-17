/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

      void kvadrat (GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2)
{
         glBegin(GL_POLYGON);
         glVertex2f(x1, y1);
	     glVertex2f(x2, y1);
         glVertex2f(x2, y2);
         glVertex2f(x1, y2);
         glEnd();
}
    void trougao (GLfloat x1, GLfloat x2,GLfloat x3, GLfloat y1, GLfloat y2, GLfloat y3)
{
         glBegin(GL_TRIANGLES);
         glVertex2f(x1, y1);
	     glVertex2f(x2, y2);
         glVertex2f(x3, y3);

         glEnd();
}
void boje (GLfloat b) //Funkcija koja boji poligon na osnovu unetog broja
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

static void display(void)
{
         glClear(GL_COLOR_BUFFER_BIT);
         glColor3f(1.0, 0.0, 0.0 );
         kvadrat(0.0,2.0,0.0,2.0);
         glColor3f(1.0, 1.0, 1.0 );
         trougao(0.0,0.0,2.0,0.0,2.0,2.0);
         glFlush();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(200, 200);
    glutCreateWindow("trougao");
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
glutDisplayFunc(display);
    glutMainLoop();

}
