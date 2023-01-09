#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	while (*nums.begin() == val)
	{
		nums.erase(nums.begin());
	}
	return nums.size();
}

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(1);x
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(1);
	v1.push_back(5);
	v1.push_back(1);

	int ret= removeElement(v1, 1);
	cout << ret << endl;
	return 0;
}