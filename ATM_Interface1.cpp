#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class ATM{
    private:
        long int account_no;
        int pin;
        string name;
        double balance;
        string mobile_no;
    
    public:
        void setData(long int acc_no, int pin_a, string name_a, int bal, string mobile){
            account_no = acc_no;
            pin = pin_a;
            name = name_a;
            balance = bal;
            mobile_no = mobile;
        }

        bool verifyAccount(long int accountNo){
            return account_no == accountNo;
        }

        long int getAccountNo(){
            return account_no;
        }

        int getPin(){
            return pin;
        }

        string getName(){
            return name;
        }

        double getBalance(){
            return balance;
        }

        string getMobileNo(){
            return mobile_no;
        }

        bool authenticate(int pin_a){
            return pin == pin_a;;
        }
        
        void updateMobileNo(string old_mob, string new_mob){
            if(mobile_no == old_mob){
                mobile_no = new_mob;
                cout<<"\nSuccessfully Mobile Number Updated";
            }
            else{
                cout<<"\nInvalid Old Mobile Number !!!";
            }
        }

        void updatePin(int old_pin, int new_pin){
            if(old_pin == pin){
                pin = new_pin;
                cout<<"\n Successfully Pin is Updated";
            }
            else{
                cout<<"\n Invaild Old Pin !!";
            }
        }

        void CashWithdraw(int amount_a){
            if(amount_a <= 0){
                cout<<"\n Invalid Input !!";
            }
            else if(amount_a > balance){
                cout<<"\n Insufficient Balance !!";
            }
            else{
                balance -= amount_a;
                cout<<"\n Please Collect your Cash";
                cout<<"\n Availabe Balance is "<<balance;
            }
        }

        void DepositeAmount(int amount_a){
            if(amount_a <= 0){
                cout<<"\n Invalid Input!!";
            }
            else{
                balance += amount_a;
                cout<<"\nThe Amount is Successfully Deposited";
                cout<<"\n Available Balance is: "<<balance;
            }
        }
};

int main(){
    int choice;
    int pin;
    int AccountNo;
    char input;
    int attempt = 0;
    ATM user[10];
    ATM* currUser = nullptr; //current User pointer

    user[0].setData(123456, 2222, "Jude",80000,"9922334455");
    user[1].setData(234567, 3333, "User2",85000,"2233445566");

    menu:
        system("cls");
        cout<<"\n******** WECOME TO ATM *********"<<endl;
        cout<<"\nEnter your Account Number: ";
        cin>>AccountNo;

        for(int i=0; i<2; i++){
            if(user[i].verifyAccount(AccountNo)){
                currUser = &user[i];
                break;
            }
        }

        if(currUser == nullptr){ // If curruser == nullptr then it means the account no is not exist.So it is not updated
            cout<<"Invalid Account Number.";
            return 0;
        }

        cout<<"\nEnter your PIN: ";
        cin>>pin;

        while(attempt<2 && !currUser->authenticate(pin)){ // To access using the pointer use -> symbol
            cout<<"\nInvalid PIN. Try Again";
            cout<<"\nEnter the PIN: ";
            attempt++;
            cin>>pin;
        }

        if(!currUser->authenticate(pin)){
            cout<<"\n Account Locked due to too many failed attempts.";
            return 0;
        }  
        do{
                int amount = 0; 
                string NewMobileNo, OldMobileNo;
                int OldPin, NewPin;

                cout<<"\n\n\t OPTIONS: ";
                cout<<"\n\n [1] Check Balance ";
                cout<<"\n [2] Cash Withdraw";
                cout<<"\n [3] Cash Deposite";
                cout<<"\n [4] Show User Details";
                cout<<"\n [5] Update Pin";
                cout<<"\n [6] Update Mobile Number";
                cout<<"\n [7] Exit";
                cout<<"\n\n Enter your option: ";
                cin>> choice;

                switch(choice){
                    case 1: 
                        cout<<"\n Your Bank Balance is: "<<currUser->getBalance()<<endl;
                        break;
                
                    case 2:
                        cout<<"\n Enter The Amount: ";
                        cin>>amount;
                        currUser->CashWithdraw(amount);
                        break;

                    case 3: 
                        cout<<"\nEnter the Amount: ";
                        cin>>amount;
                        currUser->DepositeAmount(amount);
                        break;

                    case 4:
                        cout<<"\n\n The Account Details: ";
                        cout<<"\n\n Account No: "<<currUser->getAccountNo();
                        cout<<"\n Name: "<<currUser->getName();
                        cout<<"\n Balance: "<<currUser->getBalance();
                        cout<<"\n Mobile Number: "<<currUser->getMobileNo();
                        break;

                    case 5:
                        cout<<"\n Enter the Old Pin: ";
                        cin>>OldPin;
                        cout<<"\n Enter the New Pin: ";
                        cin>>NewPin;

                        currUser->updatePin(OldPin, NewPin);
                        break;
                    
                    case 6:
                        cout<<"\n Enter the old Mobile number: ";
                        cin>>OldMobileNo;
                        cout<<"\n Enter the new Mobile number: ";
                        cin>>NewMobileNo;

                        currUser->updateMobileNo(OldMobileNo,NewMobileNo);
                        break;
 
                    case 7:
                        cout<<"\n\tThank You!! Visit Again!!\n\n";
                        exit(0);

                    default: 
                        cout<<"\n Enter the Valid option !!!";
                        break;
                    
                }
            }while(1); // MENU, To run for infinite times

    return 0;
}
