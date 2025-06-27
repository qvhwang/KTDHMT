#include "CameraController.h"
#include "glut.h"
#include"SHAPE.h"

extern SHAPE KHOI;
bool isLightOn = false; // Đèn được tắt mặc định
bool isLightOn1 = false; // Đèn được tắt mặc định
bool isLightOn2 = false; // Đèn được tắt mặc định
bool isLightShining = false; // Đèn không chiếu sáng mặc định
extern bool doorOpening;
extern bool projectorOn;
extern float doorAngle;  // Góc xoay của cửa, ban đầu là 0 (đóng)

extern bool lightRowsOn[NUM_LIGHT_ROWS];
extern GLfloat lightRowPositions[NUM_LIGHT_ROWS][4];




CameraController::CameraController(float initialX, float initialY, float initialZ)
	: cameraX(initialX), cameraY(initialY), cameraZ(initialZ), lastMouseX(-1), lastMouseY(-1) {}

void CameraController::Mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		lastMouseX = x;
		lastMouseY = y;
	}
	else {
		lastMouseX = -1;
		lastMouseY = -1;
	}
}

void CameraController::Motion(int x, int y) {
	if (lastMouseX >= 0 && lastMouseY >= 0) {
		float deltaX = x - lastMouseX;
		float deltaY = y - lastMouseY;
		const float sensitivity = 0.1f;
		cameraX += deltaX * sensitivity;
		cameraY -= deltaY * sensitivity;
		glutPostRedisplay();
	}
	lastMouseX = x;
	lastMouseY = y;
}

void CameraController::SpecialKeys(int key, int x, int y) {
	const float cameraSpeed = 1.0f;
	switch (key) {
	case GLUT_KEY_UP:
		cameraY += cameraSpeed;
		break;
	case GLUT_KEY_DOWN:
		cameraY -= cameraSpeed;
		break;
	}
	glutPostRedisplay();
}


void CameraController::Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		cameraX -= 1.0;
		cameraZ -= 0.3;
		cameraY -= 0.1;
		break;
	case 'e':
		cameraX += 1.0;
		cameraY += 0.1;
		cameraZ += 0.3;
		break;
	case 'w':
		cameraY += 1.0;
		break;
	case 's':
		cameraY -= 1.0;
		break;
	case 'a':
		cameraZ += 1.0;
		break;
	case 'd':
		cameraZ -= 1.0;
		break;
	case 'z':
		cameraX += 1.0;
		break;
	case 'x':
		cameraX -= 1.0;
		break;
	case '1':
		if (isLightOn) {
			isLightShining = !isLightShining;
		}
		else {
			isLightOn = true;
			isLightOn1 = true;
		}
		break;
	case '0':
		isLightOn = false;
		isLightOn1 = false;
		isLightOn2 = false;
		isLightShining = false;
		break;
	case '2':  // Bật/tắt dàn đèn trái dưới
		lightRowsOn[0] = !lightRowsOn[0];
		break;
	case '3':  // Bật/tắt dàn đèn trái trên
		lightRowsOn[1] = !lightRowsOn[1];
		break;
	case '4':  // Bật/tắt dàn đèn phải dưới
		lightRowsOn[2] = !lightRowsOn[2];
		break;
	case '5':  // Bật/tắt dàn đèn phải trên
		lightRowsOn[3] = !lightRowsOn[3];
		break;
	case '6':  // Bật/tắt tất cả dàn đèn trần
		for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
			lightRowsOn[i] = !lightRowsOn[i];
		}
		break;
	case '7':  // Bật/tắt dàn đèn bên trái (trên và dưới)
		lightRowsOn[0] = !lightRowsOn[0];
		lightRowsOn[1] = !lightRowsOn[1];
		break;
	case '8':  // Bật/tắt dàn đèn bên phải (trên và dưới)
		lightRowsOn[2] = !lightRowsOn[2];
		lightRowsOn[3] = !lightRowsOn[3];
		break;
	case 'p':
		projectorOn = !projectorOn;
		break;
	case 'o':  // Mở cửa
	case 'O':
		if (doorAngle < 90.0f)
			doorAngle += 5.0f;
		break;
	case 'c':  // Đóng cửa
	case 'C':
		if (doorAngle > 0.0f)
			doorAngle -= 5.0f;
		break;
	case '[':  // Di chuyển đèn sang trái
		for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
			lightRowPositions[i][0] -= lightMoveSpeed;  // Giảm tọa độ X
			glLightfv(GL_LIGHT3 + i, GL_POSITION, lightRowPositions[i]);
		}
		break;

	case ']':  // Di chuyển đèn sang phải
		for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
			lightRowPositions[i][0] += lightMoveSpeed;  // Tăng tọa độ X
			glLightfv(GL_LIGHT3 + i, GL_POSITION, lightRowPositions[i]);
		}
		break;

	case '{':  // Di chuyển đèn về phía trước
		for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
			lightRowPositions[i][2] += lightMoveSpeed;  // Tăng tọa độ Z
			glLightfv(GL_LIGHT3 + i, GL_POSITION, lightRowPositions[i]);
		}
		break;

	case '}':  // Di chuyển đèn về phía sau
		for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
			lightRowPositions[i][2] -= lightMoveSpeed;  // Giảm tọa độ Z
			glLightfv(GL_LIGHT3 + i, GL_POSITION, lightRowPositions[i]);
		}
		break;

	case 'h':  // Giảm góc chiếu (chùm sáng hẹp hơn)
		if (spotCutoff > 15.0f) {
			spotCutoff -= 5.0f;
			for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
				glLightf(GL_LIGHT3 + i, GL_SPOT_CUTOFF, spotCutoff);
			}
		}
		break;

	case 'j':  // Tăng góc chiếu (chùm sáng rộng hơn)
		if (spotCutoff < 90.0f) {
			spotCutoff += 5.0f;
			for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
				glLightf(GL_LIGHT3 + i, GL_SPOT_CUTOFF, spotCutoff);
			}
		}
		break;

	}


	glutPostRedisplay();
}
