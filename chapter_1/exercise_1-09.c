#include <stdio.h>
#define NONEBLANK 'a'

int main(){
  int inp_cha, pre_cha;

  pre_cha = NONEBLANK;
  while((inp_cha = getchar()) != EOF){
    if(inp_cha != ' ') putchar(inp_cha);
    if(inp_cha == ' ')
      if(pre_cha != ' ') putchar(inp_cha);
    pre_cha = inp_cha;
  }
  return 0;
}
