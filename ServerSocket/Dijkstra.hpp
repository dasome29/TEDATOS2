//
// Created by david on 2/3/20.
//

#ifndef SERVERSOCKET_DIJKSTRA_HPP
#define SERVERSOCKET_DIJKSTRA_HPP

#include "Graph.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <set>
#include <limits>


class Dijkstra {
private:
    typedef pair<int, int> pi;

    void change_distance(int id, int distance, vector<vector<int>> &distances) {
        for (vector<int> v : distances) {
            if (v[0] == id) {
                v[1] = distance;
            }
        }
    }
    int get_distance(int id, vector<vector<int>> &distances){
        for (vector<int> v : distances) {
            if (v[0] == id) {
                return v[1];
            }
        }
    }

    bool is_visited(int id, set<int> v){
        if (v.count(id) != 0){
            return 1;
        }
        return 0;
    }

    vector<int> get_neighbors(int id, Graph g){
        LinkedList<GraphNode*> n = g.nodes;
        for (int i = 0; i < n.size; ++i) {
           if (n.getData(i)->identifier == id){
               vector<vector<int>> connections = n.getData(i)->connections;
               vector<int> result;
               for (vector<int> v : connections) {
                   result.push_back(v[0]);
               }
               return result;
           }
        }
    }
    int get_weight(int node1, int node2, Graph g){
        LinkedList<GraphNode*> n = g.nodes;
        for (int i = 0; i < n.size; ++i) {
            if (n.getData(i)->identifier == node1){
                vector<vector<int>> connections = n.getData(i)->connections;
                for (vector<int> v : connections) {
                    if (v[0] == node2){
                        return v[1];
                    }
                }
            }
        }
    }
    int get_vector_index(int id, vector<vector<int>> p){
        for (int i = 0; i < p.size(); ++i) {
            if (p[i][0] == id){
                return i;
            }
        }
    }
    vector<int> get_path(int id, vector<vector<int>> p){

        cout << "id" << id << endl;
        int current = id;
        vector<int> result;
        while(current != -1){
            cout << p[get_vector_index(current, p)][1] << endl;
            result.push_back(p[get_vector_index(current, p)][0]);
            current = p[get_vector_index(current, p)][1];
        }
        return result;
    }
    void change_parent(int son, int parent, vector<vector<int>> &parents){
        for (vector<int> &v : parents){
            if (v[0] == son){
//                cout << son << "-" << parent << endl;
                v[1] = parent;
            }
        }
    }

public:

    Dijkstra() = default;

    void dijkstra(int src, int target, Graph g) {
        priority_queue<pi, vector<pi>, greater<> > queue;
        vector<vector<int>> distances;
        vector<vector<int>> parents;
        set<int> visited;
        LinkedList<GraphNode *> n = g.nodes;


        for (int i = 0; i < n.size; ++i) {
            int a = std::numeric_limits<int>::max();
            vector<int> vec_distances;
            vec_distances.push_back(n.getData(i)->identifier);
            vec_distances.push_back(a);
            distances.push_back(vec_distances);

            vector<int> vec_parent;
            vec_parent.push_back(n.getData(i)->identifier);
            vec_parent.push_back(-1);
            parents.push_back(vec_parent);

        }
        change_distance(src, 0, distances);
        queue.push(make_pair(get_distance(src, distances), src));

        while (!queue.empty()){
//            cout << parents.size() << endl;
            pair<int, int> top = queue.top();
            int u = top.second;
            queue.pop();
            if (u == target){
//                for (int x : get_path(target, parents)){
//                    cout << x << endl;
//
//                }
                cout << get_path(target, parents).size() << endl;
                break;
            }
            for (int v : get_neighbors(u, g)) {
//                cout << v << endl;
                if (!is_visited(u, visited)){
                    if (get_distance(v, distances) > get_distance(u, distances) + get_weight(u, v, g)){
                        change_distance(v, get_distance(u, distances) + get_weight(u, v, g), distances);

                        change_parent(v, u, parents);

                        queue.push(make_pair(get_distance(v , distances), v));
                    }


                }
            }
            visited.insert(u);
        }
    }
};

#endif //SERVERSOCKET_DIJKSTRA_HPP
