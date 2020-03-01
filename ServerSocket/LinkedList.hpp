//
// Created by david on 26/2/20.
//

#ifndef SERVERSOCKET_LINKEDLIST_HPP
#define SERVERSOCKET_LINKEDLIST_HPP
#define NULL __null
#include <iostream>
using namespace std;

template <typename T> class Node {
public:
    T data;
    Node *prev;
    Node *next;

    Node() {
        data = NULL;
        next = NULL;
        prev = NULL;
    }

    Node(T d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};


template <typename B> class LinkedList {
public:
    Node<B> *first;
    Node<B> *last;

    LinkedList<B>() {
        first = NULL;
        last = NULL;
    }

    LinkedList<B>(Node<B> *node) {
        first = node;
    }

    // template <typename B>
    void addFirst(B data) {
        Node<B> *new_node = new Node<B>(data);

        if (first != NULL) {
            new_node->next = first;
            first->prev = new_node;
        }
        if (first == NULL) {
            last = new_node;
        }
        first = new_node;
    }

    void addLast(B data) {
        Node<B> *new_node = new Node<B>(data);
        if (last == NULL) {
            first = new_node;
            last = new_node;
            first->next = last;
            last->prev = first;

        } else {
            last->next = new_node;
            new_node->prev = last;
            last = new_node;
        }

    }

    void insert(int position, B data) {
        Node<B>  *new_node = new Node<B>(data);

        Node<B> *temp = first;
        int i = 0;
        while (temp != NULL){
            if (i == position){
                if (temp == first){
                    first = new_node;
                } else{
                    temp->prev->next = new_node;
                }

                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev = new_node;
                temp = NULL;
            }else {
                i++;
                temp = temp->next;
            }
        }

    }

    void print() {
        Node<B> *current = first;

        while (current != NULL) {
            int num = current->data;
            cout << num << endl;
            current = current->next;
        }
    }
};


#endif //SERVERSOCKET_LINKEDLIST_HPP
