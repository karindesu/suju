#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int num;
	struct list *next;
}l;
l *sr(l *a){
	l *q,*p;
	while(1){
		q=(l*)malloc(sizeof(l));
		scanf("%d",&q->num);
		if(q->num==0)break;
		q->next=NULL;
		if(a==NULL){
			a=q;
		}else p->next=q;
		p=q;
	}
	return a;
}
void cf(l *a){
	l *x1,*x=a,*y1,*y=a->next;
	a=a->next;
	int i=1;
	x1=x;
	y1=y;
	while(a->next!=NULL){

		a=a->next;
		if(i%2==1){
		x->next=a;
		x=x->next;
	}
	if(i%2==0){
		y->next=a;
		y=y->next;
	}
			i++;
}
x->next=NULL;
y->next=NULL;
printf("L1 = ");
for(;x1!=NULL;x1=x1->next){
	printf("%d",x1->num);
	if(x1->next!=NULL)printf("->");
}
printf("\nL2 = ");
for(;y1!=NULL;y1=y1->next){
	printf("%d",y1->num);
	if(y1->next!=NULL)printf("->");
}
}
int main(){
	l *a=NULL;
	a=sr(a);
	cf(a);
	return 0;
} 
