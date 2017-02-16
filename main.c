#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);
  
  /*draw_line(250,250,350,450,s,c);
  draw_line(250,250,450,350,s,c);
  draw_line(250,250,150,50,s,c);
  draw_line(250,250,50,150,s,c);
  draw_line(250,250,350,50,s,c);
  draw_line(250,250,450,150,s,c);
  draw_line(250,250,150,450,s,c);
  draw_line(250,250,50,350,s,c);
  draw_line(250,250,250,350,s,c);
  draw_line(250,250,350,250,s,c);
  draw_line(250,250,350,350,s,c);
  draw_line(250,250,150,350,s,c);*/
  
  display(s);
  save_extension(s, "lines.png");
}  
