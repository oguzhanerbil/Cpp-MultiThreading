// Multithreading yapýlarý
/*
(1) Thread nedir ?

- Thread => "Ýþ Parçacýðý"

RAM memory

0x000000
0x040000
....
0xFFFFFF

*/

#include <iostream>

using namespace std;

// EXAMPLE 0
/*
void sendData(int i) {
	cout << "sending data" << endl;
}

void func500ms(){
}
void func100ms(){
}
void func50ms(){
}

int main() {
	
	int sum1 = 0, sum2 = 0,totalSum=0;
	for (int i = 0; i < 10; i++) {
		sum1 += 1;
		sum2 += 1;
	}
	for (int i = 0; i < 10; i++) {
		sum1 += 1;
		sum2 += 1;
		totalSum = sum1 + sum2;
	}
	sendData(totalSum);
	sendData(totalSum);
	return 0;
}
*/

// EXAMPLE 1
/*
#include <thread>

void myThread() {
	cout << "bbbbbbbbbbbb myThread fuction is calling" << endl;
}

int main() {

	thread t(&myThread);
	cout << "Hello World aaaaaaaaa";
	t.join();

	return 0;
}
*/

// EXAMPLE 2
/*
#include <thread>
#include <cstdlib>
#include <chrono>

void myThread() {
	for(;;){
	cout << "myThread is calling\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
}
}

int main() {
	thread t(&myThread);
	
	for (;;){
	cout << "main function\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	}
	t.join();
	return 0;
}
*/

// EXAMPLE 3
/*
#include <thread>
#include <cstdlib>
#include <chrono>

void myThread1() {
	for (;;) {
		cout << "myThread1 is calling\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}
void myThread2() {
	for (;;) {
		cout << "myThread2 is calling\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

int main() {
	thread t1(&myThread1);
	thread t2(&myThread2);

	for (;;) {
		cout << "main function\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	t1.join();
	t2.join();
	return 0;
}
*/

// EXAMPLE 4
/*
#include <thread>
#include <cstdlib>
#include <chrono>

void myCalcFirst(int i, int finalValue) {
	int sum=0;
	for (int j = i; j < finalValue; j++) {
		cout << "First j: " << j << endl;
		sum += j;
	}
	cout << "Total value for first: " << sum << endl;
}
void myCalcSecond(int i, int finalValue) {
	int sum=0;
	for (int j = i; j < finalValue; j++) {
		cout << "Second j: " << j << endl;
		sum += j;
	}
	cout << "Total value for second: " << sum << endl;

}

int main() {

	thread t1(&myCalcFirst, 1,10);
	thread t2(&myCalcFirst, 10,100);

	t1.join();
	t2.join();

	return 0;
}
*/

// EXAMPLE 5
/*
#include <thread>
#include <cstdlib>
#include <chrono>

void mySecondFunc() {
	for (;;) {
		cout << "mySecondFunc is running!\n";
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

void myFirstFunc() {
	for(;;){
	cout << "myFirstFunc is running!\n";
	this_thread::sleep_for(chrono::milliseconds(1000));
	}

	// thread t2(&mySecondFunc);
	// t2.join();
}

int main() {

	thread mainThread(&myFirstFunc);
	thread t2(&mySecondFunc);
	
	mainThread.join();
	t2.join();

	return 0;
}

*/

// EXAMPLE 6
// functor

#include <thread>
#include <cstdlib>
#include <chrono>

class myFuncObject {
public:
	void operator()() {
		for (;;) {
			cout << "myFucnObject is calling\n";
			this_thread::sleep_for(chrono::milliseconds(1000));

		}
	}
};

int main() {

	myFuncObject fObject;
	thread t(fObject);
	for (;;) {
		cout << "my main thread\n";
		this_thread::sleep_for(chrono::milliseconds(1000));

	}

	// fObject();
	//fObject.operator()();

	
	t.join();
	return 0;
}