#ifndef DRAW_H
#define DRAW_H

int calcOctant(float slope);
void calc_else(int x0, int y0, int x1, int y1, screen s, color c);
void calc_octant1(int x0, int y0, int x1, int y1, screen s, color c);
void calc_octant2(int x0, int y0, int x1, int y1, screen s, color c);
void calc_octant7(int x0, int y0, int x1, int y1, screen s, color c);
void calc_octant8(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line(int x0, int y0, int x1, int y1, screen s, color c);

#endif
