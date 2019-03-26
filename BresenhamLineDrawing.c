#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

static int x1, y1, x2, y2,click=0;

void bresenham_line(int, int, int, int);
void mouse(int button, int press, int mx, int my){
	
	if(button == GLUT_LEFT_BUTTON && press == GLUT_DOWN){
		if(click == 0){
			x1 = mx;
			y1 = 500-my;
			click++;
			printf("Click no: %d\n", click);
		}
		else{
			x2 = mx;
			y2 = 500-my;
			click++;
			printf("Click no: %d\n", click);
			bresenham_line(x1, x2, y1, y2);
			glFlush();
			x1 = x2;		//to store current click as previous click for next line
			y1 = y2;
		}

	}
}



void drawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glColor4f(1,0,0,1);
	glVertex2i(x, y);
	glEnd();
}


void bresenham_line(int x1, int x2, int y1, int y2) {
	int dx,dy,p0,pk,pk1,i,x,y, xinc = 1, yinc = 1;
	float m;
	dx = x2-x1;
	if (dx < 0){ dx = -dx; xinc = -1;}
	 dy = y2-y1;
	if (dy < 0){ dy = -dy; yinc = -1;}
	m = (float)dy / (float)dx;
		x=x1;
		y=y1;
	if(m < 1){ //(case of |m|< 1 )
		drawPixel(x , y);
		p0 = 2*dy - dx;
		pk = p0;
		for(i=0; i<dx; i++){
			if(pk<0){
				pk1 = pk + 2*(dy);
			}
			else{
				pk1 = pk + 2*(dy) - 2*(dx);
				y= y + yinc;
			}
			pk=pk1;
			x= x + xinc;
			drawPixel(x,y);
		}
	}
	else{ //(case of |m|>1 ) 
		drawPixel(x,y);
		p0 = 2*dx-dy;
		pk = p0;
		
		for(i=0; i<dy; i++){
			if(pk<0){
				pk1 = pk + 2*(dx);
			}
			else{
				pk1 = pk + 2*(dx) - 2*(dy);
				x = x + xinc;
			}
			pk=pk1;
			y = y+ yinc;
			drawPixel(x,y);
		}

	}
}

void print_name(char string[],float x,float y) 
{  
	glRasterPos2f(x, y);

	for (int c= 0; c <= strlen(string); c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[c]);
	}
}

void myDisplay() {
	
	glColor4f(1,1,0,1);
	print_name( "BRESENHAM'S LINE DRAWING", 400, 488);
	print_name( "Done By:", 890, 25);
	print_name( "NIKHIL ANAND", 890, 12);
	glFlush();
}

void esckey( unsigned char key, int x, int y )
{	int a;
	a = glutGetWindow();

	if (key == 27) {glutDestroyWindow (a);}
	else {print_name("Press esc to exit no other key works", 0,3); 	glutPostRedisplay();}
}


void main(int argc, char **argv) {

	glutInit(&argc, argv); //Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(1000, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Line Drawing");
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 0.0);
		gluOrtho2D(0, 1000, 0, 500);
	glutMouseFunc(mouse); //glutPassiveMouseFunc() vs glutMotionMouseFunc()
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(esckey);
	

	glutMainLoop();
}
