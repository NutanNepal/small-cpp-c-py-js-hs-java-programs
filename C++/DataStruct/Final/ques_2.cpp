#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::map<std::string, int> MONTHS = {
	{ "JAN", 1 },
	{ "FEB", 2 },
	{ "MAR", 3 },
	{ "APR", 4 },
	{ "MAY", 5 },
	{ "JUN", 6 },
	{ "JUL", 7 },
	{ "AUG", 8 },
	{ "SEP", 9 },
	{ "OCT", 10 },
	{ "NOV", 11 },
	{ "DEC", 12 }
};

struct Date {
	Date(std::string date_) {
		month = date_.substr(0, 3);
		year = date_.substr(3, 2);
	}
	std::string month, year;
};

void sortvector(std::vector<Date*> &dates);

int main()
{
	Date* Jan97 = new Date("JAN97");
	Date* Dec98 = new Date("DEC98");
	Date* Apr04 = new Date("APR04");
	Date* Mar90 = new Date("MAR90");
	Date* Apr08 = new Date("APR08");
	Date* Nov08 = new Date("NOV08");
	Date* Jun21 = new Date("JUN21");

	std::vector<Date*> dates;
	dates.push_back(Jan97);
	dates.push_back(Dec98);
	dates.push_back(Apr04);
	dates.push_back(Mar90);
	dates.push_back(Apr08);
	dates.push_back(Nov08);
	dates.push_back(Jun21);

	sortvector(dates);

	for (std::vector<Date*>::iterator i = dates.begin(); i != dates.end(); i++) {
		std::cout << (*i)->month << (*i)->year << std::endl;
	}

	return 0;
}

void sortvector(std::vector<Date*> &dates) {
	for (int x = 0; x < dates.size(); x++) {
		for (int y = 1; y < dates.size(); y++) {
			int yi = stoi(dates[y - 1]->year);
			int yj = stoi(dates[y]->year);
			if (yi < yj) {
				Date* temp = dates[y - 1];
				dates[y - 1] = dates[y];
				dates[y] = temp;
			}
			else if (yi == yj) {
				if (MONTHS.at(dates[y - 1]->month) < MONTHS.at(dates[y]->month)) {
					Date* temp = dates[y - 1];
					dates[y - 1] = dates[y];
					dates[y] = temp;
				}
			}
			else {
				;
			}
		}
	}
}