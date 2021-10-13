#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<list>
#include<iterator>
#include <queue>
#include <set>


// #include "Minheap.h"
#include <map>

using namespace std;

string makeUpper(string in){
    for (int i = 0; i < in.length(); i++){
        in[i] = toupper(in[i]);
        return in;
    }
}

int main(int argc, char *argv[])
{


    string start = argv[1];
    string end = argv[2];
    string fileName = argv[3];

    
    //std::transform(data.begin(), data.end(), data.begin(), asciitolower);

int numWords;
ifstream infile(fileName.c_str());

if (!infile)
{
    cout << "Cannot open " << fileName << "!" << endl;
    return 1;
}

// Minheap heap = new Minheap(numWords);

infile >> numWords;

map<string, vector<string> >adj_list;
vector<string> vec;
string uppercase;

for (int i = 0; i < numWords; i++){
    infile >> uppercase;
    uppercase = makeUpper(uppercase);
    vec.push_back(uppercase);
    cout << vec[i] << endl;
}



set <std::string> set1;

for (int i = 0; i < numWords; i++){
    string temp;
    temp = vec[i];
    for (int j = 0; j < temp.length(); j++){
        int val = int(temp[i] + 1);
        for(int k = 0; k < 26){
            temp[k] = 'A' + j;
            set1.insert(temp);
        }
    }

}

for (int i = 0; i < numWords; i++){
    
}





}

int d[n]; //distances from the start node u
int p[n]; //predecessors
int c[n][n]; //edge costs
void aStarSearch (int u) {
Minheap heap;
//How should we implement this?
d[u] = 0;
pq.add(u, d[u]);
while(!pq.isEmpty()) {
int v = pq.peek();
pq.remove();
for all nodes outgoing edges (v,w) from v {
if (w hasn’t been visited || d[v] + c[v][w] < d[w]) {
d[w] = d[v] + c[v][w];
p[w] = v;
if (this is w’s first visit) {
pq.add(w, d[w]);
}
else pq.update(w, d[w]);
}
}
}
}
Que


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

