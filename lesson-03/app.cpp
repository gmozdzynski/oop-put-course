#include<iostream>
#include<string>

using namespace std;

class Bank{
    public:
        string name;
        string currency;
        double balance;
        Bank(string x, double y, string z){
            name = x;
            balance = y;
            currency = z;
        }
        Bank(string x, int y){
            name = x;
            balance = y;
            currency = "none";
        }
        Bank(string x):Bank(x,0.0, "none"){
        //name = x;
        //balance = 0;
        //currency = "none";
        }


        double returnBalance() {return this->balance; };


};

int main(){

Bank userOne("John", 200, "PLN");
Bank userTwo("Sara", 300);

cout << userOne.name << " " << userOne.balance << "\n";
cout << userTwo.name << " " << userTwo.balance << userTwo.currency << "\n";

cout<<userOne.returnBalance();

}
