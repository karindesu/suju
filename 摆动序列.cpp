#include<stdio.h>
int main(){
	int i,n=0,a[100],j=0;
	char c;
	while((c=getchar())!=']'){
		if(c>='0'&&c<='9'){
			a[n]=c-'0';
			n++;
		}
	}
	int b[n-1];
	for(i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
	}
	if(n<2)printf("�ǰڶ�����.");
	else if(n==2&&b[0]-b[1]!=0)printf("�ǰڶ�����.");
	else{
		for(i=0;i<n-2;i++){
			if(b[i]<0){
				if(b[i+1]<0){
					j++;
				}
			}else if(b[i]>0){
				if(b[i+1]>0){
					j++;
				}
			}else if(b[i]==0)j++; 
		}
		if(j==0)printf("�ǰڶ�����.");
		if(j!=0)printf("�ǰڶ����У���Ҫɾ��%d��Ԫ��.",j); 
	}
	return 0;
} 
