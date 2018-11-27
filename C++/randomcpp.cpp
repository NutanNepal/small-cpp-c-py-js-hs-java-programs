#include<iostream>
#include<string>

template <class wow>
struct structure{
    int var;
    void ret(int x);
};

template <class wow>
void structure<wow>::ret(int x){
    var = x;
    std::cout << "kys" << std::endl;
}

void test(int **x){
    **x = 2;
}

int main(){
    structure<int> x1;
    int x = 1;
    x1.ret(x);
    std::cout << x1.var << std::endl;
    int* a = &x;
    std::cout << &a << std:: endl;
    std::cout << a << std:: endl;
    std::cout << *a << std:: endl;
    test(&a);
    std:: cout << "break" << std::endl;
    std::cout << &a << std:: endl;
    std::cout << a << std:: endl;
    std::cout << *a << std:: endl;
    std:: cout << "break" << std::endl;
    std::cout << x << std:: endl;
    return 0;
}