#ifndef __SCCDIGRAPH_H__
#define __SCCDIGRAPH_H__

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int UNVISITED2 = -1;

unordered_map<int, string> words;

class Digraph2 {
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
            if(ids[to] == UNVISITED2) dfs(to);
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
    Digraph2(int V): dinh(V), canh(0) {
        adj = new vi[dinh];
        for(int i=0; i<dinh; i++) {
            ids.push_back(UNVISITED2);
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
            if(ids[i] == UNVISITED2)
                dfs(i);
        }
        cout << "So thanh phan lien thong manh: " << sccCount << endl;
        return low;
    }
};


int dem(char c, string s) {
    int count = 0;
    for(char x: s) {
        if(x == c) count ++;
    }
    return count;
}

bool check1(string s1, string s2) {
    s1.erase(s1.begin());
    for(char x: s1) {
        if(dem(x,s1) > dem(x,s2)) return false;
    }
    return true;
}



void Display_SCC_Digraph() {
    ifstream fin("gsb_words.txt");
    string s;
    int n = 0;
    while(!fin.eof()) {
        fin >> s;
        words[n] = s;
        n++;
    }

    Digraph2 dg(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if(check1(words[i], words[j]))
                    dg.addEdge(i,j);
            }
        }
    }

    // in ra so thanh phan lien thong manh
    vi low = dg.findSCC();
    
    // in ra cac tu cung thanh phan lien thong manh voi tu duoc nhap vao
    string str;
    cout << "Nhap tu can tim: "; cin >> str;
    int index;
    for(int i=0; i<n; i++) {
        if(words[i] == str) {
            index = i;
            break;
        }
    }
    cout << "Cac tu cung thanh phan lien thong voi " << str << ":\n";
    for(int i=0; i<n; i++) {
        if(low[i] == low[index]) {
            cout << words[i] << " ";
        }
    }
}

#endif
