//#include <iostream>

using namespace std;

int main(){
  int a = 3;
  int *pointa = &a;
  std::cout << pointa << '\n';
  std::cout << pointa + 1 << '\n';
  std::cout << pointa + 2 << '\n';
  std::cout << pointa + 3 << '\n';
}
