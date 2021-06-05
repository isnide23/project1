/*Solar Systerm App main.c */
/*Author: Ian Snyder */
#include <stdio.h>
#include <string.h>

char name[100];
char answer[100];

void printGreeting() {
    printf("Welcome to the Solar System!\n");
    printf("There are eight planets and one dwarf planet to explore.\n");
    printf("What is your name?\n");
    scanf("%s", name );
    printf( "Hello %s, lets explore!\n", name);
}

void askQuestion() {
    printf("Would you like to visit a random planet? (Y or N)\n");
    scanf("%s", answer);
}


int main(int argc, char *argv[]) {


    printGreeting();
    askQuestion();

    
    if (strcmp(answer, "N") == 0) {
        printf("Name a planet to visit.\n");
        askQuestion();
    } else if(strcmp(answer, "Y") == 0) {
        printf("Saturn is a dope planet with rings.\n");
    } else {
        printf("Invalid response.\n");
    }
    return 0;
}


