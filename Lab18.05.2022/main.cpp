#include<fstream>
#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
#include<GL/freeglut.h>
#include<string>
#include <time.h>
#include <sys/timeb.h>
#define WIDTH 900
#define HEIGHT 600

GLfloat x = 0.20, z = 0.25, x2 = -0.20, z2 = -0.25, txp = 0.100, tzp = 0.110, txm = -0.100, tzm = -0.110, ty = -0.015, dx = 0.030, PI = 3.14;
void table();
void face();
void room();
void plant();
double second_angle = 0, minute_angle = 0, hour_angle = 0;
GLuint text_2d;
GLfloat texBoard[8][8][4];

GLuint texture;
GLuint texture1;

void drawLine(GLfloat x, GLfloat y, GLfloat angle) {
	glVertex3f(x, x, -0.39f);
	glVertex3f(y * cos(angle), y * sin(angle), -0.39f);
}
GLfloat T[8][3] = {
    {0.020, -0.015, 0.025},
    {-0.020, -0.015, 0.025},
    {-0.020, -0.015, -0.025},
    {0.020, -0.015, -0.025},

    {-0.020, 0.015, 0.025},
    {-0.020, 0.015, -0.025},
    {0.020, 0.015, 0.025},
    {0.020, 0.015, -0.025}
};

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}


void lamps() {
    GLfloat ram1[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ram1);
    glPushMatrix();

    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, -0.29);
    glColor3f(0, 0, 0);
    glutSolidCylinder(0.015, 0.05, 10, 10);
    glColor3f(0.36, 0.25, 0.2);
    glutSolidCylinder(0.0025, -0.1, 10, 10);
    glPopMatrix();

    GLfloat lam[] = { 0.6, 0.2, 0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.19, 0.28, 0.1);
    glColor3f(1, 1, 1);
    glutSolidCylinder(0.040, 0.09, 10, 10);
    glColor3f(0.36, 0.25, 0.2);
    glutSolidCylinder(0.005, -0.2, 10, 10);
    glPopMatrix();

    GLfloat clo[] = { 1,1,1,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, clo);
    glPushMatrix();
    glRotated(90, 0.05, -0.01, 0.0);
    glTranslatef(-0.220, -0.24, 0.13);
    glutSolidCylinder(0.030, 0.01, 9, 10);
    glPopMatrix();
}
//trava
void plant() {
    GLfloat lam[] = { 1, 1, 0.58,1 };
    glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, lam);
    glPushMatrix();
    glTranslatef(-0.19, -0.04, 0.30);
    glScalef(0.09,0.11, 0.078);
    glutSolidCube(1);
    glPopMatrix();

    GLfloat lam1[] = { 0, 1, 0.5,1 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, lam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glTranslatef(-0.19, -0.30, -0.0);
    glutSolidCone(0.04, 0.05, 11, 11);
    glPopMatrix();
}
void crtajkrevet(){
    glPushMatrix();
    glColor3f(0.90,0.45,0.13);
    glTranslatef(0.2, -0.10, 0.10);
    glScalef(2.2, 0.9, 5);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.19, -0.06, -0.15);
    glScalef(2.5, 1.0, 0.05);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.19, -0.08, 0.35);
    glScalef(2.5, 1.0, 0.05);
    glutSolidCube(0.1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0,1,0);
    glTranslatef(-0.09, -0.06, 0.32);
    glScalef(5.5, 1.50, 0.05);
    glutSolidCube(0.1);
    glPopMatrix();
}
void tepih(){

    glTranslatef(-0.0003, -0.1, -0.00099);
    glRotatef(90, 1,0,0);
    glScalef(2.5, 4.0, 0.01);
    glRotatef(0, 1,0,0);
    glutSolidCube(0.15);
    glPopMatrix();
}
void ostalo(){
    GLfloat cam[] = { 0.90,0.45,0.18 ,1 };
    GLfloat cam1[] = { 0.00, 0.35, 0.40,1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam);
    glPushMatrix();

    glRotatef(-90, 1, 0, 0);
    glRotatef(-180, 0, 0, 1);
    glTranslatef(-0.05, -0.40, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.10);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cam1);
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-180, 0, 0, 1);
    glTranslatef(-0.05, -0.392, 0.15);
    glScalef(3, 0.1, 2);
    glutSolidCube(0.09);
    glPopMatrix();
    crtajkrevet();
    //komp i sto
    glColor3f(0.90,0.45,0.13);
    glPushMatrix();
    glTranslatef(-0.3, -0.10, 0.12);
    glScalef(1.6, 3.5,2.5);
    glutSolidCube(0.1);
    glPopMatrix();
    glColor3f(0.99,0.5,0.13);
    glPushMatrix();
    glRotatef(90, 1,0,0);
    glTranslatef(-0.29, 0.131, -0.089);
    glScalef(1.5, 3.0, 0.2);
    glutSolidCube(0.1);
    glPopMatrix();

    GLfloat cm[] = { 0.15,0.15,0.15 ,1 };
    //GLfloat cm1[] = { 1,1,1 ,1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, cm);

    glPushMatrix();
    glRotatef(100, 0, 0, 1);
    glTranslatef(0.05, 0.2, 0.14);
    glScalef(4, 0, 5);
    glutSolidCube(0.03);
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glRotatef(-90, 0, 0, 1);
    glTranslatef(0.15, -0.29, 0.15);
    glScalef(4, 0.4, 3);
    glutSolidCube(0.03);
    glPopMatrix();
}
void face() {
    lamps();
    ostalo();
}

void table() {
    plant();
    face();
    //tepih();
    glutSwapBuffers();
}

GLfloat room_vertices[7][3] = {
    {-0.350, -0.115, 0.400},
    {-0.350, -0.115, -0.400},
    {0.400, -0.115, -0.400},
    {0.400, -0.115, 0.400},

    {-0.350, 0.300, -0.400},
    {-0.350, 0.300, 0.400},
     {0.400, 0.300, -0.400}

};

GLfloat room_normal[3][3] = {
    {0.050, -0.115, 0},
    {-0.350, 0.115,0},
    {0.050, 0.115, -0.400}
};
void room() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //boje zida
    GLfloat wall[3][4] = { { 0.90,0.45,0.13,1 },
                            {0.90,0.45,0.13,1},
                            {0.90,0.45,0.13,1} };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, wall[0]);
    glBegin(GL_QUADS);

    glColor3f(1.0, 0.0, 0.0);
    glNormal3fv(room_normal[0]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[3]);

    glColor3f(0.0, 0.0, 1.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[1]);
    glNormal3fv(room_normal[1]);
    glVertex3fv(room_vertices[0]);
    glVertex3fv(room_vertices[1]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[5]);

    glColor3f(0.0, 1.0, 0.0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wall[2]);
    glNormal3fv(room_normal[2]);
    glVertex3fv(room_vertices[4]);
    glVertex3fv(room_vertices[6]);
    glVertex3fv(room_vertices[2]);
    glVertex3fv(room_vertices[1]);
    glEnd();

    //////
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture);
    glBegin(GL_POLYGON);
        //plafon
         glColor3f(1.0,1.0,1.0);
         glTexCoord2d(0.0, 0.0);glVertex3f(-0.3,-0.1,-0.3);
         glTexCoord2d(2.0, 0.0);glVertex3f(-0.3,-0.1,0.30);
         glTexCoord2d(2.0, 2.0);glVertex3f(0.2,-0.1,0.30);
         glTexCoord2d(0.0, 2.0);glVertex3f(0.2,-0.1,-0.3);

        glEnd();
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D,texture1);
    glBegin(GL_POLYGON);
        //levi zid
         glColor3f(1.0,1.0,1.0);
         glTexCoord2d(0.0, 0.0);glVertex3f(-0.29,0.03,0.07);
         glTexCoord2d(0.0, 2.0);glVertex3f(-0.29,0.2,0.07);
         glTexCoord2d(2.0, 2.0);glVertex3f(-0.29,0.2,0.23);
         glTexCoord2d(2.0, 0.0);glVertex3f(-0.29,0.03,0.23);
        glEnd();
    glPopMatrix();

    table();
}

void lights() {

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    GLfloat light2_pos[] = { 0, 0.2, 0, 0.0f };
    GLfloat light1_pos[] = { -0.400, -0.115, 0.400 , 0.0f };
    GLfloat diffuse0[] = { 1, 1, 1, 1.0 };
    GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse2[] = { 0.5, 0.5, 0.0, 1.0 };
    GLfloat ambient0[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat specular0[] = { 2.0, 6.0, 4.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION,  room_vertices[0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient0);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular0);

    glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular0);


}
//inicijalizacija programa
void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Lab vezba");
    lights();
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    gluPerspective(30.0, (float)WIDTH / (float)HEIGHT, 1.0,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    GLuint text_2d;
    GLfloat texBoard[8][8][4];
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &text_2d);
    glBindTexture(GL_TEXTURE_1D, text_2d);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, 8, 0, GL_RGBA, GL_FLOAT, texBoard);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glEnable(GL_DEPTH_TEST);

}
int count = 0;
void Perspec_change(int key, int x, int y) {


    switch (key) {

    case GLUT_KEY_UP:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(2.5, 1, 1.5, 0, 0, 0, 0, 1, 0);
               break;
    case GLUT_KEY_LEFT:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
                break;
    case GLUT_KEY_RIGHT:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(0.8, 0.8, -0.5, 0, 0, 0, 0, 1, 0);
                break;
    case GLUT_KEY_DOWN:
                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();
                gluLookAt(0.5, 3, -0.3, 0, 0, 0, 0, 1, 0);
                break;
        }
    glutPostRedisplay();

}
void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{

    init(argc, argv);
    glutDisplayFunc(room);
    glutSpecialFunc(Perspec_change);
    glutKeyboardFunc(lightoff);
    glClearColor(0,0,0,1);
    //glutMainLoop();
    texture=LoadTexture("./textures/texture.raw",256, 256);
    texture1=LoadTexture("./textures/texture2.raw",256, 256);

    glutMainLoop();
    return 0;
}
