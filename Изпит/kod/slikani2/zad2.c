#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

void removeEverySecondNode(node* head);
void freeNodes(node* head);
node* makeNode(int value);
node* addNode(node* head, int value);
void printList(node* head);

int main() {
    node* head;
    head = addNode(NULL, 6);
    head = addNode(head, 5);
    head = addNode(head, 16);
    head = addNode(head, 4);
    head = addNode(head, 9);
    head = addNode(head, 3);
    
    printList(head);
    removeEverySecondNode(head);
    printList(head);
    freeNodes(head);
    return 0;
}

node* makeNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

node* addNode(node* head, int value) {
    node* n = makeNode(value);
    n->next = head;
    return n;
}

void freeNodes(node* head) {
    node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void removeEverySecondNode(node* head) {
    node* temp = NULL;
    while(head->next != NULL && head->next->next != NULL) {
        if(head->next->val / 3 >= head->val) {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
            head = head->next;
        }else {
            head = head->next->next;
        }
    }
}

void printList(node* head) {
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}