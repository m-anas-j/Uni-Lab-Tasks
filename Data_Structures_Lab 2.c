#include<stdio.h>
int lo,mid,hi,key;
int binSearch(int lo, int mid,int hi,int *a)
{
    if (lo>hi)
        return 0;
    if (key==a[mid])
    {
        return 1;
    }
    else if (key>a[mid])
    {
        lo=mid;
        mid=(lo+hi)/2;
        binSearch(lo,mid,hi,a);
    }
    else
    {
        hi=mid;
        mid=(lo+hi)/2;
        binSearch(lo,mid,hi,a);
    }
}
int main()
{
    int a[]={5,8,4,12,-5,98,45,55,23,11,78,68};
    int i,j,k,tmp,flag=0,flag2=0,choice,n,cnt;
    n=12;
    for (i=0;i<n;i++)
    {
        if (cnt==0)
        {
            printf("\nSorted at pass %d\n",i-1);
            break;
        }
        cnt=0;
        printf("\nPass %d\n",i);
        for (j=0;j<n-i;j++)
        {
            if (a[j]>a[j+1])
            {
                cnt++;
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
        for (j=0;j<n;j++)
        {
            printf("%d ",a[j]);
        }
    }
    printf("\nSorted order: ");
    for (i=0;i<12;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter the number to be found\n");
    //Binary search in iterative mode
    scanf("%d",&key);

    lo=0; hi=11; mid=(lo+hi)/2;
    printf("\nChoose how you want to run binary search:\n1. Iterative mode\n2. Recursive mode\n");
    scanf("%d",&choice);
    if (choice==1){
    while (lo<=hi)
    {
        if (key==a[mid])
            {
                flag=1;
                break;
            }
        else if (key>a[mid])
        {
            lo=mid+1;
            mid=(lo+hi)/2;
        }
        else
        {
            hi=mid-1;
            mid=(lo+hi)/2;
        }
    }
    if (flag)
        printf("Found");
    else printf("Not found");
    }

    //Binary search in recursive mode
    else {
    if(binSearch(lo,mid,hi,a))
        printf("Found");
    else printf("Not found");
    }
}
