#include <iostream>
#include <string>
#include <vector>
using namespace std;

// arrange them 
// the largest number
// [3, 30, 34, 5, 9] 9534330

// �ҳ����������λ���������������ȣ�������Ƚ���һλ����λ������ȣ���ȡλ���ٵģ�
// �����õķ����� ������ð�ݷ����Ƚ��ǽ����������ϲ������ַ�ʽ���д�С�Ƚϡ�

// ��ȫ������to_string() ����
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
			// �Ƚ� nums[i] �� nums[j] �Ǹ����󣨱ȽϷ�������
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
			int leng = str.length();//ȡ��󴮵ĳ���
			for (int j = 0; j < leng; j++)//���õ����ַ�����ת������µĴ�,
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

