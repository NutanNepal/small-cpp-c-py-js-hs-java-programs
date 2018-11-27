#include <iostream>
#include <vector>

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

int DoubleLinear::dblLinear(int n){
    std::vector<int> arr_ = {1};
    int ith = 0, jth = 0, count = 0;
    for (int i = 0; i < n; i++){
        if (2 * arr_[ith] < 3 * arr_[jth]) arr_.push_back(2 * arr_[ith++] + 1);
        else if (2 * arr_[ith] > 3 * arr_[jth]) arr_.push_back(3 * arr_[jth++] + 1);
        else{
            arr_.push_back(2 * arr_[ith] + 1);
            ith ++; jth ++;
        }
    }
    return arr_[n];
}

int main(){
    DoubleLinear A;
    std::cout << A.dblLinear(20) ;
}

//[1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, 28, 31, 39, 40]