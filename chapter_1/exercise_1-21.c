#include <stdio.h>
#define TABINC 8

int main(){
  int cur_cha, bla_cou, pos, tab_cou;

  nb = nt = 0;
  for(pos = 1; (cur_char=getchar())!=EOF; ++pos){
    if(cur_cha == ' '){
      if(pos % TABINC != 0) // we aren't at tab stop
	++bla_cou;
      else{  // we hit a tab stop
	bla_cou = 0;
	++tab_cou;
      }
    } else {  // printing output
      for ( ; tab_cou > 0; --tab_cou)
	putchar('\t');
      for ( ; bla_cou > 0; --bla_cou)
	putchar(' ');
      putchar(c);
      if(inp_char == '\n') // updating column counter
	pos=0;
      else if(c == '\t') // where tab take us?
	pos = pos + (TABINC - (pos-1) % TABINC) - 1;
    }
  }
  return 0;
}
      
	
      
