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
	printf("������ʽΪ��ֵ,nֵ����3Ϊ���������ӣ�2Ϊ���Һ��ӣ�1Ϊ�����ӣ�0Ϊû�к��ӣ�˳��Ϊ�����������ͷ����������\n");
	cj(a);
	int b,x,x1;
	b=pd(a);
	x=pow(2.0,b);
	x1=pow(2.0,b-1);
	if(y==x-1)printf("������������Ҳ����ȫ��������");
	else if(y>x1-1&&y<x-1)printf("������������������ȫ��������"); 
	return 0; 
}
