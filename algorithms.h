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

#endif
