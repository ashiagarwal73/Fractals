#include <GL/glut.h>
#include <string>
#include <math.h>
#include <unistd.h>

using namespace std;
class Point
{
public:
	float xcord;
	float ycord;
	Point(float x,float y)
	{
		xcord=x;
		ycord=y;
	}

	
};
void drawTree(float x,float y,float angle,float angle2,int length)
{      
	
	float radianangle = angle*3.14/180;
	float radianangle2 = angle2*3.14/180;

	if(length>40){
	glColor3f(1.0,0.0,0.0);	
	}

	if(length<0)
	{
		return;
	}
	glBegin(GL_LINES);
	Point p(x,y);
	glVertex2f(x,y);
	glVertex2f(x+length*sin(radianangle),y+length*cos(radianangle));
	glVertex2f(x+length*sin(radianangle),y+length*cos(radianangle));
	glVertex2f(x+length*sin(radianangle)-10,y+length*cos(radianangle)+10);
	glVertex2f(x+length*sin(radianangle)-10,y+length*cos(radianangle)+10);
	glVertex2f(x,y);
	glVertex2f(x,y);
	glVertex2f(x-length*sin(radianangle2),y+length*cos(radianangle2));
	glVertex2f(x-length*sin(radianangle2),y+length*cos(radianangle2));
	glVertex2f(x-length*sin(radianangle2)+10,y+length*cos(radianangle2)+10);
	glVertex2f(x-length*sin(radianangle2)+10,y+length*cos(radianangle2)+10);
	glVertex2f(x,y);
	glEnd();
	glFlush();
	glutSwapBuffers();

if(length<40)
{
glColor3f(0.0,1.0,0.0);
	   float rightangle=angle+30;
	   float leftangle=angle2-30;

	drawTree(x+length*sin(radianangle),y+length*cos(radianangle),rightangle,leftangle,length-5);
	rightangle=angle-30;
	  leftangle=angle2+30;
	drawTree(x-length*sin(radianangle2),y+length*cos(radianangle2),rightangle,leftangle,length-5);
}
else{
	glColor3f(1.0,0.0,0.0);
	   float rightangle=angle+30;
	   float leftangle=angle2-30;

	drawTree(x+length*sin(radianangle),y+length*cos(radianangle),rightangle,leftangle,length-10);
	rightangle=angle-30;
	  leftangle=angle2+30;
	drawTree(x-length*sin(radianangle2),y+length*cos(radianangle2),rightangle,leftangle,length-10);

}

          


}
int count = 0;
void display()
{       if(count==0){
	float angle=30;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	Point p(400.0,0.0);
	glVertex2f(p.xcord-20,p.ycord);
	glVertex2f(p.xcord,p.ycord+100.0);
	glVertex2f(p.xcord,p.ycord+100.0);
	glVertex2f(p.xcord+20,p.ycord);
	glVertex2f(p.xcord+20,p.ycord);
	glVertex2f(p.xcord-20,p.ycord);
	glEnd();
	drawTree(p.xcord,p.ycord+100.0,angle,angle,80);
	count++;}
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,800.0,0.0,512.0);
	glColor3f(1,0,0);
}
int main( int argc, char* argv[] )
{

	glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
		glutInitWindowSize(800,512);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Tree");
		glutDisplayFunc(display);
		myinit();
		glutMainLoop();

    return 0;
}