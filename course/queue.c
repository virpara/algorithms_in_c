#include <stdio.h>
#include <stdbool.h>

struct queue_node {
    int value;
    struct queue_node * next;
};
typedef struct queue_node queue_node;

struct queue {
    queue_node * front;
    queue_node * back;
    int size;
};
typedef struct queue queue;

queue * create_queue() {
    queue * q = (queue *) malloc(sizeof(queue *));
    q->back = q-> front = NULL;
    q->size = 0;

    return q;
}

bool is_empty(queue * q) {
    return q->size == 0;
}

void push_queue(queue * q, int val) {
    queue_node * node = (queue_node *) malloc(sizeof(queue_node *));
    node->next = NULL;
    node->value = val;

    if(is_empty(q)) {
        q->back = q->front = node;
    } else {
        q->back->next = node;
        q->back = node;
    }
    q->size++;
}

int pop_queue(queue * q) {
    int val = q->front->value;

    queue_node * old = q->front;

    if(q->front == q->back) {
        q->front = q->back = NULL;
    } else {
        q->front = q->front->next;
    }
    free(old);
    q->size--;

    return val;
}

int main() {
    queue * q = create_queue();
    push_queue(q, 1);
    push_queue(q, 2);
    push_queue(q, 3);

    while(!is_empty(q)) {
        printf("%d\t", pop_queue(q));
    }
    return 0;
}

