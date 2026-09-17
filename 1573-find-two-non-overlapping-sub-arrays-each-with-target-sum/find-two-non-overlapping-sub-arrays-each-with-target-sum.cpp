class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int result=INT_MAX;
        int minLen=INT_MAX;
        int currSum=0;
        int i=0;
        int j=0;
        vector<int>minLenIdx(n,INT_MAX);
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i];
                i++;
            }
            if(currSum==target){
                int len = j-i+1;
                if(i>0 && minLenIdx[i-1]!=INT_MAX){
                    result=min(result,len+minLenIdx[i-1]);
                }
                minLen=min(minLen,len);
            }
            minLenIdx[j]=minLen;
            j++;
        }
        return result== INT_MAX ? -1 : result;
    }
};