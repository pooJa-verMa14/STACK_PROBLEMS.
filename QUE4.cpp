//Write a program to convert an Infix expression into a Postfix expression

#include<iostream>
#include<string.h>
using namespace std;
#define MAX 30
int stack[MAX];
int top=-1;

void push(char x)
{
    if(top==MAX-1)
    {
        cout<<"STACK IS FULL";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
int pop()
{
    int item;
    if(top==-1)
    {
        return 0;
    }
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}

int highprec(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}

int main(void)
{
    char infix[100],output[100],count=0;
    cout<<"ENTER YOUR INFIX EXPRESSION==>";
    gets(infix);  //gets() works as cin function but drawback of cin is it consider space as end of the string but this issue is solved in gets()
    cout<<"YOUR INFIX EXPRESSION IS==>";
    puts(infix);  //puts() works as cout function + new line operator
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                output[count++]=pop();
            }
            pop();
        }
        else if(isalnum(infix[i]))
        {
            output[count++]=infix[i];
        }
        else
        {
            while(highprec(infix[i])<=highprec(stack[top]))
            {
                output[count++]=pop();
            }
            push(infix[i]);
            

        }
    }
    while(top!=-1)
    {
        output[count++]=pop();
    }
    for(int i=0;i<count;i++)
    {
        cout<<output[i];
    }
    
}

