//
//  LinkCut.cpp
//  Link Cut trees
//
//  Created by Amritha on 12/10/18.
//  Copyright © 2018 Amritha. All rights reserved.
//

/*#include<iostream>
#include "LinkCut.hpp"
using namespace std;

Node::Node(int c, int id){
    this->id = id;
    s = c;
    on = 0;
    l = r = p = NULL;
    flip = false;
}

bool Node::isRoot() {
    return (p == NULL || (p->l != this && p->r != this));
}

void Node::normalize() {
    if(flip) {
        flip = false;
        on = s - on;
        myFlip =  !(myFlip);
        if(l != NULL)
            l->flip = !(l->flip);
        if(r != NULL)
            r->flip = !(r->flip);
    }
}

void Node::update() {
    
}
 */
