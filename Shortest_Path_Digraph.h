#ifndef __SPD_H__
#define __SPD_H__


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

unordered_map<int, string> word1;

class Digraph3 {
private:
    int dinh, canh;
    vi *adj;
    
    vector<bool> visited;
    vi parent;

    void bfs(int u) {
            queue<int> q;
            q.push(u);
            visited[u] = true;

            while(!q.empty()) {
                int v = q.front(); q.pop();
                for(int x: adj[v]) {
                    if(!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                        parent[x] = v;
                    }
                }
            }
        }
public: 
    Digraph3(int V): dinh(V), canh(0) {
        adj = new vi[dinh];
        for(int i=0; i<dinh; i++) {
            visited.push_back(false);
            parent.push_back(-1);
        }
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        canh++;
    }

    void printPath(int a, int b) {
            bfs(a);
            cout << " a" << endl;
            if(!visited[b]) cout << "khong tim thay duong di\n";
            else {
                vi path;
                while(b != a) {
                    path.push_back(b);
                    b = parent[b];
                }
                path.push_back(a);
                reverse(path.begin(), path.end());
                for(int k: path) {
                    if(k != path[path.size()-1])
                        cout << word1[k] << " -> ";
                    else cout << word1[k] << endl;
                }
            }
        }
};


int dem1(char c, string s) {
    int count = 0;
    for(char x: s) {
        if(x == c) count ++;
    }
    return count;
}

bool check4(string s1, string s2) {
    s1.erase(s1.begin());
    for(char x: s1) {
        if(dem(x,s1) > dem(x,s2)) return false;
    }
    return true;
}



void Display_SP_Digraph() {
    ifstream fin("gsb_words.txt");
    string s;
    int n = 0;
    while(!fin.eof()) {
        fin >> s;
        word1[n] = s;
        n++;
    }

    Digraph3 dg(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i!=j) {
                if(check4(word1[i], word1[j]))
                    dg.addEdge(i,j);
            }
        }
    }


    string s1, s2;
    cout << "Tu dau: "; cin >> s1;
    cout << "Tu cuoi: "; cin >> s2;

    int x, y;
    for(int i=0; i<n; i++) {
        if(word1[i] == s1) x = i;
        if(word1[i] == s2) y = i;
    }


    dg.printPath(x, y);

    
}

#endif
