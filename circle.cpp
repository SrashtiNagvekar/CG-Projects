#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
int r = 20,xc=0,yc=0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	float x, y;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glLineWidth(1);
	glBegin(GL_POINTS);
	for (int deg = 0; deg <= 360; deg += 2)
	{
		x = r * cos(deg)+xc;
		y = r * sin(deg)+yc;
		glVertex2f(x, y);
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
