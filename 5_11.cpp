//213. ��ҽ��� II
//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��

//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�

//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if (nums.size() == 1)return nums[0];
//        if (nums.size() == 2)return max(nums[0], nums[1]);
//
//        int ret1 = getmonymax(nums, 0, nums.size() - 2);
//        int ret2 = getmonymax(nums, 1, nums.size() - 1);
//        return max(ret1, ret2);
//    }
//    int getmonymax(vector<int>& nums, int start, int end)
//    {
//        vector<int>dp(nums.size(), 0);
//        dp[start] = nums[start];
//        dp[start + 1] = max(nums[start], nums[start + 1]);
//        for (size_t i = start + 2; i <= end; i++)
//        {
//            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//        }
//        return dp[end];
//    }
//};