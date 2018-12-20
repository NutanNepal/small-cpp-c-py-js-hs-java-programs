#include <iostream>
#include <set>
#include <string>

struct Animal {
	Animal(std::string na, int n, bool t) : name(na), numberOfLegs(n), tail(t) { ; }
	int numberOfLegs;
	std::string name;
	bool tail;
};

std::multiset<Animal*> _union(std::multiset<Animal*> A, std::multiset<Animal*> B);

int main()
{
	Animal* Cow = new Animal("Cow", 4, 1);
	Animal* Man = new Animal("Man", 2, 0);
	Animal* Spider = new Animal("Spider", 8, false);
	Animal* Fish = new Animal("Fish", 0, true);

	std::multiset<Animal*> A = { Cow, Man, Spider };
	std::multiset<Animal*> B = { Man, Man, Spider, Fish };
	std::multiset<Animal*> unionAB = _union(A, B);

	for (std::multiset<Animal*>::iterator it = unionAB.begin(); it != unionAB.end(); it++) {
		std::cout << (*it)->name;
		std::printf(" has %d legs and %d tail\n", (*it)->numberOfLegs, (*it)->tail);
	}

	return 0;
}

std::multiset<Animal*> _union(std::multiset<Animal*> A, std::multiset<Animal*> B) {
	std::multiset<Animal*> returnset;
	returnset.insert(A.begin(), A.end());
	returnset.insert(B.begin(), B.end());
	return returnset;
}