#include <iostream>
#include <string>
using namespace std;

class Fruit{
	private:
		string name;
		string taste;
		int nutritionval;
	public:
		void setproperties(string somename, string taste1, int val){
			name = somename;
			taste = taste1;
			nutritionval = val;
		}
		string getname(){
			return name;
		}
		string gettaste(){
			return taste;
		}
		int getnutrition(){
			return nutritionval;
		}
};

int main()
{
	unsigned short num, nutritionvalue, propertychoice;
	string namee, tastee;

	cout << "We have 2 fruits. Choose one: " << endl;
	cout << "1. Apple" << endl;
	cout << "2. Banana" << endl;
	cin >> num;
	Fruit Apple;
	Fruit Banana;

	cout << "What do you call it?" << endl;
	cin >> namee;
	cout << "How was the fruit?" << endl;
	cin >> tastee;
	cout << "Enter the nutrition value: ";
	cin >> nutritionvalue;
	switch (num){
		case 1:
			Apple.setproperties(namee, tastee, nutritionvalue);
			break;
		case 2:
			Banana.setproperties(namee, tastee, nutritionvalue);
	}

	cout << "What do u want to know about ur fruit?" << endl;
	cout << "1. name" << endl;
	cout << "2. taste\n3. nutritionvalue" << endl;
	cin >> propertychoice;
	if (num == 1){
		switch (propertychoice){
			case 1:
				cout << Apple.getname() << endl;
				break;
			case 2:
				cout << Apple.gettaste() << endl;
				break;
			case 3:
				cout << Apple.getnutrition() << endl;
		}

	}
	if (num == 2){
		switch (propertychoice){
			case 1:
				cout << Banana.getname() << endl;
				break;
			case 2:
				cout << Banana.gettaste() << endl;
				break;
			case 3:
				cout << Banana.getnutrition() << endl;
		}
	}
	return 0;
}
