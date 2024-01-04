#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	char num[14];
	char name[20];
	char ip[50]; 
	int k;
	struct list *next;
}l; 
l txl[100];
int hash(char num[14]){
	int key;
	key=(num[2]-'0')*10+num[10]-'0'; 
	return key;
}//数字分析法（取第三位和末尾两位数字）
void cr(char num[],char name[],char ip[],int key){
	l *q,*p;
	int i=0;//标记记入链表次数（无意义 
	if(txl[key].k==0){
		strcpy(txl[key].ip,ip);
		strcpy(txl[key].name,name);
		strcpy(txl[key].num,num);
		txl[key].k=1;
		printf("%d\n",i);
	}else{
		i++;
		q=(l*)malloc(sizeof(l));
		strcpy(q->ip,ip);
		strcpy(q->name,name);
		strcpy(q->num,num);
		q->k=1;
		q->next=NULL;
		if(txl[key].next==NULL){
			txl[key].next=q;
		}else{
			p=txl[key].next;
			i++;
			while(p->next!=NULL){
				i++;
				p=p->next;
			}
			p->next=q;
		}
		printf("%d\n",i);
	}
} 
void cx(char num[],char name[],char ip[],int key){
	l *p;
	int i=0;
	if(txl[key].k==0)printf("不存在\n");
	else{
		p=txl[key].next;
		if(strcmp(txl[key].ip,ip)==0&&strcmp(txl[key].name,name)==0)printf("位于散列表a[%d]",key);
		else{
			while(p!=NULL){
				i++;
				if(strcmp(p->ip,ip)==0&&strcmp(p->name,name)==0){
					printf("位于散列表a[%d].%d",key,i);
					return;
				}
				p=p->next;
			}
			printf("不存在");
		}
	}
}
void sc(char num[],char name[],char ip[],int key){
		l *p,*q;
	int i=0;
	if(txl[key].k==0)printf("不存在\n");
	else{
		p=txl[key].next;
		if(strcmp(txl[key].ip,ip)==0&&strcmp(txl[key].name,name)==0){
			if(p==NULL)txl[key].k=0;
			else{
						strcpy(txl[key].ip,p->ip);
		                strcpy(txl[key].name,p->name);
		                strcpy(txl[key].num,p->num);
		                p=p->next;
		                txl[key].next=p;
			}
								printf("删除成功\n"); 
		}
		else{
			q=&txl[key];
			while(p!=NULL){
				i++;
				if(strcmp(p->ip,ip)==0&&strcmp(p->name,name)==0){
					q->next=p->next;
					free(p);
					printf("删除成功\n"); 
					return;
				}
				q=q->next;
				p=p->next;
			}
			printf("不存在");
		}
	}
}
int main(){
	int i,key;
	char num[14],name[20],ip[50];
	for(i=0;i<=100;i++){
		txl[i].k=0;
	}
	while(1){

		printf("输入1.插入,2.查询,3.删除,0.结束\n");
				scanf("%d",&i);
		if(i==0)return 0;
		if(i==1){
			scanf("%s%s%s",num,name,ip);
			key=hash(num);
			cr(num,name,ip,key);
		}
		if(i==2){
			scanf("%s%s%s",num,name,ip);
			key=hash(num);
			cx(num,name,ip,key);
		} 
		if(i==3){
			scanf("%s%s%s",num,name,ip);
			key=hash(num);
			sc(num,name,ip,key);
		}
	}
}
