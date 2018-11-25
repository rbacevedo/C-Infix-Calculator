#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;



int main()
{
	deque<char> operators;
	deque<int> nums;
	string temp = "";
	int curr_result = 0;
	int result;
	bool again = false;
	bool invalid_input = false;
	string input;
	do {
		if (invalid_input)
		{
			cout << "Sorry you entered the wrong expression, please try again";
		}
		cin >> expression;
		for (int i = 0; i < expression.size(); ++i)
		{
			if (!(expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/' || (int(expression[i]) > 48 && int(expression[i]) < 57)))
			{
				cout << int(expression[i]) << endl << endl;
				invalid_input = true;
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
		nums.pop_back();
		cout << result << endl << endl;
		cout << "Want to run the calculaltor again?[yes, no]";
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


	} while (invalid_input || again);

	cout << "Thanks for using our amazing calculator";
	cout << "Have a wonderful day :)";
	//cout << endl << endl << nums.front() << endl << endl;
	system("pause");
	return 0;
}
