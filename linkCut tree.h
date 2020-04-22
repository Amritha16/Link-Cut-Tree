//
//  linkCut tree.h
//  Link Cut trees
//
//  Created by Amritha on 19/10/18.
//  Copyright © 2018 Amritha. All rights reserved.
//

#ifndef linkCut_tree_h
#define linkCut_tree_h
struct Node
{   int sz;
    int label; /* size, label */
    Node *p, *pp, *l, *r; /* parent, path-parent, left, right pointers */
    Node(); 
};

class LinkCut {
    Node *x;
public:
    LinkCut(int n);
    void update(Node *x);
    void rotR(Node *x);
    void rotL(Node *x);
    void splay(Node *x);
    Node* access(Node *x);
    void link(int u, int v);
    void cut(int u);
    int root(int u);
    int depth(int u);
    int lca(int u, int v);
    virtual ~LinkCut();
};

#endif /* linkCut_tree_h */
