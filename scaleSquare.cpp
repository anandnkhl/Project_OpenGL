#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

float square[4][2] = {{-40.0,-40.0},{-40.0,40.0},{40.0,40.0},{40.0,-40.0}};

void key(unsigned char k, int x, int y){
	if(k == ' '){
		if(square[0][0] >= -200.00f){	
			for(int i = 0; i<4; i++){
			float scale = 1.2;
			for(int j = 0; j<2; j++){
				square[i][j] =  square[i][j]*scale;
				cout<<square[i][j]<<endl;
			}
		}
		}
		
		glutPostRedisplay();
	}
	if(k == 13){
		if(square[0][0] <= -20.00f){
			for(int i = 0; i<4; i++){
			float scaledown = 0.8;
			for(int j = 0; j<2; j++){
				square[i][j] =  square[i][j]*scaledown;
				cout<<square[i][j]<<endl;
			}
		}}
		
		glutPostRedisplay();
	}
	
}


void draw(void)
{
glClearColor(0,0,0,0);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0, 500.0, -500.0,500.0);
glColor3f(1, 0, 0);
glBegin(GL_POLYGON);
glVertex2f(square[0][0],square[0][1]);
glVertex2f(square[1][0],square[1][1]);
glVertex2f(square[2][0],square[2][1]);
glVertex2f(square[3][0],square[3][1]);
glEnd();
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(30, 50);
glutInitWindowSize(1000, 1000);
glutCreateWindow("Scale Square");
glutDisplayFunc(draw);
glutKeyboardFunc(key);
glutMainLoop();
return 0;
}
