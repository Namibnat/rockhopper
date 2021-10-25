#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void clear_comments(char** buffer, size_t* fsize)
{
  /* 
    Read the input buffer, and clear out comments
  */
 for (size_t i = 0; i < *fsize; i++){
    printf("%c\n", *(*buffer + i));
 }

}

void read_the_file(char** buffer, size_t* fsize)
{
  FILE *fp;

  fp = fopen("./test/testfile.c", "r");
  if (fp){
    fseek(fp, 0, SEEK_END);
    *fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    *buffer = realloc(*buffer, *fsize + 1);
    *buffer[*fsize] = '\0';
    *fsize += 1;

    fread(*buffer, 1, *fsize, fp);
    printf("%s\n", *buffer);
    fclose(fp);
  }
}

int scanner()
{
  char *buffer = NULL;
  size_t fsize = 0;
  read_the_file(&buffer, &fsize);
  if (fsize == 0) return 1;
  clear_comments(&buffer, &fsize);
  if (fsize == 0) return 2;

  // printf("%s", buffer);
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
