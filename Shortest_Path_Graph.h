#ifndef __SPG_H__
#define __SPG_H__

#include <bits\stdc++.h>
using namespace std;

#define vi vector<int>

unordered_map<int, string> word;

class Graph2 {
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
        Graph2(int n): dinh(n), canh(0) {
            adj = new vi[n];
            for(int i=0; i<n; i++)
            {
                visited.push_back(false);
                parent.push_back(-1);
            }
        }
        
        void addEdge(int u, int v) {
            canh++;
            adj[u].push_back(v);
            adj[v].push_back(u);
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
                        cout << word[k] << " -> ";
                    else cout << word[k] << endl;
                }
            }
        }    
};

bool check3(string s1, string s2) {
    int count = 0;
    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i]) count++;
    }
    return count == 1;
}

void Display_SPG() {
    ifstream fin("gsb_words.txt");

    int n = 0;
    string s;
    while(!fin.eof()) {
        fin >> s;
        word[n] = s;
        n++;
    }

    Graph2 g(n);
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(check3(word[i], word[j]))
                g.addEdge(i,j);
        }
    }

    string s1, s2;
    cout << "Tu dau: "; cin >> s1;
    cout << "Tu cuoi: "; cin >> s2;

    int x, y;
    for(int i=0; i<n; i++) {
        if(word[i] == s1) x = i;
        if(word[i] == s2) y = i;
    }

    g.printPath(x,y);

}

#endif