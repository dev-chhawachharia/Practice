#include<iostream>
using namespace std;
struct Node
{
    int id,age,salary;
    string name;
    Node *next;
    Node(int empid, int empage , int empsalary , string empname)
    {
        id=empid;
        age=empage;
        salary =empsalary;
        name = empname;
        next=NULL;
    }
};
Node *input(Node *head,int lid, int lage , int lsalary , string lname)
{
    Node *temp = new Node(lid,lage,lsalary,lname);
    if(head==NULL)
    {return temp;}
    Node *curr = head;
    while(curr->next!=NULL)
    {curr=curr->next;}
    curr->next=temp;
    return head;
}
void displayList(Node *head)
{
    Node *curr = head;
    cout<<"Employee Details: \n";
    if(curr==NULL) cout<<"Empty Record";
    while(curr!=NULL)
    {
        cout<<"\nName: "<<curr->name;
        cout<<"\nId: "<<curr->id;
        cout<<"\nAge: "<<curr->age;
        cout<<"\nSalary :"<<curr->salary;
        curr = curr->next;
        cout<<"\n\n\n";
    }
}
int count(Node *head)
{
    int number=0;
    Node *curr = head;
    while(curr!=NULL)
    {
        number++;
        curr=curr->next;
    }
    return number;
}
Node *insert(Node *head)
{
    int lpos;
    int number = count(head);
    cout<<"\nCurrent Number of Employees: "<<number;
    cout<<"Enter the position at which you want to record.\nFor Example\n1 if you want to enter at the beginning.\n"<<number<<"if you want insert at the end.\nPLease Note the position can only be between 1 and "<<number<<endl;
    cin>>lpos;
    while(lpos<=number)
    {       
        int lid,  lage , lsalary ;
        string lname;
        cout<<"Enter Details";
        cout<<"Name:  ";
        getline(cin>>ws,lname);
        cout<<"\nId:  ";
        cin>>lid;
        cout<<"\nAge:   ";
        cin>>lage;
        cout<<"\nSalary:  ";
        cin>>lsalary;
        Node *temp = new Node(lid,lage,lsalary,lname);
        if(lpos==1)
        {
            temp->next=head;
            return temp;
        }
        Node *curr = head;
        for(int i =1;i<=(lpos-2)&&curr!=NULL;i++)
        curr = curr->next;
        temp->next=curr->next;
        curr->next=temp;
        return head;
    }
    if(lpos>number)
    cout<<"Out of range TRY Again";
}   
Node *deleterec(Node *head,int lpos)
{
    
    int num = count(head);
    while (lpos!=-1 && lpos<num)
    {
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }
        Node *curr = head;
        for(int i = 1; i<=(lpos -3) && curr!=NULL;i++)
        curr = curr->next;
        Node *temp = curr;
        temp->next=temp->next->next;
        delete curr->next;
        return head;        
    }   
    if(lpos==num)
    {
        Node *temp = head;
        while(temp->next->next!=NULL)
        temp=temp->next;
        delete temp->next;
        temp->next=NULL;
    }
    else
    cout<<"Record not found"; 
}
Node *modify(Node *head,int lpos)
{
    
    int lid,  lage , lsalary ;
    string lname;
    while (lpos!=-1)
    {
        Node *curr = head;
        for(int i =1;i<=lpos-1 && curr!=NULL;i++)
        curr=curr->next;

        cout<<"\nEnter New Data\n";
        cout<<"Name:  ";
        getline(cin>>ws,lname);
        curr->name=lname;
        cout<<"\nId:  ";
        cin>>lid;
        curr->id=lid;
        cout<<"\nAge:   ";
        cin>>lage;
        curr->age=lage;
        cout<<"\nSalary:  ";
        cin>>lsalary;
        curr->salary=lsalary;
        cout<<"\nData Modified";
        return head;
    }   
    if(lpos==-1)
    cout<<"Record not found";
    

}
void displayrec(Node *head, int lpos)
{
    Node *curr = head;
    for(int i =1;i<=lpos-1 && curr!=NULL;i++)
    curr=curr->next;
    cout<<"\nDetails:\n";
    cout<<"\nName: "<<curr->name;
    cout<<"\nId: "<<curr->id;
    cout<<"\nAge: "<<curr->age;
    cout<<"\nSalary :"<<curr->salary;

}
int Search(Node *head)
{
    int pos=1;
    int lempid;
    cout<<"\nEnter ID to Search: ";
    cin>>lempid;
    Node *curr=head;
    while(curr!=NULL)
    {
        if(lempid == curr->id)
        break;
        pos++;
        curr=curr->next;
    }
    return pos;
}
int main()
{
    Node *head = NULL;
    int n,counter;
    int mid,mage,msalary;
    string mname;
    cout<<" Enter Number of Employees to enter:-  ";
    cin>>n;
    counter=1;
    cout<<"\n Enter Employee Details:\n";
    while(counter<=n)
    {           
        cout<<"Employee Number "<<counter<<":\n";
        cout<<"Name:  ";
        getline(cin>>ws,mname);
        cout<<"\nId:  ";
        cin>>mid;
        cout<<"\nAge:   ";
        cin>>mage;
        cout<<"\nSalary:  ";
        cin>>msalary;                
        head = input( head,mid,mage,msalary,mname);
        
        counter++;
    }
    displayList(head);
    cout<<"\nCurrent Number of Employees: "<<count(head);
    int choice;
    int mposm=0;
    int mposd=0;
    int mpos=0;

    do
    {
        cout<<"\nEnter 1 for Insertion of a New Record \nEnter 2 for Deletion of a Record \nEnter 3 to Modify a record \nEnter 4 to Search a particular record\nEnter 5 to EXIT  : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                head = insert(head);
                cout<<"Updated Recordss";
                displayList(head);
                cout<<"\nCurrent Number of Employees: "<<count(head);
                break;
            }
            case 2:
            {
                mposd = Search(head);
                head = deleterec(head,mposd);
                cout<<"Updated Recordss";
                displayList(head);
                cout<<"\nCurrent Number of Employees: "<<count(head);
                break;
            }
            case 3:
            {
                mposm = Search(head);
                head = modify(head,mposm);
                cout<<"Updated Recordss";
                displayList(head);
                cout<<"\nCurrent Number of Employees: "<<count(head);
                break;
            }
            case 4:
            {
                mpos= Search(head);
                if(mpos!=-1){
                cout<<"Record Found.\nFetching Data\nPrinting Data:\n\n";
                displayrec(head,mpos);
                }
                else{
                    cout<<"\nRecord Not found";
                }
                break;
            }
            case 5:
            {
            exit(0);
            break;
            }
            default :
            {
                cout<<"Invalid choice. Try Again";
                break;
            }
        }  
    } while (choice!=5);    
}

