#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz=0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next=head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if(head==NULL)
        {
            cout<<"\nUnderflow\n";
            return -1;
        }
        int res = head->data;
        Node *temp=head;
        head= head->next;
        delete temp;
        sz--;
        return res;
    }
    void display()
    {
        Node *curr = head;
        if(curr==NULL){
            cout<<"\nEmpty Stack\n";
        }
        while(curr!=NULL)
        {
            cout<<curr->data<<endl;
            curr=curr->next;
        }
    }
};
int main()
{
    MyStack s;
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
                if(data2!=-1){
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