#include <stdio.h>
#include <stdlib.h>

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

// Duyệt LNR (trung tự)
// void inorder(TNode* r) {
//     if (!r) return;
//     inorder(r->left);
//     printf("%d ", r->key);
//     inorder(r->right);
// }

// Duyệt LRN (hậu tự)
// void postorder(TNode* r) {
//     if (!r) return;
//     postorder(r->left);
//     postorder(r->right);
//     printf("%d ", r->key);
// }

// Hàm main để kiểm tra

int CountNodes(TNode* r) {
    if (!r) return 0;
    return 1 + CountNodes(r->left) + CountNodes(r->right);
}
int CountLeaves(TNode* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return CountLeaves(r->left) + CountLeaves(r->right);
}
int CountInternalNodes(TNode* r) {
    if (!r || (!r->left && !r->right)) return 0;
    return 1 + CountInternalNodes(r->left) + CountInternalNodes(r->right);
}

int main() {
    TNode* root = makeSampleTree();

    printf("Duyet NLR (Preorder): ");
    preorder(root);
    printf("\n");

    int totalNodes = CountNodes(root);
    int leafNodes = CountLeaves(root);
    int internalNodes = CountInternalNodes(root);
    printf("Tong so nut: %d\n", totalNodes);
    printf("So nut la: %d\n", leafNodes);
    printf("So nut noi: %d\n", internalNodes);
    

    return 0;
}
