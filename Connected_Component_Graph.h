#ifndef __CCG_H_
#define __CCG_H_


#include <bits\stdc++.h>
using namespace std;

#define vi vector<int>

class Graph1 {
    private:
        int dinh, canh;
        vector<bool> visited;
        vi *adj;

        void dfs(int u) {
            visited[u] = true;
            for(int x: adj[u]) {
                if(!visited[x]) dfs(x);
            }
        }
    public:
        Graph1(int n): dinh(n), canh(0) {
            adj = new vi[n];
            for(int i=0; i<n; i++)
                visited.push_back(false);
        }
        
        void addEdge(int u, int v) {
            canh++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count () {
            int count = 0;
            for(int i=0; i<dinh; i++) {
                if(!visited[i]) {
                    dfs(i);
                    count++;
                }
            }
            return count;
        }
};

bool check5(string s1, string s2) {
    int count = 0;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) count++;
    }
    return count == 1;
}

void Display_CCGraph() {
    unordered_map<int, string> word;
    ifstream fin("gsb_words.txt");

    int n = 0;
    string s;
    while(!fin.eof()) {
        fin >> s;
        word[n] = s;
        n++;
    }

    Graph1 g(n);
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(check5(word[i], word[j]))
                g.addEdge(i,j);
        }
    }

    int res = g.count();
    cout << "So thanh phan lien thong cua do thi: " << res << endl;
}

#endif