//Develop a menu driven program demonstrating the following operations on a Stack:
//push(), pop(), isEmpty(), isFull(), display(), and peek().
//Note: Use either arrays or linked list to implement stack

#include<iostream>
using namespace std;
#define MAX 20
int stack[MAX];
int top=-1;

void push() //TO INSERT ELEMENT AT THE TOP OF THE STACK
{
    int x;
    cout<<"ENTER THE VALUE==>";
    cin>>x;

    if(top==MAX-1)
    {
        cout<<"\nSTACK IS FULL\n";
    }
    else
    {
        top++;
        stack[top]=x;
        cout<<"YOUR "<<x<<" IS PUSHED TO THE STACK\n";
    }
}

void pop()  //TO DELETE THE TOP MOST ELEMENT OF THE STACK
{
    int item;
    if(top==-1)
    {
        cout<<"STACK IS EMPTY\n";
    }
    else
    {
        item=stack[top];
        top--;
        cout<<"TOP ELEMENT OF YOUR STACK ("<<item<<") IS POPPED OUT\n";
    }
}

void peek() //TO KNOW WHAT IS THE TOP ELEMENT OF THE STACK
{
    if(top==-1)
    {
        cout<<"STACK IS EMPTY\n";
    }
    else
    {
        cout<<"TOP MOST ELEMENT OF THE STACK IS "<<stack[top]<<"\n";
    }
}

void ISempty()  //TO CHECK IF STACK IS EMPTY OR NOT
{
    if(top==-1)
    {
        cout<<"STACK IS EMPTY\n";
    }
    else
    {
        cout<<"STACK IS NOT EMPTY\n";
    }
}

void ISfull()  //TO CHECK IF STACK IS FULL OR NOT
{
    if(top==MAX-1)
    {
        cout<<"STACK IS FULL\n";
    }
    else
    {
        cout<<"STACK IS NOT FULL\n";
    }
}

void display() //TO DISPLAY ALL THE ELEMENTS OF STACK
{
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
}

int main(void)
{
    int ch;

    do
    {
        cout<<"**********MENU*************"<<endl;
        cout<<"| PRESS 0: TO PUSH        |\n| PRESS 1: TO POP         |\n| PRESS 2: TO PEEK        |\n| PRESS 3: TO ISEMPTY     |\n| PRESS 4: TO ISFULL      |\n| PRESS 5: TO DISPLAY     |\n| PRESS 4: TO EXIT        |\n";
        cout<<"***************************"<<endl;
        cout<<"Enter: ";
        void (*fptr[10])()={push,pop,peek,ISempty,ISfull,display};
        cin>>ch;
       (*fptr[ch])();
       cout<<endl;
    } while (ch!=6);
    
}
