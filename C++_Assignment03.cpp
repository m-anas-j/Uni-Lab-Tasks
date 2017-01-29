#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class emp{
    int age,doj,moj,yoj;
    string name;
public:
    void set_doj(int passed_doj)
    {
        doj=passed_doj;
    }
    void set_moj(int passed_moj)
    {
        moj=passed_moj;
    }
    void set_yoj(int passed_yoj)
    {
        yoj=passed_yoj;
    }
    void set_name(string passed_name)
    {
        name=passed_name;
    }
    int get_yoj()
    {
        return yoj;
    }
};
class hrm{
    double salary,netsalary,incrm,total=0;
    int noy;
public:
    void set_salary(double passed_salary)
    {
        salary=passed_salary;
    }
    void set_incrm(double passed_incrm)
    {
        incrm=passed_incrm;
    }
    void set_noy(int passed_noy)
    {
        noy=passed_noy;
    }
    double get_salary()
    {
        return salary;
    }
    double get_incrm()
    {
        return incrm;
    }
    double calc_netsalary()
    {
        double x=salary, y=incrm;
        for (int j=1;j<=noy;j++)
        {
            x=x+x*y/100;
        }
        netsalary=x;
        return netsalary;
    }
    void set_netsalary(double net)
    {
        netsalary=net;
    }
    double get_netsalary()
    {
        return netsalary;
    }
};
int main()
{
    hrm rnk[3];
    emp emp[3];
    double x,y;
    string name;
    double total=0,average;
    int a;
    for (int i=0;i<3;i++)
    {
        cout<<"Enter the name, yoj, salary and increment of rank "<<i<<" employee"<<endl;
        cin>>name;
        emp[i].set_name(name);
        cin >> x;
        emp[i].set_yoj(x);
        cin >> x;
        rnk[i].set_salary(x);
        cin>>y;
        rnk[i].set_incrm(y);
        a=emp[i].get_yoj();
        a=2017-a;
        rnk[i].set_noy(a);
        total+=rnk[i].calc_netsalary();
    }
    printf("The average salary of the employees is %0.2lf",total/3);
    getchar();
    getchar();
}
