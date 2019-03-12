//
// Created by Ivo Georgiev on 2019-03-07.
//

#include <stdio.h>

struct str{
    int a;
    char c;
};

static struct str s_arr[4]; //The array is of type struct str

void run_global_array()
{
    printf("Running global array\n");

    char character = 'a';

    for(int i = 0; i <  sizeof(s_arr) / sizeof(s_arr[0]); i++)
    {
        s_arr[i].a = i;
        s_arr[i].c = character;
        character++;
    }

    printf("Data in array:\n");
    for(int i = 0; i <  sizeof(s_arr) / sizeof(s_arr[0]); i++)
    {
        printf("%d\t%c\n", s_arr[i].a, s_arr[i].c);
    }
}



