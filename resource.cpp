#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <list>

using namespace std;

class CPerson
{
private:
    string m_strName;
    int m_iAge;
    string m_strAddress;

public:
    CPerson(){};

    CPerson(string name, int age, string add)
    {
        m_strName = name;
        m_iAge = age;
        m_strAddress = add;
    }

    void set_m_strName(string name);
    void set_m_iAge(int age);
    void set_m_strAddress(string address);

    string get_m_strName();
    int get_m_iAge();
    string get_m_strAddress();
};

// setters
void CPerson ::set_m_strName(string name)
{
    m_strName = name;
}
void CPerson ::set_m_iAge(int age)
{
    m_iAge = age;
}
void CPerson ::set_m_strAddress(string address)
{
    m_strAddress = address;
}

// getters
string CPerson ::get_m_strName()
{
    return m_strName;
}
int CPerson ::get_m_iAge()
{
    return m_iAge;
}
string CPerson ::get_m_strAddress()
{
    return m_strAddress;
}

class CEmployee : public CPerson
{
private:
    int m_iEmpId;
    // date m_dtJoiningDate;
    double m_dSalary;
    string m_strDesignation;
    string m_strSkillSet;

public:
    CEmployee(){};

    void set_m_iEmpId(int id);
    void set_m_dSalary(double sal);
    void set_m_strDesignation(string desg);
    void set_m_strSkillSet(string skill);

    int get_m_iEmpId();
    double get_m_dSalary();
    string get_m_strDesignation();
    string get_m_strSkillSet();

    static void strgetline()
    {
        cin.clear();
        cin.sync();
    }

    static void display_reources(vector<CEmployee> vect)
    {

        cout << "\n\n\t\tResources Details \n\n";
        cout << "_________________________________________________________ \n\n";
        for (CEmployee c : vect)
        {
            cout << "Name : \t\t" << c.get_m_strName() << "\n";
            cout << "Age : \t\t" << c.get_m_iAge() << " \n";
            cout << "Address : \t" << c.get_m_strAddress() << " \n";
            cout << "Emp ID : \t" << c.get_m_iEmpId() << " \n";
            cout << "Salary : \t" << c.get_m_dSalary() << " \n";
            cout << "Designation : \t" << c.get_m_strDesignation() << " \n";
            cout << "Skill Set : \t" << c.get_m_strSkillSet() << " \n";
            cout << "\n--------------------------------------\n\n";
        }
    }
};

// setters
void CEmployee ::set_m_iEmpId(int id)
{
    m_iEmpId = id;
}

void CEmployee ::set_m_dSalary(double sal)
{
    m_dSalary = sal;
}

void CEmployee ::set_m_strDesignation(string desg)
{
    m_strDesignation = desg;
}

void CEmployee ::set_m_strSkillSet(string skill)
{
    m_strSkillSet = skill;
}

// getters
int CEmployee ::get_m_iEmpId()
{
    return m_iEmpId;
}

double CEmployee ::get_m_dSalary()
{
    return m_dSalary;
}

string CEmployee ::get_m_strDesignation()
{
    return m_strDesignation;
}

string CEmployee ::get_m_strSkillSet()
{
    return m_strSkillSet;
}

// vector's object sorted by salary(desc)
vector<CEmployee> sortedBySalary(vector<CEmployee> vect)
{

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i; j < vect.size(); j++)
        {
            CEmployee temp;
            if (vect[i].get_m_dSalary() < vect[j].get_m_dSalary())
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    return vect;
}

// vector's object sorted by Emp Id(desc)
vector<CEmployee> sortedByEmpId(vector<CEmployee> vect)
{

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = i; j < vect.size(); j++)
        {
            CEmployee temp;
            if (vect[i].get_m_iEmpId() < vect[j].get_m_iEmpId())
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
    return vect;
}

// Download functionality in csv file
void download_data_in_File(vector<CEmployee> &ve)
{
    fstream file;
    file.open("data.csv", ios_base::out);
    for (int i = 0; i < ve.size(); i++)
    {
        file << "Employee " << i << " details:\n";
        file << " Name : \t\t\t" << ve[i].get_m_strName() << endl;
        file << " Age : \t\t\t\t" << ve[i].get_m_iAge() << endl;
        file << " Address : \t\t\t" << ve[i].get_m_strAddress() << endl;
        file << " Emp Id : \t\t\t" << ve[i].get_m_iEmpId() << endl;
        file << " Salary : \t\t\t" << ve[i].get_m_dSalary() << endl;
        file << " Designation : \t\t" << ve[i].get_m_strDesignation() << endl;
        file << " Skill Set : \t\t" << ve[i].get_m_strSkillSet() << endl;
        file << "\n\n\n";
    }
    file.close();
}
int main()
{
    CEmployee e;          // object
    vector<CEmployee> ve; // vector
    ve.push_back(e);      // vector method

    int choice;
    do
    {
        cout << "\n\n\t\t ----------  Welcome :) ----------\n\n";
        cout << "\n 1. Add Resource ";
        cout << "\n 2. Display All Resources ";
        cout << "\n 3. Display Resources Sorted by Salary ";
        cout << "\n 4. Display Resources Sorted by Emp ID ";
        cout << "\n 5. Download Data in File ";
        cout << "\n 6. Exit \n\n";
        cout << "\n\tEnter your choice : ";
        cin >> choice;

        CEmployee emp1;

        // local variables
        string name1;
        string add1;
        int id1;
        double sal1;
        string desg1;
        string skill1;

        int age1;
        switch (choice)
        {
        case 1:
            CEmployee::strgetline();
            cout << "\n\n\t\t==== Enter your Info here ====\n\n";
            cout << "\nEnter name : ";
            getline(cin, name1);
            emp1.set_m_strName(name1);

            cout << "\nEnter age : ";
            cin >> age1;
            emp1.set_m_iAge(age1);

            cout << "\nEnter Address : ";
            CEmployee::strgetline();
            getline(cin, add1);
            emp1.set_m_strAddress(add1);

            cout << "\nEnter Emp ID : ";
            cin >> id1;
            emp1.set_m_iEmpId(id1);

            cout << "\nEnter Salary : ";
            cin >> sal1;
            emp1.set_m_dSalary(sal1);

            CEmployee::strgetline();
            cout << "\nEnter Designation : ";
            getline(cin, desg1);
            emp1.set_m_strDesignation(desg1);

            CEmployee::strgetline();
            cout << "\nEnter Skills : ";
            getline(cin, skill1);
            emp1.set_m_strSkillSet(skill1);
            ve.push_back(emp1);

            cout << "\n\n\t---- Resource added successfully :) ----";

            break;
        case 2:
            // Display all method
            CEmployee::display_reources(ve);
            break;
        case 3:
            // data sorted by salary (desc)
            ve = sortedBySalary(ve);
            CEmployee::display_reources(ve);
            break;
        case 4:
            // data sorted by Emp Id(desc)
            ve = sortedByEmpId(ve);
            CEmployee::display_reources(ve);
            break;
        case 5:
            //download data
            download_data_in_File(ve);
            break;
        case 6:
            exit(0);
            break;

        default:
            cout << "\n \tEnter a valid choice : \n\n";
            break;
        }
    } while (choice != 0);
}
