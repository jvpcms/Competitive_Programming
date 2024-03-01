// by jvpcms

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
bool vis[N];
int layer[N];
vector<int> adj [N];

int bfs(int o)
{
    memset(vis, 0, N);

    queue<int> q;
    q.emplace(o);

    int edge = o;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (!vis[u])
        {
            vis[u] = 1;
            for (auto i : adj[u]) if (!vis[i])
            {
                q.emplace(i);
                edge = i;
            }
        }
    }

    return edge;
}

void dfs(int o)
{

    vis[o] = 1;
    for (auto i : adj[o]) if (!vis[i])
    {
        layer[i] = layer[o] + 1;
        dfs(i);
    }

    return;

}

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    int e1 = bfs(1);
    int e2 = bfs(e1);

    memset(vis, 0, N);
    memset(layer, 0, N);

    dfs(e1);

    cout << layer[e2];

    return 0;
}
