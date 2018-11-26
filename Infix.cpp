#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <windows.h>

using namespace std;

string char_repeater(int n, char x)
{
	string character = "  ";
	for (; n > 0; n--)
	{
		character += x;
	}
	character += "\n";
	return character;
}


void welcome_message()
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

void invalid_input_message()
{
	system("cls");
	cout << char_repeater(104, '*');
	cout << "  ** Sorry you entered an invalid input expression, please try again                                     **\n";
	cout << char_repeater(104, '*');
	cout << "\n";
}

void result_message(int result)
{
	cout << "\n";
	cout << char_repeater(40, '*');
	cout << "  Your result is ";
	cout << result << "\n";
	cout << char_repeater(40, '*');
	cout << "\n";
}

void run_again()
{
	cout << "\n  Want to run the calculator again? [yes, no]: ";
}

void bye_message()
{
	cout << "\n\n";
	cout << char_repeater(104, '*');
	cout << "  ** Thanks for using our amazing calculator                                                            **\n";
	cout << "  ** Have a wonderful day :)                                                                            **\n";
	cout << char_repeater(104, '*');
	cout << "\n";
}


int main()
{
	string expression;
	deque<char> operators;
	deque<int> nums;
	string temp = "";
	int curr_result = 0;
	int result = 0;
	bool again = false;
	bool invalid_input = false;
	string input;
	do {
		operators.clear();
		nums.clear();
		system("cls");
		if (invalid_input)
		{
			invalid_input_message();
		}
		welcome_message();
		again = false;
		invalid_input = false;
		result = 0;
		cin >> expression;
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
			if (expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/')
			{
				operators.push_back(expression[i]);
			}

			if (i == expression.size() - 1)
			{
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
		result_message(result);
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
	} while (invalid_input || again);
	bye_message();
	//cout << endl << endl << nums.front() << endl << endl;
	system("pause");
	return 0;
}
