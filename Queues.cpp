#include<stdio.h>
#include<stdlib.h>
int *q;
int max,rear=-1,front=0,count=0;
void Enqueue()
{
int ele;
if(count==max)
printf("Queue overflow");
else
{
printf("Enter the element to be inserted\n");
scanf("%d", &ele);
rear=(rear+1)%max;
q[rear]=ele;
count++;
}
}
void Dequeue()
{
if(count==0)
printf("Queue underflow");
else
{
printf("Deleted ele is %d\n",q[front]);
front=(front+1)%max;
count--;
}
}
void display()
{
int i,k;
if(count==0)
printf("Queue is empty");
else
{
k=front;
for(i=0;i<count;i++)
{
printf("%d\n",q[k]);
k=(k+1)%max;
}
}
}
int main()
{
int choice,ele;
printf("Enter the size of the queue: ");
scanf("%d", &max);
q=(int *)malloc(max*sizeof(int));
while(1)
{
printf("\nEnter your choice\n ");
printf("1 for enqueue\n 2 for dequeue\n 3 for display\n 4 for exit\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: Enqueue();
 break;
 case 2: Dequeue();
 break;
 case 3: display();
 break;
 case 4: free(q);
exit(0);
 default: printf("Invalid choice.");
 }
 }
}

