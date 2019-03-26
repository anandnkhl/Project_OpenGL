#include<iostream>
#include<GL/glut.h>
#include<string.h>
#include <algorithm>
using namespace std;


void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f,0.0f);
	gluOrtho2D(0,750,0,750);
	glFlush();
}

void fractal(float x, float y, float incx, float incy, int count){
	glColor4f(1,0,0,1);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x + incx, y + incy);
	glEnd();
	glFlush();

	glColor4f(1,1,0,1);
	glBegin(GL_LINES);
	glVertex2i(x, y);
	glVertex2i(x - incx,  y + incy);
	glEnd();
	glFlush();


	if(count <= 5){	
		fractal(x + incx, y + incy, incx * 0.5, incy * 0.5, count + 1);
		fractal(x - incx, y + incy, incx * 0.5, incy * 0.5, count + 1);
	}

}

void myDisplay() {

	glBegin(GL_LINES);
	glVertex2i(350, 0);
	glVertex2i(350, 200);
	glEnd();
	glColor4f(1,0,0,1);

	fractal(350, 200, 150, 100, 0);
	cout<<"Done"<<endl;
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(750, 750); //Initialize the size of Window
	glutInitWindowPosition(100, 0); //Initial position of the window
	glutCreateWindow("Fractal Try 1"); //Name of the Window
	Init();
	//createMenu();
	//glutMouseFunc(mouse);
	//glutKeyboardFunc(keyboard);
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}
