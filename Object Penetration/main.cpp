//1. Prajnadip Das Samya 22-46258-1
//2. Mir Md Mofakkar Hossain 22-46245-1
//3. Nazifa Tabushum Turaba 22-46271-1
//4. Asif Uddin Sazid 22-46282-1
//Section-J

#include<windows.h>
#include<gl/glut.h>
#define dx 32
#define dy 32
#define maxrow 25
#define maxcol 25
#include<math.h>
#include<string.h>
#include<stdio.h>
double x11, y11;
GLfloat z11=-650;
int i11=0;

double x22, y22;
int i22=0;
GLfloat z22=-650;

double x33, y33;
int i33=0;
GLfloat z33=-650;

double six, siy;
int si=0;

double si1x, si1y;
int si1=0;

double si2x, si2y;
int si2=0;

GLint i, j;
GLint x[maxcol], y[maxrow];
double trw=1.4;
double tmw=1.4;
double tlw=1.45;

void init()
{
    glClearColor(0.0,0.0,1.0,0.0); // Set clear color to blue
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void clearscreenfunc()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void rwall()   //right
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float ambient[] = { 0.9,0.3,0.5,1 };  //set rgb color
    float light_pos[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
       glRotatef(50, 0, 1, 0);
       glRotatef(10, -1, 0, 0);
       glRotatef(11.7, 0, 0, -1);
       glTranslatef(0.4, trw, 0.4);
       glScalef(0.5, 1.2, 0.07);
       glutSolidCube(1);
    }
void mwall() //middle
{
       glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       float ambient[] = { 0.7,0.8,0.7,1 };
       float light_pos[] = { 27,8,2,3 };
       glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glRotatef(50, 0, 1, 0);
	glRotatef(10, -1, 0, 0);
	glRotatef(11.7, 0, 0, -1);
	glTranslatef(0.1, tmw, 0.1);
       glScalef(0.5, 1.2, 0.04);
	glutSolidCube(1);
}
void lwall()  //left
{
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
     	float ambient[] = { 1.0,1.0,1.0,1.0}; //white lighting
       float light_pos[] = { 27,8,2,3};
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glRotatef(50, 0, 1, 0);
	glRotatef(10, -1, 0, 0);
	glRotatef(11.7, 0, 0, -1);
	glTranslatef(-0.2, tlw, -0.2);
       glScalef(0.4, 1.2, 0.01);
	glutSolidCube(1);
}
void floor()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
       gluLookAt(0.09, -18.0, 3.0, 0.0, 0.0, 2.5, 0.0, 1.0, 0.0);
	glTranslatef(-8, -10, -2);
       glDisable(GL_LIGHTING);
	glColor3f(0.2,0.4,0.4);
	glScalef(0.02, 0.02, 0.02);
	glLineWidth(2.0);
	for (i = 0; i <= maxcol - 1; i++)
		x[i] = x[0] + i*dx;
	for (j = 0; j <= maxrow - 1; j++)
		y[j] = y[0] + j*dy;
	for (i = 0; i < maxcol - 1; i++)
	{
		for (j = 0; j < maxrow - 1; j++)
		{
			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i], y[j]);
			glVertex2f(x[i], y[j + 1]);
			glVertex2f(x[i + 1], y[j + 1]);
			glVertex2f(x[i + 1], y[j]);
			glEnd();
		}
	}
}
void gamma() //bottom;
{
       glDisable(GL_LIGHTING);
    	glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
	glDisable(GL_LIGHTING);
	glTranslatef(z11,-45,0);
	glPointSize(5);
	glColor3f(1.0, 1.0, 0.0);
	GLfloat qa=0;
	for (GLfloat i11 = -1400; i11<=qa+10000; i11 = i11+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x11,y11);
       x11 = -(float)i11;
       if(i11>=9995 && i11 <= 9998) qa = 10000;
       else if(i11>=19995 && i11 <= 19998) qa = 20000;
       else if(i11>=29995 && i11 <= 29998) qa = 30000;
       else if(i11>=39995 && i11<= 39998) qa = 40000;
       else if(i11>=49995 && i11<=49998) qa = 60000;
	y11 = 10.0 * sin(i11 *(35.284 / 360.0));
	glEnd();
}
z11+=2;
}
void beta()  //middle
{
 	glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       glColor3f(1,0,0.7);
	glTranslatef(z22,5,0);
	glPointSize(5);
	glColor3f(0.6, 0.3, 0.8);
	GLfloat wa=0;
	for (GLfloat i22 = -1400; i22<=wa+10000; i22 = i22+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x22,y22);
       x22 = -(float)i22;
       if(i22>=9995 && i22 <= 9998) wa = 10000;
       else if(i22>=19995 && i22 <= 19998) wa = 20000;
       else if(i22>=29995 && i22 <= 29998) wa = 30000;
       else if(i22>=39995 && i22<= 39998) wa = 40000;
       else if(i22>=49995 && i22<=49998) wa = 60000;
	y22 = 5.0 * sin(i22 *(35.284 / 360.0)); //increase 1st increase height,increase 2nd decrease width
	glEnd();
}
z22+=1.4;
}
void alpha()  //top
{
 	glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       double w = glutGet(GLUT_WINDOW_WIDTH);
       double h = glutGet(GLUT_WINDOW_HEIGHT);
	double ar = w / h;
	glOrtho(-360 * ar, 360 * ar, -120, 120, -1, 1);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
	glTranslatef(z33,40,0);
	glPointSize(5);
	glColor3f(0.9, 0., 0.4);
	for (GLfloat i33 = -1400; i33<=80200; i33 = i33+4)
{
       glBegin(GL_POINTS);
       glVertex2f(x33,y33);
       x33 = -(float)i33;
	y33 = 5.0 * sin(i33 *(15.284 / 360.0));  //increase 1st increase height,increase 2nd decrease width
	glEnd();
}
z33+=1.6;
}
void molecules()
{
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
//glClearColor(1,0,0,0);
       float ambient[] = { 0.7,0.1,0.1,1 };
       float light_pos[] = { 2,8,2,3 };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

       glTranslatef(-0.7,0.3,0.075);
       glutSolidSphere(0.08,100,100);
       float ambient1[] = { 0.1,0.3,1.0,1 };
       float light_pos1[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
       glTranslatef(0,-0.3,0);
       glutSolidSphere(0.06,100,100);
       float ambient2[] = { 0.1,1.0,0.1,1 };
       float light_pos2[] = { 27,8,2,3 };
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos2);
       glTranslatef(0,-0.4,0);
       glutSolidSphere(0.09,100,100);
}
void specialkeyboard(int key,int x,int y)
{
       switch(key)
       {
       case GLUT_KEY_DOWN:
              {
                            tmw=-0.1;// go meddile  object and check
                            break;
              }
       case GLUT_KEY_LEFT:
              {
                  tlw=-0.1;// go leftwall  object and check
                  break;
              }
       case GLUT_KEY_RIGHT:
              {
                       trw=0.05;//go right wall  object and check
                       break;
              }
       case GLUT_KEY_PAGE_DOWN:
              {
                     trw=1.45;
                     break;
              }
       case GLUT_KEY_PAGE_UP:
              {
                     tmw=1.4;
                     break;
              }
       case GLUT_KEY_END:
              {
                     tlw=1.4;
                     break;
              }
       }
}
void getCompnentsDiscxn()
{
    	char comp_paper[]="PAPER";
	 	char comp_alm[]="ALLUMINIUM";
	 	char comp_lead[]="LEAD";
	 	char al[]="Alpha Ray";
	 	char be[]="Beta Ray";
	 	char ga[]="Gamma Ray";
	 	char ml[]="Molecules";
	 	char rp[]="Radio-active Elements";
	 	char pr[]="Computer graphics; ";
	 	char pr_task[]="Final Term project";
	 	char tp[]="";
	 	char tpp[]="";
	 	char by[]=" ";
	 	char usn[]=" ";
       glDisable(GL_LIGHTING);
       glColor3f(1,1,1);
	glRasterPos2f(0.33,-0.35);
	for(int iqa=0;iqa<strlen(comp_paper);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,comp_paper[iqa]);
       }
       glRasterPos2f(0.67,-0.35);
	for(int iqa=0;iqa<strlen(comp_alm);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,comp_alm[iqa]);
       }
       glRasterPos2f(1.18,-0.25);
	for(int iqa=0;iqa<strlen(comp_lead);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,comp_lead[iqa]);
       }
       glRasterPos2f(-0.3,0.7);
	for(int iqa=0;iqa<strlen(al);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,al[iqa]);
       }
       glRasterPos2f(-0.3,0.37);
	for(int iqa=0;iqa<strlen(be);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,be[iqa]);
       }
       glRasterPos2f(-0.3,-0.01);
	for(int iqa=0;iqa<strlen(ga);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ga[iqa]);
       }
       glRasterPos2f(-0.1,0.83);
	for(int iqa=0;iqa<strlen(ml);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ml[iqa]);
       }
       glRasterPos2f(0.6,0.95);
	for(int iqa=0;iqa<strlen(rp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,rp[iqa]);
       }
       glColor3f(0,0,0.2);
       glRasterPos2f(0.0,-0.47);
	for(int iqa=0;iqa<strlen(pr);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pr[iqa]);
       }
       glColor3f(1,0,0);
        glRasterPos2f(0,-0.55);
	for(int iqa=0;iqa<strlen(pr_task);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pr_task[iqa]);
       }
       glRasterPos2f(1.24,-0.5);
	for(int iqa=0;iqa<strlen(tp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,tp[iqa]);
       }
       glRasterPos2f(1.38,-0.6);
	for(int iqa=0;iqa<strlen(tpp);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,tpp[iqa]);
       }
       glRasterPos2f(1.24,-0.2);
	for(int iqa=0;iqa<strlen(by);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,by[iqa]);
       }
       glRasterPos2f(1.24,-0.3);
	for(int iqa=0;iqa<strlen(usn);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,usn[iqa]);
       }
}
//The getHow2Operate Function displays ' how to operate?' instruction
void getHow2Operate()
{
    char InxnVarb[]={"How to Operate?"};
    char acxnKey[]={"==>To Activate Paper, Aluminum or Lead:-"};
    char pressAcxnKey[]={"   Press <-,DownArrow or -> button, respectively."};
    char deacxnKey[]={"==>To Deactivate Paper, Aluminum or Lead:-"};
    char pressDeacxnKey[]={"   Press end,pg up or pg dn button, respectively."};
   glColor3f(1,0.5,0);
   glRasterPos2f(-0.2,1.3);
	for(int iqa=0;iqa<strlen(InxnVarb);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,InxnVarb[iqa]);
       }
       glColor3f(0,0,0);
       glRasterPos2f(-0.3,1.23);
	for(int iqa=0;iqa<strlen(acxnKey);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_9_BY_15,acxnKey[iqa]);
       }
       glRasterPos2f(-0.3,1.18);
	for(int iqa=0;iqa<strlen(pressAcxnKey);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pressAcxnKey[iqa]);
       }
       glRasterPos2f(-0.3,1.11);
	for(int iqa=0;iqa<strlen(deacxnKey);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_9_BY_15,deacxnKey[iqa]);
       }
       glRasterPos2f(-0.3,1.05);
       for(int iqa=0;iqa<strlen(pressDeacxnKey);iqa++)
       {
              glutBitmapCharacter(GLUT_BITMAP_9_BY_15,pressDeacxnKey[iqa]);
       }
       glColor3f(1,0,0);
       glRasterPos2f(-0.3,1.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(200,0,w,h);
	gamma();
	if(tlw!=-0.1)
      {
             glViewport(200,0,w,h);
             alpha();
      }
      else
       {
              glViewport(200,0,w-1000,h);
              alpha();
       }
    if(tmw!=-0.1)
            {
                glViewport(200,0,w,h);
    	       beta();
            }else
            {
                glViewport(200,0,w-700,h);
                beta();
            }
	glViewport(0,0,w,h);
	rwall();
	mwall();
	lwall();
	molecules();
	 getCompnentsDiscxn();
    getHow2Operate();
	floor();
	glFlush();
}
void keybordfunc(unsigned char key,GLint xmouse,GLint ymouse)
{
   switch(key)
   {
       case'n':
           exit(0);
           break;
    }
}
void update(int value)
{
		glutPostRedisplay();
		glutTimerFunc(1, update, 0);
}
int main(int argc, char **argv)
{
    x[0] = 1;
	y[0] = 1;
	glutInit(&argc, argv);
	glutInitWindowSize(1400, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Demonstration of Radio-active Elements");
	init();
	glutDisplayFunc(display);
	glutTimerFunc(0, update, 0);
	glutSpecialFunc(specialkeyboard);
    glutKeyboardFunc(keybordfunc);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
