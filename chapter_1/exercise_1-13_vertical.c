#include <stdio.h>

#define MAX_WORD_LENGTH 100

int main(void)
{
  int counts[MAX_WORD_LENGTH+1] = {0};
  int input_char, length, max_frequency = 0;

  while((input_char = getchar()) != EOF)
    {
      if(input_char == ' ' || input_char == '\t'
	 || input_char == '\n')
	{
	  if(len>0)
	    {
	      if(len>MAX_WORD_LENGTH)
		len = MAX_WORD_LENGTH;
	      counts[len]++;
	      if(counts[len] > max_frequency)
		max_frequency = counts[len];
	      len = 0;
	    }
	} else {
	++len;
	if(len > MAX_WORD_LENGTH)
	  len = MAX_WORD_LENGTH;
      }
    }

  if(len > 0)
    {
      counts[len]++;
      if(counts[len] > max_frequency)
	max_frequency = counts[len];
    }

  for(int row = max_frequency; row > 0; --row)
    {
      for(int word = 1; word <= MAX_WORD_LENGTH; ++word)
	{
	  putchar(counts[w] >= row ? '*' : ' ');
	}
      putchar('\n');
    }

  for(int word = 1; word <= MAX_WORD_LENGTH; ++word)
    {
      putchar('-');
    }
  putchar('\n');

  return 0;
}
