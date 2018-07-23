/* Soda Machine Application written by Joseph Hart */

#include <iostream>
#include <iomanip>
using namespace std;
/* This application will simulate a vending maching and it's operations. 
	okay so, this program will first display an default screen that has BEVERAGES & SNACKS	
	Then, you should be able to enter a character to allow you to see the drinks and 
	the prices. Once the list displays a prompt should appear allowing you to 'enter your currency'.
	Once you're done entering your money, you will be presented with another prompt to ask you to 
	make a selection. The program will 'dispense' your item and them subtract  the total from your
	available funds and offer you to make another selection or enter more coins. This should repeat 
	the user either runs out of money or chooses to exit the program. Upon exiting, the program will 
	return any currency in coins that the user didn't use.
*/
double globalFunds;
class VendingMachine{
	public:
		double storeFunds(double);
		void displayFunds();
		void vend(double, int);
};

//implementation

double VendingMachine::storeFunds(double f){
	globalFunds = f;
}

void VendingMachine::displayFunds(){
		cout << "\n You have an available balance of $" << setprecision(3) << globalFunds;
		cout << "\n";
}

void VendingMachine::vend(double p, int b){
	
	if (globalFunds >= p){
		cout << "\nYou have $" << setprecision(3) << globalFunds << " the cost is $"
			<< setprecision(3) << p << "\n";
		globalFunds = globalFunds - p;
		if (p == 1.25)
			cout << "\n Dispensing a Coke\n";
		if (p == 1.5)
			cout << "\n Dispensing a Sprite\n";
		cout << "\nYour remaining balance is $" << setprecision(3) << globalFunds << "\n";		
	}else{
		cout << "\nYou don't have enough funds applied to this transaction.";
	}
}

int main(){
	int start = 0;
	int fundsAdded;
	void ShowItems();
	void AddFunds();
	double PurchaseBeverage();
	VendingMachine vendingMachine;

	while (start == 0){
		cout << "\n       ICE COLD BEVERAGES   \n";
		cout << "\nEnter 1 to see the items avaiable";
		cout << "\nEnter 2 to apply funds to this transaction";
		cout << "\nEnter 3 to view your funds";
		cout << "\nEnter 4 to purchase some tasty beverages";
		cout << "\nEnter 5 to exit this simulation\n";
		cin >> start;
		if (start == 1){
			ShowItems();
			start = 0;
		}else if (start == 2){
			AddFunds();
			vendingMachine.displayFunds();
			start = 0;
			fundsAdded = 1;
		}else if (start == 3){
			if (fundsAdded == 1){
				vendingMachine.displayFunds();
				start = 0;
			}else
				cout << "\nSorry, you haven't applied any money to this transaction, please select another option.\n";
				start = 0;
		}else if (start == 4){
			PurchaseBeverage();
			start = 0;
		}else if (start == 5){
			if (globalFunds > 0){
				cout << "\nNow dispensing your remaing funds in the amount of $" << setprecision(3) << globalFunds << "\n";
				cout << "Have a nice day!\n";
			}else
				cout << "Have a nice day!\n";
		}else{
			cout << "\nI'm sorry, that isn't a valid choice.";
			cout << "\nPlease try again.\n";
			start = 0;
		}
			
	}
}

void AddFunds(){
	double funds;
	VendingMachine vendingMachine;
	
	cout << "Enter the amount of funds you want to deposit in the format 0.00: \n";
	cin >> funds;
	vendingMachine.storeFunds(funds);
	cout << "\n";
	
}

void ShowItems(){
	int i;
	double items[2] = {1.25, 1.50};
	cout << "\nThe items available are: ";
	for (i = 0; i < 2; i++){
		if(i == 0)
			cout << "\n 1. COKE   - $" << items[i];
		if(i == 1)
			cout << "\n 2. SPRITE - $" << items[i];
	}
	cout << "\n" ;
}

double PurchaseBeverage(){
	int whichBeverage;
	double price;
	char youSure;
	VendingMachine vendingMachine;
	
	ShowItems();
	cout << "\nWhich beverage would you like to purchase?";
	cout << "\nEnter (1) for Coke and (2) for Sprite.";
	cin >> whichBeverage;
	if (whichBeverage == 1){
		price = 1.25;
		cout << "\nThat item costs $1.25. Do you want to purchase it?";
		cout << "\nEnter 'Y' for yes and 'N' for no\n";
		cin >> youSure;
		if (youSure == 'Y' || youSure == 'y'){
			vendingMachine.vend(price, whichBeverage);
		}else{
		}
	}else if (whichBeverage == 2){
		price = 1.50;
		cout << "\nThat item costs $1.50. Do you want to purchase it?";
		cout << "\nEnter 'Y' for yes and 'N' for no\n";
		cin >> youSure;
		if (youSure == 'Y' || youSure == 'y'){
			vendingMachine.vend(price, whichBeverage);
		}
	}
}