#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>
#define num 600

int LE[num],RE[num];
void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}
void draw(void){
    GLint P1[2]={50,100},P2[2]={250,100},P3[2]={250,300},P4[2]={50,300};
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2iv(P1);
    glVertex2iv(P2);
    glVertex2iv(P3);
    glVertex2iv(P4);
    glEnd();
    for(int i=0;i<num;i++){
        LE[i]=num;
        RE[i]=0;
    }
    scanline(P2[0],P2[1],P3[0],P3[1]);
    scanline(P2[0],P2[1],P1[0],P1[1]);
    scanline(P1[0],P1[1],P4[0],P4[1]);
    scanline(P4[0],P4[1],P3[0],P3[1]);

    for(int y=0;y<num;y++){
        for(int x=LE[y];x<RE[y];x++){
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            glFlush();
        }
    }
    glFlush();

}
void scanline(GLint x1,GLint y1,GLint x2,GLint y2){
    int x,M; //M= (x2-x1)
    int t,y;
    if(y1>y2){
        t=x1;
        x1=x2;
        x2=t;
        t=y1;
        y1=y2;
        y2=t;
    }
    if ((y2-y1)==0){
        M=(x2-x1);
    }else{
        M=(float)(x2-x1) / (float) (y2-y1);
    }
    x=x1;
    for(y=y1;y<=y2;y++){
        if(x<LE[y]){
            LE[y]=(int) x;
            }
        if(x>RE[y]){
            RE[y]=(int) x;
        }
        x=x+M;
    }
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("EX.Scan-Line 4 squares ");
    myinit();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
