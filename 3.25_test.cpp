#include<iostream>
#include<vector>

using namespace std;
//135.分发糖果
// 保证较大评分的那个比周围分到的糖果数最大；先从前往后遍历一遍，右边比左边大时，右边糖果数为左边糖果数+1，
// 再从右往左遍历一遍，当左边评分比右边高时，左边糖果数为此时糖果数和右边糖果数+1的最大值
// class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        int ret = 0;
//        //先从前往后遍历，大的比小的多1
//        vector<int> candyses(ratings.size(), 1);
//        for (int i = 1; i < ratings.size(); i++)
//        {
//            if (ratings[i] > ratings[i - 1])
//            {
//                candyses[i] = candyses[i - 1] + 1;
//            }
//        }
//        //再从后往前遍历，大的拿此时的糖果数量和小的+1比较取大的
//        for (int i = ratings.size() - 2; i >= 0; i--)
//        {
//            if (ratings[i] > ratings[i + 1])
//            {
//                candyses[i] = max(candyses[i], candyses[i + 1] + 1);
//            }
//        }
//        for (auto e : candyses)
//        {
//            ret += e;
//        }
//        return ret;
//    }
//};
//134.加油站
//一、当总量和小于0，不能循环返回-1，当每次的差值（最小值)都大于0，能跑完；其余就从后往前遍历，当能把前面负的部分填补完即起点
//二、从0开始遍历，当余量总量小于0时，前一个站为start，余量为0；当往后都是正值是start即为起点；前者是total量不为负数即能循环完的情况，否则返回-1
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int totalsum = 0;
//        int start = 0;
//        int cursum = 0;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            cursum += gas[i] - cost[i];
//            totalsum += gas[i] - cost[i];
//            if (cursum < 0)
//            {
//                start = i + 1;
//                cursum = 0;
//            }
//        }
//        if (totalsum < 0) return -1;
//        return start;
//    }
//};
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int totalsum = 0;
//        int start = 0;
//        int cursum = 0;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            cursum += gas[i] - cost[i];
//            totalsum += gas[i] - cost[i];
//            if (cursum < 0)
//            {
//                start = i + 1;
//                cursum = 0;
//            }
//        }
//        if (totalsum < 0) return -1;
//        return start;
//    }
//};
//1005.k次取反后最大化的数组和
// 按绝对值从大到小排序，然后从大到小取反的正加权，剩余k次数给最小值用
// class Solution {
//public:
//    static bool cmp(int a, int b)
//    {
//        return abs(a) > abs(b);
//    }
//
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end(), cmp);
//        int sum = 0;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            if (nums[i] < 0 && k>0)
//            {
//                nums[i] *= -1;
//                k--;
//            }
//            sum += nums[i];
//        }
//
//        if (k > 0 && (k % 2 != 0))
//        {
//            sum += (nums[nums.size() - 1] * (-1));
//        }
//        else
//        {
//            sum += nums[nums.size() - 1];
//        }
//        return sum;
//    }
//};
//45.跳跃游戏二
//必然能跳到最后，返回最小步数，若在此阶段不能到达，在此阶段取最大覆盖范围，当到达此阶段时步数++且更新覆盖范围
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int ret = 0;
//        int curpath = 0;
//        int nextpath = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            nextpath = nextpath > i + nums[i] ? nextpath : i + nums[i];
//            if (i == curpath && curpath < nums.size() - 1)
//            {
//                ret++;
//                curpath = nextpath;
//                if (nextpath >= nums.size() - 1)
//                {
//                    break;
//                }
//            }
//        }
//        return ret;
//    }
//};

//55.跳跃游戏
// 取最大路径覆盖范围
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        int path = 0;
//        int nextpath = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            nextpath = nextpath > (i + nums[i]) ? nextpath : (nums[i] + i);
//            if (path == i)
//            {
//                path = nextpath;
//                if (path >= nums.size() - 1)
//                {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};


//122.买卖股票的最佳时机二
// 只要有的赚就买【1，2，3】 3-1=（2-1）+（3-2）
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int value = 0;
//        for (int i = 1; i < prices.size(); i++)
//        {
//            if ((prices[i] - prices[i - 1]) > 0)
//            {
//                value += prices[i] - prices[i - 1];
//            }
//        }
//        return value;
//    }
//};

//53.最大子数组和
// 当value小于0时势必会拉低后面总数组，那么要更新value；只需要value比maxvalue大就能更新maxvalue了
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int value = 0;
//        int maxvalue = INT_MIN;
//        if (nums.size() == 1)
//        {
//            return nums[0];
//        }
//        for (int i = 0; i < nums.size(); i++)
//        {
//            value += nums[i];
//            maxvalue = maxvalue > value ? maxvalue : value;
//            if (value < 0)
//            {
//                value = 0;
//            }
//        }
//        return maxvalue;
//    }
//};

//376.摆动序列
// 用prev记录前一对的差值，cur记录当前对的差值，达到摆动ret就加加，当达到摆动的时候prev才更新，相当于中间有不摆动的序列直接跳过，因为一个元素或者两个元素也算是摆动，所以ret默认值是1
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//        int curdvalue = 0;
//        int prevdvalue = 0;
//        int ret = 1;
//        for (int i = 1; i < nums.size(); i++)
//        {
//            curdvalue = nums[i] - nums[i - 1];
//            if ((prevdvalue <= 0 && curdvalue > 0) || (prevdvalue >= 0 && curdvalue < 0))
//            {
//                ret++;
//                prevdvalue = curdvalue;
//            }
//        }
//        return ret;
//    }
//};

//455.分发饼干
// 
// 从大到小遍历孩子
// class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end(), greater<int>());
//        sort(s.begin(), s.end(), greater<int>());
//        int index = 0;
//        for (int i = 0; i < g.size(); i++)
//        {
//            if (index < s.size() && s[index] >= g[i])
//            {
//                index++;
//            }
//        }
//        return index;
//    }
//};
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//        int num = 0;
//        for (int i = 0; i < s.size(); i++)//遍历饼干，从前往后依次去满足最小胃口的孩子
//        {
//            if (num < g.size() && s[i] >= g[num])
//            {
//                num++;
//            }
//        }
//        return num;
//    }
//};

    //int getValue(vector<int> gifts, int n) {
    //    int hash[1000] = { 0 };
    //    for (int i = 0; i < gifts.size(); i++)
    //    {
    //        hash[gifts[i]]++;
    //    }
    //    int ret = 0;
    //    int mid = gifts.size() / 2;
    //    for (int i = 0; i < gifts.size(); i++)
    //    {
    //        if (hash[gifts[i]] >= mid)
    //        {
    //            ret = gifts[i];
    //            return ret;
    //        }
    //    }
    //    return ret;
    //}


    //int main()
    //{
    //    vector<int> gifts;
    //    gifts.push_back(2);
    //    gifts.push_back(1);
    //    gifts.push_back(1);
    //    gifts.push_back(3);
    //    gifts.push_back(3);
    //    gifts.push_back(1);
    //    gifts.push_back(3);

    //    int ret = getValue(gifts, gifts.size());

    //    cout << ret << endl;

    //    return 0;
    //}
    