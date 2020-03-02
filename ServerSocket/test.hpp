//
// Created by david on 1/3/20.
//

#ifndef SERVERSOCKET_TEST_HPP
#define SERVERSOCKET_TEST_HPP

#include "Graph.hpp"


int test(){
    Graph *graph = new Graph();
    graph->uploadGraph();
    cout << "Ended" << endl;
    return 0;
}

#endif //SERVERSOCKET_TEST_HPP
