#include <stdio.h>
  
int main()
{
  int a, b;
  FILE *numb, *amount;
  numb = fopen("aplusb.in", "r");
  amount = fopen("aplusb.out", "w");
  fscanf(numb, "%d%d", &a, &b);
  fprintf(amount, "%d", a + b);
  fclose(numb);
  fclose(amount);
  return 0;
}
