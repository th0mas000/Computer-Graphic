#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-400.0,600.0,-400.0,600.0);
}
int reflectX(int y){
    return y*-1;
}
int reflectY(int x){
    return x*-1;
}
void drawline(float x1,float y1,float x2,float y2){
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}
void showReflection(){
    int x1,y1,x2,y2;

    glClear(GL_COLOR_BUFFER_BIT);
    //line1
    x1=50,y1=100,x2=250,y2=100;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //Reflection X
    glColor3f(1.0,0.0,0.0);
    y1=reflectX(y1);
    y2=reflectX(y2);
    drawline(x1,y1,x2,y2);
    glFlush();
    //line2
    x1=50,y1=100,x2=150,y2=300;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //Reflection X
    glColor3f(1.0,0.0,0.0);
    y1=reflectX(y1);
    y2=reflectX(y2);
    drawline(x1,y1,x2,y2);
    glFlush();
    //line3
    x1=250,y1=100,x2=150,y2=300;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //Reflection X
    glColor3f(1.0,0.0,0.0);
    y1=reflectX(y1);
    y2=reflectX(y2);
    drawline(x1,y1,x2,y2);
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Reflection");
    myinit();
    glutDisplayFunc(showReflection);
    glutMainLoop();
    return 0;
}
