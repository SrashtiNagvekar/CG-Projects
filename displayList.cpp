#include<glut.h>
#define BOX 1
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	glNewList(BOX, GL_COMPILE);
	   glBegin(GL_POLYGON);
	   glVertex2f(50, 50);
	   glVertex2f(50, -50);
	   glVertex2f(-50, -50);
	   glVertex2f(-50, 50);
	   glEnd();
	   glEndList();
	   glCallList(BOX);
	   glFlush();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("list");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
