#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void skip_to_new_line(char** buffer, size_t* i)
{
  size_t increment = 1;
  while (*(*buffer + *i) != '\n' && *(*buffer + *i) != '\0')
  *i = *i + increment;
}

bool is_slash_slash(char** buffer, size_t i)
{
  if (*(*buffer + i + 1) == '\0') return false;
  if (*(*buffer + i) == '/' && (*(*buffer + i + 1) == '/')) return true;
  return false;
}

void clear_comments(char** buffer, size_t* fsize)
{
  /* 
    Read the input buffer, and clear out comments
  */
 bool in_slash_slash = false;
 bool in_slash_star = false;
 bool in_dbl_quote_str = false;
 bool in_sgl_quote_str = false;

 for (size_t i = 0; i < *fsize; i++){
  if (is_slash_slash(buffer, i))
    skip_to_new_line(buffer, &i);
  if (i == *fsize) break;
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
