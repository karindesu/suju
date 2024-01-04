#include<stdio.h> 
void CountSort(int arr[], int sz)
{
	int min = arr[0];
	int max = arr[0];
    int i;
	for (i = 0; i < sz; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int range = max - min + 1;

	int count[range];
	for(i=0;i<range;i++){
		count[i]=0;
	}

	for (int i = 0; i < sz; i++)
	{
		count[arr[i] - min]++;
	}

	i = 0;
	for (int j = 0; j < range; j++)
	{
		while (count[j]--)
		{
			arr[i] = j + min;
			i++;
		}
	}
}
int main(int argc, char * argv[]) {
    int i,a[10]={6,12,458,5,4,28,19,1230,9,47};
    CountSort(a, 10); 
    for(i=0; i<10; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
