#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,600.0,0.0,600.0);
}
//****************// Note สูตร DDA // ***************//
    // (x1,y1) = (5,4) -> (x2,y2) = (12,7)
    // deltaX = |12-5| = 7
    // deltaY = |7-4| = 3
    // step = 7
    // x + 1 และ  y + 7/3
// ตาราง
/*
    step   x    y
    0      5    4
    1      6    4.4
    2      7    4.8
    3      8    5.2
    4      9    5.6
    5      10   6.0
    6      11   6.4
    7      12   6.8
*/
void DDAline(double X1,double Y1,double X2,double Y2){
    float dx = X2-X1;
    float dy = Y2-Y1;
    float steps,xInc,yInc,x,y;

    if (abs(dx)>abs(dy)) steps = abs(dx);
    else steps = abs(dy);

    xInc = dx/steps;
    yInc = dy/steps;

    x=X1;
    y=Y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glPointSize(1.0);

    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
    glFlush();

    for(int i=0;i<steps;i++){
        x=x+xInc;
        y=y+yInc;
        glBegin(GL_POINTS);
        //Sleep(10);
        glVertex2d(round(x),round(y));
    }
}
void show (void){

  //สามเหลี่ยม แบบ 1
  DDAline(50,20,150,100);
  DDAline(50,20,150,20);
  DDAline(150,20,150,100);

  // 4 เหลี่ยม
  DDAline(250,100,350,100);
  DDAline(250,20,350,20);

  DDAline(250,20,250,100);
  DDAline(350,20,350,100);

  // 5 เหลี่ยม
  DDAline(430,60,430,150);
  DDAline(550,150,550,60);
  DDAline(430,150,490,200);
  DDAline(490,200,550,150);
  DDAline(430,60,550,60);

  // 6 เหลี่ยม
  DDAline(20,250,80,200);
  DDAline(80,200,140,250);

  DDAline(20,250,20,350);
  DDAline(140,250,140,350);

  DDAline(20,350,80,400);
  DDAline(80,400,140,350);

  // 8 เหลี่ยม
  DDAline(200,250,200,350);
  DDAline(340,250,340,350);

  DDAline(240,200,300,200);
  DDAline(240,400,300,400);

  DDAline(200,350,240,400);
  DDAline(200,250,240,200);

  DDAline(300,400,340,350);
  DDAline(340,250,300,200);

   // สามเหลี่ยม แบบ 2
  DDAline(360,250,390,350);
  DDAline(390,350,420,250);
  DDAline(360,250,420,250);

  // รูป 6 เหลี่ยม แบบ 2
  DDAline(20,400,20,500);
  DDAline(140,400,140,500);

  DDAline(20,400,80,450);
  DDAline(80,450,140,400);

  DDAline(20,500,80,460);
  DDAline(80,460,140,500);


  glEnd();
  glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(500,100);
    glutCreateWindow("LABL_DDA");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
