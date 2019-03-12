//
// Created by Ivo Georgiev on 2019-03-07.
//

/* Cases for insertion
 *   1) List is empty: insert at head
 *   2) data being inserted is smaller than data in head: Make data the new head
 *   3) data being inserted is larger than data in tail: Make data the new tail
 *   4) data being inserted is already in list: insert in front of original
 *   5) data being inserted does not match any of these: Find place where previous nodes data is smaller
 *                                                    and next nodes data is larger, insert here.
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head    = NULL;
struct node *tail    = NULL;
struct node *current = NULL;

void list_insert(int data)
{
    current = head;

    if(head == NULL) //case 1
    {
        head = (struct node*) malloc(sizeof(struct node));
        head->next = 0;
        head->data = data;
        tail = head;
    }
    else
    {
        if (data >= tail->data) //case 2
        {
            tail->next = (struct node*) malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = data;
            tail->next = 0;
        }
        else if (data < head->data)//case 3
        {
            struct node *temp = head;
            head = (struct node*) malloc(sizeof(struct node));
            head->data = data;
            head->next = temp;
        }
        else //cases 4 and 5
        {
            //struct node* tempNext = current->next;

            while (data >= current->next->data)
            {
                current = current->next;
            }

            struct node *temp = current->next;

            current->next   = (struct node*) malloc(sizeof(struct node));
            current         = current->next;
            current->data   = data;
            current->next   = temp;
        }


    }
}

void printList()
{
    current = head;

    printf("data in list:\n");
    while(current != NULL)
    {
        printf("%d\n",current->data);
        current =  current->next;
    }
}

void freeList()
{
    current = head;
    while(current != NULL)
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        current = head;
    }
}

void run_linked_list()
{
    int rand_max = 100;
    printf("Running linked list\n");

    /*
    list_insert(67);            //test for case 1
    for(int i = 0; i < 4; i++)  //test for case 2
    {
        list_insert(i);
    }
    for(int i = 3; i >= 0; i--) //test for case 3
    {
        list_insert(i);
    }
    for(int i = 3; i >= 0; i--) //test for case 4
    {
        list_insert(3);
    }

    //test for case 5
     list_insert(3);
     list_insert(5);
     list_insert(6);
     list_insert(7);
     list_insert(8);
     list_insert(2);
     list_insert(4);
     list_insert(0);
    */

    for(int i = 0; i < 10; i++)  //insert random numbers
    {
        list_insert(rand() % rand_max+1);
    }

    printList();
    freeList();
}
