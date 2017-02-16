#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_bird(screen s, color c){
  draw_line(200,440,200,140,s,c);
  draw_line(200,140,280,140,s,c);
  draw_line(280,40,280,200,s,c);
  draw_line(280,100,420,40,s,c);
  draw_line(420,40,340,260,s,c);
  draw_line(340,260,340,440,s,c);
  draw_line(340,440,380,480,s,c);
  draw_line(380,480,320,480,s,c);
  draw_line(280,40,300,0,s,c);
  draw_line(300,0,280,20,s,c);
  draw_line(280,20,260,20,s,c);
  draw_line(260,20,260,140,s,c);
  draw_line(260,40,200,20,s,c);
  draw_line(200,20,240,60,s,c);
  draw_line(240,60,240,140,s,c);
  draw_line(200,360,120,360,s,c);
  draw_line(120,360,80,320,s,c);
  draw_line(80,320,100,480,s,c);
  draw_line(100,480,180,480,s,c);

  draw_line(200,300,220,280,s,c);
  draw_line(220,280,240,300,s,c);
  draw_line(240,300,260,280,s,c);
  draw_line(260,280,280,300,s,c);
  draw_line(280,300,300,280,s,c);
  draw_line(300,280,320,300,s,c);
  draw_line(320,300,340,280,s,c);

  draw_line(180,480,180,460,s,c);
  draw_line(180,460,200,440,s,c);
  draw_line(200,440,220,440,s,c);
  draw_line(220,440,240,460,s,c);
  draw_line(240,460,240,480,s,c);
  draw_line(240,480,220,499,s,c);
  draw_line(220,499,200,499,s,c);
  draw_line(200,499,180,480,s,c);
  draw_line(240,480,260,480,s,c);
  draw_line(260,480,260,460,s,c);
  draw_line(260,460,280,440,s,c);
  draw_line(280,440,300,440,s,c);
  draw_line(300,440,320,460,s,c);
  draw_line(320,460,320,480,s,c);
  draw_line(320,480,300,499,s,c);
  draw_line(300,499,280,499,s,c);
  draw_line(280,499,260,480,s,c);
 
 int xL, xR;
  for (xL = 200; xL <= 220; xL++)
    draw_line(xL,480,xL,460,s,c);
  for (xR = 280; xR <= 300; xR ++)
    draw_line(xR,480,xR,460,s,c);
}

int main() {

  screen s;
  color c;
   
  c.red = 52;
  c.green = 152;
  c.blue = 219;
  
  clear_screen(s);

  draw_bird(s,c);
  
  display(s);
  save_extension(s, "lines.png");
}  
