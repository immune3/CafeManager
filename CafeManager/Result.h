#pragma once
#include <iostream>

using namespace std;

/*
������� ����ϴ� result Observer���� ����ϴ� Ŭ����.
������� ��� �������� ��Ÿ����.
*/

class Result
{
public:
	int order;
	int baristaId;

	Result(int tmp_order, int tmp_baristaId)
	{
		order = tmp_order;
		baristaId = tmp_baristaId;
	}

};