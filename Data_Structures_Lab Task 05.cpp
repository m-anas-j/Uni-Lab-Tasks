#include<bits/stdc++.h>
using namespace std;
int top=-1;
string stck;
void push(char a);
void pop(char b);
void pop2(char b);
void checkexpr();
void conversion();
int precedence(char a, char b);
int main()
{
    char expr[100];
    int x;
    while(1){
    cout<<"Enter your choice:\n1.Check validity of expression\n2.Convert from infix to postfix\n3.Calculation\n4.Exit\n";
    cin>>x;
    if (x==1)
    {
        cout<<"Enter Expression\n";
        cin>>expr;
        for (int i=0;expr[i];i++)
        {
            if (expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
                    {
                        push(expr[i]);
                        cout<<"Pushing: "<<expr[i]<<endl;
                    }
            else if (expr[i]==')' || expr[i]=='}' || expr[i]==']')
                    {
                        pop(expr[i]);
                        cout<<"Popping: "<<expr[i]<<endl;
                    }
            else if (expr[i]>='A' && expr[i]<='z')
            {
                push(expr[i]);
                cout<<"Pushing: "<<expr[i]<<endl;
            }
        }
        checkexpr();
    }
    else if (x==2)
    {
        int k=0,m;
        cout<<"Enter Expression\n";
        cin>>expr;
        int j=0;
        char expr2[100], num;
        for (int i=0;expr[i];i++)
        {
            m=i;
            while(expr[m]>='0' && expr[m]<='9')
            {
                expr2[j]=expr[m];
                j++;
                m++;
                if (expr[m]>='0'&&expr[m]<='9')
                {
                    i++;
                    continue;
                }
                else
                {
                    expr2[j]=',';
                    j++;
                    break;
                }
            }

            if (expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
                        push(expr[i]);
            else if (expr[i]==')' || expr[i]=='}' || expr[i]==']')
            {
                while(1)
                {
                    if (stck[top]!='(')
                    {
                        expr2[j]=stck[top];
                        j++;
                        expr2[j]=',';
                        j++;
                        pop2(stck[top]);
                    }
                    else if (stck[top]=='(')
                    {
                        pop2(stck[top]);
                        break;
                    }
                }
            }
            else if (expr[i]>='0' && expr[i]<='9')
                continue;
            else
            {
                if (precedence(expr[i],stck[top])==1)
                    push(expr[i]);
                else
                {
                    expr2[j]=stck[top];
                    j++;
                    expr2[j]=',';
                    j++;
                    stck[top]=expr[i];
                }
            }

        }
        expr2[j-1]='\0'; //j-1 to replace the last comma with null character
        cout<<"Postifix form of the given expression: "<<expr2<<endl;
    }
    else if (x==3)
    {
        int k=0,l=0,m;
        char expr3[100];
        double stck2[100];
        char temp[100];
        cout<<"Enter the expression\n";
        cin>>expr3;
        for (int i=0;expr3[i];i++)
        {
            k=0;
            m=i;
            while(expr3[m]>='0' && expr3[m]<='9')
            {
                temp[k]=expr3[m];
                k++;
                m++;
                if (expr3[m]>='0'&&expr3[m]<='9')
                {
                    i++;
                    continue;
                }
                else
                {
                    temp[k]='\0';
                    stck2[l]=atoi(temp);
                    //cout<<stck2[l]<<endl;//print this line to check if all numbers are properly converted or not
                    l++;
                    break;
                }
            }
            //k=0;
            if (expr3[i]=='+')
            {
                stck2[l-2]=stck2[l-2]+stck2[l-1];
                stck2[l-1]=0;
                l--;
            }
            else if (expr3[i]=='-')
            {
                stck2[l-2]=stck2[l-2]-stck2[l-1];
                stck2[l-1]=0;
                l--;
            }
            else if (expr3[i]=='*')
            {
                stck2[l-2]=stck2[l-2]*stck2[l-1];
                stck2[l-1]=0;
                l--;
            }
            else if (expr3[i]=='/')
            {
                stck2[l-2]=stck2[l-2]/stck2[l-1];
                stck2[l-1]=0;
                l--;
            }
        }
        cout<<"The result is: "<<stck2[l-1]<<endl; //l-1 referring to stck[0]
    }
    else break;
}
}
void push(char a)
{
    top++;
    stck[top]=a;
}
void pop(char b)
{
    if (top==-1)
        cout<<"No expression given"<<endl;
    else
    {
        if (b==')')
        {
            if (stck[top]=='(')
            {
                stck[top]='\0';
                top--;
            }
        }
        else if (b=='}')
        {
            if (stck[top]=='{')
            {
                stck[top]='\0';
                top--;
            }
        }
        else if (b==']')
        {
            if (stck[top]=='[')
            {
                stck[top]='\0';
                top--;
            }
        }
    }
}
void checkexpr()
{
    if (top==-1)
        cout<<"Valid\n";
    else cout<<"Invalid\n";
}
int precedence(char a, char b) //a=scanned item, b= stck[top]
{
    if(a=='/')
        return 1;
    else if ((a=='*' || a=='/') && (b=='+' || b=='-'))
        return 1;
    else if (a=='/' && b=='*')
        return 1;
    else if (b=='(' || b=='{' || b=='[')
        return 1;
    else if ((a=='+' || a=='-') && (b=='+' || b=='-'))
        return 1;
    else if (a==b)
        return 1;
    else return 0;
}
void pop2(char b)
{
    if (top==-1)
        cout<<"No expression given"<<endl;
    else
        {
            stck[top]='\0';
            top--;
        }
}
