class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
            vector<string> ranks = {"",
                                "Gold Medal", "Silver Medal", "Bronze Medal"};

        vector<int> maxidx;

        for (int i = 0; i < score.size(); i++)
            maxidx.push_back(i);

        auto cmp = [&score](int l, int r)
        { return score[l] > score[r]; };

        sort(maxidx.begin(), maxidx.end(), cmp);

        vector<string> res(score.size());

        int r = 1;
        for (int idx : maxidx)
        {
            if (r < ranks.size())
                res[idx] = ranks[r];

            else
                res[idx] = to_string(r);

            r++;
        }

        return res;
    }
};