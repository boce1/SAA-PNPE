#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct node {
    int val;
    struct node* next;
} node;

node* makeNode(int value);
void addNode(node* head, int value);
int medianSecondDiagonal(int matrix[N][N]);
void freeNodes(node* head);

int main() {
    int matrix[N][N] = {
        {20, 5, 1},
        {4,15, 6},
        {7,4,8}
    };
    printf("%d \n", medianSecondDiagonal(matrix));
    return 0;
}

node* makeNode(int value) {
    node* n = (node*)malloc(sizeof(node));
    n->val = value;
    n->next = NULL;
    return n;
}

void addNode(node* head, int value) {
    while(head->next != NULL && value > head->next->val) {
        head = head->next;
    }
    node* newNode = makeNode(value);
    newNode->next = head->next;
    head->next = newNode;
}

void freeNodes(node* head) {
    node* temp = NULL;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int medianSecondDiagonal(int matrix[N][N]) {
    int i;
    node* head = makeNode(matrix[0][N - 1]);

    for(i = 1; i < N; i++) {
        addNode(head, matrix[i][N - i - 1]);
    }

    int index = N / 2;
    node* temp = head;
    for(i = 0; i < index; i++) {
        temp = temp->next;
    }
    int output = temp->val;

    freeNodes(head);
    return output;
}