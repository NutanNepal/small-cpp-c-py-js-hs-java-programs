#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Expr{
private:
  string getInput;
  string getexpression(string str, int position, int &left, int &right);
  string changestr(string str, string evaluated, int start, int end);
  string geteval(string[] toeval);
public:
  Expr(){
    cout << "Enter the expression: " << endl;
    getline(cin, getInput);
  }
  double eval();
  ~Expr(){};
};

double Expr::eval(){
  string toeval, evaluated;
  char sign;
  char signs[] = {'/', '*', '+', '-'}
  string modifiedstr = getInput;
  bool flag = true;
  int signposition;
  for (int _ = 0; _ < 4; _++){
    int leftsignpos = -1, rightsignpos = -1;
    sign = signs[_];
    while (flag) {
      flag = false;
      for (int i = 0; i < modifiedstr.length(); i++){
        if (modifiedstr[i] == sign){
          flag = true;
          signposition = i;
          break;
        }
      }
    }
    if (flag){
      toeval = getexpression(modifiedstr, signposition, leftsignpos, rightsignpos);
      evaluated = geteval(toeval, sign);
      modifiedstr = changestr(modifiedstr, leftsignpos, rightsignpos, evaluated);
    }
  }
}

string Expr::getexpression(string str, int position, int &left, int &right){
  string expression[] = {'0', '0'};
  for(int i = position - 1; i > 0; i++){
    if (str[i] == '*' || str[i] == '+' || str[i] == '-'){
      left = i;
      break;
    }
    left = i;
  }
  for(int i = position + 1; i < str.length(); i++){
    if (str[i] == '*' || str[i] == '+' || str[i] == '-'){
      right = i;
      break;
    }
    right = i;
  }
  expression[0] = str.substr(left + 1 , position - left - 1);
  expression[1] = str.substr(position + 1, right - position - 1);
  return expression;
}

string Expr::geteval(string[] toeval, sign){
  double num1, num2, evaluated;
  stringstream toeval[0];
  toeval[0] >> num1;
  stringstream toeval[1];
  toeval[1] >> num2;
  switch (sign) {
    case '/': evaluated = num1 / num2;
    break;
    case '*': evaluated = num1 * num2;
    break;
    case '+': evaluated = num1 + num2;
    break;
    case '-': evaluated = num1 - num2;
    break;
  }

  return to_string(answer);
}


string Expr::changestr(string str, string evaluated, int start, int end){
  string modified;
  modified = str.substr(0, start);
  modified.append(evaluated).append(syt.substr(end+1, str.length() - end - 1));
  return modified;
}

int main() {
  Expr expression;
  double answer;
  answer = expression.eval();
  cout << "The answer is : " << answer <<endl;
  return 0;
}
