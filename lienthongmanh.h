#ifndef __LIENTHONGMANH_H__
#define __LIENTHONGMANH_H__


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int UNVISITED = -1;


class Digraph1 {
private:
    int dinh, canh;
    vi *adj;
    
    stack<int> st;
    vi ids;
    vi low;
    vector<bool> onStack;

    int sccCount = 0;
    int id = 0;

    void dfs(int u) {
        st.push(u);
        onStack[u] = true;
        ids[u] = low[u] = id++;

        for(int to: adj[u]) {
            if(ids[to] == UNVISITED) dfs(to);
            if(onStack[to]) low[u] = min(low[u], low[to]);
        }

        if(ids[u] == low[u]) {
            for(int node=st.top(); ; node = st.top()) {
                st.pop();
                onStack[node] = false;
                low[node] = ids[u];
                if(node == u) break;
            }
            sccCount++;
        }
    }
public: 
    Digraph1(int V): dinh(V), canh(0) {
        adj = new vi[dinh];
        for(int i=0; i<dinh; i++) {
            ids.push_back(UNVISITED);
            low.push_back(0);
            onStack.push_back(false);
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        canh++;
    }

    vi findSCC() {
        for(int i=0; i<dinh; i++) {
            if(ids[i] == UNVISITED)
                dfs(i);
        }
        cout << "So thanh phan lien thong manh: " << sccCount << endl;
        return low;
    }
};


void Display_LienThongManh() {
    int n, m;
    cout << "so dinh: "; cin >> n;
    cout << "so canh: "; cin >> m;

    Digraph1 dg(n);
    for(int i=0; i<n; i++) {
        int u, v;
        cout << "Nhap cac canh u & v:";
        cin >> u >> v;
        dg.addEdge(u,v);
    }

    // in ra so thanh phan lien thong manh
    dg.findSCC();

}


#endif