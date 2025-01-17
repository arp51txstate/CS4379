#include <QtGui/QtGui>
#include <QtOpenGL/QtOpenGL>
#include <math.h>
#include "globj.h"

GLobj::GLobj(QWidget *parent)
    : QGLWidget(parent)
{

}

GLobj::~GLobj()
{

}

//Initialize
void GLobj::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
}

//Set up the viewport
void GLobj::resizeGL( int w, int h )
{
    if(w>h)
        glViewport((w-h)/2, 0, h, h);
    else
        glViewport(0, (h-w)/2, w, w);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

//Paints the GL scene
void GLobj::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glPointSize(4.0f);
    glLineWidth(2.0f);

    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glColor3f (1.0, 0.25, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.4f, 0.4f, 0.2f);
    glVertex3f(0.47f, 0.47f, 0.2f);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f,-0.25f,0.0f);
    glVertex3f(-0.5f,-0.25f,0.0f);
    glVertex3f(-0.75f,0.25f,0.0f);
    glEnd();

    glColor3f (0.25, 0.25, 1.0);
    glBegin(GL_POLYGON);
      glVertex3f(-0.75f,-0.75f,0.0f);
      glVertex3f(-0.95f,-0.75f,0.0f);
      glVertex3f(-0.95f,-0.95f,0.0f);
      glVertex3f(-0.75f,-0.95f,0.0f);
  glEnd();

    glColor3f (0.25, 1.0, 1.0);
    glBegin(GL_POLYGON);
      glVertex3f(0.8f,0.90f,0.0f);
      glVertex3f(0.9f,0.90f,0.0f);
      glVertex3f(0.95f,0.85f,0.0f);
      glVertex3f(0.9f,0.8f,0.0f);
      glVertex3f(0.8f,0.8f,0.0f);
      glVertex3f(0.75f,0.85f,0.0f);
    glEnd();

   glBegin(GL_QUADS);

      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 0.25f, 0.25f, -0.25f);
      glVertex3f(-0.25f, 0.25f, -0.25f);
      glVertex3f(-0.25f, 0.25f,  0.25f);
      glVertex3f( 0.25f, 0.25f,  0.25f);

      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 0.25f, -0.25f,  0.25f);
      glVertex3f(-0.25f, -0.25f,  0.25f);
      glVertex3f(-0.25f, -0.25f, -0.25f);
      glVertex3f( 0.25f, -0.25f, -0.25f);

      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.25f,  0.25f, 0.25f);
      glVertex3f(-0.25f,  0.25f, 0.25f);
      glVertex3f(-0.25f, -0.25f, 0.25f);
      glVertex3f( 0.25f, -0.25f, 0.25f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 0.25f, -0.25f, -0.25f);
      glVertex3f(-0.25f, -0.25f, -0.25f);
      glVertex3f(-0.25f,  0.25f, -0.25f);
      glVertex3f( 0.25f,  0.25f, -0.25f);

      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-0.25f,  0.25f,  0.25f);
      glVertex3f(-0.25f,  0.25f, -0.25f);
      glVertex3f(-0.25f, -0.25f, -0.25f);
      glVertex3f(-0.25f, -0.25f,  0.25f);

      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(0.25f,  0.25f, -0.25f);
      glVertex3f(0.25f,  0.25f,  0.25f);
      glVertex3f(0.25f, -0.25f,  0.25f);
      glVertex3f(0.25f, -0.25f, -0.25f);
   glEnd();

    glFlush ();
}

