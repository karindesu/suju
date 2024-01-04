#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
	char num[14];
	char name[20];
	char ip[50]; 
	int k;
}l; 
l txl[100];
int hash(char num[14]){
	int key;
	key=(num[2]-'0')*10+num[10]-'0'; 
	return key;
}//数字分析法（取第三位和末尾两位数字）
int pf(int key){
	int i=1;
	if(txl[key].k==0)return key;
	while(key+i*i<=100){
		if(txl[key+i*i].k==0)return key+i*i;
		if(txl[key-i*i].k==0)return key-i*i;
		i++;
	}
	return 101;
}//平方探测法 
void cr(char num[],char name[],char ip[],int key){
	int k; 
	k=pf(key);
	if(k!=101){
		printf("%d",k);
		strcpy(txl[k].ip,ip);
		strcpy(txl[k].name,name);
		strcpy(txl[k].num,num);
		txl[k].k=1;
	}
} 

int main(){
	int i,key;
	char num[14],name[20],ip[50];
	for(i=0;i<=100;i++){
		txl[i].k=0;
	}
	while(1){

		printf("输入1.插入,0.结束\n");
				scanf("%d",&i);
		if(i==0)return 0;
		if(i==1){
			scanf("%s%s%s",num,name,ip);
			key=hash(num);
			cr(num,name,ip,key);
		}
	}
}
