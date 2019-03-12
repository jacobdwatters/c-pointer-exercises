//
// Created by Ivo Georgiev on 2019-03-07.
//

#include <stdio.h>
#include <stdlib.h>

struct str{
    int a;
    char c;
};

void run_array_of_pointers()
{
    printf("Running array of pointers\n");

    struct str w1, w2, w3, w4;

    struct str **arr_p = (struct str**) calloc(4, sizeof(struct str*));
    struct str arr[] = {w1, w2, w3, w4};

    char character = 'a';

    for(int i = 0; i < 4; i++)
    {
        arr_p[i] = &arr[i];
        arr_p[i]->a = i;
        arr_p[i]->c = character;
        character++;
    }

    printf("Data in array:\n");
    for(int i = 0; i < 4; i++)
    {
       printf("%d\t%c\n", arr_p[i]->a, arr_p[i]->c);
    }

    free(arr_p);
}