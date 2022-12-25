#include<iostream>
using namespace std;

void display(int x[],int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(int x[],int n)
{
    bool swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped = false;
        for(int j =0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                swap(x[j],x[j+1]);
                swapped = true;
            }
        }
        cout<<"Array After Pass "<<i+1<<": ";
        display(x,n);
        if(swapped==false)
        break;
    }
}
int bsearch(int x[],int n,int data)
{
    int low = 0,high=n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(x[mid]==data)
        return mid;
        else if(x[mid]>data)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}
int main()
{   
    int len;
    cout<<"Enter number of elements to be sorted: ";
    cin>>len;
    int arr[len];
    cout<<"\nEnter Array Elements: ";
    for(int i =0;i<len;i++)
    cin>>arr[i];
    bubblesort(arr,len);
    cout<<"\nFinal Sorted array: ";
    display(arr,len);
    int x;
    cout<<"\nEnter element to search: ";
    cin>>x;
    int pos = bsearch(arr,len,x);
    if(pos!=-1)
    cout<<"\nElement present"<<endl;
    else
    cout<<"Element not present"<<endl;
}