class Solution {
public:
    int trap(vector<int>& height) {
        // Aprroach 1: Takes TC as O(n) and SC as O(n)



        // // creating left and right max array:
        // vector<int> left (height.size(), 0);
        // vector<int> right (height.size(), 0);

        // // left array:
        // int max = 0;
        // for(int i=0; i<height.size(); i++)
        // {
        //     if(height[i] > max)
        //     {
        //         max = height[i];
        //     }

        //     left[i] = max;
        // }

        // // right array:
        // max = 0;
        // for(int i=height.size()-1; i>=0; i--)
        // {
        //     if(height[i] > max)
        //     {
        //         max = height[i];
        //     }
            
        //     right[i] = max;
        // }

        // // finding water a particular index can hold by the formula: min(maxLeftHeight, maxRightHeight) - its own area(1 * height) -> 1 is width
        // int ans = 0;
        // for(int i=0; i<height.size(); i++)
        // {
        //     ans += min(left[i], right[i]) - height[i] * 1;
        // }

        // return ans;



        // Approach 2: Takes TC as O(n) and SC as O(1)
        // Using two pointers to find water an index can store:
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while(left <= right)
        {
            // if left building is smaller
            if(height[left] <= height[right])
            {
                // check if left building is greater than previous greatest left building: if so update leftmax building and this case will not give any trapped water:
                if(height[left] >= leftMax)
                {
                    leftMax = height[left];
                }

                // if current left builing is smaller than previous greatest left building, store ans:
                else
                {
                    ans += leftMax * 1 - height[left] * 1;
                }
                

                // update left
                left++;
            }

            // if right building is smaller
            else
            {
                // check if current right building is greater than previous greatest right building: if so update rightmax building and this case will not give any trapped water:
                if(height[right] >= rightMax)
                {
                    rightMax = height[right];
                }

                // if current left builing is smaller than previous greatest left building, store ans:
                else
                {
                    ans += rightMax * 1 - height[right] * 1;
                }

                right--;
            }
        }

        return ans;
    }
};