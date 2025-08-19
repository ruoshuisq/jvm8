//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef CLASSHIERARCHY_HPP
#define CLASSHIERARCHY_HPP
#include "JClass.hpp"


// jvms8 6.5.instanceof
// jvms8 6.5.checkcast
bool isSubClassOf(JClass the,JClass other);
bool isImplements(JClass the,JClass other);
bool isSubInterfaceOf(JClass the,JClass other);
bool  isAssignableFrom(JClass the,JClass other)  {

    if (&the == &other) {
        return true;
    }
    if(!the.isInterface()) {
        return isSubClassOf(other,the);
    }else {
        return isImplements(other,the);
    }
}

// the extends c
bool isSubClassOf(JClass the,JClass other)  {
    for (JClass * c=the.superClass;c!=nullptr;c=c->superClass) {
        if(c==&other) {
            return true;
        }
    }
    return false;
}

// the implements iface TODO
bool isImplements(JClass the,JClass other) {
    for (JClass * c=&the;c!=nullptr;c=c->superClass) {
        // if(&c == &other) {
            return true;
        // }
    }
    return false;
}
// func (the *Class) isImplements(iface *Class) bool {
//     for c := the; c != nil; c = c.superClass {
//         for _, i := range c.interfaces {
//             if i == iface || i.isSubInterfaceOf(iface) {
//                 return true
//             }
//         }
//     }
//     return false
// }

// the extends iface
bool isSubInterfaceOf(JClass the,JClass other) {
    return false;//TODO
}
// func (the *Class) isSubInterfaceOf(iface *Class) bool {
//     for _, superInterface := range the.interfaces {
//         if superInterface == iface || superInterface.isSubInterfaceOf(iface) {
//             return true
//         }
//     }
//     return false
// }


#endif //CLASSHIERARCHY_HPP
