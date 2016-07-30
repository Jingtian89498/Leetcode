#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n);

int main()
{
	string str;
	
	str = to_string(3);
	if (str[1] == '\0')
		cout << str[0] << endl;

	for (int i = 1; i < 10; i++)
		cout << countAndSay(i) << endl;

	return 0;


}

string countAndSay(int n) {
	string str = "\0";
	string str1;
	if (n == 1)
		str = '1';
	else
	{
		str1 = countAndSay(n - 1);
		int i;
		int j, k;
		for (i = 0; str1[i] != 0; i = j)
		{
			k = 1;
			for (j = i + 1; str1[j] == str1[i]; j++)
				k++;
			str = str + to_string(k) + str1[i];
		}
	}
	return str;
}
