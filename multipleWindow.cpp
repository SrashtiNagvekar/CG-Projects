#include<stdio.h>
#include<glut.h>

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
	glMatrixMode(GL_MODELVIEW);
}

void display1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	
		glVertex2f(30, 30);
		glVertex2f(30, -30);
		glVertex2f(-30, -30);
		glVertex2f(-30, 30);
		glEnd();
		glFlush();
	
}

void display2()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);

	glVertex2f(30, 30);
	glVertex2f(30, -30);
	glVertex2f(-30, -30);
	glVertex2f(-30, 30);
	glEnd();
	glFlush();

}

int main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(50, 80);
	int id1 = glutCreateWindow("first");
	glutSetWindow(id1);
	init();
	glutDisplayFunc(display1);
	glutInitWindowPosition(50, 30);
	glutInitWindowSize(300, 300);
	int id2 = glutCreateWindow("second");
	glutSetWindow(id2);
	init();
	glutDisplayFunc(display2);
	glutMainLoop();
}
