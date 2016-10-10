#include <iostream>
#include <cstdio>
#include <cmath>
#include <GL/glut.h>
using namespace std;
double X_1, Y_1, X_2, Y_2;

float redondeo(float v)
{
  return floor(v + 0.5);
}

void dibujar_linea()
{
  double dx=(X_2-X_1);
  double dy=(Y_2-Y_1);
  double incremento;
  float xInc,yInc,x=X_1,y=Y_1;
  incremento=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
  xInc=dx/(float)incremento;
  yInc=dy/(float)incremento;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);
  glVertex3f(x,y,0.0);
  
  for(int k=0;k<incremento;k++)
  {
    x+=xInc;
    y+=yInc;
    glVertex3f(redondeo(x), redondeo(y),0.0);
  }
  glEnd();

  glFlush();
}
void Init()
{
  glClearColor(0.0,0.0,0.0,0);
  gluOrtho2D(-640 , 640 , -480 , 480);
}
int main(int argc, char **argv)
{
  cout<<"INGRESE LOS DOS PUNTOS:\n";  
  cout<<"\n INGRESE EL PUNTO 1  X_1 , Y_1:\n";
  scanf("%lf%lf",&X_1,&Y_1);

  //cout<<"primeros puntos"<<X_1<<Y_1;
  cout<<"\n INGRESE EL PUNTO 2 X_2 , Y_2:\n";
  scanf("%lf%lf",&X_2,&Y_2);

  //cout<<"segundos puntos"<<X_2<<Y_2;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("LINEA INCREMNTAL");
  Init();
  glutDisplayFunc(dibujar_linea);
  glutMainLoop();
  return 0;
}