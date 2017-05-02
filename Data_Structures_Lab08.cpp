#include<bits/stdc++.h>
using namespace std;
int main()
{

    //int ar[20]={92,65,22,100,50};
    static int x=0;
    int ar[20];
    cout<<"How many values would you like to sort?";
    int num;
    cin>>num;
    cout<<"Enter the next value:\n";
    for (; x<num; x++)
    {
        cin>>ar[x];
    }
    int na[20];
    na[0]=ar[0];
    for (int i=1; i<num; i++)
    {
        int parent=i/2;
        int ptr=i;
        if (i%2==0) parent=0;
        na[i]=ar[i];
        while (na[parent]<na[ptr])
        {
            cout<<parent<<' '<<i<<endl;
            int temp=na[parent];
            na[parent]=na[ptr];
            na[ptr]=temp;
            ptr=parent;
            parent=ptr/2;
        }
    }
    /*for (int i=0;i<5;i++)
    {
        cout<<na[i]<<' ';
    }*/
    int n=num-1;
    int ptr=n;
    while(n)
    {
        int temp;
        temp=na[0];
        na[0]=na[n];
        na[n]=temp;
        n--;
        ptr=0;
        while((na[ptr]<na[2*ptr+1] && 2*ptr+1<=n) || (na[ptr]<na[2*ptr+2] && 2*ptr+2<=n))
        {
            if (2*ptr+1<=n && na[ptr]<na[2*ptr+1])
            {
                int tmp=na[ptr];
                na[ptr]=na[2*ptr+1];
                na[2*ptr+1]=tmp;
                if (2*ptr+1>n) break;
                ptr=2*ptr+1;
            }
            else if (2*ptr+2<=n && na[ptr]<na[2*ptr+2])
            {
                int tmp=na[ptr];
                na[ptr]=na[2*ptr+2];
                na[2*ptr+2]=tmp;
                if (2*ptr+2>n) break;
                ptr=2*ptr+2;
            }
        }
    }
    for (int i=0; i<num; i++)
    {
        cout<<na[i]<<' ';
    }
    /*while(1)
    {
        cout<<"Enter value number "<<x+1<<endl;
        cin>>ar[x];
        x++;
        cout<<"1. View tree\n2. Sort\n";
        int choice;
        cin>>choice;
        if (choice==2)
        {
            na[0]=ar[0];
            for (int i=1; i<x; i++)
            {
                int parent=i/2;
                int ptr=i;
                if (i%2==0) parent=0;
                na[i]=ar[i];
                while (na[parent]<na[ptr])
                {
                    int temp=na[parent];
                    na[parent]=na[ptr];
                    na[ptr]=temp;
                    ptr=parent;
                    parent=ptr/2;
                }
            }
            int n=x-2;
            int ptr=n;
            while(n)
            {
                int temp;
                temp=na[0];
                na[0]=na[n];
                na[n]=temp;
                n--;
                ptr=0;
                while((na[ptr]<na[2*ptr+1] && 2*ptr+1<=n) || (na[ptr]<na[2*ptr+2] && 2*ptr+2<=n))
                {
                    if (2*ptr+1<=n && na[ptr]<na[2*ptr+1])
                    {
                        int tmp=na[ptr];
                        na[ptr]=na[2*ptr+1];
                        na[2*ptr+1]=tmp;
                        if (2*ptr+1>n) break;
                        ptr=2*ptr+1;
                    }
                    else if (2*ptr+2<=n && na[ptr]<na[2*ptr+2])
                    {
                        int tmp=na[ptr];
                        na[ptr]=na[2*ptr+2];
                        na[2*ptr+2]=tmp;
                        if (2*ptr+2>n) break;
                        ptr=2*ptr+2;
                    }
                }
            }
            for (int i=0; i<=x; i++)
            {
                cout<<na[i]<<' ';
            }
        }
    }*/

}
