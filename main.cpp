#include<iostream>
#include<string>
#include<map>
#include "ATM.h"
#include "ATM.cpp"

using namespace std;

/*Везде добавить обработку ошибок*/

bool menu(string card_number) {
	cout << "			Меню			" << '\n';
	cout << "1 - Проверить баланс" << endl;
	cout << "2 - Снять наличные" << endl;
	cout << "3 - Оплата коммунальных платежей" << endl;
	cout << "4 - Пополнить баланс мобильного телефона" << endl;
	cout << "5 - Забрать карту" << endl;
	cout << "Введите номер операции - " << endl;
	int number;
	cin >> number;
	switch (number) {
			case 1:
				CheckBalance(card_number);
				break;
			case 2:
				if (GetCash(card_number) == false) 
					return false;
				break;
			case 3:
				FillUpBalanceOfMobile(card_number);
				break;
			case 4:
				PayUtilityBills(card_number);
				break;
			case 5:
				return false;
			default:
				cout << "Нет такой операции" << endl;
				menu(card_number);
				break;
		}
	return true;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "Введите базу данных" << endl;
	bool flag = true;
	while (flag == true) {
		cout << "Введите карты и баланс" << endl;
		string number_card;
		double balance;
		getline(cin, card_number);
		cin >> balance;
		mymap.insert (pair<string,double> (number_card,balance) );
		cout << "1 - Продолжить ввод" << endl;
		cout << "2 - Закончить ввод" << endl;
		switch (number) {
			case 1:
				flag = true;
				break;
			case 2:
				flag = false;
				break;
		}
	}
		
	string card_number;
	string name;
	int cvv;
	int month;
	int year;
	int pincode;
	string card_type;
	for (;;) {
	cout << "Эмуляция Банкомата ATM" << endl << endl;
	cout << "Введите карту:" << endl;
	cout << "Введите номер карты" << endl;
	getline(cin, card_number);
	cout << "Введите имя и фамилию" << endl;
	getline(cin, name);
	cout << "Введите CVV" << endl;
	cin >> cvv;
	cout << "Введите месяц окончания(цифра)" << endl;
	cin >> month;
	cout << "Введите год окончания(цифра)" << endl;
	cin >> year;
	cout << "Введите тип карты" << endl;
	getline(cin, card_type);
	bool flag = false;
	if (!AcceptCard(card_number, name, cvv, month, year, card_type)) {
		cout << "Карта вставлена неправильно" << endl;
	} else {
		for (;;) {
			cout << "Введите пин-код" << endl;
			cin >> pincode;
			int iter = 0;
			while ((iter < 3) && !flag) {
				if (!ProcessCard(card_number, pincode)) {
					cout << "Пин-код не верен. Введите пин-код еще раз" << endl;
					cin >> pincode;
					iter++;
				} else
					flag = true;
			}
			if (iter == 3) {
				cout << "Пин-код не верен. Карта заблокирована. Чтобы разблокировать карту, нужно обратиться в любое отделение банка." << endl;
			}

			if (flag == true) {
				if (menu(card_number) == false)
					break;
			}
		}
	}
	return 0;
}