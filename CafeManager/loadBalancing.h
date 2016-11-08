#pragma once

// ���� �����ϰ� �ִ� �ε� �뷱�� �˰���
/*
# Least Connection (�ּ� ���� ���) 
+ ���� Ŀ�ؼ��� ���� ���� ������ ����� �䱸�� �����ϴ� ��� 
+ �յ��� Ʈ���� �����ϱ� ���� ó�� �ӵ��� ���� ������ �� ���� ������ �ް� �� 
+ �������� ������ ����ϰ� �����Ǿ��� �� ȿ������ Ʈ���� �л��� ����

CafeManager�� ���� ���� ����
�ٸ���Ÿ �� ���� ���� ������ �ϰ� ���� �� �� �ٸ���Ÿ���� �ֹ� �Ҵ�
���õ��� ���� (���� �ð��� ����) �ٸ���Ÿ�� ���� ��� �� ���� �ֹ� �Ҵ�
�䱸�Ǵ� �޴��� �յ��ϰ� �ֹ� �Ǿ��� �� or �ٸ���Ÿ�� ó�� ������ �޴��� 
�յ��ϰ� �ֹ� �Ǿ��� �� ȿ�������� �л� ����
*/


// main�� ���� �� �� �� ���Ͽ��� ������ �� �� extern �Լ��� static����
extern vector<menu> men;
extern vector<barista> bari;
extern queue<order> ord;

#define MAX_ORDER 10 // �ٸ���Ÿ ������ ���� �� �ִ� �ִ� �ֹ���

int selectBarista(order ord) {
	// ������� ������ �𸣴� �켱�� ���� Ŀ�� ���� �ò��� ����
	// �ʱⰪ�� �ִ밪���� ����
	int least = MAX_ORDER + 1;
	int id;

	// ���� �׳� �ٸ���Ÿ �ֹ� ���� ������ �й��ϴ� ��

	for (int i = 0; i < bari.size(); i++) {
		// ���� ���� �ֹ����� ���� �ٸ���Ÿ�� ã�� ���� loop�� ������ Ȯ��
		if (least > bari[i].currentWork()) {
			least = bari[i].currentWork();
			id = i; // �ش� �ٸ���Ÿ�� index�� ���� Ȥ�� �ٸ���Ÿ ��ü�� ã�� ���� ����
		}
	}

	return id;
}

void loadBalancing() {
	// ť�� �մ� �ֹ��� �� �� ������
	while (!ord.empty()) {
		// ���� �տ��մ� �ֹ��� ������
		order curOrd = ord.front();
		// �迭�� ��� �ٸ���Ÿ�� ���̵�(�ε���)
		int baristaId;
		// �ε� �뷱�� �˰����� ���� ���� �ֹ���ȣ�� �´� �ٸ���Ÿ�� ������
		baristaId = selectBarista(curOrd);
		// �ٸ���Ÿ Ŭ���������� doWork()�� ���� ������ ������� ����
		// ���õ� �ٸ���Ÿ���� �ֹ� �Ҵ�
		bari[baristaId].doWork(curOrd.getDrinkName(), curOrd.getNumOfDrink());
		// �ֹ� �Ϸ� ť���� ����
		ord.pop();
	}
}

