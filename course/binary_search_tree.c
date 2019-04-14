#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// binary search tree
struct tree_node {
    int value;
    struct tree_node * left;
    struct tree_node * right;
};
typedef struct tree_node tree_node;

struct tree {
    tree_node * root;
    int size;
};
typedef struct tree tree;

tree * create_tree() {
    tree * t = (tree *) malloc(sizeof(tree *));
    t->root = NULL;
    t->size = 0;

    return t;
}

bool empty_tree(tree * t) {
    return t->size == 0;
}

void insert_tree(tree * t, int val) {
    tree_node * n = (tree_node *) malloc(sizeof(tree_node *));
    n->left = n->right = NULL;
    n->value = val;

    if (empty_tree(t)) {
        t->root = n;
        t->size++;
        return;
    }

    tree_node * node = t->root;
    while(true) {
        if (val < node->value) {
            if (node->left == NULL) {
                node->left = n;
                t->size++;
                break;
            }
            node = node->left;
        } else if (val > node->value){
            if (node->right == NULL) {
                node->right = n;
                t->size++;
                break;
            }
            node = node->right;
        } else {
            // value exists in the tree
            break;
        }
    }
}

//void remove_tree(tree * t, int val) {
//    tree_node * root = t->root;
//    while(root != NULL) {
//        if (val == root->value) {
//            // remove root
//        } else {
//
//        }
//    }
//}

void print_tree(tree_node * root) {
    if (root == NULL) return;

    print_tree(root->left);
    printf("%d\t", root->value);
    print_tree(root->right);
}

int main() {
    tree * t = create_tree();
    insert_tree(t, 5);
//    insert_tree(t, 7);
    insert_tree(t, 3);
    insert_tree(t, 4);
//    insert_tree(t, 7);

//    print_tree(t->root);

    return 0;
}
