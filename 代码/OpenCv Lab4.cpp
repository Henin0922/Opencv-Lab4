
#include<stdlib.h>
#include <glut.h>

void myinit(void)
{


	glClearColor(1.0, 1.0, 1.0, 0.0); 
	glColor3f(1.0, 0.0, 0.0); 

	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void  plot_circle_points(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
	glVertex3f(xc + x, yc + y, 0);
	glVertex3f(xc - x, yc + y, 0);
	glVertex3f(xc + x, yc - y, 0);
	glVertex3f(xc - x, yc - y, 0);
	glVertex3f(xc + y, yc + x, 0);
	glVertex3f(xc - y, yc + x, 0);
	glVertex3f(xc + y, yc - x, 0);
	glVertex3f(xc - y, yc - x, 0);
	glEnd();
}
void drawcircle(int xc, int yc, int radius)
{
	int x, y, p;
	x = 0;
	y = radius;
	p = 3 - 2 * radius;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	while (x < y)
	{
		plot_circle_points(xc, yc, x, y);
		if (p < 0)
			p = p + 4 * x + 6;
		else
		{
			p = p + 4 * (x - y) + 10;
			y -= 1;
		}
		x += 1;
	}
	if (x == y)
		plot_circle_points(xc, yc, x, y);
}


/* the display callback: */
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);  
	glViewport(0, 0, 500, 500);
	drawcircle(200, 200, 100);	
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(500, 500); 
	glutInitWindowPosition(0, 0); 
	glutCreateWindow("Bresenham  circile");
	glutDisplayFunc(display); 
	myinit(); 
	glutMainLoop(); 
}