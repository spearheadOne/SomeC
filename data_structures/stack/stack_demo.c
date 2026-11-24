//
// Created by abondar on 07.03.16.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {

    Stack storage;
    Stack *stack = &storage;
    void *removed;
    int data = 0;
    int data1 = 1;
    int data2 = 2;

    stack_init(stack, NULL);

    printf("Stack has been created\n");
    stack_push(stack, &data);
    stack_push(stack, &data1);
    stack_push(stack, &data2);

    printf("Stack head %d\n", *(int *)stack_peek(stack));
    printf("Stack size %d\n", stack_size(stack));

    stack_pop(stack, &removed);
    printf("Removed %d\n", *(int *)removed);
    stack_pop(stack, &removed);
    printf("Removed %d\n", *(int *)removed);
    stack_pop(stack, &removed);
    printf("Removed %d\n", *(int *)removed);

    printf("Stack has been cleared\n");

    stack_destroy(stack);
    printf("Stack has been destroyed\n");


    return 0;
}
