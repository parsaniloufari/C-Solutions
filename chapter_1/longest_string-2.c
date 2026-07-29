#include <stdio.h>

#define MAXLINE 1000

int max_len;
char inp_line[MAXLINE], long_line[MAXLINE];

int my_getline(void);
void my_copy(void);

int main()
{
  int curr_len;

  max_len = 0;
  while((curr_len=my_getline()) > 0){
    if(curr_len > max_len){
      max_len = curr_len;
      my_copy();
    }
  }

  if(max_len>0)
    printf("%s", long_line);

  return 0;
}

int my_getline(void)
{
  int ind, inp_char;

  for(ind=0; ind<MAXLINE-1 &&
	(inp_char=getchar())!=EOF &&
	inp_char!='\n'; ind++)
    inp_line[ind]=inp_char;

  if(inp_char=='\n')
    ind++;

  inp_line[ind]='\0';
  return ind;
}

void my_copy(void)
{
  int ind;

  for(ind=0; inp_line[ind]!='\0'; ind++)
    long_line[ind]=inp_line[ind];
  long_line[ind]='\0';
}
    
