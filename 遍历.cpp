#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct Stack
{
    TreeNode **elements;
    int top;
    int maxSize;
} Stack;
Stack *createStack(int size)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->elements = (TreeNode **)malloc(size * sizeof(TreeNode *));
    s->top = -1;
    s->maxSize = size;
    return s;
}
int isFull(Stack *s)
{
    return s->top == s->maxSize - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}
void push(Stack *s, TreeNode *node)
{
    if (!isFull(s))
	{
        s->elements[++s->top] = node;
    }
}
TreeNode* pop(Stack *s)
{
    if (!isEmpty(s))
	{
        return s->elements[s->top--];
    }
    return NULL;
}
TreeNode* top(Stack *s)
{
    if (!isEmpty(s))
	{
        return s->elements[s->top];
    }
    return NULL;
}
void deleteStack(Stack *s)
{
    free(s->elements);
    free(s);
}
void preorderTraversal(TreeNode *root)
{
    if (root == NULL) return;

    Stack *stack = createStack(100);
    push(stack, root);
    
    while (!isEmpty(stack))
	{
        TreeNode *current = pop(stack);
        printf("%d ", current->val);

        if (current->right != NULL) push(stack, current->right);
        if (current->left != NULL) push(stack, current->left);
    }

    deleteStack(stack);
}
void inorderTraversal(TreeNode *root)
{
    if (root == NULL) return;

    Stack *stack = createStack(100);
    TreeNode *current = root;
    
    while (!isEmpty(stack) || current != NULL)
	{
        if (current != NULL)
		{
            push(stack, current);
            current = current->left;
        }
		else
		{
            current = pop(stack);
            printf("%d ", current->val);
            current = current->right;
        }
    }

    deleteStack(stack);
}
void postorderTraversal(TreeNode *root)
{
    if (root == NULL) return;

    Stack *stack = createStack(100);
    TreeNode *current = root;
    TreeNode *lastVisited = NULL;

    while (!isEmpty(stack) || current != NULL)
	{
        if (current != NULL)
		{
            push(stack, current);
            current = current->left;
        }
		else
		{
            TreeNode *peekNode = top(stack);
            if (peekNode->right != NULL && lastVisited != peekNode->right)
			{
                current = peekNode->right;
            } else {
                printf("%d ", peekNode->val);
                lastVisited = pop(stack);
            }
        }
    }

    deleteStack(stack);
}
TreeNode* createNode(int value)
{
    if (value == -1) return NULL;
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
TreeNode *createTree(int n)
{
    printf("请输入 %d 个节点的索引和它们的左右子节点索引（-1代表空）：\n", n);
    TreeNode **nodes = (TreeNode **)malloc((n + 1) * sizeof(TreeNode *));
    for (int i = 1; i <= n; ++i)
	{
        nodes[i] = (TreeNode *)malloc(sizeof(TreeNode));
    }
    int value, leftIndex, rightIndex;
    for (int i = 1; i <= n; ++i)
	{
        scanf("%d %d %d", &value, &leftIndex, &rightIndex);
        nodes[i]->val = value;
        nodes[i]->left = (leftIndex == -1) ? NULL : nodes[leftIndex];
        nodes[i]->right = (rightIndex == -1) ? NULL : nodes[rightIndex];
    }
    TreeNode *root = nodes[1];
    free(nodes);
    return root;
}
void freeTree(TreeNode* root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main()
{
    int n;
    printf("请输入节点总数 n:\n");
    scanf("%d", &n);

    TreeNode *root = createTree(n);

    printf("先序遍历结果：");
    preorderTraversal(root);
    printf("\n");

    printf("中序遍历结果：");
    inorderTraversal(root);
    printf("\n");

    printf("后序遍历结果：");
    postorderTraversal(root);
    printf("\n");
    freeTree(root);
    return 0;
}
