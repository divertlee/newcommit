#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//135.分糖果
//n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
//你需要按照以下要求，给这些孩子分发糖果：
//每个孩子至少分配到 1 个糖果。
//相邻两个孩子评分更高的孩子会获得更多的糖果。
//请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
//要保证评分最高的孩子的糖果数比左右都要高：那么当判断右孩子比左孩子评分高时，右孩子依靠左孩子的糖果数：就要从左到右循环判断
// 再次判断左孩子比右孩子评分高的情况：那么就得从右往左遍历：左孩子的糖果数此时依赖于右孩子的糖果数如果左孩子的糖果数已经比右孩子的糖果数多时就不需要++了
//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        vector<int> candysint(ratings.size(), 1);
//        for (int i = 1; i < ratings.size(); i++)//从左往右确定右大于左的情况
//        {
//            if (ratings[i] > ratings[i - 1])
//            {
//                candysint[i] = candysint[i - 1] + 1;
//            }
//        }
//
//        for (int i = ratings.size() - 2; i >= 0; i--)//从右往左确定左比右大的情况
//        {
//            if (ratings[i] > ratings[i + 1])
//            {
//                candysint[i] = max(candysint[i], candysint[i + 1] + 1);//保证每个左右评分最高的孩子的糖果都比左右两边多
//            }
//        }
//        int ret = 0;
//        for (auto e : candysint)
//        {
//            ret += e;
//        }
//        return ret;
//    }
//};

//134.加油站
// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//给定两个整数数组 gas 和 cost ，如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1 。如果存在解，则 保证 它是 唯一 的。
// 把油的剩余量加起来（ans），当ans小于0时，那么选择这个当做起点肯定不能完成循环。
// 若能完成循环则在这个点的前半段油的剩余量<0，那么在这个点的后半段的油剩余量必定>0；那么为于后半段的第一个点这个点就是起点
// 若总量小于0必不能完成循环返回-1；能完成循环就返回油的剩余总量的正数那段的第一个点
// class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int start = 0;
//        int ans = 0;
//        int total = 0;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            ans += (gas[i] - cost[i]);
//            total += (gas[i] - cost[i]);
//            if (ans < 0)//油的剩余量小于0时，重新选起点
//            {
//                start = i + 1;
//                ans = 0;
//            }
//        }
//        if (total < 0) return -1;//油的剩余量总和小于0时，不能完成循环
//        return start;
//    }
//};
// 默认以0为起点：记录油剩余量的总量，当剩余总量小于0不能完成循环返回-1；当油的剩余总量>=0时就必然能完成循环返回起点；
// 取油的剩余总量的最小值形态min，从后往前补，当把这个min补到>=0时就能作为起点即从起点到0点的（后半段）能把0到这个起点（前半段）的负值填平
// class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int ans = 0;
//        int min = INT_MAX;
//        for (int i = 0; i < gas.size(); i++)
//        {
//            ans += (gas[i] - cost[i]);
//            if (ans < min)
//            {
//                min = ans;//记录累计量的最小值
//            }
//        }
//        if (ans < 0) return -1;//油的总和小于0-无法完成循环
//        if (min >= 0)
//        {
//            return 0;//如果每次油的剩余量的最小值都 >=0，那么从第0结点出发必定能完成循环
//        } //此时min为负数，那么从后到前哪个节点能最先把负数的ans填平那么那个节点就是起点
//        for (int i = gas.size() - 1; i >= 0; i--)
//        {
//            int tmp = gas[i] - cost[i];
//            min += tmp;
//            if (min >= 0)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};
// 
    //int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //    vector<int>ans;
    //    for (int i = 0; i < gas.size(); i++)
    //    {
    //        ans.push_back( gas[i] - cost[i]);
    //    }

    //    return ans[0];
    //}

    //int main()
    //{
    //    vector<int> gas;
    //    gas.push_back(1);
    //    gas.push_back(2);
    //    gas.push_back(3);
    //    gas.push_back(4);
    //    gas.push_back(5);
    //    vector<int> cost;
    //    cost.push_back(3);
    //    cost.push_back(4);
    //    cost.push_back(5);
    //    cost.push_back(1);
    //    cost.push_back(2);

    //    int ret = canCompleteCircuit(gas, cost);
    //    cout << ret << endl;
    //    return 0;
    //}

//1005.K 次取反后最大化的数组和
//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
//选择某个下标 i 并将 nums[i] 替换为 - nums[i] 。
//重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
//以这种方式修改数组后，返回数组 可能的最大和
//取单体最大--部分最大--总和最大：先按照绝对值由大到小排列：总和最大看绝对值最大，所以绝对值最大的负数优先被处理成正数；
// 然后只要是负数就取反，然后次数k--；最后给最小的数取剩余k次反即可
//class Solution {
//public:
//    static bool cmp(int a, int b)
//    {
//        return abs(a) > abs(b);
//    }
//    int largestSumAfterKNegations(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end(), cmp);// 按照绝对值由大到小排列
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (nums[i] < 0 && k != 0)
//            {
//                nums[i] *= -1;
//                k--;
//            }
//        }
//        if (k % 2 != 0) nums[nums.size() - 1] *= -1;
//        int ret = 0;
//        for (auto e : nums)
//        {
//            ret += e;
//        }
//        return ret;
//    }
//};

//45.跳跃游戏二
//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
//0 <= j <= nums[i]
//i + j < n
//返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
// 走到范围最后一节才判断，是否要继续走，所以要走到路程最后
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int curdistance = 0;
//        int nextdistance = 0;
//        int ans = 0;//步数
//        for (int i = 0; i < nums.size(); i++)
//        {
//            nextdistance = max(nextdistance, i + nums[i]);//更新下个最大跳跃范围
//            if (curdistance == i)//走到当前跳跃范围的最尾段
//            {
//                if (curdistance < nums.size() - 1)//当前范围走不到最后就需要更新且再走一步
//                {
//                    curdistance = nextdistance;//更新
//                    ans++;
//                    if (nextdistance >= nums.size() - 1)//下一个范围能到达
//                        break;
//                }//当前这一步能走到结尾，直接退出循环
//                else break;
//            }
//        }
//        return ans;
//    }
//};

////只需走到倒数第二个结点即可，因为题目说了必定能走到；若走到了，则加加ans；若没走到倒数第二个结点，则当前结点就能到
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int curdistance = 0;
//        int nextdistance = 0;
//        int ans = 0;
//        for (int i = 0; i < nums.size() - 1; i++)
//        {
//            nextdistance = max(nextdistance, i + nums[i]);//更新下一个范围
//            if (curdistance == i)
//            {
//                curdistance = nextdistance;
//                ans++;
//            }
//        }
//
//        return ans;
//    }
//
//};


//int main()
//{
//	string str = "abcde";
//	cout << str << endl;
//	reverse(str.begin(), str.end());
//	cout << str << endl;
//	return 0;
//}