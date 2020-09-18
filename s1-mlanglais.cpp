// Morgan Langlais
// CS 5388
// Assignment S1
// Fall 2020, Texas State University

#define GL_SILENCE_DEPRECATION
#include <math.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>

void drawCube() {
								glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
								glEnable(GL_DEPTH_TEST);
								glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
								glLoadIdentity();

								glRotatef(35, .5, .5, .5);

								glBegin(GL_POLYGON);
								glColor3f( 1.0, 0.0, 0.0 );
								glVertex3f(  0.5, -0.5, -0.5 );
								glColor3f( 0.0, 1.0, 0.0 );
								glVertex3f(  0.5,  0.5, -0.5 );
								glColor3f( 0.0, 0.0, 1.0 );
								glVertex3f( -0.5,  0.5, -0.5 );
								glColor3f( 1.0, 0.0, 1.0 );
								glVertex3f( -0.5, -0.5, -0.5 );
								glEnd();

								glBegin(GL_POLYGON);
								glColor3f(   1, 1, 0 );
								glVertex3f(  0.5, -0.5, 0.5 );
								glVertex3f(  0.5,  0.5, 0.5 );
								glVertex3f( -0.5,  0.5, 0.5 );
								glVertex3f( -0.5, -0.5, 0.5 );
								glEnd();

								glBegin(GL_POLYGON);
								glColor3f(  1.0,  0.0,  1.0 );
								glVertex3f( 0.5, -0.5, -0.5 );
								glVertex3f( 0.5,  0.5, -0.5 );
								glVertex3f( 0.5,  0.5,  0.5 );
								glVertex3f( 0.5, -0.5,  0.5 );
								glEnd();

								glBegin(GL_POLYGON);
								glColor3f(   0.0,  1.0,  0.0 );
								glVertex3f( -0.5, -0.5,  0.5 );
								glVertex3f( -0.5,  0.5,  0.5 );
								glVertex3f( -0.5,  0.5, -0.5 );
								glVertex3f( -0.5, -0.5, -0.5 );
								glEnd();

								glBegin(GL_POLYGON);
								glColor3f(   0.0,  0.0,  1.0 );
								glVertex3f(  0.5,  0.5,  0.5 );
								glVertex3f(  0.5,  0.5, -0.5 );
								glVertex3f( -0.5,  0.5, -0.5 );
								glVertex3f( -0.5,  0.5,  0.5 );
								glEnd();

								glBegin(GL_POLYGON);
								glColor3f(   1.0,  0.0,  0.0 );
								glVertex3f(  0.5, -0.5, -0.5 );
								glVertex3f(  0.5, -0.5,  0.5 );
								glVertex3f( -0.5, -0.5,  0.5 );
								glVertex3f( -0.5, -0.5, -0.5 );
								glEnd();

								glFlush();
								glutSwapBuffers();
}

void exit(int);

void setWindow()
{
								glMatrixMode(GL_PROJECTION);
								glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
								glEnable(GL_DEPTH_TEST);
								glLoadIdentity();
								glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
}

void setViewport(int left, int right, int bottom, int top)
{
								glViewport(left, bottom, right - left, top - bottom);
}

void myInit(void)
{
								glClearColor(1.0,1.0,1.0,0.0);
								glColor3f(1, 0, 0);
								glLineWidth(4.0);
}

void ngon(int n)
{
								glLoadIdentity();
								glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
								if(n == 1) {
																glPointSize(3);
																glBegin(GL_POINTS);
																glVertex2i(0, 0);
								} else if (n == 2) {
																glBegin(GL_LINES);
																glVertex2f(-.3, 0);
																glVertex2f(.3, 0);
								} else {
																float degree, vertx, verty, rotate, degToRad;
																if(n == 6) {

																}
																rotate = 360.0/n;
																degree = rotate/2 + 180;
																degToRad = 180/3.14159;
																glBegin(GL_POLYGON);
																for(int i = 0; i < n; i++, degree += rotate)
																{
																								vertx = .5 * sin(degree/degToRad);
																								verty = .5 * sin((90 - degree)/degToRad);
																								glVertex3f(vertx, verty, 0);
																}
								}
								glEnd();
								glFlush();
}

void myDisplay(void)
{
								glClear(GL_COLOR_BUFFER_BIT);
								setWindow();
								setViewport(0, 800, 0, 600);
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
								switch(theKey)
								{
								case 'Q':
								case 'q':
																exit(-1);
								case 'P':
								case 'p':
																ngon(1);
																break;
								case 'T':
								case 't':
																ngon(3);
																break;
								case 'S':
								case 's':
																ngon(4);
																break;
								case 'H':
								case 'h':
																ngon(6);
																break;
								case 'C':
								case 'c':
																ngon(30);
																break;
								case 'L':
								case 'l':
																ngon(2);
																break;
								case 'U':
								case 'u':
																drawCube();
																break;
								default:
																break;
								}
}

int main(int argc, char** argv)
{
								glutInit(&argc, argv);
								glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
								glutInitWindowSize(800,600);
								glutInitWindowPosition(100, 150);
								glutCreateWindow("t for triangle, p for point, s for square, u for cube, h for hexagon, c for circle, l for line, q to quit (not case sensitive)");
								glutDisplayFunc(myDisplay);
								glutKeyboardFunc(myKeyboard);
								myInit();
								glutMainLoop();
}
