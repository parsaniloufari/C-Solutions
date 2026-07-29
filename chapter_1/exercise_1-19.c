#include <stdio.h>
#include <string.h>
#define LINELIMIT 1000

int my_getline(char input_line[], int line_limit)
{
  int index, input_char;
  for(index = 0; index<line_limit-1 && (input_char=getchar())!=EOF && input_char!='\n'; index++)
    input_line[index] = input_char;
  if(input_char == '\n'){
    input_line[index] = '\n';
    index++;
  }
  input_line[index] = '\0';
  return index;
}

char *my_reverse(char *input_line)
{
  int i, j;
  char tmp;
  for(i=0, j=strlen(input_line)-1; i<j; i++, j--){
    tmp = input_line[i];
    input_line[i] = input_line[j];
    input_line[j] = tmp;
  }
  return input_line;
}

int main()
{
  char input_line[LINELIMIT];
  int input_line_length;

  while((input_line_length=my_getline(input_line, LINELIMIT)) > 0)
    printf("%s", my_reverse(input_line));
  return 0;
}
