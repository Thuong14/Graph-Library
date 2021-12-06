#ifndef __PRUFERCODE_H__
#define __PRUFERCODE_H__

#include <iostream>
#include <set>
#include "Graph.h"

using namespace std;

vi prufer_code(vector<vi> adj) {
    int n = adj.size();
    vi degree(n);
    set<int> leafs;
    vector<bool> killed(n,false);
    for(int i=1; i<n; i++){
        degree[i] = adj[i].size();
        if(degree[i] == 1)
            leafs.insert(i);
    }

    vi code;
    for(int i=0; i<n-2; i++) {
        int leaf = *leafs.begin();
        leafs.erase(leafs.begin());
        killed[leaf] = true;

        int v;
        for(int u: adj[leaf]) {
            if(!killed[u])
                v = u;
        }
        code.push_back(v);

        if(--degree[v]==1) leafs.insert(v);
    }
    return code;
}

void Display_Purfercode() {
    cout << "Nhap du lieu:\n";
    int e; cin >> e;
    Graph g(e+1);
    int u, v;
    for(int i=0; i<e; i++) {
        cin >> u >> v;
        g.addEdge(u,v);
    }

    vector<vi> adj;
    for(int i=0; i<e+1; i++) {
        adj.push_back(g.getAdj(i));
    }

    vi code = prufer_code(adj);

    for(int x: code)
        cout << x << " ";
    cout << endl;
}

#endif