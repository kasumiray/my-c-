using System.Numerics;

class solution
{
include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int left = 0;
        long long sum = 0;
        int maxRobots = 0;
        deque<int> dq; // Stores indices of chargeTimes in decreasing order of value

        for (int right = 0; right < n; ++right) {
            sum += runningCosts[right];

            // Maintain decreasing order in the deque
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            // Shrink the window from the left if total cost exceeds budget
            while (!dq.empty() && chargeTimes[dq.front()] + (long long)(right - left + 1) * sum > budget) {
                if (dq.front() == left) {
                    dq.pop_front();
                }
                sum -= runningCosts[left];
                left++;
            }

            maxRobots = max(maxRobots, right - left + 1);
        }

        return maxRobots;
    }
};
   } 




}
 
