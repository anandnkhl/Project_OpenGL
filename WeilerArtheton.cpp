#include<iostream>
#include<GL/glut.h>
#include <algorithm>
using namespace std;

int vertices=5,x,y,click = 0, i = 0,index=0;
float t1=0.0f,t2=1.0f;
int x_in[15], y_in[15];
int x_polygon[15], y_polygon[15];
int winxmin = 150, winymin = 150, winxmax = 350, winymax = 350;

void mouse(int button, int press, int mx, int my){
	
		if(button == GLUT_LEFT_BUTTON && press == GLUT_DOWN){
			x = mx;
			y = 500-my;
			x_polygon[click]=x;
			y_polygon[click]=y;
			click++;
			if (click == vertices){
				glBegin(GL_LINE_LOOP);
				glColor4f(0.0,1.0,0.0,1.0);
				for(int j = 0; j < vertices; j++){
					glVertex2f(x_polygon[j],y_polygon[j]);
				}
				x_polygon[vertices]=x_polygon[0], y_polygon[vertices]=y_polygon[0];
				glEnd();
				glFlush();
			}
		}

}

void clip(int lineno){
t1=0.0f,t2=1.0f;
//cout<<"lineno:"<<lineno<<endl;
int xc1,xc2,yc1,yc2;
float p[4],q[4];
float r[4];
int x1 = x_polygon[lineno];
cout<<"x1:"<<x1<<endl;
int y1 = y_polygon[lineno];
cout<<"y1:"<<y1<<endl;
int lineinc = lineno+1;
int x2 = x_polygon[lineinc];
cout<<"x2:"<<x2<<endl;
int y2 = y_polygon[lineinc];
cout<<"y2:"<<y2<<endl;
int deltax=x2-x1,deltay=y2-y1;
cout<<"deltax:"<<deltax<<endl;
cout<<"deltay:"<<deltay<<endl;

 p[0]=-deltax;q[0]=x1-winxmin;
 p[1]=deltax;q[1]=winxmax-x1;
 p[2]=-deltay;q[2]=y1-winymin;
 p[3]=deltay;q[3]=winymax-y1;

 for(int i=0;i<4;i++)
{
 r[i] = q[i]/p[i];
cout<<"r:"<<r[i]<<endl;
}

for(int i=0;i<4;i++)
{
  if (p[i] < 0)
   {
	t1 = max(r[i],t1);
	}

  if (p[i] > 0)
   {
	t2 = min(r[i],t2);
	}
}
cout<<"t1:"<<t1<<"t2:"<<t2<<endl;
if (t1 < t2)
{
  xc1 = x1 + deltax * t1;
  yc1 = y1 + deltay * t1;
  xc2 = x1 + deltax * t2;
  yc2 = y1 + deltay * t2;
x_in[index] = xc1;
y_in[index] = yc1;
index++;
x_in[index] = xc2;
y_in[index] = yc2;
//cout<<"deltax:"<<deltax<<endl;
//cout<<"deltay:"<<deltay<<endl;
}

glBegin(GL_LINES);
glColor4f(0.0,1.0,0.0,1.0);
glVertex2f(xc1,yc1);
glVertex2f(xc2,yc2);
glEnd();
glFlush();


}

void Init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(0,500,0,500);
	glFlush();
}

void mydisplay(){
	glBegin(GL_LINE_LOOP);
	glColor4f(1.0,0.0,0.0,1.0);
	glVertex2f(winxmin,winymin);
	glVertex2f(winxmin,winymax);
	glVertex2f(winxmax,winymax);
	glVertex2f(winxmax,winymin);
	glEnd();
	glFlush();
}

void keyboard( unsigned char key, int x, int y )
{

	if (key == 32) { 
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glutPostRedisplay();
		cout<< "Vertices here is ="<< vertices << "\n";
		for(int k = 0; k < vertices; k++){
			clip(k);
			cout<<x_in[k]<<","<<y_in[k]<<endl;
			cout<<"I am running in iteration number:"<< k << "\n";
		}
		click = 0;
	}
}

int main(int argc, char **argv){
	glutInit(&argc, argv);//Initialize window
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); //Single Window
	glutInitWindowSize(500, 500); //Initialize the size of Window
	glutInitWindowPosition(100, 100); //Initial position of the window
	glutCreateWindow("Weiler Artheton Polygon Clipping"); //Name of the Window
	Init();
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}
