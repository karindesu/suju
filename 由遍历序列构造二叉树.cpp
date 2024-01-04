#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

int preIndex = 0;

Node *newNode(char data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int search(char *arr, int strt, int end, char value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}
Node *buildTree(char *in, char *pre, int inStrt, int inEnd);
void printLevelOrder(Node *root);
int height(Node *node);
void printCurrentLevel(Node *root, int level);
Node *buildTree(char *in, char *pre, int inStrt, int inEnd) {
    if (inStrt > inEnd)
        return NULL;

    Node *tNode = newNode(pre[preIndex++]);

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void printInorder(Node *node) {
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}
void printLevelOrder(Node *root) {
    if (root == NULL) return;

    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
        printf("\n");
    }
}

int height(Node *node) {
    if (node == NULL) return 0;
    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight)
        return (lheight + 1);
    else
        return (rheight + 1);
}

void printCurrentLevel(Node *root, int level) {
    if (root == NULL) return;
    if (level == 1)
        printf("%c ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

int main() {
    int n;
    printf("请输入节点数量：");
    scanf("%d", &n);

    char *in = (char *)malloc(n * sizeof(char));
    char *pre = (char *)malloc(n * sizeof(char));

    printf("请输入中序遍历的结果：");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &in[i]);
    }

    printf("请输入先序遍历的结果：");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pre[i]);
    }

    Node *root = buildTree(in, pre, 0, n - 1);

    printf("根据输入构建的树的层序遍历结果：\n");
    printLevelOrder(root);
    printf("\n");

    free(in);
    free(pre);
    return 0;
}

