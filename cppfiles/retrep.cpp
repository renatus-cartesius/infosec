#include<iostream>
using namespace std;

void hello(){
	cout << "Hello World";
}

int main(){
	void (*ptr)() = hello;
	cout << &ptr << endl;
	ptr();
	//while(true){
	//}
	return 0;
}
