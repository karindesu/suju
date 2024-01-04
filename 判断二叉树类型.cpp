#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Tree{
	int data;
	struct Tree *rchild;
	struct Tree *lchild;
}tree; 
tree T;
void cj(tree *a){
	scanf("%d",&a->data);
	int n;
	scanf("%d",&n);
	if(n==0){
		a->rchild=NULL;
		a->lchild=NULL;
	}
	if(n==1){
		a->lchild=(tree*)malloc(sizeof(tree));
		a->rchild=NULL;
		cj(a->lchild);
	}
	if(n==2){
		a->rchild=(tree*)malloc(sizeof(tree));
		a->lchild=NULL;
		cj(a->rchild);
	}
	if(n==3){
		a->rchild=(tree*)malloc(sizeof(tree));
		a->lchild=(tree*)malloc(sizeof(tree));
		cj(a->lchild);
		cj(a->rchild);
	}
}
int y=0;
int pd(tree *a){
	int i=0,j=0;
	y++;
	if(a->lchild!=NULL){
		i=pd(a->lchild);
	}
	if(a->rchild!=NULL){
		j=pd(a->rchild);
	}
	if(a->lchild==NULL&&a->rchild==NULL)return 1;
	if(i>j)return i+1;
	if(j>=i)return j+1;
} 
int main(){
	tree *a=&T;
	printf("创建方式为：值,n值（当3为有两个孩子，2为有右孩子，1为有左孩子，0为没有孩子；顺序为先序遍历，以头到最左再右\n");
	cj(a);
	int b,x,x1;
	b=pd(a);
	x=pow(2.0,b);
	x1=pow(2.0,b-1);
	if(y==x-1)printf("是满二叉树，也是完全二叉树。");
	else if(y>x1-1&&y<x-1)printf("不是满二叉树，是完全二叉树。"); 
	return 0; 
}
