
#include<glut.h>
int w = 500, h = 500;
float size = 40;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glFlush();
}

void mousef(int b, int s, int x, int y)
{
	y = h - y;
	float t;
	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		t = size / 2.0;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		glFlush();
		glBegin(GL_POLYGON);
			glVertex2f(x + t, y + t);
			glVertex2f(x + t, y - t);
			glVertex2f(x - t, y - t);
			glVertex2f(x - t, y + t);
			glEnd();
			glFlush();

	}

	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
	{
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
}

void main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutInitWindowSize(w,h);
		glutCreateWindow("mouse");
		init();
		glutDisplayFunc(display);
		glutMouseFunc(mousef);
		glutMainLoop();
}
