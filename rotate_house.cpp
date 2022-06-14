#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
int angle = 90;
int p[9][2] = { {10,0},{10,10},{20,10},{20,0},{15,20},{13,0},{13,5},{17,5},{17,0} };
int n = 9;
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}

void draw_house()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,0);
	glVertex2f(10,10);
	glVertex2f(20,10);
	glVertex2f(20,0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(10,10);
	glVertex2f(15,20);
	glVertex2f(20,10);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2f(13, 0);
	glVertex2f(13,5);
	glVertex2f(17,5);
	glVertex2f(17,0);
	glEnd();
}

void display()
{
	int xp = 15, yp = 20;
	glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1, 0, 0);
		glPointSize(3);
		draw_house();
		glFlush();
		glColor3f(0, 1, 0);
		glLoadIdentity();
		glTranslatef(xp, yp, 0);
		glRotatef(angle, 0, 0, 1);
		glTranslatef(-xp, -yp, 0);
		draw_house();
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
	return 0;
}
