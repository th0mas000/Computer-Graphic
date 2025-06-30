#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>
#define PI 3.14

// ROTATED
void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-400.0,600.0,-400.0,600.0);
}
void drawline(float x1,float y1,float x2,float y2){
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
float rotateWiseX(float sita,float x,float y){
    float val = PI/180;
    float xnew = (x*cos(sita*val))-(y*sin(sita*val));
    return xnew;
}
float rotateWiseY(float sita,float x,float y){
    float val = PI/180;
    float ynew = (x*sin(sita*val))+(y*cos(sita*val));
    return ynew;
}
void showRotated(void){
    glClear(GL_COLOR_BUFFER_BIT);
    float sita = 180;
    float x1,y1,x2,y2,x1new,y1new,x2new,y2new;

    //line1
    x1=100,y1=100,x2=200,y2=100;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();

    glColor3f(1.0,0.0,0.0);
    x1new = rotateWiseX(sita,x1,y1);
    y1new = rotateWiseY(sita,x1,y1);
    x2new = rotateWiseX(sita,x2,y2);
    y2new = rotateWiseY(sita,x2,y2);
    drawline(x1new,y1new,x2new,y2new);
    glFlush();

    //line2
    x1=100,y1=100,x2=200,y2=300;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();

    glColor3f(1.0,0.0,0.0);
    x1new = rotateWiseX(sita,x1,y1);
    y1new = rotateWiseY(sita,x1,y1);
    x2new = rotateWiseX(sita,x2,y2);
    y2new = rotateWiseY(sita,x2,y2);
    drawline(x1new,y1new,x2new,y2new);
    glFlush();

    //line3
    x1=200,y1=100,x2=200,y2=300;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();

    glColor3f(1.0,0.0,0.0);
    x1new = rotateWiseX(sita,x1,y1);
    y1new = rotateWiseY(sita,x1,y1);
    x2new = rotateWiseX(sita,x2,y2);
    y2new = rotateWiseY(sita,x2,y2);
    drawline(x1new,y1new,x2new,y2new);
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Rotated");
    myinit();
    glutDisplayFunc(showRotated);
    glutMainLoop();
    return 0;
}
