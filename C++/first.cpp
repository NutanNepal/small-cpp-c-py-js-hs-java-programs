#include <iostream>
#include <string>
using namespace std;

class Fruit{
	private:
		string name;
		string taste;
		int nutritionval;
	public:
		void setname(string somename){
			name = somename;
		}
		void settaste(string taste1){
			taste = taste1;
		}
		void setnutrition(int val){
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
	switch (num){
		case 1:
			
			cout << "What do you call it?" << endl;
			cin >> namee;
			Apple.setname(namee);
			cout << "How was the apple?" << endl;
			cin >> tastee;
			Apple.settaste(tastee);
			cout << "Enter the nutrition value: ";
			cin >> nutritionvalue;
			Apple.setnutrition(nutritionvalue);
			break;
		case 2:
			
			cout << "What do you call it?" << endl;
			cin >> namee;
			Banana.setname(namee);
			cout << "How was the Banana?" << endl;
			cin >> tastee;
			Banana.settaste(tastee);
			cout << "Enter the nutrition value: ";
			cin >> nutritionvalue;
			Banana.setnutrition(nutritionvalue);
	}

	cout << "What do u want to know about ur fruit?" << endl;
	cout << "1. name" << endl;
	cout << "2. taste\n 3. nutritionvalue" << endl;
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