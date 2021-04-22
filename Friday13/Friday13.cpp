/*Перечислить дни, на которые приходится пятница 13-го числа в заданном диапазоне лет из интервала 1901-2099 г.г.
Ввод из файла INPUT.TXT. В единственной строке задаются через пробел начальный и конечный годы. 
Вывод в файл OUTPUT.TXT. Выводится столько строк, сколько найдено пятниц 13-го числа. 
Пример
Ввод   
1952 1954  
Вывод 
1952 JUNE
1953 FEBRUARY
1953 MARCH
1953 NOVEMBER
1954 AUGUST
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

const int bottom_date = 1901;
const int top_date = 2099;
const int all_month = 12;
//const int first_day_of_1901 = 1; //1 число 1901 года приходится на вторник

void Months(vector<string>& month)
{
	month.push_back("JANUARY");
	month.push_back("FEBRUARY");
	month.push_back("MARCH");
	month.push_back("APRIL");
	month.push_back("MAY");
	month.push_back("JUNE");
	month.push_back("JULY");
	month.push_back("AUGUST");
	month.push_back("SEPTEMBER");
	month.push_back("OCTOBER");
	month.push_back("NOVEMBER");
	month.push_back("DECEMBER");
}

void TotalDayInWeek(vector<string>& day_week)
{
	day_week.push_back("Monday");
	day_week.push_back("Tuesday");
	day_week.push_back("Wednesday");
	day_week.push_back("Thursday");
	day_week.push_back("Friday");
	day_week.push_back("Saturday");
	day_week.push_back("Sunday");
}

void Calendar(vector<string> day_week, vector<int> all_days, int& int_day, int day)
{
	if (int_day == 7)
	{
		int_day = 0;
		cout << day_week[int_day] << ": " << day << endl;
	}
	else
	{
		all_days.push_back(day);
		cout << day_week[int_day] << ": " << day << endl;
	}
}

void Next_month(int& i, int day_month[12], int& day)
{
	//прибавляем месяц
	if (day == day_month[i])
	{
		i++;
		day = 0;
		int month=0;
		cout << month[&i] << endl;
	}
}

int main(int argc, char* argv[])
{
	int year_one = 0, year_two = 0;
	input >> year_one >> year_two;
	
    if (!input)
    {
        cout << "Error open file input.txt" << endl;
        return 1;
    }

	if (year_one < bottom_date || year_two > top_date)
	{
		cout << "Incorrect data entered";
		return 1;
	}
	
	int i = 0;
	
    vector<string> month;
    Months(month);
	
	int day_month [12] = { 31, 28,  31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	vector<string> day_week;
	TotalDayInWeek(day_week);
	
//	cout << month[i] << endl << year_one << endl << year_two<<endl<< day_month[i]<<endl<<day_week[i];
	vector <int> all_days;
	int int_day = 1; //первое число 1901 года приходится на вторник
	//int int_year = 1; //для отсчета високосного года
	//cout << month[i] << endl;
	int day_in_year =1;
	for (int year = year_one; year <= year_two; year++)
	{
		for (int month = 1;  month <= all_month; month++)
		{
			for (int day = 1; day < day_month[i]; day++)
			{
				/*Calendar(day_week, all_days, int_day, day);
				int_day++;
				day_in_year++;
				Next_month(i, day_month, day);
				day_in_year++;*/
				//cout << day_in_year << endl;
				//cout << day_month[i] << endl;

				if ((day == 5) && (day == 13) && (year >= year_one))
					cout << year << day_month[month - 1] << endl;
			}
			i++;
		}
	}
    return 0;
}

/*
сделать привязку числа ко дню недели и месяцу
високосный год
проверки корректных данных в инпуте(проверка на пустоту и не цифры)
 */