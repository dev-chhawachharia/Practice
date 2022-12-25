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
void selectionsort(int x[],int n)
{    
    for(int i=0;i<n-1;i++)
    {
        int min_ind=i;
        for(int j=i+1;j<n;j++)
            if(x[j]<x[min_ind])
                min_ind=j;
        swap(x[min_ind],x[i]);
        cout<<"Array After Pass "<<i+1<<": ";
        display(x,n);          
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
    selectionsort(arr,len);
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