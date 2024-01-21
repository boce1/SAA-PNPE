#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct node {
    int val;
    struct node* next;
} node;

node* makeNode(int value);
void addNode(node* head, int value);
int find21st(int matrix[N][N]);

int main() {
    int matrix[N][N] = {
        {1, 4, 5}, 
        {5, 8, 8}, 
        {3, 0, 5}
    };
    printf("%d\n", find21st(matrix));
    return 0;
}

node* makeNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void addNode(node* head, int value) {
    node* nodeToAdd = makeNode(value);

    while(head->next != NULL && nodeToAdd->val > head->next->val) {
        head = head->next;
    }
    nodeToAdd->next = head->next;
    head->next = nodeToAdd;
}

void freeList(node* head) {
    node* temp = NULL;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int find21st(int matrix[N][N]) {
    int i;
    node* head = makeNode(matrix[0][0]);

    for(i = 1; i < N; i++) {
        addNode(head, matrix[i][i]);
    }

    node* temp = head;
    for(i = 0; i < 2 - 1; i++) { // 21 instead of 2,
        temp = temp->next;
    }
    int output = temp->val;
    freeList(head);
    return output;
}