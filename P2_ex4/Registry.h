/* 
 * File:   Registry.h
 * Author: JORGEC
 *
 * Created on 13 de abril de 2020, 18:42
 */

#include "LinkedList.h"
#include <string>
#ifndef REGISTRY_H
#define REGISTRY_H

class Registry : public LinkedList<string>{
public:
    Registry();
    Registry(const Registry& orig);
    virtual ~Registry();
    
    void insert(const string& element);
    void merge(const Registry& other);
    bool operator==(const Registry& other) const;
    
    // Opcional: quants cops apareix cada usuari en un registre
    //void count(LinkedList<std::string>& users, LinkedList<int>& counts) const;
private:

};

#endif /* REGISTRY_H */

