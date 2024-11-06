#include <iostream>
#include "TSP/BaB/BFS/BFS.h"
#include "data/data_loader/DataLoader.h"
int main() {

    DataLoader dataLoader = DataLoader();
    vector<Node> nodes = dataLoader.loadData("4nodes.txt");

    BFS bfs = BFS();
    bfs.bfs(nodes[1],nodes.size());
    return 0;
}
