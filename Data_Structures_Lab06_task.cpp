#include<bits/stdc++.h>

using namespace std;

void quicksort(int L,int R);

int partitn(int L,int R);

int A[]={5,10,3,20,30,45,12,78,-5,6};

int pivot,loc,n=9;

int main()

{

    quicksort(0,n);

    for (int i=0;i<=n;i++)

    {

        cout<<A[i]<<' ';

    }

}

int partitn(int L, int R)

{

    pivot=L;

    int ptr=R;

    int loc;

    while (pivot!=ptr)

    {

        if((A[pivot]>A[ptr] && pivot<ptr) || (A[pivot]<A[ptr] && pivot>ptr))

        //if((A[pivot]>A[ptr]) || (A[pivot]<A[ptr]))

        {

            int temp=A[pivot];

            int temptr=ptr;

            A[pivot]=A[ptr];

            A[ptr]=temp;

            ptr=pivot;

            pivot=temptr;

        }

        if (ptr>pivot)

        {

            ptr--;

        }

        else if (ptr<pivot)

        {

            ptr++;

        }

    }

    return pivot;

 

}

void quicksort(int L, int R)

{

    if (R>L)

    {

        int loc=partitn(L,R);

        quicksort(L,loc-1);

        quicksort(loc+1,R);

    }

    else return;

}

