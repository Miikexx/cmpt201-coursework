#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Enter your command:\n> ");
  char *buff = NULL;
  size_t size = 0;

  // getline() -> does buffer allocation (must be freed)
  if (getline(&buff, &size, stdin) != -1L) {

    // tokenize string:
    char *input_str = buff;
    char *delim = " \t\n\r";
    char *token = NULL;
    char *saveptr = NULL;

    // input_string must have real string on first call, but be NULL later.
    // saveptr: Null at first and set later
    while ((token = strtok_r(input_str, delim, &saveptr))) {
      printf("Token: '%s'\n", token);
      input_str = NULL;
    }
  } else {
    printf("Getline failure.\n");
  }
  free(buff);
}
