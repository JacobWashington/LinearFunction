#include <iostream>
#include <cmath>
using namespace std;

/********** VARIABLE DECLARATIONS **********/

void menu1();
void printFunction();
double getSolutionFx(double initialBalance, double rateOfChange, double fx);
double getSolutionX(double initialBalance, double rateOfChange, double x);
void generateProblem();
void checkSolution(double fx, double x, double b, double m, int selection, double solution);

/********** MAIN **********/

int main() {
	menu1();

	return 0;
}

/********** FUNCTION DEFINITIONS **********/

void menu1() {
	bool continueProgram = true;
	char menu1Selection;

	do {

		cout << "\n\tWelcome! This program can accept your arguments and determine the appropriate Linear Function,\n\tor generate a random linear equation for you to solve!\n";
		cout << "\tLets get started!\n";
		cout << "\n\tPlease select from the following:\n";
		cout << "\n\t\t1. Create a Linear Function.";
		cout << "\n\t\t2. Test yourself! Generate a random function and solve.";
		cout << "\n\t\t3. Exit Program.\n";
		cout << "\n\t\tSelection: ";
		cin >> menu1Selection;

		switch (menu1Selection) {
		case '1':
			printFunction();
			break;
		case '2':
			generateProblem();
			break;
		case '3':
			cout << "\t\t\n\nEXITING PROGRAM.\n\n";
			continueProgram = false;
			break;
		}

	} while (continueProgram);
}

void printFunction() {
	double initialBalance;
	double rateOfChange;

	cout << "\n\n\t\tPlease input your initial balance as an integer: ";
	cin >> initialBalance;
	cout << '\n';

	cout << "\n\n\t\tPlease input your rate of change as an integer: ";
	cin >> rateOfChange;
	cout << '\n';

	cout << "\n\t\t\tF(x) = " << rateOfChange << "x + " << initialBalance << "\n\n";
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

void generateProblem() {
	int selection = 0;

	cout << "\n\t\tWhat would you like to solve for?\n";
	cout << "\n\t\t\t1. F(x)";
	cout << "\n\t\t\t2. x";
	cout << "\n\t\t\t3. b";
	cout << "\n\t\t\t4. m";
	cout << "\n\n\t\tSelection: ";
	cin >> selection;

	double fx = 1 + (rand() % 10000);
	double x = 1 + (rand() % 1000);
	double b = 1 + (rand() % 30000);
	double m = (1 + (rand() % 10)) / 2.5;
	double solution = 0.0;

	switch (selection) {
	case 1:
		cout << "\n\t\tSolve for F(x): ";
		cout << "\n\n\t\t\tF(x) = " << m << "(" << x << ") + " << b << "\n\n";
		cout << "\n\t\t\tSolution: ";
		cin >> solution;
		cout << "\n\n";
		break;
	case 2:
		cout << "\n\t\tSolve for x: ";
		cout << "\n\n\t\t\t" << fx << " = " << m << "(x) + " << b << "\n\n";
		cout << "\n\t\t\tSolution: ";
		cin >> solution;
		cout << "\n\n";
		break;
	case 3:
		cout << "\n\t\tSolve for b: ";
		cout << "\n\n\t\t\t" << fx << " = " << m << "(" << x << ") + " << "b" << "\n\n";
		cout << "\n\t\t\tSolution: ";
		cin >> solution;
		cout << "\n\n";
		break;
	case 4:
		cout << "\n\t\tSolve for m: ";
		cout << "\n\n\t\t\t" << fx << " = " << "m" << "(" << x << ") + " << b << "\n\n";
		cout << "\n\t\t\tSolution: ";
		cin >> solution;
		cout << "\n\n";
		break;
	}

	checkSolution(fx, x, b, m, selection, solution);

}

void checkSolution(double fx, double x, double b, double m, int selection, double solution) {
	double solvedProblem = 0;
	bool correct = false;
	double roundedSolution = round(solution);

	switch (selection) {
	case 1:
		solvedProblem = round((m * x) + b);
		correct = solvedProblem == roundedSolution;
		break;
	case 2:
		solvedProblem = round((fx - b) / m);
		correct = solvedProblem == roundedSolution;
		break;
	case 3:
		solvedProblem = round(fx - (m * x));
		correct = solvedProblem == roundedSolution;
		break;
	case 4:
		solvedProblem = round((fx - b) / x);
		correct = solvedProblem == roundedSolution;
		break;
	}

	if (correct) {
		cout << "\n\t\tCONGRATULATIONS!!! You got it right!\n";
	}
	else {
		cout << "\n\t\tOUCH!!! Better luck next time!\n";
		cout << "\n\t\tThe correct answer is: " << solvedProblem << '\n';
	}
}