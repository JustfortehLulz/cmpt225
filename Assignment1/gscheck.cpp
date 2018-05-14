#include <iostream>
#include <string>
#include <istream>
#include <algorithm>
#include "char_stack.cpp"

using namespace std;

int main()
{
	char_stack* bracketStack = new char_stack();

	char input[256];
	int length = 0;
	char openBracket,errChar;
	int temp,errTemp;
	int linenumber = 1;
	while(cin.getline(input,256)) 
	{

		length = cin.gcount(); // length of the line that was read

		for(int i = 0;i < length;i++) //reading the line that was inputed 
		{
			if(input[i] == '(' || input[i] == '{' || input[i] == '[')
			{
				bracketStack->push(input[i]); //pushes ( , { , or [
			}
			else if(input[i] == ')' || input[i] == '}' || input[i] == ']')
			{
				if(bracketStack->empty()) // checks if stack is empty
				{

					cout << "Error on line: " << linenumber << ": ";
					cout << "Too many " << input[i] << endl;
					for (int j = 0; j <= i;j++) // outputs the line with the error character
					{
						cout << input[j];
					}
					cout << '\n';
					for (int errorCount = 0; errorCount <= i ;errorCount++) // outputs the number of spaces
					{
						cout << ' ';
					}
					for (int k = i+1; k<length; k++) // outputs the line after error 
					{
						cout << input[k];
					}
					cout << '\n';
					return -1;
				}
				openBracket = bracketStack->top(); //checks the top of the stack

				if(input[i] == ')') //closing bracket is ')'
				{
					temp = (int) input[i] - 1;
					if((int) openBracket == temp) // checks if the matching '(' is at the top of the stack
					{
						bracketStack->pop();
					}
					else // when there is a bracket mismatch
					{

						errTemp = (int) openBracket + 2; 
						errChar = (char) errTemp;
						cout << "Error on line " << linenumber << ": ";
						cout << "Read " << input[i] << ", expected " << errChar << endl;

						for (int j = 0; j <= i;j++) //outputs the line with the error character
						{
							cout << input[j];
						}
						cout << '\n';
						for (int errorCount = 0; errorCount <= i ;errorCount++) // outputs the number of spaces
						{
							cout << ' ';
						}
						for (int k = i+1; k<length; k++) // outputs the line after error 
						{
							cout << input[k];
						}
						cout << '\n';
						return -1;
					}
				}
				else // for when the closing bracket is },]
				{
					temp = (int) input[i] - 2;
					if((int) openBracket == temp) // checks if the matching { or [ is at the top of the stack
					{
						bracketStack->pop();
					}
					else
					{
						if (openBracket == '(') // when the opening bracket is { or [ and closing is )
						{
							
							errTemp = (int) openBracket + 1;
							errChar = (char) errTemp;
							
							cout << "Error on line " << linenumber << ": ";
							cout << "Read " << input[i] << ", expected " << errChar << endl;
							
							for (int j = 0; j <= i;j++) //outputs the line with the error character
							{
								cout << input[j];
							}
							cout << '\n';
							for (int errorCount = 0; errorCount <= i ;errorCount++) // outputs the number of spaces
							{
								cout << ' ';
							}
							for (int k = i+1; k<length; k++) // outputs the line after error 
							{
								cout << input[k];
							}
							cout << '\n';
							return -1;
						}
						else // when the there is a bracket mismatch between { and [
						{

							errTemp = (int) openBracket + 2;
							errChar = (char) errTemp;
							cout << "Error on line " << linenumber << ": ";
							cout << "Read " << input[i] << ", expected " << errChar << endl;

							for (int j = 0; j <= i;j++) //outputs the line with the error character
							{
								cout << input[j];
							}
							cout << '\n';
							for (int errorCount = 0; errorCount <= i ;errorCount++) // outputs the number of spaces
							{
								cout << ' ';
							}
							for (int k = i+1; k<length; k++) // outputs the line after error 
							{
								cout << input[k];
							}
							cout << '\n';
							return -1;
						}
					}
				}
			}
		}
		linenumber++;
	}
	if ( !(bracketStack->empty()) ) //checks if stack is empty of not
	{
		errChar = bracketStack->pop();
		cout << "Error at end of file: " << "Too many " << errChar << endl; // stack is not empty
	}
	else
	{
		cout << "No Errors Found" << endl; // stack is empty
	}
	delete bracketStack;
	return 0;
}