/*Solar Systerm App main.c */
/*Author: Ian Snyder */
#include <stdio.h>

char str[100];

int main(int argc, char *argv[]) {
   printf("Welcome to the Solar System!\n");
   printf("There are eight planets and one dwarf planet to explore.\n");
   printf("What is your name?\n");
   scanf("%s", str );
   printf( "Hello %s\n", str);
   return 0;
}


