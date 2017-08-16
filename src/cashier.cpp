#include <iostream>
#include <iomanip>

using namespace std;

double getChange(double sum);

int main(){
	cout << "Welcome to the cashier! " << endl;
	cout << "Scan the items one by one, and give me money. " << endl;

	double sum = 0;
	int count = 0;
	double price;

	do {
		count ++;
		cout << "Please scan item #" << count << ": ";
		cin >> price;
		if (price > 0)
			sum += price;
		cout << "Subtotal: $" << fixed << setprecision(2) << sum << endl;
	} while (price >= 0);

	double change = getChange(sum);
	double due = change;

	int dollars, quarters, dimes, nickels, pennies;

	dollars = change;
	change -= dollars;

	quarters = change / 0.25;
	change -= quarters * 0.25;

	dimes = change / 0.1;
	change -= dimes * 0.1;

	nickels = change / 0.05;
	change -= nickels * 0.05;

	pennies = change / 0.01;

	cout << "Total Amount: $" << fixed << setprecision(2) << sum << endl;
	cout << "Change due: $" << fixed << setprecision(2) << due << endl;

	cout << "Dollars: " << dollars << endl;
	cout << "Quarters: " << quarters << endl;
	cout << "dimes: " << dimes << endl;
	cout << "nickels: " << nickels << endl;
	cout << "pennies: " << pennies << endl;

	cout << endl << "Thank you for shopping! Have a great day! " << endl;

	return 0;
}

double getChange(double sum) {
	double payment, change;
	while (true) {
		cout << "Make Payment: $";
		cin >> payment;
		change = payment - sum;
		if (change < 0) {
			cout << "Incorrect Amount! Prepare enough money!" << endl;
			continue;
		}
		break;
	}
	return change;
}
