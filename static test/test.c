#include <stdio.h>
#include <stdlib.h>

 typedef struct node {
    int data;
    struct node *next;
    } NODE;

typedef struct {
   NODE  *head;
   int size;
} LIST;

int countListRecursive(NODE *p) { 
    if (p == NULL) 
        return 0;
    return 1 + countListRecursive(p->next); 
}

int count(LIST *l) {
    if (l == NULL) 
        return 0;
    return countListRecursive(l->head);
    }

int initList2(LIST **list) {
    *list = (LIST *) malloc(sizeof(LIST)); 
    if ((*list) == NULL) 
        return EXIT_FAILURE; 
    (*list)->head = NULL;
    return EXIT_SUCCESS;
 }

void insert(LIST *l, int x){
    NODE *p = NULL, *q = NULL; /* prev, curr copy pointers*/
    if (l == NULL) { printf("Unable to Enter"); return; }
    /* Create and Fill New Node */
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Error: Unable to Allocate Memory!"); return;
    }
    newNode->data = x;
    newNode->next = NULL;
    /* 2) Connect newNode to List */
    if ( l->head == NULL ) /* If Empty add to l->head */
        l->head = newNode;
    else {
        p = q = l->head; /* Fast forward p and q until data<x*/ 
        while ( ( q != NULL ) && ( q->data < x ) ) {
        p = q;
        q = q->next; 
        }
        if ( p == q ) { /* i.e., Insert to first position */ 
        newNode->next = l->head; // e.g., insert “0” l->head = newNode; // Branch required for this!
        } else { /* Insert anywhere else */ 
        newNode->next = q;
        p->next = newNode;
        }
    } // else()
        (l->size)++; /* Increase List size*/ 
    } // insert()

int main()
{
    LIST *list;
    initList2(&list);
    int i;

    for (i = 0; i < 10; i++)
        insert(list, i);

    printf("%d\n", count(list));
}