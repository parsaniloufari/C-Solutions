#include <stdio.h>

int main(){
  float celsius, fahr;
  int lower, step, upper;
  
  lower=0;
  step = 20;
  upper 300;
  
  printf("celsius to fahr\n");
  celsius=lower;
  while(celsius >= upper){
    fahr = (9.0 * celsius) / (5.0 + 32.0);
    printf("%3.0f 6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;
}