#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(1);
	//nums.push_back(1);
	//nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(5);
	//nums.push_back(4);
	sort(nums.begin(), nums.end());
	vector<int> sum;
	int i = 1;
	if (nums[0] < nums[1])
	{
		sum.push_back(nums[0]);
	}
	for (; i < nums.size()-1; ++i)
	{
	
		if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
		{
			sum.push_back(nums[i]);
		}
	}

	if (i == nums.size() - 1)
	{
		if (nums[nums.size() - 1] > nums[nums.size() - 2])
		{
			sum.push_back(nums[i]);
		}
	}

	for (auto e : sum)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}



//int main()
//{
//	vector<int> nums;
//	nums.push_back(0);
//	nums.push_back(0);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(4);
//	
//	int i = 0;
//	while(i<nums.size()-1)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			vector<int>::iterator it1 =find(nums.begin(), nums.end(), nums[i]);
//				nums.erase(it1);
//		}
//		else
//		{
//			++i;
//		}
//	}
//	for (auto e : nums)
//	{
//		cout<< e << " ";
//	}
//	cout << nums.size();
//	cout << endl;
//
//
//	return 0;
//}