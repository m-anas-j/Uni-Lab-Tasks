#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* parent;
    node* right;
    node *next;
};
int sz,deleted;
node *A;
node *B;
node *C;
node *D;
node *E;
node *F;
node *G;
node *H;
node *I;
node *J;
node *K;
node *root;
node *mystack;
void push(node *node)
{
    sz++;
    node->next=mystack->next;
    mystack->next=node;
}
void pop()
{
    sz--;
    node *ptr=mystack;
    ptr=ptr->next;
    mystack->next=ptr->next;
    cout<<ptr->data<<' ';
    //return ptr;
}
node *top()
{
    return mystack->next;
}
void recursiveIn(node* yaya)
{
    if (yaya==NULL)
        return;
    else
    {
        recursiveIn(yaya->left);
        cout<<yaya->data<<' ';
        recursiveIn(yaya->right);
    }
}
int main()
{
    mystack=new node;
    mystack->next=NULL;
    A=new node;
    B=new node;
    C= new node;
    D=new node;
    E=new node;
    F= new node;
    G=new node;
    H=new node;
    I=new node;
    J=new node;
    K=new node;
    A->data=65;
    A->left=B;
    A->right=C;
    B->left=D;
    B->parent=A;
    B->data=19;
    B->right=E;
    C->left=H;
    C->parent=A;
    C->data=74;
    C->right=I;
    D->left=NULL;
    D->right=NULL;
    D->parent=B;
    D->data=15;
    E->parent=B;
    E->left=F;
    E->right=G;
    E->data=28;
    F->parent=E;
    F->left=NULL;
    F->right=NULL;
    F->data=25;
    G->parent=E;
    G->left=NULL;
    G->right=NULL;
    G->data=57;
    H->parent=C;
    H->left=NULL;
    H->right=J;
    H->data=71;
    I->parent=C;
    I->left=NULL;
    I->right=K;
    I->data=81;
    J->parent=H;
    J->left=NULL;
    J->right=NULL;
    J->data=72;
    K->parent=I;
    K->left=NULL;
    K->right=NULL;
    K->data=88;
    node *root=A;
    node *current=root;
    while(1)
    {
        cout<<"\n1. Display sorted numbers\n2. Insert new number\n3. Recursive in-order display\n4. Delete a node\n";
        int choice;
        cin>>choice;
        if (choice==1)
        {
            current=root;
            while (current!=NULL)
            {
                push(current);
                //if (current->left==NULL)
                //{
                if (current->left==NULL && current->right==NULL)
                {
                    int flag=0;
                    pop();
                    if (sz==0) break;
                    node *ptr=top();
                    if (ptr->right!=NULL)
                    {
                        current=ptr->right;
                    }
                    else flag=1;
                    pop();
                    if (flag)
                    {
                        ptr=top();
                        current=ptr->right;
                        pop();
                    }
                }
                else if (current->left==NULL && current->right!=NULL)
                {
                    node *ptr=top();
                    current=ptr->right;
                    pop();
                }
                //}
                else current=current->left;
            }
        }
        else if (choice==2)
        {
            current=root;
            node* newnode=new node;
            cout<<"Insert the data you want to input\n";
            cin>>newnode->data;
            while(current!=NULL)
            {
                if (current->left==NULL && newnode->data<current->data)
                {
                    newnode->left=current->left;
                    newnode->right=NULL;
                    newnode->parent=current;
                    current->left=newnode;
                    break;
                }
                else if (current->right==NULL && newnode->data>current->data)
                {
                    newnode->right=current->right;
                    newnode->left=NULL;
                    newnode->parent=current;
                    current->right=newnode;
                    break;
                }
                else if (newnode->data<current->data)
                {
                    current=current->left;
                }
                else current=current->right;
            }
        }
        else if (choice==3)
        {
            recursiveIn(root);
        }
        else if (choice==4)
        {
            deleted=0;
            cout<<"\nEnter the number you want to delete\n";
            int num;
            cin>>num;
            current=root;
            while(current!=NULL)
            {
                if (num>current->data)
                    current=current->right;
                else if (num<current->data)
                    current=current->left;
                else if (num==current->data)
                {
                    if (current->left==NULL && current->right==NULL)
                    {
                        node *ptr=current->parent;
                        //ptr->right=NULL;
                        //ptr->left=NULL;
                        if (ptr->right->data==num)
                            {
                                //delete ptr->right;
                                ptr->right=NULL;
                                deleted=1;
                            }
                        else if (ptr->left->data==num)
                            {
                                //delete ptr->left;
                                ptr->left=NULL;
                                deleted=1;
                            }
                        else
                        {
                            ptr->left=NULL;
                            ptr->right=NULL;
                            deleted=1;
                        }
                        delete current;
                        break;
                        /*delete current;
                        current=NULL;
                        deleted=1;
                        break;*/
                    }
                    else if (current->left==NULL && current->right!=NULL)
                    {
                        current->data=current->right->data;
                        delete current->right;
                        current->right=NULL;
                        deleted=1;
                        break;
                    }
                    else if (current->left!=NULL && current->right==NULL)
                    {
                        current->data=current->left->data;
                        delete current->left;
                        current->left=NULL;
                        deleted=1;
                        break;
                    }
                    else
                    {
                        cout<<"yay\n";
                        node *ptr=current;
                        if (ptr->right!=NULL)
                            ptr=ptr->right;
                        else ptr=ptr->left;
                        if (ptr->left!=NULL)
                            ptr=ptr->left;
                        //else ptr=ptr->right;
                        int temp=current->data;
                        current->data=ptr->data;
                        ptr->data=temp;
                        current=current->right;
                        continue;
                    }
                }
            }
            if (deleted==0) cout<<"Number not found\n";
            else cout<<"Number found and deleted\n";
        }
        else break;
    }
}
