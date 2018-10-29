#include <iostream>
#include <string>

using namespace std;

class box_shape{
  public:
  virtual void area(){
    ;
  }

};
class box_rectangle: public box_shape{
  int base, height;
  public:
  box_rectangle(int a, int b): base(a), height(b){
    ;
  }
  float area(int a, int b){
    return a*b;
  }

};
class box_triangle: public box_shape{
  public:
  float area(int b, int h){
    return 0.5*b*h;
  }
};
class box_square: public box_shape{
  public:
  float area(int a){
    return a*a;
  }
};

int calculate_area(box_shape *box[], int n){

}

int main() {

  return 0;
}
