#pragma once

#include <string>
#include "glut.h"


class DoVat{
public:


	void drawTable() {
		// draw table by glutsolidcube and gl scalef
		glPushMatrix();
		glTranslatef(7.2, 1.5, 1.2);
		glScalef(2.8, 0.1, 1.4);
		glColor3f(162 / 255.0, 108 / 255.0, 72 / 255.0); // màu nâu nhạt
		glutSolidCube(2);
		glPopMatrix();

		// draw legs of table
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				glPushMatrix();
				glTranslatef(4.7 + i * 5, 0.7, 0.3 + j * 2);  // increase the z value
				glScalef(0.25, 1.6, 0.2);
				glColor3f(0.5, 0.28, 0.0);
				glutSolidCube(1);
				glPopMatrix();
			}
		}

	}

	void drawComputerCase() {
		glPushMatrix();
		glTranslatef(5.3, 2.3, 1.2); // adjust the translation
		glScalef(0.8, 1.5, 1.5); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.42, 2.35, 1.3); // adjust the translation
		glScalef(0.6, 1.2, 1.4);
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.1, 3.05, 1.8); // adjust the translation
		glScalef(0.1, 0.1, 0.1); // adjust the scale
		glColor3f(1.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(5.5, 3.05, 1.8); // adjust the translation
		glScalef(0.1, 0.1, 0.1); // adjust the scale
		glColor3f(2.5, 20.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();
	}

	void drawMonitor1() {
		glPushMatrix();
		glTranslatef(7, 2.6, 0.6); // adjust the translation
		glScalef(2, 1.3, 0.1); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(7, 2.6, 0.65); // adjust the translation
		glScalef(1.8, 1.1, 0.1); // adjust the scale
		glColor3f(0.5, 0.5, 0.5);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(7, 1.7, 0.6); // adjust the translation
		glScalef(0.2, 0.5, 0.2); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(7, 1.65, 0.6); // adjust the translation
		glScalef(0.5, 0.1, 0.5); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();
	}
	/*
	void drawMonitor2() {
		
		glPushMatrix();
		glTranslatef(0.8, 2.5, 0.5);
		//glTranslatef(9.05, 2.6, 1); // adjust the translation
		glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
		glScalef(2, 1.3, 0.1); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, 1.48, 0.35);
		//glTranslatef(9.05, 2.6, 1.05); // adjust the translation
		glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.8, 1.1, 0.1); // adjust the scale
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, 0.58,0.3);
		//glTranslatef(9.05, 1.7, 1); // adjust the translation
		glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.2, 0.5, 0.2); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0.8, 0.53, 0.3);
		//glTranslatef(9.05, 1.65, 1); // adjust the translation
		glRotatef(-20.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.5, 0.1, 0.5); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();
	}
	*/
	

	void drawKeyboard() {
		glPushMatrix();
		glTranslatef(6.8, 1.64, 1.7); // adjust the translation
		glScalef(1.5, 0.15, 0.7); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		for (float i = -0.6; i <= 0.7; i += 0.25) {
			for (float j = -0.2; j <= 0.4; j += 0.2) {
				glPushMatrix();
				glTranslatef(6.8 + i, 1.7, 1.7 + j); // adjust the translation
				glScalef(0.05, 0.1, 0.05); // adjust the scale
				glColor3f(0.5, 0.5, 0.5);
				glutSolidCube(1);
				glPopMatrix();
			}
		}
	}

	void drawMousePad() {
		glPushMatrix();
		glTranslatef(7.22, 1.54, 1.7); // adjust the translation
		glScalef(2.85, 0.15, 1.2); // adjust the scale
		glColor3f(0.96, 0.87, 0.70);
		glutSolidCube(1);
		glPopMatrix();
	}

	void drawMouse() {


		glPushMatrix();
		glTranslatef(8.2, 1.65, 1.8); // adjust the translation
		glScalef(0.3, 0.25, 0.44); // adjust the scale
		glColor3f(0.0, 0.0, 0.0);// Set color to black
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8.13, 1.75, 1.7); // adjust the translation
		glScalef(0.1, 0.1, 0.15); // adjust the scale
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8.28, 1.75, 1.7); // adjust the translation
		glScalef(0.1, 0.1, 0.15); // adjust the scale
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

	}



	void drawChair() {
		// Draw the seat of the chair
		glPushMatrix();
		glTranslatef(7.2, 0.8, 3.2);
		glScalef(0.6, 0.1, 0.6);
		glColor3f(0.9, 0.8, 0.8);  // Light gray
		glutSolidCube(2);
		glPopMatrix();

		// Draw the backrest of the chair
		glPushMatrix();
		glTranslatef(7.2, 1.6, 3.8);
		glScalef(0.6, 0.8, 0.1);
		glColor3f(0.9, 0.8, 0.8);  // Light gray
		glutSolidCube(2);
		glPopMatrix();

		// Draw the armrests of the chair
		for (int i = 0; i < 2; i++) {
			glPushMatrix();
			glTranslatef(6.6 + i * 1.2, 1.2, 3.2);
			glScalef(0.1, 0.1, 0.5);
			glColor3f(0.5, 0.5, 0.5);  // Light gray
			glutSolidCube(2);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(6.6 + i * 1.2, 1.08, 3.2);
			glScalef(0.15, 0.4, 0.15);
			glColor3f(0.2, 0.2, 0.2);  // Dark gray
			glutSolidCube(1);
			glPopMatrix();
		}

		// Draw the leg of the chair
		glPushMatrix();
		glTranslatef(7.2, 0.4, 3.2);
		glScalef(0.1, 0.8, 0.1);
		glColor3f(0.2, 0.2, 0.2);  // Dark gray
		glutSolidCube(1);
		glPopMatrix();

		// Draw the crossbars of the chair
		for (int i = 0; i < 2; i++) {
			glPushMatrix();
			glTranslatef(7.2, 0.05, 3.2);
			glRotatef(90.0f * i, 0.0f, 1.0f, 0.0f);
			glScalef(1.2, 0.1, 0.1);
			glColor3f(0.2, 0.2, 0.2);  // Dark gray
			glutSolidCube(1);
			glPopMatrix();
		}
	}


	void drawWindow() {
		glPushMatrix();
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); // apply rotation to the entire window

		// Draw the window frame
		glPushMatrix();
		glTranslatef(7.5, 2.7, -0.05); // adjust the translation to be close to the axes
		glScalef(2.3, 2.8, 0.1); // adjust the scale
		glColor3f(0.5, 0.5, 0.5);
		glutSolidCube(1);
		glPopMatrix();

		//draw the outside
		glPushMatrix();
		glTranslatef(7.45f, 2.7, -0.01); // adjust the translation to be close to the axes
		glScalef(1.5, 2.4, -0.2); // adjust the scale
		glColor3f(180 / 255.0, 218 / 255.0, 252 / 255.0);
		glutSolidCube(1);
		glPopMatrix();

		// Draw the window panes
		float gap = 0.45; // gap between panes
		float scaleAdjust = 1.1; // adjust the scale to make panes smaller

		// Draw two opening panes
		for (int i = 0; i < 2; i++) {
			glPushMatrix();
			glTranslatef(7.26 - 0.5 + i * (1.0 + gap), 2.76, -0.35); // adjust the translation to match the frame
			glRotatef(45.0f - i * 90.0f, 0.0f, 1.0f, 0.0f); // rotate the pane 45 degrees for the first pane and -45 degrees for the second pane
			glScalef(scaleAdjust, 2 * scaleAdjust + 0.25, 0.1); // adjust the scale to make panes vertical
			glColor3f(0.96, 0.87, 0.70);
			glutSolidCube(1);
			glPopMatrix();
		}

		glPopMatrix(); // restore the matrix stack after drawing the entire window
	}

	

	void drawFullTable() {
		drawTable();
		drawComputerCase();
		drawMonitor1();
		//drawMonitor2();
		drawKeyboard();
		drawMousePad();
		drawMouse();
		drawChair();
		drawWindow();
		
	}

};

