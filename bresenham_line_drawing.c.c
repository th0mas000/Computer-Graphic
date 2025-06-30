#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,600.0,0.0,600.0);
}
void Bresenhamline(float x1, float y1, float x2, float y2){
    float dx,dy,p,x,y;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1);

    x = x1;
    y = y1;
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    p=2*dx-dy;
    if (x1 != x2){
        while (x<=x2){
            glBegin(GL_POINTS);
            glVertex2d(x,y);
            x++;
            if (p<=0){
                p = p+2*dy;
            }
            else{
                if (y1 < y2) y++;
                else y--;
                p=p+2*dy-2*dx;
            }
        }
    }else{
       while (y<=y2){
            glBegin(GL_POINTS);
            glVertex2d(x,y);
            y++;
       }

    }
}
void show (void){
    Bresenhamline(20,30,400,150);
    Bresenhamline(20,150,400,30);

    Bresenhamline(20,30,20,150);
    Bresenhamline(400,30,400,150);

    Bresenhamline(20,30,400,30);
    Bresenhamline(20,152,400,152);

    // image 2
    Bresenhamline(20,250,400,250);

    Bresenhamline(20,250,60,280);
    Bresenhamline(20,250,60,220);
    Bresenhamline(60,220,60,280);

    Bresenhamline(400,250,430,280);
    Bresenhamline(400,250,430,220);

    Bresenhamline(350,250,430,280);
    Bresenhamline(350,250,430,220);

    // image 3

    Bresenhamline(290,350,290,400);
    Bresenhamline(300,350,300,400);
    Bresenhamline(290,350,300,350);

    Bresenhamline(270,402,320,402);
    Bresenhamline(270,407,320,407);
    Bresenhamline(270,402,270,407);
    Bresenhamline(320,402,320,407);

    Bresenhamline(280,407,280,550);
    Bresenhamline(310,407,310,580);

    Bresenhamline(280,550,310,580);


    glEnd();
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(500,100);
    glutCreateWindow("LAB_Bresenham’s Line");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
