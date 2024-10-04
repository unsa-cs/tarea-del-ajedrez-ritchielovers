#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "chess.h"

void setColor(char c) {
  switch (c) {
  case '_':
    glColor3f(1.0f, 1.0f, 1.0f);
    break; // white
  case '=':
    glColor3f(0.5f, 0.5f, 0.5f);
    break; // gray
  case '.':
    glColor3f(1.0f, 1.0f, 1.0f);
    break; // white
  case '@':
    glColor3f(0.0f, 0.0f, 0.0f);
    break; // black
  case '#':
    glColor3f(0.2f, 0.2f, 0.2f);
    break; // dark gray
  default:
    glColor3f(0.0f, 1.0f, 0.0f);
    break; // green
  }
}

void interpreter(char **fig) {
  glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing
                                // color
  glBegin(GL_QUADS);            // Each set of 4 vertices form a quad

  int j = 0;
  // Tamaño de las figuras
  float pixel = 0.211;
  while (fig[j]) {
    int i = 0;
    while (fig[j][i]) {
      setColor(fig[j][i]);
      float x = 1.0 + i * pixel;
      float y = 1.0 + j * pixel;
      // Vertices de cada figura
      // Izquierda superiot
      glVertex2f(x, y);
      // Derecha superior
      glVertex2f(x + pixel, y);
      // Derecha inferior
      glVertex2f(x + pixel, y + pixel);
      // Izquierda inferior
      glVertex2f(x, y + pixel);
      i++;
    }
    j++;
  }

  glEnd();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(0, 0);   // origin on the window system
  glutInitWindowSize(1000, 1000); // window´s size
  glutCreateWindow("Chess");

  glClearColor(1.0, 1.0, 1.0, 0.0); // black background
  glMatrixMode(GL_PROJECTION);       // setup viewing projection
  glLoadIdentity();                  // start with identity matrix
  glOrtho(0.0, 100.0, 100.0, 0.0, -1.0,
          1.0); // setup a 100x100x2 viewing world

  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
