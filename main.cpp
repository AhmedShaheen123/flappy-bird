#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include<mmsystem.h>

#include <iostream>
#include <cstdlib>
#include <sstream>  // for string streams
#include <string>
#include <sstream>
#include <string.h>// for string
#include <cstdio>


using namespace std;
#endif
float deltax=.05;
float deltay=.05;
float postiona1=400;
float postiona2=350;
float postionb1=200;
float postionb2=150;
float postionBirdx1=80;
float postionBirdx2=100;
float postionBirdy1=300;
float postionBirdy2=320;
int topOne=320;
int downOne=220;
int topTwo=300;
int downTwo=240;
int mi=270,ma=350;
int score =0;

bool stop=false;
int factor = 5;
// Clears the current window and draws a triangle.
void screen()
{
    glClearColor(0.4,0.773,0.808,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnd();

}
void downroad(){
    glColor3f(0.871,0.847,0.584);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(400,0);
    glVertex2f(400,50);
    glVertex2f(0,50 );
    glEnd();
}
void toproad(){
    glLineWidth(5);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0,50);
    glVertex2f(400,50);
    glEnd();
    glColor3f(0.612,0.902,0.349);
    glBegin(GL_POLYGON);
    glVertex2f(0,50);
    glVertex2f(400,50);
    glVertex2f(400,60);
    glVertex2f(0,60);
    glEnd();
    glLineWidth(2);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(0,60);
    glVertex2f(400,60);
    glEnd();

}
void renderbutmap(float x,float y,void *font,char *string){
    char *c;
    glRasterPos2d(x,y);
    for(c=string;*c!='\0';c++){
        glutBitmapCharacter(font,*c);
    }

}
void gameover(){
    glColor3f(1,0,0);
    char buf[100]={0};
    char h[100]={0};
    sprintf(buf,"Game over");
    renderbutmap(150,320,GLUT_BITMAP_TIMES_ROMAN_24,buf);
    sprintf(h,"enter R to restart");
    renderbutmap(127,290,GLUT_BITMAP_TIMES_ROMAN_24,h);

}
void scoreDisplay(){

    glColor3f(0,0,0);
    char buf[100]={0};
    sprintf(buf,"%d",score);
    renderbutmap(190,500,GLUT_BITMAP_TIMES_ROMAN_24,buf);

}
	//writeString(s,0,195,GLUT_BITMAP_HELVETICA_18);


void objectOneA(){
    if(postiona1>447){
    srand(time(0));
    mi=150,ma=350;
    topOne= (mi+rand() %  (ma - mi + 1))+30;
    downOne=(topOne-100);
    }

    //the top tower body
    glColor3f(00.455,0.753,0.184);
    glBegin(GL_POLYGON);
    glVertex2f(postiona1,600);
    glVertex2f(postiona1,topOne);
    glVertex2f(postiona2,topOne);
    glVertex2f(postiona2,600);
    glEnd();
    //body border
    glLineWidth(3);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postiona1,600);
    glVertex2f(postiona1,topOne);
    glVertex2f(postiona2,topOne);
    glVertex2f(postiona2,600);
    glEnd();
    //body border box
    glLineWidth(5);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postiona1,topOne+36);
    glVertex2f(postiona1,topOne);
    glVertex2f(postiona2,topOne);
    glVertex2f(postiona2,topOne+36);
    glEnd();
    // the down body /////////////////////////
    glColor3f(00.455,0.753,0.184);
    glBegin(GL_POLYGON);
    glVertex2f(postiona1,60);
    glVertex2f(postiona1,downOne);
    glVertex2f(postiona2,downOne);
    glVertex2f(postiona2,60);
    glEnd();
    // down body border
    glLineWidth(3);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postiona1,60);
    glVertex2f(postiona1,downOne);
    glVertex2f(postiona2,downOne);
    glVertex2f(postiona2,60);
    glEnd();
    //down body border box
    glLineWidth(5);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postiona1,downOne);
    glVertex2f(postiona1,downOne-36);
    glVertex2f(postiona2,downOne-36);
    glVertex2f(postiona2,downOne);
    glEnd();
    postiona1-=deltax;
    postiona2-=deltax;
    if(int(postiona1)==0){
        postiona1=450;
        postiona2=400;
        score+=1;

    }
    if(stop==false){
    glutPostRedisplay();
}
}

void objectTwoA(){
    //the second top tower body
    if(postionb1>447){
    srand(time(0));
    mi=150,ma=350;
    topTwo= (mi+rand() %  (ma - mi + 1))+30;
    downTwo=(topTwo-80);
    }
    glColor3f(00.455,0.753,0.184);
    glBegin(GL_POLYGON);
    glVertex2f(postionb1,600);
    glVertex2f(postionb1,topTwo);
    glVertex2f(postionb2,topTwo);
    glVertex2f(postionb2,600);
    glEnd();
    //the second top tower border
    glLineWidth(3);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postionb1,600);
    glVertex2f(postionb1,topTwo);
    glVertex2f(postionb2,topTwo);
    glVertex2f(postionb2,600);
    glEnd();
    //the second top tower border box
    glLineWidth(5);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postionb1,topTwo);
    glVertex2f(postionb1,topTwo+36);
    glVertex2f(postionb2,topTwo+36);
    glVertex2f(postionb2,topTwo);
    glEnd();
        //the second down tower body
    glColor3f(00.455,0.753,0.184);
    glBegin(GL_POLYGON);
    glVertex2f(postionb1,60);
    glVertex2f(postionb1,downTwo);
    glVertex2f(postionb2,downTwo);
    glVertex2f(postionb2,60);
    glEnd();
    //the second down tower border
    glLineWidth(3);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postionb1,60);
    glVertex2f(postionb1,downTwo);
    glVertex2f(postionb2,downTwo);
    glVertex2f(postionb2,60);
    glEnd();
    //the second down tower border box
    glLineWidth(5);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(postionb1,downTwo);
    glVertex2f(postionb1,downTwo-36);
    glVertex2f(postionb2,downTwo-36);
    glVertex2f(postionb2,downTwo);
    glEnd();
    postionb1-=deltax;
    postionb2-=deltax;
    if(int(postionb1)==0){
        postionb1=450;
        postionb2=400;

        score+=1;
    }
    if(stop==false){
    glutPostRedisplay();
    }
}
bool isCollided(){
    if(postionBirdx1>=postiona2&&postionBirdx1<=postiona1&&postionBirdy1>=0&&postionBirdy1>=topOne){

    };
}
void bird(){
    glColor3f(0,0,1);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(postionBirdx1,postionBirdy1);
    glEnd();
    postionBirdy1-=deltay;
   if(postionBirdx1>=postiona2&&postionBirdx1<=postiona1&&postionBirdy1>=0&&(postionBirdy1>=topOne||postionBirdy1<=downOne)||postionBirdy1<=60){
        stop=!stop;
        gameover();


    }
    else if(postionBirdx1>=postionb2&&postionBirdx1<=postionb1&&postionBirdy1>=0&&(postionBirdy1>=topTwo||postionBirdy1<=downTwo)||postionBirdy1<=60){
        stop=!stop;
        gameover();
    }

}
void keyboard(unsigned char key,int x ,int y){
    if(key=='a') stop=!stop;
    if(key=='e')  exit(0);
    if(key=='r'){
         postiona1=400;
         postiona2=350;
         postionb1=200;
         postionb2=150;
         postionBirdx1=80;
         postionBirdx2=100;
         postionBirdy1=300;
         postionBirdy2=320;
         topOne=320;
         downOne=220;
         topTwo=300;
         downTwo=240;
         score =0;
    }
    glutPostRedisplay();
}
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
	postionBirdy1+=30;
		break;
		glutPostRedisplay();
		}
}
void mainDisplay() {
    screen();
    downroad();
    toproad();
	objectOneA();
	objectTwoA();
	bird();
	scoreDisplay();
	glFlush();
}
// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char** argv)
{
    bool x=false;
    // Use a single buffered window in RGB mode (as opposed to a double-buffered
    // window or color-index mode).
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 600);
    glutCreateWindow("Flappy Bird");
    gluOrtho2D(0,400,0,600);
    glutSpecialFunc(key);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(mainDisplay);
    glutPostRedisplay();
    glutMainLoop();
}
