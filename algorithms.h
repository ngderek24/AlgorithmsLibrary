#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <string>
#include <vector>

/*
* Definitions
*/

//definition of a tree node
template<class V>
struct treeNode
{
    V data;
    treeNode* left;
    treeNode* right;
	treeNode* parent;
};

//definition of a list node
template<class N>
struct listNode
{
	N data;
	listNode* next;
};

//definition of a graph node
template<class G>
struct graphNode
{
	G data;
	bool visited = false;
	vector<graphNode*> connectedTo;
};

/*
* Strings
*/

//reverses a string
//O(n) time
void reverseString(char* str);

//reverses a string
//O(n) time
void reverseString(char* begin, char* end);

//reverses words in a string
//O(n) time
void reverseWords(char* str);

//Checks whether string s1 and s2 are a rotation of each other
bool isRotated(string s1, string s2);

//determines whether s1 is an anagram of s2
//O(n) time
bool isAnagram(string s1, string s2);

//compress input string into its run length encoding
//O(n) time
string runLengthEncode(string s);

//inserts c at pos in s
string insertCharAt(string s, char c, int pos);

/*
* Arrays
*/

//Print duplicated elements in an integer array
//O(n) time, O(1) space
void printDuplicate(int arr[], int size);

//randomly shuffles elements of an array using the Fisher-Yates algorithm
template<class T>
void fisher_yates_shuffle(T arr[], int size);

//merges two sorted arrays(a is big enough to hold values of both a and b)
void merge(int a[], int b[], int sizeA, int sizeB);

//search a rotated sorted array to find the number x using a variation of binary search
//O(log n) time expected
int search(int arr[], int start, int end, int x);

/*
* Linked Lists
*/

//Reverse a linked list
//O(n) time, O(1) space
template<class N>
void reverseLinkedList(listNode* head);

//removes duplicates from an unsorted linked list
//O(n) time
template<class N>
void removeDuplicates(listNode* node);

//finds the kth to last element of a singly linked list
//O(n) time
template<class N>
listNode* kthToLastOfList(listNode* head, int k);

//deletes a node in the middle of a singly linked list, given only access to that node
template<class N>
bool deleteListNode(listNode* node);

//finds beginning of loop in a circular linked list
template<class N>
listNode* findBegin(listNode* head);

//creates a linked list for all the nodes at the level specified
template<class V>
void createLevelLinkedList(treeNode* root, listNode* head, int level);

/*
* Graphs
*/

//determines whether n1 and n2 are connected within the graph
template<class G>
bool isConnected(graphNode* n1, graphNode* n2);

/*
* Trees
*/

//Level order traversal using queue
//O(n) time complexity, n = number of nodes in tree
//visits node at each level and add children to queue similar to BFS
template<class V>
void levelOrder(treeNode* root);

//Level order traversal using queue in spiral using two stacks
//O(n) time complexity, O(n) space, n = number of nodes in tree
//visits node at each level and add children to two stacks to traverse in a spiral
template<class V>
void levelOrderSpiral(treeNode* root);

//determines whether a binary tree is balanced
//O(n) time
template<class V>
bool isBalanced(treeNode* root, int& height);

//determines whether a binary tree is a binary search tree using min/max algorithm
//O(n) time
template<class V>
bool isBST(treeNode* root, int min, int max);

//returns the leftmost child in the tree starting at root
//O(h) time, h = height of tree
template<class V>
treeNode* leftMostChild(treeNode* root);

//finds the in-order successor to the given node in a BST (assuming node has parent pointer)
template<class V>
treeNode* inorderSucc(treeNode* root);

//finds the in-order successor to the given node in a BST (assuming node has no parent pointer)
template<class V>
treeNode* inorderSucc(treeNode* root, treeNode* node);

//finds the lowest common ancestor of n1 and n2 in a binary tree
//O(n) time
template<class V>
treeNode* BT_LCA(treeNode* root, treeNode* n1, treeNode* n2);

//finds the lowest common ancestor of n1 and n2 in a binary search tree
//O(h) time
template<class V>
treeNode* BST_LCA(treeNode* root, treeNode* n1, treeNode* n2);

//determines whether two trees match each other
template<class V>
bool treeMatch(treeNode* t1, treeNode* t2);

//determines whether t1 contains t2 as a subtree
template<class V>
bool containsTree(treeNode* t1, treeNode* t2);

/*
* Bit Manipulation
*/

//updates bits i to j of n with m (length of m is guaranteed to be correct)
int updateBits(int n, int m, int i, int j);

//determines whether n is a power of 2
bool isPowerOf2(int n);

//determines number of bits to flip to convert a to b
int bitFlipNeeded(int a, int b);

/*
* Recursion & Dynamic Programming
*/

//a magic index i is one such that arr[i] == i
//finds a magic index in arr using binary search (assuming non-distinct elements)
//if elements are distinct, we can limit our search on half of array depending on mid index
int magicIndex(int arr[], int start, int end);

//computes all permutations of a string of unique characters
//O(n!) time
vector<string> computePerms(string s);

#endif
