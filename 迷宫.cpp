#include<stdio.h>
#include<string.h>
#define max 100
int map[max][max],map1[max][max];
int head,tail;
int next[4][2]={{0,1},{-1,0},{1,0},{0,-1}};	
int x1,y1,x2,y2;
int w,h;
struct node
{
	int x,y;
	int pre;
}q[max];
void bfs()
{
	int x,y,i;
	int zd=0;
	head=0;
	tail=1;
	q[tail].x=x1;
	q[tail].y=y1;
	q[tail].pre=-1;
	while(head<tail)
	{
		head++;
		for(i=0;i<4;i++)
		{
			x=q[head].x+next[i][0];
			y=q[head].y+next[i][1];
			if(x>=1&&x<=w&&y>=1&&y<=h&&map[y][x]==0)
			{
				tail++;
				q[tail].x=x;
				q[tail].y=y;
				q[tail].pre=head;
				map[y][x]=1;
				if(x==x2&&y==y2)
				{
					while(q[tail].pre!=-1){
						zd++;
						tail=q[tail].pre;
					}
                    printf("%d\n",zd);
					return;
				}
			}
		}
	}
	return;
}
int dg(int n,int m){
	int i=0,j,x,y;
	if(n==x2&&m==y2)return 1;
	for(j=0;j<4;j++){
		x=n+next[j][0];
		y=m+next[j][1];
	if(x>=1&&x<=w&&y>=1&&y<=h&&map1[y][x]==0){
		map1[y][x]=1;
		i=dg(x,y);
		if(i>0)return i+1;
	}
}
	return 0; 
}
int main()
{
	scanf("%d%d",&w,&h);
			
	char str;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
		{
			scanf(" %c",&str);
			if(str=='1')
			map1[i][j]=map[i][j]=1;
			else
			map1[i][j]=map[i][j]=0;
		}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	bfs();
	int zd;
	zd=dg(x1,y1);
	printf("%d",zd-1);
	return 0;
}

