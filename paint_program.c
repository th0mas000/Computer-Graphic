#include<gl\gl.h>
#include<gl\glut.h>
#include<windows.h>

int size = 2 ;
int flipX = 900, flipY = 600;
int mouse_down = 0;
int prev_x = 0, prev_y = 0;
int x1,y1,x2,y2,dy,dx,step ;
float r,g,b;
int first=0;
char shape = 'p';
int rad=40;
int ra = 0;

void drawLine(int x1, int y1, int x2, int y2) {
    glColor3f(r,g,b);
    glLineWidth(size);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}
void dda_line2(int x1, int y1, int x2, int y2) {
    glColor3f(r,g,b);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
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
    glPointSize(size);
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    for(int i=1; i<=steps; i++){
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        glFlush();
        x=x+Xinc;
        y=y+Yinc;
    }
}

void plotQ(int x, int y, int xcenter, int ycenter){
    glVertex2d(xcenter+x, ycenter+y); //Q1
    glVertex2d(xcenter+y, ycenter+x); //Q2
    glVertex2d(xcenter+y, ycenter-x); //Q3
    glVertex2d(xcenter+x, ycenter-y); //Q4
    glVertex2d(xcenter-x, ycenter-y); //Q5
    glVertex2d(xcenter-y, ycenter-x); //Q6
    glVertex2d(xcenter-y, ycenter+x); //Q7
    glVertex2d(xcenter-x, ycenter+y); //Q8
}

void midPointCircle(int xcenter, int ycenter, int radias){
    int x=0, y=radias;
    int p=1-radias;
    glColor3f(r,g,b);
    glPointSize(2);
    glBegin(GL_POINTS);
    glVertex2d(xcenter+x, ycenter+y);
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
        plotQ(x, y, xcenter, ycenter);

    }
    glEnd();
    glFlush();
}

void myinit(void){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, flipX,  0,flipY);
}

void mouse(int button,int state,int x ,int y){
    int X=x;
    int Y= flipY - y;
    if(shape == 'p'){
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            mouse_down = 1;
            prev_x = x;
            prev_y = flipY - y;
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            mouse_down = 0;
        }
    }else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && shape=='l'){
        if(first==0){
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
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && shape=='c'){
        midPointCircle(X, Y, rad);
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && shape=='t'){
        int x_1 = X-50-ra, x_2 = X, x_3 = X+50+ra;
        int y_1 = Y-30-ra, y_2 = Y, y_3 = Y+30+ra;
        dda_line2(x_3,y_1,x_1,y_1);
        dda_line2(x_1,y_1,x_2,y_3);
        dda_line2(x_2,y_3,x_3,y_1);
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && shape=='s'){
        int x_1 = X-40-ra, x_2 = X, x_3 = X+40+ra;
        int y_1 = Y-40-ra, y_2 = Y, y_3 = Y+40+ra;
        dda_line2(x_1,y_3,x_3,y_3);
        dda_line2(x_1,y_1,x_3,y_1);
        dda_line2(x_1,y_1,x_1,y_3);
        dda_line2(x_3,y_1,x_3,y_3);
    }
}

void keyboard(unsigned char key, int x, int y){
    if(key=='p'){
        printf(" Mode ==> Pen \n");
        shape = 'p';
    }
    if(key=='l'){   // Draw Line
        printf(" Mode ==> Line \n");
        shape = 'l';
    }
    if(key=='c'){   // Draw Circle
        printf(" Mode ==> Circle \n");
        shape = 'c';
    }
    if(key=='s'){   // Draw Square
        printf(" Mode ==> Square \n");
        shape = 's';
    }
    if(key=='t'){   // Draw Triangle
        printf(" Mode ==> Triangle \n");
        shape = 't';
    }
    if(key == 'n'){
        if (shape == 'c')rad=rad+5;
        if (shape == 't' || shape == 's')ra=ra+5;
        if (shape == 'p' || shape == 'l'){
            size = size + 2;
        }
    }
    if(key == 'm'){
        if (shape == 'c')rad=rad-5;
        if (shape == 't' || shape == 's')ra=ra-5;
        if (shape == 'p' || shape == 'l'){
            size = size - 2;
            if(size == 0) size = 2;
        }
    }
    if(key == 27){
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        shape=shape;
    }

    if(key=='r'){
        r=1.0;
        g=0.0;
        b=0.0;
    }
    if(key=='g'){
        r=0.0;
        g=1.0;
        b=0.0;
    }
    if(key=='b'){
        r=0.0;
        g=0.0;
        b=1.0;
    }
    if(key=='y'){
        r=1.0;
        g=1.0;
        b=0.0;
    }
    if(key=='/'){
        r=0.0;
        g=0.0;
        b=0.0;
    }
    if(key=='d'){
        r=1.0;
        g=1.0;
        b=1.0;
        printf(" Mode ==> eraser \n");
        shape = 'p';
    }
}

void motion(int x, int y) {
    if (mouse_down) {
        int cur_x = x;
        int cur_y = flipY - y;
        drawLine(prev_x, prev_y, cur_x, cur_y);
        prev_x = cur_x;
        prev_y = cur_y;
    }
}

void show(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(flipX, flipY);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Final Project");
    myinit();
    glutDisplayFunc(show);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    printf("-----------------------------------------------\n\t\t     About\n");
    printf("-----------------------------------------------\n");
    printf("\t  ------------Mode------------\n\n");
    printf("\t    0.  'p' == Pen (default) \n\t    1.  'l' == Line  \n\t    2.  'c' == Circle \n\t    3.  't' == Triangle \n\t    4.  's' == Square \n");
    printf("\t    5.  'r' == Red \n\t    6.  'g' == Green  \n\t    7.  'b' == Blue \n\t    8.  'y' == yellow \n\t    9.  '/' == Black \n\t    10.  '+' == + size \n\t    11. '-' == - size \n");
    printf("\t    12. 'd' == Eraser \n\t    13. 'Esc' == Clear all  \n");
    printf("\n\t  ----------------------------\n");
    printf("\n----------------------------------------------\n");
    glutMainLoop();
    return 0;
}
