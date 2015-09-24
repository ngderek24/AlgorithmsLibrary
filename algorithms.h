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

//given two strings, find the shortest distance between them in the string array
int shortestDist(string s[], int size, string s1, string s2);

//determines whether s can be rearranged to form a palindrome
bool canFormPalindrome(string s);

//returns the next lexicographically greater string than s
string nextPermutation(string s);

//removes whitespaces from a string
// O(n) time
void removeSpaces(string& s);

//returns the length of the longest substring of s with unique characters
//O(n) time
int longestUniqueSubstring(string s);

//determines whether there exists an anagram of s1 that is a substring of s2
//O(n) time
bool isAnagramSubstring(const string& s1, const string& s2);

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

//finds contiguous sequence with largest sum in array (returns largest sum) (Kadane's algorithm)
int largestContSum(int arr[], int size);

//prints all pairs of integers in the array that sums to the specified value
//this version of implementation uses array accesses but you can also use a hash map if space is not a problem (O(n))
//O(nlogn)
void printSumPairs(int arr[], int size, int sum);

//calculates the median of two sorted arrays
//assumptions: both a1 and a2 are sorted and have the same size
int median(int a1[], int a2[], int size);

//finds longest increasing subsequence of arr
int* longestIncSeq(int arr[], int size);

//convert distinct elements in arr into zigzag format where a < b > c < d > e...
//O(n) time
void zigZag(int arr[], int size);

//finds starting index of maximum average subarray of length k
//O(n) time
int maxAvg(int arr[], int size, int k);

//prints union of two sorted arrays
//O(n+m) time
void unionOfSortedArrays(int a[], int b[], int m, int n);

//prints intersection of two sorted arrays
//O(n+m) time
void intersectionOfSortedArrays(int a[], int b[], int m, int n);

//returns the size of the largest subarray of a with sum of 0
//O(n) time using hashed table
int largestZeroSumSubarray(int a[], int n);

//returns maximum sum of a[i]*i with only rotations allowed on the array
//O(n) time
int maxRotatedSum(int a[], int n);

//returns the maximum product of a subarray in a
// O(n) time
int maxProductSubarray(int a[], int n);

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

//finds intersection point of two singly linked lists
//O(n+m) time, n and m are sizes of the linked lists
template<class N>
int findIntersection(listNode* h1, listNode* h2);

//returns a random number from a list
//uses reservoir sampling technique
template<class N>
int findRandom(listNode* head);

//reverse a singly linked list in groups of k nodes
//O(n) time
template<class N>
void reverseListByK(listNode* head, int k);

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

//finds the maximum path sum in a binary tree
template<class V>
int maxPathSum(treeNode* root, int& maxSum);

//prints the nodes of a binary tree seen from the left view
template<class V>
void printLeftView(treeNode* root);


//prints the common nodes in two binary search trees
//O(h1 + h2) space, O(n) time
template<class V>
void commonNodesBSTs(treeNode* r1, treeNode* r2);

/*
* Bit Manipulation
*/

//updates bits i to j of n with m (length of m is guaranteed to be correct)
int updateBits(int n, int m, int i, int j);

//determines whether n is a power of 2
bool isPowerOf2(int n);

//determines number of bits to flip to convert a to b
int bitFlipNeeded(int a, int b);

//increment value of x by 1 without using operators (only bit manipulation)
int increment(int x);

//rotate bits to the left by d bits
//assumming 32-bit int
int rotateLeft(int x, unsigned int d);

//rotate bits to the right by d bits
//assumming 32-bit int
int rotateRight(int x, unsigned int d);

//prints the only two integers in given array that appear an odd number of times
void printOddTwoIntegers(int a[], int n);

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

// count how many n-digit numbers whose digits add up to sum
// an array is used to reduce time complexity of recursion
// 1 <= n <= 100 and 1 <= sum <= 50000
int countNDigitSum(int n, int sum);

// return the length of the longest common subsequence of two strings
// O(m + n)
int longestCommonSubsequence(string x, string y, int m, int n);

// determines whether num is palindromic
bool isNumPalindrome(int num);

/*
 * Searching and Sorting
 */

//selection sort on array
void selectionSort(int arr[], int size);

//bubble sort
void bubbleSort(int arr[], int size);

//insertion sort
void insertionSort(int arr[], int size);

//partitions array around a pivot p, used for quicksort
int partition(int arr[], int start, int end);

//quicksort
void quickSort(int arr[], int start, int end);

//merge
void merge(int arr[], int start, int mid, int end);

//mergesort
void mergeSort(int arr[], int start, int end);

/*
 * Others
 */

//swaps two integers
void swap(int& a, int& b);

//calculate x^n
//O(logn) time
int power(int x, unsigned int n);

#endif
