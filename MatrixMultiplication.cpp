#include<stdio.h>
#include<stdlib.h>
#define MAX 50  //preprocessor directive (macro),replaces every instance of MAX with 50//
int main()
{
	int a[MAX][MAX],b[MAX][MAX],product[MAX][MAX];
	int arows,acolumns,brows,bcolumns;
	int i,j,k;
	int sum=0;
	//ask the user to enter the order of the matrix a//
	printf("Enter the number rows and columns of matrix a:");
	scanf("%d%d",&arows,&acolumns);     //reads the input from the user//
	//ask the user to enter the order of the matrix b//
	printf("Enter tne number rows and columns of matrix b:");
	scanf("%d%d",&brows,&bcolumns);
	if(acolumns!=brows)
	{
		printf("\n Multiplication not possible");
		exit(0);
	}
	else
	{
		//ask the user to enter the elements of matrix a//
		printf("Enter the elements of matrix a:\n");
		for(i=0;i<arows;i++)
		{
			for(j=0;j<acolumns;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		//ask the user to enter the elements of matrix b//
		printf("Enter the elements of matrix b:\n");
		for(i=0;i<brows;i++)
		{
			for(j=0;j<bcolumns;j++)
			{	
				scanf("%d",&b[i][j]);
			}
		}
		//displays the matrix a//
		printf("\n Matrix a\n");
		for(i=0;i<arows;i++)
		{
			printf("\n");
			for(j=0;j<acolumns;j++)
			{	
				printf("%d\t",a[i][j]);
			}
		}
		//displays the matrix b//
		printf("\n");
		printf("\n Matrix b\n");
		for(i=0;i<brows;i++)
		{
			printf("\n");
			for(j=0;j<bcolumns;j++)
			{
				printf("%d\t",b[i][j]);
			}
		}
		printf("\n");
		for(i=0;i<arows;i++)
		{
			for(j=0;j<bcolumns;j++)
			{
				for(k=0;k<brows;k++)
				{
					sum+=a[i][k]*b[k][j];
				}
				product[i][j]=sum;
				sum=0;
			}
		}
		//displays the product matrix//
		printf("\n");
		printf("\nResultant matrix:\n");
		for(i=0;i<arows;i++)
		{
			printf("\n");
			for(j=0;j<bcolumns;j++)
			{
				printf("%d\t",product[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
