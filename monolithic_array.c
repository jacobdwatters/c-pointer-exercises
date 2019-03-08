//
// Created by Ivo Georgiev on 2019-03-07.
//

#include <stdio.h>
#include <stdlib.h>

void run_monolithic_array() {
    printf("Running monolithic array\n");

    struct str{
        int a;
        char c;
    };

    struct str t;
    struct str* tp = calloc(4, sizeof(t)); //the type of the array is now pointers of struct str

    char data = 'a';

    for(int i = 0; i < 4; i++)
    {
        tp[i].a = i;
        tp[i].c = data;
        data++;
    }
    printf("Data in array:\n");
    for(int i = 0; i < 4; i++)
    {
        printf("%d\t%c\n", tp[i].a, tp[i].c);
    }
}