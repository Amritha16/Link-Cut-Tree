# Link Cut Tree
An implementation of Tarjan and Sleator's 'dynamic tree', https://www.cs.cmu.edu/~sleator/papers/dynamic-trees.pdf.
A link/cut tree is a data structure for representing a forest, a set of rooted trees, and offers the following operations:

-> Add a tree consisting of a single node to the forest.

-> Given a node in one of the trees, disconnect it (and its subtree) from the tree of which it is part.

-> Attach a node to another node as its child.

-> Given a node, find the root of the tree to which it belongs. By doing this operation on two distinct nodes, one can check whether they belong to the same tree.
  
Average	Worst case:

Link	O(log n)	amortized O(log n)

Cut	O(log n)	amortized O(log n)

Path	O(log n)	amortized O(log n)

FindRoot	O(log n)	amortized O(log n)
