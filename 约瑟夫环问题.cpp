#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *next;
}s;
int main(){
	int i=1,n=10;
	s *h=NULL,*q,*p;
	while(i<=n){
		q=(s*)malloc(sizeof(s));
		q->num=i;
		q->next=NULL;
		if(h==NULL){
			h=q;
		}else p->next=q;
		p=q;
		if(i==n)p->next=h;
		i++;
	}
	printf("淘汰顺序为:");
	while(h->next!=p){
		q=h->next;
		p=q->next;
		q->next=p->next;
		h=q->next;
		if(h->next!=p)printf("%d",p->num);
		else printf("\n最后剩下的人是%d",p->num);
		free(p);
}
return 0;
}
