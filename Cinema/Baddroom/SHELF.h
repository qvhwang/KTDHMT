
#include <string>
#include "glut.h"


class SHELF {
public:

	void drawShelf() {
		//Tầng 2
		glPushMatrix();
		glColor3f(139 / 255.0, 69 / 255.0, 19 / 255.0); // Wood color (approximated)
		glTranslatef(2, 3.5, 0.3); // vị trí
		glScalef(2, 0.2, 1); // kích thước
		glutSolidCube(1);
		glColor3f(0.0, 0.0, 0.0); // màu đen (dùng cho wireframe)
		glutWireCube(0);
		glPopMatrix();
		//Tầng 1
		glPushMatrix();
		glColor3f(139 / 255.0, 69 / 255.0, 19 / 255.0); // Wood color (approximated)
		glTranslatef(3, 2.5, 0.3); // vị trí
		glScalef(2, 0.2, 1); // kích thước
		glutSolidCube(1);
		glColor3f(0.0, 0.0, 0.0); // màu đen (dùng cho wireframe)
		glutWireCube(0);
		glPopMatrix();
	}


	void drawBook(float x, float y, float z, float width, float height, float depth, float r, float g, float b) {
		// Draw book
		glPushMatrix();
		glColor3f(r, g, b); // Set color
		glTranslatef(x, y, z); // Set position
		glScalef(width, height, depth); // Set size
		glutSolidCube(1); // Draw book
		glColor3f(0.0, 0.0, 0.0); // Set wireframe color to black
		glutWireCube(0); // Draw wireframe of book
		glPopMatrix();
		//Draw page
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Set color
		glTranslatef(x, y, z + depth / 2); // Set position
		glScalef(width / 2, height, 0.01); // Set size
		glutSolidCube(1); // Draw book cover
		glColor3f(0.0, 0.0, 0.0); // Set wireframe color to black
		glutWireCube(0); // Draw wireframe of book cover
		glPopMatrix();


	}


	void drawBooksOnShelf() {
		// Tầng 1
		drawBook(2.3, 2.84, 0.4, 0.2, 0.5, 0.5, 0.0, 0.2, 0.1);
		drawBook(2.6, 2.84, 0.4, 0.2, 0.5, 0.5, 0.0, 0.2, 0.1);
		drawBook(2.9, 2.84, 0.4, 0.2, 0.5, 0.5, 0.0, 0.2, 0.1);
		drawBook(3.2, 2.84, 0.4, 0.2, 0.5, 0.5, 0.0, 0.2, 0.1);

		//Tầng 2
		drawBook(1.3, 3.84, 0.4, 0.2, 0.5, 0.5, 0.5, 0.5, 0.5);
		drawBook(1.6, 3.84, 0.4, 0.2, 0.5, 0.5, 0.5, 0.5, 0.5);
		drawBook(1.9, 3.84, 0.4, 0.2, 0.5, 0.5, 0.5, 0.5, 0.5);

	}
	void drawgiasach() {
		drawShelf();
		drawBooksOnShelf();
	}

};

