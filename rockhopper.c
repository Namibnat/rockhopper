#include <stdio.h>
#include <stdlib.h>

int scanner()
{
  char *buffer = NULL;
  FILE *fp;

  fp = fopen("./test/testfile.c", "r");
  if (fp){

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  buffer = malloc(fsize + 1);
  if (buffer == 0){
    return 1
  }
  fread(buffer, 1, fsize, fp);
  
  fclose(fp);

  printf("%s", buffer);
  free(buffer);
  return 0;

  }
}

int main()
{
  int success = scanner();
  if (success > 0){
    printf("Error reading input");
  }
  
  return 0;
}
