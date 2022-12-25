#include<iostream>
using namespace std;
class String
{
    public:      
    int length(char a[50])
    {
        int len =0;
        int i =0;
        while(a[i]!='\0')
        {
            len++;
            i++;   
        }
        return len;
    }

    void copy(char a[50])
    {
        char b[50];
        int i=0;
        while(a[i]!='\0')
        {
            b[i]=a[i];
            i++;
        }
        b[i]='\0';
        cout<<"Copied String :  ";
        for(int j=0;j<i;j++)
        {
            cout<<b[j];
        }
        cout<<"\n";

    }
    void concat(char a[50], char b[50])
    {
        int i = 0;
        while(a[i]!='\0')
        i++;
        for(int j=0;b[j]!='\0';j++ )
        {
            a[i]=b[j];
            i++;
        }
        a[i]='\0';
        cout<<"Concatenated String : ";
        for(int j=0;j<i;j++)
        {
            cout<<a[j];
        }
        cout<<"\n";
    }
    void reverse(char a[50])
    {
        int len = length(a);
        int i=0;
        char b[50];
        for(int j= len-1;j>=0;j--)
        {
          b[i]=a[j];
          i++;
        }
        b[i]='\0';
        cout<<"Reversed String :   ";
        for(int j=0;j<i;j++)
        {
            cout<<b[j];
        }
        cout<<"\n";
      bool flag = true;
      int k =0;
      while(b[k]!='\0')
      {
          if(a[k]!=b[k])
          flag= false;
          k++;
      }
      if(flag==true)
      cout<<"It is a PALLINDROME number\n ";
    }
    void compare(char a[50], char b[50])
    {
        int len1= length(a);
        int len2= length(b);
        if(len1==len2)
        {
			int i=0;
			while(a[i]==b[i] && a[i]!='\0')
				i++;
			if(a[i]>b[i])
				cout<<endl<<a<<" is greater  than "<<b<<endl;
			else if(a[i]<b[i])
				cout<<endl<<a<<" is less than "<<b<<endl;
			else
			  cout<<"\n"<<a<<" is equal to "<<b<<endl;
		}
        else if(len1>len2)
        cout<<endl<<a<<" is greater  than "<<b<<endl;
        else
        cout<<endl<<a<<" is less than "<<b<<endl;
    }
};

int main()
{
	char str[50],str2[50],c, str3[50],str4[50];
	String s1;   //Object of the class.
	int choice;
	do
	{
	cout<<"\nString Operations:\n1.length\n2.copy	\n3.concatenate\n4.Reverse\n5.Compare Strings\nEnter choice:";
	
	cin>>choice;
	switch(choice)
	{
	case 1:
	     cout<<"Enter String:";
	     cin>>str;
		cout<<"\nLength: "<<s1.length(str);
		break;
	case 2:
		cout<<"Enter String:";
		cin>>str3;
        s1.copy(str3);
		break;
	case 3:
        
		cout<<"Enter String:";
		cin>>str3;
        cout<<"\nEnter String to concatenate: ";
		cin>>str4;
		s1.concat(str3,str4);
		break;
	case 4:
		cout<<"Enter String:";
		cin>>str;
		s1.reverse(str);
		break;
	case 5:
		cout<<"Enter String:";
		cin>>str;
		cout<<"\nEnter another string : ";
		cin>>str2;
		s1.compare(str,str2);
		break;
	default:
		cout<<"Wrong choice"<<endl;
		break;
    }
    cout<<"\nDo you want to continue(y/n)"<<endl;
    cin>>c;
    }while(c=='y' || c=='Y');

    return 0;
}


