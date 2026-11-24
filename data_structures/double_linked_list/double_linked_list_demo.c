//
// Created by abondar on 07.03.16.
//

#include <stdio.h>
#include "double_list.h"


int main() {

    DList storage;
    DList *l = &storage;
    void *removed;

    int data = 0;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;

    dlist_init(l, NULL);
    printf("Linked list has been initialized\n");

    dlist_ins_next(l, NULL, &data1);
    dlist_ins_prev(l, l->head, &data);
    dlist_ins_next(l, l->tail, &data2);


    printf("Current double linked list size %d\n", dlist_size(l));

    printf("Head elem %d\n", *(int *)dlist_head(l)->data);
    printf("Tail elem %d\n", *(int *)dlist_tail(l)->data);

    dlist_ins_prev(l,l->tail,&data3);

    printf("Head elem after insertion %d\n", *(int *)dlist_head(l)->data);
    printf("Current linked list size %d\n", dlist_size(l));

    dlist_remove(l, dlist_tail(l)->prev->prev, &removed);
    dlist_remove(l, dlist_tail(l), &removed);
    dlist_remove(l, dlist_head(l), &removed);
    dlist_remove(l, l->head, &removed);


    printf("Linked list has been cleared\n");

    if (dlist_size(l)==0) {
        dlist_destroy(l);
        printf("Linked list has been destroyed\n");
    } else {
        printf("Can't delete list. It's not empty %d\n",dlist_size(l));

    }

    return 0;
}
