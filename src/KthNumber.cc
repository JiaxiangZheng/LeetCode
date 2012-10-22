/* 
 * Author : jiaxiang.zheng135@gmail.com
 * Date   : 2012/10/16
 */
#include <queue>
#include <vector>
#include <iostream>
using std::priority_queue;
class Solution
{
public:
    virtual int solve(const std::vector<int>& arr, int K) = 0;
};
class Solution1 : public Solution
{
public:
   int solve(const std::vector<int>& arr, int K)
   {
       priority_queue<int, std::vector<int>, std::greater<int>> pQ;
       for (int i=0; i<arr.size(); ++i)
       {
            if (i<K) pQ.push_back(arr[i]);
            else {
                if (pQ.top() < arr[i]) continue;
                pQ.pop();
                pQ.push(arr[i]);
            }
       }
       return pQ.top();
   }
};
class Solution2 : public Solution
{
public:
    /* To be edit using quick-sort partition algorithm
     * Average time can be achieved to O(n)
     */
    int solve(const std::vector<int>& arr, int K)
    {
    }
};
