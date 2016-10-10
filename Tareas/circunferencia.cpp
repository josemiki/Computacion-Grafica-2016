#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

#define ancho 600
#define largo 600
#define escalado 210

GLfloat radio;
//GLfloat angulo;



void reshape(int width, int height)
{
 	glViewport(0, 0, width, height);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-1, 1, -1, 1, -1, 1);
 	glMatrixMode(GL_MODELVIEW);
}

void display()
{
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3f(0,255,1);
 	glLoadIdentity();

  double ar = glutGet(GLUT_WINDOW_WIDTH) / (double)glutGet( GLUT_WINDOW_HEIGHT );
  glOrtho( -escalado * ar, escalado * ar, -escalado, escalado, -1, 1);


  //radio=(GLfloat)largo/3.0;
  //cout<<"radio:"<<radio<<endl;
  GLfloat x,y;
  

  glBegin(GL_POINTS);


  for(int i=45;i<=90;i++)
  {
      x=(GLfloat)radio*cos(i*3.14159f/180.0f);
      y=(GLfloat)radio*sin(i*3.14159f/180.0f);
      cout<<"x"<<x<<endl;
      cout<<"y"<<y<<endl;
      glVertex3f(x,y,0.0);
      glVertex3f(x,-y,0.0);
      glVertex3f(-x,y,0.0);
      glVertex3f(-x,-y,0.0);
      glVertex3f(y,x,0.0);
      glVertex3f(y,-x,0.0);
      glVertex3f(-y,x,0.0);
      glVertex3f(-y,-x,0.0);
    //glVertex3f(x,y,0.0);
  }
 	glEnd();
 	glFlush();
 }

void init()
{
 	glClearColor(0,0,0,0);
}
int main(int argc, char **argv)
{
  //obtengo los lados
  cout<<"insertar radio de la circuferencia (Max 200):\n";
  cin>>radio;
  //angulo = (GLfloat)360/sides*3.14159f/180.0f; // grados a radianes
  //angulo = (GLfloat)360.0f/sides; // grados a radianes
  //cout<<"angulo"<<angulo<<endl;
  //angulo = (GLfloat)i*3.14159f/180.0f; // grados a radianes
  //angulo=360.0/sides;
 	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);

 	glutInitWindowSize(ancho, largo);
 	glutCreateWindow("Drawing with OpenGL");
 	init();
 	//glutDisplayFunc();

 	glutDisplayFunc(display);
 	glutReshapeFunc(reshape);
 	glutMainLoop();
 	return 0;
}
