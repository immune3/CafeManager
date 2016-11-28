// �� �� �� ó���� �����ϱ� ���� ��� (������ main�� test()�� ����)
#pragma once
#include <string>
using namespace std;

class myTime {
private:
	int hour;
	int min;
	int sec;
	int timeSec;
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

	// hh:mm:ss �������� ���� string�� int�� ��, ��, �ʷ� �и��� �������ش�
	myTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	// accessor
	int getHour();
	int getMin();
	int getSec();
	int getTimeSec();


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
	bool operator>(myTime &t);
	bool operator<(myTime &t);

	myTime operator+(int num);
	myTime& operator++();
};

// accessor
int myTime::getHour() {
	if (hour > 23)
		hour -= 24;
	return hour; 
}

int myTime::getMin() {
	if (min > 59) {
		hour++;
		min -= 60;
	}
	getHour();
	return min; 
}

int myTime::getSec() {
	if (sec > 59){
		min++;
		sec -= 60;
	}
	getMin();
	return sec; 
}

int myTime::getTimeSec() {
	return sec + min * 60 + hour * 360;
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

bool myTime::operator>(myTime &t) {
	if (hour > t.hour)
		return true;
	else if (min > t.min)
		return true;
	else if (sec > t.sec)
		return true;
	else
		return false;
}

bool myTime::operator<(myTime &t) {
	if (hour < t.hour)
		return true;
	else if (min < t.min)
		return true;
	else if (sec < t.sec)
		return true;
	else
		return false;
}

myTime myTime::operator+(int num) {
	myTime temp(hour, min, sec);
	temp.min += num;
	if (temp.min > 59) {
		temp.hour++;
		temp.min -= 60;
	}
	if (temp.hour > 23)
		temp.hour -= 24;
	return temp;
}



myTime& myTime::operator++() {
	min++;
	if (min > 59) {
		hour++;
		min -= 60;
	}
	if (hour > 23)
		hour -= 24;

	return *this;
}
