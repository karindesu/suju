#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list{
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
void cr(char num[],char name[],char ip[],int key){
	int i=0;
	while(key+i<=100){
	if(txl[key+i].k==0){
		strcpy(txl[key+i].name,name);
		strcpy(txl[key+i].ip,ip);
		strcpy(txl[key+i].num,num);
		txl[key+i].k=1;
		return;
	}
	i++;
}
    i=-key;
    while(key+i<key){
    		if(txl[key+i].k==0){
		strcpy(txl[key+i].name,name);
		strcpy(txl[key+i].ip,ip);
		strcpy(txl[key+i].num,num);
		txl[key+i].k=1;
		return;
	}
	i++;
	}
} //线性探测法 
void cx(char num[],char name[],char ip[],int key){
	if(txl[key].k==0)printf("不存在\n");
	int i=0,q=0;
	while(strcmp(txl[key+i].name,name)!=0){
		if(key+i<100&&q==0)i++;
		else if(key+i==100){
			i=-key;
			q=1;
		}else if(key+i<key)i++;
		else {
		printf("不存在\n");
		return;
	}
	}
	printf("%s %s %s",txl[key+i].ip,txl[key+i].name,txl[key+i].num); 
}//线性探测法 
int main(){
	int i,key;
	char num[14],name[20],ip[50];
	for(i=0;i<=100;i++){
		txl[i].k=0;
	}
	while(1){

		printf("输入1.插入,2.查询,0.结束\n");
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
	}
}
