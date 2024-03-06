/*
#include <iostream>
#include <thread>
#include <cstdio>

// Example 1

using namespace std;

// lambda
class lambda_1_1 {
public:
	void operator()() // operator overloading
	{
		cout << "lambda_1_1 is calling" << endl;
	}
};

int main() {
	[]() 
		{cout << "Selam bebek" << endl;}();
	lambda_1_1 a;
	a();

	class lambda_1_2 {
	public:
		void operator()() {
			cout << "lambda_1_2 is calling" << endl;
		}
	};
	lambda_1_2()();
	return 0;
}*/
/*
#include <iostream>
#include <thread>
#include <cstdio>

// Example 2

using namespace std;

// lambda
class lambda_1_1 {
public:
	void operator()() // operator overloading
	{
		cout << "lambda_1_1 is calling" << endl;
	}
};

int main() {
	// Version 1
	[]()
		{cout << "Selam bebek" << endl; }();

	// Version 2
	lambda_1_1()();

	// Version 3
	class lambda_1_2 {
	public:
		void operator()() {
			cout << "lambda_1_2 is calling" << endl;
		}
	};

	return 0;
}*/

/*
#include <iostream>
#include <thread>
#include <cstdio>

// Example 3

using namespace std;
class lambda_1_1 {
	int x;
public:
	constexpr void operator()()  {
		
		x++;
	}
};

int main() {
	[]() {cout << "mehmet" << endl; }();
	
	lambda_1_1()();
	return 0;
}*/

#include <iostream>
#include <thread>
#include <cstdio>

// Example 4

using namespace std;
// [] <typename T> () int, constexpr, double {code}
int main() {
	auto f = [](int x) {
		cout << "Calculation : " << x << endl;
		return x;
		};
	
	class lambdaExp {
	public:
		lambdaExp(int y) {
			cout << "LambdaExp constructor : " << y << endl;
		}
		int operator()(int x) {
			cout << "Calculation : " << x << endl; 
			return 5 * x;
		}
	};
	f(5);
	auto g = lambdaExp(20)(10);
	cout << "G : " << g << endl;
	return 0;
}