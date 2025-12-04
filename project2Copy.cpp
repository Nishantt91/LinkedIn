
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// **** //
// header.h = includes everything in class // reference header.h in cpp with Functions & Main.

// This part is new, committed via terminal*

using namespace std;



//Create a class: Make it generic (dont initialize). Use as template
class bankAccount {

//keeps this data protected (accessible with setters/getters) //
private:
    string name;
    int accountNum;
    string accountType;
    double balance;
    double iRate; // decimal
    static int n; // allows us to use incrementOperator++ in functions
    double deposit;
    double withdraw;
    
//Use function prototypes // User values go thru this f(x) and gets implemented. (value assigned to objects)
public:
    
    // CONSTRUCTORS --> initializes variables before entering actual data. The constructors () help avoid garbage assigned to the values.// No return types required. Nothing being returned.
    // We can have multiple constructors. Based on object type "ObjectClassName(data)" in Main.
    //Constructors
    bankAccount(); // No arguement was entered.
    bankAccount(string& nam, string accountT);  // "456" was passed via "Account yourAccount(456);". Ths one is implemented!
    bankAccount(int accountN);
    bankAccount(double bale, double iR);
    bankAccount(double bale, double iR, double deposit, double withdraw);
    
    //Getter or accessors -->Always returns something back to object class, but accessed indirectly via member access. Because we cannot access the private data directly. We may be able to access it indirectly via object class (see main: "Account myAccount").
    //To Access private data, we use:
        // (return type)+ "get"+VariableName();//ex: int getID(). // if no return type = "void"
    
   
    // Setters or Mutators = Sets value to data (in private: id, fname).
    // Always void, because theres no return.
    
    // Setters/Mutators (initializes it)
    void setname(string nam);
    static void setn(int n);
    void setaccountNum(int n); // pass 'incrementNum' to 'accountNum' // sets accountNum to 1
    void setaccountType(string T);
    void setbalance(double bal);
    void setiRate(double rate);
    void setdeposit(double depo);
    void setwithdraw(double with);
    
    
    
    // Getters/Accessors (returns value type)
    string getname();
    static int getn();
    int getaccountNum();
    string getaccountType();
    double getbalance();
    double getiRate();
    double getdeposit();
    double getwithdraw();

    
    //Destructor (release memory back to OS)
    ~bankAccount(); //  no aguement needed // no return type // " ~ sameNameofClass(); "
    
    //functions can be added too.
    void show();
    
};


class checkingAccount : public bankAccount {

private:
    int checkingNum;
    double checkingBalance;
    double interest; //
    double minBal; //
    double fees; //
    // verify if balance < minBal
    // write a check
    // withdraw (overrides method of parent class)
    

public:
    
    void setcheckingNum(int cnum);
    void setcheckingBalance(double bal);
    void setinterest(double intr);
    void setminBal(double minb);
    void setfees(double fee);
    
    int getcheckingNum();
    double getcheckingBalance();
    double getinterest();
    double getminBal();
    double getfees();
    
    // constructors
    checkingAccount() {
        
        checkingNum = getaccountNum();
        checkingBalance = getaccountNum();
        interest = getiRate();
        minBal = 0000.00;
        fees = 50.00;
    }

    checkingAccount(int n) : bankAccount() {
        
         checkingNum = n;
    }
    
    checkingAccount(double c, double i, double m, double f):bankAccount()  {
        
        checkingNum = getaccountNum();
        checkingBalance = getaccountNum();
        interest = getiRate();
        minBal = 0000.00;
        fees = 50.00;
    }


    ~checkingAccount() {
        
        //cout << "\tChecking Account Destructed! " << endl;
    }

    void show()
    {
        
        //cout << "Name: " << name << endl; //private data member
        cout << "\n\n Account Number:  " << checkingNum << " \nChecking Balance: " << checkingBalance << "\ninterest: " << interest << "\nMinimum Balance: " << minBal << "\nfees: "<< fees << endl;
    }
    

};
 
                                  // CONTSTRUCTOR //

// Class :: Class()
bankAccount::bankAccount() {
    
    name = "noName";
    accountNum = 00000000;
    accountType = "Checking/Saving";
    balance = 0000.00;
    iRate = 0.00;
}

bankAccount::bankAccount(string& nam, string accountT) {
    name = nam;
    accountType = accountT;
}

bankAccount::bankAccount(int accountN) {
    accountNum = accountN;
}


bankAccount::bankAccount(double bal, double iR) {
    balance = bal;
    iRate = iR;
}

bankAccount::bankAccount(double bale, double iR, double deposit, double withdraw) {
    deposit = 0000.00;
    withdraw = 0000.00;
}


                            //IMPLEMENTATION // (Sets the value/Gets the value)

// Set Name //
void bankAccount::setname(string nam){
    name = nam;
}

// Get Name //
string bankAccount::getname() {
    return name;
}

//set n (no funtion needed)
int bankAccount::n = 0;


// Getn
int bankAccount::getn() {

    static int n= 0;
    return n++;
}


// set account num.
void bankAccount::setaccountNum(int n) {
    accountNum = n;
}

    
/*
 
    To assign random numbers (7 digits) directly inside function. //
 
    int num = NULL;
    for (int i = 0; i <= 50000000; i++) { // random num assignment for account
        num += rand() % 10;
    }
 
*/


// Get Account Number //
int bankAccount::getaccountNum() {
    
    return n++;
}


// Set Account Type //
void bankAccount::setaccountType(string a){
    
    if (a == "C" || "c" == a) {
        
        accountType = "Checkings";
        
    } else if (a == "S" || "s" == a) {
        
        accountType = "Savings";
    }
    
}

// Get Account Type //
string bankAccount::getaccountType() {
    return accountType;
}


void bankAccount::setwithdraw(double with){
   
    double w,y;
    w = with;
    //withdraw = w;
    
    cout << "\nEnter the amount to withdraw: " << endl;
    cin >> y;
    system("pause");
    
    withdraw = y;
    
        if (withdraw > balance) {
            cout << "Insufficient Amount" << endl;
            system("pause");
        } else {
            balance = balance - withdraw;
            cout <<" Successfully withrawled $: "<< withdraw <<" \nBalance: " << balance << endl;
        }
    
}

double bankAccount::getwithdraw() {
    return withdraw;
}



// Set Balance //
void bankAccount::setbalance(double bal){
    //initial balance
    balance = bal;
    
    int y = 0;
    
    while (y != -1) {
    int x;
    cout << "\nEnter (1) to Deposit (Account: " << accountNum << "): " <<endl;
    cout << "\nEnter (2) to Withdrawl (Account: "  << accountNum << "): " << endl;
    cout << "\nEnter (3) to Deposit & Withdrawl (Account: "  << accountNum << "): " << endl;
    cin >> x;
        

    if (x == 1) {
            cout << "\nEnter the amount to be deposited: " << endl;
            cin >> deposit;
            system("pause");
            
            balance = balance + deposit;
            
            cout <<" \n\tDeposit Successfull! \n\tBalance:  " << balance << endl;
        
            cout <<" \n\tCurrent Balance: " << balance << "\n\nTo exit, enter \"-1\" "<< endl;
            cin >> y;
        
    } else if (x == 2) {
            cout << "\nEnter the amount to withdraw: " << endl;
            cin >> withdraw;
            system("pause");
            
                if (withdraw > balance) {
                    cout << "Insufficient Amount" << endl;
                    system("pause");
                } else {
                    balance = balance - withdraw;
                    cout <<" Successfully withrawled! New Balance:  " << balance << endl;
                }
        
        cout <<" \n\tCurrent Balance: " << balance << "\n\nTo exit, enter \"-1\" "<< endl;
        cin >> y;
        
    } else if (x == 3) {
        
        cout << "\nEnter the amount to be deposited: " << endl;
        cin >> deposit;
        system("pause");
        
        balance = balance + deposit;
        
        cout <<" \n\tDeposit Successfull! \n\tBalance:  " << balance << endl;
        system("pause");
        
        cout << "\nEnter the amount to withdraw: " << endl;
        cin >> withdraw;
        
            if (withdraw > balance) {
                cout << "Insufficient Amount" << endl;
            } else {
                balance = balance - withdraw;
                cout <<" Successfully withrawled: $" << withdraw << "\n\tBalance:  " << balance << endl;
            }
        
        cout <<" \n\tCurrent Balance: " << balance << "\n\nTo exit, enter \"-1\" "<< endl;
        cin >> y;
        
    } else if (0 >= x || x >= 4) {
        
        cout << "Invalid selection! Try again! Select: " << endl;
        
        int x;
        cout << "\nEnter (1) to Deposit (Account: " << accountNum << "): " <<endl;
        cout << "\nEnter (2) to Withdrawl (Account: "  << accountNum << "): " << endl;
        cout << "\nEnter (3) to Deposit & Withdrawl (Account: "  << accountNum << "): " << endl;
        cin >> x;
        
        cout <<" \n\tCurrent Balance: " << balance << "\n\nTo exit, enter \"-1\" "<< endl;
        cin >> y;
        system("pause");
        
    }
    
    } // end while

} // end void


// Set iRate //
void bankAccount::setiRate(double ir) {
    iRate = ir;
}

// Get iRate //
double bankAccount::getiRate() {
    return iRate;
}



                                    // SHOW //
// DISPLAYS
void bankAccount::show() {
cout << "\nAccount Information (Parent Class): " << endl;
cout << "\n\nName: "<< name << " \nType: "<< accountType << " \nAccNumber: " << accountNum <<  " \nRate: " << iRate  << " \nDeposited amount: " << deposit << " \nWithdrawal amount: " << withdraw << " \nBalance: " << balance << endl;
    
}


                                // DESTRUCTORS //

bankAccount::~bankAccount() {
      //cout<< "Destruction Complete" << endl;
}

                          // CHECKING ACCOUNT CLASS //
                              // IMPLEMENTATION //

// Set checking num //
void checkingAccount::setcheckingNum(int cnum) {
    
    checkingNum = getaccountNum();
}

// Get checking num //
int checkingAccount::getcheckingNum() {
    
    return checkingNum;
}

// Set checking balance//
void checkingAccount::setcheckingBalance(double bal) { // to call this function, send 000s to trigger it.
    

    //initial balance
    checkingBalance = bal;
    
    int x;
    cout << "\tWelcome to CHECKING ACCOUNT. Make a selection:  " << endl;
    cout << "Enter (1) to Deposit (Account: " << checkingNum << "): " <<endl;
    cout << "Enter (2) to Withdrawl (Account: "  << checkingNum << "): " << endl;
    cout << "Enter (3) to Deposit & Withdrawl (Account: "  << checkingNum << "): " << endl;
    cin >> x;
    

    if (x == 1) {
        
            double deposit;
            cout << "\nEnter the amount to be deposited: " << endl;
            cin >> deposit;
            system("pause");
            
            checkingBalance = (checkingBalance + deposit);
        
            
            cout <<" \n\tDeposit Successfull! \n\tBalance:  $" << checkingBalance << endl;
        
    } else if (x == 2) {
        
            double withdraw;
            cout << "\nEnter the amount to withdraw: " << endl;
            cin >> withdraw;
            system("pause");
            
                if (withdraw > checkingBalance) {
                    cout << "Insufficient Amount" << endl;
                    system("pause");
                    
                } else {
                    checkingBalance = (checkingBalance - withdraw);
                    cout <<" Successfully withrawled from Checking Account! Balance: " << checkingBalance << endl;
                    system("pause");
                }
        
    } else if (x == 3) {
            
        double deposit;
        cout << "\nEnter the amount to be deposited: " << endl;
        cin >> deposit;
        system("pause");
        
        checkingBalance = (checkingBalance + deposit);
        
        cout <<" \n\tDeposit Successfull! \n\tBalance:  " << checkingBalance << endl;
        system("pause");
        
        double withdraw;
        cout << "\nEnter the amount to withdraw: " << endl;
        cin >> withdraw;
        
            if (withdraw > checkingBalance) {
                cout << "Insufficient Amount" << endl;
            } else {
                checkingBalance = (checkingBalance - withdraw);
                cout <<" Successfully withrawled: $" << withdraw << "\n\tBalance:  " << checkingBalance << endl;
            }
        
    } else if (x >= 4) {
        
        cout << "Invalid selection! Try again: " << endl;
        system("pause");
        
    } else {
        system("pause");
    }
    
}

// Get checking balance //
double checkingAccount::getcheckingBalance() {
    
    return checkingBalance;
}
 
// Set checking interest//
void checkingAccount::setinterest(double intr) {
    
    interest = intr;
}

// Get checking interest //
double checkingAccount::getinterest() {
    
    return interest;
}
 
// Set checking minimum balance//
void checkingAccount::setminBal(double min) {
    
    minBal = min;
}

// Get checking minimum balance //
double checkingAccount::getminBal() {
    
    return minBal;
}

// Set checking fee //
void checkingAccount::setfees(double fee) {
    
    fees = fee;
}

// Get checking fee //
double checkingAccount::getfees() {
    
    return fees;
}


    

//5 THINGS for return data: show, store, pass it, nothing, process it.//

int main()  {
    
    
    // object created
    bankAccount myAccount;
    checkingAccount checking;
    
    // set precision // fixed number // req. header file
    // cout << fixed << setprecision(2) << endl;
    
    
    // Set name
    string n;
    cout << "Enter Acount User Name: " << endl;
    cin >> n;
    myAccount.setname(n);
    
     
    // Set (send arguement)/ Display account num
    // Assign random numbers to account number from main: class.setAccountnum(DATA) --> Setter Fx --> getter Fx returns to caller (back to main)
    
    // set account num
    myAccount.setaccountNum(00000);
    
    // set checking num
    checking.setcheckingNum(00000);
    
    //Check
    cout << "\nCheck Account Numbers: " << endl;
    cout << "Main Account Number: " << myAccount.getaccountNum() << endl;
    cout << "Checking Account Number: " << checking.getcheckingNum() << endl;
    
    
    // Set Type
    string t;
    cout << "\nSelect Type of Account: \nEnter 'C' for Checking \n'S' for Saving\n" << endl;
    cin >> t;
    myAccount.setaccountType(t);
    
    
    // Set rate
    myAccount.setiRate(0.03);
    
    //set checking rate
    checking.setinterest(0.03);
    
    //set min bal
    checking.setminBal(250);
    
    
    int q;
    cout << "Select Account \nEnter (1) = Main Account \nEnter (2) = Checking Account \nEnter (3) = Savings Account (Not yet made)" << endl;
    cin >> q;
    
    if (q == 1) {
        //Deposit in main
        myAccount.setbalance(0000);
    } else if (q == 2) {
        //Deposit in checking
        checking.setcheckingBalance(0000);
    } else if (q == 3) {
        //Deposit in saving
        
    } else {
        cout << "Wrong Input" << endl;
    }
    
  
    
    
    
    
    // enter deposit amount
    //double d;
    //cout << "\nEnter deposit amount: " << endl;
    //cin >> d;
    
    // Set deposit
    //myAccount.setdeposit(d);
    
    //Update balance after deposit
    //myAccount.setbalance(myAccount.getdeposit());
    
    
    // enter deposit amount
    //double w;
    //cout << "\nEnter withdrawl amount: " << endl;
    //cin >> w;
    
    // Set rate
    //myAccount.setwithdraw(w);
    
    // min balance needs to be $200
    checking.setminBal(200);
    

    //show results
    myAccount.show();
    
    checking.show();
    
    
// ----------------------------Object Array -------------------------------------------- //
    
  
    // 10 object files - for 10 customers.
    bankAccount customers[10]; //  10 account object atrray (each with same definition) // skip index in loop
    
    checkingAccount customer[10]; //  10 account object atrray (each with same definition) // skip index in loop
    
    cout << "\n\n" << endl;
    cout << "10 Empty Main (Parent Class) Accounts created!\n" << endl;
    cout << "10 Empty Checking (Child Class) Accounts created!\n" << endl;
    
    /*
    for (int i =0; i <10; i++) {
        cout << "Account " << i+1 << "): \n";
        
        //Random Number gen for account number (7 digits)
        int num = NULL;
        for (int i = 0; i <= 500000; i++) { // random num assignment for account
            num += rand() % 10;
        }

        customers[i].setname(n);
        //RANDOM 7 digits for account number
        customers[i].setaccountNum(num);
        
        //STATIC INT - TO ASSIGN ACCOUNT NUMBER IN INCREMENTS
        //customers[i].setaccountNum(bankAccount::getn());
        
        //initial balance
        //customers[i].setbalance(0000.00);
        customers[i].setaccountType("Checking");
               
        //For first (i=0) customer, assign the current i value (accountNum = 0);
        //For second (i=1) customer, assign the current i value (accountNum = 1);
        //...Til the 10th.
        
        //customers[i].show(); // display all customers array and assigned account number.
        cout << "\n";
    }
    */
    
    
    //Another way to display variable data.
    /*
    cout << myAccount.getname() << endl;
    cout << myAccount.getaccountNum() << endl;
    cout << myAccount.getaccountType() << endl;
    cout << myAccount.getbalance() << endl;
    cout << myAccount.getiRate() << endl;
    */
     
    return 0;
}

// Function to increment

//  int result() {
//    static int checkingAccountNum = 10;
//    return checkingAccountNum++ ;
//}
