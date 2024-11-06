//
// Created by Kuba on 23/10/2024.
//

#include "BFS.h"

//Z wektora A chcemy usunac wsyztskie wspolne wartości dla wektora B
void BFS::usunWspolne(vector<pair<Node*,int>>& A, vector<Node*>& B) {
    unordered_set<int> values;
    for(const auto& p: B){
        values.insert(p->get_value());
    }
    A.erase(remove_if(A.begin(), A.end(),
                      [&values](const pair<Node*,int>& p) {
                          return p.first && values.count(p.first->get_value()) > 0;
                      }),
            A.end());
}

void BFS::bfs(Node start, int size) {
    vector<pair<vector<Node* >, int>> ways = {
            { { &start }, 0 }
    };
    for(int x = 0; x < size; x++){
        cout << x << endl;
        for(int x = 0; x < ways.size(); x++) {
            for (int y = 0; y < ways[x].first.size(); y++) {
                cout << ways[x].first[y]->get_value() << ' ';
            }
            cout << endl;
        }
        cout << endl;
        vector<pair<vector<Node*>, int>> newWays = vector<pair<vector<Node*>, int>>();
        for(pair<vector<Node*>, int>& p: ways){
            //temp -> lista wierzchołków do których można pójśc i chcemy z niego usunąc wszytskei wierzchołki już odwiedzone
            vector<pair<Node*,int>> temp = p.first[p.first.size()-1]->getVectorOfNodes();
            usunWspolne(temp,p.first);
            //dla każdego nowego mozlwiego wierzchołka tworzymy nową ścieżkę.
            //bierzemy kopię ścieżki p.first, dodajemy do niej nowy wierzchołek t.first
            for(pair<Node *, int> t: temp){
                vector<Node*> n = p.first;
                n.push_back(t.first);
                newWays.push_back(make_pair(n,p.second+t.second));
            }
        }
        ways = newWays;


    }
}