#include<stdio.h>
int main(){
	int n,i;
	while(1){
		printf("�����������ܽ��,����0��������\n");
		scanf("%d",&n);
		if(n==0){
			printf("�������");
			return 0;
	    }
	    i=n/25;
	    if(i!=0)printf("%d��25��",i);
	    n%=25;
	    i=n/5;
	    n=n%5;
	    if(i!=0)printf("%d��5��",i);
		i=n;
		if(i!=0)printf("%d��1��",i);
		printf("Ӳ�ҡ�\n"); 
	}
}
