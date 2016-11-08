#pragma once
#include "menu.h"

class barista {
private:
	int totalMade;		// �ٸ���Ÿ�� ���� �� Ŀ���� ��
	int numOfCofMade;	// ���� ���� Ŀ���� ��
	int rank;	// �ٸ���Ÿ�� ��ũ (0 ~ 5, �������� ��ư� �� �ٲ�)

public:
	// ������
	barista() {	//  ����Ʈ ������
		totalMade = -1;
		numOfCofMade = -1;
		rank = -1;
		// to do something

	}
	barista(int prof) {
		totalMade = 0;
		numOfCofMade = 0;
		rank = prof;
		// to do something

	}

	// accessor
	int getNumOfCofMade() { return numOfCofMade; }
	int getRank() { return rank; }
	int getTotalMade() { return totalMade; }

	// mutator
	void setRank(int prof) { rank = prof; }
	void incNumOfCofMade() { numOfCofMade++; }	// numOfCofMade++
	void incNumOfCofMade(int numOfCof) { numOfCofMade += numOfCof; }

												// function
	// �ٸ���Ÿ�� ���õǾ��� �� 
	// �ٸ���Ÿ Ŭ���������� �ٲ��־���� �κ� work�� ��Ƶа�
	void doWork(string drinkName, int numOfDrink); 
	int currentWork();
	void endOfDay();
};

// �Ϸ簡 ������ �������� ������� �� Ŀ�Ǽ��� ���ø��� Ŀ�Ǽ��� �����ش�
void barista::endOfDay() {
	totalMade += numOfCofMade;
	numOfCofMade = 0;
}

/* �̷������� �Լ� �߰� ����
void barista::funcName(type param, ..) {

}
*/

void barista::doWork(string drinkName, int numOfDrink) {
	//this->incNumOfCofMade(numOfDrink);
	/***************************************************
	   this ��������� �ʾƵ� �˴ϴ�
	   ��� ���ο����� ��� ���� private ������ �ٷ� ���ٰ����մϴ�
	***************************************************/
	numOfCofMade += numOfDrink;
}

int barista::currentWork() {
	//return this->getNumOfCofMade();
	/***************************************************
	   �̰͵� ���������̰� �� �Լ��� �׳� getNumOfCofMade() �����ڿ� �Ȱ��� �Լ��̱� ������ �����Ͻð�
	   getNumOfCofMade() ������ּ���(���� ���� �Լ� ���� ȣ��)
	***************************************************/
	return numOfCofMade;
}