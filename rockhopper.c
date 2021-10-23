#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int clear_comments(char **buffer, long fsize)
{
  /* 
    Read the input buffer, and clear out comments
  */
 for (long i = 0; i < 4; i++){
  printf("%c\n", *buffer[i]);
 }
  return fsize;
}

long read_the_file(char **buffer)
{
  FILE *fp;
  long fsize = 0;

  fp = fopen("./test/testfile.c", "r");
  if (fp){
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *buffer = realloc(*buffer, fsize + 1);
    if (fsize == 0){
      return 1;
    }
    fread(*buffer, 1, fsize, fp);
    fclose(fp);
  }
  return fsize;
}

int scanner()
{
  char *buffer = NULL;
  long fsize = read_the_file(&buffer);
  fsize = clear_comments(&buffer, fsize);

  printf("%s", buffer);
  free(buffer);

  return 0;
}

int main()
{
  int success = scanner();
  if (success > 0){
    printf("Error reading input");
  }
  return 0;
}
