//betterMain.cc
#include "Coins.h"
const int CENTS_FOR_CHIPS = 68;
int main(){
	Coins pocket(5,3,6,8);
	Coins piggyBank(50,50,50,50);

	cout << "I started with " << pocket << " in my pocket." << endl;

    //Create a Coins object called payForChips and initialize it.
    Coins payForChips = pocket.extractChange(CENTS_FOR_CHIPS);
    cout << "I bought a bag of chips for " << CENTS_FOR_CHIPS << " cents." << endl;


    cout << "I currently have " << pocket << " left in my pocket." << endl;
    cout << "I also currently have " << piggyBank << " left in my piggy bank." << endl;

    cout << "I am now transferring 749 cents from my piggy bank to pocket." << endl;
    piggyBank.extractChange(749);
    Coins a(29,2,0,4);
    pocket.depositChange(a);

    cout << "I currently have " << pocket << " left in my pocket." << endl;
    cout << "I also currently have " << piggyBank << " left in my piggy bank." << endl;

    Coins sofaChange(13,17,21,25);
    cout << "I then started cleaning around the house and found " << sofaChange << " in the sofa." << endl;
    piggyBank.depositChange(sofaChange);
    cout << "After depositing that money in my piggy bank, I now have " << piggyBank << endl;
	return 0;
}