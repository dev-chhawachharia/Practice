#include<iostream>
#include<stack>
using namespace std;
int precedence(char x)
{
    if(x=='^')
    return 3;
    else if(x=='/')
    return 2;
    else if(x=='*')
    return 1;
    else if(x=='+' )
    return 0;
    else if(x=='-')
    return -1;
    else 
    return -2;
}
void intopost(string exp)
{
    char a;
    stack<char> s1;
    string result;
    for(int i=0;i<exp.length();i++)
    {
         a = exp[i];
    
        if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            result+=a;
        }
        else if(a=='(')
        {
            s1.push(a);            
        }
        else if(a==')')
        {
            while(s1.top()!='(')
            {
                result+=s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else
        {
            if(s1.empty())
            {
                s1.push(a);
            }
            else if(!s1.empty()&&precedence(a)>precedence(s1.top()))
            {
                s1.push(a);
            }
            else{
                while(!s1.empty()&&precedence(a)<precedence(s1.top()))
                {
                    result+=s1.top();
                    s1.pop();
                }
                s1.push(a);
            }
        }
    }

        while(!s1.empty())
        {
            result+=s1.top();
            s1.pop();
        }
        cout<<result<<endl;
}
void intopre(string exp)
{
    char a;
    stack<char> s1,result;
    string prefix;
    for(int i=0;i<exp.length();i++)
    {
         a = exp[i];
    
        if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
        {
            result.push(a);
        }
        else if(a=='(')
        {
            s1.push(a);            
        }
        else if(a==')')
        {
            while(s1.top()!='(')
            {
                result.push(s1.top());
                s1.pop();
            }
            s1.pop();
        }
        else
        {
            if(s1.empty())
            {
                s1.push(a);
            }
            else if(!s1.empty()&&precedence(a)>precedence(s1.top()))
            {
                s1.push(a);
            }
            else{
                while(!s1.empty()&&precedence(a)<precedence(s1.top()))
                {
                    result.push(s1.top());
                    s1.pop();
                }
                s1.push(a);
            }
        }
    }

        while(!s1.empty())
        {
            result.push(s1.top());
            s1.pop();
        }
        while(!result.empty())
        {
            prefix+=result.top();
            result.pop();
        }
        cout<<prefix<<endl;
}
int main()
{
    string inf;
    int choice;
    do
    {
        cout<<"\nEnter infix operation: ";
        cin>>inf;
        cout<<"Enter 1 to convert into Postfix.\nEnter 2 to convert into Prefix.\nEnter 3 to Exit: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"\nPostfix Operation: ";
                intopost(inf);
                break;
            }
            case 2:
            {
                cout<<"\nPrefix operation: ";
                intopre(inf);
                break;
            }
            case 3:
            {
                exit(0);
                break;
            }
            default:
            {
                cout<<"Invalid Input. Try again.";
                break;
            }

        }
    }while(choice!=3); 
}


