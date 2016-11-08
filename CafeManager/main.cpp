#include <iostream>
#include <fstream>
#include <queue>
#include "barista.h"
#include "order.h"
#include "loadBalancing.h"

using namespace std;

// fstream functions
void loadMenuFile(string fileName);
void loadBaristaFile(string fileName);
void loadOrderFile(string fileName);

vector<menu> men;		// ��� �޴� ������ �����ص� vector�� �ڷᱸ��
vector<barista> bari;	// ��� �ٸ���Ÿ ���� �����ص� vector�� �ڷᱸ��
queue<order> ord;		// ��� �ֹ������� �����ص� queue�� �ڷᱸ��

string drinkName;	// �޴� �̸�

// main �ȿ� ����ϰ� �ؼ� �����ϱ� ���ϰ� �ϱ� ���� �׽�Ʈ �Լ� ���� ����
void test();

int main() {

	loadMenuFile("menu.txt");
	loadBaristaFile("barista.txt");
	loadOrderFile("order.txt");
	cout << endl;

	// loadBalancing
	loadBalancing();

	// test
	test();
	
	return 0;
}

// �̰� UI Ŭ������ ������� �ؼ� ���� ���� �����ϰ� �� �ʿ� ����
void test() {
	int i;

	for (i = 0; i < men.size(); i++)
		cout << i << "�� �޴�, �޴��̸� :" << men[i].getDrinkName() << " ����� �ð� :" << men[i].getMakeTime() << "��" << endl;
	cout << endl;

	for (i = 0; i < bari.size(); i++)
		cout << i << "�� �ٸ���Ÿ, ���õ� :" << bari[i].getProficiency() << " ����� �ִ� �޴� ���� :" << bari[i].getNumOfMakeableMenu() << endl;
	cout << endl;

	for (i = 0; i < bari.size(); i++) {
		cout << i << "�� �ٸ���Ÿ, �ֹ��� : " << bari[i].getNumOfCofMade() << endl;
	}

	while (!ord.empty()) {
		cout << "�ֹ���ȣ : " << ord.front().getOrderNum() << " �ֹ��ð� : " << ord.front().getOrderTime()
			<< " �ֹ��޴� :" << ord.front().getDrinkName() << " �ֹ����� :" << ord.front().getNumOfDrink() << endl;
		ord.pop();
	}
	cout << endl;
}

/****************************
�޴��� ���� �����͸� �о�´�
****************************/
void loadMenuFile(string fileName) {

	int i;
	int numOfMenu;	// �� �޴��� ����
	int makeTime, drinkPrice;	// �޴��� ����µ� �ɸ��� �ð�, �޴��� ����
	
	cout << fileName << " loading" << endl;
	ifstream in(fileName);
	if (in.fail()) {
		cout << fileName << " open fail" << endl;
		return;
	}

	in >> numOfMenu;
	for (i = 0; i < numOfMenu; i++) {
		in >> drinkName >> makeTime >> drinkPrice;
		menu temp(drinkName, makeTime, drinkPrice);
		men.push_back(temp);
	}
	cout << fileName << " load complete" << endl;
	in.close();
}

/********************************
�ٸ���Ÿ�� ���� �����͸� �о�´�
********************************/
void loadBaristaFile(string fileName) {

	int i, j;
	int numOfBarista;	// �� �ٸ���Ÿ�� ����
	int numOfMakableMenu;	// �ٸ���Ÿ�� ���� �� �ִ� �޴��� ��
	int proficiency;	// �ٸ���Ÿ�� ���õ� (0 ~ 5)
		
	cout << fileName << " loading" << endl;
	ifstream in(fileName);
	if (in.fail()) {
		cout << fileName << " open fail" << endl;
		return;
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
	cout << fileName << " load complete" << endl;
	in.close();
}

/*********************************
�ֹ��� ���� �����͸� ť�� �����Ѵ�
**********************************/

void loadOrderFile(string fileName) {

	int orderNum;		// �ֹ���ȣ
	int customerNum;	// ����ȣ
	string orderTime;	// �ֹ��ð�
	int numOfDrink;		// �ֹ�����

	cout << fileName << " loading" << endl;
	ifstream in(fileName);
	if (in.fail()) {
		cout << fileName << " open fail" << endl;
		return;
	}

	while (!in.eof()) {
		in >> orderNum >> customerNum >> orderTime >> drinkName >> numOfDrink;
		order temp(orderNum, customerNum, orderTime, drinkName, numOfDrink);
		ord.push(temp);
	}
	cout << fileName << " load complete" << endl;
	in.close();
}