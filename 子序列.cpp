#include<stdio.h>
#include<stdlib.h>
typedef struct xl{
	int num;
	struct xl *q,*h;
}x;
x *sr(x *h){
	int n;
	x *b,*q,*p;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		b=(x*)malloc(sizeof(x));
		b->num=n;
		b->h=NULL;
		b->q=NULL;
		if(h==NULL){
			h=b;
			q=h;
		}else{
			q->h=b;
			q=q->h;
		    q->q=p;
		}
		p=q;
		
		
	}
	return h;
}
void bj(x *a,x *b){
	if(a->num==b->num){
		if(b->h==NULL){
			printf("是子序列。"); 
		}else{
			for(;a->q!=NULL;a=a->q);
			bj(a,b->h);
		}
	}else{
		if(a->h==NULL)printf("不是子序列。");
		 else{
		 	bj(a->h,b);
		 }
	}
}
int main(){
	x *a=NULL,*b=NULL;
	a=sr(a);
	b=sr(b);
	bj(a,b);
	return 0;
}
