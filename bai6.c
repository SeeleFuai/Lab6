#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int key;
    struct TNode *left, *right;
} TNode;

// Tạo nút mới
TNode* createNode(int x) {
    TNode* p = (TNode*)malloc(sizeof(TNode));
    if (!p) exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

// Thêm nút vào BST
int insertBST(TNode** r, int x) {
    if (*r == NULL) {
        *r = createNode(x);
        return 1;
    }
    if (x == (*r)->key) return 0;
    if (x < (*r)->key) return insertBST(&(*r)->left, x);
    else return insertBST(&(*r)->right, x);
}

void inorder(TNode* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->key);
    inorder(r->right);
}

TNode* findMin(TNode* r) {
    while (r && r->left) r = r->left;
    return r;
}

TNode* deleteBST(TNode* r, int x) {
    if (!r) return NULL;

    if (x < r->key) { 
        r->left = deleteBST(r->left, x); 
    } 
    /*
        10
       /  \
      5    15
     / \   / \
    3   7 13 17
              \
              20
    */
    else if (x > r->key) {                                                                      
        r->right = deleteBST(r->right, x);
    } 
    else {
        // Trường hợp 1: không có con trái
        if (!r->left) {
            TNode* t = r->right;
            free(r);
            return t;
        }
        // Trường hợp 2: không có con phải
        if (!r->right) {
            TNode* t = r->left;
            free(r);
            return t;
        }
        // Trường hợp 3: có cả hai con, thế mạng bằng min bên phải
        TNode* s = findMin(r->right);
        r->key = s->key;
        r->right = deleteBST(r->right, s->key); // xóa nút thế mạng
    }
    return r;
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

    int x;
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &x);
    root = deleteBST(root, x);

    printf("Cay BST sau khi xoa %d duyet LNR: ", x);
    inorder(root);
    printf("\n");

    return 0;
}