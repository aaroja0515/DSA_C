#include <stdio.h>
#include <ctype.h>
#define max 100
char stack[max];
int top=-1;

void push(char ch)
{
stack[++top]=ch;
}
char pop()
{
return stack[top--];
}

char peek()
{
return stack[top];
}

int isEmpty()
{
return top==-1;
}
int precedence(char ch)
{
switch(ch)
{
case '^':return 3;
case '*':return 2;
case '/':return 2;
case '+':return 1;
case '-':return 1;
default:return 0;
}
}
int main()
{
char infix[max],postfix[max];
int i=0,j=0;
printf("enter infix expression: ");
scanf("%s",infix);
while(infix[i]!='\0')
{
char ch=infix[i];
if(isalnum(ch))
{
postfix[j++]=ch;
}
else if(ch== '(')
{
push(ch);
}
else if(ch==')')
{
while(!isEmpty() && peek()!='(')
{
postfix[j++]=pop();
}
pop();
}
else
{
while(!isEmpty()&&
peek()!='(' &&
(precedence(peek())>precedence(ch)||
(precedence(peek())==precedence(ch)&&ch!='^')))
{
postfix[j++]=pop();
}
push(ch);
}
i++;
}
while(!isEmpty())
{
postfix[j++]=pop();
}
postfix[j++]='\0';
printf("postfix expression:%s\n",postfix);
return 0;
}


