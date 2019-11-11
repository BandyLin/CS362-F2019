#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int a;
    char c[33] = "abcdefghijklmnopqrstuvwxyz{[()]} ";
    // srand((unsigned)clock());
    a = rand() % 33;
    return c[a];
}

char str[6];
char *inputString()
{
    char c[26] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;    
    // srand((unsigned)clock());
    str[0] = c[rand() % 26];
    str[1] = c[rand() % 260 / 10];
    str[2] = c[rand() % 520 / 20];
    str[3] = c[rand() % 260 / 10];
    str[4] = c[rand() % 52000 / 2000];
    str[5] = '\0';
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}


