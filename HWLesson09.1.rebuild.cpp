#include <iostream>
#include <cmath>
using namespace std;

void Calculate(double amount_of_credit, double interest_rate, int month) {
    double monthly_percentage = interest_rate / 100 / 12;
    double forvard_percentage = monthly_percentage + 1;
    double annuity_factor = (monthly_percentage * pow(forvard_percentage, month)) / (pow(forvard_percentage, month) - 1);
    double monthly_annuity_payment = annuity_factor * amount_of_credit;
    cout << "Monthly annuity payment:\t\t\t\t" << monthly_annuity_payment << endl;
    double ballance_of_the_loan = amount_of_credit - monthly_annuity_payment;
    double amount_paid = monthly_annuity_payment * (double)month;
    cout << "Amount payable for the period:\t\t\t\t" << amount_paid << endl;
    double month_procent = (amount_paid - amount_of_credit) / (double)month;
    cout << "////////////////////////////////////////////////////////////////////////\n";
    cout << "Month\t\t" << "Payment\t\t" << "Loan balance\t" << "Interest paid\t\n";
    for (int i = 1; i < month + 1; i++) {
        cout << i << "\t\t" << monthly_annuity_payment << "\t\t" << amount_paid - (monthly_annuity_payment * i) << "\t\t" << month_procent * i << endl;
    }
}

void Mortgage_calculation() {
    double initial_amount, amount_of_credit, interest_rate;
    int month;
    cout << "Enter the amount of the down payment:\t\t\t";
    cin >> initial_amount;
    cout << "Enter the loan amount:\t\t\t\t\t";
    cin >> amount_of_credit;
    cout << "Enter the interest rate of the loan:\t\t\t";
    cin >> interest_rate;
    cout << "Enter the loan repayment period (in month):\t\t";
    cin >> month;
    cout << "////////////////////////////////////////////////////////////////////////\n";
    amount_of_credit = amount_of_credit - initial_amount;
    cout << "Amount of credit:\t\t\t\t\t" << amount_of_credit << endl;
    Calculate(amount_of_credit, interest_rate, month);
}

void Early_payment() {
    double initial_amount, amount_of_credit, interest_rate;
    int month;
    cout << "Enter the amount of the loan balance:\t\t\t\t";
    cin >> amount_of_credit;
    cout << "Enter the interest rate of the loan:\t\t\t\t";
    cin >> interest_rate;
    cout << "Enter the balance of the loan repayment period (in month):\t";
    cin >> month;
    cout << "Enter the amount to pay:\t\t\t\t\t";
    cin >> initial_amount;
    cout << "////////////////////////////////////////////////////////////////////////\n";
    amount_of_credit = amount_of_credit - initial_amount;
    cout << "Loan balance amount:\t\t\t\t\t" << amount_of_credit << endl;
    Calculate(amount_of_credit, interest_rate, month);
}

void Period_cut_payment() {
    double initial_amount, amount_of_credit, interest_rate;
    int month;
    cout << "Enter the amount of the loan balance:\t\t\t\t";
    cin >> amount_of_credit;
    cout << "Enter the interest rate of the loan:\t\t\t\t";
    cin >> interest_rate;
    cout << "Enter the balance of the loan repayment period (in month):\t";
    cin >> month;
    cout << "Enter the amount to pay:\t\t\t\t\t";
    cin >> initial_amount;
    cout << "////////////////////////////////////////////////////////////////////////\n";
    double monthly_percentage = interest_rate / 100 / 12;
    double forvard_percentage = monthly_percentage + 1;
    double annuity_factor = (monthly_percentage * pow(forvard_percentage, month)) / (pow(forvard_percentage, month) - 1);
    double monthly_annuity_payment = annuity_factor * amount_of_credit;
    amount_of_credit = amount_of_credit - initial_amount;
    cout << "Loan balance amount::\t\t\t\t\t" << amount_of_credit << endl;
    int newmonth = amount_of_credit / monthly_annuity_payment;
    cout << "New loan term (month):\t\t\t\t\t" << newmonth << endl;
    Calculate(amount_of_credit, interest_rate, newmonth);
}


int main()
{
    cout << "\t\tMORTGAGE CALUCULATOR\n";
    cout << "Choice for calculation:\n" << "1. Loan calculation\n" << "2. Loan repayment calculation\n";
    int choise;
    cin >> choise;
    switch (choise)
    {
    case 1: {
        Mortgage_calculation();
    }
          break;
    case 2: {
        cout << "Choose one of the following early repayment options:\n" << "1. Payment reduction\n" << "2. Reducing the term\n";
        int choise;
        cin >> choise;
        switch (choise) {
        case 1: {
            Early_payment();
        }
              break;
        case 2: {
            Period_cut_payment();
        }
              break;
        default: {
            cout << "Menu item selection error!" << endl;
        }
               break;
        }
    }
          break;
    default: {
        cout << "Menu item selection error!" << endl;
    }
           break;
    }
    return 0;
}