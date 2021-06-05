/*Solar Systerm App main.c */
/*Author: Ian Snyder */
#include <stdio.h>
#include <string.h>

void printGreeting() {
    printf("Welcome to the Solar System!\n");
    printf("There are eight planets and one dwarf planet to explore.\n");
}

int main(int argc, char *argv[]) {
    char name[100];
    char answer[100];

    printGreeting();
    // printf("Welcome to the Solar System!\n");
    // printf("There are eight planets and one dwarf planet to explore.\n");
    printf("What is your name?\n");
    scanf("%s", name );
    printf( "Hello %s, lets explore!\n", name);
    printf("Would you like to visit a random planet? (Y or N)\n");
    scanf("%s", answer);
    if (strcmp(answer, "N") == 0) {
        printf("Name a planet to visit.\n");
    } else {
        printf("Saturn is a dope planet with rings.\n");
    }
    return 0;
}


