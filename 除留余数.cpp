#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
	int num;
	char name[20];
	char ip[50]; 
	int k;
}l; 
l txl[100];
int hash(int num){
	int key;
	key=num%100; 
	return key;
}
void cr(int num,char name[],char ip[],int key){
	int i=0;
	while(key+i<=100){
	if(txl[key+i].k==0){
		strcpy(txl[key+i].name,name);
		strcpy(txl[key+i].ip,ip);
		txl[key+i].num=num;
		txl[key+i].k=1;
		printf("插入散列表a[%d]中，%d %s %s\n",key+i,num,name,ip);
		return;
	}
	i++;
}
    i=-key;
    while(key+i<key){
    		if(txl[key+i].k==0){
		strcpy(txl[key+i].name,name);
		strcpy(txl[key+i].ip,ip);
		txl[key+i].num=num;
		txl[key+i].k=1;
				printf("插入散列表a[%d]中，%d %s %s\n",key+i,num,name,ip);
		return;
	}
	i++;
	}
} //线性探测法 
int main(){
	int i,key, num;
	char name[20],ip[50];
	for(i=0;i<=100;i++){
		txl[i].k=0;
	}
	while(1){

		printf("输入1.插入,2.查询,0.结束\n");
				scanf("%d",&i);
		if(i==0)return 0;
		if(i==1){
			scanf("%d%s%s",&num,name,ip);
			key=hash(num);
			cr(num,name,ip,key);
		}
	}
}
