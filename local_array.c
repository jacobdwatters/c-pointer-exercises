//
// Created by Ivo Georgiev on 2019-03-07.
//

#include <stdio.h>

void run_local_array()
{
    printf("Running local array\n");

    struct str{
        int a;
        char c;
    };

    static struct str s_arr[4]; //the array is of type struct str

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