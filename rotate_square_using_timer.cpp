#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
int angle = 0;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	int r = 20;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	int x = r * cos(angle);
	int y = r * sin(angle);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(-y, x);
	glVertex2f(-x, -y);
	glVertex2f(y, -x);
	glEnd();
	glutSwapBuffers();
	glFlush();
}

void idlef(int v)
{
	angle += 5;
	if (angle >= 360)
		angle = 0;
	glutTimerFunc(30, idlef, 60);
	glutPostRedisplay();
}

//void mousef(int b, int s, int x, int y)
//{
//	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
//		glutIdleFunc(idlef);
//	if (b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN)
//		glutIdleFunc(NULL);
//}

int main()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("first");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(30, idlef, 60);
	/*glutMouseFunc(mousef);*/
	glutMainLoop();
	return 0;
}
