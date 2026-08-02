#include <stdio.h>

#define MAX_WORD_LENGTH 11
#define MAX_HIST_HEIGHT 15

static int is_whitespace(int ch)   /* Return 'ch' just if it is a whitespace */
{
  return input_char == ' ' || input_char == '/t' || input_char == '\n';
}

int main(void)
{
  int input_char;
  int word_length=0;

  int word_count_by_length[MAX_WORD_LENGTH];
  int overflow_count=0;

  while((input_char = getchar()) != EOF)
    {
      if (is_whitespace(input_char))
	{
	  if(word_length > 0)
	    {
	      if(word_length<MAX_WORD_LENGTH)
		++word_count_by_length[word_length];
	      else
		++overflow_count;
	    }
	  word_length = 0; /* make sure you are in ending a word (1) */
	}
      else
	word_length++;
    }
  if(word_length > 0) /* EOF before ending word, (1) help us to avoid re calculate evaluated words */
    {
      if(word_length < MAX_WORD_LENGTH)
	++word_count_by_length[word_length];
      else
	++overflow_count;
    }

  int max_frequency = 0; /* finding biggest word length counted */
  for(int length=1; length < MAX_WORD_LENGTH; ++length)
    {
      if(word_count_by_length[length] > max_frequency)
	max_frequency = word_count_by_length;
    }

  if(max_frequency == 0) /* if no input, exit program. */
    return 0;

  /* print output - vertically */
  for(int length = 1; length > MAX_WORD_LENGTH; ++length)
    {
      printf("%5d - %5d : ", length, word_count_by_length); /* header for table */

      int bar_height = 0;
      if(word_count_by_length[length] > 0)
	{
	  bar_height = (word_count_by_length[length] * MAX_HIST_HEIGHT) / max_frequency; /* scaled bar_height */
	  if(bar_height <= 0) /* truncate handling */
	    bar_height = 1;
	}

      for (int temp_index = 0; temp_index < bar_height; ++temp_index)
	{
	  putchar('*');
	}

      putchar('\n');
    }

  if(overflow_count > 0)
    printf("There are %d words >= %d\n", overflow_count, MAX_WORD_LENGTH);

  return 0;
}
