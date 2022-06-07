#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
float X1=30, Y1=30,X2=30,Y2=60;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	float dx, dy, xincr, yincr, x, y, steps;
	int k;
	dx = X2 - X1;
	dy = Y2 - Y1;
	if (fabs(dx) > fabs(dy))
		steps = dx;
	else
		steps = dy;
	xincr = float(dx) / float(steps);
	yincr = float(dy) / float(steps);
	x = X1;
	y = Y1;
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
	for (k = 1; k < steps; k++)
	{
		x += xincr;
		y += yincr;
		glBegin(GL_POINTS);
		glVertex2f(x, y);
		glEnd();
		glFlush();
	}
}

int main()
{
	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("first");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
