#pragma once
#include <iostream>
using namespace std;

class Reader {
public:
	virtual void read() { cout << "read something" << endl;
		readData();
		readCondition();
	}
protected:
	void readData() { cout << "read something data" << endl; }
	void readCondition() { cout << "read something condition" << endl; }
};

class Writer {
public:
	void write() { cout << "write something" << endl;
		writeData();
		writeResult();
	}
protected:
	void writeData() { cout << "write something Data" << endl; }
	void writeResult() { cout << "write something Result" << endl; }
};

class Computer {
public:
	void compute() { cout << "compute something" << endl; }
private:

};

// Reader �����ؼ� ���ϴµ��� ���� ���� �ε� �뷱�̿��� Reader �޾Ƽ� read��
class ReaderSample : virtual public Reader {
public:
	void read() { cout << "���� read�Ҳ� �����ż� �������̵�" << endl; 
	readCondition();
	readData();
	}
	void readData() { cout << "�����ϸ� �̷������� ���� �� ������ �Ǵ� vector�� �޴���" << endl; }
	void readCondition() { cout << "read something condition" << endl; }
};

class WriterSample : public Writer {
public:
	void write() {
		cout << "LoadBalancing���� �׳� �̰� ����" << endl;
		this->writeData(); // Ȥ�� �θ� ��������� 
		this->writeResult();
	}
private:
};

class LoadBalancing {
public:
	Reader* reader;
	Writer* writer;
	Computer* computer;
public:
	LoadBalancing() {
		reader = new Reader;
		writer = new Writer;
		computer = new Computer;
		init();
	}
	LoadBalancing(Reader* reader) {
		this->reader = reader;
		init();
	}
	LoadBalancing(Writer* writer) {
		this->writer = writer;
		init();
	}
	LoadBalancing(Computer* computer) {
		this->computer = computer;
		init();
	}
	LoadBalancing(Reader* reader, Writer* writer)
	{
		this->reader = reader;
		this->writer = writer;
		init();
	}
	LoadBalancing(Reader* reader, Writer* writer, Computer* computer) {
		this->reader = reader;
		this->writer = writer;
		this->computer = computer;
		init();
	}

	void init() {
		reader->read();
		computer->compute();
		writer->write();
	}
};
