
#include <iostream>
#include <bitset>
#include <map>
#include <utility>

using namespace std;

int substitution(int word){//word is 8 bit word
    int upperBits = (0xf0 & word) >> 4;
    int lowerBits = 0x0f & word;
    upperBits = ((upperBits + 1) * 7) % 16;
    lowerBits = ((lowerBits + 1) * 7) % 16;
    upperBits = upperBits << 4;
    return (upperBits | lowerBits);
}

int reverseSubstitution(int word, map<int, int> pairs){
    int upperBits = (0xf0 & word) >> 4;
    int lowerBits = (0x0f & word);
    //reversing the modulo functions
    upperBits = pairs[upperBits];
    lowerBits = pairs[lowerBits];
    return ((upperBits << 4 | lowerBits) & 0x000000ff);
}

map<int, int> genSubstitutionPairs(){
  map<int, int> pairs;
  for(int i = 0; i <= 15; i++){
    int Si = ((i + 1) * 7) % 16;
    pairs.insert(pair<int, int>(Si, i));
  }
  return pairs;
}

int permutation(int word){
    int circularLeftShifted = (word << 2) | (word >> 6); //(word << shiftamount) | (word >> (WORD_LENGTH - shiftamount))
    return circularLeftShifted;
}

int reversePermutation(int word){
    int circularRightShifted = (word >> 2) | (word << 6);
    return (circularRightShifted & 0x000000ff);
}

int cipher(int word, int key){
  //Round 0
  int firstKey = (key & 0xff000000) >> 24;
  word = (word ^ firstKey);
  //Round 1
  int secondKey = (key & 0x00ff0000) >> 16;
  word = substitution(word);
  word = permutation(word);
  word = word ^ secondKey;
  // word = (permutation(substitution(word)) ^ secondKey);
  //Round 2
  int thirdKey = (key & 0x0000ff00) >> 8;
  word = substitution(word);
  word = permutation(word);
  word = word ^ thirdKey;
  // word = (permutation(substitution(word)) ^ thirdKey);
  //Round 3
  int fourthKey = (key & 0x000000ff);
  word = substitution(word);
  word = (word ^ fourthKey);
  return word;
}

int reverseCipher(int word, int key){
  map<int, int> subPairs = genSubstitutionPairs();
  //Reversing round 3
  int fourthKey = (key & 0x000000ff);
  word = word ^ fourthKey; // reversing the final XOR
  word = reverseSubstitution(word, subPairs);
  //Reversing round 2
  int thirdKey = (key & 0x0000ff00) >> 8;
  word = word ^ thirdKey;
  word = reversePermutation(word);
  word = reverseSubstitution(word, subPairs);
  //Reversing round 1
  int secondKey = (key & 0x00ff0000) >> 16;
  word = word ^ secondKey;
  word = reversePermutation(word);
  word = reverseSubstitution(word, subPairs);
  //Reversing round 0
  int firstKey = (key & 0xff000000) >> 24;
  word = word ^ firstKey;
  return word;
}

void electronicCodeBook(){
  int key = 0x98267351;
  int cleartext[] = {0x61, 0x62, 0x61};
  for(int i = 0; i < 3; i++){
    cout << hex << cipher(cleartext[i], key);
  }
  cout << endl;
}

void cipherBlockChainEncrypt(){
  int key = 0x98267351;
  int cleartext[] = {0x68, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64};
  int currentIV = 0x42;
  for(int i = 0; i < 11; i++){
    int currentWord = cleartext[i] ^ currentIV;
    int resultCipher = cipher(currentWord, key);
    cout << hex << resultCipher;
    currentIV = resultCipher;
  }
  cout << endl;
}

void cipherBlockChainDecrypt(){
  int ciphertext[] = {0x34, 0x51, 0xf6, 0xfd, 0x3b, 0x61, 0x26, 0xe0, 0xae, 0x58, 0x15};
  int currentIV = 0x42;
  int key = 0x98267351;
  for(int i = 0; i < 11; i++){
     int resultCipher = reverseCipher(ciphertext[i], key);
     resultCipher = (resultCipher ^ currentIV);
     cout << hex << resultCipher;

     currentIV = ciphertext[i];
  }
  cout << endl;
}

int main(){
  electronicCodeBook();
  cipherBlockChainEncrypt();
  cipherBlockChainDecrypt();
}
