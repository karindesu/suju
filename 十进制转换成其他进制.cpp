#include<stdio.h>
typedef struct zhan{
	char a[100];
	int top;
}z;
z e,b,s;
void ejz(int n){
	if(n==0)return;
	e.a[e.top]=n%2+'0';
	e.top++;
	ejz(n/2);
}
void bjz(int n){
		if(n==0)return;
	b.a[b.top]=n%8+'0';
	b.top++;
	bjz(n/8);
}
void sljz(int n){
		if(n==0)return;
	if(n%16<=9&&n%16>=0)s.a[s.top]=n%16+'0';
	else{
		s.a[s.top]=n%16-10+'A';
	}
	s.top++;
	sljz(n/16);
}
int main(){
	int n;
	e.top=0;
	b.top=0;
	s.top=0;
	scanf("%d",&n);
	ejz(n);
	bjz(n);
	sljz(n);
	e.top--;
	b.top--;
	s.top--;
	printf("二进制：");
	for(;e.top>=0;e.top--){
		printf("%c",e.a[e.top]);
	}
	printf("\n八进制：");
		for(;b.top>=0;b.top--){
		printf("%c",b.a[b.top]);
	}
		printf("\n十六进制：");
		for(;s.top>=0;s.top--){
		printf("%c",s.a[s.top]);
	}
	return 0;
}
