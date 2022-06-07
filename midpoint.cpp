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

void eight_way_sym(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glVertex2f(y, x);
	glVertex2f(-y,x);
	glVertex2f(-x, y);
	glVertex2f(-x, -y);
	glVertex2f(-y,-x);
	glVertex2f(y, -x);
	glVertex2f(x, -y);
	glEnd();
	glFlush();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0,0);
	glPointSize(2);
	int x = 0;
	int y = r;
	int p = 1 - r;
	eight_way_sym(x+xc, y+yc);
	while (x <= y)
	{
		x++;
		if (p < 0)
			p += (2*x) + 1;
		else
		{
			y--;
			p += (2 * x )- (2 * y) + 1;
		}
		eight_way_sym(x+xc, y+yc);
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
