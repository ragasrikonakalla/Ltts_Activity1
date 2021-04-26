/*
 ~~~~~~~~~~~~~: HANGMAN :~~~~~~~~~~~~~~~~
 ~~~~~~~~~: Word guess game :~~~~~~~~~~~~
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "hang.h"

char word[50];

int main() {
    void hang.loop1();
    printf("~~~~~~~~~~~~~~~:HANGMAN:~~~~~~~~~~~~~~~\n~~~~~~~~~~~Word guess game~~~~~~~~~~~\n");
    int n;
    char (*dict)[50] = loadDict(&n);
    // After function call 'loadDict', it updates number of
    // words in 'n' and returns a pointer to a two dimensional
    // array ie 'dict'. Every row of 'dict' contains a word
    // loaded from the dictionary. Therefore dict[0] holds first
    // word from the dictionary, dict[1] holds second and so on
    // upto n - 1.
    if (dict == NULL) {
        printf("Memory error: Insufficient RAM.\n");
        printf("Sorry, unable to load dictionary.\n");
        printf("Quitting :(\n");
        exit(1);
    }

   // displayDictionary(dict, n);
    printf("------------------\n");
    // Getting a random word below
    char word[50];
    char temp[50];
    int i;
    char enteredAlphabets[29] = "[abcdefghijklmnopqrstuvwxyz]";
    char alphabet;
    char copy[50];
    int chances = 7;
    int flag;
    strcpy(word, dict[getRandom(n)]);
    // printf("%s\n", word);
    for ( i = 0; i < strlen( word); i++) {
        temp[i] = '-';
    }
    temp[i] = '\0';
      
    while (1) {
    printf("GUESS:%s\n", temp);
    printf("YOU GOT %d CHANCES", chances);  
    printf("\n%s", enteredAlphabets);
    strcpy(copy, temp);
    printf("\n>");
    scanf(" %c", &alphabet);
    for (i = 0;enteredAlphabets[i] != '\0'; i++) {
        if (enteredAlphabets[i] == alphabet) {
            enteredAlphabets[i] = '-';
            flag = 1;
            break;
        }
        flag = 0;
    }
    if (flag == 0) {
        printf("Already guessed : %c\n", alphabet);
        continue;
    }
    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] == alphabet) {
           temp[i] = alphabet;
        }
    }

    if (strcmp(temp, word) == 0) {
        printf("> %s \n :)YOU WON... \n", word);
        break;
    } 
    if (!(strcmp(copy, temp))) {
        chances--;
        if ( chances == 0 ) {
            printf(" :( YOU LOST... \n> %s \n ", word);
            break;
        }
    }
}
    return 0;
}
   


