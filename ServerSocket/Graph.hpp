//
// Created by david on 29/2/20.
//

#ifndef SERVERSOCKET_GRAPH_HPP
#define SERVERSOCKET_GRAPH_HPP

#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "string"
#include <bits/stdc++.h>
#include "Matrix.h"

using namespace std;

class GraphNode {
public:
    vector<vector<int>> connections;
    int identifier;

    GraphNode(int num){
        identifier = num;
    }

    void connect(int id, int weight) {
        vector<int> temp;
        temp.push_back(id);
        temp.push_back(weight);
        connections.push_back(temp);
    }
};

class Graph {
private:
    vector<string> explode(const string& s, const char& c)
    {
        string buff{""};
        vector<string> v;

        for(auto n:s)
        {
            if(n != c) buff+=n; else
            if(n == c && buff != "") { v.push_back(buff); buff = ""; }
        }
        if(buff != "") v.push_back(buff);

        return v;
    }
    GraphNode* get_node(int id){
        GraphNode* temp;
        for (int i = 0; i < nodes.size; ++i) {
            temp = nodes.getData(i);
            if (temp->identifier == id){
                return temp;
            }
        }
        return 0;
    }
    bool node_exist(int id){
        GraphNode* temp;
        for (int i = 0; i < nodes.size; ++i) {
            temp = nodes.getData(i);
            if (temp->identifier == id){
                return 1;
            }
        }
        return 0;
    }
    int toInt(string s){
        try
        {
            int i = std::stoi(s);
            return i;
        }
        catch (std::invalid_argument const &e)
        {
            return 0;
        }
        catch (std::out_of_range const &e)
        {
            return 0;
        }
    }

    void create_node(int id){
        if(!node_exist(id)){
            GraphNode* n1 = new GraphNode(id);
            nodes.addLast(n1);
        }
    }
    void connect_nodes(vector<string> v){
        if(v.size() != 0) {
            create_node(toInt(v[0]));
            create_node(toInt(v[1]));
            get_node(toInt(v[0]))->connect(toInt(v[1]), toInt(v[2]));
        }
    }
public:
    LinkedList<GraphNode*> nodes;

    Graph() = default;

    void uploadGraph() {
        string STRING;
        ifstream infile;
        infile.open ("./nodes.txt");
        string temp;
        while(!infile.eof()) // To get you all the lines.
        {
            getline(infile,STRING); // Saves the line in STRING.
            vector<string> v{explode(STRING, ',')};
            connect_nodes(v);
        }
        cout << "Connected" << endl;
        infile.close();
    }

};

#endif //SERVERSOCKET_GRAPH_HPP