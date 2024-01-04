#include<stdio.h>
int a[10]={6,12,458,5,4,28,19,1230,9,47},n=9;
void qs(int left,int right){
		if(left>right)return;
	int i=left,j=right,b,t;

	b=a[left];
	while(i!=j){
		while(a[j]>=b&&i<j){
			j--;
		}
		while(a[i]<=b&&i<j){
			i++;
		}
		if(i<j){
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=b;
	 	for(int w=left;w<=right;w++){
		printf("%d ",a[w]);
	}
	printf("\n");
	qs(left,i-1);
	qs(i+1,right);
}
int main(){
	qs(0,n);
	int i;
	for(i=0;i<=n;i++){
		printf("%d ",a[i]);
	}
}
