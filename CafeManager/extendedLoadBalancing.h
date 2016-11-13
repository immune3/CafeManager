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
	virtual void write() { cout << "write something" << endl;
		writeData();
		writeResult();
	}
protected:
	void writeData() { cout << "write something Data" << endl; }
	void writeResult() { cout << "write something Result" << endl; }
};

class Computer {
public:
	virtual void compute() { cout << "compute something" << endl; }
private:

};

// Reader 종속해서 원하는데로 구현 실제 로드 밸런싱에선 Reader 받아서 read함
class ReaderSample : public Reader {
public:
	void read() { cout << "Reader Sample" << endl; 
	readCondition();
	readData();
	}
	void readData() { cout << "Read Data Sample" << endl; }
	void readCondition() { cout << "read something condition" << endl; }
};

class WriterSample : public Writer {
public:
	void write() {
		cout << "Writer Sample" << endl;
		this->writeData(); // 혹은 부모꺼 써버리던지 
		this->writeResult();
	}
private:
};

class ExtendedLoadBalancing {
public:
	Reader* reader;
	Writer* writer;
	Computer* computer;
public:
	ExtendedLoadBalancing() {
		reader = new Reader;
		writer = new Writer;
		computer = new Computer;
		init();
	}
	ExtendedLoadBalancing(Reader* reader) {
		this->reader = reader;
		init();
	}
	ExtendedLoadBalancing(Writer* writer) {
		this->writer = writer;
		init();
	}
	ExtendedLoadBalancing(Computer* computer) {
		this->computer = computer;
		init();
	}
	ExtendedLoadBalancing(Reader* reader, Writer* writer)
	{
		this->reader = reader;
		this->writer = writer;
		init();
	}
	ExtendedLoadBalancing(Reader* reader, Writer* writer, Computer* computer) {
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


