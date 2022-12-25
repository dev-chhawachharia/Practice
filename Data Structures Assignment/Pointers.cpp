#include<iostream>
using namespace std;
class String
{
    public:      
    int length(char *a)
    {
        int len =0;
        int i =0;
        while(*a!='\0')
        {
            len++;
            i++;
            a++;   
        }
        return len;
    }

    void copy(char b[50])
    {
        char *a;
        a=b;
        cout<<"Copied String :  ";
        while (*a!=0)
        {
           cout<<*a;
           a++;

        }
        cout<<"\n";
        

    }
    char concat(char *a , char *b)
    {
        while(*(++a));
        while ((*a++=*b++));     
        return *a;
    }
    void reverse(char *a)
    {
        char *p=a;
        char *s=a+length(a)-1;
        while(p<s){
            char tmp =  *p;
            *p++=*s;
            *s--= tmp;
        }
        if(s==a)
        cout<<"Palindrome Word"<<endl;
    }
    void compare(char *a, char *b)
    {
        int len1= length(a);
        int len2= length(b);
        if(len1==len2)
        {
			int i=0;
			while(*a==*b && *a!='\0')
				{
                    i++;
                    a++;
                    b++;
                }

			if(*a>*b)
				cout<<endl<<a<<" is greater  than "<<b<<endl;
			else if(*a<*b)
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
	char str[50],str2[50],c, str3[50],str4[50],d,e;
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
		d = s1.concat(str3,str4);
        cout<<"Concatenated String: "<<str3<<endl;
        break;
	case 4:
		cout<<"Enter String:";
		cin>>str;
		s1.reverse(str);
        cout<<"Reversed String: "<<str<<endl;
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


