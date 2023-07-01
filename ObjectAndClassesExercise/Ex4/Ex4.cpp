#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    string m_strName;
    string m_strSurName;
    double m_dAverage;

public:

    Student(string strName, string strSurName, double dAverage)
        : m_strName(strName)
        , m_strSurName(strSurName)
        , m_dAverage(dAverage)
    {
    }

    ~Student()
    {
    }

    void print()
    {
        cout << m_strName << " " << m_strSurName<< " " << m_dAverage << endl;
    }

    const double getAverage()
    {
        return m_dAverage;
    }
};

double calculateTotalAverage(vector<Student>& oStudents)
{
    double dTotal = 0;

    for (size_t i = 0; i < oStudents.size(); i++)
    {
        dTotal += oStudents[i].getAverage();
    }

    return dTotal / oStudents.size();
}

int main()
{
    int nStudentsCount = 0;
    cin >> nStudentsCount;

    if (nStudentsCount <= 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
        
    vector<Student> oStudents;

    for (size_t i = 0; i < nStudentsCount; i++)
    {
        string strName, strSurName;
        double dAverage;

        cin >> strName >> strSurName >> dAverage;

        Student oStudent(strName, strSurName, dAverage);
        
        oStudents.push_back(oStudent);
        oStudent.print();
    }

    cout << calculateTotalAverage(oStudents) << endl;

    return 0;
}
