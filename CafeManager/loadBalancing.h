#pragma once

// ���� �����ϰ� �ִ� �ε� �뷱�� �˰���
/*
# Least Connection (�ּ� ���� ���) 
+ ���� Ŀ�ؼ��� ���� ���� ������ ����� �䱸�� �����ϴ� ��� 
+ �յ��� Ʈ���� �����ϱ� ���� ó�� �ӵ��� ���� ������ �� ���� ������ �ް� �� 
+ �������� ������ ����ϰ� �����Ǿ��� �� ȿ������ Ʈ���� �л��� ����

CafeManager�� ���� ���� ����
�ٸ���Ÿ �� ���� ���� ������ �ϰ� ���� �� �� �ٸ���Ÿ���� �ֹ� �Ҵ�
��ũ�� ���� (������ �� �ִ� ������� ����) �ٸ���Ÿ�� ���� ��� �� ���� �ֹ� �Ҵ�
�䱸�Ǵ� �޴��� �յ��ϰ� �ֹ� �Ǿ��� �� or �ٸ���Ÿ�� ó�� ������ �޴��� 
�յ��ϰ� �ֹ� �Ǿ��� �� ȿ�������� �л� ����
*/


// main�� ���� �� �� �� ���Ͽ��� ������ �� �� extern �Լ��� static����
extern vector<menu> men;
extern vector<barista> bari;
extern queue<order> ord;
//vector<int, int> workIndex;

#define MAX_ORDER 10 // �ٸ���Ÿ ������ ���� �� �ִ� �ִ� �ֹ���
/*
int searchMakeTime(string drinkName, int begin, int end) {
	int mid = (begin + end) / 2;
	if (drinkName == men[mid].getDrinkName()) {
		cout << "ã�� ���� �̸� :" << drinkName << endl;
		return men[mid].getMakeTime();
	}
	else if (begin <= end){
		if (drinkName[0] == men[mid].getDrinkName()[0])
			
		else if (drinkName[0] < men[mid].getDrinkName()[0])
			searchMakeTime(drinkName, begin, mid);
		else
			searchMakeTime(drinkName, mid, end);
	}
}
*/
void selectBarista(order ord) {
	
	int numOfDrink = ord.getNumOfDrink();	// �ֹ� ���� ����
	int numOfBarista = bari.size();		// �� �ٸ���Ÿ�� ��
	string drinkName = ord.getDrinkName();
	
//	int makeTime = searchMakeTime(drinkName, 0, men.size());

	if (numOfDrink == 1) { // �ֹ� ���� 1���̸�
	// ������������ ���ĵ������Ƿ� ���õ��� ���� barista���� ã��(�ں��� search)
		for (int i = numOfBarista - 1; i >= 0; i--) {	// �ٸ���Ÿ index�� 0���� �̹Ƿ� numOfBarista-1
			if (!bari[i].getDoing()) {	// ���� ���ϰ� ������
				bari[i].doWork();	// barista�� flag�� true�� �ٲ���
				//workIndex.push_back();
				break;
			}
		}
	}
	else {	// �ֹ� ���� ������ �������̸�

		// �̺κ��� �ϴ� ����ǰ� �س������ �ֹ������� 1���϶� �� �ٿ��ֱ��ص� �ٲ����
		for (int i = numOfBarista -1 ; i >= 0; i--) {
			if (!bari[i].getDoing()) {	// ���� ���ϰ� ������
				bari[i].doWork();	// barista�� flag�� true�� �ٲ���
				break;
			}
		}
	}
}

void findEndOrder() {
	// to do something

}

void start() {
	int totalMake = 0;	// ��� �ٸ���Ÿ ���� �� �����
	myTime curTime;// = "08:30:00";	// ���� ���� �ð�(�ð��� �帧�� ���� ����)

	// ť�� �մ� �ֹ��� �� �� ������
	while (!ord.empty()) {
		order curOrd = ord.front(); // ���� �տ��մ� �ֹ��� ������
		if (curOrd.getOrderTime() == curTime) {		// �� ���� �ֹ��� ���� �ð��� �������

			cout << "�ֹ� ��ȣ :" << curOrd.getOrderNum() << " �ֹ� ���� �ð� :" << curTime << " ���� :"<< curOrd.getNumOfDrink() << endl;

			// �ε� �뷱�� �˰����� ���� ���� �ֹ���ȣ�� �´� �ٸ���Ÿ�� ������
			selectBarista(curOrd);	// ���� ������ �Ѱ���

			// ��� �ٸ���Ÿ ���� �� ����� update
			totalMake += curOrd.getNumOfDrink();
			cout << "�� ���� Ŀ�Ǽ� :" << totalMake << endl;			
			// �ֹ� �Ϸ� ť���� ����
			ord.pop();
		}
		else {	// �� ���� �ֹ��� ���� �ð��� �ٸ� ���
			++curTime;	// �ð��� 1�� �÷���
			
			// to do something
			// � �ٸ���Ÿ�� �������� ���ᰡ �Ϸ�� �ð��� ��� �ٸ���Ÿ�� �÷��׸� false�� ������ְ� �����Ϸ� �޼��� ���
			findEndOrder();
		}
		
	}
}

