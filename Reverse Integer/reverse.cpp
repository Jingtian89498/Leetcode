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
	// �ж�����ķ������ҷ�  
	if (x / 1000000000 == 0) // x�ľ���ֵС��1000000000, ��Խ��  
	{
		return false;
	}
	else if (x == INT_MIN) // INT_MIN��ת��Խ�磬Ҳû������������ȡ����ֵ����Ҫ���У���ֱ�ӷ���true  
	{
		return true;
	}
	x = abs(x);
	// x = d463847412 ->  2147483647. (����x������û��Խ�磬����d�϶���1��2)  
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