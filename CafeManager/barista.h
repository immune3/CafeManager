#pragma once
#include "menu.h"
#include <vector>

class barista {
private:
	int totalMade;		// �ٸ���Ÿ�� ���� �� Ŀ���� ��
	int numOfCofMade;	// ���� ���� Ŀ���� ��
	int proficiency;	// �ٸ���Ÿ�� ���õ� (0 ~ 5)
	int numOfMakableMenu;	// // �ٸ���Ÿ�� ���� �� �ִ� �޴��� ��
	vector<menu> makable;	// �ٸ���Ÿ�� ����� �ִ� ���� �޴�, �̰����� ���õ��� ���� �ٸ���Ÿ�� ���� ���� �ð��� �̸� ����� �Ѽ� �ֵ���

public:
	// ������
	barista() {	//  ����Ʈ ������
		totalMade = -1;
		numOfCofMade = -1;
		proficiency = -1;
		numOfMakableMenu = -1;
		// to do something

	}
	barista(int prof, int num) {
		totalMade = 0;
		numOfCofMade = 0;
		proficiency = prof;
		numOfMakableMenu = num;
		// to do something

	}

	// accessor
	int getNumOfCofMade() { return numOfCofMade; }
	int getProficiency() { return proficiency; }
	int getTotalMade() { return totalMade; }
	int getNumOfMakeableMenu() { return numOfMakableMenu; }

	// mutator
	void setProficiency(int prof) { proficiency = prof; }
	void incNumOfCofMade() { numOfCofMade++; }	// numOfCofMade++

												// function
	void endOfDay();
	int baristaMakeTime(string drink);	// ���õ��� ���� �ٸ���Ÿ�� ���� ���� �ð�
};


// �Ϸ簡 ������ �������� ������� �� Ŀ�Ǽ��� ���ø��� Ŀ�Ǽ��� �����ش�
void barista::endOfDay() {
	totalMade += numOfCofMade;
	numOfCofMade = 0;
}

// ���õ��� ���� �ٸ���Ÿ�� ���� ���� �ð�
int barista::baristaMakeTime(string drink) {
	// to do something
	int makeTime = -1;


	/*
	switch (proficiency) {
	case 0:

	case 1:

	case 2:

	case 3:

	case 4:

	case 5:

	}
	*/
	return makeTime;

}

/* �̷������� �Լ� �߰� ����
void barista::funcName(type param, ..) {

}
*/

