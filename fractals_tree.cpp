
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
	usleep(1000);
	float radianangle = angle*3.14/180;
	float radianangle2 = angle2*3.14/180;
	if(length<30)
	{
	glColor3f(0,1,0);	
	}
	if(length>30)
	{
	glColor3f(1,0,0);	
	}
	if(length<0)
	{
		return;
	}
	glBegin(GL_LINES);
	Point p(x,y);
	glVertex2f(x,y);
	glVertex2f(x+length*sin(radianangle),y+length*cos(radianangle));
	glVertex2f(x,y);
	glVertex2f(x-length*sin(radianangle2),y+length*cos(radianangle2));
	glEnd();
	glFlush();
	glutSwapBuffers();
	 float rightangle=angle+30;
	 float leftangle=angle2-30;

	drawTree(x+length*sin(radianangle),y+length*cos(radianangle),rightangle,leftangle,length-10);
	 rightangle=angle-30;
	  leftangle=angle2+30;
	 drawTree(x-length*sin(radianangle2),y+length*cos(radianangle2),rightangle,leftangle,length-10);
	
}
void display()
{
	float angle=30;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	Point p(320.0,0.0);
	glVertex2f(p.xcord,p.ycord);
	glVertex2f(p.xcord,p.ycord+100.0);
	glEnd();
	drawTree(p.xcord,p.ycord+100.0,angle,angle,80);
	glFlush();
	glutSwapBuffers();
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,512.0);
	glColor3f(1,0,0);
}
int main( int argc, char* argv[] )
{

	glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
		glutInitWindowSize(640,512);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Tree");
		glutDisplayFunc(display);
		myinit();
		glutMainLoop();

    return 0;
}


