#include<stdio.h>
int main(){
	char a[]={"abcde"};
	int top=4;
	char b[5];
	int n=0,i,j=4;
	while((b[n]=getchar())!='\n')n++;
	for(i=0;i<n;i++){
		if(a[j]!=b[i]){
			printf("���ǺϷ��ĳ�ջ���С�");
			return 0; 
		}
		j--;
	}
	printf("�ǺϷ��ĳ�ջ���С�");
	return 0;
} 
