#include "GL/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Lib(pict).h" 
float pos_x = -5, pos_y = 5.2;

void renderScene(void);
bool isVictory = false;
bool isDeaf = false;
bool isGetRat[3] = { false,false,false};
bool isOpenDoor[3] = { false, false, false };
bool isVictory1 = false;


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
	glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glPushMatrix();
    drawCSENA();
    if (!isGetRat[0])
    drawRat(0,0);
    drawWalls();
    if (isVictory1)
    drawViktory();

    drawExcit(0.3,-0.5);
    if (!isVictory1)
    drawKosa(pos_x, pos_y, 0);
   
    
    
    glutSwapBuffers(); 
}

void processKeys(unsigned char key, int x, int y) {

    if (key == 113)
        exit(0); 
    if (key == 100) {
        pos_x = pos_x + 0.1;

    }
    if (key == 97) {
        pos_x = pos_x - 0.1;

    }

    if (key == 119) {
        pos_y = pos_y + 0.1;

    }
    if (key == 115) {
        pos_y = pos_y - 0.1;

    }
   if (((pos_x>=-9) && (pos_x<=-5.9) &&(pos_y>=-9)&&(pos_y<=9))
       || ((pos_x >= -4) && (pos_x <= -1.8) && (pos_y >= -3.2) && (pos_y <= 9))
       || ((pos_x >= 5.9) && (pos_x <= 9) && (pos_y >= -9) && (pos_y <= 9))
       || ((pos_x >= -9) && (pos_x <= 9) && (pos_y >= 5.9) && (pos_y <= 9))
       || ((pos_x >= -9) && (pos_x <= 9) && (pos_y >= -9) && (pos_y <= -5.9))
       || ((pos_x >= -.15) && (pos_x <= 9) && (pos_y >= -3.2) && (pos_y <= -0.57))
        || ((pos_x >= -.15) && (pos_x <= 1.9) && (pos_y >= -3.2) && (pos_y <= 4))
       || ((pos_x >= -.15) && (pos_x <= 4.6) && (pos_y >= 2.7) && (pos_y <= 4))
       )
       pos_x = -5, pos_y = 5.2;
   if ((pos_x >= 2.3) && (pos_x <= 2.9) && (pos_y >= 2) && (pos_y <= 2.5))
       isVictory1 = true;
   if ((pos_x >= -0.75) && (pos_x <= -0.65) && (pos_y >= 0.55) && (pos_y <= 0.65))
       isGetRat[0] = true;
   
   
    glutPostRedisplay();
}
