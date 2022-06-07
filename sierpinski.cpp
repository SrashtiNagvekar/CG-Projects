
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
//--------------------------Sierpinski gasket--------------------------------------
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
	float p[3][2] = { {10,10},{20,20},{30,10} };
	float rp[2] = { 20,15 };
	for (int i = 0; i < 5000; i++)
	{
		int v = rand() % 3;
		rp[0] = (rp[0] + p[v][0])/2;
		rp[1] = (rp[1] + p[v][1]) / 2;
		glBegin(GL_POINTS);
		glVertex2f(rp[0], rp[1]);
		glEnd();
		glFlush();

	}
}

int main()
{
	glutInitDisplayMode(GLUT_RGB| GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutCreateWindow("first");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
