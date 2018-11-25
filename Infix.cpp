#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{

	deque<char> operators;
	deque<int> nums;
	int index = 0;
	string expression = "1+2*4+9-6";
	string temp = "";
	int curr_result = 0;
	int result;
	for (int i = 0; i < expression.size(); ++i)
	{
		if (i == expression.size() - 1)
		{
			temp += expression[i];
		}

		if (!(expression[i] == '+' || expression[i] == '-'
			|| expression[i] == '*' || expression[i] == '/' || i == expression.size() - 1))
		{
			temp += expression[i];
			//cout << temp << endl;
		}

		if (expression[i] == '6' || expression[i] == '9')
		{
			cout << "Here" << endl << endl;
		}

		else
		{
			//cout << temp << endl << endl;
			nums.push_back(stoi(temp));
			//cout << temp << endl << endl;
			if (!(i == expression.size() - 1))
			{
				temp = "";
			}
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
						////cout << curr_result << endl;
					}
					else
					{
						curr_result = nums[nums.size() - 2] / nums.back();
						operators.pop_back();
						nums.pop_back();
						nums.pop_back();
						nums.push_back(curr_result);
					}

					//cout << nums.back() << endl << endl;
					//cout << nums[nums.size() - 2] << endl << endl;
					
				}

				else if (expression[i] == '+' || expression[i] == '-')
				{
					//cout << operators.front() << endl << endl;
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
						curr_result = nums[1] - nums.front();
						operators.pop_front();
						nums.pop_front();
						nums.pop_front();
						nums.push_front(curr_result);
					}
					
				}
				//nums.push_front(curr_result);
				//cout << curr_result << endl << endl;
			}
		}
		if (expression[i] == '+' || expression[i] == '-'
			|| expression[i] == '*' || expression[i] == '/')
		{
			operators.push_back(expression[i]);
		}

		if (i == expression.size() - 1)
		{
			if (operators.front() == '+')
			{
				result = nums.front() + nums[1];
				nums.pop_back();
				nums.pop_back();
				operators.pop_back();
				nums.push_back(result);
			}
			else if (operators.front() == '-')
			{
				result = nums[1] - nums.front();
				nums.pop_back();
				nums.pop_back();
				operators.pop_back();
				nums.push_back(result);
			}
			else if (operators.front() == '*')
			{
				result = nums.front() * nums[1];
				nums.pop_back();
				nums.pop_back();
				operators.pop_back();
				nums.push_back(result);
			}
			else if (operators.front() == '/')
			{
				result = nums[0] / nums[1];
				nums.pop_back();
				nums.pop_back();
				operators.pop_back();
				nums.push_back(result);
			}
		}
		//cout << curr_result << endl << endl;
	}
	//nums.push_back(stoi(temp));

	//Need to do the very last operation

	/*if (operators.front() == '+')
	{
		result = nums.front() + nums[1];
		nums.pop_back();
		nums.pop_back();
		operators.pop_back();
		nums.push_back(result);
	}

	else if (operators.front() == '-')
	{
		result = nums[1] - nums.front();
		nums.pop_back();
		nums.pop_back();
		operators.pop_back();
		nums.push_back(result);
	}

	else if (operators.front() == '*')
	{
		result = nums.front() * nums[1];
		nums.pop_back();
		nums.pop_back();
		operators.pop_back();
		nums.push_back(result);
	}

	else if (operators.front() == '/')
	{
		result = nums[nums.size() - 2] / nums.back();
		nums.pop_back();
		nums.pop_back();
		operators.pop_back();
		nums.push_back(result);
	}*/

	cout << endl << endl << nums.front() << endl << endl;
	
	system("pause");
	return 0;
}
