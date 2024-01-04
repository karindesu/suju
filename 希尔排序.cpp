#include<stdio.h>
int main(){
	int a[10]={6,12,458,5,4,28,19,1230,9,47};
	int n,m=10,i,j,b,q;
	n=m/2;
	while(n>0){
			for(i=0;i<m;i++)printf("%d ",a[i]);
			printf("\n"); 
		for(j=0;j<n;j++){
			for(i=j+n;i<m;i+=n){
				b=a[i];
				for(q=i-n;q>=0&&a[q]>b;q-=n){
					a[q+n]=a[q];
				}
				a[q+n]=b;
			}
		}
		n/=2;
	}
	for(i=0;i<m;i++)printf("%d ",a[i]);
	return 0;
} 
