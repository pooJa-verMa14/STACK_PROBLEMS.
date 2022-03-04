//Write a program for the evaluation of a Postfix expression.
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


int main(void)
{
    char postfix[100];
    int operand1,operand2,x;
    cout<<"ENTER YOUR POSTFIX EXPRESSION==>";
    gets(postfix);
    cout<<"YOUR POSTFIX EXPRESSION IS==>";
    puts(postfix);
    for(int i=0;i<strlen(postfix);i++)
    {
        if(isdigit(postfix[i]))
        {
            x=(int)(postfix[i] - '0');
            push(x);
        }
        else
        {
            operand2=pop();
            operand1=pop();
            switch(postfix[i])
            {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1/operand2); break;
            }
            

        }
    }
    cout<<stack[top];
}
