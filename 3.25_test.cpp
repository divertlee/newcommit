#include<iostream>
#include<vector>

using namespace std;
//135.�ַ��ǹ�
// ��֤�ϴ����ֵ��Ǹ�����Χ�ֵ����ǹ�������ȴ�ǰ�������һ�飬�ұ߱���ߴ�ʱ���ұ��ǹ���Ϊ����ǹ���+1��
// �ٴ����������һ�飬��������ֱ��ұ߸�ʱ������ǹ���Ϊ��ʱ�ǹ������ұ��ǹ���+1�����ֵ
// class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        int ret = 0;
//        //�ȴ�ǰ�����������ı�С�Ķ�1
//        vector<int> candyses(ratings.size(), 1);
//        for (int i = 1; i < ratings.size(); i++)
//        {
//            if (ratings[i] > ratings[i - 1])
//            {
//                candyses[i] = candyses[i - 1] + 1;
//            }
//        }
//        //�ٴӺ���ǰ����������ô�ʱ���ǹ�������С��+1�Ƚ�ȡ���
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
//134.����վ
//һ����������С��0������ѭ������-1����ÿ�εĲ�ֵ����Сֵ)������0�������ꣻ����ʹӺ���ǰ���������ܰ�ǰ�渺�Ĳ�����꼴���
//������0��ʼ����������������С��0ʱ��ǰһ��վΪstart������Ϊ0������������ֵ��start��Ϊ��㣻ǰ����total����Ϊ��������ѭ�������������򷵻�-1
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
//1005.k��ȡ������󻯵������
// ������ֵ�Ӵ�С����Ȼ��Ӵ�Сȡ��������Ȩ��ʣ��k��������Сֵ��
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
//45.��Ծ��Ϸ��
//��Ȼ��������󣬷�����С���������ڴ˽׶β��ܵ���ڴ˽׶�ȡ��󸲸Ƿ�Χ��������˽׶�ʱ����++�Ҹ��¸��Ƿ�Χ
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

//55.��Ծ��Ϸ
// ȡ���·�����Ƿ�Χ
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


//122.������Ʊ�����ʱ����
// ֻҪ�е�׬����1��2��3�� 3-1=��2-1��+��3-2��
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

//53.����������
// ��valueС��0ʱ�Ʊػ����ͺ��������飬��ôҪ����value��ֻ��Ҫvalue��maxvalue����ܸ���maxvalue��
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

//376.�ڶ�����
// ��prev��¼ǰһ�ԵĲ�ֵ��cur��¼��ǰ�ԵĲ�ֵ���ﵽ�ڶ�ret�ͼӼӣ����ﵽ�ڶ���ʱ��prev�Ÿ��£��൱���м��в��ڶ�������ֱ����������Ϊһ��Ԫ�ػ�������Ԫ��Ҳ���ǰڶ�������retĬ��ֵ��1
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

//455.�ַ�����
// 
// �Ӵ�С��������
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
//        for (int i = 0; i < s.size(); i++)//�������ɣ���ǰ��������ȥ������Сθ�ڵĺ���
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
    