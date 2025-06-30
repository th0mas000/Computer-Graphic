#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}
void drawPoints(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_POINTS);
    glVertex2i(50,15);
    glVertex2i(90,145);
    glEnd();
    glFlush();


}
void drawLines(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINES);
    glVertex2i(50,15);
    glVertex2i(90,145);
    glEnd();
    glFlush();


}

void drawLinesStrip(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINE_STRIP);
    glVertex2i(20,10);
    glVertex2i(50,10);
    glVertex2i(20,80);
    glVertex2i(50,80);
    glEnd();
    glFlush();

}

void drawLinesLoop(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20,10);
    glVertex2i(50,10);
    glVertex2i(20,80);
    glVertex2i(50,80);
    glEnd();
    glFlush();

}

void drawRec(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    int p1[]={50,100};
    int p2[]={200,100};
    int p3[]={200,250};
    int p4[]={50,250};
    glBegin(GL_POLYGON);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glEnd();
    glFlush();
}

void drawTri(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    int p1[]={200,100};
    int p2[]={400,100};
    int p3[]={550,300};
    glBegin(GL_POLYGON);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glEnd();
    glFlush();
}

void drawPoly(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    int p1[]={50,300};
    int p2[]={200,100};
    int p3[]={400,100};
    int p4[]={550,300};
    int p5[]={400,480};
    int p6[]={200,480};
    glBegin(GL_POLYGON);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glVertex2iv(p6);
    glEnd();
    glFlush();
}


void Lab1A(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINES);
    glVertex2i(20,100);
    glVertex2i(70,120);
    glBegin(GL_LINES);
    glVertex2i(20,20);
    glVertex2i(40,50);
    glBegin(GL_LINES);
    glVertex2i(70,10);
    glVertex2i(90,70);
    glEnd();
    glFlush();
}

void Lab1B(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINE_STRIP);
    glVertex2i(150,100);
    glVertex2i(200,120);
    glVertex2i(230,70);
    glVertex2i(200,10);
    glVertex2i(160,30);
    glVertex2i(180,70);
    glEnd();
    glFlush();
}

void Lab1C(void){
    glColor3f(1.0,0,1);
    glPointSize(100);
    glBegin(GL_LINE_LOOP);
    glVertex2i(10,190);
    glVertex2i(100,250);
    glVertex2i(140,120);
    glVertex2i(100,10);
    glVertex2i(25,90);
    glVertex2i(75,150);
    glEnd();
    glFlush();
}

void Lab2(void){
    glColor3f(1,0.5,0);
    glPointSize(100);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20,20);
    glVertex2i(120,20);
    glVertex2i(120,100);
    glVertex2i(70,150);
    glVertex2i(20,100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(50,20);
    glVertex2i(50,45);
    glVertex2i(80,45);
    glVertex2i(80,20);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(90,100);
    glVertex2i(110,100);
    glVertex2i(110,80);
    glVertex2i(90,80);
    glVertex2i(90,100);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(30,110);
    glVertex2i(30,150);
    glVertex2i(45,150);
    glVertex2i(45,123);
    glEnd();
    glFlush();
}

void Lab3(void){
    glColor3f(1.0,0,0);
    glPointSize(100);
    int p1[]={100,300};
    int p2[]={300,300};
    int p3[]={200,450};
    glBegin(GL_TRIANGLES);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glEnd();

    glColor3f(0,1,0);
    glPointSize(100);
    int p4[]={100,150};
    int p5[]={300,150};
    int p6[]={300,300};
    int p7[]={100,300};
    glBegin(GL_POLYGON);
    glVertex2iv(p4);
    glVertex2iv(p5);
    glVertex2iv(p6);
    glVertex2iv(p7);
    glEnd();

    glColor3f(0,0.2,0.5);
    glPointSize(100);
    int p8[]={300,150};
    int p9[]={500,170};
    int p10[]={500,320};
    int p11[]={300,300};
    glBegin(GL_POLYGON);
    glVertex2iv(p8);
    glVertex2iv(p9);
    glVertex2iv(p10);
    glVertex2iv(p11);
    glEnd();

    glColor3f(0,0,1);
    glPointSize(100);
    int p12[]={300,300};
    int p13[]={500,320};
    int p14[]={400,465};
    int p15[]={200,450};
    glBegin(GL_POLYGON);
    glVertex2iv(p12);
    glVertex2iv(p13);
    glVertex2iv(p14);
    glVertex2iv(p15);
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

    glutDisplayFunc(Lab3);
    glutMainLoop();
    return 0;
}
