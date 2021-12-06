#ifndef __PATHPLANNING_H__
#define __PATHPLANNING_H__

#include<bits\stdc++.h>
using namespace std;

#define pa pair<int, int>
#define vp vector<pair<int,int>>
#define maxn 100
#define maxf INT_MAX

vector<bool> check2(maxn);
vector<int> f(maxn);
vector<int> parent1(maxn, -1);
vector<int> parent2(maxn, -1);

class Graph3 {
    private:
        int dinh, canh;
        vp *adj;
    public:
        Graph3(int V): dinh(V) {
            adj = new vp[dinh];
            for(int i=0; i<dinh; i++) {
                for(int j=0; j<dinh; j++)
                    adj[i].push_back(make_pair(j,-1));
            }
        }
        void addEdge(int u, int v, int w) {
            adj[u][v].second = w;
            adj[v][u].second = w;
        }

        void bfs(int u1, int u2, int c, int d, int r) {
            queue<int> q1, q2;
            q1.push(u1);
            q2.push(u2);

            while(!q1.empty() && !q2.empty()) {
                int v1 = q1.front(); q1.pop();
                int v2 = q2.front(); q2.pop();

                for(pa k: adj[v1]) {
                    int x = k.first;
                    if(Dijkstra(x, q2.front()) > r) {
                        q1.push(x);
                        parent1[x] = v1;
                    }
                }

                for(pa k: adj[v2]) {
                    int x = k.first;
                    if(Dijkstra(x, q1.front()) > r) {
                        q1.push(x);
                        parent2[x] = v2;
                    }
                }
                if(v1==c && v2 == d) break;
            }
        }

        

        int Dijkstra(int s, int e) {
            for(int i=0; i<dinh; i++) {
                f[i] = maxf;
                check2[i] = true;
            }
            f[s] = 0;
            int v = s, fmin;
            while(v!=e) {
                fmin = maxf;
                for(int i=0; i<dinh; i++) {
                    if(check2[i] && fmin>f[i]) {
                        fmin = f[i];
                        v = i;
                    }
                }
                if(fmin == maxf) break;

                check2[v] = false;
                
                for(int i=0; i<dinh; i++) {
                    if(adj[v][i].second>0 && f[i] > f[v] + adj[v][i].second)
                        f[i] = f[v] + adj[v][i].second;
                }
            }
            return f[e];
        }

        void Path_Planning(int a, int b, int c, int d, int r) {
            bfs(a,b,c,d,r);
            vector<int> path1, path2;
            while(c != a) {
                path1.push_back(c);
                c = parent1[c];
            }
            path1.push_back(a);
            reverse(path1.begin(), path1.end());
            for(int k: path1) cout << k << " ";
            cout << endl;

            while(d != b) {
                path1.push_back(d);
                d = parent2[d];
            }
            path1.push_back(b);
            reverse(path1.begin(), path2.end());
            for(int k: path2) cout << k << " ";
        }
};

void Display_PathPlanning() {
    int n,m,a,b,c,d,r;
    cin >> n >> m;
    Graph3 g(n);
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u,v,w);
    }
    cin >> a >> b >> c >> d >> r;
    g.Path_Planning(a,b,c,d,r);
}

#endif