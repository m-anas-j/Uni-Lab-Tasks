#include<bits/stdc++.h>
int header=1, avail=2,firstavailused=0;
using namespace std;
int main()
{
    int coef[9]= {0,0,0,0,2,-5,1,-3,0}, exp[9]= {0,-1,0,0,8,3,1,0,0}, link[9]= {0,4,3,8,5,6,7,0,0},x,y,k=header,choice;
    while(1)
    {
        printf("\nEnter choice:\n1.View List\n2.Add Element\n3.Delete Element\n4.Sort\n5.Exit\n");
        scanf("%d",&choice);
        if (choice==1)
        {
            int i=header;
            //for (int i=0;i<8;i++)
            while (i!=0)
            {

                if (coef[i]==0)
                {
                    i=link[i];
                    continue;
                }
                else
                {
                    if ((coef[i]!=1) && (exp[i]!=1&&exp[i]!=0))
                    {
                        if (coef[i]>0)
                            printf("+%dx^%d",coef[i],exp[i]);
                        else printf("%dx^%d",coef[i],exp[i]);
                    }
                    else if (coef[i]!=1 && exp[i]==1 )
                    {
                        if (coef>0)
                            printf("+%dx",coef[i]);
                        else printf("%dx",coef[i]);
                    }
                    else if (coef[i]!=1 && exp[i]==0 )
                    {
                        if (coef[i]>0)
                            printf("+%d",coef[i]);
                        else printf("%d",coef[i]);
                    }

                    else if (coef[i]==1 && (exp[i]!=1&&exp[i]!=0))
                    {
                        if (coef[i]>0)
                            printf("+x^%d",exp[i]);
                        else printf("x^%d",exp[i]);
                    }
                    else
                    {
                        if (coef[i]>0)
                            printf("+x");
                        else printf("x");
                    }
                }
                i=link[i];
            }
            /*while (link[i]!=0)
            {
                cout<<coef[i]<<'x'<<exp[i]<<' ';
                i=link[i];
            }*/
        }
        else if (choice==2)
        {
            int ptr=header;
            int pre,temp;
            //Adding an element
            if (avail==0)
            {
                cout<<"Insufficient Memory\n";
            }
            else
            {
                int flag=0;
                printf("\nEnter the new co-efficient and exponent\n");
                scanf("%d %d",&x,&y);
                coef[avail]=x;
                exp[avail]=y;
                while(ptr!=0)
                {
                    if (exp[ptr]==y)
                    {
                        coef[ptr]+=x;
                        exp[ptr]+=y;
                        flag=1;
                        break;
                    }
                    pre=ptr;
                    ptr=link[ptr];
                }
                if (flag==0)
                {
                    link[pre]=avail;
                    temp=link[avail];
                    link[avail]=0;
                    avail=temp;
                }
                else {}
            }
            firstavailused=ptr;
            if (firstavailused!=0)
            {
                avail=firstavailused;
                firstavailused=0;
            }
            cout<<"New avail "<<avail<<endl;
        }
        else if (choice==3)
        {
            //Deleting an element
            int ptr=header;
            int pre,temp;
            int newavail;
            printf("\nEnter the new co-efficient and exponent you want to delete\n");
            scanf("%d %d",&x,&y);
            //x=x*-1;
            while(ptr!=0)
            {
                if (coef[ptr]==x && exp[ptr]==y)
                {
                    coef[ptr]=0;
                    exp[ptr]=0;
                    link[pre]=link[ptr];
                    newavail=ptr;//5
                    int temp=link[avail];//3
                    link[avail]=newavail;//5
                    link[newavail]=temp;//3
                    //avail=newavail;
                    cout<<"Ptr value "<<ptr<<" Avail value "<<avail<<endl;
                    break;
                }
                pre=ptr;
                ptr=link[ptr];
            }


        }
        else if (choice==4)
        {
            //sorting the elements according to increasing order of coefficient
            int ptr1=header;
            int ptr2=header,pre=ptr2;
            ptr2=link[ptr2];
            cout<<"What do you want to sort by?\n1.By coefficient\n2.By exponent\n";
            int yay;
            cin>>yay;
            if (yay==1)
            {
                while(ptr1!=0)
                {
                    ptr2=header;
                    pre=ptr2;
                    ptr2=link[ptr2];

                    while(ptr2!=0)
                    {
                        if (coef[pre]>coef[ptr2])
                        {
                            int temp = coef[pre];
                            int temp2 = exp[pre];
                            coef[pre]=coef[ptr2];
                            exp[pre]=exp[ptr2];
                            coef[ptr2]=temp;
                            exp[ptr2]=temp2;
                        }
                        pre=ptr2;
                        ptr2=link[ptr2];
                    }
                    ptr1=link[ptr1];
                }
                cout<<"Sorted\n";
            }
            else if (yay==2)
            {
                while(ptr1!=0)
                {
                    ptr2=header;
                    pre=ptr2;
                    ptr2=link[ptr2];

                    while(ptr2!=0)
                    {
                        if (coef[pre]>coef[ptr2])
                        {
                            int temp = coef[pre];
                            int temp2 = exp[pre];
                            coef[pre]=coef[ptr2];
                            exp[pre]=exp[ptr2];
                            coef[ptr2]=temp;
                            exp[ptr2]=temp2;
                        }
                        pre=ptr2;
                        ptr2=link[ptr2];
                    }
                    ptr1=link[ptr1];
                }
            }
        }
        else break;
    }
}

