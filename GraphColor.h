#ifndef __GRAPHCOLOR_H__
#define __GRAPHCOLOR_H__

#include<bits/stdc++.h>
 
using namespace std;
 
int n,e,i,j;
vector<vector<int> > graph;
vector<int> color;
bool vis[10001100];
 
void greedyColoring()
{
    color[0]  = 0;
    for (i=1;i<n;i++)
        color[i] = -1;
 
    bool unused[n];
 
    for (i=0;i<n;i++)
        unused[i]=0;
 
 
    for (i = 1; i < n; i++)
    {
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = true;
        int cr;
        for (cr=0;cr<n;cr++)
            if (unused[cr] == false)
                break;
 
        color[i] = cr; 
 
        for (j=0;j<graph[i].size();j++)
            if (color[graph[i][j]] != -1)
                unused[color[graph[i][j]]] = false;
    }
}
 
void Display_Tomau()
{
    fstream f;
    f.open("dothi.txt");
    int x,y;
    f>>n>>e;
    cout<<"\n";
    graph.resize(n);
    color.resize(n);
    memset(vis,0,sizeof(vis));
    for(i=0;i<e;i++)
    {
        f>>x>>y;
        // x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    string color_list[] = {"red", "green", "blue", "yellow","white","brow","chartreuse", "chocolate1",
                        "coral1","cornflowerblue","cornsilk","coral3","	darkblue","darkgreen","aqua",
                        "azure2","gold3","gold2","gold4","ghostwhite","gold","goldenrod1"};

    ofstream fo;
    fo.open("dothitomau.dot");
    fo << "graph tree {\n";

    greedyColoring();
    for(i=0;i<n;i++)
    {
        fo << i << " [fillcolor=" << color_list[color[i]] << ", style=filled];" << endl;
    }
    f.seekg(0);
    
    f>> x >> y;
    
    for(int i=0; i<e; i++) {
        f>> x >> y;
        fo << x << "--" << y << endl;
    }
    fo << "}";
    f.close();
    fo.close();
    
    // Biên dịch file dothitomau.dot với chương trình Grapviz
    // ta sẽ dc fide PDF tô màu đồ thị
}

#endif