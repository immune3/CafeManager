#pragma once
#include <string>

using namespace std;

class menu {
private:
	string drinkName;	// ������ �̸�
	int makeTime;	// ���Ḧ ����µ� �ɸ��� �ð�
	int drinkPrice;	// ������ ����, ��� ����� ���� ���� ���߿� ������ ������ �����Ϸ��� ���
public:
	// ������
	menu() {	//  ����Ʈ ������
		drinkName = "empty";
		makeTime = -1;
		drinkPrice = -1;
	}
	menu(string name, int time, int price) {
		drinkName = name;
		makeTime = time;
		drinkPrice = price;
	}

	// accessor
	string getDrinkName() { return drinkName; }
	int getMakeTime() { return makeTime; }
	int getDrinkPrice() { return drinkPrice; }

	// mutator
	void setMakeTime(int time) { makeTime = time; }

	// function

};


/* �̷������� �Լ� �߰� ����
void menu::funcName(type param, ..) {

}
*/

