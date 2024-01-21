#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 50

typedef struct treeNode {
    struct treeNode* left;
    struct treeNode* right;
    char val[STR_SIZE];
} treeNode;

treeNode* makeNode(const char* str);
treeNode* insertNode(treeNode* root, const char* str);
void inOrderTraversal(treeNode* tree);
void freeBTS(treeNode* tree);

int main() {
    char str1[] = "o";
    char str2[] = "uy";
    char str3[] = "a";
    char str4[] = "pr";
    char str5[] = "c";

    treeNode* root = NULL;
    root = insertNode(root, str1);
    insertNode(root, str2);
    insertNode(root, str3);
    insertNode(root, str4);
    insertNode(root, str5);

    inOrderTraversal(root);
    freeBTS(root);
    return 0;
}

treeNode* makeNode(const char* str) {
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->left = NULL;
    node->right = NULL;
    strcpy(node->val, str);
    return node;
}

treeNode* insertNode(treeNode* root, const char* str) {
    if(root != NULL) {
        int difference = strcmp(root->val, str);
        if(difference < 0) {
            root->left = insertNode(root->left, str);
        }else {
            root->right = insertNode(root->right, str);
        }
    }
    return makeNode(str);
}

void inOrderTraversal(treeNode* root) {
    if(root != NULL) {
        inOrderTraversal(root->left);
        printf("%s ", root->val);
        inOrderTraversal(root->right);
    }
}

void freeBTS(treeNode* root) {
    if(root != NULL) {
        freeBTS(root->left);
        freeBTS(root->right);
        free(root);
    }
}