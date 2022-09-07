#include <iostream>
using namespace std;

void menu();
void printFunction(double initialBalance, double rateOfChange);
void menu2(bool &balanceSet, bool &rateSet, bool &continueProgram, double initialBalance, double rateOfChange);
double getSolutionFx(double initialBalance, double rateOfChange, double fx);
double getSolutionX(double initialBalance, double rateOfChange, double x);

int main() {
	menu();

	return 0;
}

void menu() {
	bool continueProgram = true;
	char currentSelection;
	double initialBalance = 0.0;
	double rateOfChange = 0.0;
	bool balanceSet = false;
	bool rateSet = false;

	do {
		
		if (!balanceSet && !rateSet) {
			cout << "\n\tWelcome! This program will accept your arguments and determine the appropriate Linear Function.\n";
			cout << "\tLets get started!\n";
		}

		cout << "\n\tPlease select from the following questions to respond to:\n";

		if (!balanceSet) {
			cout << "\n\t\tA. What is the initial balance of your function?";
		}

		if (!rateSet) {
			cout << "\n\t\tB. By what rate will your function change?";
		}

		cout << "\n\t\tC. Exit Program.\n";
		cout << "\n\t\tSelection: ";

		cin >> currentSelection;

		do {
			switch (currentSelection) {
			case 'A':
				cout << "\n\n\t\tPlease input your initial balance as an integer: ";
				cin >> initialBalance;
				cout << '\n';

				balanceSet = true;

				break;
			case 'a':
				cout << "\n\n\t\tPlease input your initial balance as an integer: ";
				cin >> initialBalance;
				cout << '\n';
				
				balanceSet = true;

				break;
			case 'B':
				cout << "\n\n\t\tPlease input your rate of change as an integer: ";
				cin >> rateOfChange;
				cout << '\n';

				rateSet = true;

				break;
			case 'b':
				cout << "\n\n\t\tPlease input your rate of change as an integer: ";
				cin >> rateOfChange;
				cout << '\n';

				rateSet = true;

				break;
			case 'C':
				cout << "\t\t\n\nEXITING PROGRAM.\n\n";
				continueProgram = false;
				break;
			case 'c':
				cout << "\t\t\n\nEXITING PROGRAM.\n\n";
				continueProgram = false;
				break;
			}
		} while (!balanceSet && !rateSet && continueProgram);

		if (balanceSet && rateSet) {
			printFunction(initialBalance, rateOfChange);
			menu2(balanceSet, rateSet, continueProgram, initialBalance, rateOfChange);
		}

	} while (continueProgram);
}

void printFunction(double initialBalance, double rateOfChange) {
	cout << "\n\t\t\tF(x) = " << rateOfChange << "x + " << initialBalance << "\n\n";
}

void menu2(bool& balanceSet, bool& rateSet, bool& continueProgram, double initialBalance, double rateOfChange) {
	int menu2Selection = 0;

	cout << "\n\tPlease select from the following options:\n";
	cout << "\n\t\t1. Input value for F(x) and solve for x.";
	cout << "\n\t\t2. Input value for x and solve for F(x).";
	cout << "\n\t\t3. Create a new function.";
	cout << "\n\t\t4. Exit Program.\n";
	cout << "\n\t\tSelection: ";
	cin >> menu2Selection;

	switch (menu2Selection) {
	case 1:
		double fx;

		cout << "\n\t\tPlease provide an integer value for F(x): ";
		cin >> fx;

		cout << "\n\t\t\tx = " << getSolutionFx(initialBalance, rateOfChange, fx) << '\n';
		cout << "\n\t\tWould you like to input another value?\n";
		cout << "\n\t\t1. Yes\n";
		cout << "\n\t\t2. No\n";
		cout << "\n\t\tSelection: ";
		cin >> menu2Selection;

		switch (menu2Selection) {
		case 1:
			menu2(balanceSet, rateSet, continueProgram, initialBalance, rateOfChange);
		case 2:
			balanceSet = false;
			rateSet = false;
			break;
		}

		break;

	case 2:
		double x;

		cout << "\n\t\tPlease provide an integer value for x: ";
		cin >> x;

		cout << "\n\t\t\tF(x) = " << getSolutionX(initialBalance, rateOfChange, x) << '\n';

		cout << "\n\t\tWould you like to input another value?\n";
		cout << "\n\t\t1. Yes\n";
		cout << "\n\t\t2. No\n";
		cout << "\n\t\tSelection: ";
		cin >> menu2Selection;

		switch (menu2Selection) {
		case 1:
			menu2(balanceSet, rateSet, continueProgram, initialBalance, rateOfChange);
		case 2:
			balanceSet = false;
			rateSet = false;
			break;
		}

		break;

	case 3:
		balanceSet = false;
		rateSet = false;
		break;

	case 4:
		cout << "\t\t\n\nEXITING PROGRAM.\n\n";
		continueProgram = false;
		break;
	}
}

double getSolutionFx(double initialBalance, double rateOfChange, double fx) {
	double solution = 0;

	solution = (fx - initialBalance) / rateOfChange;

	return solution;
}

double getSolutionX(double initialBalance, double rateOfChange, double x) {
	double solution = 0;

	solution = (rateOfChange * x) + initialBalance;

	return solution;
}