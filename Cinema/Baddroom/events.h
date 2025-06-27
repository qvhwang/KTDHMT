#ifndef EVENTS_H
#define EVENTS_H

extern float seatAngle; // ← Khai báo để các file khác dùng được

void keyboard(unsigned char key, int x, int y);
void idle();
void initGL();

#endif
