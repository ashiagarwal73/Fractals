
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
float angle=60*3.14/180;
void drawTriangle(float x,float y,int length)
{
	if(length<5)
	{
		return;
	}
	glBegin(GL_LINES);
	Point p(x,y);
	glVertex2f(p.xcord,p.ycord);
	glVertex2f(p.xcord+length*cos(angle),p.ycord+length*sin(angle));
	 glVertex2f(p.xcord+length*cos(angle),p.ycord+length*sin(angle));
	 glVertex2f(p.xcord+length,p.ycord);
	 glVertex2f(p.xcord+length,p.ycord);
	 glVertex2f(p.xcord,p.ycord);
	glEnd();
	glFlush();
	glutSwapBuffers();
	drawTriangle(p.xcord,p.ycord,length/2);
	drawTriangle(p.xcord+(length/2)*cos(angle),p.ycord+(length/2)*sin(angle),length/2);
	drawTriangle(p.xcord+(length/2),p.ycord,length/2);
}
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	drawTriangle(140.0,100.0,400);
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
		glutCreateWindow("Triangle");
		glutDisplayFunc(display);
		myinit();
		glutMainLoop();

    return 0;
}