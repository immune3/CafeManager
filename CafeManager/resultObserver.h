#pragma once
#include <iostream>
#include <queue>
#include "Result.h"

using namespace std;

/*
�ε� �뷱�� �˰��� ���� �ֹ��� �ٸ���Ÿ���� ���� �� ������ ����ϰ�
����� ����ϴ� Ŭ����
*/

class resultObserver
{
public :
	vector<Result> results;		//��������� ��� �ڷᱸ��
	int numOfOrders;			//��踦 ���� ���� ��ü �ֹ� ��

	resultObserver(int size)
	{
		numOfOrders = size;
	}

	void insertResult(int order, int baristaId)
	{
		Result result(order, baristaId);
		results.push_back(result);
	}

	void showResult()
	{
		cout << "�ε� �뷱�� ���" << endl;

		for (int i = 0; i < results.size(); i++)
		{
			cout << "�ֹ� ��ȣ : " << results.at(i).order << "�� �ٸ���Ÿ " << results.at(i).baristaId << "���� �����Ǿ����ϴ�." << endl;
		}



	}
};