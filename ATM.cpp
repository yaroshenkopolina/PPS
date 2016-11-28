#include<iostream>
#include "ATM.h"

using namespace std;

map<string, double> database_money;

bool AcceptCard(string card_number, string name, int cvv, int month, int year, string card_type) {
	return 0;
}

bool CheckBalance(string card_number) {
	cout << "Текущий баланс: " << database_money.find(card_number)->second << '\n';
	return true;
}

bool GetCash(string card_number) {
	cout << "Введите сумму: ";
	double sum;
	cin >> sum;
	double balance = database_money.find(card_number)->second;
	if (balance >= sum) {
		database_money.erase(card_number);
		balance = balance - sum;
		mymap.insert (pair<string,double> (number_card,balance) );
	}
	if (balance < sum) {
		cout << "Недостаточно средств на счёте" << '\n';
		return false;
	}
	return true;
}

bool FillUpBalanceOfMobile(string card_number) {
	return true;
}

bool PayUtilityBills(string card_number) {
	return true;
}

bool ProcessCard(string card_number, int pincode) {
	return true;
}