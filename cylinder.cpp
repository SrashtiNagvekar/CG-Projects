#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	int xc = 0, yc = 0, r = 20;
	float x, y;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	glBegin(GL_POINTS);
	for (int xc = 0; xc <=10; xc+=2)
	{
		for (int i = 0; i < 360; i++)
		{
			x = r * cos(i)+xc;
			y = r * sin(i)+yc;
			glVertex2f(x, y);
		}
		yc += 2;
		
	}
	glEnd();
	glFlush();
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
