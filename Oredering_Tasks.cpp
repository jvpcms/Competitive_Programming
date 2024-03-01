// by jvpcms

#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int in[N];
queue<int> q;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m)
    {
        if (!m and !n) break;

        vector<int> tsort;
        memset(in, 0, N);
        vector<int> adj[N];

        while (m--)
        {
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            in[b]++;
        }

        for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            tsort.push_back(u);

            for (int v : adj[u])
            {
                in[v]--;
                if (in[v] == 0) q.push(v);
            }
        }

        for (auto i : tsort) cout << i << ' ';
        cout << '\n';
    }
    
    return 0;
}
