#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int len, i, j;
  char *result;


  len = strlen(str);
  result = (char*) calloc(len+1, sizeof(char));

  for(i = 0; i < len; i++){
      if(str[i] != 'a' && str[i] != 'i' && str[i] != 'u' && str[i] != 'e'&& str[i] != 'o'&& \
          str[i] != 'A' && str[i] != 'I' && str[i] != 'U' && str[i] != 'E'&& str[i] != 'O'){
            result[j] = str[i];
            j++;
          }

  }

  return result;
}
