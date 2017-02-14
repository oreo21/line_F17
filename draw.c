#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  float slope = (y1 - y0)/(x1 - x0);
  int A = y1 - y0, B = x0 - x1;
  int x = x0, y = y0;
  int d = 2 * A + B;
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
