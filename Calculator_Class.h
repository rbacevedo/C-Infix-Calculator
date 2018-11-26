#ifndef CALCULATOR_CLASS_H
#define CALCULATOR_CLASS_H
#include <string>
#include <deque>

using namespace std;

//Infix Calculator Class
class Calculator
{
public:
	//Constructor
	Calculator()
	{
		temp = "";
		curr_result = 0;
		again = false;
		invalid_input = false;
	};
	// Lets you repeat a symbol n times for the welcome message
	string char_repeater(int n, char x);
	// Lets you add a welcome message for the user
	void welcome_message();
	// Lets you check if the inputted number is a whole number or not
	void invalid_input_message();
	// Lets you check if the following operation is valid or not
	void result_message();
	// Performs the final operations
	void run_again();
	// Bye message for the calculator
	void bye_message();
	//Function where the bulk of the work is
	// Calculator main function
	void calculate();
private:
	// The algebraic expression calculator
	string expression;
	// deque for the operators
	deque<char> operators;
	// deque for each number of the expression
	deque<int> nums;
	// temporary value that stores the current number when parsing the elements in the expression
	string temp = "";
	// The latest value 
	int curr_result = 0;
	// the final result of the calculator
	int result = 0;
	// bool that lets you iterate over and over again to calculate new inputted expressions
	bool again = false;
	// bool that tells you if the input is invalid or not
	bool invalid_input = false;
	// Yes or no value inputted by the user to start the calculator again
	string input;
};

#endif // !CALCULATOR_CLASS_H
