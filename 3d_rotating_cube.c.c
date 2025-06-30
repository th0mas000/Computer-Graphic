#include<gl\gl.h>
#include<gl\glu.h>
#include<gl\glut.h>
float x,y,z;
GLfloat xRotated,yRotated,zRotated;
void draw (void);

void idle(void){
    xRotated+=0.01;
    yRotated+=0.01;
    draw();
}
void draw(){
    x=y=z=1;
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-4.0,-2.0,-6.0);

    glColor3f(1.0,1.0,0.0);

    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);

    //Button
    glBegin(GL_LINE_LOOP);
    glVertex3f(x,-y,z);//p1
    glVertex3f(x,-y,-z);//p2
    glVertex3f(-x,-y,-z);//p3
    glVertex3f(-x,-y,z);//p4
    glEnd();

    //Left
    glBegin(GL_LINE_LOOP);
    glVertex3f(-x,-y,z);//p1
    glVertex3f(-x,-y,-z);//p2
    glVertex3f(-x,y,-z);//p3
    glVertex3f(-x,y,-z);//p4
    glEnd();

    //Back
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x,-y,-z);//p1
    glVertex3f(-x,-y,-z);//p2
    glVertex3f(-x,y,-z);//p3
    glVertex3f(-x,y,-z);//p4
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x,-y,z);//p1
    glVertex3f(x,-y,-z);//p2
    glVertex3f(-x,y,-z);//p3
    glVertex3f(-x,y,-z);//p4
    glEnd();


    glFlush();
}

void reshape(int x, int y){
    if(y==0||x==0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,(GLdouble)x/(GLdouble)y,0.6,40);
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(750,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BasicOpenGL");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
