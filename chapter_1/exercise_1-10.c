#include <stdio.h>
int main(){
  int inp_cha;
  while((inp_cha=getchar()) != EOF){
    if(inp_cha == ' ') printf("\\b");
    else if(inp_cha == '\t') printf("\\t");
    else if(inp_cha == '\\') printf("\\\\"); // one backslash = //, two = ////
    else putchar(inp_cha);
  }
  return 0;
}
