//bestMain.cc

#include "Coins.h"



int coinMenu(Coins &c){
	cout << endl << "Welcome to the Coins Main Menu:" << endl;
	cout << "Your current balance: " << c << endl;
    cout << "What would you like to do?" << endl;
    
    cout << "D - Deposit change..." << endl;
    cout << "E - Extract change..." << endl;
    cout << "P - Print your balance..." << endl;
    cout << "Q - Quit the program" << endl;
    string s;
    cout << endl << "Type your input: ";
    cin >> s;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    //CANNOT USE STRING FOR SWITCH STATEMENT so will use an int
    int switchExp = 0;
    if(s=="d") switchExp = 1;
    else if(s=="e") switchExp = 2;
    else if(s=="p") switchExp = 3;
    else if(s=="q") switchExp = 4;
    switch(switchExp){
    	default: return 0;
    	case 1:{ // deposit
    		cout << "How many quarters are you depositing? ";
    		int qInput=0;
    		cin >> qInput;
    		cout << "How many dimess are you depositing? ";
    		int dInput=0;
    		cin >> dInput;
    		cout << "How many nickels are you depositing? ";
    		int nInput=0;
    		cin >> nInput;
    		cout << "How many penniess are you depositing? ";
    		int pInput=0;
    		cin >> pInput;
    		Coins temp(qInput, dInput, nInput, pInput);
    		cout << "You are depositing these " << temp << endl;
    		c.depositChange(temp);
    		return 1;
    	}
    	case 2:{// extract
    		cout << "How much money will you be withdrawing? ";
    		int input=0;
    		cin >> input;
    		c.extractChange(input);
    		cout << "After extracting your balance is " << c << endl;
    		return 2;
    	}
    	case 3:{
    		cout << c << endl;
    		return 3;
    	}
    	case 4: return 4;
    }







	return 1;
}

int main(){
	Coins c(0,0,0,0);
	int x=0;
	while(x!=4) x = coinMenu(c);
	cout << "Exiting coins program..." << endl;
	return 0;
}