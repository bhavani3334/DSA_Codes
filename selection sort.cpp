#include<stdio.h>
#include<stdlib.h>
void selectionsort(int a[],int n);
void selectionsort(int a[],int n)
{
	int i,j,pos,temp;
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
				pos=j;
		}
		if(i!=pos)
		{
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
}
int main()
{
	int *a,n,i;
	printf("enter the number of elements\n");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	selectionsort(a,n);
	printf("after sorting\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	free(a);
}
