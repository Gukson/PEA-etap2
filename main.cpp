#include <iostream>
#include "TSP/BaB/BFS/BFS.h"
#include "data/data_loader/DataLoader.h"
int main() {

    DataLoader dataLoader = DataLoader();
    vector<Node> nodes = dataLoader.loadData("5nodes.txt");

    BFS bfs = BFS();
    bfs.bfs(nodes[1], nodes.size());
    cout << "Optimum: " << dataLoader.optimum << endl;
    cout << "rezultat: " << bfs.result << endl;

    return 0;
}
