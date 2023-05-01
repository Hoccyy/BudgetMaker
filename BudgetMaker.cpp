#include "functions.h"

int main(){
    double goalInput;
    double incomeInput;
    double balanceInput;    // Financial variables created


    printf("\nEnter your balance : $ ");
    scanf ("%lf", &balanceInput);

    printf("\nEnter your monthly income : $ ");
    scanf ("%lf", &incomeInput);

    printf("\nEnter your goal : $ ");
    scanf ("%lf", &goalInput);

    // Stores user info in an Account object
    Account userAccount(balanceInput, incomeInput, goalInput);

    // Goal seek test of the default goalseek function if you wish to have a separate goal
    int goalSeekTempval = userAccount.goalSeek(); // Storing temporarily to avoid multiple calls

    if (goalSeekTempval > 0) {
        if (goalSeekTempval > 12) {
            printf ("%d Months or %d years needed to achieve your goal!\n", goalSeekTempval, (goalSeekTempval / 12));
        }
        else {
            std::cout << goalSeekTempval << " Months needed to achieve your goal.\n" << std::endl;
        }
    }
    else {
        std::cout << "Sufficient funds OR 1 month for goal.\n" << std::endl;
    }
    
    // Expenditure allowance calculation
    std::cout << "\nTotal expenditure-: $ " << userAccount.totalExpenditure() << std::endl;
    std::cout << "Remaining monthly funds-: $ " << userAccount.getMonthlyIncome() - userAccount.totalExpenditure() << std::endl;
    return 0;
}