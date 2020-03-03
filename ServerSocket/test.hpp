//
// Created by david on 1/3/20.
//

#ifndef SERVERSOCKET_TEST_HPP
#define SERVERSOCKET_TEST_HPP

#include "Graph.hpp"
#include "Dijkstra.hpp"


int test(){
    Graph *graph = new Graph();
    graph->uploadGraph();
    Dijkstra *d = new Dijkstra();
    d->dijkstra(1, 10, *graph);
    cout << "Ended" << endl;
    return 0;
}

#endif //SERVERSOCKET_TEST_HPP
