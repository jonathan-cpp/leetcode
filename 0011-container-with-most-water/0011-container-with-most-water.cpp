class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int water = 0;
        int best = 0;

        while(left < right) {
            water = std::min(height[left], height[right]) * (right - left);
            best = std::max(best, water);

            if (height[left] < height[right]) 
                left++;
            else                              
                right--;
        }
        
        return best;
    }
};