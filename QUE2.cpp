//Given a String, Reverse it using STACK. For example “data structure” should be
//output as “erutcurtsatad.”

#include<iostream>
#include<string.h>
using namespace std;
#define MAX 50
char stack[MAX];
int top=-1;


void push(char x)
{
    if(top==MAX-1)
    {
        cout<<"STACK IS FULL\n";
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i];
    }
}

int main(void)
{
    char string[100];
    cout<<"ENTER YOUR STRING==>";
    gets(string);    //gets() works as cin function but drawback of cin is it consider space as end of the string but this issue is solved in gets()
    cout<<"INITIALLY YOUR STRING IS==>";
    puts(string);    //puts() works as cout function + new line operator
    cout<<"YOUR REVERSED STRING IS==>";
    for(int i=0;i<strlen(string);i++)
    {
         push(string[i]);
    }
    display();
}
