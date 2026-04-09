#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end())
        {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while (!q.empty())
        {
            string currentGene = q.front().first;
            int curStep = q.front().second;
            q.pop();

            if (currentGene == endGene)
            {
                return curStep;
            }

            for (int i = 0; i < 8; i++)
            {
                char original = currentGene[i];

                for (auto ch : {'A', 'C', 'G', 'T'})
                {
                    currentGene[i] = ch;

                    if (bankSet.find(currentGene) != bankSet.end())
                    {
                        q.push({currentGene, curStep + 1});
                        bankSet.erase(currentGene);
                    }
                }

                currentGene[i] = original;
            }
        }

        return -1;
    }
};

int main()
{
    string startGene = "AACCGGTT", endGene = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    // string startGene = startGene = "AACCGGTT", endGene = "AAACGGTA";
    // vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};

    Solution solution;
    cout << solution.minMutation(startGene, endGene, bank);

    return 0;
}

// https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150