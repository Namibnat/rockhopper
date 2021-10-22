#include <stdio.h>


void scanner()
{
  char *tokens[200];
  FILE *fp;
  fp = fopen("./test/testfile.c", "r");
  fclose(fp);

}

int main()
{
  scanner();
  
  return 0;
}
