//Write a program that checks if an expression has balanced parentheses.

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

void pop()
{
    if(top==-1)
    {
        cout<<"STACK IS EMPTY";
    }
    else
    {
        top--;
    }
}

int main(void)
{
    char infix[100];
    cout<<"ENTER YOUR INFIX EXPRESSION==>";
    gets(infix);  //gets() works as cin function but drawback of cin is it consider space as end of the string but this issue is solved in gets()
    cout<<"YOUR INFIX EXPRESSION IS==>";
    puts(infix);  //puts() works as cout function + new line operator
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(' || infix[i]=='{')
        {
            push(infix[i]);
        }
        if(infix[i]==')')
        {
            if(stack[top]=='(')
            {
                pop();
            }
            
        }
        if(infix[i]=='}')
        {
            if(stack[top]=='{')
            {
                pop();
            }
            
        }
    }
    if(top==-1)
    {
        cout<<"YOUR INFIX EXPRESSION IS BALANCED\n";
    }
    else
    {
        cout<<"YOUR INFIX EXPRESSION IS NOT BALANCED\n";
    }


}
