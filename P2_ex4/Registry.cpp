/* 
 * File:   Registry.cpp
 * Author: JORGEC
 * 
 * Created on 13 de abril de 2020, 18:42
 */

#include "Registry.h"

Registry::Registry() {
    
}

Registry::Registry(const Registry& orig) {

}

Registry::~Registry() {
    
}

void Registry::insert(const string& element) {
    // < 0 si pos va abans que element
    // > 0 si pos va després de element
    
    if (size() == 0)
        insertFront(element);
    else {
        Position<string> pos(begin());
        int equals = pos.element().compare(element);

        if (equals == 0){
            insertAfter(pos,element);
        }
        else if (equals < 0){
            while(equals < 0){
                if (pos.next().element() == "0"){
                    insertBack(element);
                    equals = 404;
                    break;
                }
                else {
                    pos = pos.next();
                    equals = pos.element().compare(element);
                }

            }
            if(equals != 404)
                insertBefore(pos,element);
            }
        else if (equals > 0){
            insertFront(element);
        }
    }
    
}

void Registry::merge(const Registry& other) {
    Position<string> pos(other.begin());
    
    while(pos.next().element() != "0"){
        insert(pos.element());
        pos = pos.next();
    }
}

bool Registry::operator==(const Registry& other) const {
    Position<string> pos_re(begin());
    Position<string> pos_ot(other.begin());
    int fi = 0;
    
    if (size() == other.size()){
        while(pos_re.next().element() != "0" && fi == 0){
            if (pos_re.element() != pos_ot.element()){
                fi = 1;
                break;
            }
            pos_re = pos_re.next();
            pos_ot = pos_ot.next();
        }
    }
    else
        fi=1;
    
    return (fi == 0);
        
}




