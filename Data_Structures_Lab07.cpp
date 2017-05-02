#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *parent;
    struct node *right;
    struct node *next;
};

struct node *yay;
int sz;
void push(struct node* ptr)
{
        sz++;
        ptr->next=yay->next;
        yay->next=ptr;
}
struct node* pop()
{
        sz--;
        node *ptr=yay;
        ptr=ptr->next;
        yay->next=ptr->next;
        cout<<ptr->data<<' ';
        return ptr;
}
node* top()
    {
        return yay->next;
    }
int main()
{
    node *A=new node;
    node *B=new node;
    node *C=new node;
    node *D=new node;
    node *P=new node;
    node *Q=new node;
    node *R=new node;
    node *S=new node;
    node *L=new node;
    node *M=new node;
    node *N=new node;
    node *O=new node;
    node *X=new node;
    node *Y=new node;
    node *Z=new node;
    yay=new node;

    yay->next=NULL;
    A->data='A';
    A->left=B;
    A->right=C;
    B->data='B';
    B->left=D;
    B->parent=A;
    B->right=P;
    C->data='C';
    C->left=S;
    C->parent=A;
    C->right=L;
    D->data='D';
    D->left=NULL;
    D->parent=B;
    D->right=NULL;
    P->data='P';
    P->left=Q;
    P->parent=B;
    P->right=R;
    Q->data='Q';
    Q->left=O;
    Q->parent=P;
    Q->right=X;
    R->data='R';
    R->left=NULL;
    R->parent=P;
    R->right=NULL;
    S->data='S';
    S->left=NULL;
    S->parent=C;
    S->right=NULL;
    L->data='L';
    L->left=M;
    L->parent=C;
    L->right=N;
    M->data='M';
    M->left=Y;
    M->parent=L;
    M->right=Z;
    N->data='N';
    N->left=NULL;
    N->parent=L;
    N->right=NULL;
    O->data='O';
    O->left=NULL;
    O->parent=Q;
    O->right=NULL;
    X->data='X';
    X->left=NULL;
    X->parent=Q;
    X->right=NULL;
    Y->data='Y';
    Y->left=NULL;
    Y->parent=M;
    Y->right=NULL;
    Z->data='Z';
    Z->left=NULL;
    Z->parent=M;
    Z->right=NULL;
    node *root=A;
    node *current;
    current=root;
    while (current!=NULL)
    {
        push(current);
        current=current->left;
        if (current==NULL)
        {
            pop();
            node *ptr=top();
            if (ptr->right==NULL)
            {
                cout<<ptr->data;
                delete ptr;
                break;
            }
            pop();
            current=ptr->right;
        }
    }


}
