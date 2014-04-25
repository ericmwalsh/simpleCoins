//Coins.h

#include <iostream>
#include <fstream>
using namespace std;

const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins{
public:
    Coins(int q, int d, int n, int p);
    void depositChange(Coins c);
    bool hasSufficientAmount(int amount);
    bool canMakeChange(int amount);
    Coins extractChange(int amount);
    void print(ostream &out);
private:
    int quarters, dimes, nickels, pennies;
};

ostream & operator << (ostream &out, Coins &c);
