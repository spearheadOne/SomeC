//
// Created by abondar on 07.03.16.
//

#include <stdio.h>
#include "list.h"


int main() {

    //linked list
    List storage;
    List *l = &storage;
    void *removed;

    int data = 0;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    list_init(l, NULL);
    printf("Linked list has been initalized\n");

    list_ins_next(l, NULL, &data);
    list_ins_next(l, NULL, &data1);
    list_ins_next(l, NULL, &data2);


    printf("Current linked list size %d\n", list_size(l));

    printf("Head elem %d\n", *(int *)l->head->data);
    printf("Next of head elem %d\n", *(int *)l->head->next->data);
    printf("Next of the next %d\n", *(int *)l->head->next->next->data);
    printf("Tail elem %d\n", *(int *)l->tail->data);

    list_ins_next(l, l->head, &data3);

    printf("Current linked list size %d\n", list_size(l));
    printf("New next of head %d\n", *(int *)l->head->next->data);

    list_rem_next(l, NULL, &removed);
    list_rem_next(l, NULL, &removed);
    list_rem_next(l, NULL, &removed);
    list_rem_next(l, NULL, &removed);

    printf("Linked list has been cleared\n");

    list_destroy(l);
    printf("Linked list has been destroyed\n");

    return 0;
}
