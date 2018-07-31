//
//  main.c
//  KMPPrimer
//
//  Created by Zeaho on 2018/7/31.
//  Copyright © 2018年 Zeaho. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma mark - interface
void GetNext(char substring[], int *next);

int KMPMatch(char string[], char substring[], int next[]);

#pragma mark - implementation
int main(int argc, const char * argv[]) {
    
    char string[] = "BBC ABCDAB ABCDABCDABDE";
    char substring[] = "ABCDABD";
    int next[(int)strlen(substring)];

    GetNext(substring, next);
    
    int index = KMPMatch(string, substring, next);
    
    printf("string    : %s\n", string);
    printf("substring : %s\n", substring);
    printf("index     : %d\n", index);
    
    return 0;
}

void GetNext(char substring[], int *next) {
    int i= 0;
    int j= -1;
    next[0] = -1;
    while (i < strlen(substring) - 1) {
        if (j == -1 || substring[i] == substring[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMPMatch(char string[], char substring[], int next[]) {
    int i = 0;
    int j = 0;
    while (i < strlen(string) && abs(j) < strlen(substring)) {
        if (j == -1 || string[i] == substring[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == strlen(substring)) {
        return i - j;
    } else {
        return -1;
    }
}
