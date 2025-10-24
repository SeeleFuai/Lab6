#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int key;
    struct TNode *left, *right;
} TNode;

TNode* createNode(int x) {
    TNode* p = (TNode*)malloc(sizeof(TNode));
    if (!p) exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

int insertBST(TNode** r, int x) {
    if (*r == NULL) {
        *r = createNode(x);
        return 1;
    }
    if (x == (*r)->key) return 0;
    if (x < (*r)->key) return insertBST(&(*r)->left, x);
    else return insertBST(&(*r)->right, x);
}

// Tìm kiếm nút có giá trị x
TNode* searchBST(TNode* r, int x) {
    if (!r || r->key == x) return r;
    return x < r->key ? searchBST(r->left, x) : searchBST(r->right, x);
}

// Tìm giá trị nhỏ nhất
TNode* findMin(TNode* r) {
    while (r && r->left) r = r->left;
    return r;
}

// Tìm giá trị lớn nhất
TNode* findMax(TNode* r) {
    while (r && r->right) r = r->right;
    return r;
}

void inorder(TNode* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->key);
    inorder(r->right);
}

int main() {
    TNode* root = NULL;
    int arr[] = {9, 5, 4, 8, 6, 3, 14, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insertBST(&root, arr[i]);
    }

    printf("Cay BST duyet LNR (tang dan): ");
    inorder(root);
    printf("\n");

    TNode* minNode = findMin(root);
    TNode* maxNode = findMax(root);
    printf("Min = %d\n", minNode->key);
    printf("Max = %d\n", maxNode->key);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    TNode* found = searchBST(root, x);
    printf("Ket qua tim kiem: %s\n", found ? "FOUND" : "NOT FOUND");

    return 0;
}
