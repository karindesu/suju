#include<stdio.h>
typedef struct sy{
	int i;
	int j;
	int num;
}s;
void xc(s a[],s b[],int x,int y,int n){
	int c[n][n];
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)c[i][j]=0;
	}
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(a[i].j==b[j].i){
				c[a[i].i][b[j].j]+=a[i].num*b[j].num;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(c[i][j]!=0)printf("{%d %d %d}\n",i,j,c[i][j]);
		}
	}
} 
void xj(s a[],s b[],int x,int y){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(a[i].i==b[j].i&&a[i].j==b[j].j){
				a[i].num+=b[j].num;
				b[j].num=0;
			}
		}
	}
	for(i=0;i<x;i++){
		printf("{%d %d %d}\n",a[i].i,a[i].j,a[i].num);
	}
	for(i=0;i<y;i++){
		if(b[i].num!=0)printf("{%d %d %d}\n",b[i].i,b[i].j,b[i].num);
	}
}
int main(){
	int i,n,x,y;
	printf("输入阶数n\n");
	scanf("%d",&n);
	printf("分别输入A，B矩阵中非零元素总数:\n");
	scanf("%d%d",&x,&y);
	s a[x],b[y];
	printf("按顺序输入A矩阵非零元素行，列坐标,数据:\n");
	for(i=0;i<x;i++){
		scanf("%d%d%d",&a[i].i,&a[i].j,&a[i].num);
	}
	printf("按顺序输入B矩阵非零元素行，列坐标,数据:\n");
	for(i=0;i<y;i++){
		scanf("%d%d%d",&b[i].i,&b[i].j,&b[i].num);
	}
	xc(a,b,x,y,n);
	xj(a,b,x,y);
	return 0;
}
 
