#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  ASSERT_STREQ("", disemvowel((char*) ""));
}

TEST(Disemvowel, HandleNoVowels) {
  char *str;
  int size;


  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  char *clearleak = disemvowel(str);
  str[0] = 'p';
  str[1] = 'q';
  str[2] = 'r';
  str[3] = 's';
  str[4] = 't';
  str[size-1] = '\0';
  ASSERT_STREQ("pqrst", clearleak);

  free(clearleak);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char *str;
  int size;


  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  char *clearleak = disemvowel(str);
  str[0] = 'a';
  str[1] = 'e';
  str[2] = 'i';
  str[3] = 'o';
  str[4] = 'u';
  str[5] = 'A';
  str[6] = 'E';
  str[7] = 'I';
  str[8] = 'O';
  str[9] = 'U';
  str[10] = 'A';
  str[11] = 'u';
  str[12] = 'o';
  str[13] = 'i';
  str[14] = 'e';
  str[15] = 'a';
  str[size-1] = '\0';
  ASSERT_STREQ("", clearleak);

  free(clearleak);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char *str;
  int size;


  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  char *clearleak = disemvowel(str);
  str[0] = 'M';
  str[1] = 'o';
  str[2] = 'r';
  str[3] = 'r';
  str[4] = 'i';
  str[5] = 's';
  str[6] = ',';
  str[7] = 'M';
  str[8] = 'i';
  str[9] = 'n';
  str[10] = 'n';
  str[11] = 's';
  str[12] = 'o';
  str[13] = 't';
  str[14] = 'a';
  str[size-1] = '\0';


  ASSERT_STREQ("Mrrs, Mnnst",
		      clearleak);

  free(clearleak);
}

TEST(Disemvowel, HandlePunctuation) {
  char *str;
  int size;


  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  char *clearleak = disemvowel(str);
  str[0] = 'A';
  str[1] = 'n';
  str[2] = '(';
  str[3] = 'U';
  str[4] = 'n';
  str[5] = 'e';
  str[6] = 'x';
  str[7] = 'p';
  str[8] = 'l';
  str[9] = 'i';
  str[10] = 'n';
  str[11] = 'e';
  str[12] = 'd';
  str[13] = ')';
  str[14] = 'E';
  str[15] = 'l';
  str[16] = 'e';
  str[17] = 'p';
  str[18] = 'h';
  str[19] = 'a';
  str[20] = 'n';
  str[21] = 't';
  str[size-1] = '\0';
  ASSERT_STREQ("n (nxplnd) lphnt!",
		      clearleak);
    free(clearleak);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;


  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  char *clearleak = disemvowel(str);
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  ASSERT_STREQ("xyz", clearleak);

  free(clearleak);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
