#include <iostream>
#include <string>
#include "myAtoi.h"

using namespace std;

int main()
{
	string s = "2147483648";
	cout << myAtoi(s) << endl;
	return 0;
}