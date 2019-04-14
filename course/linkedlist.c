#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node {
    int value;
    struct list_node * next;
};
typedef struct list_node list_node;

struct linked_list {
    int size;
    list_node * list;
};
typedef struct linked_list linked_list;

linked_list * create_list() {
    linked_list * l = (linked_list *) malloc(sizeof(linked_list));
    l->size = 0;
    l->list = NULL;

    return l;
}

bool is_empty(linked_list * l) {
    return l->size == 0;
}

void add_list(linked_list * l, int v) {
    list_node * n = (list_node *) malloc(sizeof(list_node));
    n->next = NULL;
    n->value = v;

    if(is_empty(l)) {
        l->list = n;
        l->size++;
    } else {
        // append the new node at the end
        list_node * list = l->list;
        while(list->next != NULL) {
            list = list->next;
        }

        list->next = n;
        l->size++;
    }
}

void print_list(linked_list * l) {
    list_node * n = l->list;
    while(n != NULL) {
        printf("%d\t", n->value);
        n = n->next;
    }
}

// problem 1 return size of the list
int size_list(linked_list * l) {
    int size = 0;

    list_node * n = l->list;
    while(n != NULL) {
        size++;
        n = n->next;
    }

    return size;
}

// problem 2 return node containing the value
list_node * find_list(linked_list * l, int value) {
    list_node * n = l->list;
    while(n != NULL) {
        if(n->value == value) return n;
        n = n->next;
    }

    return NULL;
}

// problem 4
void clear_list(linked_list * l) {
    list_node * n = l->list;

    l->size = 0;
    l->list = NULL;

    while (n != NULL) {
        list_node * temp = n->next;
        free(n);
        n = temp;
    }

}

// todo: problem 3 and 5

int main() {
    linked_list * l = create_list();
    add_list(l, 5);
    add_list(l, 1);
    add_list(l, 8);

    print_list(l);
    printf("list size: %d\n", size_list(l));
    printf("address of 8: %d\n", find_list(l, 8));
    printf("address of 2: %d\n", find_list(l, 2));

    clear_list(l);

    return 0;
}
