#include <stdio.h>
#include <stdbool.h>


struct stack_node {
    int value;
    struct stack_node * next;
};
typedef struct stack_node stack_node;


struct stack {
    stack_node * head;
    int size;
};
typedef struct stack stack;

stack * create_stack() {
    stack * s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    s->head = NULL;

    return s;
}

bool is_empty(stack * s) {
    return s->size == 0;
}

void push(stack * s, int val) {
    // create new node
    stack_node * node = (stack_node *) malloc(sizeof(stack_node));
    node->value = val;
    node->next = s->head;

    // adjust stack to point to new node and increase the size
    s->head = node;
    s->size++;
}

int pop(stack * s) {
    stack_node * head = s->head;
    int val = head->value;

    // get rid of head node, point to next node and decrease the size
    s->head = head->next;
    s->size--;

    free(head);
    return val;
}

int main() {
    stack * s = create_stack();
    push(s, 5);
    push(s, 9);
    push(s, 3);

    while(!is_empty(s)) {
        printf("%d\t", pop(s));
    }

    return 0;
}
