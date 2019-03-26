#include <GL/glut.h>
#include <stdio.h>

void esckey(unsigned char key, int a, int b){
	if(key == 27) {glClear(GL_COLOR_BUFFER_BIT);  glFlush();}

}


void main(int argc, char **argv) {

	glutInit(&argc, argv); //Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Drawing");
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		gluOrtho2D(0, 500, 0, 500);
		glFlush();
	glutKeyboardFunc(esckey);

	
	glutMainLoop();
}
