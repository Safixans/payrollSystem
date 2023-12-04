#include <iostream>
#include <string>

using namespace std;

class Company {
protected:
    string company_name;
    string password;
    double tax;
    double pension;
public:
    void set_company_name(string name) {
        company_name = name;
    }

    void set_password(string password) {
        this->password = password;
    }

    string get_company_name() {
        return company_name;
    }

    string get_password() {
        return password;
    }

    void set_tax(double tax) {
        this->tax = tax;
    }

    void set_pension(double pension) {
        this->pension = pension;
    }

    double get_tax() {
        return tax;
    }

    double get_pension() {
        return pension;
    }
};

class Person {
protected:
    string Name;
    string ID;
public:
    void set_Name(string name) {
        Name = name;
    }

    void set_ID(string id) {
        ID = id;
    }

    string get_Name() {
        return Name;
    }

    string get_ID() {
        return ID;
    }
};

class Employee : public Person {
protected:
    double daily_hours;
    float per_hour_price;
    double overtime_salary;
    double total_overtime_salary;

public:
    double bonuses;
    double worked_hours;
    double overtime_hours;
    double absent_hours;

    void setWorking_hours(double Working_hour) {
        daily_hours = Working_hour;
    }

    void setOvertime_hours(double Overtime_hours) {
        overtime_hours = Overtime_hours;
    }

    void setAbsent_hours(double Absent_hours) {
        absent_hours = Absent_hours;
    }

    void setBonuses(double Bonuses) {
        bonuses = Bonuses;
    }

    void setWorked_hours(double Worked_hours) {
        worked_hours = Worked_hours;
    }

    void setHourPrice(double h) {
        per_hour_price = h;
    }

    void setOvertimeSalary(double h) {
        overtime_salary = h;
    }

    double getBonuses() {
        return bonuses;
    }

    double getWorked_hours() {
        return worked_hours;
    }

    double getOvertime_hours() {
        return overtime_hours;
    }

    double getOvertimeSalary() {
        return overtime_salary;
    }

    double getAbsent_hours() {
        return absent_hours;
    }

    double getWorkingHours() {
        return daily_hours;
    }

    double getHourPrice() { return per_hour_price; }


};


class Money : public Employee, public Company {

protected:
    double total_deduction;
    double net_income;
    double salary;
public:
    double deduction;

    Money() {
        worked_hours = 0;
        overtime_hours = 0;
        absent_hours = 0;
        bonuses = 0;
        net_income = 0;
        deduction = 0;
        total_deduction = 0;
    }


    void setSalary(double Salary) {
        salary = Salary;
    }

    void set_deduction(double d) {
        deduction = d;
    }

    double get_deduction() {
        return deduction;
    }

    double getSalary() {
        salary = worked_hours * per_hour_price;
        return salary;
    }

    void reset() {
        total_overtime_salary = 0;
        worked_hours = 0;
        overtime_hours = 0;
        bonuses = 0;
        total_deduction = 0;
        net_income = 0;
        salary = 0;
        deduction = 0;
    }

    double getTotalOvertimeSalary() {
        total_overtime_salary = overtime_hours * overtime_salary;
        return total_overtime_salary;
    }

    double get_net_deduction() {
        total_deduction = getSalary() * (tax / 100 + pension / 100) + deduction;
        return total_deduction;
    }

    double get_net_income() {
        net_income = getSalary() + bonuses + getTotalOvertimeSalary() - get_net_deduction();
        return net_income;
    }
};
