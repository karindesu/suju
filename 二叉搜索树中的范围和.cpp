#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!node) {
        fprintf(stderr, "�ڴ治�㣡\n");
        exit(1);
    }
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertTreeNode(struct TreeNode** root, int val) {
    if (*root == NULL) {
        *root = newTreeNode(val);
    } else if (val < (*root)->val) {
        insertTreeNode(&((*root)->left), val);
    } else if (val > (*root)->val) {
        insertTreeNode(&((*root)->right), val);
    }
}

int rangeSumBST(struct TreeNode* root, int L, int R) {
    if (root == NULL) return 0;
    if (root->val < L) return rangeSumBST(root->right, L, R);
    if (root->val > R) return rangeSumBST(root->left, L, R);
    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root = NULL;
    int val;
    printf("����������������Ľڵ�ֵ������-1������:\n");
    while (1) {
        scanf("%d", &val);
        if (val == -1) break;
        insertTreeNode(&root, val);
    }

    int L, R;
    printf("�����뷶Χ [L, R]: ");
    scanf("%d %d", &L, &R);

    int sum = rangeSumBST(root, L, R);
    printf("������������ %d �� %d ��Χ�Ľڵ��ܺ���: %d\n", L, R, sum);

    freeTree(root); // �ͷ������ڴ�
    return 0;
}
