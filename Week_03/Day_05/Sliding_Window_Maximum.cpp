//Using Brute Force ->  Time Complexity : O(n^2)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res;

        for (int i = 0; i <= n - k; i++) {
            int maxi = nums[i];
            for (int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }
            res.push_back(maxi);
        }
        return res;
    }
};

// Using Priority Queue -> Time Complexity : O(n log n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;

        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {

            pq.push({nums[i], i});

            while(!pq.empty() &&
                  pq.top().second <= i-k) {
                pq.pop();
            }

            if(i >= k-1) {
                res.push_back(pq.top().first);
            }
        }

        return res;
    }
};

// Using Deque -> Time Complexity : O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;

        vector<int> res;

        for(int i = 0; i < n; i++) {
            
            //Step 1
            while(!deq.empty() && deq.front() <= i-k) {
                deq.pop_front();
            }

            //Step 2
            while(!deq.empty() && nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }
            //Step 3
            deq.push_back(i);

            //Step 4
            if(i >= k-1) {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};
