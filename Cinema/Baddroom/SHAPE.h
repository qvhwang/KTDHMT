#include <string>
#include "glut.h"
#
class SHAPE {
public:
	// H toạ độ
	void draw() {
		// X-axis (red)
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(10, 0, 0);
		glEnd();

		// Y-axis (green)
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 10, 0);
		glEnd();

		// Z-axis (blue)
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 10);
		glEnd();
	}

	// Hàm vẽ khối 
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


		// Tường trái
		drawCube(
			0, 0, 0, // góc trái dưới
			0, 5, 0, // góc phải dưới
			0, 5, 10, // góc phải trên
			0, 0, 10, // góc trái trên
			60, 80, 45, // màu sắc
			0.3, // độ dày của tường
			"x" // hướng lùi
		);

		// Tường phải
		drawCube(
			-0.3, 0, 0, // góc trái dưới
			10, 0, 0, // góc phải dưới
			10, 5, 0, // góc phải trên
			-0.3, 5, 0, // góc trái trên
			65, 85, 50, // màu sắc
			0.3, // độ dày của tường
			"z" // hướng lùi
		);

		// Nền nhà
		drawCube(
			-0.3, 0, -0.3, // góc trái dưới
			10, 0, -0.3, // góc phải dưới
			10, 0, 10, // góc phải trên
			-0.3, 0, 10, // góc trái trên
			214, 233, 229, // màu sắc
			0.3, // độ dày của tường
			"y" // hướng lùi
		);
		// Trần nhà
		drawCube(
			-0.3, 4.99f, -0.299, // góc trái dưới
			7.99, 4.99f, -0.299, // góc phải dưới
			4.99, 4.99f, 4.99, // góc phải trên
			-0.299, 4.99f, 7.99, // góc trái trên
			255, 255, 255, // màu sắc
			0.3, // độ dày của tường
			"y" // hướng lùi
		);
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

	void drawBed() {
		// Khung giường
		glPushMatrix();
		setMaterialColor(210 / 255.0, 180 / 255.0, 140 / 255.0,  // Ambient color
			210 / 255.0, 180 / 255.0, 140 / 255.0,  // Diffuse color
			1.0, 1.0, 1.0,                          // Specular color
			1.0f, 1.0f, 1.0f);                      // Alpha values

		glTranslatef(1.75f, 0.1f, 4.5f); // Vị trí dịch thêm 3 theo trục z
		glScalef(2.0f, 0.2f, 1.65f); // Kích thước không thay đổi
		glutSolidCube(2.0f);
		glColor3f(48 / 255.0, 29 / 255.0, 31 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();

		// Đệm
		glPushMatrix();
		glTranslatef(1.75f, 0.4f, 4.5f); // Vị trí dịch thêm 3 theo trục z
		glScalef(1.8f, 0.1f, 1.5f); // Kích thước không thay đổi
		glutSolidCube(2.0f);
		glColor3f(118 / 255.0, 69 / 255.0, 70 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();

		// Đầu giường
		glPushMatrix();
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0); // Màu nâu nhạt
		glTranslatef(0.1f, 0.5f, 4.499f); // Vị trí dịch thêm 3 theo trục z
		glScalef(0.2f, 1.2f, 3.0f); // Kích thước không thay đổi
		glutSolidCube(1.0f);
		glColor3f(118 / 255.0, 69 / 255.0, 70 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();

		// Gối 1
		glPushMatrix();
		glColor3f(228 / 255.0, 223 / 255.0, 219 / 255.0); // Màu nâu nhạt
		glTranslatef(0.5f, 0.55f, 5.3f); // Vị trí dịch thêm 3 theo trục z
		glScalef(0.5f, 0.13f, 0.6f); // Kích thước không thay đổi
		glutSolidCube(1.0f);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();

		// Gối 2
		glPushMatrix();
		glColor3f(228 / 255.0, 223 / 255.0, 219 / 255.0); // Màu nâu nhạt
		glTranslatef(0.5f, 0.55f, 4.0f); // Vị trí dịch thêm 3 theo trục z
		glScalef(0.5f, 0.13f, 0.6f); // Kích thước không thay đổi
		glutSolidCube(1);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();

		// Chăn
		glPushMatrix();
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0); // Màu nâu nhạt
		glTranslatef(2.5f, 0.52f, 4.5f); // Vị trí dịch thêm 3 theo trục z
		glScalef(1.85f, 0.05f, 2.5f); // Kích thước không thay đổi
		glutSolidCube(1);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0);
		glutWireCube(1.0f);
		glPopMatrix();
	}




#pragma region --              



	// vẽ tay nắm tủ
	void drawCabinetHandle(float x, float y, float z) {
		glPushMatrix();
		glColor3f(0 / 255.0, 0 / 255.0, 0 / 255.0);
		glTranslatef(x, y, z); // vị trí
		glScalef(0.1f, 0.02f, 0.02f); // kích thước
		glutSolidCube(1);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0);
		glutWireCube(1);
		glPopMatrix();
	}

	// Tủ 
	void drawCabinetAndLamp() {
		// Tủ
		glPushMatrix();
		GLfloat cabinet_ambient[] = { 196 / 255.0, 132 / 255.0, 89 / 255.0 }; // Màu vàng nhạt
		GLfloat cabinet_diffuse[] = { 196 / 255.0, 132 / 255.0, 89 / 255.0 }; // giảm giá trị diffuse
		GLfloat cabinet_specular[] = { 196 / 255.0, 164 / 255.0, 123 / 255.0, 1.0 }; // giảm giá trị specular
		glMaterialfv(GL_FRONT, GL_AMBIENT, cabinet_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cabinet_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, cabinet_specular);

		glColor3f(162 / 255.0, 108 / 255.0, 72 / 255.0); // màu nâu nhạt
		glTranslatef(6.3f - 4.3f, 0.5f, 0.5f); // vị trí 
		glScalef(3.3f, 1.2f, 1.0f); // kích thước
		glutSolidCube(1.2f);
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0);
		glutWireCube(1);
		glPopMatrix();

		// Ngăn 1
		glPushMatrix();
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0); // màu nâu nhạt
		glTranslatef(5.2f - 4.3f, 0.5f, 0.9f); // vị trí
		glScalef(0.85f, 0.2f, 0.7f); // kích thước
		glutSolidCube(1);
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0);
		glutWireCube(1);
		glPopMatrix();
		drawCabinetHandle(5.25f - 4.3f, 0.55f, 1.25f); // vị trí nắm kéo ngăn 1

		// Ngăn 2
		glPushMatrix();
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0); // màu nâu nhạt
		glTranslatef(6.6f - 4.3f, 0.5f, 0.9f); // vị trí
		glScalef(0.85f, 0.2f, 0.7f); // kích thước
		glutSolidCube(1);
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0);
		glutWireCube(1);
		glPopMatrix();
		drawCabinetHandle(6.6f - 4.3f, 0.5f, 1.25f); // vị trí nắm kéo ngăn 2

		// Ngăn 3
		glPushMatrix();
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0); // màu nâu nhạt
		glTranslatef(5.2f - 4.3f, 0.9f, 0.9f); // vị trí
		glScalef(0.85f, 0.2f, 0.7f); // kích thước
		glutSolidCube(1);
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0);
		glutWireCube(1);
		glPopMatrix();
		drawCabinetHandle(5.2f - 4.3f, 0.9f, 1.25f); // vị trí nắm kéo ngăn 3

		// Ngăn 4
		glPushMatrix();
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0); // màu nâu nhạt
		glTranslatef(6.6f - 4.3f, 0.9f, 0.9f); // vị trí
		glScalef(0.85f, 0.2f, 0.7f); // kích thước
		glutSolidCube(1);
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0);
		glutWireCube(1);
		glPopMatrix();
		drawCabinetHandle(6.6f - 4.3f, 0.9f, 1.25f); // vị trí nắm kéo ngăn 4



		void Tea();
	}
	float bigCabinetDoorAngle = -45.0f;

	void drawCabinetInterior() {
		glPushMatrix();
		glColor3f(139 / 255.0, 69 / 255.0, 19 / 255.0); // màu nâu sẫm
		glTranslatef(3.39f, 0.6f, 0.605f); // vị trí
		glScalef(0.7f, 1.0f, 1.0f); // kích thước
		glutSolidCube(1);
		glColor3f(128 / 255.0, 128 / 255.0, 128 / 255.0);
		glutWireCube(1);
		glPopMatrix();
	}

	void drawBigCabinetDoor() {
		// Vẽ không gian bên trong tủ
		if (bigCabinetDoorAngle < 0) {
			drawCabinetInterior();
		}

		// Vẽ cánh tủ
		glPushMatrix();
		glColor3f(196 / 255.0, 132 / 255.0, 89 / 255.0); // màu nâu nhạt
		glTranslatef(3.39f, 0.6f, 1.1f); // vị trí
		glTranslatef(-0.4f, 0.0f, 0.0f); // di chuyển trục xoay về cạnh bên trái của cánh tủ
		glRotatef(bigCabinetDoorAngle, 0.0f, 1.0f, 0.0f); // xoay cánh tủ
		glTranslatef(0.4f, 0.0f, 0.0f); // di chuyển trục xoay về vị trí ban đầu
		glScalef(0.8f, 1.0f, 0.05f); // kích thước
		glutSolidCube(1);
		glColor3f(203 / 255.0, 139 / 255.0, 93 / 255.0);
		glutWireCube(1);

		drawCabinetHandle(0.2f, 0.0f, 0.65f); // vị trí nắm kéo cánh tủ lớn
		glPopMatrix();
	}

	void Tea() {
		glColor3f(1.0, 0.0, 0.0); // Màu đỏ
		glutSolidTeapot(5.0); // Vẽ teapot solid với kích thước 0.5
	}
#pragma endregion

#pragma region Loa
	void drawSpeaker() {
		// Vẽ thân loa
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Màu đen
		glTranslatef(0.8f, 1.48f, 0.3f); // Vị trí loa
		glScalef(0.5f, 0.5f, 0.5f); // Kích thước loa
		glutSolidCube(1.0f);
		glPopMatrix();

		// Vẽ phần trước của loa
		GLUquadric* quad = gluNewQuadric();
		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Màu trắng
		glTranslatef(0.8f, 1.48f, 0.458f); // Vị trí phần trước của loa
		gluCylinder(quad, 0.2f, 0.2f, 0.1f, 32, 32); // Vẽ hình trụ
		glPopMatrix();

		// Vẽ thân loa
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0); // Màu đen
		glTranslatef(1.5f, 1.48f, 0.3f); // Vị trí loa
		glScalef(0.5f, 0.5f, 0.5f); // Kích thước loa
		glutSolidCube(1.0f);
		glPopMatrix();

		// Vẽ phần trước của loa

		glPushMatrix();
		glColor3f(1.0, 1.0, 1.0); // Màu trắng
		glTranslatef(1.5f, 1.48f, 0.458f); // Vị trí phần trước của loa
		gluCylinder(quad, 0.2f, 0.2f, 0.1f, 32, 32); // Vẽ hình trụ
		glPopMatrix();

		gluDeleteQuadric(quad);


	}
#pragma endregion



	// đèn ngủ
	const int num_slices = 50; // Số lượng phân đoạn của đèn ngủ

	void drawCylinder(double radiusTop, double radiusBottom, double height) {
		GLUquadric* quadric = gluNewQuadric();
		gluQuadricDrawStyle(quadric, GLU_FILL);
		gluQuadricNormals(quadric, GLU_SMOOTH);

		glPushMatrix();
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);// Xoay trục z 90 độ
		gluCylinder(quadric, radiusBottom, radiusTop, height, num_slices, 1);
		glPopMatrix();

		gluDeleteQuadric(quadric);
	}

	void drawLamp() {
		double top_radius = 0.3; // Bán kính đỉnh
		double bottom_radius = 0.5; // Bán kính đáy
		double height = 1.0; // Chiều cao

		glTranslatef(0.47f, 1.65f, 2.2f);// Vị trí đèn ngủ

		glColor3f(250 / 255.0, 241 / 255.0, 214 / 255.0); // Màu vàng
		// Vẽ hình trụ
		drawCylinder(top_radius, bottom_radius, height);

		glColor3f(0.5, 0.5, 0.5); // Màu xám cho thanh sắt
		// Vẽ thanh sắt giữ bóng đèn
		glTranslatef(0.0f, -0.5f, 0.0f); // Điều chỉnh vị trí của thanh sắt
		drawCylinder(0.05, 0.05, 0.5); // Vẽ hình trụ nhỏ để tạo thanh sắt

		// Vẽ thanh sắt nằm ngang từ tường đến thanh sắt hiện tại
		glColor3f(0.5, 0.5, 0.5); // Màu xám cho thanh sắt
		glTranslatef(0.045f, 0.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		drawCylinder(0.05, 0.05, 0.6);
		glRotatef(-90.0f, 0.0f, 1.0f, 0.0f); // Xoay trở lại vị trí ban đầu
	}



	void DrawFull() {
		//draw();
		drawWalls();
		drawBed();
		drawCabinetAndLamp();
		drawBigCabinetDoor();
		//drawSpeaker();
		drawLamp();
	}

};

