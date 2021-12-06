#ifndef GRAPH_H
#define GRAPH_H

#include<istream>
#include<vector>

using namespace  std;

#define vi vector<int>

class Graph {
private:
    int soDinh;
    int soCanh;
    vector<int> *danhsachke;
public:
    Graph(int V) {
        soDinh = V;
        soCanh = 0;
        danhsachke = new vi[soDinh];
    }

    Graph(istream &in) {
        int v, w;
        in >> soDinh;
        in >> soCanh;
        for (int i = 0; i < soCanh; i++) {
            in >> v >> w;
            danhsachke[v].push_back(w);
            danhsachke[w].push_back(v);
        }
    }

    void addEdge(int v, int w) {
        soCanh++;
        danhsachke[v].push_back(w);
        danhsachke[w].push_back(v);
    }

    vector<int> getAdj(int v) {
        return danhsachke[v];
    }

    int getV() { return soDinh; }

    int getE() { return soCanh; }
};

#endif