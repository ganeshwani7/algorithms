algorithms
==========

Unique algorithms implementation

1. Van Emde Boas tree.
Features:
  1. Specialized tree which which gives O(log(log n)) time for insertion, deletion and searching an element in a tree.
  2. Phenomenal time of O( 1 ) to extract max and min element from the tree.
  
Limitations:
  1. Size of q(The universe of elements should be 1..n-1).
  2. Basically, value of elements which can be stored in the tree is restricted.

Recommendations:
  1. Good option for Van Emde Boas tree would be Red - black trees, which basically gives O(log n) time for all 
      operations.

Use:
  1. Very useful while implementing Heap, to extract min and max element from the tree.
