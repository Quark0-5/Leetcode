#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto BinarySearch = [&]()->int
        {
            int left = 0, right = nums.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target){
                    return mid;
                }
                else if (nums[mid] < target){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            return -1;
        };
        int index = BinarySearch();
        int FirstIndex, LastIndex;
        if(index == -1){
            FirstIndex = -1;
            LastIndex = -1;
        }else{
            FirstIndex = 0;
            LastIndex = nums.size() - 1;
            for(int i =index;i>0;i--){
                if(nums[i] != nums[i-1]){
                    FirstIndex = i;
                    break;
                }
            }
            for(int i = index; i < (nums.size()-1);i++){
                if(nums[i]!= nums[i+1]){
                    LastIndex = i;
                    break;
                }
            }
        }
        return {FirstIndex, LastIndex};
    }
};
int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> data(n);
    for(auto &x:data){
        cin >> x;
    }
    int target;
    cin >> target;
    vector<int> ans = s.searchRange(data, target);
    cout << ans[0] << " " << ans[1] << endl;
}