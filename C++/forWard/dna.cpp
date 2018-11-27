#include <string>
#include <iostream>
#include <map>

std::string DNAStrand(const std::string& dna)
{
  std::map<char, char> dna_ = {{'A','T'}, {'T','A'}, {'G','C'}, {'C','G'}};
  std::string output;
  for (int i = 0; i < dna.length(); i++){
      output += dna_[dna[i]];
  }
  return output;
}

int main(){
    std::string str = "ATGC";
    std::cout << DNAStrand(str);
}