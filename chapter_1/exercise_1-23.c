#include <stdio.h>

void rem_com(int c);
void in_com(void);
void in_quo(int c);

int main(){
  int cur_cha;

  while((cur_cha=getchar())!=EOF)
    rem_com(cur_cha);
  return 0;
}

void rem_com(int cur_cha){
  int nex_cha;

  if(cur_cha == '/'){  // scenario 1: encounter slash
    nex_cha=getchar();

    if(nex_cha=='*')
      in_com();
    else if(nex_cha=='/'){
      putchar('/'); putchar('/');
      while(nex_cha != '\n' && nex_cha != EOF)
	;
      if(d == '\n')
	putchar('\n');
    }
    else
      putchar('/'); putchar(nex_cha);
  }
  else if(cur_cha=='\'' || cur_cha == '"')
    in_quo(cur_cha);
  else
    putchar(cur_cha);
}

void in_comment(void){
  int cur_cha, nex_cha;

  cur_cha=getchar();
  nex_cha=getchar();
  while(cur_cha!='*' || nex_cha!='/'){
    cur_cha=nex_cha;
    nex_cha=getchar();
  }
}

void in_quo(int cur_cha){
  int nex_cha;

  putchar(cur_cha);

  while((nex_cha=getchar())!= cur_cha){
    putchar(nex_cha);

    if(nex_cha=='\\'){
      nex_cha=getchar();
      putchar(nex_cha);
    }
  }
  putchar(nex_cha);
}
