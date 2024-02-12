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

void sendData(int i) {
	cout << "sending data" << endl;
}

int main() {
	
	int sum1, sum2=0;
	for (int i = 0; i < 10; i++) {
		sum1 += 1;
		sum2 += 1;

	}
	sendData(sum1);
	sendData(sum2);
	return 0;
}