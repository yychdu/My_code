   
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> res;
    vector<int> a;
    int _size = nums.size();
    sort(nums.begin(), nums.end());
    for (int k = 0; k < _size - 2; ++k)
    {
        if (nums[k] > 0)
            break;
        if (k > 0 && nums[k] == nums[k - 1])
            continue;
        int i = k + 1, j = _size - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                while (i < j && nums[i] == nums[++i])
                    ;
            }
            else if (sum > 0)
            {
                while (i < j && nums[j] == nums[--j])
                    ;
            }
            else
            {
                res.push_back({nums[k], nums[i], nums[j]});
                while (i < j && nums[i] == nums[++i])
                    ;
                while (i < j && nums[j] == nums[--j])
                    ;
            }
            
        }
    }

    return res;
}

int main()
{
    vector<int> a(4, 0);
    threeSum(a);
}