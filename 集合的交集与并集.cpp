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
	h->q=p;
	p->h=h;
	return h;
}
void jj(x *a,x *b){
	printf("交集为：{");
	x *q=a,*p;
	while(1){
		p=b;
		while(1){
			if(q->num==p->num)
			{
			printf("%d ",q->num);
			break;
		}
		p=p->h;
			if(p==b)break;
		}
		q=q->h;
		if(q==a)break;
	}
	printf("}\n");
}
void bj(x *a,x *b){
		printf("并集为：{");
	x *q=a,*p;
	while(1){
		p=b;
		while(1){
			if(q->num==p->num)
			{
			printf("%d ",q->num);
			p->num=0;
			break;
		}
		p=p->h;
			if(p==b){
				printf("%d ",q->num);
			break;
		}
		}
		q=q->h;
		if(q==a)break;
	}
	p=b;
	while(1){
		if(p->num!=0)printf("%d ",p->num);
		p=p->h;
		if(p==b)break;
	}
	printf("}");
}
int main(){
	x *a=NULL,*b=NULL;
	a=sr(a);
	b=sr(b);
	jj(a,b);
	bj(a,b);
	return 0;
}
