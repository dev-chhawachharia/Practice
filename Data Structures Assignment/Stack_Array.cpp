#include<iostream>
using namespace std;
struct MyStack
{
    int *arr;
    int cap,top;
    MyStack(int c)
    {
        cap=c;
        arr = new int[c];
        top=-1;
    }
    void push(int x)
    {
        if(top==cap-1)
        {
            cout<<"Overflow\n";
        }
        else
        {
            top++;
            arr[top]=x;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Underflow\n";
            return -2;
        }
        else
        {
            int res = arr[top];
            top--;
            return res;
        }
    }
    int size()
    {
        return (top+1);
    }
    void display()
    {
        cout<<"Current stack: "<<endl;
        if(top!=-1){
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<endl;
            }
        }
        else
        cout<<"Empty Stack";
    }

};
int main()
{
    int sz;
    cout<<"Enter number of stack elements: ";
    cin>>sz;
    MyStack s(sz);
    int choice;
    do
    {
        cout<<"\nEnter 1.for Pushing element on stack.\nEnter 2. for Poping an element out of stack.\nEnter 3. to exit:  ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                int data1;
                cout<<"\nEnter Element to PUSH in Stack: ";
                cin>>data1;
                s.push(data1);
                s.display();
                break;
            }
            case 2:
            {
                int data2;
                data2 = s.pop();
                if(data2!=-2){
                    s.display();
                }
                break;
            }
            case 3:
            {
                exit(0);
                break;
            }
        
        default:
            cout<<"Invalid Input Try Again";
            break;
        }
    }while(choice!=3);
}
