#include<stdio.h>
#include<glut.h>
int size = 1;
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
	glBegin(GL_POLYGON);
	glVertex2f(-10 * size, 10 * size);
	glVertex2f(-10 * size, -10 * size);
	glVertex2f(10 * size, -10 * size);
	glVertex2f(10 * size, 10 * size);
	glEnd();
	glFlush();
}

void demo_menu(int id)
{
	switch (id)
	{
	case 1:exit(0);
		break;
	case 2:size = size * 2;
		break;
	case 3:size = size / 2;
		break;
	}
	glutPostRedisplay();
}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("first");
	glutCreateMenu(demo_menu);
	glutAddMenuEntry("quit", 1);
	glutAddMenuEntry("incr sq size", 2);
	glutAddMenuEntry("decr sq size", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
