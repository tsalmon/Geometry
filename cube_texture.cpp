#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdlib>
#include "sdlglutils.h"

void Dessiner();
 
double angleZ = 0;
double angleX = 0;
GLuint texture1; 
GLuint texture2;
int main(int argc, char *argv[])
{
  SDL_Event event;
 
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("SDL GL Application", NULL);
  SDL_SetVideoMode(1920, 1080, 32, SDL_OPENGL);
 
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective(70,(double)1920/1080,1,1000);
 
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D); 
  Dessiner();
 
  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time,ellapsed_time;
  Uint32 start_time;
  texture1 = loadTexture("stainedglass05.jpg");
  texture2 = loadTexture("metal090r.jpg");  
  for (;;)
    {
      start_time = SDL_GetTicks();
      while (SDL_PollEvent(&event))
        {
 
	  switch(event.type)
            {
	    case SDL_QUIT:
	      exit(0);
	      break;
            }
        }
 
      current_time = SDL_GetTicks();
      ellapsed_time = current_time - last_time;
      last_time = current_time;
 
      angleZ += 0.05 * ellapsed_time;
      angleX += 0.05 * ellapsed_time;
 
      Dessiner();
 
      ellapsed_time = SDL_GetTicks() - start_time;
      if (ellapsed_time < 10)
        {
	  SDL_Delay(10 - ellapsed_time);
        }
 
    }
 
  return 0;
}
 
void Dessiner()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity( );
 
  gluLookAt(3,4,2,0,0,0,0,0,1);
 

  glBindTexture(GL_TEXTURE_2D, texture2);
  glBegin(GL_QUADS);
  glColor3ub(255,0, 0);
  glTexCoord2i(0,0);      glVertex3i(-10,-10,-1);
  glColor3ub(255,255, 255);
  glTexCoord2i(10,0);     glVertex3i(10,-10,-1);
  glColor3ub(255,255, 255);
  glTexCoord2i(10,10);    glVertex3i(10,10,-1);
  glTexCoord2i(0,10);     glVertex3i(-10,10,-1);
  glEnd();

  glRotated(angleZ,0,0,1);
  glRotated(angleX,1,0,0);

  glBindTexture(GL_TEXTURE_2D, texture1); 

  /*
  glBegin(GL_QUADS);
  glTexCoord2d(0,1);  glVertex3d(1,1,1);
  glTexCoord2d(0,0);  glVertex3d(1,1,-1);
  glTexCoord2d(1,0);  glVertex3d(-1,1,-1);
  glTexCoord2d(1,1);  glVertex3d(-1,1,1);
  glEnd();
  */

  glBegin(GL_QUADS);
 
  glTexCoord2d(0,1);
  glVertex3d(1,1,1);
  glTexCoord2d(0,0);
  glVertex3d(1,1,-1);
  glTexCoord2d(1,0);
  glVertex3d(-1,1,-1);  
  glTexCoord2d(1,1);
  glVertex3d(-1,1,1);
 
  glTexCoord2d(0,1);
  glVertex3d(1,-1,1);
  glTexCoord2d(0,0);
  glVertex3d(1,-1,-1);
  glTexCoord2d(1,0);
  glVertex3d(1,1,-1);
  glTexCoord2d(1,1);
  glVertex3d(1,1,1);
 
  //face bleue 
  glTexCoord2d(0,1);
  glVertex3d(-1,-1,1);
  glTexCoord2d(0,0);
  glVertex3d(-1,-1,-1);
  glTexCoord2d(1,0);
  glVertex3d(1,-1,-1);
  glTexCoord2d(1,1);
  glVertex3d(1,-1,1);
  
  //face jaune
  //glColor3ub(255,255,0); 
  glTexCoord2d(0,1);
  glVertex3d(-1,1,1);
  glTexCoord2d(0,0);
  glVertex3d(-1,1,-1);
  glTexCoord2d(1,0);
  glVertex3d(-1,-1,-1);
  glTexCoord2d(1,1);
  glVertex3d(-1,-1,1);
 
  //face cyan
  //glColor3ub(0,255,255); 
  glTexCoord2d(0,0);
  glVertex3d(1,1,-1);
  glTexCoord2d(0,1);
  glVertex3d(1,-1,-1);
  glTexCoord2d(1,1);
  glVertex3d(-1,-1,-1);
  glTexCoord2d(1,0);
  glVertex3d(-1,1,-1);
 
  //glColor3ub(255,0,255); //face magenta
  glTexCoord2d(0,1);
  glVertex3d(1,-1,1);
  glTexCoord2d(0,0);
  glVertex3d(1,1,1);
  glTexCoord2d(1,0);
  glVertex3d(-1,1,1);
  glTexCoord2d(1,1);
  glVertex3d(-1,-1,1);
 
  glEnd();
  
  glFlush();
  SDL_GL_SwapBuffers();
}
