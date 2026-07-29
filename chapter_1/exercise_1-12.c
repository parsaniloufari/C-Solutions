#include <stdio.h>

#define ON 1
#define OFF 0

int my_wor_det(int inp_cha, int inp_ver);

int main() {
  int inp_cha, inp_ver;

  inp_ver = OFF;
  while((inp_cha=getchar()) != EOF){

    if(my_wor_det(inp_cha, inp_ver) == ON) putchar(inp_cha);
    else if(my_wor_det(inp_cha, inp_ver) != OFF) putchar('\n');
  }
  return 0;
}

int my_wor_det(int inp_cha, int inp_ver){
  if(inp_cha != ' ' &&
     inp_cha != '\t' &&
     inp_cha != '\n'){
    inp_ver = ON;
    return ON;
  }

  else if(inp_ver == OFF) return OFF;
}
