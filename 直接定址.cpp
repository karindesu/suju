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
	key=num-50;
	return key;
}
int main(){
	int i,key;
	int num;
	char name[20],ip[50];
	while(1){

		printf("输入1.插入,0.结束\n");
				scanf("%d",&i);
		if(i==0)return 0;
		if(i==1){
			scanf("%d%s%s",&num,name,ip);
			key=hash(num);
			printf("key值为%d,对应散列表a[%d]",key,key);
		}
	}
}
