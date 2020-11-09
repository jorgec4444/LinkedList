/* 
 * File:   LinkedList.h
 * Author: JORGEC
 *
 * Created on 9 de abril de 2020, 16:28
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <stdexcept>
#include "Position.h"
#include "NodeList.h"
#include <iostream>

using namespace std;

template <class Element>
class LinkedList {
public:
    
    LinkedList() {
        _head = new NodeList<Element>("0");
        _rear = new NodeList<Element>("0");
        _head->setNext(_rear);
        _rear->setPrevious(_head);
        _size = 0;
        cout << "LinkedList buida creada." << endl;
    }
    
    LinkedList(vector<Element> elements){
        _head = new NodeList<Element>("0");
        _rear = new NodeList<Element>("0");
        _head->setNext(_rear);
        _rear->setPrevious(_head);
        _size = 0;
        
        for(int i = elements.size()-1; i > -1; i--){
            insertFront(elements[i]);
        }
        cout << "LinkedList per vector creada" << endl;
    }
    
    
    LinkedList(const LinkedList<Element>& list){
        Position<Element>* pos = new Position<Element>(list._head);
        LinkedList<Element>* new_list = new LinkedList<Element>();
    
        if (pos != nullptr){
            new_list->insertFront(pos);
            while (pos.next() != nullptr){
                new_list->insertAfter(pos,pos->next().element());
                pos = pos.next();
            }
        }
    }
    
    /*virtual ~LinkedList (){
        cout << "LinkedList destructor called :" << endl;
        if (_size != 0){
            NodeList<Element>* iterator(_head->getNext());
            NodeList<Element>* tmp = iterator;
            int cnt = 0;
            while (cnt < _size-1) {
                cout << iterator->getElement() << endl;
                if (iterator->getNext()->getElement() != "0"){
                    tmp = iterator->getNext();
                }
                delete iterator;
                iterator = tmp;
                cnt++;

            }
            _head = nullptr;
            _rear = nullptr;
            _size = 0;
        }else
            cout << "La LinkedList està buida" << endl;
    }*/
    
    int size() const{
        return _size;
    }
    
    bool isEmpty(){
        if (_size == 0)
            return true;
        else
            return false;
    }
    
   
    Position<Element> begin() const{
        Position<Element>* first = new Position<Element>(_head->getNext());
        return *first;
    }
    
    Position<Element> end() const{
        Position<Element>* last = new Position<Element>(_rear->getPrevious());
        return *last;
    }
    
    void insertFront(const Element & element){
        NodeList<Element>* new_node = new NodeList<Element>(element);
        
        if (_size == 0) {
            _head->getNext()->setPrevious(new_node);
            new_node->setNext(_head->getNext());
            _head->setNext(new_node);
        } else {
            _head->getNext()->setPrevious(new_node);
            new_node->setNext(_head->getNext());
            new_node->setPrevious(_head);
            _head->setNext(new_node);
        }

        _size++;
    }
    
    void insertBack(const Element & element){
        NodeList<Element>* new_node = new NodeList<Element>(element);
        
        if (_size == 0) {
            _rear->getPrevious()->setNext(new_node);
            new_node->setPrevious(_rear->getPrevious());
            _rear->setPrevious(new_node);
        } else {
            _rear->getPrevious()->setNext(new_node);
            new_node->setPrevious(_rear->getPrevious());
            new_node->setNext(_rear);
            _rear->setPrevious(new_node);
        }
        
        _size++;

    }
    
    void insertAfter(Position<Element>& position, const Element& element){
        NodeList<Element>* new_node = new NodeList<Element>(element);
    
        position.getNode()->getNext()->setPrevious(new_node);
        new_node->setNext(position.getNode()->getNext());
        new_node->setPrevious(position.getNode());
        position.getNode()->setNext(new_node);

        _size++;
    }
    
    void insertBefore(Position<Element>& position, const Element & element){
        NodeList<Element>* new_node = new NodeList<Element>(element);

        position.getNode()->getPrevious()->setNext(new_node);
        new_node->setPrevious(position.getNode()->getPrevious());
        position.getNode()->setPrevious(new_node);
        new_node->setNext(position.getNode());
        
        _size++;
    }
    
    
    void print() const {
        if (_size != 0){
            Position<Element> iterator(_head->getNext());
            int cnt = 0;
            cout << "[ ";
            while (cnt < _size) {
                cout << iterator.element() << " ";
                iterator = iterator.next();
                cnt++;
            }
            cout << "]" << endl;
        }else
            cout << "La LinkedList està buida" << endl;
    }

private:
    NodeList<Element>* _head;
    NodeList<Element>* _rear;
    int _size;
    
};

#endif /* LINKEDLIST_H */

