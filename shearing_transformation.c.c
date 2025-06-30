#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>
#define PI 3.14159265
int w=600,h=800;
void myinit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);gluOrtho2D(-w,h,-w,h);
}
void drawline(int X1,int Y1,int X2,int Y2){
    glBegin(GL_LINES);
    glVertex2i(X1,Y1);
    glVertex2i(X2,Y2);
    glEnd();
}
int shearX(int x,int shx,int y){
    return x+shx*y;
}
int shearY(int y,int shy,int x){
    return y+shy*x;
}
void showshearing(){
    int x1,y1,x2,y2,shx=2,shy=1;
    glClear(GL_COLOR_BUFFER_BIT);
    //line1
    x1=50,y1=50,x2=150,y2=50;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //shearing
    glColor3f(1.0,0.0,0.0);
    x1=shearX(x1,shx,y1);
    y1=shearY(y1,shy,x1);
    x2=shearX(x2,shx,y2);
    y2=shearY(y2,shy,x2);
    drawline(x1,y1,x2,y2);
    glFlush();
    //line 2
    x1=50,y1=50,x2=50,y2=150;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //shearing
    glColor3f(1.0,0.0,0.0);
    x1=shearX(x1,shx,y1);
    y1=shearY(y1,shy,x1);
    x2=shearX(x2,shx,y2);
    y2=shearY(y2,shy,x2);
    drawline(x1,y1,x2,y2);
    glFlush();
    //line 3
    x1=150,y1=50,x2=150,y2=150;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //shearing
    glColor3f(1.0,0.0,0.0);
    x1=shearX(x1,shx,y1);
    y1=shearY(y1,shy,x1);
    x2=shearX(x2,shx,y2);
    y2=shearY(y2,shy,x2);
    drawline(x1,y1,x2,y2);
    glFlush();

    //line 4
    x1=50,y1=150,x2=150,y2=150;
    glColor3f(0.0,0.0,0.0);
    drawline(x1,y1,x2,y2);
    glFlush();
    //shearing
    glColor3f(1.0,0.0,0.0);
    x1=shearX(x1,shx,y1);
    y1=shearY(y1,shy,x1);
    x2=shearX(x2,shx,y2);
    y2=shearY(y2,shy,x2);
    drawline(x1,y1,x2,y2);
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Shearing");
    myinit();
    glutDisplayFunc(showshearing);
    glutMainLoop();
    return 0;
}
