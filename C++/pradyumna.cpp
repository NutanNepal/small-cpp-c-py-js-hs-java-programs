#include<iostream>
#include<string>
#include<sstream>
#include<math.h>

using namespace std;

class Expr {
	string userInput;
	int len;
	char sign[4] = { '/','*','+','-' };
	int startPos, endPos;
	double num1, num2, answer;

public:
	Expr();
	string getInput();																	//receives string input
	void setInput(string str);															//sets input to variable of class
	string reverse(string str);															//returns the reverse of a string
	double convert(string nums);														//converts a string to double
	double front(string expr, char sign );								//returns number in front of the operand as double
	double back(string expr, char sign);									//returns number in back of the operand as double
	double evaluate(double num1, double num2, char sign);								//evaluates and returns answer
	bool findSign(string str, char sign);												//returns the location of sign on string
	string makeString(string str, double answer, int startPos, int endPos, int length);//updates the string
	void printString(string str);														//calculates all of above and returns final answer
	void calculate();
	~Expr();

};

Expr::Expr() {
	}

string Expr::getInput() {
	string str;
	cout << "Enter expression: ";
	getline(cin, str);
	return str;
}

void Expr::setInput(string str) {
	userInput = str;
}

string Expr::reverse(string str) {

	int len = str.length();
	char temp;
	for (int i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
	}
	return str;
}
double Expr::convert(string nums) {
	double ab;

	stringstream ss;
	ss << nums;
	ss >> ab;
	return ab;
}

double Expr::front(string expr, char sign) {
	string temp;
	string temp2;
	int a = expr.find(sign);
	if (a == 0 && sign == '-') {
		for (int j = 1,k=0; j < expr.length(); j++,k++) {
			temp2[k] = expr[j];
		}
		a = temp2.find(sign);
	}
	int i;
	double number;

	for (i=a-1; i >= 0 && expr[i] != '/' && expr[i] != '*' && expr[i] != '+' && expr[i] != '-'; i--) {
		temp = temp + expr[i];
	}

	temp = reverse(temp);
	startPos = i+1;
	number = convert(temp);

	if (startPos >= 1) {
		if (expr[startPos - 1] == '-') {
			/*if (expr[startPos - 2] == '-') {
				number = number;
			}
			else {*/
				number = -number;
			//}
		}
	}
	else {
		if (expr[startPos] == '-') {number = -number;}
	}
	cout << number <<"----------" <<endl;
	return number;

}

double Expr::back(string expr, char sign) {
	string temp;
	int a = expr.find(sign,1);
	int i;
	double number;

	for (i = a + 1; i != expr.length() && expr[i] != '/' && expr[i] != '*' && expr[i] != '+' && expr[i] != '-'; i++) {
		temp = temp + expr[i];
	}
	endPos = (i - 1) ;
	number = convert(temp);


	return number;
}

double Expr::evaluate(double num1, double num2, char sign) {
	switch (sign) {
	case '/':
		return num1 / num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	}
}

bool Expr::findSign(string str, char sign) {
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == sign) {
			return true;
			break;
		}
	}
	return false;
}

string Expr::makeString(string str, double answer, int startPos, int endPos, int length) {
	string temp;
	string check;
	string converted;

	check = str.substr(0, startPos);
	converted = to_string(answer);
	temp.append(converted);
	temp.append(str.substr(endPos + 1, length - (endPos+1)));
	str.clear();
	str = temp;

	return str;
}

void Expr::printString(string str) {
	int point = str.find('.');
	if (point) {
		for (int i = 0; i <= point + 2; i++) {
			cout << str[i];
		}
	}
	else {
		cout << str << endl;
	}
}

void Expr::calculate() {
	for (int i = 0; i < 4; i++) {
		while (findSign(userInput, sign[i])) {
			len = userInput.length();
			num1 = front(userInput, sign[i]);
			num2 = back(userInput, sign[i]);
			answer = evaluate(num1, num2, sign[i]);
			answer = roundf(answer * 100) / 100;
			userInput = makeString(userInput, answer, startPos, endPos, len);
			cout << userInput << endl;
		}
	}
	cout << "Evaluation of expression: ";
	printString(userInput)
	cout << endl;
}

Expr::~Expr() {

}

int main() {

	string input;

	Expr expr;
	input = expr.getInput();
	expr.setInput(input);
	expr.calculate();

	system("pause");
	return 0;
}
