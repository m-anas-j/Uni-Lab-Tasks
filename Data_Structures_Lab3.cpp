#include<bits/stdc++.h>
int header, avail=1;
using namespace std;
int main()
{
    int coef[8]={0,0,0,2,-5,1,-3,0}, exp[8]={-1,0,0,8,3,1,0,0}, link[8]={3,2,7,4,5,6,0,0},x,y,k=header,choice;
    while(1){
            printf("\nEnter choice:\n1.View List\n2.Add Element\n3.Delete Element\n4.Sort\n5.Exit\n");
            scanf("%d",&choice);
    if (choice==1){
    int i=header;
    //for (int i=0;i<8;i++)
    while (link[i]!=0)
    {

        if (coef[i]==0)
            {
                i=link[i];
                continue;
            }
        else
            {
                if ((coef[i]!=1&&coef[i]!=0) && (exp[i]!=1&&exp[i]!=0))
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
                else if (coef[i]!=1 && exp[i]==1)
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
    }
    else if (choice==2){
    k=header;
    //Adding an element
    printf("\nEnter the new co-efficient and exponent\n");
    scanf("%d %d",&x,&y);
    while (link[k]!=0)
    {
        /*int temp1=k;
        k=link[k];
        if (k==0)
        {
            link[temp1]=avail;
            coef[avail]=x;
            exp[avail]=y;
            int temp=link[avail];
            link[avail]=0;
            avail=temp;
        }*/
        k=link[k];
    }
    int temp=link[avail];
    coef[avail]=x;
    exp[avail]=y;
    link[avail]=0;
    avail=temp;
    }
    //Exit
    else if (choice==5)
    break;
}
}
