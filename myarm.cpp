#include <math.h>
#include "glut.h"

// starting postions of the hand 
static int shoulder = 0, elbow = 0, wrist = 0, thumb = 0, index = 0, middle = 0, ring = 0, little = 0;

int windowWidth = 1024;
int windowHeight = 768;

float aspect = float(windowWidth) / float(windowHeight);


double eye[] = {0,0,1};
double center[] = {0,0,0};
double up[] = {0,1,0};


void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1]*b[2] - a[2]*b[1];
	c[1] = a[2]*b[0] - a[0]*b[2];
	c[2] = a[0]*b[1] - a[1]*b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0]*a[0] + a[1]*a[1] + a[2]*a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

double temp[3];
temp[0] = p[0];
temp[1] = p[1];
temp[2] = p[2];

temp[0] = -a[2]*p[1] + a[1]*p[2];
temp[1] = a[2]*p[0] - a[0]*p[2];
temp[2] = -a[1]*p[0] + a[0]*p[1];

temp[0] *= sin(theta);
temp[1] *= sin(theta);
temp[2] *= sin(theta);

temp[0] += (1-cos(theta))*(a[0]*a[0]*p[0] + a[0]*a[1]*p[1] + a[0]*a[2]*p[2]);
temp[1] += (1-cos(theta))*(a[0]*a[1]*p[0] + a[1]*a[1]*p[1] + a[1]*a[2]*p[2]);
temp[2] += (1-cos(theta))*(a[0]*a[2]*p[0] + a[1]*a[2]*p[1] + a[2]*a[2]*p[2]);

temp[0] += cos(theta)*p[0];
temp[1] += cos(theta)*p[1];
temp[2] += cos(theta)*p[2];

p[0] = temp[0];
p[1] = temp[1];
p[2] = temp[2];

}

void Left()
{
	double speed = 3.1415/8;
	rotatePoint(up,speed,eye);
}

void Right()
{
	double speed = 3.1415/8;
	rotatePoint(up,-speed,eye);
}

void Up()
{
	double speed = 3.1415/8;
	double rot_axis[3];
	double look[3];

	look[0] = -eye[0];
	look[1] = -eye[1];
	look[2] = -eye[2];

	crossProduct(look,up,rot_axis);

	normalize(rot_axis);

	rotatePoint(rot_axis,speed,eye);

	rotatePoint(rot_axis,speed,up);

}

void Down()
{
	double speed = 3.1415/8;
	double rot_axis[3];
	double look[3];

	look[0] = -eye[0];
	look[1] = -eye[1];
	look[2] = -eye[2];

	crossProduct(look,up,rot_axis);

	normalize(rot_axis);

	rotatePoint(rot_axis,-speed,eye);

	rotatePoint(rot_axis,-speed,up);

}

void display ( void )
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glClear (GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0],eye[1],eye[2],center[0],center[1],center[2],up[0],up[1],up[2]);

	  
	glScalef (0.1, 0.1, 0.1);


	//Shoulder
  
   glTranslatef (-1.0, 0.0, 0.0);         

   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,0.0);
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   
   
   //Elbow
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.0,1.0,0.0);
   glScalef (2.0, 0.4, 1.0);
   glutWireCube (1.0);
   glPopMatrix();
   
   //wrist
   glTranslatef (1.0, 0.0, 0.0);
   glRotatef (-(GLfloat) wrist, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.0);
   glPushMatrix();
   glColor3f(0.0,0.0,1.0);
   glScalef (0.5, 0.4, 1.0);
  glutWireCube (1.0);
   glPopMatrix();
   
   
   //Thumb
   glPushMatrix();
   glTranslatef (0.0, 0.125, -0.2);
   glRotatef (-(GLfloat) thumb, 0.0, 0.0, 1.0);
   glTranslatef (0.3, 0.0, 0.8);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.5, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   
   glTranslatef (0.15, 0.0, -0.8);
   glRotatef (-(GLfloat) thumb, 0.0, 0.0, 1.0);
   glTranslatef (0.25, 0.0, 0.8);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.5, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();
   
   
   //Pointer Finger
   glPushMatrix();
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef (-(GLfloat) index, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.4);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef (-(GLfloat) index, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();       
   glPopMatrix();
 
   
   //Middle Finger
   glPushMatrix();
   glTranslatef (0.5, 0.10, 0.0);
   glRotatef (-(GLfloat) middle, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   
   glTranslatef (0.5, 0.0, 0.0);
   glRotatef (-(GLfloat) middle, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();
   
   
   //Ring Finger
   glPushMatrix();
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef (-(GLfloat) ring, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, -0.4);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   
   glTranslatef (0.5, 0.1, 0.0);
   glRotatef (-(GLfloat) ring, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.1,  0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();
   
   
   //little Finger
   glPushMatrix();
   glTranslatef (0.2, 0.1, 0.0);
   glRotatef (-(GLfloat) little, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, -0.6);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.5, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (0.4, 0.1, 0.0);
   glRotatef (-(GLfloat) little, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.1, 0.0);
   glPushMatrix();
   glColor3f(1.0,0.0,1.0);
   glScalef (0.6, 0.2, 0.2);
   glutWireCube (1.0);
   glPopMatrix();
   glPopMatrix();

  
	glFlush ();
	glutSwapBuffers();
}


void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
    
      //Elbow
      case '1':
	 if (elbow < 160)
         elbow = (elbow + 5) ;
         glutPostRedisplay();
         break;
      case '!':
	 if (elbow > 0)
         elbow = (elbow - 5);
         glutPostRedisplay();
         break;
      //wrist
      case '2':
	 if (wrist < 90)
	 wrist = (wrist + 5) ;
         glutPostRedisplay();
         break;
      case '@':
	 if (wrist > 0)
	 wrist = (wrist - 5) ;
         glutPostRedisplay();
         break;
	 
      //Thumb 
      case '5':
	 if (thumb < 90)
         thumb = (thumb + 5) ;
         glutPostRedisplay();
         break;
      case '%':
	 if (thumb > 0)
         thumb = (thumb - 5);
         glutPostRedisplay();
         break;
	 
      //Pointer Finger
      case '6':
	 if (index < 90)
         index = (index + 5) ;
         glutPostRedisplay();
         break;
      case '^':
	 if (index > 0)
         index = (index - 5) ;
         glutPostRedisplay();
         break;
	 
      //Middle Finger
      case '7':
	 if (middle < 90)
         middle = (middle + 5);
         glutPostRedisplay();
         break;
      case '&':
	 if (middle > 0)
         middle = (middle - 5) ;
         glutPostRedisplay();
         break;
	 
      //Ring Finger
      case '8':
	 if (ring < 90)
         ring = (ring + 5) ;
         glutPostRedisplay();
         break;
      case '*':
	 if (ring > 0)
         ring = (ring - 5) ;
         glutPostRedisplay();
         break;
	 
      //little Finger
      case '9':
	 if (little < 90)
         little = (little + 5) ;
         glutPostRedisplay();
         break;
      case '(':
	 if (little > 0)
         little = (little - 5);
         glutPostRedisplay();
	 break;

      //Entire Hand
      case '3':
         if (thumb < 90)
         thumb = (thumb + 5) ;
         if (index < 90)
         index = (index + 5) ;
         if (middle < 90)
         middle = (middle + 5) ;
         if (ring < 90)
         ring = (ring + 5) ;
         if (little < 90)
         little = (little + 5) ;
         glutPostRedisplay();
         break;
	  case '#':
         if (thumb > 0)
         thumb = (thumb - 5) ;
         if (index > 0)
         index = (index - 5) ;
         if (middle > 0)
         middle = (middle - 5);
         if (ring > 0)
         ring = (ring - 5) ;
	 if (little > 0)
         little = (little - 5) ;
         glutPostRedisplay();
	 break;

      
      default:
         break;
   }
}



void specialKeys(int key, int x, int y)
{
	switch( key )
	{
		case GLUT_KEY_LEFT  : Left(); break;
        case GLUT_KEY_RIGHT : Right() ; break;
        case GLUT_KEY_UP :    Up() ; break;
        case GLUT_KEY_DOWN :  Down() ; break;
	}

    glutPostRedisplay();
}

int main ( void )
{

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Cyrstall Ball Interface Example");

	glMatrixMode(GL_PROJECTION);
	gluPerspective(60,aspect,0,10);


	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}

