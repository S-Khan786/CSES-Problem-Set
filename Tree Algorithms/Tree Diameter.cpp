#include<bits/stdc++.h>
using namespace std;

void bournVita() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif  
}

void dfs(int curr, vector<vector<int>>& edges, int parent, vector<int>& dist) {
    if(parent != -1) {
        dist[curr] = dist[parent] + 1;
    }
    else {
        dist[curr] = 0;
    }

    for(auto& ngr : edges[curr]) {
        if(ngr != parent) {
            dfs(ngr, edges, curr, dist);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > edges(n, vector<int>());
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; //Make 0-Based Indexing
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> distX(n, 0);
    dfs(0, edges, -1, distX);

    int y = 0;
    for(int i=0; i<n; i++) {
        if(distX[i] > distX[y]) {
            y = i;
        }
    }

    vector<int> distY(n, 0);
    dfs(y, edges, -1, distY);

    int z = 0;
    for(int i=0; i<n; i++) {
        if(distY[i] > distY[z]) {
            z = i;
        }
    }

    cout << distY[z] << endl;
}

int main() {
    bournVita();

    solve();
}
