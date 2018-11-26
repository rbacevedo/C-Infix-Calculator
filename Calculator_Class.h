#ifndef CALCULATOR_CLASS_H
#define CALCULATOR_CLASS_H
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <windows.h>

using namespace std;

class Calculator
{
public:
	Calculator()
	{
		temp = "";
		curr_result = 0;
		again = false;
		invalid_input = false;
	};
	// Lets you repeat a symbol n times for the welcome message
	string char_repeater(int n, char x);
	//Lets you add a welcome message for the user
	void welcome_message();
	//Lets you check if the inputted number is a whole number or not
	void invalid_input_message();
	//Lets you check if the following operation is valid or not
	void result_message();
	//Performs the final operations
	void run_again();

	void bye_message();
	void calculate();
private:
	string expression;
	deque<char> operators;
	deque<int> nums;
	string temp = "";
	int curr_result = 0;
	int result = 0;
	bool again = false;
	bool invalid_input = false;
	string input;
};

#endif // !CALCULATOR_CLASS_H
