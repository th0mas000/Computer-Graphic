#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

//ข้อ 2.1
//Q1/Q4 and Q2/Q3

void plot (int xc,int yc,int x,int y){
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc-x,yc+y);//Q4
}
void plot1 (int xc,int yc,int x,int y){
    glVertex2d(xc+x,yc-y);//Q2
    glVertex2d(xc-x,yc-y);//Q3
}

// ข้อ 2.2
//Q1/Q2 and Q3/Q4
/*
void plot (int xc,int yc,int x,int y){
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc+x,yc-y);//Q2
}
void plot1 (int xc,int yc,int x,int y){
    glVertex2d(xc-x,yc-y);//Q3
    glVertex2d(xc-x,yc+y);//Q4
}
*/

void ellipse(int rx,int ry,int xc, int yc){

    int rx2=rx*rx;
    int ry2=ry*ry;
    int tworx2=2*rx2;
    int twory2=2*ry2;
    int x=0,y=ry;

    //R1
    int p=ry2-(rx2*ry)+(0.25*rx2);
    int px=0;
    int py=tworx2*ry;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();

    while(px<py){
        x++;
        px=px+twory2;
        if(p<0){
            p=p+twory2*x+ry2;
        }else{
            y--;
            p=p+twory2*x+ry2-tworx2*y;
            py=py-tworx2;
        }
        glBegin(GL_POINTS);
        plot(xc,yc,x,y);
        glEnd();
    }
     glFlush();

    //R2
    p=ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2;
    while(y>0){
        y--;
        if(p>0){
            p=p+rx2-tworx2*y;
        }else{
            x++;
            p=p+twory2*x-tworx2*y+rx2;
        }
        glBegin(GL_POINTS);
        plot(xc,yc,x,y);
       // glEnd();
    }
     //glFlush();

}

void ellipse1(int rx,int ry,int xc, int yc){

    int rx2=rx*rx;
    int ry2=ry*ry;
    int tworx2=2*rx2;
    int twory2=2*ry2;
    int x=0,y=ry;

    //R1
    int p=ry2-(rx2*ry)+(0.25*rx2);
    int px=0;
    int py=tworx2*ry;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();

    while(px<py){
        x++;
        px=px+twory2;
        if(p<0){
            p=p+twory2*x+ry2;
        }else{
            y--;
            p=p+twory2*x+ry2-tworx2*y;
            py=py-tworx2;
        }
        glBegin(GL_POINTS);
        plot1(xc,yc,x,y);
        glEnd();
    }
    glFlush();

    //R2
    p=ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2;
    while(y>0){
        y--;
        if(p>0){
            p=p+rx2-tworx2*y;
        }else{
            x++;
            p=p+twory2*x-tworx2*y+rx2;
        }
        glBegin(GL_POINTS);
        plot1(xc,yc,x,y);
        //glEnd();
    }
     //glFlush();

}

void show(void){
    //ข้อ 2.1
    ellipse(80,220,300,100);
    ellipse1(80,220,300,540);

    //ข้อ 2.2
    //ellipse(260,80,40,300);
    //ellipse1(260,80,560,300);

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
