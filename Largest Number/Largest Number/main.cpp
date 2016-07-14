#include <iostream>
#include <string>
#include <vector>
using namespace std;

// arrange them 
// the largest number
// [3, 30, 34, 5, 9] 9534330

// 找出数组里最高位最大的数。（如果相等，则继续比较下一位；若位数仍相等，则取位数少的）
// 最后采用的方法是 类似于冒泡法。比较是将这两个数合并的两种方式进行大小比较。

// 完全可以用to_string() 函数
string largestNumber(vector<int>& nums);

int main()
{
	vector<int> numbs = { 0,0};
	//largestNumber(numbs);
	cout << largestNumber(numbs) << endl;
	char ch;
	cin.get(ch);
	return 0;
}

string largestNumber(vector<int>& nums)
{
	string largestNumber;
	
	for (int i = 0; i < int(nums.size()) - 1; i++)
	{
		for (int j = i + 1; j < int(nums.size()); j++)
		{
			// 比较 nums[i] 与 nums[j] 那个更大（比较方法：）
			int inumbers = 1;
			int jnumbers = 1;
			int a = nums[i];
			int b = nums[j];
			while (a /= 10)	inumbers++;
			while (b /= 10)	jnumbers++;
			if ((nums[i] * pow(10, jnumbers) + nums[j]) < (nums[j] * pow(10, inumbers) + nums[i]))
			{
				swap(nums[i], nums[j]);
			}
			
		}
	}
	for (int i = 0; i < int(nums.size()); i++)
		cout << nums[i] << endl;
	int flag = 0;
	for (int i = 0; i < int(nums.size()); i++)
		if (nums[i] == 0)
			flag++;
	if (flag != int(nums.size()))
	{
		for (int i = 0; i < int(nums.size()); i++)
		{
			string str, strt;
			do
			{
				str += char(nums[i] % 10 + 48);
			} while (nums[i] /= 10);
			int leng = str.length();//取最后串的长度
			for (int j = 0; j < leng; j++)//将得到的字符串反转后放入新的串,
			{
				strt += str[leng - 1 - j];
			}
			largestNumber += strt;
		}
	}
	else
		largestNumber = "0";
	
	
	return largestNumber;
}

