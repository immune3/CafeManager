#include <iostream>
#include <fstream>
#include <queue>
#include "barista.h"
#include "order.h"

using namespace std;

vector<menu> men;		// ��� �޴� ������ �����ص� vector�� �ڷᱸ��
vector<barista> bari;	// ��� �ٸ���Ÿ ���� �����ص� vector�� �ڷᱸ��
queue<order> ord;		// ��� �ֹ������� �����ص� queue�� �ڷᱸ��

int main() {

	int i, j;
	int numOfMenu;	// �� �޴��� ����
	int numOfBarista;	// �� �ٸ���Ÿ�� ����
	string drinkName;	// �޴� �̸�
	int makeTime, drinkPrice;	// �޴��� ����µ� �ɸ��� �ð�, �޴��� ����
	int numOfMakableMenu;	// �ٸ���Ÿ�� ���� �� �ִ� �޴��� ��
	int proficiency;	// �ٸ���Ÿ�� ���õ� (0 ~ 5)
	int orderNum;		// �ֹ���ȣ
	int customerNum;	// ����ȣ
	string orderTime;	// �ֹ��ð�
	int numOfDrink;		// �ֹ�����

						/****************************
						�޴��� ���� �����͸� �޴´�
						****************************/
	cout << "�޴� �����͸� �о�ɴϴ�." << endl;
	ifstream in("menu.txt");
	if (in.fail()) {
		cout << "menu file open fail" << endl;
		return 1;
	}

	in >> numOfMenu;
	for (i = 0; i < numOfMenu; i++) {
		in >> drinkName >> makeTime >> drinkPrice;
		menu temp(drinkName, makeTime, drinkPrice);
		men.push_back(temp);
	}
	cout << "�޴� ������ �ε� �Ϸ�." << endl;
	in.close();

	/******************************
	�ٸ���Ÿ�� ���� �����͸� �޴´�
	******************************/
	cout << "�ٸ���Ÿ �����͸� �о�ɴϴ�." << endl;
	in.open("barista.txt");
	if (in.fail()) {
		cout << "barista file open fail" << endl;
		return 1;
	}

	in >> numOfBarista;
	for (i = 0; i < numOfBarista; i++) {
		in >> proficiency >> numOfMakableMenu;
		barista temp(proficiency, numOfMakableMenu);
		bari.push_back(temp);
		for (j = 0; j < numOfMakableMenu; j++) {
			in >> drinkName;
			// To do something  
			// ���� ���� ������ barista.h�� vector�� makable�� �߰� �����Ϸ��� ������
		}

	}
	cout << "�ٸ���Ÿ �����͸� �ε� �Ϸ�." << endl;
	in.close();

	/*********************************
	�ֹ��� ���� �����͸� ť�� �����Ѵ�
	**********************************/
	cout << "�ֹ� �����͸� ť�� �о�ɴϴ�." << endl;
	in.open("order.txt");
	if (in.fail()) {
		cout << "order file open fail" << endl;
		return 1;
	}

	while (!in.eof()) {
		in >> orderNum >> customerNum >> orderTime >> drinkName >> numOfDrink;
		order temp(orderNum, customerNum, orderTime, drinkName, numOfDrink);
		ord.push(temp);
	}
	cout << "�ֹ� �����͸� ť�� �ε� �Ϸ�." << endl;
	in.close();

	// test
	for (i = 0; i < numOfMenu; i++)
		cout << i << "�� �޴�, �޴��̸� :" << men[i].getDrinkName() << " ����� �ð� :" << men[i].getMakeTime() << "��" << endl;
	cout << endl;

	for (i = 0; i < numOfBarista; i++)
		cout << i << "�� �ٸ���Ÿ, ���õ� :" << bari[i].getProficiency() << " ����� �ִ� �޴� ���� :" << bari[i].getNumOfMakeableMenu() << endl;
	cout << endl;

	while (!ord.empty()) {
		cout << "�ֹ���ȣ : " << ord.front().getOrderNum() << " �ֹ��ð� : " << ord.front().getOrderTime()
			<< " �ֹ��޴� :" << ord.front().getDrinkName() << " �ֹ����� :" << ord.front().getNumOfDrink() << endl;
		ord.pop();
	}
	cout << endl;

	return 1;
}