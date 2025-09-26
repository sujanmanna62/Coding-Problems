class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
      map<long long, int> PrefixSum;
      long long sum = 0;
      int MaxLen = 0;
      for (int i = 0; i < arr.size(); i++)
      {
        sum = sum + arr[i];
        if (sum == k)
        {
          MaxLen = max(MaxLen, i + 1);
        }
        int rem = sum - k;
        if (PrefixSum.find(rem) != PrefixSum.end())
        {
          int len = i - PrefixSum[rem];
          MaxLen = max(MaxLen, len);
        }
        if (PrefixSum.find(sum) == PrefixSum.end())
        {
          PrefixSum[sum] = i;
        }
      }
      return MaxLen;
            
    }
};