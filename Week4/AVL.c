#include <stdio.h>
#include <stdlib.h>

/* AVL Tree Node */
struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

/* Utility Functions */
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *n) {
    return (n == NULL) ? 0 : n->height;
}

/* Create Node */
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

/* Right Rotate */
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* Left Rotate */
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* Balance Factor */
int getBalance(struct Node* n) {
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

/* Insert */
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    /* LL */
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    /* RR */
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    /* LR */
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    /* RL */
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* Inorder */
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Main */
int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("AVL Tree Inorder: ");
    inorder(root);

    return 0;
}
