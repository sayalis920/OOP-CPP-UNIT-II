#include <iostream>
#include <string>
using namespace std;
class Employee {
protected:
int empId;
string name;
string department;

public:
Employee(int id, string n, string dept)
: empId(id), name(n), department(dept) {}

void displayBasicInfo() const {
cout << "ID: " << empId
<< " | Name: " << name
<< " | Department: " << department;
}

virtual double calculateSalary() const = 0;
virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
private:
double monthlySalary;
public:
FullTimeEmployee(int id, string n, string dept, double salary)
: Employee(id, n, dept), monthlySalary(salary) {}
double calculateSalary() const override {
return monthlySalary;
}

void display() const {
displayBasicInfo();
cout << " | Type: Full-Time | Salary: Rs. "
<< calculateSalary() << endl;
}
};

class PartTimeEmployee : public Employee {
private:
double hourlyRate;
int hoursWorked;
public:
PartTimeEmployee(int id, string n, string dept, double rate, int hours)
: Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours) {}

double calculateSalary() const override {
return hourlyRate * hoursWorked;
}
void display() const {
displayBasicInfo();
cout << " | Type: Part-Time | Salary: Rs. "
<< calculateSalary() << endl;
}
};
