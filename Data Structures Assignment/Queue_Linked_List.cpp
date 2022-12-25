#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next=NULL;
    }
};
struct Queue{
    Node *front , *rear;
    Queue()
    {
        front=NULL;
        rear = NULL;        
    }
    void enqueue(int x)
    {
        Node *temp = new Node(x);
        if(front==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"\nEmpty Queue, cannot Dequeue"<<endl;
            return;
        }
        Node *temp=front;
        front=front->next;
        if(front==NULL){rear=NULL;}
        delete temp;
    }
    void display()
    {
        Node *curr = front;
        if(curr==NULL){
            cout<<"\nEmpty Queue\n";
        }
        while(curr!=NULL)
        {
            cout<<curr->data;
            curr=curr->next;
        }
    }
};
int main()
{
    Queue q;
    int choice;
    do
    {
        cout<<"\nEnter 1.for adding element to queue.\nEnter 2. for removing an element from queue.\nEnter 3. to exit:  ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                int data1;
                cout<<"\nEnter Element to ADD in Queue: ";
                cin>>data1;
                q.enqueue(data1);
                q.display();
                break;
            }
            case 2:
            {
                q.dequeue();
                q.display();
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