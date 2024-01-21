#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* makeNode(int value);
treeNode* addNode(treeNode* root, int value);
void freeNodes(treeNode* root);
void sortArray(treeNode* root, int arr[], int* index);
void traversal(treeNode* root);

int main() {
    int arr[] = {4,8,1,10,3,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    treeNode* root = makeNode(arr[0]);
    int i;
    for(i = 0; i < n; i++) {
        addNode(root, arr[i]);
    }

    int index = 0;
    sortArray(root, arr, &index);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    freeNodes(root);
    return 0;
}

treeNode* makeNode(int value) {
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
}

treeNode* addNode(treeNode* root, int value) {
    if(root == NULL) {
        return makeNode(value);
    }

    if(value < root->val) {
        root->left = addNode(root->left, value);
    }else if(value > root->val) {
        root->right = addNode(root->right, value);
    }

    return root;
}

void sortArray(treeNode* root, int arr[], int* index) {
    if(root != NULL) {
        sortArray(root->left, arr, index);
        arr[(*index)++] = root->val;
        sortArray(root->right, arr, index);
    }
}

void freeNodes(treeNode* root) {
    if(root != NULL) {
        freeNodes(root->left);
        freeNodes(root->right);
        free(root);
    }
}