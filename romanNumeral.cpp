/***********************************************************************
Program that converts roman numerals to arabic number values.
***********************************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>
using namespace std;

const int I = 1;
const int V= 5;
const int X= 10;
const int L= 50;
const int C= 100;
const int D= 500;
const int M= 1000;


int main() {
	int total = 0,
		value = 0,
		oldVal = 0,
		oldestVal = 0;
	char ch = 0;
	bool syntaxError = 0;

	ifstream infile;
	infile.open("roman.txt");
	if (!infile)
	{
		cout << "Error opening file..." << endl;
		exit(1106);
	}
	
	while (infile)
	{
		
		infile.get(ch);
		ch = toupper(ch);
		cout << ch;

		if (ch == '\n') // resets value and displays total after hitting a new line
		{
			value = 0,
			oldVal = 0,
			oldestVal = 0;
			if (total > 0) //prevents multiple newlines from displaying a total
			cout << "The converted number is: " << total << endl << endl;
			total = 0;
		}
		else if (ch == 'M')
		{
			value = M;
			total += M;
		}
		else if (ch == 'D')
		{
			value = D;
			total += D;
		}
		else if (ch == 'C')
		{
			value = C;
			total += C;
		}
		else if (ch == 'L')
		{
			value = L;
			total += L;
		}
		else if (ch == 'X')
		{
			value = X;
			total += X;
		}
		else if (ch == 'V')
		{
			value = V;
			total += V;
		}
		else if (ch == 'I')
		{
			value = I;
			total += I;
		}
		else
		{
			syntaxError = 1;
			
		}


		//PROCESSES
		if (oldVal < value)
			total -= (oldVal * 2);


		//ERRORS
		if (oldestVal == oldVal && oldVal < value && oldestVal != 0)//oldestVal != 0 to false-positives in error checking
			syntaxError = 1;

		if (oldestVal < oldVal && oldVal < value && oldestVal != 0)
			syntaxError = 1;
		
		if (syntaxError)
		{
			value = 0,
			oldVal = 0,
			oldestVal = 0;
			total = 0;
			syntaxError = 0;
			cout << endl << "An illegal action has occured, moving to the next line" << endl << endl;
			infile.ignore(200, '\n');
		}
		
		oldestVal = oldVal;
		oldVal = value;

	}//end while

	infile.close();

	return 0;
} // end main
