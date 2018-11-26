#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <windows.h>
#include "Calculator_Class.h"
using namespace std;

// Repeat character values for aesthetic purposes
string Calculator::char_repeater(int n, char x)
{
	string character = "  ";
	for (; n > 0; n--)
	{
		character += x;
	}
	character += "\n";
	return character;
}

// Calculator Welcome Message
void Calculator::welcome_message()
{
	cout << char_repeater(104, '*');
	cout << "  ** Hello Welcome to the calculator of your dreams                                                     **\n";
	cout << "  ** In this calculator you can perform addition(+), substraction(-), multiplication(*) and division(/) **\n";
	cout << "  ** This calculator sadly does not support operation on parenthesis yet                                **\n";
	cout << "  ** An example of an operation that you can perform is 5+6*7-8/8-29                                    **\n";
	cout << char_repeater(104, '*');
	cout << "\n";
	cout << "  Input Expression = ";
}

// Message if you inputted an invalid input
void Calculator::invalid_input_message()
{
	system("cls");
	cout << char_repeater(104, '*');
	cout << "  ** Sorry you entered an invalid input expression, please try again                                     **\n";
	cout << char_repeater(104, '*');
	cout << "\n";
}

// Result of the particular calculation
void Calculator::result_message()
{
	cout << "\n";
	cout << char_repeater(40, '*');
	cout << "  Your result is ";
	cout << result << "\n";
	cout << char_repeater(40, '*');
	cout << "\n";
}

// Message to prompt the user to run the calculator again
void Calculator::run_again()
{
	cout << "\n  Want to run the calculator again? [yes, no]: ";
}

// Bye message
void Calculator::bye_message()
{
	cout << "\n\n";
	cout << char_repeater(104, '*');
	cout << "  ** Thanks for using our amazing calculator                                                            **\n";
	cout << "  ** Have a wonderful day :)                                                                            **\n";
	cout << char_repeater(104, '*');
	cout << "\n";
}

// Use the infix calculator
void Calculator::calculate()
{
	do {
		//clear the values in case that invalid input was given
		operators.clear();
		nums.clear();
		system("cls");
		// if invalid input was given
		if (invalid_input)
		{
			invalid_input_message();
		}
		// welcome message
		welcome_message();
		again = false;
		invalid_input = false;
		result = 0;
		// Inputting expression
		cin >> expression;
		// loop to parse the input string and perform the desired operations
		for (int i = 0; i < expression.size(); ++i)
		{
			if (!(expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/' || (int(expression[i]) >= 48 && int(expression[i]) <= 57)))
			{
				invalid_input = true;
				break;
			}
			else
			{
				invalid_input = false;
			}
			if (i == expression.size() - 1)
			{
				temp += expression[i];
			}

			if (!(expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/' || i == expression.size() - 1))
			{
				temp += expression[i];
			}
			else
			{
				nums.push_back(stoi(temp));
				temp = "";

				if (nums.size() > 1)
				{
					if (operators.back() == '*' || operators.back() == '/')
					{
						if (operators.back() == '*')
						{
							curr_result = nums.back() * nums[nums.size() - 2];
							operators.pop_back();
							nums.pop_back();
							nums.pop_back();
							nums.push_back(curr_result);
						}
						else
						{
							//To prevent division by 0
							if (nums.back() == 0)
							{
								invalid_input = true;
								break;
							}
							curr_result = nums[nums.size() - 2] / nums.back();
							operators.pop_back();
							nums.pop_back();
							nums.pop_back();
							nums.push_back(curr_result);
						}
					}

					else if (expression[i] == '+' || expression[i] == '-')
					{
						if (operators.front() == '+')
						{
							curr_result = nums.front() + nums[1];
							operators.pop_front();
							nums.pop_front();
							nums.pop_front();
							nums.push_front(curr_result);
						}
						else if (operators.front() == '-')
						{
							curr_result = nums.front() - nums[1];
							operators.pop_front();
							nums.pop_front();
							nums.pop_front();
							nums.push_front(curr_result);
						}

					}
				}
			}
			//place the new operator value after the operation has been performed
			if (expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/')
			{
				operators.push_back(expression[i]);
			}

			//If there are any elements left in the deques perform the required operations on them
			if (i == expression.size() - 1)
			{
				// If user inputs 2+ or something similar repeat the loop
				if (nums.size() == 1 && operators.size() == 1)
				{
					invalid_input = true;
					break;
				}
				result = nums.back();
				while (!operators.empty())
				{
					if (operators.front() == '+')
					{
						result = nums.front() + nums[1];
						nums.pop_front();
						nums.pop_front();
						operators.pop_front();
						nums.push_front(result);
					}
					else if (operators.front() == '-')
					{
						result = nums.front() - nums[1];
						nums.pop_front();
						nums.pop_front();
						operators.pop_front();
						nums.push_front(result);
					}
				}

			}
		}
		result_message();
		if (!invalid_input)
		{
			nums.pop_back();
			run_again();
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);
			if (input == "YES")
			{
				again = true;
			}
			else
			{
				again = false;
			}
		}
	} while (invalid_input || again); //Run loop as long as the user wants to keep calculaing or invalid input was given
	bye_message();
}