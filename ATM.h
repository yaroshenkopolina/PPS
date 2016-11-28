include<iostream>
#include<string>
#include <clocale>

using namespace std;




class Cash {
public:
	int denomination;
	Cash(): denomination(0){}
	Cash(int _denomination): denomination(_denomination){}
};

class person {
public:
	string name;
	string surname;
	person(): name(""), surname(""){}
	person(string _name, string _surname): name(_name), surname(_surname){}
};


class timeMY {
public:
	int month;
	int year;
	timeMY(): month(1), year(1970){}
	timeMY(int _month, int _year): month(_month), year(_year){}
};

class timeMYD {
public:
	int month;
	int year;
	int day;
	timeMYD(int _month, int _year, int _day): timeMY(_month, _year), day(_day){}
};

class timeAll: public timeMYD {
public:
	int day;
	int month;
	int year;
	int min;
	int sec;
	int hour;
	timeAll(int _month, int _year, int _day, int _hour, int _min, int _sec): timeMYD(_month, _year, _day), hour(_hour), min(_min), sec(_sec){}
};

enum card_type {
	MASTERCARD,
	VISA,
	AMERICAN_EXPRESS,
	UNION_CARD,
	NPS,
	OTHER
};

class CreditCard {
public:
	string number;
	int pin_code;
	timeMY good_thru;
	person personal_data;
	int cvv;
	card_type type;
	CreditCard(): number(""), pin_code(0), good_thru(timeMY()), personal_data(person()), cvv(0), type(OTHER){}
	CreditCard(string    _number,
	           int       _pin_code,
	           timeMY      _good_thru,
	           person    _personal_data,
	           int       _cvv,
			   card_type _type): number(_number), pin_code(_pin_code), good_thru(_good_thru), personal_data(_personal_data), cvv(_cvv), type(_type){}
	bool ProvideAccessToTheAccount();
};

class CardReader {
	bool AcceptCard();
	bool EjectCard();
	bool ReadCard(CreditCard & card);
	bool RecognizedType(card_type type);
};

class Cheque {
	time date;
	int money; // in rubls
	int residual; // остаток
	person personal_data;
	string account_num;
};

class Display {
	void prompt(string inf);
	bool accept_input();
};

class Account {
public:
	string number;
	double money;
	string information;
	Account(): number(""), money(0), information("") {}
	Account(string _number, double _money, string _information): number(_number), money(_money), information(_information) {}
	bool open(/*какие-то параметры*/);
	bool deduct_funds(/*какие-то параметры*/);
	bool verify_funds(/*какие-то параметры*/);
};

class CheckingAccount : public Account {
public:
	CheckingAccount(string _number, double _money, string _information): Account(_number, _money, _information) {}
	bool withdraw_funds();
};

class SavingsAccount : public Account {
public:
	double amount_of_saving_money;
	double interest_rate;
	double period of
	CheckingAccount(string _number, double _money, string _information): Account(_number, _money, _information) {}
	bool withdraw_saving_money();
};

class CashDispenser {
public:
	int cash_balance;
	CashDispenser(): cash_balance(0) {}
	CashDispenser(int _cash_balance): cash_balance(_cash_balance){}
	bool provide_cash();
};

class Bank {
public:
	string name;
	Bank(): name(""){}
	Bank(string _name): name(_name){}
	bool processing_requests_from_ATM();
};

class BankNotowningTheATM : public Bank {
public:
	string name;
	BankNotowningTheATM(string _name): Bank(_name){}
};

class BankOwningTheATM : public Bank {
public:
	string name;
	BankOwningTheATM(string _name): Bank(_name){}
	bool provides_operator();
};

class Operator {
public:
	Operator(): {}
	bool add_money();
	bool remove_money();
	bool reset_thecash_dispenser();
	bool read_thelogs_of_theATMs();
};

class LogsOfATM {
public:
	database data;
	LogsOfATM(database _data): data(_data) {}
	bool provides_operator_with_data();
};

class Keyboard {
public:
	Keyboard(): {}
	bool choose_action();
	bool enter_pincode();
	bool enter_amount_of_money();
};

class ButtonsNearTheDisplay {
public:
	ButtonsNearTheDisplay(): {}
	bool choose_action();
};

class ATM {
public:
	string serial_number;
	string operation_system;
	string requirements_for_credit_card;
	ATM(): serial_number(""), string operation_system(""), string requirements_for_credit_card("") {}
	ATM(string _serial_number, string _operation_system, string _requirements_for_credit_card;): serial_number(""), string operation_system(""), string requirements_for_credit_card("") {}
	bool pay_utility_bills();
	bool put_thecommision();
	bool switch_operation_system();
	bool fillup_balance_of_mobile();
	bool get_cash();
	bool check_balance();
};




	



	

bool AcceptCard(string card_number, string name, int cvv, int month, int year, string card_type);
bool ProcessCard(string card_number, int pincode);
bool CheckBalance(string card_number);
bool GetCash(string card_number);
bool FillUpBalanceOfMobile(string card_number);
bool PayUtilityBills(string card_number);




