#include<gl\gl.h>
#include<gl\glut.h>
#include<windows.h>
int x1,y1,x2,y2,dy,dx,step;
float r,g,b;
int first=0;
int flipX = 800, flipY = 500;
void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,flipX,flipY,0.0);
}
void dda_line(void){
    float x,y,xx1=x1,xx2=x2,yy1=y1,yy2=y2,DX,DY,steps,Xinc,Yinc;
    x=x1,y=y1;
    DY = y2-y1;
    DX = x2-x1;

    if(DY>DX){
        steps = DY;
    }
    else{
        steps = DX;
    }
    Xinc = DX/steps;
    Yinc = DY/steps;
    x = x1;
    y = y1;
    glPointSize(2);
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    for(int i=1;i<=steps;i++){
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        glFlush();
        x=x+Xinc;
        y=y+Yinc;
        printf("x=%.2f,y=%.2f\n",x,y);
    }
}
void mouse (int button,int state,int x, int y ){
    int X=x;
    int Y=y;
    if (button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if (first == 0){
            x1=X;
            y1=Y;
            first++;
        }else{
            x2=X;
            y2=Y;
            first=0;
            dda_line();
        }
    }
}
void keyboard(unsigned char key,int x,int y){
    if(key == 'r'){
        r = 1;
        g = 0;
        b = 0;
    }
    if(key == 'g'){
        r = 0;
        g = 1;
        b = 0;
    }
    if(key == 'b'){
        r = 0;
        g = 0;
        b = 1;
    }
    if(key == 'y'){
        r = 1;
        g = 1;
        b = 0;
    }
    if(key == 'o'){
        r = 1;
        g = 0.5;
        b = 0;
    }
    if(key == '0'){
        r = 0;
        g = 0;
        b = 0;
    }
}
void show (void){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(flipX,flipY);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BasicOpenGL");
    myinit();
    glutDisplayFunc(show);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
