#pragma once
#include <string>

using namespace std;

class order {
private:
	int orderNum;		// �ֹ���ȣ
	int customerNum;	// ����ȣ
	string orderTime;	// �ֹ��ð�
	string drinkName;	// �����̸�
	int numOfDrink;		// �ֹ�����
public:
	// ������
	order() {	//  ����Ʈ ������
		orderNum = -1;
		customerNum = -1;
		orderTime = "empty";
		drinkName = "empty";
		numOfDrink = -1;
	}
	order(int order, int customer, string time, string name, int num) {
		orderNum = order;
		customerNum = customer;
		orderTime = time;
		drinkName = name;
		numOfDrink = num;
	}

	// accessor
	int getOrderNum() { return orderNum; }
	int getCustomerNum() { return customerNum; }
	string getOrderTime() { return orderTime; }
	string getDrinkName() { return drinkName; }
	int getNumOfDrink() { return numOfDrink; }

	// mutator


	// function
	// �ֹ��ð��� HH:MM:SS string type ���� �޾�����
	int getOrderTimeHour();		// �ð��� return
								//int getOrderTimeMin();	// ���� return
								//int getOrderTimeSec();	// �ʸ� return
};


// �ð��� return
int order::getOrderTimeHour() {
	//to do something
	int hour = -1;

	return hour;
}


/* �̷������� �Լ� �߰� ����
void order::funcName(type param..) {

}
*/