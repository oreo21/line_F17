#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int calcOctant(float slope){
  if (slope == 0) return 0;
  else if (slope > 0 && slope <= 1) return 1;
  else if (slope > 1) return 2;
  else if (slope < 0 && slope >= -1) return 8;
  else if (slope < -1) return 7;
  return -1;
}

void draw_horizontal(int x0, int y0, int x1, int y1, screen s, color c) {


}

void draw_octant1(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = 2 * A + B;
  int x = x0, y = y0;
  while (x <= x1){
    plot(s, c, x, y);
    if (d > 0) y++, d += 2 * B;
    x++, d += 2 * A;
}

void draw_octant2(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = A + 2 * B;
  int x = x0, y = y0;
  while (y <= y1){
    plot(s, c, x, y);
    if (d < 0) x++, d += 2 * A;
    y++, d += 2 * B;
}

void draw_octant7(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = A - 2 * B;
  int x = x0, y = y0;
  while (y >= y1){
    plot(s, c, x, y);
    if (d > 0) x++, d += 2 * A;
    y--, d -= 2 * B;
}

void draw_octant8(int x0, int y0, int x1, int y1, screen s, color c) {
  int A = y1 - y0, B = x0 - x1, d = 2 * A - B;
  int x = x0, y = y0;
  while (x <= x1){
    plot(s, c, x, y);
    if (d < 0) y--, d -= 2 * B;
    x++, d += 2 * A;
}

void draw_vertical(int x0, int y0, int x1, int y1, screen s, color c) { 

}


//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  float slope = (y1 - y0)/(x1 - x0);
  int octant = calcOctant(slope);
  if (octant == 0) draw_horizontal(x0, y0, x1, y1, s, c);
  if (octant == 1) draw_octant1(x0, y0, x1, y1, s, c);
  if (octant == 2) draw_octant2(x0, y0, x1, y1, s, c);
  if (octant == 7) draw_octant7(x0, y0, x1, y1, s, c);
  if (octant == 8) draw_octant8(x0, y0, x1, y1, s, c);
  if (octant == -1) draw_vertical(x0, y0, x1, y1, s, c);
  while(x <= x1) {
    plot(s, c, x, y);
    if(d > 0) {
      y++;
      d += 2 * B;
    }
    x++;
    d += 2 * A;
  }
}
