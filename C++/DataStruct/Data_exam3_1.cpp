#include <iostream>
#include <stack>

struct Priority {
	Priority(int i = 0): priority_(i) { ; }
	int priority_;
};

std::stack<Priority> sortStack(std::stack<Priority> &input){
	std::stack<Priority> tempStack;
	while (!input.empty()){
		Priority temp = input.top();
		input.pop();
		while (!tempStack.empty() && tempStack.top().priority_ < temp.priority_){
			input.push(tempStack.top());
			tempStack.pop();
		}
		tempStack.push(temp);
	}
    return tempStack;
}

int main()
{
	Priority A = { 3 }; Priority B = { 5 }; Priority C = { 0 }; Priority D = { 8 };
	std::stack<Priority> customer;
	customer.push(A); customer.push(B); customer.push(C); customer.push(D);
	customer = sortStack(customer);
	std::cout << customer.top().priority_ << std::endl;
	customer.pop();
	std::cout << customer.top().priority_ << std::endl;
	Priority E = { 1 }; customer.push(E);
	std::cout << customer.top().priority_ << std::endl;
    return 0;
}