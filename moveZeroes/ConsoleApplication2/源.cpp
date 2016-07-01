#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums);
void moveZeroes1(vector<int>& nums);
void moveZeroes2(vector<int>& nums);

int main()
{
	vector<int> arr = { 0,14,3,4,0,2,0 };
	moveZeroes2(arr);
	for (int i = 0; i < (int)arr.size(); i++)
	{
		cout << arr[i] << ";\t";
	}
	cin.get();
	return 0;
}

void moveZeroes(vector<int>& nums)
{
	/* �����ĸ���
	 * ѭ�����Ѳ�Ϊ��������ηŵ����
	 * ����ٰ�ǰ�����ȫ���Ƶ����	
	*/
	int n = nums.size();

	// count the zeroes
	int numZeroes = 0;
	for (int i = 0; i < n; i++)
	{
		numZeroes += (nums[i] == 0);
	}

	// make all the non-zero elements retain their original order.
	vector<int> ans;
	for (int i = 0; i <n; i++)
	{
		if (nums[i] != 0)
		{
			ans.push_back(nums[i]);
		}
	}

	// move all zeros to the end
	while (numZeroes--)
	{
		ans.push_back(0);
	}

	// combine the result.
	for (int i = 0; i < n; i++)
	{
		nums[i] = ans[i];
	}
}

void moveZeroes1(vector<int>& nums)
{
	/* ѭ�����ҳ���һ�����λ�ã�����֮��ĵ�һ����������ֵ����
	 * ���ӵ�һ���������գ���ֵΪ0
	*/
	int lastNonZeroFoundAt = 0;

	for (int i = 0; i < (int)nums.size(); i++)
	{
		if (nums[i] != 0)
		{
			nums[lastNonZeroFoundAt++] = nums[i];
		}
	}

	for (int i = lastNonZeroFoundAt; i < (int)nums.size(); i++)
	{
		nums[i] = 0;
	}
}

void moveZeroes2(vector<int>& nums)
{
	// ѭ���������ֵĵ�һ������֮���һ������������
	for (int lastNonZeroFoundAt = 0, cur = 0; cur < (int)nums.size(); cur++)
	{
		if (nums[cur] != 0)
		{
			swap(nums[lastNonZeroFoundAt++], nums[cur]);
		}
	}
}