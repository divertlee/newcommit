//#include<iostream>
//#include<string>
//using namespace std;
// 
// 1049.最后一块石头的重量二
// 
////有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
//每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
// 
// 两块石头相撞，怎么样让一堆石头相撞后遗留下来的石头最小？尽可能的把石头分成重量相似的两堆，然后让这两堆相撞，要么没有石头遗留下来，要么剩余最小的石头
// 
// 每个石头只能选择一次，01背包；背包容积为石头重量的一半，每次最大可能的把石头装进去，若刚好有一次装满即石头堆里出现了堆为总石头重量的一半，那么这次相撞石头必不剩余
// i为石头的编号 j为背包的容积；dp[j]为容积为j的背包
// 根据数据可以把背包初始化为最大石头总重量的一半，然后把每个区间的dp值初始化为0
// for循环遍历i，即从0-i依次选择编号为i的石头放进背包里
// for从容积为石头总重量的一半开始遍历到0可以要求每块石头选择一次放进背包里
// 背包容积刚好是放进石头重量的一半时即相撞后石头为0
// target=sum/2是向下取整，所以sum>=2*target
// 
// class Solution {
//public:
//    //尽可能的把石头分成重量相同的两堆，这样相撞后遗留下来的小石头重量才算是最小
//    int lastStoneWeightII(vector<int>& stones) {
//        int sum = 0;
//        for (auto e : stones)
//        {
//            sum += e;
//        }
//        int target = sum / 2;//sum/2小于等于sum的一半即sum-target>=target
//        vector<int>dp(1501, 0);
//        for (int i = 0; i < stones.size(); i++)//遍历石头
//        {
//            for (int j = target; j >= stones[i]; j--)
//            {
//                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
//            }
//        }
//        return sum - dp[target] - dp[target];
//    }
//};
// 416.分割等和子集
// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//怎么转化为01背包呢？首先nums里的元素每个只能取一次，能分割成两个子集的话，即俩个子集都是等于nums总数的一半； 
// 所以先计算nums子集总和的一半，若不能分割成两半明显的不行
// nums子集的一半target，往dp背包里面装米；首先背包的总容量为target，当背包刚好装进重量为target的物品时就返回true
// 依次遍历物品，背包的容积从最大即为target的一半开始可以装物品，这样保持每次装的时候物品只取一次
// dp[target]==target时就返回true，不然就为false
// class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        vector<int>dp(10001, 0);
//        int sum = 0;
//        for (auto e : nums)
//        {
//            sum += e;
//        }
//        if (sum % 2 == 1) return false;
//        int target = sum / 2;
//        for (int i = 0; i < nums.size(); i++)//遍历物品
//        {
//            for (int j = target; j >= nums[i]; j--)//从后往前遍历重量
//            {
//                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//
//            }
//        }
//        if (dp[target] == target)
//        {
//            return true;
//        }
//        return false;
//    }
//};
    //int Add(int num1, int num2) {
    //    string lo = to_string(num1);
    //    string sh = to_string(num2);
    //    int flag = 0;
    //    if (lo[0] == '1' && sh[0] != '1') { //num1为负数
    //        if (abs(num1) < num2) { //正数数比负数大，sum为正数
    //            flag = 1; //记录正数
    //        }
    //        else if (num1 == num2) {
    //            return 0;
    //        }
    //    }
    //    else if (lo[0] != '1' && sh[0] == '1') { //num2为负数
    //        if (abs(num2) < num1) { //正数比负数大，sum为正数
    //            flag = 1; //记录正数
    //        }
    //        else if (num1 == num2) {
    //            return 0;
    //        }
    //    }
    //    if (lo.size() < sh.size()) {
    //        string tmp = lo;
    //        lo = sh;
    //        sh = tmp;
    //    }
    //    string sum(32,'0');
    //    for (int i = 31; i >= 0; i--)
    //    {
    //        if(lo[i]=='1'&&sh[i]=='1'&&sum[i]=='1')
    //        {
    //           
    //        }
    //   }

    //}
    //int main()
    //{
    //    int num1 = 5;
    //    int num2 = 7;
    //    int ret = Add(num1, num2);
    //    cout << ret << endl;
    //    return 0;
    //}




//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int N = 0;//物品数量
//    int V = 0;//背包容积
//    cin >> N >> V;
//    vector<int> ve(N, 0);//物品体积
//    vector<int>we(N, 0);//物品价值
//    for (int i = 0; i < N; i++)
//    {
//        cin >> ve[i] >> we[i];
//    }
//    vector<int>dp(V + 1, 0);
//    for (int i = 0; i < N; i++)//从前往后遍历物品
//    {
//        for (int j = V; j >= ve[i]; j--)//从后往前遍历体积
//        {
//            dp[j] = max(dp[j], dp[j - ve[i]] + we[i]);
//        }
//    }
//    cout << dp[dp.size() - 1] << endl;
//    return 0;
//}