#include<iostream>
#include<string>
#include<map>
#include "ATM.h"
#include "ATM.cpp"

using namespace std;

/*����� �������� ��������� ������*/

bool menu(string card_number) {
	cout << "			����			" << '\n';
	cout << "1 - ��������� ������" << endl;
	cout << "2 - ����� ��������" << endl;
	cout << "3 - ������ ������������ ��������" << endl;
	cout << "4 - ��������� ������ ���������� ��������" << endl;
	cout << "5 - ������� �����" << endl;
	cout << "������� ����� �������� - " << endl;
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
				cout << "��� ����� ��������" << endl;
				menu(card_number);
				break;
		}
	return true;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	cout << "������� ���� ������" << endl;
	bool flag = true;
	while (flag == true) {
		cout << "������� ����� � ������" << endl;
		string number_card;
		double balance;
		getline(cin, card_number);
		cin >> balance;
		mymap.insert (pair<string,double> (number_card,balance) );
		cout << "1 - ���������� ����" << endl;
		cout << "2 - ��������� ����" << endl;
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
	cout << "�������� ��������� ATM" << endl << endl;
	cout << "������� �����:" << endl;
	cout << "������� ����� �����" << endl;
	getline(cin, card_number);
	cout << "������� ��� � �������" << endl;
	getline(cin, name);
	cout << "������� CVV" << endl;
	cin >> cvv;
	cout << "������� ����� ���������(�����)" << endl;
	cin >> month;
	cout << "������� ��� ���������(�����)" << endl;
	cin >> year;
	cout << "������� ��� �����" << endl;
	getline(cin, card_type);
	bool flag = false;
	if (!AcceptCard(card_number, name, cvv, month, year, card_type)) {
		cout << "����� ��������� �����������" << endl;
	} else {
		for (;;) {
			cout << "������� ���-���" << endl;
			cin >> pincode;
			int iter = 0;
			while ((iter < 3) && !flag) {
				if (!ProcessCard(card_number, pincode)) {
					cout << "���-��� �� �����. ������� ���-��� ��� ���" << endl;
					cin >> pincode;
					iter++;
				} else
					flag = true;
			}
			if (iter == 3) {
				cout << "���-��� �� �����. ����� �������������. ����� �������������� �����, ����� ���������� � ����� ��������� �����." << endl;
			}

			if (flag == true) {
				if (menu(card_number) == false)
					break;
			}
		}
	}
	return 0;
}