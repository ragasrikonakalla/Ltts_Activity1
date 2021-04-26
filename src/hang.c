#include <stdio.h>
#include <ctype.h>
#include "hang.h"

void displayDictionary(char dict[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", dict[i]);
    }
}

int getRandom(int n) {
    static bool flag = true;
    if (flag) {
        srand(time(NULL));
        flag = false;
    }
    return rand() % n;
}

void clrscr(void) {
    printf("\033[2J");
    printf("\033[0;0f");
}

char (*loadDict(int *n))[50] {
    
     long wordsCount = 20;
    FILE *fp =  fopen("verySmallDictionary.txt", "r");

    // DO NOT DISTURB BELOW CODE.
    if (!fp) {
        *n = -1;
        return NULL;
    }
    char (*dict)[50] = (char(*)[50])malloc(wordsCount * 50);
    if (!dict) {
        *n = -2;
        return NULL;
    }
    int i = 0;
    while (fgets(dict[i], 50, fp) != NULL) {
        dict[i][strlen(dict[i]) - 1] = '\0';
        i++;
    }
    fclose(fp);
    *n = i;
    return dict;
}
