#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> & digits);

int main()
{
	vector<int> a = { 9 };
	vector<int> b;
	b = plusOne(a);
	for (int x : b)
		cout << x << '\t';
	cout << endl;
	return 0;
}

vector<int> plusOne(vector<int> & digits)
{
	vector<int> result = digits;
	int n = digits.size();
	int i;
	int flag = 1;
	for (i = n - 1; i >= 0; i--)
	{
		result[i] = (digits[i] + flag) % 10;
		flag = (digits[i] + flag) / 10;
	}
	if (flag == 1)
		result.insert(result.begin(), 1);
	return result;

}
