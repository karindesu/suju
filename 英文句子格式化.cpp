#include<stdio.h>
int main(){
	char c[100];
	printf("ÇëÊäÈë×Ö·û´®:\n");
	gets(c);
	int q,i=0,j=0;
	while(c[i]!='\0'){
		q=0;
		if(c[i]==' '&&j==0){
		i++; 
		continue;
	}
		if(c[i]!=' '&&j==0)j++;
		while(c[i+q]==' '){
			q++;
			if(c[i+q]=='\0')
			{
			i=i+q;
			break;
		}
			if(c[i+q]!=' '){
				i=i+q-1;
			}
		}
		if(c[i]!='\0')printf("%c",c[i]);
		if(c[i]!='\0')i++;
	}
	return 0;
} 
