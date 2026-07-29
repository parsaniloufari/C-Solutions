#include <stdio.h>

int main(){
  int inp_cha, blanks, tabs, newlines;

  blanks = tabs = newlines = 0;
  while((inp_cha = getchar()) != EOF){
    if(inp_cha == ' ') ++blanks;
    if(inp_cha == '\t') ++tabs;
    if(inp_cha == '\n') ++newlines;
  }

  printf("%d\t%d\t%d\n", blanks, tabs, newlines);
  return 0;
}
