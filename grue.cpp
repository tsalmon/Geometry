//g++ -o grue grue.cpp `sdl-config --cflags --libs` -lGL -lGLU
#include <stdio.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define LARGEUR_ECRAN 640
#define HAUTEUR_ECRAN 480

#define SOCLE_X 150
#define SOCLE_Y 50

#define COU_X 50
#define COU_Y 300

#define BRAS_X 150
#define BRAS_Y 30

#define BOITE_X 25
#define BOITE_Y 50

int tige = 200;
int rot_cou = 0;
int rot_bras = 0;
bool shift = false;

/*
    Dessine le repère actuel pour faciliter
    la compréhension des transformations.
    Utiliser « echelle » pour avoir un repère bien orienté et positionné
    mais avec une échelle différente.
*/
void dessinerRepere(unsigned int echelle = 1)
{
  glPushMatrix();
  glScalef(echelle,echelle,echelle);
  glBegin(GL_LINES);
  glColor3ub(0,0,255);
  glVertex2i(0,0);
  glVertex2i(1,0);
  glColor3ub(0,255,0);
  glVertex2i(0,0);
  glVertex2i(0,1);
  glEnd();
  glPopMatrix();
}

void carre(float x1, float y1, float x2, float y2, int color_r, int color_g, int color_b)
{
  glBegin(GL_POLYGON);
  glColor3ub(color_r, color_g, color_b);    
  glVertex2d(x1, y1);
  glColor3ub(color_r, color_g, color_b);   
  glVertex2d(x1, y2);
  glColor3ub(color_r, color_g, color_b);  
  glVertex2d(x2, y2);
  glColor3ub(color_r, color_g, color_b);    
  glVertex2d(x2, y1);
  glEnd();  
}

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface* ecran = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);
  SDL_Flip(ecran);
  bool continuer = true;
  SDL_Event event;
  SDL_EnableKeyRepeat(10,10);
  SDL_WM_SetCaption("Grue", NULL);
  SDL_SetVideoMode(LARGEUR_ECRAN, HAUTEUR_ECRAN, 32, SDL_OPENGL);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluOrtho2D(0,LARGEUR_ECRAN,0,HAUTEUR_ECRAN);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      switch(event.type)
        {
	case SDL_KEYDOWN:
	  switch(event.key.keysym.sym)
	    {
	    case SDLK_RSHIFT:
	      shift = true;
	      break;
	    case SDLK_LSHIFT:
	      shift = true;
	      break;
	    case SDLK_UP:
	      if(!shift)
		rot_bras++;
	      else
		tige--;
	      break;
	    case SDLK_DOWN:
	      if(!shift)
		rot_bras--;
	      else
		tige++;
	      break;
	    case SDLK_RIGHT:
	      if(!shift)
		rot_cou++;
	      break;
	    case SDLK_LEFT:
	      if(!shift)
		rot_cou--;
	      break;
	    default:
	      break;
	    }
	  break;
	case SDL_KEYUP:
	  switch(event.key.keysym.sym)
	    {
	    case SDLK_RSHIFT:
	      shift = false;
	      break;
	    case SDLK_LSHIFT:
	      shift = false;
	      break;
	    }
	  break;
	case SDL_QUIT:
	  continuer = false;
        }
      
      glClear(GL_COLOR_BUFFER_BIT);
      /* socle */
      glPushMatrix();
      glTranslated(50, 30, 0);
      carre(0, 0, SOCLE_X, SOCLE_Y, 255, 127, 0);
      
      /* cou */
      glPushMatrix();
      glTranslated(50, 30, 0);
      glRotated(rot_cou, 0, 0, 1);
      carre(0, 0, COU_X, COU_Y, 255, 255, 0);
      
      /* bras */
      glPushMatrix();
      glTranslated(COU_X-25, COU_Y-15, 0);
      glRotated(rot_bras, 0, 0, 1);
      carre(0, 0, BRAS_X, BRAS_Y, 0, 255, 0);
      
      /* tige */
      glPushMatrix();
      glTranslated(BRAS_X, BRAS_Y-15, 0);
      glRotated(-rot_bras-rot_cou, 0, 0, 1);
      carre(0, 0, 1, -tige, 255, 255, 255);
      
      /* boite */
      glPushMatrix();
      glTranslated(0, -tige, 0);
      carre(-25, 0, BOITE_X, BOITE_Y, 91, 59, 17);
      
      glPopMatrix();
      glPopMatrix();
      glPopMatrix();
      glPopMatrix();
      glPopMatrix();
      glFlush();
      SDL_GL_SwapBuffers();
      
    }
  SDL_Quit();
 
  return 0;
}
