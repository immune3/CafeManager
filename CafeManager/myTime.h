// �� �� �� ó���� �����ϱ� ���� ��� (������ main�� test()�� ����)
#pragma once
#include <string>
using namespace std;

class myTime {
private:
	int hour;
	int min;
	int sec;
public:
	myTime() {
		hour = 0;
		min = 0;
		sec = 0;
	}
	
	// hh:mm:ss �������� ���� string�� int�� ��, ��, �ʷ� �и��� �������ش�
	myTime(string time) {
		hour = (time[0] - '0') * 10 + (time[1] - '0');
		min = (time[3] - '0') * 10 + (time[4] - '0');;
		sec = (time[6] - '0') * 10 + (time[7] - '0');;
	}

	// accessor
	int getHour();
	int getMin();
	int getSec();


	//mutator
	void setTime(string time);

	// ostream ������ << �����ε�(����� ����)
	friend ostream& operator<<(ostream& out, const myTime& t) {
		
		if (t.hour < 10)
			out << "0" << t.hour;
		else
			out << t.hour;
		if (t.min < 10)
			out << ":0" << t.min;
		else
			out << ":" << t.min;
		if (t.sec < 10)
			out << ":0" << t.sec;
		else
			out << ":" << t.sec;
		return out;
	}

	// myTime type���� ==(equal) �񱳿����� �����ε�
	bool operator==(myTime &t);
};

// accessor
int myTime::getHour() {
	if (hour > 23)
		hour -= 24;
	return hour; 
}

int myTime::getMin() {
	if (min > 60) {
		hour++;
		min -= 60;
	}
	getHour();
	return min; 
}

int myTime::getSec() {
	if (sec > 60){
		min++;
		sec -= 60;
	}
	getMin();
	return sec; 
}

void myTime::setTime(string time) {
	hour = (time[0] - '0') * 10 + (time[1] - '0');
	min = (time[3] - '0') * 10 + (time[4] - '0');;
	sec = (time[6] - '0') * 10 + (time[7] - '0');;
}

// ������ �����ε�
bool myTime::operator==(myTime &t) {
	if (hour != t.hour || min != t.min || sec != t.sec)
		return false;
	return true;
}