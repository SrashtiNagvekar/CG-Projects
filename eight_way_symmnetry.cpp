#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
int r = 20, xc = 0, yc = 0;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void eight_way_sym(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glVertex2f(y, x);
	glVertex2f(-y, x);
	glVertex2f(-x, y);
	glVertex2f(-x, -y);
	glVertex2f(-y, -x);
	glVertex2f(y, -x);
	glVertex2f(x, -y);
	glEnd();
	glFlush();
}

void display()
{
	float x, y;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	glPointSize(2);
	for (int i = 0; i < 45; i++)
	{
		x = r * cos(i);
		y = r * sin(i);
		eight_way_sym(x, y);
	}
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("circle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
