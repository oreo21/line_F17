#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int calcOctant(float slope){
  if (slope > 0 && slope <= 1)  return 1;
  else if (slope > 1) return 2;
  else if (slope < 0 && slope >= -1) return 8;
  else if (slope < -1) return 7;
  else return 0; //slope is either 0 or undefined
}

void draw_octant1(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = 2 * A + B;
  int x = x0, y = y0;
  while (x <= x1){
    plot(s, c, x, y);
    if (d > 0) y++, d += 2 * B;
    x++, d += 2 * A;
  }
}

void draw_octant2(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = A + 2 * B;
  int x = x0, y = y0;
  while (y <= y1){
    plot(s, c, x, y);
    if (d < 0) x++, d += 2 * A;
    y++, d += 2 * B;
  }
}

void draw_octant7(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = A - 2 * B;
  int x = x0, y = y0;
  while (y >= y1){
    plot(s, c, x, y);
    if (d > 0) x++, d += 2 * A;
    y--, d -= 2 * B;
  }
}

void draw_octant8(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = 2 * A - B;
  int x = x0, y = y0;
  while (x <= x1){
    plot(s, c, x, y);
    if (d < 0) y--, d -= 2 * B;
    x++, d += 2 * A;
  }
}

void draw_else(int x0, int y0, int x1, int y1, screen s, color c) { 
  int x = x0, y = y0;
  if (y0 == y1){ 
    while (x < x1) plot(s, c, x, y), x++;
  }
  else {
    while (y < y1) plot(s, c, x, y), y++;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  float slope = (float)(y1 - y0) / (float)(x1 - x0);
  printf("slope = %f\n", slope);
  int octant = calcOctant(slope);
  printf("octant = %d\n", octant);
  if (x0 > x1){ //accounts for octants 3-6, flips endpoints
    int tempX, tempY;
    tempX = x1, x1 = x0, x0 = tempX;
    tempY = y1, y1 = y0, y0 = tempY;
  }
  printf("(x0, y0) = (%d, %d), (x1, y1) = (%d, %d)\n", x0, y0, x1, y1);
  if (octant == 0) draw_else(x0, y0, x1, y1, s, c);
  if (octant == 1) draw_octant1(x0, y0, x1, y1, s, c);
  if (octant == 2) draw_octant2(x0, y0, x1, y1, s, c);
  if (octant == 7) draw_octant7(x0, y0, x1, y1, s, c);
  if (octant == 8) draw_octant8(x0, y0, x1, y1, s, c);
}
