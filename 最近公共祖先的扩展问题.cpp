#include<stdio.h>
#include<stdlib.h>
typedef struct Tree{
	char data;
	struct Tree *rchild;
	struct Tree *lchild;
}tree; 
tree T;
char sj[10],sj2[10];
int i=0,j=0;
void cj(tree *a){
	a->data=getchar();
	int n;
	scanf("%d",&n);
	getchar();
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
int cz(int n,tree *a){
	int f;
	if(a->data==n){
    sj[i]=a->data;
	i++;
	return 1;
}
	else{
		if(a->lchild!=NULL){
			f=cz(n,a->lchild);
			if(f==1){
				sj[i]=a->data;
				i++;
				return 1;
			}
			
		}
		if(a->rchild!=NULL){
			f=cz(n,a->rchild);
			if(f==1){
				sj[i]=a->data;
				i++;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	tree *a=&T;
	printf("������ʽΪ��ֵ��nֵ����3Ϊ���������ӣ�2Ϊ���Һ��ӣ�1Ϊ�����ӣ�0Ϊû�к��ӣ�˳��Ϊ�����������ͷ����������\n");
	cj(a);
	int n,m;
	printf("������i��j\n");
	scanf("%c %c",&n,&m);
	cz(n,a);
	int f,g;
	for(f=0;f<i;f++){
		sj2[f]=sj[f];
	}
	i=0;
	cz(m,a);
	g=i;
	f--;g--;
	printf("�����ڵ�����Ĺ������ȵ�ֵΪ��"); 
	while(1){
		if(sj[g]!=sj2[f]){
			printf("%c",sj[g+1]);
			break;
		}
		f--;
		g--;
		if(f<0||g<0){
			printf("%c",sj[g+1]);
			break;
		}
	}
	return 0; 
}
