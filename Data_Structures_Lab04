#include<bits/stdc++.h>
using namespace std;
struct node{
int ID;
string IP;
struct node* next;
};
struct node *head=(struct node*) malloc(sizeof(struct node));
void addNode(int ID, string IP)
{
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->ID=ID;
    newnode->IP=IP;
    newnode->next=head->next;
    head->next=newnode;
    /*struct node* ptr=head->next;
    struct node* prev,prevr;
    while (ptr!=head)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=head;*/
}
void printNode()
{
    struct node* ptr;
    ptr=head->next;
    while (ptr!=head)
    {
        cout<<ptr->ID<<' '<<ptr->IP<<endl;
        ptr=ptr->next;
    }
}
int main()
{
    head->next=head;
    cout<<"Choose an option\n1.View List\n2.Add node\n3.Delete Node\n4.Find Distance between nodes\n5.Which node is closer?\n6.Exit\n";
    while(1)
    {
        int x;
        cin>>x;
        if (x==1)
        {
            printNode();
        }
        else if (x==2)
        {
            int x;
            string y;
            cout<<"Enter ID and IP\n";
            cin>>x>>y;
            addNode(x,y);
        }
        else if (x==3)
        {
            struct node* ptr;
            struct node* prev;
            ptr=head->next;
            int a;
            cout<<"Enter the ID of the node you want to delete:\n";
            cin>>a;
            while (ptr->ID!=a)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            prev->next=ptr->next;
            free(ptr);
        }
        else if (x==4)
        {
            int j=1;
            cout<<"Enter the 1st and 2nd IDs:\n";
            int p,q;
            cin>>p>>q;
            struct node* ptr1=head->next;
            while(ptr1!=head)
            {
                if (ptr1->ID==p)
                    break;
                ptr1=ptr1->next;
            }
            while(ptr1->ID!=q)
            {
                j++;
                ptr1=ptr1->next;
            }
            cout<<"The distance between 1st and 2nd IDs is "<<j<<endl;
        }
        else if (x==5)
        {
            cout<<"Enter the ID of the master node\n";
            int o;
            cin>>o;
            struct node* ptr=head->next;
            struct node* prev;
            struct node* header;
            //struct node
            while(ptr->ID!=o)
            {
                //prev=ptr;
                ptr=ptr->next;
            }
            header=ptr;
            ptr=header->next;
            /*while (ptr!=header)
            {
               // printf("%d %s\n",ptr->ID,ptr->IP);
                cout<<ptr->ID<<' '<<ptr->IP<<endl;
                ptr=ptr->next;
            }*/
            cout<<"Successfully changed master node to ID "<<o<<endl;
            cout<<"Enter the two nodes:\n";
            int p,q,r;
            cin>>p>>q;
            //struct node* ptr=head->next;
            while (ptr!=header)
            {
                if (ptr->ID==p)
                {
                    r=p;
                    break;
                }
                else if (ptr->ID==q)
                {
                    r=q;
                    break;
                }
                ptr=ptr->next;
            }
            cout<<r<<" is closer to the master node\n";
        }
        else if (x==6)
            break;
    }
}
