/*Solar Systerm App main.c */
/*Author: Ian Snyder */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "./cJSON.h"
#include "./cJSON.c"

char name[50];
char answer[50];
char planet[50];
int planet_count = -1;
typedef struct planet_s {
    char *name;
    char *description;
    struct planet_s *next;
} Planet;


void printGreeting() {
    printf("Welcome to the Solar System!\n");
    printf("There are eight planets and one dwarf planet to explore.\n");
    printf("What is your name?\n");
    scanf("%s", name );
    printf( "Hello %s, lets explore!\n", name);
}

void askRandomQuestion() {
    printf("Would you like to visit a random planet? (Y or N)\n");
    scanf("%s", answer);
}

void askWhichPlanet(Planet *node) {
    printf("Which planet would you like to visit? (Ex: Jupiter)\n");
    scanf("%s", planet);
    Planet *head = node;
    for (int i = 0; i < planet_count; i++) {
        if (strcmp(planet, node->name) == 0) {
            printf("Welcome to %s! %s\n", node->name, node->description);
            return;
        }
        node = node->next;
    }
    printf("Invalid planet, try again.\n");
    askWhichPlanet(head);


}

void randomPlanet(Planet *node) {
    int random_num = (rand() % planet_count);
    for (int i = 0; i < random_num; i++) {
        node = node->next;
    }
    printf("Welcome to %s! %s\n", node->name, node->description);
}

Planet* createPlanets(char* file)
{
    cJSON *root = cJSON_Parse(file);
    char *solar_system = cJSON_GetObjectItem(root, "name")->valuestring;
    printf("Solar system name: %s\n", solar_system);

    // create planets linked list
    cJSON *planets = cJSON_GetObjectItem(root, "planets");
    planet_count = cJSON_GetArraySize(planets);
    Planet *head = NULL;
    Planet *tail = NULL;
    for (int i = 0; i < planet_count; i++) {
        Planet *newPlanet = malloc(sizeof(Planet));

        // Get the JSON element, put into newPlanet 
        cJSON *planet = cJSON_GetArrayItem(planets, i);
        newPlanet->name = strdup(cJSON_GetObjectItem(planet, "name")->valuestring);
        newPlanet->description = strdup(cJSON_GetObjectItem(planet, "description")->valuestring);
        newPlanet->next = NULL;
        
        // make linked list
        if (head == NULL) {
            head = newPlanet;
            tail = newPlanet;
        } 
        else {
            tail->next = newPlanet;
            tail = newPlanet; 
        }     
    }
 
    // free memory
    cJSON_Delete(root);
    return head;
}


int main(int argc, char *argv[]) {

    // initialize rand number
    time_t t;
    srand((unsigned) time(&t));

    // open file
    FILE *fp = fopen("planetarySystem.json", "r");
    if (fp == NULL) {
        printf("File could not be opened");
        return -1;
    }

    // turn file into string
    char* buffer = NULL;
    size_t len;
    ssize_t bytes_read = getdelim(&buffer, &len, '\0', fp);
    if ( bytes_read == -1) {
        printf("File could not be read into buffer");
        return -1;
    }

    Planet *list = createPlanets(buffer);
    printGreeting();
    askRandomQuestion();

    for (;;) {
        if (strcmp(answer, "N") == 0) {
            printf("Name a planet to visit.\n");
            askWhichPlanet(list);
            break;
        } else if(strcmp(answer, "Y") == 0) {
            randomPlanet(list);
            break;
        } else {
            printf("Invalid response.\n");
            askRandomQuestion();
        }
    }

    return 0;
}


