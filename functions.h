#ifndef FUNCTIONS_H // Header guard to prevent multiple includes
#define FUNCTIONS_H

#include <iostream>

class Account {
    private:
        double accountBalance;
        double monthlyIncome;
        double financialGoal;

    public:
        Account(double balance, double incomePerMonth, double goal) : accountBalance(balance), monthlyIncome(incomePerMonth), financialGoal(goal){}
        //
        double getBalance() {
            return accountBalance;
        }
        double getMonthlyIncome() {
            return monthlyIncome;
        }
        double getFinancialGoal() {
            return financialGoal;
        }
        //
        void setBalance(double bal) {
            accountBalance = bal;
        }
        void setMonthlyIncome(double income) {
            accountBalance = income;
        }
        void setGoal(double goal) {
            financialGoal = goal;
        }
        
        //
        int goalSeek(double separateGoal) {
            try
            {
                double tmp = (separateGoal - getBalance())/getMonthlyIncome();
                int months = (int) tmp;
                return months;
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error : " << e.what() << '\n';
                return 0;
            }
        }

        int goalSeek() {
            try
            {
                double tmp = (getFinancialGoal() - getBalance())/getMonthlyIncome();
                int months = (int) tmp;
                return months;
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error : " << e.what() << '\n';
                return 0;
            }
        }

        double calcMortgage() {
            return (32./100) * getMonthlyIncome();
        }
        double calcTransport() {
            return (10./100) * getMonthlyIncome();
        }
        double calcFood() {
            return (15./100) * getMonthlyIncome();
        }
        // Returns the total monthly expenditure based on what financial analysts say is the best for financial growth
        double totalExpenditure() {
            double expenditure = (calcTransport() + calcFood() + calcMortgage());
            return expenditure;
        }
};
#endif // End of header guard