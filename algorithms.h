#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <string>

//definition of a tree node
struct treeNode
{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

//definition of a list node
struct listNode
{
	int data;
	struct listNode* next;
};

//Level order traversal using queue
//O(n) time complexity, n = number of nodes in tree
//visits node at each level and add children to queue similar to BFS
void levelOrder(treeNode* root);

//Level order traversal using queue in spiral using two stacks
//O(n) time complexity, O(n) space, n = number of nodes in tree
//visits node at each level and add children to two stacks to traverse in a spiral
void levelOrderSpiral(treeNode* root);

//Print duplicated elements in an integer array
//O(n) time, O(1) space
void printDuplicate(int arr[], int size);

//Reverse a linked list
//O(n) time, O(1) space
void reverseLinkedList(listNode* head);

//Checks whether string s1 and s2 are a rotation of each other
bool isRotated(string s1, string s2);

//reverses a string
//O(n) time
void reverseString(char* str);

//reverses a string
//O(n) time
void reverseString(char* begin, char* end);

//reverses words in a string
//O(n) time
void reverseWords(char* str);

//randomly shuffles elements of an array using the Fisher-Yates algorithm
template<class T>
void fisher_yates_shuffle(T arr[], int size);

//determines whether s1 is an anagram of s2
//O(n) time
bool isAnagram(string s1, string s2);

//compress input string into its run length encoding
//O(n) time
string runLengthEncode(string s);

//removes duplicates from an unsorted linked list
//O(n) time
void removeDuplicates(listNode* head);

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

//determines whether a binary tree is balanced
//O(n) time
template<class V>
bool isBalanced(treeNode* root, int& height);

//determines whether n1 and n2 are connected within the graph
template<class G>
bool isConnected(graphNode* n1, graphNode* n2);

//creates a linked list for all the nodes at the level specified
template<class V>
void createLevelLinkedList(treeNode* root, listNode* head, int level);

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

#endif
