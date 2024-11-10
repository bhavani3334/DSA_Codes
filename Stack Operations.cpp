
#include<stdio.h>
#include<stdlib.h>
int *a;
int max,top=-1;
void push(int ele)
{
	if(top==max-1)
	{
		max=2*max;
    	printf("stack overflow so stack is resized and element is pushed\n");
		a=(int*)realloc(a,max*sizeof(int));		
	}
		a[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("stack underflow");
		return -999;
	}
	else
	{
		return(a[top--]);
	}	
}
void display()
{
	int i;
	if(top==-1)
		printf("stack is empty");
	else
	{
		printf("stack elements are");
		for(i=top;i>=0;i--)
			printf("%d\t",a[i]);
	}
}
int main()
{
	int choice,ele;
	printf("enter the value of max:");
	scanf("%d",&max);
	a=(int *)malloc(max*sizeof(int));
	while(1)
	{
	printf("\nenter your choice\n ");
	printf("1 for push\n 2 for pop\n 3 for display\n  4 for exit\n");
   	scanf("%d",&choice);
   	switch(choice)
   	{
   		case 1: 	printf("enter the element to be pushed");
   		            	scanf("%d",&ele);
   		            	push(ele);
   		            	break;
   		case 2:	ele=pop();
   			if(ele!=-999)
   				printf("deleted element is %d\n",ele);
   			break;
   		case 3:	display();
   			break;
   		case 4:	free(a);
		   		exit(0);
   		default:printf("invalid choice");
   	}
   }
}

