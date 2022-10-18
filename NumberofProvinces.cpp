// Number of Provinces
// Graph

class Solution
{

public:
    void dfs(int src, vector<int> &vist, vector<int> adj[])
    {
        vist[src] = 1;

        for (auto x : adj[src])
        {
            if (vist[x] == 0)
            {
                dfs(x, vist, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isC)
    {
        int n = isC.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isC[i][j] == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vist(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (vist[i] == 0)
            {
                ans++;
                dfs(i, vist, adj);
            }
        }
        return ans;
    }
};