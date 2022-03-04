/*Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.*/


#include<iostream>
using namespace std;
#define MAX 30
int stack[MAX];
int top=-1;

void push(int x)
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
    int arr[100],size,output[100],count=1;
    cout<<"ENTER THE SIZE OF YOUR ARRAY==>";
    cin>>size;
    cout<<"\nENTER THE ELEMENTS IN YOUR ARRAY\n";
    for(int i=0;i<size;i++)
    {
        cout<<"ENTER THE ELEMENT AT "<<i<<" INDEX==>";
        cin>>arr[i];
    }

    output[0]=-1;

    for(int i=1;i<size;i++)
    {
        push(arr[i-1]);
        if(arr[i]>stack[top])
        {
            output[count++]=stack[top];
        }
        if(arr[i]<=stack[top])
        {
            pop();
            if(arr[i]>stack[top])
            {
                output[count++]=stack[top];
            }
            else
            {
                output[count++]=-1;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        cout<<output[i]<<" ";
    }

}
