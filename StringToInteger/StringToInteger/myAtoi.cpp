#include <string>
#include "myAtoi.h"

using namespace std;

int myAtoi(string str)
{
	if (str == "")
		return 0;
	int i = 0;
	int sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return 0;
	long long result = str[i] - '0'; // 需要越界判断，不能用int
	for (i = i+1; str[i] != 0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			if (result > INT_MAX)
				return sign < 0 ? INT_MIN : INT_MAX;
		}
		else
			break;
	}

	return (int)result * sign;
}
