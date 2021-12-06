#ifndef __DONUOC_H__
#define __DONUOC_H__

#include<iostream>
#include<tuple>
#include<map>
using namespace std;

typedef tuple<int, int, int> Dinh;

map<Dinh, bool> visited;

void print(Dinh &u, Dinh &v){
    int l10, l7, l4;
    tie(l10,l7,l4) = u;
    cout << "\"("<<l10<<","<<l7<<","<<l4<<")\"" << "->";
    tie(l10,l7,l4) = v;
    cout << "\"("<<l10<<","<<l7<<","<<l4<<")\";"<<endl;
}

void explore(Dinh &s) {
    visited[s] = true;

    int l10, l7, l4;
    tie(l10, l7, l4) = s;

    if (l7 == 2 or l4 == 2) exit(0);

    int do_max;
    if (l10 > 0) {
        if (l7 < 7) {
            do_max = min(l10, 7 - l7);
            Dinh v = make_tuple(l10 - do_max, l7 + do_max, l4);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
        if (l4 < 4) {
            do_max = min(l10, 4 - l4);
            Dinh v = make_tuple(l10 - do_max, l7, l4+do_max);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
    }
    if (l7 > 0) {
        if (l10 < 10) {
            do_max = min(10-l10, l7);
            Dinh v = make_tuple(l10 + do_max, l7 - do_max, l4);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
        if (l4 < 4) {
            do_max = min(l7, 4-l4);
            Dinh v = make_tuple(l10, l7-do_max, l4+do_max);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
    }
    if (l4 > 0) {
        if (l10 < 10) {
            do_max = min(10-l10, l4);
            Dinh v = make_tuple(l10 + do_max, l7, l4 - do_max);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
        if (l7 < 7) {
            do_max = min(7-l7, l4);
            Dinh v = make_tuple(l10, l7 + do_max, l4 - do_max);
            if (!visited[v]) {
                print(s, v);
                explore(v);
            }
        }
    }
}

void Display_Donuoc(){
    Dinh start = make_tuple(0,7,4);
    explore(start);
}

#endif

