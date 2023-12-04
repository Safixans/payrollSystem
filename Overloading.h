#include <fstream>
#include "string"
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <limits>

using namespace std;

template<typename T>
T getInput(const string &prompt, int limitStart = 0, int limitEnd = 0) {
    while (true) {
        try {
            T input;
            cout << prompt << endl;
            cin >> input;

            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid Input");
            }

            if (typeid(T) == typeid(int)) {
                if (input < limitStart || input > limitEnd) {
                    throw runtime_error("Input is outside the allowed range");
                }
            } else if (typeid(T) == typeid(double)) {
                if (input < 0) {
                    throw runtime_error("Input must be non-negative");
                }
            }

            return input;
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
    }
}


string name, ID, company_name, password, ask_password, password1, password2;
bool is_start = true, is_continue, is_position = true, is_found = false;
double hourly_salary, deduction, working_hours, bonuses, pension, tax, overtime_salary, worked_hours_for_adding, absent_hours_for_adding;
int option;
fstream file, password_file, file_copy, file_copy1, file_copy3, file_copy4, file_copy5, file_copy_6, file_copy7, file_copy8;
Money m;
Company c;

void operator>>(istream &in, Money &m) {
    cout << "Input an employee's name: ";
    cin.ignore();
    getline(cin, name);
    ID_error:
    cout << "Input an ID of the employee: ";
    cin >> ID;
    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
    file.clear();
    file.seekg(0);
    while (file.read((char *) &m, sizeof(m))) {
        if (ID == m.get_ID()) {
            cout << "The employee with the ID already exists!" << endl;
            file.close();
            goto ID_error;
        }
    }
    file.close();
    m.set_Name(name);
    m.set_ID(ID);
    daily_working_hours:
    working_hours = getInput<double>("Input daily working hours of the employee: ");
    if (working_hours > 24) {
        cout << "People cannot work more than 24 hours in a day!" << endl;
        goto daily_working_hours;
    }
    m.setWorking_hours(working_hours);
    hourly_salary = getInput<double>("Input an hourly salary of the employee: ");
    m.setHourPrice(hourly_salary);
    overtime_salary = getInput<double>("Input an overtime hourly salary of the employee: ");
    m.setOvertimeSalary(overtime_salary);
}

void operator<<(ostream &out, Money &m) {
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<endl;
    out << "Name: " << m.get_Name() << endl;
    out << "ID: " << m.get_ID() << endl;
    out << "Daily working hours: " << m.getWorkingHours() << endl;
    out << "Hourly salary: " << m.getHourPrice() << "$" << endl;
    out << "Hourly overtime salary: " << m.getOvertimeSalary() << "$" << endl;
    out << "Overtime hours: " << m.getOvertime_hours() << endl;
    out << "Absent hours: " << m.getAbsent_hours() << endl;
    out << "Total worked hours: " << m.getWorked_hours() << endl;
    out << "Tax: " << c.get_tax() << "%" << endl;
    out << "Pension: " << c.get_pension() << "%" << endl;
    out << "Deduction: " << m.get_deduction() << "$" << endl;
    out << "Bonuses: " << m.getBonuses() << "$" << endl;
    out << "Salary: " << m.getSalary() << "$" << endl;
    out << "Total overtime Salary: " << m.getTotalOvertimeSalary() << "$" << endl;
    out << "Net deduction: " << m.get_net_deduction() << "$" << endl;
    out << "Net Income: " << m.get_net_income() << "$" << endl;
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout << endl;
}

void Paycheck(Money &m, Company &c) {
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<endl;
    cout << "Employee information:" << endl;
    cout<<endl;
    cout << "Name: " << m.get_Name() << endl;
    cout << "Employee ID: " << m.get_ID() << endl;
    cout << endl;
    cout << "Earnings:" << endl;
    cout<<endl;
    cout << "Regular hours: " << m.getWorked_hours() << endl;
    cout << "Rate: " << m.getHourPrice() << "$" << endl;
    cout << "Total Earnings: " << m.getSalary() << "$" << endl;
    cout << endl;
    cout << "Overtime:" << endl;
    cout<<endl;
    cout << "Overtime Hours: " << m.getOvertime_hours() << endl;
    cout << "Rate: " << m.getOvertimeSalary() << "$" << endl;
    cout << "Total Overtime: " << m.getTotalOvertimeSalary() << "$"
         << endl;
    cout << endl;
    cout << "Deductions:" << endl;
    cout<<endl;
    cout << "Taxes: " << c.get_tax() << "%" << endl;
    cout << "Retirement plan: " << c.get_pension() << "%" << endl;
    cout << "Total deductions: " << m.get_net_deduction() << "$"
         << endl;
    cout << endl;
    cout << "Net pay: " << m.get_net_income() << "$" << endl;
    cout << endl;
    cout << "Company name: " << c.get_company_name() << endl;
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<endl;
}
void display_logo(){
    cout<<"  _____            _____       _ _    _____           _                 \n"
          " |  __ \\          |  __ \\     | | |  / ____|         | |                \n"
          " | |__) |_ _ _   _| |__) |___ | | | | (___  _   _ ___| |_ ___ _ __ ___  \n"
          " |  ___/ _` | | | |  _  // _ \\| | |  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
          " | |  | (_| | |_| | | \\ \\ (_) | | |  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
          " |_|   \\__,_|\\__, |_|  \\_\\___/|_|_| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
          "              __/ |                          __/ |                      \n"
          "             |___/                          |___/                       "<<endl;
}
