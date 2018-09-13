//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************			GALVAN HERNANDEZ KARINA			******//
//************************************************************//
//************************************************************//
#include "Main.h"

float transZ = -7.0f;
int screenW = 0.0;
int screenH = 0.0;

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		glRotatef(angleX, 0, 1, 0);
		//Poner Código Aquí.
		

		glPushMatrix(); //torso
			glScalef(10,10,5);
			prisma();
		glPopMatrix();

		glPushMatrix(); //cuello
			glTranslatef(0,5.5,0);
			glScalef(4,1,5);
			prisma();
		glPopMatrix();

		glPushMatrix(); //cabeza
			glTranslatef(0, 8, 0);
			glScalef(5, 4, 5);
			prisma();
		glPopMatrix();

		glPushMatrix(); //hombro derecho
		glTranslatef(5, 3, 0);
		glScalef(1, 3, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //bicep derecho
		glTranslatef(6, 3, 0);
		glScalef(6, 2, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //codo derecho
		glTranslatef(9, 3, 0);
		glScalef(1, 1, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //antebrazo derecho
		glTranslatef(12.5, 3, 0);
		glScalef(6, 2, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //mano derecha
		glTranslatef(16, 3, 0);
		glScalef(1.5, 1.5, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //hombro izquierdo
		glTranslatef(-5, 3, 0);
		glScalef(1, 3, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //bicep izquierdo
		glTranslatef(-8, 3, 0);
		glScalef(6, 2, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //codo izquierdo
		glTranslatef(-11, 3, 0);
		glScalef(1, 1, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //antebrazo izquierdo
		glTranslatef(-14.5, 3, 0);
		glScalef(6, 2, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //mano izquierda
		glTranslatef(-18, 3, 0);
		glScalef(1.5, 1.5, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //femur derecho
		glTranslatef(3, -6, 0);
		glScalef(4, 8, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //rodilla derecha
		glTranslatef(3, -9, 0);
		glScalef(2, 4, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //pantorrilla derecha
		glTranslatef(3, -15, 0);
		glScalef(4, 8, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //pie derecho
		glTranslatef(3, -20, 0);
		glScalef(3, 3, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //femur izquierdo
		glTranslatef(-3, -6, 0);
		glScalef(4, 8, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //rodilla izquierda
		glTranslatef(-3, -10, 0);
		glScalef(2, 2, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //pantorrilla izquierda
		glTranslatef(-3, -15, 0);
		glScalef(4, 8, 5);
		prisma();
		glPopMatrix();

		glPushMatrix(); //pie izquierdo
		glTranslatef(-3, -20, 0);
		glScalef(3, 3, 5);
		prisma();
		glPopMatrix();


  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-10, 10,-10, 10, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}


void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'q':
	case 'Q':
		transY += 0.3f;
		printf("Posicion en X: %f\n", transY);
		break;
	case 'e':
	case 'E':
		transY += -0.3f;
		printf("Posicion en Z: %f\n", transY);
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}


void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}


