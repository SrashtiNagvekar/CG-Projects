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
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	int xc = 40, yc = 40, r1 = 10, r2 = 15;
	glBegin(GL_LINE_STRIP);
	for (int theta = 0; theta <= 360; theta++)
	{
		float x1 = xc + r1 * cos(theta);
		float y1 = yc + r1 * sin(theta);
		float x2 = xc + r2 * cos(theta);
		float y2 = xc + r2 * sin(theta);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	
	}
	glEnd();
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
