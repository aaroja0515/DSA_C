#include <stdio.h>
#define MAX 5
int queue[MAX];
int front =-1,rear=-1;
void enqueue(int item)
{
if((rear+1)%MAX==front)
{
printf("queue overflow\n");
return;
}
if(front==-1){
front=rear=0;
}
else
{
rear=(rear+1)%MAX;
}
queue[rear]=item;
printf("value entered=%d\n",item);
}
void dequeue(){
int item;
if(front==-1)
{
printf("queue underflow\n");
return;
}
item=queue[front];
if(front==rear)
{
front=rear=-1;
}
else
{
front=(front+1)%MAX;
}
printf("deleted value=%d\n",item);
}
void display()
{
int i;
if(front==-1)
{
printf("queue is Empty\n");
return;
}
printf("circular queue:");
i=front;
while(1)
{
printf("%d\t",queue[i]);
if(i==rear)
break;
i=(i+1)%MAX;
}
printf("\n");
}
int main()
{
int choice,item;
while(1)
{
printf("\n circular queue\n");
printf(" 1.enqueue\n");
printf(" 2.dequeue\n");
printf(" 3.display\n");
printf(" 4.exit\n");

printf("enter your choice");
scanf("%d",&choice);
switch(choice){

case 1:
printf("enter element");
scanf("%d",&item);
enqueue(item);
break;

case 2:
dequeue();
break;

case 3:
display();
break;

case 4:
return 0;

default:
printf("invalid choice\n");
}
}
}


