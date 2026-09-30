/* Multi-Function Calculator
 * Original code by Rafael Echeverri
 *
 * A menu-driven calculator supporting averaging, quadratic root-solving,
 * number formatting, sorting, random number generation, and writing
 * results to a local file.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
using namespace std;

double displaynum = 29839242424839.042904920490291432323; // sentinel values used to check if a solution has been saved
double displaynum2 = 293894294982498429342.32938928;

double Average(); // function prototypes
void Formatting(double num);
void Organize(double numbers[], int item_num);

class Root { // begin class declaration
private: // data members
	double a;
	double b;
	double c;
	double root1;
	double root2;

public:
	Root(); // constructor prototype

	void displayRoot() // displays the solved roots
	{
		displaynum = root1;
		displaynum2 = root2;

		cout << "The first root is " << root1 << endl;
		cout << "The second root is " << root2 << endl << endl;
	}
};

Root::Root() // constructor: initializes data members from user input
{
	cout << "Enter the value for a: ";
	cin >> a;
	cout << "Enter the value for b: ";
	cin >> b;
	cout << "Enter the value for c: ";
	cin >> c;

	root1 = (-b + sqrt((b * b) - 4 * a * c)) / (2 * a); // quadratic formula, both roots
	root2 = (-b - sqrt((b * b) - 4 * a * c)) / (2 * a);
}

int main()
{
	int e = 0; // controls the main menu loop
	char mode; // selected menu option
	double fornum; // number to be formatted
	const int item_num = 5; // fixed size of the sorting array
	double numbers[item_num];
	double num1, num2, num3, num4, num5;
	string filename = "solution.txt"; // output file, written to the local directory

	cout << "Welcome to the interactive calculator!" << endl << endl;

	while (e == 0)
	{
		cout << "We offer the following modes: " << endl
			<< "[A]verage between numbers" << endl
			<< "[F]ormatting numbers" << endl
			<< "[R]andom number generator" << endl
			<< "[Q]uadratic root solving" << endl
			<< "[O]rganize numbers" << endl
			<< "[W]rite answer to file" << endl
			<< "[E]xit" << endl << endl;
		cout << "Please select your mode: ";
		cin >> mode;

		switch (mode)
		{
		case 'E': // exit
			e++;
			break;

		case 'A': // average of user-entered numbers
			cout << "The average is " << Average() << endl << endl;
			break;

		case 'F': // format a number (fixed or scientific notation, adjustable decimals)
			cout << "Enter your number for formatting: ";
			cin >> fornum;
			Formatting(fornum);
			break;

		case 'R': // random number generator
		{
			double random = rand();
			cout << "Your random number is " << random << endl << endl;
			displaynum = random;
			displaynum2 = 293894294982498429342.32938928; // reset, since root wasn't used
			break;
		}

		case 'O': // sort 5 user-entered numbers
			cout << "Enter 5 numbers for sorting: " << endl;
			cout << "Enter number 1: ";
			cin >> num1;
			cout << "Enter number 2: ";
			cin >> num2;
			cout << "Enter number 3: ";
			cin >> num3;
			cout << "Enter number 4: ";
			cin >> num4;
			cout << "Enter number 5: ";
			cin >> num5;

			numbers[0] = num1;
			numbers[1] = num2;
			numbers[2] = num3;
			numbers[3] = num4;
			numbers[4] = num5;

			Organize(numbers, item_num);
			break;

		case 'Q': // solve quadratic roots via the Root class
		{
			Root R_Object;
			R_Object.displayRoot();
			break;
		}
		case 'W': // write the most recent result to a local file
		{
			ofstream ofFile;
			ofFile.open(filename.c_str());
			if (displaynum == 29839242424839.042904920490291432323)
			{
				cout << "No answer has been saved, please try again once you have used the program"
					<< endl << endl;
			}
			else
			{
				ofFile << displaynum << ' ';
			}

			if (displaynum2 != 293894294982498429342.32938928)
			{
				ofFile << displaynum2; // writes the second root too, if quadratic mode was last used
			}

			ofFile.close();
			break;
		}
		default:
			cout << endl << "Please select a valid mode. Make sure to use uppercase letters." << endl << endl;
		}
	}

	cout << endl << "Thank you for using the interactive calculator!" << endl;

	return 0;
}

double Average() // averages a user-specified count of numbers
{
	int n;
	int m = 1;
	double average = 0;
	double summation = 0;
	double number;
	cout << endl << "How many numbers do you wish to average?: ";
	cin >> n;
	double l = n;

	for (; n >= 1; n--)
	{
		cout << "enter number " << m << ": ";
		cin >> number;
		m++;
		summation = summation + number;
	}

	average = summation / l;
	displaynum = average;
	displaynum2 = 293894294982498429342.32938928; // reset second value

	return average;
}

void Formatting(double num) // formats a number as fixed or scientific notation
{
	int n = 0;
	char code;

	cout << "How many decimals do you desire?: ";
	cin >> n;

	cout << endl << "Press S if you desire scientific display";
	cout << endl << "Press any other key for decimal display: ";
	cin >> code;

	switch (code)
	{
	case 'S':
		cout << "Your formatted number is:" << endl;
		cout << fixed << setprecision(n) << scientific << num << endl;
		break;
	default:
		cout << "Your formatted number is:" << endl;
		cout << fixed << setprecision(n) << num << endl;
	}

	cout << "Solutions will follow this formatting until changed." << endl << endl;

	return;
}

void Organize(double numbers[], int item_num) // bubble sort, ascending order
{
	int i, k, j;
	double sub1, sub2;

	for (k = 1; k <= item_num; k++)
	{
		for (j = 0; j < (item_num - 1); j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				sub1 = numbers[j];
				sub2 = numbers[j + 1];
				numbers[j] = sub2;
				numbers[j + 1] = sub1;
			}
		}
	}

	double* numbersaddress = numbers; // pointer-based traversal for display
	cout << "Numbers sorted from smallest to largest: " << endl;
	for (i = 0; i < item_num; i++)
	{
		cout << *(numbersaddress + i) << "   ";
	}
	cout << endl << endl;
}
