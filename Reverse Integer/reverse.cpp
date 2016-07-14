#include <iostream>
#include <vector>

using namespace std;

int reverse(int x);
bool overflow(int x);


int main()
{
	int x = 1534236469;
	cout << INT_MIN << endl;
	cout << reverse(x) << endl;
	return 0;
}

int reverse(int x)
{
	if (overflow(x) == true)
	{
		return 0;
	}

	int ret = 0;

	while (x != 0)
	{
		ret = 10 * ret + x % 10;
		x /= 10;
	}

	return ret;
}

bool overflow(int x)
{
	// 判断溢出的方法，我服  
	if (x / 1000000000 == 0) // x的绝对值小于1000000000, 不越界  
	{
		return false;
	}
	else if (x == INT_MIN) // INT_MIN反转后越界，也没法按下述方法取绝对值（需要特判），直接返回true  
	{
		return true;
	}
	x = abs(x);
	// x = d463847412 ->  2147483647. (参数x，本身没有越界，所以d肯定是1或2)  
	// or -d463847412 -> -2147483648.   
	for (int cmp = 463847412; cmp != 0; cmp /= 10, x /= 10)
	{
		if (x % 10 > cmp % 10)
		{
			return true;
		}
		else if (x % 10 < cmp % 10)
		{
			return false;
		}
	}

	return false;
}