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
}//���ַ�������ȡ����λ��ĩβ��λ���֣�
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
} //����̽�ⷨ 
void cx(char num[],char name[],char ip[],int key){
	if(txl[key].k==0)printf("������\n");
	int i=0,q=0;
	while(strcmp(txl[key+i].name,name)!=0){
		if(key+i<100&&q==0)i++;
		else if(key+i==100){
			i=-key;
			q=1;
		}else if(key+i<key)i++;
		else {
		printf("������\n");
		return;
	}
	}
	printf("%s %s %s",txl[key+i].ip,txl[key+i].name,txl[key+i].num); 
}//����̽�ⷨ 
int main(){
	int i,key;
	char num[14],name[20],ip[50];
	for(i=0;i<=100;i++){
		txl[i].k=0;
	}
	while(1){

		printf("����1.����,2.��ѯ,0.����\n");
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
