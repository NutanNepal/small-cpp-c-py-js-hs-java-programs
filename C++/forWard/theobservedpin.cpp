#include <iostream>
#include <string>
#include <vector>
#include <map>

const std::map<char, std::vector<char>> MAPPER = {
    {'0', {'0', '8'}},
    {'1', {'1', '2', '4'}},
    {'2', {'1', '2', '3', '5'}},
    {'3', {'2', '3', '6'}},
    {'4', {'1', '4', '5', '7'}},
    {'5', {'2', '4', '5', '6', '8'}},
    {'6', {'3', '5', '6', '9'}},
    {'7', {'4', '7', '8'}},
    {'8', {'0', '5', '7', '8', '9'}},
    {'9', {'6', '8', '9'}}
};

std::vector<std::string> get_pins(std::string observed) {
    int pointer = 0;
    std::vector<std::vector<std::string>> probable;
    for(std::string::iterator i = observed.begin(); i != observed.end(); i++){  //iterates through the input
        std::vector<std::string> nth_vec;
        if (probable.size() == 0){
            for(int j = 0; j < (MAPPER.at(*i)).size(); j++){
                nth_vec.push_back(std::string(1, MAPPER.at(*i)[j]));
            }
        }
        else{
            for(int j = 0; j < (MAPPER.at(*i)).size(); j++){
                for(int k = 0; k < probable[pointer - 1].size(); k++){
                    nth_vec.push_back(probable[pointer - 1][k] + MAPPER.at(*i)[j]);
                }
            }
        }
        probable.push_back(nth_vec);
        pointer++;
    }
    return probable[probable.size() - 1];
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> probable = get_pins("0123");
    for (int i = 0; i < probable.size(); i++){
        std::cout << probable[i] << ", ";
    }
    return 0;
}