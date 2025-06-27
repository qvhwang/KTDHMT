#include "CameraController.h" 
#include "SHAPE.h"
#include <stdlib.h>
#include <cmath>
#include "glut.h"

#define NUM_LIGHT_ROWS 4  // 4 dàn đèn
bool lightRowsOn[NUM_LIGHT_ROWS] = { false };  // Trạng thái của từng dàn đèn
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


// Vị trí của 4 dàn đèn
GLfloat lightRowPositions[NUM_LIGHT_ROWS][4] = {
	{-3.0f, 10.5f, 1.5f, 1.0f},    // Dàn trái dưới
	{-3.0f, 10.5f, -15.0f, 1.0f},  // Dàn trái trên
	{5.0f, 10.5f, 1.5f, 1.0f},     // Dàn phải dưới
	{5.0f, 10.5f, -15.0f, 1.0f}    // Dàn phải trên
};

SHAPE KHOI;
CameraController cameraController;
float wallX = 8.9f;
float doorAngle = 0.0f;

// Thêm biến cho các đèn
bool spotlightsOn = true;
float ambientLight = 0.3f;
bool projectorOn = false;
bool ceilingLightsOn = false;



	void drawCeilingLight() {
		// Hàm helper để vẽ một bóng đèn với màu tương ứng trạng thái
		auto drawLightBulb = [](float x, float y, float z, bool isOn) {
			glPushMatrix();
			if (isOn) {
				// Màu khi đèn bật - màu trắng sáng
				glColor3f(1.0f, 1.0f, 0.9f);
			}
			else {
				// Màu khi đèn tắt - màu xám tối
				glColor3f(0.4f, 0.4f, 0.4f);
			}
			glTranslatef(x, y, z);
			glutSolidSphere(0.3, 50, 50);
			glutWireSphere(0.3, 50, 50);
			glPopMatrix();
			};

		// Dàn đèn trái dưới (index 0)
		drawLightBulb(-3.0f, 10.5f, 5.0f, lightRowsOn[0]);
		drawLightBulb(-3.0f, 10.5f, -3.0f, lightRowsOn[0]);
		drawLightBulb(-3.0f, 10.5f, 1.5f, lightRowsOn[0]);

		// Dàn đèn trái trên (index 1)
		drawLightBulb(-3.0f, 10.5f, -18.5f, lightRowsOn[1]);
		drawLightBulb(-3.0f, 10.5f, -15.0f, lightRowsOn[1]);
		drawLightBulb(-3.0f, 10.5f, -11.0f, lightRowsOn[1]);

		// Dàn đèn phải dưới (index 2)
		drawLightBulb(5.0f, 10.5f, 5.0f, lightRowsOn[2]);
		drawLightBulb(5.0f, 10.5f, -3.0f, lightRowsOn[2]);
		drawLightBulb(5.0f, 10.5f, 1.5f, lightRowsOn[2]);

		// Dàn đèn phải trên (index 3)
		drawLightBulb(5.0f, 10.5f, -18.5f, lightRowsOn[3]);
		drawLightBulb(5.0f, 10.5f, -15.0f, lightRowsOn[3]);
		drawLightBulb(5.0f, 10.5f, -11.0f, lightRowsOn[3]);


	//Thanh đỡ bóng đèn dưới
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.0f, 1 );
	glScalef( 0.6f, 0.6f, 10.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	//Các thanh nhỏ bên trái dưới
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, 5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, -3);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, 1.5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();


	//Thanh đỡ bóng đèn bên trái trên
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.0f, -15);
	glScalef(0.6f, 0.6f, 10.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	//Các thanh nhỏ bên trái dưới
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, -18.5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, -15);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(-3.0f, 11.5f, -11);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();


	 
	//Thanh đỡ bóng đèn bên phải dưới
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.0f, 1);
	glScalef(0.6f, 0.6f, 10.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	//Các thanh nhỏ bên phải dưới
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, 5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, -3);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, 1.5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();


	// Bóng đèn bên phải trên 
	glPushMatrix();
	glColor3f(212 / 255.0, 120454 / 255.0, 201 / 255.0);// màu trắng
	glTranslatef(5.0f, 10.5f, -18.5);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();

	glPushMatrix();
	glColor3f(212 / 255.0, 120454 / 255.0, 201 / 255.0);// màu trắng
	glTranslatef(5.0f, 10.5f, -15);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();

	glPushMatrix();
	glColor3f(212 / 255.0, 120454 / 255.0, 201 / 255.0);// màu trắng
	glTranslatef(5.0f, 10.5f, -11);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();


	//Thanh đỡ bóng đèn bên phải trên
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.0f, -15);
	glScalef(0.6f, 0.6f, 10.0f);
	glutSolidCube(1.0);
	glPopMatrix();

	//Các thanh nhỏ bên phải trên
	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, -18.5);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, -15);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);  // Màu viền đen
	glPushMatrix();
	glTranslatef(5.0f, 11.5f, -11);
	glScalef(0.3f, 0.4f, 0.5f);
	glutSolidCube(1.0);
	glPopMatrix();

}


void setupLighting() {
	// Bật hệ thống ánh sáng
	glEnable(GL_LIGHTING);

	// 1. THIẾT LẬP NGUỒN SÁNG MÔI TRƯỜNG (Ambient Light - LIGHT0)
	if (isLightOn && isLightShining) {
		glEnable(GL_LIGHT0);

		// Tăng ánh sáng môi trường tổng thể
		GLfloat ambient_position[] = { 0.0f, 1.0f, 0.0f, 0.0f };
		GLfloat ambient_light[] = { 0.4f, 0.4f, 0.4f, 1.0f };     
		GLfloat ambient_diffuse[] = { 0.3f, 0.3f, 0.3f, 1.0f };  
		GLfloat ambient_specular[] = { 0.2f, 0.2f, 0.2f, 1.0f };

		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, ambient_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, ambient_specular);
		glLightfv(GL_LIGHT0, GL_POSITION, ambient_position);
	}
	else {
		glDisable(GL_LIGHT0);
	}

	// 2. THIẾT LẬP HAI NGUỒN SÁNG ĐỊNH HƯỚNG (LIGHT1 và LIGHT2)
	if (isLightOn && isLightShining) {
		// LIGHT1 - Tăng cường độ sáng chung
		glEnable(GL_LIGHT1);
		GLfloat light1_position[] = { 1.0f, 10.0f, 1.0f, 0.0f };
		GLfloat light1_ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };   
		GLfloat light1_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
		GLfloat light1_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };   

		glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
		glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
		glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

		// LIGHT2 - Bổ sung ánh sáng phụ trợ
		glEnable(GL_LIGHT2);
		GLfloat light2_position[] = { -1.0f, 5.0f, -1.0f, 0.0f };
		GLfloat light2_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };    
		GLfloat light2_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };  
		GLfloat light2_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };  

		glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
	}
	else {
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
	}

	// 3. THIẾT LẬP ĐÈN TRẦN (Spotlights - từ LIGHT3 đến LIGHT6)
	for (int i = 0; i < NUM_LIGHT_ROWS; i++) {
		GLenum light = GL_LIGHT3 + i;

		if (lightRowsOn[i]) {
			glEnable(light);

			// Tăng mạnh cường độ ánh sáng spotlight
			GLfloat ceiling_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };     // Tăng ambient
			GLfloat ceiling_diffuse[] = { 3.0f, 3.0f, 2.8f, 1.0f };     // Tăng cường độ khuếch tán
			GLfloat ceiling_specular[] = { 2.0f, 2.0f, 2.0f, 1.0f };    // Tăng specular

			glLightfv(light, GL_AMBIENT, ceiling_ambient);
			glLightfv(light, GL_DIFFUSE, ceiling_diffuse);
			glLightfv(light, GL_SPECULAR, ceiling_specular);

			glLightfv(light, GL_POSITION, lightRowPositions[i]);
			GLfloat spot_direction[] = { 0.0f, -1.0f, 0.0f };
			glLightfv(light, GL_SPOT_DIRECTION, spot_direction);

			// Giữ nguyên các thông số spotlight
			glLightf(light, GL_SPOT_CUTOFF, 90.0f);
			glLightf(light, GL_SPOT_EXPONENT, 10.0f);

			// Giảm hệ số suy giảm để ánh sáng mạnh hơn
			glLightf(light, GL_CONSTANT_ATTENUATION, 0.3f);      // Giảm xuống để ánh sáng mạnh hơn
			glLightf(light, GL_LINEAR_ATTENUATION, 0.01f);       // Giảm suy giảm tuyến tính
			glLightf(light, GL_QUADRATIC_ATTENUATION, 0.001f);   // Giảm suy giảm bậc hai
		}
		else {
			glDisable(light);
		}
	}

	// 4. THIẾT LẬP VẬT LIỆU MẶC ĐỊNH với độ phản xạ cao hơn nhiều
	GLfloat default_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };    // Tăng ambient
	GLfloat default_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };    // Tăng diffuse tối đa
	GLfloat default_specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };   // Tăng specular
	GLfloat default_shininess[] = { 64.0f };                    // Tăng độ bóng

	glMaterialfv(GL_FRONT, GL_AMBIENT, default_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, default_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, default_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, default_shininess);

	// 5. THIẾT LẬP COLOR TRACKING
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_NORMALIZE);
}

void init() {
	glClearColor(137 / 255.0, 154 / 255.0, 208 / 255.0, 1.0);

}
// Hàm vẽ nội dung chiếu (có thể đặt ở ngoài hoặc trong class tùy cấu trúc code của bạn)
void drawProjectedContent() {
	// Lưu trạng thái ma trận
	glPushMatrix();

	// Di chuyển đến vị trí trên màn hình
	glTranslatef(-5.0f, 1.0f, 0.02f); // Điều chỉnh vị trí text/hình ảnh

	// Vô hiệu hóa ánh sáng để vẽ text/hình ảnh với màu thuần túy
	glDisable(GL_LIGHTING);

	// Vẽ khung phim (màu đen)
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(10.0f, 3.0f, 0.0f);
	glVertex3f(0.0f, 3.0f, 0.0f);
	glEnd();

	// Vẽ nội dung phim (ví dụ: một số hình chữ nhật động)
	static float movieTime = 0.0f;
	movieTime += 0.01f; // Tăng thời gian để tạo hoạt ảnh

	// Vẽ một số hình chữ nhật màu để mô phỏng cảnh phim
	for (int i = 0; i < 5; i++) {
		float x = 0.5f + (i * 2.0f);
		float y = 0.5f + sin(movieTime + i) * 0.5f;

		// Màu ngẫu nhiên dựa trên thời gian
		glColor3f(sin(movieTime + i) * 0.5f + 0.5f,
			cos(movieTime + i * 0.7f) * 0.5f + 0.5f,
			sin(movieTime * 0.8f + i) * 0.5f + 0.5f);

		glBegin(GL_QUADS);
		glVertex3f(x, y, 0.01f);
		glVertex3f(x + 1.5f, y, 0.01f);
		glVertex3f(x + 1.5f, y + 1.0f, 0.01f);
		glVertex3f(x, y + 1.0f, 0.01f);
		glEnd();
	}

	// Vẽ text "NOW PLAYING" 
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos3f(3.5f, 3.5f, 0.01f);
	const char* text = "NOW PLAYING";
	for (const char* c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}

	// Bật lại ánh sáng
	glEnable(GL_LIGHTING);

	// Khôi phục ma trận
	glPopMatrix();
}


void drawScreen() {
	float screenWidth = 12.0f;
	float screenHeight = 5.0f;
	float screenZ = -22.0f;

	// ===== Viền đen xung quanh màn hình =====
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(1.0f, 7.0f, screenZ);
	glScalef(screenWidth + 0.6f, screenHeight + 0.6f, 0.2f);
	glutSolidCube(1.0);
	glPopMatrix();

	// ===== Màn hình trắng bạc ở giữa =====
	glPushMatrix();
	glTranslatef(1.0f, 7.0f, screenZ + 0.01f);

	if (projectorOn) {
		// Thiết lập ánh sáng phản xạ từ màn hình (LIGHT6)
		glEnable(GL_LIGHT6);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Vẽ màn hình cơ bản
		glColor3f(0.85f, 0.85f, 0.85f);
		glPushMatrix();
		glScalef(screenWidth, screenHeight, 0.05f);
		glutSolidCube(1.0);
		glPopMatrix();

		// Thêm hiệu ứng phát sáng
		glColor4f(1.0f, 1.0f, 0.9f, 0.3f);
		glBegin(GL_QUADS);
		glVertex3f(-screenWidth / 2, -screenHeight / 2, 0.1f);
		glVertex3f(screenWidth / 2, -screenHeight / 2, 0.1f);
		glVertex3f(screenWidth / 2, screenHeight / 2, 0.1f);
		glVertex3f(-screenWidth / 2, screenHeight / 2, 0.1f);
		glEnd();

		glDisable(GL_BLEND);
	}
	else {
		// Khi máy chiếu tắt, màn hình có màu xám tối
		glColor3f(0.3f, 0.3f, 0.3f);
		glScalef(screenWidth, screenHeight, 0.05f);
		glutSolidCube(1.0);
	}
	glPopMatrix();

	// ===== Chân khung đỡ màn hình (2 bên) =====
	glColor3f(0.2f, 0.2f, 0.2f);
	for (float offsetX : {-5.5f, 5.5f}) {
		glPushMatrix();
		glTranslatef(1.0f + offsetX, 6.5f, -22.7);
		glScalef(0.3f, 3.0f, 1.3f);
		glutSolidCube(1.0);
		glPopMatrix();
	}
}

void drawChair(float x, float y, float z) {
	glPushMatrix();
	glTranslatef(x, y, z);  // Di chuyển đến vị trí ghế

	// === NỆM NGỒI ===
	glPushMatrix();
	glColor3f(0.7f, 0.1f, 0.1f); // Đỏ đậm
	glTranslatef(0.0f, -0.1f, 0.0f);  // nâng lên khỏi mặt đất
	glScalef(0.8f, 0.2f, 0.8f);       // dài x rộng x cao
	glutSolidCube(1.0f);
	glPopMatrix();

	// === TỰA LƯNG ===
	glPushMatrix();
	glColor3f(0.9f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.3f, 0.35f); // cao hơn và lui về sau
	glScalef(0.8f, 0.7f, 0.1f);       // dày mỏng như tấm lưng
	glutSolidCube(1.0f);
	glPopMatrix();

	// === TAY VỊN TRÁI ===
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(-0.45f, 0.2f, 0.0f);
	glScalef(0.1f, 0.5f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// === TAY VỊN PHẢI ===
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(0.45f, 0.2f, 0.0f);
	glScalef(0.1f, 0.5f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// === 4 CHÂN GHẾ ===
	glColor3f(0.1f, 0.1f, 0.1f);
	float legHeight = 0.2f;
	float legThickness = 0.1f;
	float legYOffset = -0.2f - legHeight / 2; // thấp hơn nệm ngồi

	// chân trước trái
	glPushMatrix();
	glTranslatef(-0.35f, legYOffset, 0.3f);
	glScalef(legThickness, legHeight, legThickness);
	glutSolidCube(1.0f);
	glPopMatrix();

	// chân trước phải
	glPushMatrix();
	glTranslatef(0.35f, legYOffset, 0.3f);
	glScalef(legThickness, legHeight, legThickness);
	glutSolidCube(1.0f);
	glPopMatrix();

	// chân sau trái
	glPushMatrix();
	glTranslatef(-0.35f, legYOffset, -0.3f);
	glScalef(legThickness, legHeight, legThickness);
	glutSolidCube(1.0f);
	glPopMatrix();

	// chân sau phải
	glPushMatrix();
	glTranslatef(0.35f, legYOffset, -0.3f);
	glScalef(legThickness, legHeight, legThickness);
	glutSolidCube(1.0f);
	glPopMatrix();



	glPopMatrix(); // Kết thúc toàn bộ ghế
}


void drawTexturedFloor() {
	float width = 13.0f, height = 0.40f, depth = 8.0f;

	float x = 1.5f, y = 2.2f, z = 3.05f;

	glColor3f(1.0f, 1.0f, 1.0f); // Màu trắng để hiển thị texture đúng nếu dùng
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f); // không scale toàn bộ, scale từng vertex

	// Vẽ mặt trên có vân sọc (giống texture hoặc hiệu ứng gỗ, thảm)
	glBegin(GL_QUADS);
	glColor3f(0.25f, 0.25f, 0.25f); // màu tối
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f); // sọc tối
			else
				glColor3f(0.3f, 0.3f, 0.3f); // sọc sáng hơn

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j + 1.0f);
			glVertex3f(i, height / 2, j + 1);
		}
	}
	glEnd();

	// Các mặt còn lại vẫn giữ nguyên màu xám
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);
	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);
	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}
void drawTexturedFloor1() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.1f;     // Độ dày 0.1f như code cũ
	float depth = 19.0f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = -0.4f;         // Y như code cũ
	float z = -2.5f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j + 1.0f);
			glVertex3f(i, height / 2, j + 1.0f);
		}
	}
	glEnd();

	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}

void drawTexturedFloor2() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.5f;     // Độ dày 0.1f như code cũ
	float depth = 17.0f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = -0.2f;         // Y như code cũ
	float z = -1.45f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j + 1.0f);
			glVertex3f(i, height / 2, j + 1.0f);
		}
	}
	glEnd();


	
	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}
void drawTexturedFloor3() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.4f;     // Độ dày 0.1f như code cũ
	float depth = 15.5f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = 0.2f;         // Y như code cũ
	float z = -0.71f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j );
			glVertex3f(i, height / 2, j);
		}
	}
	glEnd();

	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}

void drawTexturedFloor4() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.4f;     // Độ dày 0.1f như code cũ
	float depth = 14.0f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = 0.6f;         // Y như code cũ
	float z = 0.04f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j+ 1);
			glVertex3f(i, height / 2, j+1);
		}
	}
	glEnd();

	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}

void drawTexturedFloor5() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.4f;     // Độ dày 0.1f như code cũ
	float depth = 12.5f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = 1.0f;         // Y như code cũ
	float z = 0.8f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i, height / 2, j);
		}
	}
	glEnd();

	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}

void drawTexturedFloor6() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.4f;     // Độ dày 0.1f như code cũ
	float depth = 11.0f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = 1.4f;         // Y như code cũ
	float z = 1.55f;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j + 1.0f);
			glVertex3f(i, height / 2, j + 1.0f);
		}
	}
	glEnd();

	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}

void drawTexturedFloor7() {
	// Điều chỉnh kích thước theo code cũ
	float width = 13.0f;     // Chiều rộng như code cũ
	float height = 0.4f;     // Độ dày 0.1f như code cũ
	float depth = 9.35f;     // Chiều dài như code cũ

	// Điều chỉnh vị trí theo code cũ
	float x = 1.5f;          // X như code cũ
	float y = 1.8f;         // Y như code cũ
	float z = 2.38;         // Z như code cũ

	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(1.0f, 1.0f, 1.0f);

	// Vẽ mặt trên với họa tiết ô vuông
	glBegin(GL_QUADS);
	for (float i = -width / 2; i < width / 2; i += 1.0f) {
		for (float j = -depth / 2; j < depth / 2; j += 1.0f) {
			if (((int)(i + j)) % 2 == 0)
				glColor3f(0.2f, 0.2f, 0.2f);
			else
				glColor3f(0.3f, 0.3f, 0.3f);    // Màu sáng hơn một chút

			glVertex3f(i, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i + 1.0f, height / 2, j);
			glVertex3f(i, height / 2, j);
		}
	}
	glEnd();
	
	// Các mặt còn lại màu đồng nhất
	glColor3f(0.2f, 0.2f, 0.2f);

	// Mặt dưới
	glBegin(GL_QUADS);
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glEnd();

	// 4 mặt bên
	glBegin(GL_QUADS);
	// Mặt trước
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);

	// Mặt sau
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt trái
	glVertex3f(-width / 2, -height / 2, -depth / 2);
	glVertex3f(-width / 2, -height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, depth / 2);
	glVertex3f(-width / 2, height / 2, -depth / 2);

	// Mặt phải
	glVertex3f(width / 2, -height / 2, -depth / 2);
	glVertex3f(width / 2, -height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, depth / 2);
	glVertex3f(width / 2, height / 2, -depth / 2);
	glEnd();

	glPopMatrix();
}
void drawCinemaStairs(float startX, float startY, float startZ, int numSteps, float stepWidth, float stepHeight, float stepDepth) {
	for (int i = 0; i < numSteps; i++) {
		glPushMatrix();

		// Dịch chuyển vị trí từng bậc
		glTranslatef(startX, startY + i * stepHeight, startZ + i * stepDepth);

		// Tạo màu xen kẽ giả họa tiết gỗ (2 tông màu xám nâu nhạt và đậm)
		if (i % 2 == 0) {
			glColor3f(0.7f, 0.6f, 0.5f);  // màu nâu nhạt (gỗ sáng)
		}
		else {
			glColor3f(0.5f, 0.4f, 0.3f);  // màu nâu đậm (gỗ tối)
		}

		// Vẽ bậc thang là hình hộp với kích thước: rộng x cao x sâu
		glScalef(stepWidth, stepHeight, stepDepth);
		glutSolidCube(1.0);

		glPopMatrix();
	}
}


void floor() {

	drawTexturedFloor();
	drawTexturedFloor1();
	drawTexturedFloor2();
	drawTexturedFloor3();
	drawTexturedFloor4();
	drawTexturedFloor5();
	drawTexturedFloor6();
	drawTexturedFloor7();

}



void drawChairRows() {
	char rowLabels[] = { 'A','B','C','D','E','F','G','H' };
	float seatSpacingX = 1.0f;
	float seatSpacingZ = 1.5f;
	float baseY = 0.0f;
	float yStep = 0.4f;


	for (int i = 0; i < 8; i++) { // 8 hàng ghế
		float y = baseY + (7 - i) * yStep;
		float z = -i * seatSpacingZ;


		// Ghế bên trái (2 cái)
		for (int j = 0; j < 2; j++) {
			float x = (j - 4.5f) * seatSpacingX;  // Dịch ra ngoài bên trái
			drawChair(x, y, z);

				
		}

		// Ghế bên phải (9 cái)
		for (int j = 0; j < 9; j++) {
			float x = (j - 0.5f) * seatSpacingX;  // Dịch ra ngoài bên phải
			drawChair(x, y, z);
		}
	}
}


void drawSpeaker(float x, float y, float z) {
	// Thân loa (màu xám đậm)
	glColor3f(0.2f, 0.2f, 0.2f);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(0.5f, 1.0f, 0.3f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Màng loa (màu đen)
	glColor3f(0.05f, 0.05f, 0.05f);
	glPushMatrix();
	glTranslatef(x, y, z + 0.16f);  // hơi nhô ra phía trước
	glutSolidSphere(0.2f, 20, 20);
	glPopMatrix();
}
void setMaterialColor(
	float r1, float g1, float b1,
	float r2, float g2, float b2,
	float r3, float g3, float b3,
	float alpha1, float alpha2, float alpha3
)
{
	GLfloat ambientColor[] = { r1, g1, b1, alpha1 }; // Màu phản chiếu môi trường
	GLfloat diffuseColor[] = { r2, g2, b2, alpha2 }; // Màu phản chiếu khuyếch tán
	GLfloat specularColor[] = { r3, g3, b3, alpha3 }; // Màu phản chiếu gương

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularColor);
}
void drawCube(
	float x1, float y1, float z1, // góc trái dưới
	float x2, float y2, float z2, // góc phải dưới
	float x3, float y3, float z3, // góc phải trên
	float x4, float y4, float z4, // góc trái trên
	float r = 255, float g = 255, float b = 255, // màu sắc
	float thickness = 0.1, // độ dày của tường
	std::string direction = "y" // hướng lùi
) {


	glColor3f(r / 255.0, g / 255.0, b / 255.0); // Set color

	// Thiết lập màu sắc cho vật liệu


	float dx = 0, dy = 0, dz = 0;
	if (direction == "x") dx = thickness;
	else if (direction == "y") dy = thickness;
	else if (direction == "z") dz = thickness;

	// Mặt trước
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x4, y4, z4);
	glEnd();

	// Viền trc
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_LINE_LOOP);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x4, y4, z4);
	glEnd();


	// Mặt sau
	glColor3f(r / 255.0, g / 255.0, b / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x1 - dx, y1 - dy, z1 - dz);
	glVertex3f(x2 - dx, y2 - dy, z2 - dz);
	glVertex3f(x3 - dx, y3 - dy, z3 - dz);
	glVertex3f(x4 - dx, y4 - dy, z4 - dz);
	glEnd();


	// Mặt trên
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x4, y4, z4);
	glVertex3f(x3, y3, z3);
	glVertex3f(x3 - dx, y3 - dy, z3 - dz);
	glVertex3f(x4 - dx, y4 - dy, z4 - dz);
	glEnd();

	//Viền Mặt trên
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_LINE_LOOP);
	glVertex3f(x4, y4, z4);
	glVertex3f(x3, y3, z3);
	glVertex3f(x3 - dx, y3 - dy, z3 - dz);
	glVertex3f(x4 - dx, y4 - dy, z4 - dz);
	glEnd();


	// Mặt dưới
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2 - dx, y2 - dy, z2 - dz);
	glVertex3f(x1 - dx, y1 - dy, z1 - dz);
	glEnd();


	// Viền Mặt dưới
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_LINE_LOOP);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2 - dx, y2 - dy, z2 - dz);
	glVertex3f(x1 - dx, y1 - dy, z1 - dz);
	glEnd();


	// Mặt phải
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x3 - dx, y3 - dy, z3 - dz);
	glVertex3f(x2 - dx, y2 - dy, z2 - dz);
	glEnd();

	//Viền Mặt phải
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x3 - dx, y3 - dy, z3 - dz);
	glVertex3f(x2 - dx, y2 - dy, z2 - dz);
	glEnd();


	// Mặt trái
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, z1);
	glVertex3f(x4, y4, z4);
	glVertex3f(x4 - dx, y4 - dy, z4 - dz);
	glVertex3f(x1 - dx, y1 - dy, z1 - dz);
	glEnd();


	// Viền Mặt trái
	glBegin(GL_QUADS);
	glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0); // Set color
	glVertex3f(x1, y1, z1);
	glVertex3f(x4, y4, z4);
	glVertex3f(x4 - dx, y4 - dy, z4 - dz);
	glVertex3f(x1 - dx, y1 - dy, z1 - dz);
	glEnd();
}
// Hàm vẽ một hình vuông trang trí với viền
void drawDecorativeSquare(float size) {
	// Vẽ viền trắng
	glColor3f(1.0f, 1.0f, 1.0f);  // Màu trắng cho viền
	glPushMatrix();
	glScalef(size, size, 0.02f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Vẽ phần trong màu hồng
	glColor3f(0.95f, 0.75f, 0.75f);  // Màu hồng nhạt
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.01f);
	glScalef(size - 0.05f, size - 0.05f, 0.02f);
	glutSolidCube(1.0f);
	glPopMatrix();
}

//Tường và sàn nhà
void drawWalls() {


	glPushMatrix();
	GLfloat wall_ambient[] = { 237 / 255.0, 230 / 255.0, 214 / 255.0, 1.0 }; // Màu tường  
	GLfloat wall_diffuse[] = { 237 / 255.0, 230 / 255.0, 214 / 255.0, 1.0 }; // Màu tường
	GLfloat wall_specular[] = { 0.0, 0.0, 0.0, 1.0 }; // Màu tường

	// Thiết lập màu sắc phản chiếu cho mặt trước của tường
	glMaterialfv(GL_FRONT, GL_AMBIENT, wall_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, wall_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, wall_specular);

	// Thiết lập màu sắc phản chiếu cho mặt sau của tường
	glMaterialfv(GL_BACK, GL_AMBIENT, wall_ambient);
	glMaterialfv(GL_BACK, GL_DIFFUSE, wall_diffuse);
	glMaterialfv(GL_BACK, GL_SPECULAR, wall_specular);


	// Tường sau phần trên (từ 5.0f đến 12.2f - như phần trên tường phải)
	drawCube(
		-5.5f, 5.0f, -23.0f,     // góc trái dưới
		8.5f, 5.0f, -23.0f,      // góc phải dưới
		8.5f, 12.2f, -23.0f,     // góc phải trên
		-5.5f, 12.2f, -23.0f,    // góc trái trên
		100, 0, 0,              // màu sắc
		0.5f,                     // độ dày của tường
		"z"                       // hướng lùi
	);

	// Tường sau phần dưới (từ -0.8f đến 5.0f - như phần bên trái/phải tường phải)
	drawCube(
		-5.5f, -0.8f, -23.0f,    // góc trái dưới
		8.5f, -0.8f, -23.0f,     // góc phải dưới
		8.5f, 5.0f, -23.0f,      // góc phải trên
		-5.5f, 5.0f, -23.0f,     // góc trái trên
		100, 0, 0,              // màu sắc
		0.5f,                     // độ dày của tường
		"z"                       // hướng lùi
	);

	// Tường phải phần trên cửa
	drawCube(
		8.5f, 5.0f, -23.0f,      // góc trái dưới
		8.5f, 12.2f, -23.0f,     // góc phải dưới
		8.5f, 12.2f, 7.0f,       // góc phải trên
		8.5f, 5.0f, 7.0f,        // góc trái trên
		100, 0, 0,              // màu sắc
		0.3f,                     // độ dày
		"x"                       // hướng lùi
	);
	// Tường phải phần dưới cửa
	drawCube(
		8.5f, -0.8f, -23.0f,     // góc trái dưới
		8.5f, 0.0f, -23.0f,      // góc phải dưới
		8.5f, 0.0f, 7.0f,        // góc phải trên
		8.5f, -0.8f, 7.0f,       // góc trái trên
		100, 0, 0,              // màu sắc
		0.3f,                     // độ dày
		"x"                       // hướng lùi
	);

	// Tường phải bên trái cửa
	drawCube(
		8.5f, 0.0f, -23.0f,      // góc trái dưới
		8.5f, 5.0f, -23.0f,      // góc phải dưới
		8.5f, 5.0f, -19.5f,      // góc phải trên (điều chỉnh thành -19.5f)
		8.5f, 0.0f, -19.5f,      // góc trái trên (điều chỉnh thành -19.5f)
		100, 0, 0,              // màu sắc
		0.3f,                     // độ dày
		"x"                       // hướng lùi
	);

	// Tường phải bên phải cửa
	drawCube(
		8.5f, 0.0f, -14.5f,      // góc trái dưới (điều chỉnh thành -14.5f)
		8.5f, 5.0f, -14.5f,      // góc phải dưới (điều chỉnh thành -14.5f)
		8.5f, 5.0f, 7.0f,        // góc phải trên
		8.5f, 0.0f, 7.0f,        // góc trái trên
		100, 0, 0,              // màu sắc
		0.3f,                     // độ dày
		"x"                       // hướng lùi
	);

	// Nền nhà
	drawCube(
		-5.5f, -0.45f, -23.0f,     // góc trái dưới
		8.5f, -0.45f, -23.0f,      // góc phải dưới
		8.5f, -0.45f, 7.0f,        // góc phải trên
		-5.5f, -0.45f, 7.0f,       // góc trái trên
		50, 50, 50,            // màu sắc
		0.5f,                     // độ dày của sàn
		"y"                       // hướng lùi
	);

	// Trần nhà
	drawCube(
		-5.5f, 12.2f, -23.0f,     // góc trái dưới
		8.5f, 12.2f, -23.0f,      // góc phải dưới
		8.5f, 12.2f, 7.0f,        // góc phải trên
		-5.5f, 12.2f, 7.0f,       // góc trái trên
		255, 255, 255,            // màu sắc
		0.5f,                     // độ dày của trần
		"y"                       // hướng lùi
	);
	glPopMatrix();
}
void drawOldStyleSpeaker() {
	// Thiết lập màu và vật liệu cho loa
	GLfloat speakerMaterial[] = { 0.23f, 0.7f, 0.3f, 1.0f };  // Màu xám đậm
	GLfloat speakerSpecular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat speakerShininess[] = { 30.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, speakerMaterial);
	glMaterialfv(GL_FRONT, GL_SPECULAR, speakerSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, speakerShininess);

	glPushMatrix();

	// Vẽ hình thang (phần chính của loa)
	glBegin(GL_QUADS);
	// Mặt trước (phần lớn - mặt loa)
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.5f, 1.0f);    // Mặt trước rộng hơn
	glVertex3f(1.5f, -1.5f, 1.0f);
	glVertex3f(1.5f, 1.5f, 1.0f);
	glVertex3f(-1.5f, 1.5f, 1.0f);

	// Mặt sau (phần nhỏ - gắn tường)
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-0.75f, -0.75f, 0.0f);  // Mặt sau nhỏ hơn
	glVertex3f(0.75f, -0.75f, 0.0f);
	glVertex3f(0.75f, 0.75f, 0.0f);
	glVertex3f(-0.75f, 0.75f, 0.0f);

	// Các mặt bên
	// Mặt trên
	glVertex3f(-1.5f, 1.5f, 1.0f);
	glVertex3f(1.5f, 1.5f, 1.0f);
	glVertex3f(0.75f, 0.75f, 0.0f);
	glVertex3f(-0.75f, 0.75f, 0.0f);

	// Mặt dưới
	glVertex3f(-1.5f, -1.5f, 1.0f);
	glVertex3f(1.5f, -1.5f, 1.0f);
	glVertex3f(0.75f, -0.75f, 0.0f);
	glVertex3f(-0.75f, -0.75f, 0.0f);

	// Mặt trái
	glVertex3f(-1.5f, -1.5f, 1.0f);
	glVertex3f(-1.5f, 1.5f, 1.0f);
	glVertex3f(-0.75f, 0.75f, 0.0f);
	glVertex3f(-0.75f, -0.75f, 0.0f);

	// Mặt phải
	glVertex3f(1.5f, -1.5f, 1.0f);
	glVertex3f(1.5f, 1.5f, 1.0f);
	glVertex3f(0.75f, 0.75f, 0.0f);
	glVertex3f(0.75f, -0.75f, 0.0f);
	glEnd();

	glPopMatrix();
}

void drawSpeakersOnRightWall() {
	// Loa 1 - gần phía trước
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(8.2f, 8.0f, 0.0f);      // Lùi vào 0.3f so với tường
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); // Xoay để hướng ra ngoài tường
	glScalef(0.5f, 0.5f, 0.5f);          // Thu nhỏ loa
	drawOldStyleSpeaker();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27f, 0.27f, 0.27f);
	glTranslatef(7.8f, 8.0f, 0.0);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();

	// Loa 2 - ở giữa
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(8.2f, 8.0f, -8.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawOldStyleSpeaker();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27f, 0.27f, 0.27f);
	glTranslatef(7.8f, 8.0f, -8.0);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();

	// Loa 3 - gần phía sau
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f);
	glTranslatef(8.2f, 8.0f, -16.0f);
	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	drawOldStyleSpeaker();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.27f, 0.27f, 0.27f);
	glTranslatef(7.8f, 8.0f, -16.0);
	glutSolidSphere(0.3, 50, 50);// vẽ hình cầu
	glutWireSphere(0.3, 50, 50);// vẽ lưới hình cầu
	glPopMatrix();
}
void drawCinemaDoor() {
	glPushMatrix();
	glTranslatef(8.5f, 2.5f, -17.0f);  
	glRotatef(doorAngle, 0, 1, 0);     // Xoay quanh trục Y

	// Khung cửa
	glColor3f(0.2f, 0.2f, 0.2f);      // Màu xám đậm cho khung
	glPushMatrix();
	glScalef(0.2f, 5.0f, 5.0f);       // Kích thước khung
	glutSolidCube(1.0f);
	glPopMatrix();

	// Mặt cửa chính
	glColor3f(0.5f, 0.3f, 0.2f);      // Màu nâu đỏ cho cửa
	glPushMatrix();
	glTranslatef(-0.1f, 0.0f, 0.0f);  // Lùi vào một chút so với khung
	glScalef(0.1f, 4.8f, 4.8f);       // Kích thước nhỏ hơn khung
	glutSolidCube(1.0f);
	glPopMatrix();

	// Tay nắm cửa
	glColor3f(0.8f, 0.8f, 0.8f);      // Màu bạc cho tay nắm
	glPushMatrix();
	glTranslatef(-0.2f, 0.0f, -2.0f); // Vị trí tay nắm
	glScalef(0.1f, 0.3f, 0.8f);       // Kích thước tay nắm
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();
}


void drawProjector() {
	glPushMatrix();
	glTranslatef(1.0f, 11.0f, -5.0f);

	// Vẽ thân máy chiếu
	if (projectorOn) {
		glColor3f(0.8f, 0.8f, 0.8f);
	}
	else {
		glColor3f(0.3f, 0.3f, 0.3f);
	}

	glPushMatrix();
	glScalef(2.0f, 0.5f, 2.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glColor3f(0.3f, 0.3f, 0.3f);
	glPushMatrix();
	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(0.4f, 1.0f, 0.3f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Vẽ ống kính
	glColor3f(0.1f, 0.1f, 0.1f);
	glPushMatrix();
	glTranslatef(0.0f, -0.1f, -1.0f);
	glScalef(0.4f, 0.4f, 0.3f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Thiết lập ánh sáng máy chiếu (LIGHT7)
	if (projectorOn) {
		glEnable(GL_LIGHT7);

		// Vị trí ánh sáng (từ ống kính máy chiếu)
		GLfloat projector_pos[] = { 1.0f, 10.9f, -6.0f, 1.0f };

		// Hướng chiếu (hướng xuống và về phía trước)
		GLfloat projector_direction[] = { 0.0f, -0.2f, -1.0f };

		// Thiết lập màu ánh sáng với cường độ cao hơn
		GLfloat projector_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };    // Thêm ambient light
		GLfloat projector_diffuse[] = { 1.5f, 1.5f, 1.4f, 1.0f };    // Tăng cường độ diffuse
		GLfloat projector_specular[] = { 1.0f, 1.0f, 0.9f, 1.0f };   // Tăng specular

		glLightfv(GL_LIGHT7, GL_POSITION, projector_pos);
		glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, projector_direction);
		glLightfv(GL_LIGHT7, GL_AMBIENT, projector_ambient);
		glLightfv(GL_LIGHT7, GL_DIFFUSE, projector_diffuse);
		glLightfv(GL_LIGHT7, GL_SPECULAR, projector_specular);

		// Điều chỉnh các thông số spotlight để chiếu sáng rộng hơn
		glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 60.0f);        // Tăng góc chiếu
		glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 10.0f);      // Giảm độ tập trung để ánh sáng lan tỏa hơn

		// Điều chỉnh suy giảm ánh sáng
		glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.8f);
		glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.03f);
		glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.002f);

		// Vẽ tia sáng nhìn thấy được
		glPushMatrix();
		glTranslatef(0.0f, -0.1f, -1.0f);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_LIGHTING);

		// Vẽ nhiều lớp tia sáng với độ trong suốt khác nhau
		for (int i = 0; i < 12; i++) {  // Tăng số lượng tia
			float alpha = 0.03f - (i * 0.002f);  // Tăng độ trong suốt ban đầu
			glColor4f(1.0f, 1.0f, 0.9f, alpha);

			glBegin(GL_TRIANGLES);
			glVertex3f(0.0f, 0.0f, 0.0f);

			float angle = i * (M_PI / 6.0f);  // Chia đều 12 tia
			float radius = 4.0f;  // Tăng bán kính
			glVertex3f(radius * cos(angle), -2.5f, -12.0f + (radius * sin(angle)));
			glVertex3f(radius * cos(angle + M_PI / 6.0f), -2.5f, -12.0f + (radius * sin(angle + M_PI / 6.0f)));
			glEnd();
		}

		// Vẽ thêm một cone ánh sáng lớn hơn với độ trong suốt thấp
		glColor4f(1.0f, 1.0f, 0.9f, 0.01f);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.0f, 0.0f);
		for (int i = 0; i <= 32; i++) {
			float angle = i * (2.0f * M_PI / 32.0f);
			float radius = 5.0f;
			glVertex3f(radius * cos(angle), -3.0f, -12.0f + (radius * sin(angle)));
		}
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_BLEND);
		glPopMatrix();
	}
	else {
		glDisable(GL_LIGHT7);
	}

	glPopMatrix();
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(cameraController.getCameraX(), cameraController.getCameraY(), cameraController.getCameraZ(), 0, 1, -5, 0, 1, 0);
	drawCinemaDoor();
	drawScreen();      // màn hình
	drawChairRows();   // các hàng ghế
	drawSpeakersOnRightWall();
	drawWalls();       // Vẽ tường, trần, sàn
	floor();
	// Hai bên màn chiếu (giả sử màn chiếu ở z = -16.0f)
	drawSpeaker(-4.0f, 3.5f, -23.0f);  // Bên trái
	drawSpeaker(6.0f, 3.5f, -23.0f);   // Bên phải
	drawCeilingLight();
	drawProjector();
	setupLighting();
	glFlush();
	glutSwapBuffers();
}




void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraController.getCameraX(), cameraController.getCameraY(), cameraController.getCameraZ(), 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


int main(int argc, char** argv) {

	printf("Huong dan dieu khien:\n");
	printf("wasd, zx: Di chuyen camera\n");
	printf("q/e: Xoay camera trai/phai\n");
	printf("1: Bat den moi truong\n");
	printf("2-5: Bat/tat tung dan den tran (trai/phai, tren/duoi)\n");
	printf("6-8: Bat/tat dong thoi cac dan den trai/phai\n");
	printf("p: Bat/tat may chieu\n");
	printf("o/O, c/C: Mo/dong cua bang cach thay doi goc quay doorAngle\n");
	printf("[, ], {, }: Di chuyen vi tri dan den trong khong gian\n");
	printf("h/j: Dieu chinh goc chieu den (thu hep/mo rong anh sang)\n");




	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	int windowWidth = 1200;

	int windowHeight = 950;

	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("3D Room");
	glutMouseFunc([](int button, int state, int x, int y) { cameraController.Mouse(button, state, x, y); });
	glutMotionFunc([](int x, int y) { cameraController.Motion(x, y); });
	glutKeyboardFunc([](unsigned char key, int x, int y) { cameraController.Keyboard(key, x, y); });
	glutSpecialFunc([](int key, int x, int y) { cameraController.SpecialKeys(key, x, y); });

	glEnable(GL_DEPTH_TEST);
	init();
	glutIdleFunc(display); // hoặc glutPostRedisplay();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}