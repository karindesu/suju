#include<stdio.h>
int max(int i,int j)
{
	if(i>j) return i;
	else return j;
}
int min(int i,int j)
{
	if(i<j) return i;
	else return j;
}
int find(int i,int j)
{					
	if(i==j) return i;
	else return	find(max(i,j)/2,min(i,j));
}
int main()
{
	int m,n,k,i;
	printf("���볤��\n"); 
	scanf("%d",&k);
	int a[10000];
	printf("����ֵ\n"); 
	for(i=1;i<=k;i++)
		scanf("%d",&a[i]);
		printf("����i,j");
	scanf("%d %d",&m,&n);
	i=find(m,n);
	printf("%d %d\n",i,a[i]);
	return 0;
}

