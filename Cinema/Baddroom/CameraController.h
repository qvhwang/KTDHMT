#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H
#define NUM_LIGHT_ROWS 4  // 4 dàn đèn

class CameraController {
public:
    CameraController(float initialX = 12, float initialY = 5, float initialZ = 22);
    void Mouse(int button, int state, int x, int y);
    void Motion(int x, int y);
    void SpecialKeys(int key, int x, int y);
    void Keyboard(unsigned char key, int x, int y);
    float getCameraX() const { return cameraX; }
    float getCameraY() const { return cameraY; }
    float getCameraZ() const { return cameraZ; }
    float angleY = 0.0f;  // Góc xoay quanh trục Y

    
private:
    float spotCutoff = 45.0f;     // Góc chiếu mặc định
    float spotExponent = 10.0f;   // Độ tập trung mặc định
    float cameraX;
    float cameraY;
    float cameraZ;
    int lastMouseX;
    int lastMouseY;
    float spotDirectionX = 0.0f;    // Thêm biến điều khiển hướng X
    float spotDirectionZ = 0.0f;    // Thêm biến điều khiển hướng Z
    const float rotateSpeed = 1.0f;  // Tốc độ xoay
    float lightMoveSpeed = 0.5f;  // Tốc độ di chuyển đèn

    
};
extern bool isLightOn;
extern bool isLightOn1;
extern bool isLightOn2;
extern bool isLightShining;
extern float doorOffset;
extern float doorAngle;
extern bool doorOpening;


#endif // CAMERACONTROLLER_H
