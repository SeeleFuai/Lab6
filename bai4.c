#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Định nghĩa struct nút cây nhị phân
typedef struct TNode {
    int key;
    struct TNode *left, *right;
} TNode;

// Hàm tạo một nút mới
TNode* createNode(int x) {
    TNode* p = (TNode*)malloc(sizeof(TNode));
    if (!p) exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

// Hàm dựng cây mẫu 7 nút
TNode* makeSampleTree() {
    TNode* n1 = createNode(1);
    TNode* n2 = createNode(2);
    TNode* n3 = createNode(3);
    TNode* n4 = createNode(4);
    TNode* n5 = createNode(5);
    TNode* n6 = createNode(6);
    TNode* n7 = createNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    return n1;
}

void preorder(TNode* r) {
    if (!r) return;
    printf("%d ", r->key);
    preorder(r->left);
    preorder(r->right);
}

int findDFS(TNode* r, int x) {
    if (!r) return 0;
    if (r->key == x) return 1;
    return findDFS(r->left, x) || findDFS(r->right, x);
}

int findBFS(TNode* r, int x) {
    if (!r) return 0;
    TNode* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = r;

    while (front < rear) {
        TNode* current = queue[front++];
        if (current->key == x) return 1;
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    return 0;
}


int main() {
    TNode* root = makeSampleTree();

    printf("Duyet NLR (Preorder): ");
    preorder(root);
    printf("\n");
    int x = 5;
    if (findDFS(root, x)) {
        printf("Tim thay %d trong cay.\n", x);
    } else {
        printf("Khong tim thay %d trong cay.\n", x);
    }
    printf("***********\n");
    if (findBFS(root, x)) {
        printf("Tim thay %d trong cay (BFS).\n", x);
    } else {
        printf("Khong tim thay %d trong cay (BFS).\n", x);
    }
    return 0;
}
