#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s);

int main()
{
	string str;
	str = " 1";
	cout << lengthOfLastWord(str) << endl;
	return 0;
}

int lengthOfLastWord(string s)
{
	if (s == "")
	    return 0;
	int l = 0;
	int length = 0;
	while (s[l] != 0)
		l++;
	int i = l - 1;
	for (i; i && s[i] == ' '; i--){}
	for (i; i != 0 && s[i] != ' '; i--)
		length++;
	if (i == 0 && s[i] != ' ')
		return length + 1;
	else
		return length;
}
