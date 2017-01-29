#include<iostream>
#include<string>
using namespace std;
class emp{
    string name;
    int dob,salary;
    public:
    void set_salary(int passed_salary)
    {
        salary=passed_salary;
    }
    void set_dob(int passed_dob)
    {
        dob=passed_dob;
    }
    void set_name(string passed_name)
    {
        name=passed_name;
    }
    int get_salary()
    {
        return salary;
    }
    string get_name()
    {
        return name;
    }
};

int main()
{
    emp employee[3];
    for (int i=0;i<3;i++)
    {
        int a;
        string b;
        cin >> a;
        cin >> b;
        employee[i].set_salary(a);
        employee[i].set_name(b);
        //cout << employee[i].dob << endl;
        //cout << employee[i].salary;
    }
        for (int i=0;i<3;i++)
        {

            cout << employee[i].get_name() << employee[i].get_salary;
        }
}
