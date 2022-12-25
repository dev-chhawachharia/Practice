#include<iostream>
using namespace std;
struct Queue{
    int size,cap;
    int *arr;
    Queue(int c)
    {
        size=0;
        cap=c;
        arr=new int[cap];
    }
    bool isFull()
    {
        return(size==cap);
    }
    bool isEmpty()
    {
        return(size==0);
    }
    void enqueue(int x)
    {
        if(isFull()){
            cout<<"\nQueue Full,Cannot add"<<endl;
            return;
        }
        arr[size]=x;
        size++;
    }
    void dequeue()
    {
        if(isEmpty()){
            cout<<"\nQueue Empty,Cannot remove"<<endl;
            return;
        }
        for(int i=0;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
    void display()
    {
        if(isEmpty()){
            cout<<"\nQueue Empty"<<endl;
            return;
        }
        cout<<"\nCurrent Queue: "<<endl;
        for(int i = 0; i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int sz;
    cout<<"Enter number of  elements: ";
    cin>>sz;
    Queue q(sz);
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


