#include<iostream>
using namespace std;
struct node
{
    int num;
    int pow;
    node *next;
};
node * yay;

void addition(int newnum, int newpow);

void display();

int check(int newnum,int newpow);

int main()
{
    yay = new node;
    yay->next=NULL;
    while(1)
    {
        cout<<"Enter your choice\n1.Add an element\n2.View the expression\n3.Exit\n";
        int choice;
        cin>>choice;
        if (choice==1)
        {
            cout<<"Enter the number and its exponent\n";
            int newnum,newpow;
            cin>>newnum>>newpow;
            addition(newnum,newpow);
        }
        else if (choice==2)
            display();
        else break;
    }

}
void addition(int newnum, int newpow)
{
    if (check(newnum,newpow)==1)
        return;
    node *ptr=yay;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *newnode=new node;
    newnode->num=newnum;
    newnode->pow=newpow;
    newnode->next=ptr->next;
    ptr->next=newnode;
}
void display()
{
    node *ptr=yay->next;
    if (ptr==NULL)
        {
            cout<<"No expression to display\n";
            return;
        }
    while(ptr!=NULL)
    {
        if (ptr->pow>0 || ptr->pow<0)
        {
            if (ptr->num>=0)
            cout<<'+'<<ptr->num<<"x^"<<ptr->pow;
            else cout<<ptr->num<<"x^"<<ptr->pow;
        }
        else if (ptr->pow==0)
        {
            if (ptr->num>=0)
            cout<<'+'<<ptr->num;
            else cout<<ptr->num;
        }
        ptr=ptr->next;
    }
    cout<<endl;
}
int check(int newnum,int newpow)
{
    int flag=0;
    node *ptr=yay->next;
    while(ptr!=NULL)
    {
        if (ptr->pow==newpow)
        {
            ptr->num=ptr->num+newnum;
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    return flag;
}
