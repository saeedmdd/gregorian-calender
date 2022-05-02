#include <iostream>
#include <conio.h>
using namespace std;
class Date {
private:

public:
	int y, m, d;
	Date(int a = 1900, int b = 1, int c = 1) {
		y = a; m = b; d = c;
	}


	void set(int a = 1900, int b = 1, int c = 1) {
		y = a; m = b; d = c;
		y = d / 366;
		y += 1900;
		d = d % 366;

		for (int i = 1900; i < y; i++)
			if (!(i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))) d++;
		m = d / 31;
		d %= 31;
		m++;
		for (int i = 1; i < m; i++) {
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) && i == 2) d += 2;
			else if (i == 2) d += 3;

			if (i == 4 || i == 6 || i == 9 || i == 11) d++;
		}

	}

	int Date_to_d() {
		int c = 0, counter = 0;

		for (int i = 1900; i < y; i++)
			if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0)) c++;

		for (int i = 1; i < m; i++) {
			if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0) && i == 2) counter++;
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) counter += 3;
			if (i == 4 || i == 6 || i == 9 || i == 11) counter += 2;
		}


		return (y - 1900) * 365 + c + 28 * (m - 1) + counter + d;


	}
	void show(int Entekhab = 0) {
		char day[8][4] = { "sun","mon","tue","wed","thu","fri","sat","" };

		switch (Entekhab) {
		case 0:cout << y << "/" << m << "/" << d; break;
		case 1:cout << d << " " << month_name[m] << " " << y; break;
		case 2: cout << day[Date_to_d() % 7] << "\t" << d << "\t" << month_name[m] << "\t" << y; break;
		}




	}
	void get() {
		do {
			cout << "year:";
			cin >> y;
		} while (y < 1900);
		do {
			cout << "month:";
			cin >> m;
		} while (m <= 0 || m > 12);
		int End_Day = month_day[m];
		do {
			cout << "day:";
			cin >> d;
			if (y % 4 == 0) End_Day++;
			if (y % 4 == 0 && y % 100 == 0 && y % 400 != 0) End_Day--;
		} while (d<1 || d>End_Day);
	}
	Date operator+(int b) {
		Date temp;
		temp.set(0, 0, Date_to_d() + b);
		return temp;
	}
	Date operator-(int b) {
		Date temp;
		if (Date_to_d() > b)
			temp.set(0, 0, Date_to_d() - b);
		else
			temp.set(0, 0, b - Date_to_d());

		return temp;
	}

	static int month_day[13];
	static char month_name[13][4];
};
int Date::month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char Date::month_name[13][4] = { " ","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
int main() {

	getch();
	return 0;
}
