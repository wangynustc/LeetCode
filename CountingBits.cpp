/****************************************************************************
* This is a linear solution to https://leetcode.com/problems/counting-bits/
* The O(n*sizeof(integer)) is easy and is bypassed.
* For the similar questions(wanna o(n) solutin), we can consider record 
* preceding information for later usage.
****************************************************************************/
class Solution {
public:
    vector<int> countBits(int num) {
        assert(num >= 0);
        vector<int> *results = new vector<int>;
        results->push_back(0);
        int last_result = 0;
        for (int i = 1; i <= num; i = i * 2)
        {
            for (int j = i; j <= num && j < i * 2; ++j)
            {
                if (j - i < i / 2) {
                    results->push_back((*results)[i / 2 + j - i]);
                } else {
                    results->push_back((*results)[i / 2 + j - i] + 1);
                }
            }
        }
        
        return *results;
    }
};
