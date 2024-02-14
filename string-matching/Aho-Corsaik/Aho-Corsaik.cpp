#include <vector>
#include <iostream>
using namespace std;

#ifndef ALPHA_MAX
#define ALPHA_MAX
const int M = 26;
#endif

//compress all vertex locations in trees to numbers
//mask to cut down on pointers and also size

struct Vertex {
    int next[M];   //edges from "concat"
    int go[M];     // 
    int prev = -1; //previous
    int link = -1; //suffix link
    char chr;      //char of the vertex
    bool out = 0;  //word end here?
    Vertex(int p = -1, char c = '$') : prev(p), chr(c) {  //constructor sets default vallues for all vals
        fill(begin(next),end(next),-1);
        fill(begin(go),end(go),-1);
    }
};

//main storage
vector<Vertex> V(1);

//adds string using emplace, better than pushback for unwieldy structs
void AddString(const string& s) {
    int it = 0;
    for(const char& ch : s) {
        int c = ch-'a';
        if(V[it].next[c] == -1) {
            V[it].next[c] = V.size();
            V.emplace_back(it,ch);
        }
        it = V[it].next[c];
    }
    V[it].out = 1;
}

//forward decl
int Go(int vertex, char chr);

//link to get the suffix link
int Link(int vertex) {
    if(V[vertex].link == -1) {
        if(vertex == 0 || V[vertex].prev == 0) V[vertex] = 0;
        else V[vertex] = Go(Link(V[vertex].prev), V[vertex].chr);
    }
    return V[vertex].link;
}

//transition state, given a "concat" char, returns which vertex to go to
int Go(int vertex, char chr) {
    int c = chr-'a';
    if(V[vertex].go[c] == -1) {
        if(V[vertex].next[c] != -1) V[vertex].go[c] = V[vertex].next[c];
        else V[vertex].go[c] = Go(Link(vertex),chr);
    }
    return V[vertex].go[c];
}