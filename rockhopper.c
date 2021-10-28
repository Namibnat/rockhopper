/* The rockhopper thingi, hoping to be a compiler one day */

#include "rockhopper.h"


void skip_to_new_line(char** buffer, size_t* i)
{
  size_t increment = 1;
  *i = *i + (2 * increment);
  while (*(*buffer + *i) != '\n' && *(*buffer + *i) != '\0'){
    *i = *i + increment;
  }
}


void skip_to_end_slash_star(char** buffer, size_t* i)
{
  size_t increment = 1;
  *i = *i + (2 * increment);
  if  (*(*buffer + *i) != '\0' && *(*buffer + *i + increment) != '\0'){
      while (*(*buffer + *i) != '*' && *(*buffer + *i + increment) != '/'){
        *i = *i + increment;
      }
  }
}


bool is_slash_slash(char** buffer, size_t* i)
{
  size_t increment = 1;
  if (*(*buffer + *i) == '\0') return false;
  if (*(*buffer + *i) == '/' && (*(*buffer + *i + increment) == '/')){
    return true;
  }
  return false;
}


bool is_slash_star(char** buffer, size_t* i)
{
  size_t increment = 1;
  if (*(*buffer + *i) == '\0') return false;
  if (*(*buffer + *i) == '/' && (*(*buffer + *i + increment) == '*')) {
    return true;
  }
  return false;
}


void clear_comments(char** buffer, size_t* fsize)
{
  /* 
    Read the input buffer, and clear out comments
  */
 size_t i = 0;

 while (strlen(*buffer)){
  printf("i is %zu\n", i);
  if (is_slash_slash(buffer, &i)) skip_to_new_line(buffer, &i);
  if (is_slash_star(buffer, &i)) skip_to_end_slash_star(buffer, &i);
  if (i >= *fsize) break;
  i++;
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
    fread(*buffer, 1, *fsize, fp);
    *fsize += 1;
    *buffer[*fsize] = '\0';
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


int main(int argc, char *argv[])
{
  int success = scanner();
  if (success > 0){
    printf("Error reading input");
  }
  return 0;
}
