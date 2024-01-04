#include<stdio.h>
 int find( int* a, int* b, int len ) {
	int i = 0, j = 0, k = 0;
	for ( ; k < len-1; k++ ) {
		if ( a[i] < b[j] ) {
			i++;
		}
		else {
			j++;
		}
	}
	return (a[i] < b[j])? a[i]: b[j];
}
int main(){
	int c,a[5],b[5],len=5;
	int i;
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++){
		scanf("%d",&b[i]);
	}
	c=find(a,b,len);
    printf("%d",c);
    return 0;
}

