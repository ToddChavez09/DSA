#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        int N = edges.size();
        for (int j = 0; j < V - 1; j++)
        {
            for (int i = 0; i < N; i++)
            {
                int wt = edges[i][2];
                int source = edges[i][0];
                int dest = edges[i][1];
                if (dist[source] != 1e8 && dist[source] + wt < dist[dest])
                {
                    dist[dest] = dist[source] + wt;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {

            int wt = edges[i][2];
            int source = edges[i][0];
            int dest = edges[i][1];
            if (dist[source] + wt < dist[dest])
            {
                return {-1};
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
