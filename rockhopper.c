#include <stdio.h>
#include <stdlib.h>

#define BUFFER


int clear_comments(char *buffer, long fsize)
{
  /* 
    Read the input buffer, and clear out comments

    Except within a character constant, a string literal, or a comment, the characters /*
    introduce a comment. The contents of such a comment are examined only to identify
    multibyte characters and to find the characters *_/ that terminate it.71)

    2 Except within a character constant, a string literal, or a comment, the characters //
    introduce a comment that includes all multibyte characters up to, but not including, the
    next new-line character. The contents of such a comment are examined only to identify
    multibyte characters and to find the terminating new-line character

  */
  char in_comment_dbs = 0;
  char in_comment_ss = 0;
  char in_string_sq = 0;
  char in_string_dq = 0;

  for (long i; i < fsize; i++){
    if (in_string_sq){
      if (buffer[i] == '\''){
        in_string_sq = 0;
        // copy it
      }
      else {
        // copy it
      }

    }
    else if (in_comment_dbs){
      if (buffer[i] == '\n'){
        in_comment_dbs = 0;
        // copy the new line
      }
      else {
        ;
      }
    }
    else if (in_comment_ss){
      if (buffer[i] == '*' && i < fsize && buffer[i+1] == '/'){
        in_comment_ss = 0;
        // add a new line
      }
    }
    else {
      if (buffer[i] == '/' && i < fsize && buffer[i+1] == '/'){
        in_comment_dbs = 1;
      }
      else if (buffer[i] == '/' && i < fsize && buffer[i+1] == '*'){
        in_comment_ss = 1;
      }
      else {
      // copy it
      }
    }
  }
  return 0;
}

int scanner()
{
  char *read_buffer = NULL;
  FILE *fp;

  fp = fopen("./test/testfile.c", "r");
  if (fp){

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  read_buffer = malloc(fsize + 1);
  if (read_buffer == 0){
    return 1
  }
  fread(read_buffer, 1, fsize, fp);
  
  fclose(fp);

  printf("%s", read_buffer);

  // TODO: complete 'clear_comments'
  // int clear_comments(char *buffer, long fsize)
  free(read_buffer);

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
