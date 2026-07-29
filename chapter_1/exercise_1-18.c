#include <stdio.h>
#define LINELIMIT 1000

int my_getline(char input_line[], int line_limit);

int main()
{
  int line_length;
  char input_line[LINELIMIT];
  while((line_length=my_getline(input_line, LINELIMIT)) > 0)
    printf("%s", input_line);
  return 0;
}

int my_getline(char input_line[], int line_limit)
{
  int index, input_char;
  for(index = 0; index<line_limit-1 && (input_char=getchar())!=EOF && input_char!='\n'; index++){
    int blank_index, tab_index;
    blank_index = tab_index = 0;

    if(input_char == ' '){blank_index++;}
    if(input_char == '\t'){tab_index++;}
    if(input_char!=' ' && blank_index>1){blank_index=0;}
    if(input_char!='\t' && tab_index>1){tab_index=0;}

    if(input_char!=' ' && input_char!='\t')
      input_line[index]=input_char;
    if(input_char==' ' && blank_index<=1)
      input_line[index]=input_char;
    if(input_char=='\t' && tab_index<=1)
      input_line[index]=input_char;
  }
  if(input_char=='\n'){
    input_line[index]='\n';
    index++;
  }
  input_line[index]='\0';
  return index;
}
