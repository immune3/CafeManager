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

priority_queue<pair <int, int> > workIndex;

//#define MAX_ORDER 10 // �ٸ���Ÿ ������ ���� �� �ִ� �ִ� �ֹ���
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
	int menuIndex;

	for (int i = 0; i < men.size(); i++) {
		if (men[i].getDrinkName() == drinkName) {
			menuIndex = i;
			break;
		}
	}
//	int makeTime = searchMakeTime(drinkName, 0, men.size());

	if (numOfDrink == 1) { // �ֹ� ���� 1���̸�
	// ������������ ���ĵ������Ƿ� ���õ��� ���� barista���� ã��(�ں��� search)
		// 1. �ٸ���Ÿ��ũ�� ���� ���Ḧ����� �ִ���, ���� ���� ������

		int min = 1000;
		int minIndex;
		for (int i = numOfBarista - 1; i >= 0; i--) { // �ٸ���Ÿ index�� 0���� �̹Ƿ� numOfBarista-1
			if (bari[i].getRank() >= men[menuIndex].getRank() && bari[i].getNumOfCofMade() < min) {
				min = bari[i].getNumOfCofMade();
				minIndex = i;
			}
		}

		bari[minIndex].setFinishMakingTime(ord.getOrderTime() + men[menuIndex].getMakeTime());
		bari[minIndex].incNumOfCofMade();
		cout << "��� �ٸ���Ÿ :" << minIndex << " �Ϸ�ð�:"<< bari[minIndex].getFinishMakingTime() << endl;
		workIndex.push(make_pair(minIndex, bari[minIndex].getFinishMakingTime().getTimeSec()));
		// 


		/*
		for (int i = numOfBarista - 1; i >= 0; i--) {
			if (!bari[i].getDoing()) {	// ���� ���ϰ� ������
				bari[i].doWork();	// barista�� flag�� true�� �ٲ���
				//workIndex.push_back();
				break;
			}
			
		}
		*/
	}
	else {	// �ֹ� ���� ������ �������̸�
		for (int i = 0; i < numOfDrink; i++) {
			int min = 1000;
			int minIndex;
			for (int i = numOfBarista - 1; i >= 0; i--) { // �ٸ���Ÿ index�� 0���� �̹Ƿ� numOfBarista-1
				if (bari[i].getRank() >= men[menuIndex].getRank() && bari[i].getNumOfCofMade() < min) {
					min = bari[i].getNumOfCofMade();
					minIndex = i;
				}
			}

			bari[minIndex].setFinishMakingTime(ord.getOrderTime() + men[menuIndex].getMakeTime());
			bari[minIndex].incNumOfCofMade();
			cout << "��� �ٸ���Ÿ :" << minIndex << " �Ϸ�ð�:" << bari[minIndex].getFinishMakingTime() << endl;
			workIndex.push(make_pair(minIndex, bari[minIndex].getFinishMakingTime().getTimeSec()));
		}
	}
}

void findEndOrder() {
	// to do something

}

void start() {
	int totalMake = 0;	// ��� �ٸ���Ÿ ���� �� �����
	myTime curTime = "08:30:00";	// ���� ���� �ð�(�ð��� �帧�� ���� ����)
	
	// ť�� �մ� �ֹ��� �� �� ������
	while (!ord.empty()) {
		order curOrd = ord.front(); // ���� �տ��մ� �ֹ��� ������
		
		if (curOrd.getOrderTime() == curTime) {		// �� ���� �ֹ��� ���� �ð��� �������
			cout << "����ð� :" << curTime << endl;
			if (workIndex.size() == bari.size()) {
				string curDrinkName = curOrd.getDrinkName();
				int curMakeTime;
				for (int i = 0; i < men.size(); i++) {
					if (curDrinkName == men[i].getDrinkName()) {
						curMakeTime = men[i].getMakeTime();
						break;
					}
				}
				
				int bariNum = workIndex.top().first;
				int bariTime = workIndex.top().second;
				bariTime = bariTime + curMakeTime;
				workIndex.pop();
				workIndex.push(make_pair(bariNum, bariTime));
				//cout << workIndex.top().first << endl;
				//cout << workIndex.top().second << endl;
				
			}
			
			// �ε� �뷱�� �˰����� ���� ���� �ֹ���ȣ�� �´� �ٸ���Ÿ�� ������
			selectBarista(curOrd);	// ���� ������ �Ѱ���
			
			// ��� �ٸ���Ÿ ���� �� ����� update
			totalMake += curOrd.getNumOfDrink();
			//cout << "�� ���� Ŀ�Ǽ� :" << totalMake << endl;			
			// �ֹ� �Ϸ� ť���� ����
			ord.pop();
		}
		else {	// �� ���� �ֹ��� ���� �ð��� �ٸ� ���
			
			// �ֹ� �Ϸ�ð�(pop)
			while(!workIndex.empty() && (bari[workIndex.top().first].getFinishMakingTime() == curTime)){
				cout << "�ٸ���Ÿ ��ȣ : "<< workIndex.top().first << " ����ð� :" << curTime << endl;
				workIndex.pop();
			}

			++curTime;	// �ð��� 1�� �÷���
			

			// to do something
			// � �ٸ���Ÿ�� �������� ���ᰡ �Ϸ�� �ð��� ��� �ٸ���Ÿ�� �÷��׸� false�� ������ְ� �����Ϸ� �޼��� ���
			findEndOrder();
		}
		
	}
}

