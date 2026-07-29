/*    Tab expansion – tabs become spaces.
Line width control – no line is longer than MAXCOL.
Word‑boundary wrapping – lines break only at blanks, never in the middle of a word.
Buffered output – the remainder of the line after a wrap is kept for the next output.*/



#include <stdio.h>

#define MAXCOL 20
#define TABINC 8

char line[MAXCOL];  // buffer of current line

int my_exptab(int pos);
int my_findblnk(int pos); // finding last blank
int my_newpos(int pos);
void my_printl(int pos); // print untill last blank

int main(){
  int cur_cha, pos;

  pos=0;
  while((cur_cha=getchar())!=EOF){
    line[pos]=cur_cha;
    if(cur_char=='\t')
      pos=my_exptab(pos);
    else if(cur_char=='\n'){
      my_printl(pos);
      pos=0;
    } else if(++pos >= MAXCOL){ // if we hit the limit
      pos = my_findblnk(pos);
      my_printl(pos);
      pos = my_newpos(pos);
    }
  }
  return 0;
}

int my_exptab(int pos){
  line[pos]=' ';  // each tab have at least one blank
  for(++pos; pos < MAXCOL &&
	(pos % TABINC) != 0; ++pos)
    line[pos]=' ';
  if(pos < MAXCOL)
    return pos;
  else{
    my_printl(pos);
    return 0;
  }
}

int my_findblnk(int pos){
  while(pos > 0 && line[pos] != ' ')
    --pos;
  if(pos == 0)
    return MAXCOL;
  else
    return pos+1;
}

int newpos(int pos){
  int i, j;

  if(pos <= 0 || pos >= MAXCOL)
    return 0;
  else{
    i=0;
    for(j=pos; j<MAXCOL; ++j){
      line[i]=line[j];
      ++i;
    }
    return i;
  }
}

void printl(int pos){
  int i;

  for (i=0; i<pos; ++i)
    putchar(line[i]);
  if(pos>0)
    putchar('\n');
}
