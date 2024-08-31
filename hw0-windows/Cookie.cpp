//#ifndef COOKIE_CRUSH_CPP
//#define COOKIE_CRUSH_CPP
//
////#include <GL/gl.h>
////#include <GL/glut.h>
//#include <iostream>
//#include<string>
//#include<cmath>
//#include<fstream>
//#include <string>
//#include "util.h"
//
//using namespace std;
//#define MAX(A,B) ((A) > (B) ? (A):(B)) // defining single line functions....
//#define MIN(A,B) ((A) < (B) ? (A):(B))
//#define ABS(A) ((A) < (0) ? -(A):(A))
//#define FPS 10
//
//#define KEY_ESC 27 // A// 20,30,30
//
//const int bradius = 30; // Cookie radius in pixels...
//
//int width = 900 + 70, height = 660 + 45; // i have set my window size to be 800 x 600
//int dball = 0; // difference between cookies center of 0 pixels
//int byoffset = bradius + dball; // 2 * bradius + dball; // board yoffset
//
//string name;
//
//int arr[10][15] = {};
//int box_1_x = 0;
//int box_1_y = 0;
//int box_2_x = 0;
//int box_2_y = 0;
//float timee = 120;
//int check = 0;
//
//float score = 0;
//int setcolor, psetcolor;
//
//enum GameState { // Use to check different states of game...
//	Ready, Shot, Over, RemoveCluster
//};
//GameState gamestate = Ready;
//
//const int ncookies = 6;
//enum Cookies {
//	CK_BISCUIT, CK_BURGER, CK_CROISSONT, CK_CUPCAKE, CK_DONUT, CK_STAR
//};
//GLuint texture[ncookies];
//GLuint tid[ncookies];
//string tnames[] = { "biscuit.png", "burger.png", "croissont.png", "cupcake.png",
//		"donut.png", "star.png" };
//GLuint mtid[ncookies];
//int cwidth = 60, cheight = 60; // 60x60 pixels cookies width & height...
//
//void RegisterTextures()
///*Function is used to load the textures from the files and display*/
//// Please do not change it...
//{
//	// allocate a texture name
//	glGenTextures(ncookies, tid);
//
//	vector<unsigned char> data;
//	ifstream ifile("image-data.bin", ios::binary | ios::in);
//	if (!ifile) {
//		cout << " Couldn't Read the Image Data file ";
//		exit(-1);
//	}
//	// now load each cookies data...
//	int length;
//	ifile.read((char*)&length, sizeof(int));
//	data.resize(length, 0);
//	for (int i = 0; i < ncookies; ++i) {
//
//		// Read current cookie
//
//		ifile.read((char*)&data[0], sizeof(char) * length);
//
//		mtid[i] = tid[i];
//		// select our current texture
//		glBindTexture(GL_TEXTURE_2D, tid[i]);
//
//		// select modulate to mix texture with color for shading
//		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
//
//		// when texture area is small, bilinear filter the closest MIP map
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//			GL_LINEAR_MIPMAP_NEAREST);
//		// when texture area is large, bilinear filter the first MIP map
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		// if wrap is true, the texture wraps over at the edges (repeat)
//		//       ... false, the texture ends at the edges (clamp)
//		bool wrap = true;
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
//			wrap ? GL_REPEAT : GL_CLAMP);
//		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
//			wrap ? GL_REPEAT : GL_CLAMP);
//
//		// build our texture MIP maps
//		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, cwidth, cheight, GL_RGB,
//			GL_UNSIGNED_BYTE, &data[0]);
//	}
//	ifile.close();
//}
//void DrawCookie(const Cookies& cname, int sx, int sy, int cwidth = 60,
//	int cheight = 60)
//	/*Draws a specfic cookie at given position coordinate
//	 * sx = position of x-axis from left-bottom
//	 * sy = position of y-axis from left-bottom
//	 * cwidth= width of displayed cookie in pixels
//	 * cheight= height of displayed cookiei pixels.
//	 * */
//{
//	float fwidth = (float)cwidth / width * 2, fheight = (float)cheight
//		/ height * 2;
//	float fx = (float)sx / width * 2 - 1, fy = (float)sy / height * 2 - 1;
//
//	glPushMatrix();
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, mtid[cname]);
//	//	glTranslatef(0, 0, 0);
//	//	glRotatef(-M_PI / 2, 0, 0, 1);
//	glBegin(GL_QUADS);
//	glTexCoord2d(0.0, 0.0);
//	glVertex2d(fx, fy);
//	glTexCoord2d(1.0, 0.0);
//	glVertex2d(fx + fwidth, fy);
//	glTexCoord2d(1.0, 1.0);
//	glVertex2d(fx + fwidth, fy + fheight);
//	glTexCoord2d(0.0, 1.0);
//	glVertex2d(fx, fy + fheight);
//	glEnd();
//
//	glColor4f(1, 1, 1, 1);
//
//	//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//	//glutSwapBuffers();
//}
//
//float Distance(float x1, float y1, float x2, float y2) {
//	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
//}
//void Pixels2Cell(int px, int py, int& cx, int& cy) {
//
//}
//void Cell2Pixels(int cx, int cy, int& px, int& py)
//// converts the cell coordinates to pixel coordinates...
//{
//
//}
//
//void swap() {
//
//	//vertical .....
//
//	for (int k = 0; k < 8; k++)
//	{
//		for (int l = 0; l < 15; l++)
//		{
//			if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
//			{
//				check = 1;
//			}
//		}
//	}
//
//	//horizontal....
//
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
//			{
//				check = 1;
//			}
//		}
//	}
//
//
//	if (check == 0)
//	{
//		if ((box_1_x - box_2_x == 1 || box_1_x - box_2_x == -1) && (box_1_y - box_2_y == 0)) //horizontal..
//		{
//			int temp = arr[box_1_y][box_1_x];
//			arr[box_1_y][box_1_x] = arr[box_2_y][box_2_x];
//			arr[box_2_y][box_2_x] = temp;
//
//
//			box_1_x = 0;
//			box_1_y = 0;
//			box_2_x = 0;
//			box_2_y = 0;
//
//		}
//
//		if ((box_1_y - box_2_y == 1 || box_1_y - box_2_y == -1) && (box_1_x - box_2_x == 0)) //vertical..
//		{
//			int temp = arr[box_1_y][box_1_x];
//			arr[box_1_y][box_1_x] = arr[box_2_y][box_2_x];
//			arr[box_2_y][box_2_x] = temp;
//
//
//			box_1_x = 0;
//			box_1_y = 0;
//			box_2_x = 0;
//			box_2_y = 0;
//
//		}
//	}
//}
//
//
//void DisplayFunction() {
//	// set the background color using function glClearColor.
//	// to change the background play with the red, green and blue values below.
//	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.
////#if 0
//	glClearColor(1/*Red Component*/, 1.0/*Green Component*/,
//		1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
//	glClear(GL_COLOR_BUFFER_BIT); //Update the colors
//
//	// Existing code for drawing screen elements
//		// Display high scores after drawing other elements
//
//
//	// #----------------- Write your code here ----------------------------#
//		//write your drawing commands here or call your drawing functions...
//
//		// draw cookies..;
//
//	if (timee > 0)
//	{
//		for (int l = 0, i = 0; i < 10; i++, l += 65)
//		{
//			for (int k = 0, j = 0; j < 15; j++, k += 65)
//			{
//				switch (arr[i][j])
//				{
//				case 1:
//				{
//					DrawCookie(CK_BISCUIT, k, l, cwidth, cheight);
//					break;
//				}
//				case 2:
//
//				{
//					DrawCookie(CK_CROISSONT, k, l, cwidth, cheight);
//					break;
//				}
//				case 3:
//				{
//					DrawCookie(CK_CUPCAKE, k, l, cwidth, cheight);
//					break;
//				}
//				case 4:
//				{
//					DrawCookie(CK_BURGER, k, l, cwidth, cheight);
//					break;
//				}
//				case 5:
//				{
//					DrawCookie(CK_DONUT, k, l, cwidth, cheight);
//					break;
//				}
//				case 6:
//				{
//					DrawCookie(CK_STAR, k, l, cwidth, cheight);
//					break;
//				}
//
//
//				}
//				DrawString(width / 2 - 0, height - 35, width, height, "Timer : " + Num2Str(timee), colors[BLACK]);
//				DrawString(width / 2 - 400, height - 35, width, height, "Score : " + Num2Str(score), colors[BLACK]);
//				DrawString(width / 3 - 400, height - 35, width, height, "GAME: ", colors[FLORAL_WHITE]);
//
//			}
//		}
//
//	}
//	else
//	{
//		DrawString(width / 2 - 200, height - 200, width, height, "GAME OVER... ", colors[WHITE]);
//		DrawString(width / 2 - 200, height - 250, width, height, "Your Score is  : " + Num2Str(score), colors[WHITE]);
//		DrawString(width / 2 - 200, height - 350, width, height, "Better luck next time ", colors[WHITE]);
//		DrawString(width / 2 - 200, height - 450, width, height, "Press ESC to Exit... ", colors[WHITE]);
//		DrawString(width / 2 - 200, height - 650, width, height, "Made by: Asadullah and Ali hasan ", colors[WHITE]);
//		DrawString(width / 2 - 200, height - 550, width, height, "HIGH SCORES: " + Num2Str(score), colors[WHITE]);
//	}
//
//	swap();
//
//	// #----------------- Write your code till here ----------------------------#
//		// do not modify below this
//	glutSwapBuffers(); // do not modify this line..
//
//}
///* Function sets canvas size (drawing area) in pixels...
// *  that is what dimensions (x and y) your game will have
// *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
// * */
//void SetCanvasSize(int width, int height) {
//	/*glMatrixMode(GL_PROJECTION);
//	 glLoadIdentity();
//	 glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.*/
//}
//
///*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
// * is pressed from the keyboard
// *
// * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
// *
// * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
// * program coordinates of mouse pointer when key was pressed.
// *
// * */
//
//void NonPrintableKeys(int key, int x, int y) {
//	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
//		// what to do when left key is pressed...
//
//	}
//	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
//
//	}
//	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
//	}
//	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
//	}
//
//	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
//	 * this function*/
//	 /*
//	  glutPostRedisplay();
//	  */
//}
///*This function is called (automatically) whenever your mouse moves witin inside the game window
// *
// * You will have to add the necessary code here for finding the direction of shooting
// *
// * This function has two arguments: x & y that tells the coordinate of current position of move mouse
// *
// * */
//
//void MouseMoved(int x, int y) {
//
//	cout << "Current Mouse Coordinates X=" << x << " Y= " << height - y << endl;
//	glutPostRedisplay();
//}
//
///*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
// *
// * You will have to add the necessary code here for shooting, etc.
// *
// * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
// * x & y that tells the coordinate of current position of move mouse
// *
// * */
//
//void MouseClicked(int button, int state, int x, int y) {
//
//
//	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
//	{
//
//		if (state == GLUT_DOWN && gamestate == Ready)
//		{
//			box_1_x = 0;
//			box_1_y = 0;
//			box_2_x = 0;
//			box_2_y = 0;
//
//			check = 0;
//
//			cout << "Left Mouse Button Pressed at Coordinates X=" << x << " Y= "
//				<< height - y << endl;
//
//			box_1_x = x / 65;
//			box_1_y = (height - y) / 65;
//
//
//		}
//		if (state == GLUT_UP && gamestate == Ready)
//		{
//			box_2_x = x / 65;
//			box_2_y = (height - y) / 65;
//
//
//			if ((box_1_x - box_2_x == 1 || box_1_x - box_2_x == -1) && (box_1_y - box_2_y == 0))
//			{
//
//				int temp = arr[box_1_y][box_1_x];
//				arr[box_1_y][box_1_x] = arr[box_2_y][box_2_x];
//				arr[box_2_y][box_2_x] = temp;
//
//			}
//
//			if ((box_1_y - box_2_y == 1 || box_1_y - box_2_y == -1) && (box_1_x - box_2_x == 0))
//			{
//
//				int temp = arr[box_1_y][box_1_x];
//				arr[box_1_y][box_1_x] = arr[box_2_y][box_2_x];
//				arr[box_2_y][box_2_x] = temp;
//
//			}
//
//		}
//	}
//	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
//	{
//
//	}
//	glutPostRedisplay();
//
//}
///*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
// * is pressed from the keyboard
// * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
// * program coordinates of mouse pointer when key was pressed.
// * */
//void PrintableKeys(unsigned char key, int x, int y) {
//	if (key == KEY_ESC/* Escape key ASCII*/) {
//		exit(1); // exit the program when escape key is pressed.
//	}
//}
//
//void crush() {
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4] && j < 11)
//			{
//				for (int k = 0; k < 8; k++)
//				{
//					for (int l = 0; l < 15; l++)
//					{
//
//
//						if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//							arr[k + 4][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//
//						}
//					}
//				}
//				arr[i][j] = 12;
//				arr[i][j + 1] = 12;
//				arr[i][j + 2] = 12;
//				arr[i][j + 3] = 12;
//				arr[i][j + 4] = 12;
//
//			}
//
//			else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && j < 12)
//			{
//				for (int k = 0; k < 8; k++)
//				{
//					for (int l = 0; l < 15; l++)
//					{
//						if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//							arr[k + 4][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//
//						}
//					}
//				}
//
//				arr[i][j] = 12;
//				arr[i][j + 1] = 12;
//				arr[i][j + 2] = 12;
//				arr[i][j + 3] = 12;
//
//			}
//
//			else	if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
//			{
//				for (int k = 0; k < 8; k++)
//				{
//					for (int l = 0; l < 15; l++)
//					{
//						if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//							arr[k + 4][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7)
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//							arr[k + 3][l] = 12;
//
//						}
//
//						else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
//						{
//							arr[k][l] = 12;
//							arr[k + 1][l] = 12;
//							arr[k + 2][l] = 12;
//
//						}
//					}
//				}
//
//				arr[i][j] = 12;
//				arr[i][j + 1] = 12;
//				arr[i][j + 2] = 12;
//
//			}
//		}
//	}
//
//	//		//AutoCrushing of cookies and generating spaces
//
//	for (int k = 0; k < 8; k++)
//	{
//		for (int l = 0; l < 15; l++)
//		{
//			if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && arr[k][l] == arr[k + 4][l] && k < 6)
//			{
//				for (int i = 0; i < 10; i++)
//				{
//					for (int j = 0; j < 13; j++)
//					{
//						if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//
//						}
//
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//
//						}
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//							arr[i][j + 4] = 12;
//
//						}
//					}
//				}
//
//				arr[k][l] = 12;
//				arr[k + 1][l] = 12;
//				arr[k + 2][l] = 12;
//				arr[k + 3][l] = 12;
//				arr[k + 4][l] = 12;
//
//
//			}
//
//			else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l] && arr[k][l] == arr[k + 3][l] && k < 7)
//			{
//				for (int i = 0; i < 10; i++)
//				{
//					for (int j = 0; j < 13; j++)
//					{
//						if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//
//						}
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//
//						}
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//							arr[i][j + 4] = 12;
//
//						}
//					}
//				}
//				arr[k][l] = 12;
//				arr[k + 1][l] = 12;
//				arr[k + 2][l] = 12;
//				arr[k + 3][l] = 12;
//
//			}
//
//			else if (arr[k][l] == arr[k + 1][l] && arr[k][l] == arr[k + 2][l])
//			{
//				for (int i = 0; i < 10; i++)
//				{
//					for (int j = 0; j < 13; j++)
//					{
//						if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//
//						}
//
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//
//						}
//						else if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i][j + 2] && arr[i][j] == arr[i][j + 3] && arr[i][j] == arr[i][j + 4])
//						{
//							arr[i][j] = 12;
//							arr[i][j + 1] = 12;
//							arr[i][j + 2] = 12;
//							arr[i][j + 3] = 12;
//							arr[i][j + 4] = 12;
//
//						}
//						
//					}
//				}
//
//				arr[k][l] = 12;
//				arr[k + 1][l] = 12;
//				arr[k + 2][l] = 12;
//
//			}
//		}
//	}
//
//	for (int i = 0; i < 8; i++) {
//		for (int j = 0; j < 13; j++) {
//			if (arr[i][j] == arr[i + 1][j + 1] && arr[i][j] == arr[i + 2][j + 2] && i < 7 && j < 10) {
//				arr[i][j] == 12;
//				arr[i + 1][j + 1] == 12;
//				arr[i + 2][j + 2] = 12;
//			}
//		}
//	}
//
//	//Shifting cookies.....
//
//	int temp = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			if (arr[i][j] == 12)
//			{
//				for (int k = i; k < 9; k++)
//				{
//					temp = arr[k][j];
//					arr[k][j] = arr[k + 1][j];
//					arr[k + 1][j] = temp;
//				}
//			}
//		}
//	}
//
//	//Shifting cookies.....
//
//	for (int j = 0; j < 15; j++)
//	{
//		for (int i = 0; i < 10; i++)
//		{
//			if (arr[i][j] == 12)
//			{
//				for (int k = i; k < 9; k++)
//				{
//					temp = arr[k][j];
//					arr[k][j] = arr[k + 1][j];
//					arr[k + 1][j] = temp;
//				}
//			}
//		}
//	}
//
//	//Generating RANDOM Cookies where spaces accoured after shifting the cookies ....
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 15; j++)
//		{
//			if (arr[i][j] == 12)
//			{
//				arr[i][j] = rand() % 6 + 1;
//				score++;
//			}
//		}
//	}
//}
///*
// * This function is called after every 00.0 milliseconds
// * (FPS is defined on in the beginning).
// * You can use this function to animate objects and control the
// * speed of different moving objects by varying the constant FPS.
// *
// * */
//float dt = 0.0, lastframe = 0.0;
//void Timer(int m) {
//	dt = (m - lastframe) / 0.0;
//	lastframe = m;
//	timee--;
//
//
//	glutPostRedisplay();
//
//	// implement your functionality here
////		//AutoCrushing of cookies and generating spaces
//	crush();
//
//	glutTimerFunc(1000, Timer, m + 1);
//}
//
//
//int main(int argc, char* argv[]) {
//	InitRandomizer(); // seed the random number generator...
//	//Write your code here for filling the canvas with different Cookies. You can use the GetCookie function for getting the random shaped cookies
//
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 16; j++)
//		{
//			arr[i][j] = rand() % 6 + 1;
//		}
//	}
//
//	glutInit(&argc, argv); // initialize the graphics library...
//
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
//	glutInitWindowPosition(0, 0); // set the initial position of our window
//	glutInitWindowSize(width, height); // set the size of our window
//	glutCreateWindow("Cookie Crush"); // set the title of our game window
//	//SetCanvasSize(width, height); // set the number of pixels...
//
//	// Load the textures from the file..;
//	RegisterTextures();
//	// Register your functions to the library.
//	// you are telling the library names of function to call for different tasks.
//
//	glutDisplayFunc(DisplayFunction); // tell library which function to call for drawing Canvas.
//	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
//	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
//	glutMouseFunc(MouseClicked);
//
//	//// This function tells the library to call our Timer function after 1000.0 milliseconds...
//	glutTimerFunc(1000, Timer, 0);
//
//	glutMainLoop();
//
//	return 1;
//}
//#endif /* */