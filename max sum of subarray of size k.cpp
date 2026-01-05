#include <climits>
#include <algorithm>
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        
        
         int n = arr.size(), res = 0;
        for(int i = 0, j = 0; i < n; i++) {
            j += arr[i];
            if(i - k >= 0) j -= arr[i - k];
            res = max(res, j);
            
            if(j<0){
                 j=0;
            }
        }
        return res;
    } 
     

    Time compl: o(n)