#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
  int array_index, temp_index, state,
    max_length, word_length_count, input_char;

  state = OUT;
  for(array_index=0; array_index<30; ++array_index)
    word_length_count[array_index]=0;
  array_index=0;

  while(((input_char=getchar()) != EOF) && array_index < 30){
    if(input_char != ' ' && input_char != '\t' && input_char != '\n'){
      state=IN;
      ++word_length_count[array_index];
    }
    else
      if(state=IN){
	state=OUT;
	++array_index;
      }
  }

  temp_index=array_index;
  max=0;
  for(array_index=0; array_index <= temp_index; ++array_index){
    if(word_length_count[array_index] > max)
      max=word_length_count[array_index];
  }

  while(max != 0){
    for(array_index=0; array_index <= temp_array; ++array_index){
      if(word_length_count[array_index] > max)   putchar(' ');
      else   putchar('*');
      if(array_index == temp_index)   putchar('\n');
    }
    --max;
  }
  return 0;
}
