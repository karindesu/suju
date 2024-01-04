#include<stdio.h>
int main(){
	int n,i;
	while(1){
		printf("请输入找零总金额,输入0结束程序\n");
		scanf("%d",&n);
		if(n==0){
			printf("程序结束");
			return 0;
	    }
	    i=n/25;
	    if(i!=0)printf("%d个25分",i);
	    n%=25;
	    i=n/5;
	    n=n%5;
	    if(i!=0)printf("%d个5分",i);
		i=n;
		if(i!=0)printf("%d个1分",i);
		printf("硬币。\n"); 
	}
}
