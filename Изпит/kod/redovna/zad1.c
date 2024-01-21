#include <stdio.h>
#include <stdlib.h>

#define N 3

int output[N];

typedef struct node {
    struct node* next;
    int val;
} node;

node* makeNode(int value);
void insertNode(node* head, node* n);
void solution(int matrix[N][N]);

int main() {
    int matrix[N][N] = {
        {1, -9, 2}, // 3
        {2, 4, -8}, // 6
        {-1, -2, 1} // 1
    };
    
    solution(matrix);
    
    int i;
    for(i = 0; i < N; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    return 0;
}

node* makeNode(int value) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode -> val = value;
    newNode -> next = NULL;
    return newNode;
}

void insertNode(node* head, node* n) {
    while(head->next != NULL && n->val > head->next->val) {
        head = head->next;
    }

    n->next = head->next;
    head->next = n;
}

void solution(int matrix[N][N]) {
    int i, j, sumRow, index;
    node* dummy = makeNode(-100);
    for(i = 0; i < N; i++) {
        sumRow = 0;
        for(j = 0; j < N; j++) {
            if(matrix[i][j] > 0) sumRow += matrix[i][j];
        }
        node* tempNode = makeNode(sumRow);
        insertNode(dummy, tempNode);
    }

    node* temp = dummy->next;
    index = 0;
    while(temp != NULL) {
        output[index++] = temp->val;
        temp = temp->next;
    }

    while(dummy != NULL) {
        temp = dummy;
        dummy = dummy->next;
        free(temp);
    }
}