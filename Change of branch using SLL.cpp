#include<stdio.h>
#include<stdlib.h>
struct SLL
{
int usn;
char name[20];
char mode[20];
struct SLL *next;
};
typedef struct SLL node;
node *start=NULL;
node* createNode()
{
node *newnode;
newnode=(node*)malloc(sizeof(node));
printf("Enter the usn: \n");
scanf("%d",&newnode->usn);
printf("Enter the Name: \n");
scanf("%s",newnode->name);
printf("Enter the mode (Regular/Lateral/COB/COC): \n");
scanf("%s",newnode->mode);
newnode->next=NULL;
return newnode;
}
void insertend()
{
node *newnode,*temp;
newnode=createNode();
if(start==NULL)
{
start=newnode;
return;
}
temp=start;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}
void display()
{
node* temp=start;
if(start==NULL)
{
printf("list is empty\n");
return;
}
printf("Students in the class are:\n");
printf("USN\tNAME\tMode\n");
while(temp!=NULL)
{
printf("%d\t%s\t%s\n",temp->usn,temp->name,temp->mode);
temp=temp->next;
}
printf("\n");
}
void deletekey()
{
node *temp=start,*prev;
int key;
if(start==NULL)
{
printf("List is empty. Deletion is not possible.\n");
return;
}
printf("Enter the USN to be deleted: \n");
scanf("%d",&key);
if (start->usn == key)
{
}
else
{
start = start->next;
printf("Deleted USN: %d\n",temp->usn);
free(temp);
while(temp!=NULL && temp->usn!=key)
{
prev=temp;
temp=temp->next;
}
if(temp==NULL)
{
printf("USN is not found, so can't delete.\n");
return;
}
prev->next=temp->next;
printf("Deleted USN: %d\n",temp->usn);
free(temp);
}
}
int main()
{
	int choice,n,i;
while(1)
{
printf("\nEnter your choice:\n");
printf("1 for insert\n");
printf("2 for display\n");
printf("3 for delete students based on COC/COB\n");
printf("4 for adding students from lateral entry/COC/COB\n");
printf("5 for exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
case 4: printf("Enter the number of students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
insertend();
break;
case 2: display();
break;
case 3: deletekey();
break;
case 5: exit(0);
default:printf("Invalid chioce\n");
}
}
}
