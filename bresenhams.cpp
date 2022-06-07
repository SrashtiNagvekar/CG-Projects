#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void bresenhams(int x1,int y1,int x2,int y2)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int twody = 2 * dy;
	int twodxdy = 2*(dx - dy);
	//int p = 2 * dx - dy;
	int x, y;
	x = x1;
	y = y1;
	setpixel(x, y);
	while (x < x2)
	{
		x++;
		if (p < 0)
		{
			p+=twody;
		}
		else
		{
			y++;
			p +=twodxdy;
		}
		setpixel(x, y);
	}


}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glPointSize(2);
	bresenhams(20, 40, 40, 60);
	glFlush();
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
