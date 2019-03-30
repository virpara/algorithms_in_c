#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// --------- heap ---------------
// max heap: every parent is bigger than its children
// min heap: every parent is smaller than its children
struct heap {
    int * array;
    int size;
};
typedef struct heap heap;

heap * create_heap(int max_size)
{
    heap * h = (heap *) malloc(sizeof(heap));
    h->array = (int *) malloc(sizeof(int) * max_size);
    h->size = 0;

    // initialize all the array as zero. Not required.
    int i;
    for(i = 0; i < max_size; i++)
        h->array[i] = 0;

    return h;
}

// check whether heap is empty
bool empty_heap(heap * h)
{
    return h->size == 0;
}

void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int nb1, int nb2)
{
    return nb1 > nb2 ? nb1 : nb2 ;
}

int min(int nb1, int nb2)
{
    return nb1 < nb2 ? nb1 : nb2;
}

void insert_max_heap(heap * h, int value)
{
    h->array[++h->size] = value; // increment the size var of heap, then add the value at the size index

    int child_index = h->size;
    // child index is not root and child is grater than parent
    while(child_index > 1 && h->array[child_index] > h->array[child_index/2]) {
        swap(&h->array[child_index], &h->array[child_index/2]);
        child_index /= 2; // check the parent node. other side of the tree is not modified, so we don't need to do child_index--
    }
}

int extract_max_heap(heap * h)
{
    if(empty_heap(h)) {
        printf("heap is empty!\n");
        return -1;
    }

    // swap the root with the last element, then remove the last element
    // root element is the maximum element in max heap, and minimum element in the min heap
    int value = h->array[1];
    h->array[1] = h->array[h->size];
    h->size--;

    // check for heap property and correct it, if it's violated
    int parent_index = 1;
    int left_child_index, right_child_index, left_child, right_child;
    do {
        left_child_index = parent_index * 2;
        right_child_index = parent_index * 2 + 1;

        // if the child elements are less than parent, then we're sure other nodes also satisfies the heap property
        left_child = h->array[left_child_index];
        right_child = h->array[right_child_index];
        if(h->array[parent_index] > max(left_child, right_child))
            break;

        // left child is greater than parent
        if(h->array[left_child_index] > h->array[right_child_index]) {
            swap(&h->array[left_child_index], &h->array[parent_index]);
            parent_index = left_child_index;
        } else {
            swap(&h->array[right_child_index], &h->array[parent_index]);
            parent_index = right_child_index;
        }

    } while(parent_index < h->size);

    return value;
}

void insert_min_heap(heap * h, int value)
{
    h->array[++h->size] = value; // increment the size var of heap, then add the value at the size index

    int child_index = h->size;
    // child index is not root and child is less than parent
    while(child_index > 1 && h->array[child_index] < h->array[child_index/2]) {
        swap(&h->array[child_index], &h->array[child_index/2]);
        child_index /= 2; // check the parent node. other side of the tree is not modified, so we don't need to do child_index--
    }
}

int extract_min_heap(heap * h)
{
    if(empty_heap(h)) {
        printf("heap is empty!\n");
        return -1;
    }

    // swap the root with the last element, then remove the last element
    // root element is the maximum element in max heap, and minimum element in the min heap
    int value = h->array[1];
    h->array[1] = h->array[h->size];
    h->size--;

    // check for heap property and correct it, if it's violated
    int parent_index = 1;
    int left_child_index, right_child_index, left_child, right_child;
    do {
        left_child_index = parent_index * 2;
        right_child_index = parent_index * 2 + 1;

        // if the child elements are greater than parent, then we're sure other nodes also satisfies the min heap property
        left_child = h->array[left_child_index];
        right_child = h->array[right_child_index];
        if(h->array[parent_index] < min(left_child, right_child))
            break;

        // left child is less than right child
        if(h->array[left_child_index] < h->array[right_child_index]) {
            swap(&h->array[left_child_index], &h->array[parent_index]);
            parent_index = left_child_index;
        } else {
            swap(&h->array[right_child_index], &h->array[parent_index]);
            parent_index = right_child_index;
        }

    } while(parent_index < h->size);

    return value;
}

int main()
{
//    heap * max_heap = create_heap(100);
//    insert_max_heap(max_heap, 6);
//    insert_max_heap(max_heap, 3);
//    insert_max_heap(max_heap, 9);
//    insert_max_heap(max_heap, 4);
//    insert_max_heap(max_heap, 3);
//
////    for(int i = 1; i <= h->size; i++)
////        printf("%d ", h->array[i]);
////    printf("\n");
//
//    // heap should always extract the maximum number in case of max heap
//    while(!empty_heap(max_heap)) {
//        printf("%d ", extract_max_heap(max_heap));
//    }
//    printf("\n");

    // TODO: min heap prints in wrong order
    heap * min_heap = create_heap(100);
    insert_min_heap(min_heap, 6);
    insert_min_heap(min_heap, 3);
    insert_min_heap(min_heap, 9);
    insert_min_heap(min_heap, 4);
    insert_min_heap(min_heap, 3);

    while(!empty_heap(min_heap)) {
        printf("%d ", extract_min_heap(min_heap));
    }
    return 0;
}
