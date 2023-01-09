#include<iostream>
#include<vector>

using namespace std;



    //int removeDuplicates(vector<int>& nums) {
    //    int fast = 0;
    //    int slow = 0;
    //    int num = nums.size();
    //    int count = 0;
    //    for (; slow < nums.size(); ++slow)
    //    {
    //        fast = slow + 1;
    //        while (fast < nums.size())
    //        {
    //            if (nums[fast] == nums[slow])
    //            {
    //                count++;
    //                if (count == 2)
    //                {
    //                    nums.erase(nums.begin() + fast);
    //                    count--;
    //                    num--;
    //                    continue;
    //                }
    //                else
    //                {
    //                    fast++;
    //                    continue;
    //                }
    //            }
    //            fast++;

    //            
    //        }
    //        count = 0;
    //    }
    //    return num;
    //}

    vector<int> sortedSquares(vector<int>& nums) {
        int negetive = -1;
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                negetive = i;
            }
        }
        int i = negetive;
        int j = i + 1;
        //i<0为没有负数，i>=0才有负数
        while (i >= 0 || j < nums.size())
        {
            if (i < 0)//没有负数
            {
                v.push_back(nums[j] * nums[j]);
                j++;
            }
            else if (j == nums.size())
            {
                v.push_back(nums[i] * nums[i]);
                i--;
            }
            else if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                v.push_back(nums[i] * nums[i]);
                i--;
            }
            else {
                v.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return v;
    }

int main()
{
    vector<int> v1;
    vector<int>v2;
    v1.push_back(-4);
    v1.push_back(-1);
    v1.push_back(0);
    v1.push_back(3);
    v1.push_back(10);

    v2= sortedSquares(v1);
    for (auto e : v2)
    {
        cout << e << " ";
    }
    cout << endl;
	return 0;
}


//v1.push_back(1);
//v1.push_back(1);
//v1.push_back(2);
//v1.push_back(3);
//v1.push_back(3);
//int removeElement(vector<int>& nums, int val) {
//    int slowIndex = 0;
//    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
//        if (val != nums[fastIndex]) {
//            nums[slowIndex++] = nums[fastIndex];
//        }
//    }
//    return slowIndex;
//}