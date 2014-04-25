//Coins.cc

#include "Coins.h"

Coins::Coins(int q, int d, int n, int p){
    quarters = q;
    dimes = d;
    nickels = n;
    pennies = p;
}
void Coins::depositChange(Coins c){
    quarters += c.quarters;
    dimes += c.dimes;
    nickels += c.nickels;
    pennies += c.pennies;
}
bool Coins::hasSufficientAmount(int amount){
    return (quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + nickels*CENTS_PER_NICKEL + pennies)>=amount;
}
bool Coins::canMakeChange(int amount){

    while(amount>0){
        for(int i=0; i<quarters && amount>=25; i++) amount-=25;
        for(int i=0; i<dimes && amount>=10; i++) amount-=10;
        for(int i=0; i<nickels && amount>=5; i++) amount-=5;
        for(int i=0; i<pennies && amount>=1; i++) amount-=1;
        return amount==0;
    }
    return true;
}
Coins Coins::extractChange(int amount){
    if(!hasSufficientAmount(amount)){
        cout << "Unable to extract change: insufficient funds available." << endl;
        return *this;
    }
    if(!canMakeChange(amount)){
        cout << "Unable to make change: the funds are available however there are insufficient coins for change." << endl;
        return *this;
    }
    int coinCount=0;
    while(amount>0){
        for(int i=0; i<quarters && amount >=25; i++){
            coinCount++;
            amount-=25;
        }
        quarters -= coinCount;
        coinCount = 0;
        for(int i=0; i<dimes && amount >=10; i++){
            coinCount++;
            amount-=10;
        }
        dimes -= coinCount;
        coinCount = 0;
        for(int i=0; i<nickels && amount >=5; i++){
            coinCount++;
            amount-=5;
        }
        nickels -= coinCount;
        coinCount = 0;
        for(int i=0; i<pennies && amount >=1; i++){
            coinCount++;
            amount-=1;
        }
        pennies -= coinCount;
    }
    return *this;
}
void Coins::print(ostream &out){
    cout << "Coins... Amount: " << (quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + nickels*CENTS_PER_NICKEL + pennies) << " , Quarters: " << quarters << " , Dimes: " << dimes << " , Nickels: " << nickels << " , Pennies: " << pennies;
}
ostream & operator << (ostream &out, Coins &c){
    c.print(out);
    return out;
}
/**
int main(){
    Coins test(4,3,2,1);
    cout << "Can you make change? " << test.canMakeChange(137) << endl;
    cout << test << endl;
    test.extractChange(67);
    cout << test << endl;
    return 0;
}
**/
