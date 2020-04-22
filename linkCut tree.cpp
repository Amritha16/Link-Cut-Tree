//
//  linkCut tree.cpp
//  Link Cut trees


#include <iostream>
#include "linkCut tree.h"

using namespace std;

Node::Node() {
    p = 0;
    pp = 0;
    l = 0;
    r = 0;
}

void LinkCut::update(Node *x)
{   x->sz = 1;
    if(x->l)
        x->sz += x->l->sz;
    if(x->r)
        x->sz += x->r->sz;
}

void LinkCut::rotR(Node *x)
{   Node *y, *z;
    y = x->p;
    z = y->p;
    if((y->l = x->r))
        y->l->p = y;
    x->r = y;
    y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
    else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void LinkCut::rotL(Node *x) {
    Node *y, *z;
    y = x->p;
    z = y->p;
    if((y->r = x->l)) y->r->p = y;
    x->l = y;
    y->p = x;
    if((x->p = z))
    {   if(y == z->l) z->l = x;
    else z->r = x;
    }
    x->pp = y->pp;
    y->pp = 0;
    update(y);
}

void LinkCut::splay(Node *x) {
    Node *y, *z;
    while(x->p)
    {   y = x->p;
        if(y->p == 0) {
            if(x == y->l)
                rotR(x);
            else
                rotL(x);
        }
        else {
            z = y->p;
            if(y == z->l) {
               if(x == y->l) {
                    rotR(y);
                    rotR(x);
                }
                else {
                    rotL(x);
                    rotR(x);
                }
            }
            else {
                if(x == y->r) {
                    rotL(y);
                    rotL(x);
                }
                else {
                    rotR(x);
                    rotR(x);
                }
            }
        }
    }
    update(x);
}

Node* LinkCut::access(Node *x) {
    splay(x);
    if(x->r) {
        x->r->pp = x;
        x->r->p = 0;
        x->r = 0;
        update(x);
    }
    
    Node *last = x;
    while(x->pp) {
        Node *y = x->pp;
        last = y;
        splay(y);
        if(y->r) {
            y->r->pp = y;
            y->r->p = 0;
        }
        y->r = x;
        x->p = y;
        x->pp = 0;
        update(y);
        splay(x);
    }
    return last;
}

Node* LinkCut::root(Node *x)
{   access(x);
    while(x->l) x = x->l;
    splay(x);
    return x;
}

void LinkCut::cut(Node *x)
{   access(x);
    x->l->p = 0;
    x->l = 0;
    update(x);
}

void LinkCut::link(Node *x, Node *y)
{   access(x);
    access(y);
    x->l = y;
    y->p = x;
    update(x);
}

Node *lca(Node *x, Node *y)
{   access(x);
    return access(y);
}

int depth(Node *x)
{   access(x);
    return x->sz - 1;
}

    LinkCut(int n)
    {   x = new Node[n];
        for(int i = 0; i < n; i++)
        {   x[i].label = i;
            update(&x[i]);
        }
    }
    
    virtual ~LinkCut()
    {   delete[] x;
    }
    
    void link(int u, int v) {
        ::link(&x[u], &x[v]);
    }
    
    void cut(int u)
    {   ::cut(&x[u]);
    }
    
    int root(int u)
    {   return ::root(&x[u])->label;
    }
    
    int depth(int u)
    {   return ::depth(&x[u]);
    }
    
    int lca(int u, int v)
    {   return ::lca(&x[u], &x[v])->label;
    }
};

int main(void)
{   return 0;
}
