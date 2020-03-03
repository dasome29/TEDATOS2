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
    Node<T> *prev;
    Node<T> *next;


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
    int size;

    LinkedList<B>() {
        first = NULL;
        last = NULL;
        size = 0;
    }

    LinkedList<B>(Node<B> *node) {
        first = node;
        last = node;
        size = 1;
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
        size++;
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
        size++;
    }
    B getData(int index){
        Node<B> *temp = first;
        for (int i = 0; i < size; ++i) {
            if (i == index){
                return temp->data;
            } else{
                temp = temp->next;
            }
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
        size++;
    }

    void print() {
        Node<B> *current = first;

        while (current != NULL) {
            int num = current->data;
            current = current->next;
        }
    }

    void empty(){
        first = NULL;
        last = NULL;
        size = 0;
    }
};


#endif //SERVERSOCKET_LINKEDLIST_HPP
