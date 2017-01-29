#include<stdio.h>
int a[16],b[16],c[16],d[16],e[16],j=-1,tmp;
int bin(int p,int q,int r)
{
    int i;
    j=r;
    for (i=q-1;i>=0;i--,j--)
    {
        if (p%2==0)
            a[j]=0;
        else a[j]=1;
        p=p/2;
    }
}
int AND(int x,int y)
{
    if (x==1&&y==1)
        return 1;
    else return 0;
}
int OR(int lol,int lel)
{
    if (lol==1||lel==1)
        return 1;
    else return 0;
}
int main()
{
    int age,sex,sib,kids,i,t,l,m,o;
    scanf("%d %d %d %d",&age,&sex,&sib,&kids);
    bin(age,7,6);    //converting all data to binary and packing them
    bin(sex,1,7);
    bin(sib,4,11);
    bin(kids,4,15);
   for (i=0;i<16;i++)
   {
       printf("%d",a[i]);
   }
   printf("\n");
   printf("Which data do you want to change?\n1.Age\n2.Sex\n3.Siblings\n4.Kids\n");
   scanf("%d",&o);
   printf("Enter the new data\n");
   scanf("%d",&t);
   if (o==1) {l=6;m=0;} //setting l=upper limit, m=lower limit
   else if (o==2) {l=7;m=7;}
   else if (o==3) {l=11;m=8;}
   else {l=15;m=12;}
   for (i=0;i<16;i++)   //Changing the bits to be changed to 0
   {
       if (i>=m&&i<=l)
        b[i]=0;
       else b[i]=1;
       c[i]=AND(a[i],b[i]);
   }
   for (i=15;i>=0;i--) //converting new data t to binary
   {
       if (t%2==0)
        d[i]=0;
       else d[i]=1;
       t=t/2;
   }
   if (o==1)
   {
       for (i=9;i>0;i--)
       {
           for (j=i-1;j<=14;j++)
           {
               d[j]=d[j+1];
               d[j+1]=0;
           }
       }
   }
   else if (o==2)
   {
       for (i=15;i>7;i--)
       {
           d[i-1]=d[i];
           d[i]=0;
       }
   }
   else if (o==3)
   {
       for (i=12;i>8;i--)
       {
           for (j=i-1;j<=14;j++)
           {
               d[j]=d[j+1];
               d[j+1]=0;
           }
       }
   }

   for (i=0;i<16;i++)
   {
       e[i]=OR(c[i],d[i]);
       printf("%d",e[i]);
   }
}
