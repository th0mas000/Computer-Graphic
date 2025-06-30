#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,1600.0,0.0,1600.0);
}

void bresenhame(float x1, float y1, float x2, float y2){
    float dx,dy,p,x,y;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    x=x1;
    y=y1;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    p = 2*dy-dx;
    while(x<=x2){
        glBegin(GL_POINTS);
        glVertex2d(x,y);
        x++;
        if(p<0){
            p = p + 2*dy;
        }else{
            if(y1<y2){
                y++;
            }else{
                y--;
            }
            p = p + 2*dy - 2*dx;
        }
    }
}


void DDALab(float x1, float y1, float x2, float y2){
    float dx = (x2-x1);
    float dy = (y2-y1);
    float step,xInc,yInc,x,y;

    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }else step = abs(dy);

    xInc = dx/(float)step;
    yInc = dy/(float)step;

    x=x1;
    y=y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
    glFlush();

    for(int i=0;i<step;i++){
        x = x + xInc;
        y = y + yInc;
        glBegin(GL_POINTS);
        glVertex2d(round(x),round(y));

    }
}

void plotQ(int x,int y,int xcenter,int ycenter){
    glVertex2d(xcenter+x,ycenter+y);//q1
    glVertex2d(xcenter+y,ycenter+x);//q2
    glVertex2d(xcenter+y,ycenter-x);//q3
    glVertex2d(xcenter+x,ycenter-y);//q4
    glVertex2d(xcenter-x,ycenter-y);//q5
    glVertex2d(xcenter-y,ycenter-x);//q6
    glVertex2d(xcenter-y,ycenter+x);//q7
    glVertex2d(xcenter-x,ycenter+y);//q8


    //Lab1
    //glVertex2d(xcenter+x,ycenter+y);
    //glVertex2d(xcenter+y,ycenter+x);
    //glVertex2d(xcenter-y,ycenter+x);
    //glVertex2d(xcenter-x,ycenter+y);


    //Lab2
    //glVertex2d(xcenter+x,ycenter+y);
    //glVertex2d(xcenter-x,ycenter+y);
    //glVertex2d(xcenter+x,ycenter-y);
   // glVertex2d(xcenter-x,ycenter-y);


}

void midpointCircle(int xcenter,int ycenter,int r){
    //int xcenter=200,ycenter=200,r=140;
    int x=0,y=r;
    int p=1-r;
    glColor3f(1.0,1.0,1.0);
    glPointSize(1);
    glBegin(GL_POINTS);
    plotQ(x,y,xcenter,ycenter);
    glEnd();
    while(x<y){
        x++;
        if(p<0){
            p=p+2*(x)+1;
        }
        else{
            y--;
            p=p+2*(x)+1-2*(y);
        }
        glBegin(GL_POINTS);
        plotQ(x,y,xcenter,ycenter);

    }


}



void show(void){
midpointCircle(200,200,140);
midpointCircle(200,200,110);
midpointCircle(200,200,80);
midpointCircle(200,200,50);
midpointCircle(200,200,20);

midpointCircle(500,500,140);
midpointCircle(500,500,110);
midpointCircle(500,500,80);
midpointCircle(500,500,50);
midpointCircle(500,500,20);

midpointCircle(800,200,140);
midpointCircle(800,200,110);
midpointCircle(800,200,80);
midpointCircle(800,200,50);
midpointCircle(800,200,20);
bresenhame(200,200,500,500);
bresenhame(500,500,800,200);
DDALab(800,200,200,200);

//DDALab(100,102,300,298);
//DDALab(300,102,100,298);
glEnd();
glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BasicOpenGL");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
