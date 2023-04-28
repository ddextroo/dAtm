/*
=============== dATM BANK SYSTEM ===============

===============
Features:

Welcome: - Not Authenticated:
Login
Signup
Admin Panel
Exit

===============
Home: - Authenticated:
Check Balance
Withdraw Cash
Deposit Cash
Account Details
Transaction History
Change Account Number
Change PIN
Transfer Money
Sign out
About Program

===============
Home: - Admin Authenticated:
User Info
Add Cash
Deduct Cash
Change Account Number
Change PIN
Sign out

===============
Info:
Author: Dexter G. Inguito
Date Started: December 27, 2022
*/

// Built in library in C
#include <stdio.h>

// Constant variables
#define ACCTN_LENGTH 100
#define PIN_LENGTH 100
#define BALANCE 100
#define RECORD 200
#define USERS 100

// Minimum and Maximum amount to be deposit and withdrawed
#define MINIMUM 99
#define MAXIMUM 500001

// Admin
#define CREATOR 354882027743

// Program features within the functions
void home();
void login();
void signup();
void admin();
void dashboard();
int validate(int pinc);
int add_record();
void check_balance();
void withdraw_cash();
void deposit_cash();
void account_details();
void transaction_history();
void change_acctn(int type);
void change_pin(int type);
void transfer_money();
void about();

// Global variable declaration of user details
// u = user count
// login acctn = account number of the authenticated user
// uid = index number of the authenticated user
// acctn = account number stored
// pin = pin stored

// UID = USER NUMBER
// ACCOUNT NUMBER = USERNAME
// PIN = PASSWORD
int u = 0, login_acctn, uid, authenticated = 0;
int acctn[ACCTN_LENGTH];
int pin[PIN_LENGTH];

// Bank details
double added[USERS][RECORD];
double balance[BALANCE];

// Main function
int main()
{
    // Main menu
    int choose;
    printf("========== Welcome to dATM Bank ==========\n");
    printf("[1] Login\n[2] Sign up\n[3] Admin Panel\n[4] Exit\n");
    printf("\nPlease choose number to proceed: ");
    scanf("%d", &choose);

    switch (choose)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        admin();
        break;
    case 4:
        printf("\n\nSee you again, user\n\n");
        return 0;
        break;
    default:
        printf("\n\nInvalid Input\n\n");
        main();
        break;
    }
}

// Function to login user by their account
void login()
{
    int i, j, acctname, pincod, prompt1 = 0, prompt2 = 0, prompt10, snum, suid;

    if (authenticated == 0)
    {
        printf("========== dATM BANK | AUTHENTICATION ==========\n");

        printf("4 digit Account Number: ");
        scanf("%d", &acctname);
        printf("PIN: ");
        scanf("%d", &pincod);
        if (acctname <= 1000 || acctname >= 9999)
        {
            printf("The entered number is not a 4-digit number.\n");
            login();
        }
        else
        {
            // Validate the input account number
            for (i = 0; i < ACCTN_LENGTH; i++)
            {
                if (acctn[i] == acctname)
                {
                    snum = acctn[i];
                    suid = i;
                    prompt1 = 1;
                }
            }
            // Validage the input pin
            if (prompt1 == 1)
            {
                if (pin[suid] == pincod)
                {
                    prompt2 = 1;
                }
            }
            else
            {
                printf("\nAccount number doesn't exist\n\n");
                printf("\nPress [1] to go back or press [2] to try again: ");
                scanf("%d", &prompt10);

                prompt10 == 1 ? main() : login();
            }
            if (prompt1 == 1 && prompt2 == 1)
            {
                login_acctn = snum;
                uid = suid;
                authenticated = 1;
                printf("\n\nAccess Granted\n\n");
                home();
            }
            else
            {
                printf("\n\nAccess Denied\n\n");
                printf("\nPress [1] to go back or press [2] to try again: ");
                scanf("%d", &prompt10);

                prompt10 == 1 ? main() : login();
            }
        }
    }
    else
    {
        printf("\n\nAccess Granted\n\n");
        home();
    }
}
// Function to create new account to the user
void signup()
{
    int acctn1, i, pincode;
    printf("========== dATM BANK | AUTHENTICATION ==========\n");
    printf("\nFirst digit of the account number must not zero\n\n");
    printf("4 digit Account Number: ");
    scanf("%d", &acctn1);
    printf("Number PIN code: ");
    scanf("%d", &pincode);

    for (i = 0; i < ACCTN_LENGTH; i++)
    {
        if (acctn[i] == acctn1)
        {
            printf("This account number is already used, try another\n");
            signup();
        }
    }
    if (acctn1 <= 1000 || acctn1 >= 9999)
    {
        printf("The entered number is not a 4-digit number.\n");
        signup();
    }
    else
    {
        if (i == 100)
        {
            if (u > 99)
            {
                printf("\n\nThis program has reached maximum users, unable to sign up...\n\n");
                main();
            }
            else
            {
                // Check if the pin is not 4 to 8 digits
                if (pincode <= 1000 || pincode >= 99999999)
                {
                    printf("PIN must contain 4 to 8 digits\n\n");
                    signup();
                }
                else
                {
                    acctn[u] = acctn1;
                    pin[u] = pincode;
                    balance[u] = 0;
                    u++;
                    printf("\n\nAccount Successfully Created!\nVerify your credentials\n\n");
                    login();
                }
            }
        }
    }
}
// Function to proceed after login
void home()
{
    int choice;
    printf("========= dATM BANK | HOME ==========\n\n");

    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            printf("[1] Check Balance\n[2] Withdraw Cash\n[3] Deposit Cash\n[4] Account Details\n[5] Transaction History\n[6] Change PIN\n[7] Change Account Number\n[8] Transfer Money\n[9] Sign out\n[10] About Program\n");
            printf("\nEnter your number choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                check_balance();
                break;
            case 2:
                withdraw_cash();
                break;
            case 3:
                deposit_cash();
                break;
            case 4:
                account_details();
                break;
            case 5:
                transaction_history();
                break;
            case 6:
                change_pin(1);
                break;
            case 7:
                change_acctn(1);
                break;
            case 8:
                transfer_money();
                break;
            case 9:
                login_acctn = 0;
                uid = 0;
                authenticated = 0;
                main();
                break;
            case 10:
                about();
                break;
            default:
                printf("Invalid Input\n");
                home();
                break;
            }
        }
        else
        {
            printf("\nUser error\n\n");
            login_acctn = 0;
            uid = 0;
            authenticated = 0;
            main();
        }
    }
    else
    {
        printf("\nNot Authenticated\n\n");
        authenticated = 0;
        login_acctn = 0;
        uid = 0;
        main();
    }
}
// Function to access the back of the program
void admin()
{
    double password;
    printf("========= dATM BANK | ADMIN PANEL ==========\n\n");
    printf("Password: ");
    scanf("%lf", &password);

    password == CREATOR ? dashboard() : printf("Access Denied");
}
// Function to control the info of the user
void dashboard()
{
    int i, choose, usernumber, acc = 0, a = add_record();
    double addcash = 0, deductcash = 0;
    printf("\n========== ATM BANK | ADMIN DASHBOARD ===========\n");
    printf("\n[1] User Info\n[2] Add Cash\n[3] Deduct Cash\n[4] Change PIN\n[5] Change Account Number\n[6] Sign out\n");
    printf("Enter your number choice: ");
    scanf("%d", &choose);

    switch (choose)
    {
        // User Info
    case 1:
        printf("\n\nTotal Accounts: %d\n", u);
        for (i = 0; i < ACCTN_LENGTH; i++)
        {
            if (acctn[i] != 0)
            {
                acc = 1;
                printf("\nUID - %d\nAccount Number: %d\nPIN: %d\nTotal Balance: %.2lf\n", i, acctn[i], pin[i], balance[i]);
            }
        }
        if (acc == 0)
            printf("\n\nNo registered account yet\n\n");

        dashboard();
        break;
        // Add Cash
    case 2:
        printf("\n\nInput UID: ");
        scanf("%d", &usernumber);
        printf("Amount to be added: ");
        scanf("%lf", &addcash);

        // Check if that account is exist in the array
        if (acctn[usernumber] == 0)
        {
            printf("\nAccount doesn't exist\n");
            dashboard();
        }
        else
        {
            balance[usernumber] = balance[usernumber] + addcash;
            printf("\n\n\nCash successfully added to the account!\n\n\n");
            added[uid][a] = addcash;
            dashboard();
        }
        break;
        // Deduct Cash
    case 3:
        printf("\n\nInput UID: ");
        scanf("%d", &usernumber);
        printf("Amount to be deducted: ");
        scanf("%lf", &deductcash);

        // Validate if the cash in below the balance
        if (deductcash > balance[uid])
        {
            printf("\nInsufficient Balance\n");
            dashboard();
        }
        else
        {
            // Check if that account is exist in the array
            if (acctn[usernumber] == 0)
            {
                printf("\nAccount doesn't exist\n");
                dashboard();
            }
            else
            {
                balance[usernumber] = balance[usernumber] - deductcash;
                printf("\n\n\nCash successfully deducted to the account!\n\n\n");
                added[uid][a] = deductcash * (-1);
                dashboard();
            }
        }
        break;
    case 4:
        change_pin(2);
        break;
    case 5:
        change_acctn(2);
        break;

        // Sign out
    case 6:
        main();
        break;
    default:
        printf("Select valid choice\n");
        dashboard();
        break;
    }
}
// Function to validate the user if they are authenticated to the program
int validate(int acctnc)
{
    int i;
    for (i = 0; i < ACCTN_LENGTH; i++)
    {
        if (acctn[i] == acctnc)
        {
            return 1; // 1
        }
    }
}
// Function to check all transactions of the user
int add_record()
{
    int i;
    for (i = 0; i < RECORD; i++)
    {
        if (added[uid][i] == 0) // since the empty element is 0
        // condition if the element is empty to return that position
        {
            return i;
        }
    }
}
// Function to check the balance of the user
void check_balance()
{
    // Validate if the account number is existed or authenticated
    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            printf("\n\n\nTotal Balance: %.2lf\n\n\n", balance[uid]);
            home();
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
// Function to withdraw cash of the user
void withdraw_cash()
{
    double withdraw;
    int a = add_record();
    printf("\n\n\nWITHDRAW CASH\n\n\n");
    printf("Amount that can be withdrawed\nMinimim: 100\nMaximum: 500000\nTo close, input 0\n\n");
    printf("Amount of cash: ");
    scanf("%lf", &withdraw);

    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            if (withdraw > balance[uid])
            {
                printf("\nInsufficient Balance\n");
                home();
            }
            else
            {
                // Validate if the cash is on range
                if (withdraw <= MINIMUM || withdraw >= MAXIMUM)
                {
                    printf("The amount must be on range\n\n");
                    home();
                }
                else
                {
                    if (withdraw == 0)
                        home();
                    else
                    {
                        balance[uid] = balance[uid] - withdraw;
                        printf("\n\n\nCash successfully stored to your account!\n\n\n");
                        // Formula to make the value negative
                        added[uid][a] = withdraw * (-1);
                        home();
                    }
                }
            }
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
// Function to deposit cash
void deposit_cash()
{
    double deposit;
    int a = add_record();
    printf("\n\n\nDEPOSIT CASH\n\n\n");
    printf("Amount that can be deposit\nMinimim: 100\nMaximum: 500000\nTo close, input 0\n\n");
    printf("Amount of cash: ");
    scanf("%lf", &deposit);

    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            if (deposit <= MINIMUM || deposit >= MAXIMUM)
            {
                printf("The amount must be on range\n\n");
                home();
            }
            else
            {
                if (deposit == 0)
                    home();
                else
                {
                    balance[uid] = balance[uid] + deposit;
                    printf("\n\n\nCash successfully stored to your account!\n\n\n");
                    // Added to the transaction array
                    added[uid][a] = deposit;
                    home();
                }
            }
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
// Function to view account details
void account_details()
{
    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            printf("\nUID: %d\nAccount number: %d\nPIN: %d\n\n", uid, acctn[uid], pin[uid]);
            home();
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
// Function to view the user transactions
void transaction_history()
{
    int i, acc = 0;

    printf("\n\nTRANSACTION HISTORY\n\n");
    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            for (i = 0; i < RECORD; i++)
            {
                if (added[uid][i] != 0)
                {
                    acc = 1;
                    added[uid][i] < 0 ? printf("\nTransaction %d = %.2lf\n\n", i + 1, added[i]) : printf("\nTransaction %d = +%.2lf\n\n", i + 1, added[uid][i]);
                }
            }
            // Check if there are no transaction stored in the array
            if (acc == 0)
                printf("\n\nNo transaction history\n\n");
            home();
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
// Function for changing pin of the user
// 2 types one for user side and one for admin side
void change_pin(int type)
{
    int pincod, tno;

    switch (type)
    {
    case 1:
        printf("\n\nCHANGE PIN CODE\n\n");
        printf("Current PIN: %d\n\n", pin[uid]);
        printf("\n\nPress -1 in pin to back\n");
        printf("Input new pin: ");
        scanf("%d", &pincod);

        // Valide if the user is authenticated
        if (pincod == -1)
            home();
        else
        {
            if (login_acctn != 0)
            {
                if (validate(login_acctn) == 1)
                {
                    if (pincod <= 1000 || pincod >= 99999999)
                    {
                        printf("PIN must contain 4 to 8 digits\n\n");
                        home();
                    }
                    else
                    {
                        // changing pin
                        pin[uid] = pincod;
                        printf("\nPIN SUCCESSFULLY CHANGED\n\n");
                        home();
                    }
                }
                else
                {
                    printf("\n\nNot logged in\n\n");
                    main();
                }
            }
        }
        break;
    // Admin side, no need to validate
    case 2:
        printf("\n\nCHANGE PIN\n\n");
        printf("\n\nPress -1 in pin to back\n");
        printf("Input UID: ");
        scanf("%d", &tno);
        printf("\nPIN for UID %d: %d\n\n", tno, pin[tno]);
        printf("Input new pin: ");
        scanf("%d", &pincod);

        // Check if that account is exist in the array
        if (pincod == -1)
            dashboard();
        else
        {
            if (acctn[tno] == 0)
            {
                printf("\nAccount doesn't exist\n");
                dashboard();
            }
            else
            {
                pin[tno] = pincod;
                printf("\nPIN SUCCESSFULLY CHANGED\n\n");
                dashboard();
            }
            break;
        default:
            printf("ERROR");
            break;
        }
    }
}
// change account number
void change_acctn(int type)
{
    int acctn1, tno;

    switch (type)
    {
    case 1:
        printf("\n\nCHANGE ACCOUNT NUMBER\n\n");
        printf("Current Account Number: %d\n\n", acctn[uid]);
        printf("\n\nPress -1 in account number to back\n");
        printf("Input new account number: ");
        scanf("%d", &acctn1);

        // Valide if the user is authenticated
        if (acctn1 == -1)
            home();
        else
        {
            if (login_acctn != 0)
            {
                if (validate(login_acctn) == 1)
                {
                    if (acctn1 <= 1000 || acctn1 >= 9999)
                    {
                        printf("The entered number is not a 4-digit number.\n");
                        home();
                    }
                    else
                    {
                        // changing account number
                        acctn[uid] = acctn1;
                        login_acctn = acctn1;
                        printf("\nACCOUNT NUMBER SUCCESSFULLY CHANGED\n\n");
                        home();
                    }
                }
                else
                {
                    printf("\n\nNot logged in\n\n");
                    main();
                }
            }
        }
        break;
    // Admin side, no need to validate
    case 2:
        printf("\n\nCHANGE ACCOUNT NUMBER\n\n");
        printf("\n\nPress -1 in account number to back\n");
        printf("Input UID: ");
        scanf("%d", &tno);
        printf("\nAccount Number for UID %d: %d\n\n", tno, acctn[tno]);
        printf("Input new account number: ");
        scanf("%d", &acctn1);

        // Check if that account is exist in the array
        if (acctn1 == -1)
            dashboard();
        else
        {
            if (acctn[tno] == 0)
            {
                printf("\nAccount doesn't exist\n");
                dashboard();
            }
            else
            {
                acctn[tno] = acctn1;
                printf("\nACCOUNT NUMBER SUCCESSFULLY CHANGED\n\n");
                dashboard();
            }
            break;
        default:
            printf("ERROR");
            break;
        }
    }
}
// Function to transfer money to another user
void transfer_money()
{
    int uidrec, amount, i, ivalue;
    int a = add_record();
    printf("\n\nTRANSFER MONEY\n\n");
    printf("\nCurrent Balance: %.2lf\n", balance[uid]);
    printf("\n\nPress -1 in amount to back\n");
    printf("Input UID of the receiver: ");
    scanf("%d", &uidrec);
    if (uidrec == -1)
        home();
    else
    {
        printf("Enter Amount: ");
        scanf("%d", &amount);
    }

    // Valide if the user is authenticated
    if (login_acctn != 0)
    {
        if (validate(login_acctn) == 1)
        {
            if (amount <= MINIMUM || amount >= MAXIMUM)
            {
                printf("The amount must be on range\n\n");
                home();
            }
            else
            {
                if (acctn[uidrec] == 0)
                {
                    printf("\nAccount doesn't exist\n");
                    home();
                }
                else
                {
                    if (amount > balance[uid])
                    {
                        printf("\nInsufficient Balance\n");
                        home();
                    }
                    else
                    {
                        if (uid == uidrec)
                        {
                            printf("Error, can't transfer in your own bank\n\n");
                            home();
                        }
                        else
                        {
                            balance[uid] = balance[uid] - amount;
                            balance[uidrec] = balance[uidrec] + amount;
                            printf("\n\n\nCash successfully to UID - %d account!\n\n\n", uidrec);
                            // Formula to make the value negative
                            added[uid][a] = amount * (-1);
                            for (i = 0; i < RECORD; i++)
                            {
                                if (added[uidrec][i] == 0)
                                {
                                    ivalue = i;
                                    break;
                                }
                            }
                            added[uidrec][ivalue] = amount;
                            home();
                        }
                    }
                }
            }
        }
        else
        {
            printf("\n\nNot logged in\n\n");
            main();
        }
    }
}
void about()
{
    printf("\n\n============ dATM BANK ============\n\n\n");
    printf("ATM BANK SYSTEM OR BANK MANAGEMENT SYSTEM\n\n");
    printf("This is a mini project that is constructed completely using the C language. The bank management system is a beginner friendly project. To construct this user only needs to know about basic data structures and syntax of the c language. No advanced topic needs to be known. Here our bank management system will consist of all the processes that used to be done in ordinary banks, such as creating a new account, registering for net banking, depositing money, withdrawing, etc. Firstly we will look into the code part by part. Each part will consist of a feature.\n\n");
    printf("\nRegister account -  through this, the user will be able to register them, and their data will be kept until the account is deleted. \n\nDeposit money -   through this, the user can deposit money to their existing account.\n\nWithdraw money -  through this feature, the user can withdraw money from their account. It would consist of one more feature: we always need to check whether the user has sufficient balance to withdraw. If yes, only the money will be withdrawn, and the amount will decrease from the balance.\n\nCheck balance -  through this feature, the user will be able to check the available balance of their account.\n\nUpdate information -  through this feature, users can update their existing features, such as account number and pin.\n\nTransaction History -  through this feature, the user can see their transaction. They can see if they are deposit money, withdraw money or even transfer money.\n\nTransfer Money -  through this feature, the user can transfer their money to other uid.\n\n");
    printf("\n\n===============\n\nInfo:\n\nDeveloper: Dexter G. Inguito\nDate Started: December 27, 2022\n");
    home();
}