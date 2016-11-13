#include <iostream>
#include <fstream>
#include <queue>
#include "barista.h"
#include "order.h"
#include "myTime.h"
#include "loadBalancing.h"

using namespace std;

// fstream functions
void loadMenuFile(string fileName);
void loadBaristaFile(string fileName);
void loadOrderFile(string fileName);

vector<menu> men;		// 모든 메뉴 정보를 저장해둘 vector형 자료구조
vector<barista> bari;	// 모든 바리스타 정보 저장해둘 vector형 자료구조
queue<order> ord;		// 모든 주문정보를 저장해둘 queue형 자료구조

string drinkName;	// 메뉴 이름

// main 안에 깔끔하게 해서 구분하기 편하게 하기 위해 따로 뺀거
void test();

int main() {

	// loadBalancing
	//start();

	// test
	//test();
	
	return 0;
}
