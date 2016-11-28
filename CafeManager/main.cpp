#include <iostream>
#include <fstream>
#include <queue>
#include "menu.h"
#include "barista.h"
#include "order.h"
#include "myTime.h"
#include "loadBalancing.h"
#include "extendedLoadBalancing.h"

using namespace std;

// fstream functions
void loadMenuFile(string fileName);
void loadBaristaFile(string fileName);
void loadOrderFile(string fileName);


vector<menu> men;		// ��� �޴� ������ �����ص� vector�� �ڷᱸ��
vector<barista> bari;	// ��� �ٸ���Ÿ ���� �����ص� vector�� �ڷᱸ��
queue<order> ord;		// ��� �ֹ������� �����ص� queue�� �ڷᱸ��
//resultObserver *observer;
string drinkName;	// �޴� �̸�

// main �ȿ� ����ϰ� �ؼ� �����ϱ� ���ϰ� �ϱ� ���� �׽�Ʈ �Լ� ���� ����
void load() {
	loadMenuFile("menu.txt");
	loadBaristaFile("barista.txt");
	loadOrderFile("order.txt");
	cout << endl;
}
void test();

int main() {

	load();
	start();
	for (int i = 0; i < bari.size(); i++) {
		cout << "i�� :" << i <<"���� :" << bari[i].getNumOfCofMade() << endl;
	}
	//ExtendedLoadBalancing loadbalncing; 
	//ExtendedLoadBalancing loadbalncing2(new ReaderSample);
	//ExtendedLoadBalancing loadbalncing3(new BasicReader, new BasicWriter, new BasicComputer);
	//ExtendedLoadBalancing loadbalncing4(new ReaderWithTime, new WriterWithTime, new ComputerWithTime);
	// test
	//test();
	
	return 0;
}

// �̰� UI Ŭ������ ������� �ؼ� ���� ���� �����ϰ� �� �ʿ� ����
// ������ : ���߿� �������� �κ��̶� �����ƿ�
void test() {
	int i;

	for (i = 0; i < men.size(); i++)
		cout << i << "�� �޴�, �޴��̸� :" << men[i].getDrinkName() << " ����� �ð� :" << men[i].getMakeTime() << "��" << endl;
	cout << endl;

	for (i = 0; i < bari.size(); i++)
		cout << i << "�� �ٸ���Ÿ, ���õ� :" << bari[i].getRank() << endl;
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

	// myTime.h ���� �׽�Ʈ and ����
	/*myTime t1 = "08:30:00";
	myTime t2 = "25:62:80"; // �߸��� �����Ͱ� ��������� getSec()�� ȣ�����ָ� �ٸ� �����ͷ� �ٲ��(�ٵ� �׷����� ������..)
	cout << t1 << " " << t2 << endl;
	cout << t2.getHour() << ":" << t2.getMin() << ":" << t2.getSec() << endl;
	cout << t1 << " " << t2 << endl;
	myTime t3 = "08:30:00";
	if (t1 == t3) // ���� �ð��� ������(�ֹ��ð��� ����ð�) �� ����
		cout << "�����ϴ�" << endl;
	
	for (int i = 0; i < 30; i++) {
		++t3;
	}
	++t3;
	cout << t1 << " " << t3 << endl;
	t1 = t3 + 5;
	cout << t1 << " " << t3 << endl;
	cout << endl;

	*/
}


/****************************
�޴��� ���� �����͸� �о�´�
****************************/
void loadMenuFile(string fileName) {

	int i;
	int numOfMenu;	// �� �޴��� ����
	int makeTime, drinkPrice;	// �޴��� ����µ� �ɸ��� �ð�, �޴��� ����
	int makableRank;	// �� �޴��� ����µ� �ʿ��� �ٸ���Ÿ ��ũ

	cout << fileName << " loading" << endl;
	ifstream in(fileName);
	if (in.fail()) {
		cout << fileName << " open fail" << endl;
		return;
	}

	in >> numOfMenu;
	for (i = 0; i < numOfMenu; i++) {
		in >> drinkName >> makeTime >> drinkPrice >> makableRank;
		menu temp(drinkName, makeTime, drinkPrice, makableRank);
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
	int rank;	// �ٸ���Ÿ�� ��ũ (0 ~ 5)
		
	cout << fileName << " loading" << endl;
	ifstream in(fileName);
	if (in.fail()) {
		cout << fileName << " open fail" << endl;
		return;
	}

	in >> numOfBarista;
	for (i = 0; i < numOfBarista; i++) {
		in >> rank;
		barista temp(rank);
		bari.push_back(temp);
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