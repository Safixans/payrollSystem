#include <iostream>
#include "Classes.h"
#include "Overloading.h"
#include  <stdlib.h>
#include "string"

using namespace std;

int main() {
    cout << "Welcome to the PAYROLL SYSTEM !!!" << endl;
    cout << "There you can manage the data of your EMPLOYEES! " << endl;
    password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::app);
    password_file.seekg(0);
    password_file.read((char *) &c, sizeof(c));
    if (password_file.eof() != 0) {
        display_logo();
        cout << "Input the company's name: ";
        getline(cin,company_name);
        c.set_company_name(company_name);
        cout << "Input a password for admin: ";
        cin >> password;
        c.set_password(password);
        pension = getInput<double>("Input pension of the employees in percentage: ");
        c.set_pension(pension);
        tax = getInput<double>("Input tax of the employees in percentage: ");
        c.set_tax(tax);
        password_file.clear();
        password_file.seekp(0);
        password_file.write((char *) &c, sizeof(c));
        password_file.close();
        file.close();
    } else {
        password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::app);
        password_file.clear();
        password_file.seekg(0);
        password_file.read((char *) &c, sizeof(c));
        tax = c.get_tax();
        pension = c.get_pension();
        password_file.close();
    }
    cout << "===============================================" << endl;
    while (is_start) {
        system("clear");
        display_logo();
        option = getInput<int>("Are you an admin or an employee:\n"
                               "1.Employee.\n"
                               "2.Admin.\n"
                               "0.Exit.", 0, 2);
        switch (option) {
            case 1:
                system("clear");
                display_logo();
                is_position = true;
                while (is_position) {
                    system("clear");
                    display_logo();
                    option = getInput<int>("Choose one of the operations below:\n"
                                           "1.Search for a employee.\n"
                                           "2.Print paychecks.\n"
                                           "0.Return.", 0, 2);
                    switch (option) {
                        case 1:
                            is_continue = true;
                            while (is_continue) {
                                system("clear");
                                display_logo();
                                file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                cout << "Enter the employee's ID to search for: ";
                                cin >> ID;
                                file.clear();
                                file.seekg(0);
                                while (file.read((char *) &m, sizeof(m))) {
                                    if (m.get_ID() == ID) {
                                        is_found = true;
                                        cout << m;
                                    }
                                }
                                if (is_found == false) {
                                    cout << "The employee has not been found!" << endl;
                                }
                                is_found = false;
                                option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                if (option == 0) {
                                    is_continue = false;
                                }
                            }
                            file.close();
                            break;
                        case 2:
                            system("clear");
                            display_logo();
                            is_continue = true;
                            while (is_continue) {
                                system("clear");
                                file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                file_copy7.open("Copy7.dat", ios::in | ios::out | ios::binary | ios::app);
                                cout << "Enter the employee's ID to search for: ";
                                cin >> ID;
                                password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::app);
                                password_file.clear();
                                password_file.seekg(0);
                                password_file.read((char *) &c, sizeof(c));
                                file.clear();
                                file.seekg(0);
                                while (file.read((char *) &m, sizeof(m))) {
                                    if (m.get_ID() == ID) {
                                        is_found = true;
                                        Paycheck(m, c);
                                        if(m.get_net_income()==0){
                                            cout<<"The employee has not worked yet!"<<endl;
                                        }
                                        else {
                                            option = getInput<int>(
                                                    "Do you want to get your salary? Type 1 to pay or 0 to reject: ", 0,
                                                    1);
                                            if (option == 1) {
                                                m.reset();
                                                file_copy7.write((char *) &m, sizeof(m));
                                            } else {
                                                file_copy7.write((char *) &m, sizeof(m));
                                            }
                                        }
                                    } else {
                                        file_copy7.write((char *) &m, sizeof(m));
                                    }
                                }
                                if (is_found == false) {
                                    cout << "The employee has not been found!" << endl;
                                }
                                is_found = false;

                                password_file.close();
                                file.close();
                                file_copy7.close();
                                remove("Data.dat");
                                rename("Copy7.dat", "Data.dat");
                                option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                if (option == 0) {
                                    is_continue = false;
                                }

                            }
                            break;
                        case 0:
                            is_position = false;
                            break;
                    }
                }
                break;
            case 2:
                system("clear");
                display_logo();
                password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::app);
                password_file.clear();
                password_file.seekg(0);
                password_file.read((char *) &c, sizeof(c));
                cout << "Enter password: ";
                cin >> ask_password;
                if (ask_password == c.get_password()) {
                    password_file.close();
                    is_position = true;
                    while (is_position) {
                        option = getInput<int>(
                                "Choose one of the operations below:\n1.Input a new record.\n2.Update fixed details of a record.\n3.Delete a record.\n4.Search for a employee.\n5.Display all records.\n6.Update worked and absent hours.\n7.Add bonuses or deduction.\n8.Print paychecks.\n9.Reset the admin's password.\n0.Return.",
                                0, 9);
                        switch (option) {
                            case 1:
                                system("clear");
                                display_logo();
                                is_continue = true;
                                while (is_continue) {
                                    cin >> m;
                                    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                    file.write((char *) &m, sizeof(m));
                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                    if (option == 0) {
                                        is_continue = false;
                                    }
                                }
                                file.close();
                                break;
                            case 2:
                                system("clear");
                                display_logo();
                                is_continue = true;
                                while (is_continue) {
                                    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                    file_copy3.open("Copy3.dat", ios::in | ios::out | ios::binary | ios::app);
                                    cout << "Enter the employee's ID to search for: ";
                                    cin >> ID;
                                    file.clear();
                                    file.seekg(0);
                                    while (file.read((char *) &m, sizeof(m))) {
                                        if (m.get_ID() == ID) {
                                            is_found = true;
                                            Daily_hours_error:
                                            cout << "Current daily working hours: " << m.getWorkingHours() << endl;
                                            working_hours = getInput<double>("New daily working hours: ");
                                            if (working_hours <= 24) {
                                                m.setWorking_hours(working_hours);
                                            }
                                            else{
                                                cout << "People cannot work more than 24 hours in a day!" << endl;
                                                goto Daily_hours_error;
                                            }
                                            cout << "Current hourly salary: " << m.getHourPrice() << "$" << endl;
                                            hourly_salary = getInput<double>("New hourly salary: ");
                                            m.setHourPrice(hourly_salary);
                                            cout << "Current overtime hourly salary: " << m.getOvertimeSalary()
                                                 << "$"
                                                 << endl;
                                            overtime_salary = getInput<double>("New overtime hourly salary: ");
                                            m.setOvertimeSalary(overtime_salary);
                                            cout << "Current tax rate: " << c.get_tax() << "%" << endl;
                                            tax = getInput<double>("New tax in percentage: ");
                                            if (tax < 100) {
                                                c.set_tax(tax);
                                            }


                                            cout << "Current pension rate: " << c.get_pension() << "%" << endl;
                                            pension = getInput<double>("New pension in percentage: ");
                                            if (pension < 100) {
                                                c.set_pension(pension);
                                            }
                                            password_file.open("Password.dat",
                                                               ios::in | ios::out | ios::binary | ios::trunc);
                                            password_file.seekp(0);
                                            password_file.write((char *) &c, sizeof(c));
                                            file_copy3.write((char *) &m, sizeof(m));
                                            password_file.close();
                                        } else {
                                            file_copy3.write((char *) &m, sizeof(m));
                                        }
                                    }
                                    file.close();
                                    file_copy3.close();
                                    remove("Data.dat");
                                    rename("Copy3.dat", "Data.dat");
                                    if (is_found == false) {
                                        cout << "The employee has not been found!" << endl;
                                    }
                                    is_found = false;
                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                    if (option == 0) {
                                        is_continue = false;
                                    }
                                }
                                break;
                            case 3:
                                system("clear");
                                display_logo();
                                is_continue = true;
                                while (is_continue) {
                                    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                    file_copy.open("Copy.dat", ios::in | ios::out | ios::binary | ios::app);
                                    cout << "Enter the employee's ID to delete the record: ";
                                    cin >> ID;
                                    file.clear();
                                    file.seekg(0);
                                    while (file.read((char *) &m, sizeof(m))) {
                                        if (m.get_ID() != ID) {
                                            file_copy.write((char *) &m, sizeof(m));
                                        } else {
                                            is_found = true;
                                            cout << "Id " << ID << " has been found and deleted!" << endl;
                                        }
                                    }
                                    if (is_found == false) {
                                        cout << "The employee has not been found!" << endl;
                                    }
                                    is_found = false;
                                    file.close();
                                    file_copy.close();
                                    remove("Data.dat");
                                    rename("Copy.dat", "Data.dat");
                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                    if (option == 0) {
                                        is_continue = false;
                                    }
                                }
                                break;
                            case 4:
                                system("clear");
                                display_logo();
                                is_continue = true;
                                while (is_continue) {
                                    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                    cout << "Enter the employee's ID to search for: ";
                                    cin >> ID;
                                    file.clear();
                                    file.seekg(0);
                                    while (file.read((char *) &m, sizeof(m))) {
                                        if (m.get_ID() == ID) {
                                            is_found = true;
                                            cout << m;
                                        }
                                    }
                                    if (is_found == false) {
                                        cout << "The employee has not been found!" << endl;
                                    }
                                    is_found = false;
                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                    if (option == 0) {
                                        is_continue = false;
                                    }
                                }
                                file.close();
                                break;
                            case 5:
                                system("clear");
                                display_logo();
                                file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                file.seekg(0);
                                while (file.read((char *) &m, sizeof(m))) {
                                    cout << m;
                                }
                                file.close();
                                break;
                            case 6:
                                system("clear");
                                display_logo();
                                option = getInput<int>(
                                        "Which hours of the employee do you want to update?\n1.Worked hours.\n2.Absent hours.",
                                        1, 2);
                                switch (option) {
                                    case 1:
                                        system("clear");
                                        display_logo();
                                        option = getInput<int>("1. Add for Everyone.\n2. Add for Specific Person.", 1,
                                                               2);
                                        switch (option) {
                                            case 1:
                                                system("clear");
                                                display_logo();
                                                is_continue = true;
                                                while (is_continue) {
                                                    file.open("Data.dat",
                                                              ios::in | ios::out | ios::binary | ios::app);
                                                    file_copy1.open("Copy1.dat",
                                                                    ios::in | ios::out | ios::binary | ios::app);

                                                    worked_hours_adding:
                                                    worked_hours_for_adding = getInput<double>(
                                                            "How many hours your Employees Worked: ");
                                                    if (worked_hours_for_adding > 24) {
                                                        cout << "You cannot choose more than 24 hours!" << endl;
                                                        goto worked_hours_adding;
                                                    }
                                                    file.clear();
                                                    file.seekg(0);
                                                    while (file.read((char *) &m, sizeof(m))) {
                                                        if (worked_hours_for_adding > m.getWorkingHours()) {
                                                            m.overtime_hours +=
                                                                    worked_hours_for_adding - m.getWorkingHours();
                                                            m.worked_hours += m.getWorkingHours();
                                                        } else {
                                                            m.worked_hours += worked_hours_for_adding;
                                                        }
                                                        file_copy1.write((char *) &m, sizeof(m));
                                                    }
                                                    file.close();
                                                    file_copy1.close();
                                                    remove("Data.dat");
                                                    rename("Copy1.dat", "Data.dat");
                                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                                    if (option == 0) {
                                                        is_continue = false;
                                                    }
                                                }
                                                break;
                                            case 2:
                                                system("clear");
                                                display_logo();
                                                is_continue = true;
                                                while (is_continue) {
                                                    file.open("Data.dat",
                                                              ios::in | ios::out | ios::binary | ios::app);
                                                    file_copy3.open("Copy2.dat",
                                                                    ios::in | ios::out | ios::binary | ios::app);
                                                    cout << "Enter the employee's ID to search for: ";
                                                    cin >> ID;
                                                    file.clear();
                                                    file.seekg(0);
                                                    while (file.read((char *) &m, sizeof(m))) {
                                                        if (m.get_ID() == ID) {
                                                            is_found = true;
                                                            worked_hours_adding1:
                                                            cout << "Current worked hours: " << m.getWorked_hours()
                                                                 << endl;
                                                            worked_hours_for_adding = getInput<double>(
                                                                    "How many hours the Employee Worked: ");
                                                            if (worked_hours_for_adding > 24) {
                                                                cout << "You cannot choose more than 24!"
                                                                     << endl;
                                                                goto worked_hours_adding1;
                                                            }
                                                            if (worked_hours_for_adding > m.getWorkingHours()) {
                                                                m.overtime_hours +=
                                                                        worked_hours_for_adding -
                                                                        m.getWorkingHours();
                                                                m.worked_hours += m.getWorkingHours();
                                                            } else {
                                                                m.worked_hours += worked_hours_for_adding;
                                                            }
                                                            file_copy3.write((char *) &m, sizeof(m));
                                                        } else {
                                                            file_copy3.write((char *) &m, sizeof(m));
                                                        }
                                                    }
                                                    if (is_found == false) {
                                                        cout << "The employee has not been found!" << endl;
                                                    }
                                                    is_found = false;
                                                    file.close();
                                                    file_copy3.close();
                                                    remove("Data.dat");
                                                    rename("Copy2.dat", "Data.dat");
                                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                                    if (option == 0) {
                                                        is_continue = false;
                                                    }
                                                }
                                                break;
                                            default:
                                                cout << "Invalid choice! Try AGAIN!" << endl;
                                                break;

                                        }
                                        break;
                                    case 2:
                                        system("clear");
                                        display_logo();
                                        is_continue = true;
                                        while (is_continue) {
                                            file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                            file_copy4.open("Copy4.dat",
                                                            ios::in | ios::out | ios::binary | ios::app);
                                            cout << "Enter the employee's ID to search for: ";
                                            cin >> ID;
                                            file.clear();
                                            file.seekg(0);
                                            while (file.read((char *) &m, sizeof(m))) {
                                                if (m.get_ID() == ID) {
                                                    is_found = true;
                                                    cout << "Current absent hours: " << m.getAbsent_hours() << endl;
                                                    absent_hours_for_adding = getInput<double>(
                                                            "How many hours your Employee was absent?: ");
                                                    m.absent_hours += absent_hours_for_adding;
                                                    file_copy4.write((char *) &m, sizeof(m));
                                                } else {
                                                    file_copy4.write((char *) &m, sizeof(m));
                                                }
                                            }
                                            if (is_found == false) {
                                                cout << "The employee has not been found!" << endl;
                                            }
                                            is_found = false;
                                            file.close();
                                            file_copy4.close();
                                            remove("Data.dat");
                                            rename("Copy4.dat", "Data.dat");
                                            option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                            if (option == 0) {
                                                is_continue = false;
                                            }
                                        }
                                        break;
                                    default:
                                        cout << "Invalid choice! Try AGAIN!" << endl;
                                        break;
                                }
                                break;
                            case 7:
                                system("clear");
                                display_logo();
                                is_continue = true;
                                while (is_continue) {
                                    file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                    file_copy5.open("Copy5.dat", ios::in | ios::out | ios::binary | ios::app);
                                    cout << "Enter employee's ID to add bonuses or deductions: ";
                                    cin >> ID;
                                    file.clear();
                                    file.seekg(0);
                                    while (file.read((char *) &m, sizeof(m))) {
                                        if (m.get_ID() == ID) {
                                            is_found = true;
                                            option = getInput<int>("Input:\n1.Add bonuses.\n2.Add deductions.", 1,
                                                                   2);
                                            switch (option) {
                                                case 1:
                                                    system("clear");
                                                    display_logo();
                                                    cout << "Current amount of bonuses: " << m.getBonuses() << "$"
                                                         << endl;
                                                    bonuses = getInput<double>("Input the amount of bonus: ");
                                                    m.bonuses += bonuses;
                                                    file_copy5.write((char *) &m, sizeof(m));

                                                    break;
                                                case 2:
                                                    system("clear");
                                                    display_logo();
                                                    cout << "Current amount of deduction: " << m.get_deduction() << "$"
                                                         << endl;
                                                    deduction = getInput<double>("Input the amount of deduction: ");
                                                    m.deduction += deduction;
                                                    file_copy5.write((char *) &m, sizeof(m));
                                                    break;
                                                default:
                                                    cout << "Invalid choice! Try AGAIN!" << endl;
                                                    break;
                                            }

                                        } else {
                                            file_copy5.write((char *) &m, sizeof(m));
                                        }
                                    }
                                    if (is_found == false) {
                                        cout << "The employee has not been found!" << endl;
                                    }
                                    is_found = false;
                                    file.close();
                                    file_copy5.close();
                                    remove("Data.dat");
                                    rename("Copy5.dat", "Data.dat");
                                    option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                    if (option == 0) {
                                        is_continue = false;
                                    }
                                }
                                break;
                            case 8:
                                system("clear");
                                display_logo();
                                option = getInput<int>("1.Print for Everyone.\n2.Print for Specific Person.", 1, 2);
                                switch (option) {
                                    case 1:
                                        system("clear");
                                        display_logo();
                                        is_continue = true;
                                        while (is_continue) {
                                            file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                            file_copy_6.open("Copy6.dat",
                                                             ios::in | ios::out | ios::binary | ios::app);
                                            password_file.open("Password.dat",
                                                               ios::in | ios::out | ios::binary | ios::app);
                                            password_file.clear();
                                            password_file.seekg(0);
                                            password_file.read((char *) &c, sizeof(c));
                                            file.clear();
                                            file.seekg(0);
                                            while (file.read((char *) &m, sizeof(m))) {
                                                Paycheck(m, c);
                                                if(m.get_net_income()==0){
                                                    cout<<"The employee has not worked yet!"<<endl;
                                                }
                                                else {
                                                    option = getInput<int>(
                                                            "Do you want to pay for the employee? Type 1 to pay or 0 to reject: ",
                                                            0, 1);
                                                    if (option == 1) {
                                                        m.reset();
                                                        file_copy_6.write((char *) &m, sizeof(m));
                                                    } else {
                                                        file_copy_6.write((char *) &m, sizeof(m));
                                                    }
                                                }
                                            }
                                            password_file.close();
                                            file.close();
                                            file_copy_6.close();
                                            remove("Data.dat");
                                            rename("Copy6.dat", "Data.dat");
                                            option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                            if (option == 0) {
                                                is_continue = false;
                                            }
                                        }
                                        break;
                                    case 2:
                                        system("clear");
                                        display_logo();
                                        is_continue = true;
                                        while (is_continue) {
                                            file.open("Data.dat", ios::in | ios::out | ios::binary | ios::app);
                                            file_copy7.open("Copy7.dat",
                                                            ios::in | ios::out | ios::binary | ios::app);
                                            cout << "Enter the employee's ID to search for: ";
                                            cin >> ID;
                                            password_file.open("Password.dat",
                                                               ios::in | ios::out | ios::binary | ios::app);
                                            password_file.clear();
                                            password_file.seekg(0);
                                            password_file.read((char *) &c, sizeof(c));
                                            file.clear();
                                            file.seekg(0);
                                            while (file.read((char *) &m, sizeof(m))) {
                                                if (m.get_ID() == ID) {
                                                    is_found = true;
                                                    Paycheck(m, c);
                                                    if(m.get_net_income()==0){
                                                        cout<<"The employee has not worked yet!"<<endl;
                                                    }
                                                    else {
                                                        option = getInput<int>(
                                                                "Do you want to pay for the employee? Type 1 to pay or 0 to reject: ",
                                                                0, 1);
                                                        if (option == 1) {
                                                            m.reset();
                                                            file_copy7.write((char *) &m, sizeof(m));
                                                        } else {
                                                            file_copy7.write((char *) &m, sizeof(m));
                                                        }
                                                    }
                                                } else {
                                                    file_copy7.write((char *) &m, sizeof(m));
                                                }
                                            }
                                            if (is_found == false) {
                                                cout << "The employee has not been found!" << endl;
                                            }
                                            is_found = false;
                                            password_file.close();
                                            file.close();
                                            file_copy7.close();
                                            remove("Data.dat");
                                            rename("Copy7.dat", "Data.dat");
                                            option = getInput<int>("Enter:\n1.Repeat the task.\n0.Return.", 0, 1);
                                            if (option == 0) {
                                                is_continue = false;
                                            }

                                        }
                                        break;
                                    default:
                                        cout << "Invalid choice! Try AGAIN!" << endl;
                                        break;
                                }
                                break;
                            case 9:
                                system("clear");
                                display_logo();
                                password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::app);
                                password_file.seekg(0);
                                password_file.read((char *) &c, sizeof(c));
                                password_file.close();
                            Password_error:
                                cout << "The current password is: " << c.get_password() << endl;
                                cout << "Input a new password: ";
                                cin >> password1;
                                cout << "Input the new password again: ";
                                cin >> password2;
                                if (password1 != password2) {
                                    cout << "The passwords do not match! Try again!" << endl;
                                    goto Password_error;
                                } else if (password1 == password2) {
                                    c.set_password(password1);
                                    password_file.open("Password.dat", ios::in | ios::out | ios::binary | ios::trunc);
                                    password_file.seekp(0);
                                    password_file.write((char *) &c, sizeof(c));
                                    password_file.close();
                                }
                                break;

                            case 0:
                                is_position = false;
                                break;
                            default:
                                cout << "Invalid choice! Try AGAIN!" << endl;
                                break;
                        }
                    }
                } else {
                    password_file.close();
                    cout << "Wrong password for admin!" << endl;
                }
                break;
            case 0:
                is_start = false;
                system("clear");
                cout << "  _______ _                 _           __                       _               _   _                                                      \n"
                        " |__   __| |               | |         / _|                     (_)             | | | |                                                     \n"
                        "    | |  | |__   __ _ _ __ | | _____  | |_ ___  _ __   _   _ ___ _ _ __   __ _  | |_| |__   ___   _ __  _ __ ___   __ _ _ __ __ _ _ __ ___  \n"
                        "    | |  | '_ \\ / _` | '_ \\| |/ / __| |  _/ _ \\| '__| | | | / __| | '_ \\ / _` | | __| '_ \\ / _ \\ | '_ \\| '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ \n"
                        "    | |  | | | | (_| | | | |   <\\__ \\ | || (_) | |    | |_| \\__ \\ | | | | (_| | | |_| | | |  __/ | |_) | | | (_) | (_| | | | (_| | | | | | |\n"
                        "    |_|  |_| |_|\\__,_|_| |_|_|\\_\\___/ |_| \\___/|_|     \\__,_|___/_|_| |_|\\__, |  \\__|_| |_|\\___| | .__/|_|  \\___/ \\__, |_|  \\__,_|_| |_| |_|\n"
                        "                                                                          __/ |                  | |               __/ |                    \n"
                        "                                                                         |___/                   |_|              |___/                     " << endl;
                break;
        }
    }
    password_file.close();
    file.close();
    return 0;
}
