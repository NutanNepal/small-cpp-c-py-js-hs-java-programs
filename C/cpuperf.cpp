#include <iostream>
using namespace std;
#define row 1572864
#define STRIDE 1 //change this to 2,4,8,16,32,64 and 128
#define iter 10000

class performance {
    int A[row];
    public:
    void init_A (){
    for (int i=0; i<row; i++){
        A[i]=i*i;//fill the array A with something
        }
    }
    void stride_A(){ //this is our benchmark
        int count=0;
        for (int i=0;i<row;i=i+STRIDE){
            if(count<10){
                cout<< A[i]<<" Hello ";
                count++;
            }
            else{
                break;
            }
        }
    }
};

int main(){
    performance perf;
    perf.init_A();//initialize A
    /*start region of interest (ROI)*/
    for(int i=0;i<iter;i++){
        perf.stride_A();
    }
    /*end region of interest (ROI)*/
    return 0;
}