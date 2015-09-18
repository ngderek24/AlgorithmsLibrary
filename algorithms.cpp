#include "algorithms.h"
#include <queue>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

//Level order traversal using queue
//O(n) time complexity, n = number of nodes in tree
//visits node at each level and add children to queue similar to BFS
template<class V>
void levelOrder(treeNode* root){
	treeNode* temp = root;
	queue<treeNode*> q;
	
	while(temp){
		cout << temp->data;

		if(temp->left)
			q.push(temp->left);

		if(temp->right)
			q.push(temp->right);

		temp = q.pop;
	}
}

//Level order traversal using queue in spiral using two stacks
//O(n) time complexity, O(n) space, n = number of nodes in tree
//visits node at each level and add children to two stacks to traverse in a spiral
template<class V>
void levelOrderSpiral(treeNode* root){
	if (root == NULL)
		return;

	stack<treeNode*> toRight;
	stack<treeNode*> toLeft;

	toLeft.push(root);

	while(!toRight.empty() || !toLeft.empty()){
		while(!toRight.empty()){
			treeNode* temp = toRight.top();
			toRight.pop();
			cout << temp->data << " ";

			//add nodes in appropriate order to correctly traverse next level
			if(temp->left)
				toLeft.push(temp->left);
			if(temp->right)
				toLeft.push(temp->right);
		}

		while(!toLeft.empty()){
			treeNode* temp = toLeft.top();
			toLeft.pop();
			cout << temp->data << " ";

			//add nodes in appropriate order to correctly traverse next level
			if(temp->right)
				toLeft.push(temp->right);
			if(temp->left)
				toLeft.push(temp->left);
		}
	}
}

//Print duplicated elements in an integer array
//O(n) time, O(1) space
void printDuplicate(int arr[], int size){
	for(int i = 0; i < size; i++){
		if(arr[abs(arr[i])] > 0)
			arr[abs(arr[i])] = -arr[abs(arr[i])];
		else
			cout << abs(arr[i]) << " ";
	}
}

//Reverse a linked list
//O(n) time, O(1) space
template<class N>
void reverseLinkedList(listNode* head){
	listNode* prev = nullptr;
	listNode* curr = head;
	listNode* next;

	while(curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

//Checks whether string s1 and s2 are a rotation of each other
bool isRotated(string s1, string s2){
	if(s1.size() == s2.size()){
		string temp = s1 + s1;
		if(s1.find(s2) != string::npos)
			return true;
		else
			return false;
	}
	return false;
}

//reverses a string
//O(n) time
void reverseString(char* str){
	char* end = str;
	char tmp;
	if(str){
		//find end of string
		while(*end)
			end++;
		end--;

		//swap characters at the start with the end, going inwards
		while(str < end){
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

//reverses a string
//O(n) time
void reverseString(char* begin, char* end){
	char tmp;
	while(begin < end){
		tmp = *begin;
		*begin++ = *end;
		*end-- = tmp;
	}
}

//reverses words in a string
//O(n) time
void reverseWords(char* str){
	char *word_begin = NULL;
    char *temp = str; 
 
    while(*temp){
        /*make sure that the string start with
          valid character (not space) only*/
        if ((word_begin == NULL) && (*temp != ' ')){
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0'))){
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    }

	//reverse whole string after reversing each word
    reverse(str, temp-1);
}

//randomly shuffles elements of an array using the Fisher-Yates algorithm
template<class T>
void fisher_yates_shuffle(T arr[], int size){
	for(int i = 0; i < size; i++){
		srand(unsigned time(0));
		int randIndex = rand() % size;
		T temp = arr[randIndex];
		arr[randIndex] = arr[i];
		arr[i] = temp;
	}
}

//determines whether s1 is an anagram of s2
//O(n) time
bool isAnagram(string s1, string s2){
	int count[256] = {0};
	int i;

	for(i = 0; s1[i] && s2[i]; i++){
		count[s1[i]]++;
		count[s2[i]]--;
	}

	if(s1[i] || s2[i])
		return false;

	for(i = 0; i < 256; i++){
		if(count[i])
			return false;
	}
	return true;
}

//compress input string into its run length encoding
//O(n) time
string runLengthEncode(string s){
	int n = s.size();
	int i;
	int count = 1;
	char prev = s[0];
	string res = "";
	
	for(i = 1; i < n; i++){
		if(s[i] == s[i-1])
			count++;
		else{
			res += prev;
			res += char(count + 48);
			count = 1;
			prev = s[i];
		}
	}
	res += prev;
	res += char(count + 48);

	if(res.size() > n)
		return s;
	return res;
}

//removes duplicates from an unsorted linked list
//O(n) time
template<class N>
void removeDuplicates(listNode* node){
	set<int> listData;
	listNode* prev = nullptr;

	while(node != nullptr){
		if(listData.find(node->data) != listData.end())
			prev->next = node->next;
		else{
			listData.emplace(node->data);
			prev = node;
		}
		node = node->next;
	}
}

//finds the kth to last element of a singly linked list
//O(n) time
template<class N>
listNode* kthToLastOfList(listNode* head, int k){
	if(k <= 0) 
		return nullptr;

	listNode* r1 = head;
	listNode* r2 = head;

	for(int i = 0; i < k-1; i++){
		if(r2 == nullptr)
			return nullptr;
		r2 = r2->next;
	}
	if(r2 == nullptr)
		return nullptr;

	while(r2->next != nullptr){
		r1 = r1->next;
		r2 = r2->next;
	}
	return r1;
}

//deletes a node in the middle of a singly linked list, given only access to that node
template<class N>
bool deleteListNode(listNode* node){
	if(node == nullptr || node->next == nullptr)
		return false;

	//copies next node's data to current node and delete next node
	listNode* next = node->next;
	node->data = next->data;
	node->next = next->next;
	return true;
}

//finds beginning of loop in a circular linked list
template<class N>
listNode* findBegin(listNode* head){
	listNode* slow = head;
	listNode* fast = head;

	//slow travels 1 node while fast travels 2 nodes at a time
	//when they collide, break and set slow to head
	while(fast != nullptr && fast->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			break;
	}

	if(fast == nullptr && fast->next == nullptr)
		return nullptr;
	
	slow = head;
	
	//both slow and fast travel 1 node at a time and when they collide, they're at the beginning of the loop in the list
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

//determines whether a binary tree is balanced
//O(n) time
template<class V>
bool isBalanced(treeNode* root, int& height){
	int leftHeight = 0;
	int rightHeight = 0;

	bool leftBal = false;
	bool rightBal = false;

	if(root == nullptr){
		height = 0;
		return true;
	}

	//recur for subtrees
	leftBal = isBalanced(root->left, leftHeight);
	rightBal = isBalanced(root->right, rightHeight);

	height = max(leftHeight, rightHeight) + 1;

	//not balanced
	if((leftHeight - rightHeight > 1) || (rightHeight - leftHeight > 1))
		return false;
	//balanced if subtrees and current tree are balanced
	else
		return (leftBal && rightBal);
}

//determines whether n1 and n2 are connected within the graph (BFS)
template<class G>
bool isConnected(graphNode* n1, graphNode* n2){
	if(n1 == n2)
		return true;

	queue<graphNode*> nodes;
	nodes.push(n1);
	graphNode* temp;

	while(!nodes.empty()){
		temp = nodes.pop();
		if(temp != nullptr){
			for(graphNode* i : nodes){
				if(!(i->visited)){
					if(i == n2)
						return true;
					else{
						i->visited = true;
						nodes.push(i);
					}
				}
			}
			temp->visited = true;
		}
	}
	return false;
}

//creates a linked list for all the nodes at the level specified
template<class V>
void createLevelLinkedList(treeNode* root, listNode* head, int level){
	if(root == nullptr || level < 0)
			return;
	
	//at right level so add node to linked list
	if(level == 0){
		listNode* temp = new listNode();
		temp->next = head->next;
		temp->data = root->data;
		head->next = temp;
	}

	//recur tree, starting with right first because we're inserting to beginning of linked list
	createLevelLinkedList(root->right, head, level-1);
	createLevelLinkedList(root->left, head, level-1);
}

//determines whether a binary tree is a binary search tree using min/max algorithm
//O(n) time
template<class V>
bool isBST(treeNode* root, int min, int max){
	if(root == nullptr)
		return true;

	//check if data is within valid range
	if(root->data <= min || root->data > max)
		return false;

	return (isBST(root->left, min, root->data) && isBST(root->right, root->data, max));
}

//returns the leftmost child in the tree starting at root
//O(h) time, h = height of tree
template<class V>
treeNode* leftMostChild(treeNode* root){
	if(root == nullptr)
		return nullptr;
	treeNode* curr = root;
	while(curr->left != nullptr)
		curr = curr->left;
	return curr;
}

//finds the in-order successor to the given node in a BST (assuming node has parent pointer)
template<class V>
treeNode* inorderSucc(treeNode* root){
	//if has right child, find leftmost child of right child
	if(root->right != nullptr)
		return leftMostChild(root->right);
	//go up the tree until a node whose left child is this node
	else{
		treeNode* s = root;
		treeNode* t = s->parent;
		while(t != nullptr && s != t->left){
			s = t;
			t = t->parent;
		}
		return t;
	}
}

//finds the in-order successor to the given node in a BST (assuming node has no parent pointer)
template<class V>
treeNode* inorderSucc(treeNode* root, treeNode* node){
	//if has right child, find leftmost child of right child
	if(node->right != nullptr)
		return leftMostChild(node->right);
	
	//traverse down from root to find succ
	treeNode* succ = nullptr;
	while(root != nullptr){
		if(node->data < root->data){
			succ = root;
			root = root->left;
		}
		else if(node->data > root->data)
			root = root->right;
		else
			break;
	}
	return succ;
}

//finds the lowest common ancestor of n1 and n2 in a binary tree
//O(n) time
template<class V>
treeNode* BT_LCA(treeNode* root, treeNode* n1, treeNode* n2){
	if(root == nullptr)
		return nullptr;

	//found node in tree
	if(root->data == n1->data || root->data == n2->data)
		return root;

	//recur left and right
	treeNode* left = BT_LCA(root->left, n1, n2);
	treeNode* right = BT_LCA(root->right, n1, n2);

	//if found in both left and right subtrees, this node must be the LCA
	if(left && right)
		return root;

	//if only found in 1 subtree, returned node must be LCA
	if(left != nullptr)
		return left;
	else
		return right;
}

//finds the lowest common ancestor of n1 and n2 in a binary search tree
//O(h) time
template<class V>
treeNode* BST_LCA(treeNode* root, treeNode* n1, treeNode* n2){
	//use property of BST to find LCA
	while(root != nullptr){
		if(n1->data < root->data && n2->data < root->data)
			root = root->left;
		else if(n1->data > root->data && n2->data > root->data)
			root = root->right;
		else
			break;
	}
	return root;
}

//determines whether two trees match each other
template<class V>
bool treeMatch(treeNode* t1, treeNode* t2){
	//empty trees match
	if(t1 == nullptr && t2 == nullptr)
		return true;

	//only 1 empty tree so no match
	if(t1 == nullptr || t2 == nullptr)
		return false;

	//different data so no match
	if(t1->data != t2->data)
		return false;
	//recur for left and right
	else
		return (treeMatch(t1->left, t2->left) && treeMatch(t1->right, t2->right));
}

//determines whether t1 contains t2 as a subtree
template<class V>
bool containsTree(treeNode* t1, treeNode* t2){
	if(t2 == nullptr)
		return true;
	if(t1 == nullptr)
		return false;
	//matching data so check if subtrees match
	if(t1->data == t2->data){
		if(treeMatch(t1, t2))
			return true;
	}
	//recur for left and right
	return (containsTree(t1->left, t2) || containsTree(t1->right, t2));
}

//updates bits i to j of n with m (length of m is guaranteed to be correct)
int updateBits(int n, int m, int i, int j){
	int allOnes = ~0;

	//forming left side of mask
	int left = allOnes << (j+1);

	//forming right side of mask
	int right = (1 << i) - 1;

	//form mask
	int mask = left | right;

	//clear bits i to j in n
	int maskedN = n & mask;

	//shift m into appropriate insert position
	int shiftedM = m << i;

	return maskedN | shiftedM;
}

//determines whether n is a power of 2
bool isPowerOf2(int n){
	if(n & (n-1) == 0)
		return true;
	return false;
}

//determines number of bits to flip to convert a to b
int bitFlipNeeded(int a, int b){
	int count = 0;
	for(int x = a^b; x != 0; x = x & (x-1))
		count++;
	return count;
}

//a magic index i is one such that arr[i] == i
//finds a magic index in arr using binary search (assuming non-distinct elements)
//if elements are distinct, we can limit our search on half of array depending on mid index
int magicIndex(int arr[], int size, int start, int end){
	if(end < start || start < 0 || end > size)
		return -1;
	int midIndex = (start + end) / 2;
	int midValue = arr[midIndex];
	if(midValue == midIndex)
		return midIndex;

	//searches left subarray
	int leftIndex = min(midIndex-1, midValue);
	int left = magicIndex(arr, size, start, leftIndex);
	if(left >= 0)
		return left;

	//searches right subarray
	int rightIndex = max(midIndex+1, midValue);
	int right = magicIndex(arr, size, rightIndex, end);
	return right;
}

//inserts c at pos in s
string insertCharAt(string s, char c, int pos){
	string start = s.substr(0, pos);
	string end = s.substr(pos);
	return start + c + end;
}

//computes all permutations of a string of unique characters
//O(n!) time
vector<string> computePerms(string s){
	vector<string> perms;
	//base case
	if(s.size() == 0){
		perms.push_back("");
		return perms;
	}

	//insert first char into each possible position
	char first = s.at(0);
	string remainder = s.substr(1);
	vector<string> words = computePerms(remainder);
	for(string word : words){
		for(int i = 0; i < words.size(); i++){
			string perm = insertCharAt(s, first, i);
			perms.push_back(perm);
		}
	}
	return perms;
}

//merges two sorted arrays(a is big enough to hold values of both a and b)
void merge(int a[], int b[], int sizeA, int sizeB){
	int indexA = sizeA - 1;
	int indexB = sizeB - 1;
	int indexMerged = sizeA + sizeB - 1;

	//merge a and b starting at the end to avoid shifting
	while(indexB >= 0){
		if(indexA >= 0 && a[indexA] > b[indexB]){
			a[indexMerged] = a[indexA];
			indexA--;
		}
		else if(a[indexA] < b[indexB]){
			a[indexMerged] = b[indexB];
			indexB--;
		}
		indexMerged--;
	}
}

//search a rotated sorted array to find the number x using a variation of binary search
//O(log n) time expected
int search(int arr[], int start, int end, int x){
	int mid = (start + end)/2;
	if(arr[mid] == x)
		return mid;
	if(end < start)
		return -1;

	//left is normally ordered
	if(arr[start] < arr[mid]){
		//search left
		if(arr[start] <= x && x <= arr[mid])
			return search(arr, start, mid-1, x);
		//search right
		else
			return search(arr, mid+1, end, x);
	}
	//right is normally ordered
	else if(arr[mid] < arr[end]){
		//search right
		if(arr[mid] <= x && x <= arr[end])
			return search(arr, mid+1, end, x);
		//search left
		else
			return search(arr, start, mid-1, x);
	}
	//left half all repeats
	else if(arr[start] == arr[mid]){
		//right half is different
		if(arr[mid] != arr[end])
			return search(arr, mid+1, end, x);
		//search both sides
		else{
			int res = search(a, start, mid-1, x);
			if(res == -1)
				return search(a, mid+1, end, x);
			else
				return res;
		}
	}
	return -1;
}

//swaps two integers
void swap(int& a, int& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

//finds contiguous sequence with largest sum in array (returns largest sum) (Kadane's algorithm)
int largestContSum(int arr[], int size){
	int largestSum = 0;
	int sum = 0;
	for(int i = 0; i < size; i++){
		sum += arr[i];
		if(sum > largestSum)
			largestSum = sum;
		else if(sum < 0)
			sum = 0;
	}
	return largestSum;
}

//prints all pairs of integers in the array that sums to the specified value
//this version of implementation uses array accesses but you can also use a hash map if space is not a problem (O(n))
//O(nlogn)
void printSumPairs(int arr[], int size, int sum){
	//sort array
	sort(arr, arr + size);
	
	int first = 0;
	int last = size-1;
	while(first < last){
		int cur = arr[first] + arr[last];
		//correct sum so print pair
		if(cur == sum){
			cout << arr[first] + " " + arr[last];
			first++;
			last--;
		}
		//increment first because need higher value
		else if(cur < sum)
			first++;
		//decrement last because need lower value
		else
			last--;
	}
}

//given two strings, find the shortest distance between them in the string array
int shortestDist(string s[], int size, string s1, string s2){
	//traverse array and save last position of word for each encounter and check distance between the two words
	//if dist is lower than min then dist becomes the new min
	int min = INT_MAX;
	int s1LastPos = -1;
	int s2LastPos = -1;
	string curWord;
	for(int i = 0; i < size; i++){
		curWord = s[i];
		if(curWord == s1){
			s1LastPos = i;
			int dist = s1LastPos - s2LastPos;
			if(s2LastPos >= 0 && dist < min)
				min = dist;
		}
		else if(curWord == s2){
			s2LastPos = i;
			int dist = s2LastPos - s1LastPos;
			if(s1LastPos >= 0 && dist < min)
				min = dist;
		}
	}
	return min;
}

//selection sort on array
void selectionSort(int arr[], int size){
	int minIndex;
	for(int i = 0; i < size-1; i++){
		minIndex = i;
		//finds minimum element in subarray
		for(int j = i+1; j < size; j++){
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}

		//swaps minimum element into appropriate position
		int tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}

//bubble sort
void bubbleSort(int arr[], int size){
	for(int i = 0; i < size-1; i++)
		for(int j = 0; j < size-i-1; j++)
			if(arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
}

//insertion sort
void insertionSort(int arr[], int size){
	int tmp, j;
	for(int i = 1; i < size; i++){
		tmp = arr[i];
		j = i-1;
		while(j >= 0 && tmp < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}
}

//calculate x^n
//O(logn) time
int power(int x, unsigned int n){
	if(n == 0)
		return 1;
	int tmp = power(x, n/2);
	if(n%2 == 0)
		return tmp * tmp;
	else
		return x * tmp * tmp;
}

//calculates the median of two sorted arrays
//assumptions: both a1 and a2 are sorted and have the same size
int median(int a1[], int a2[], int size){
	int i = 0;
	int j = 0;
	int m1 = -1;
	int m2 = -1;

	//count up to size only
	for(int count = 0; count <= size; count++){
		//save prev median
		m1 = m2;
		//all of a1 is less than a2[0]
		if(i == size){
			m2 = a2[0];
			break;
		}
		//all of a2 is less than a1[0]
		else if(j == size){
			m2 = a1[0];
			break;
		}
		else if(a1[i] < a2[j]){
			m2 = a1[i];
			i++;
		}
		else{
			m2 = a2[j];
			j++;
		}
	}
	return (m1 + m2) / 2;
}

//increment value of x by 1 without using operators (only bit manipulation)
int increment(int x){
	int one = 1;

	//flip bits until we find rightmost 0
	while(x & one){
		x ^= one;
		one <<= 1;
	}

	//flip rightmost 0 bit
	x ^= one;
	return x;
}

//rotate bits to the left by d bits
//assumming 32-bit int
int rotateLeft(int x, unsigned int d){
	return (x << d) | (x >> (32 - d));
}

//rotate bits to the right by d bits
//assumming 32-bit int
int rotateRight(int x, unsigned int d){
	return (x >> d) | (x << (32 - d));
}

//determines whether s can be rearranged to form a palindrome
bool canFormPalindrome(string s){
	//assuming ASCII-256 characters
	int count[256] = { 0 };

	for(int i = 0; i < s.size(); i++)
		count[s[i]]++;

	//count number of odd counts of char occurrences
	int oddCount = 0;
	for(int j = 0; j < 256; j++){
		if(count[j] & 1)
			oddCount++;
	}

	return (oddCount <= 1);
}

//partitions array around a pivot p, used for quicksort
int partition(int arr[], int start, int end){
	int pivot = arr[end];
	int i = start;
	for(int j = start; j < end; j++){
		if(arr[j] <= pivot){
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
		}
	}
	int t = arr[i];
	arr[i] = arr[end];
	arr[end] = t;
	return i;
}

//quicksort
void quickSort(int arr[], int start, int end){
	if(start < end){
		int p = partition(arr, start, end);
		quickSort(arr, start, p-1);
		quickSort(arr, p+1, end);
	}
}

//merge
void merge(int arr[], int start, int mid, int end){
	int s1 = mid - start + 1;
	int s2 = end - mid;
	int* left = new int[s1]; 
	int* right = new int[s2];
	int i, j, k;

	//copy data from arr into temp arrays
	for(i = 0; i < s1; i++)
		left[i] = arr[start + i];
	for(j = 0; j < s2; j++)
		right[j] = arr[mid + 1 + j];

	//merge from temp arrays into arr
	i = 0;
	j = 0;
	k = start;
	while(i < s1 && j < s2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	//copy remaining elements of temp arrays
	while(i < s1){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < s2){
		arr[k] = right[j];
		j++;
		k++;
	}

	delete left;
	delete right;
}

//mergesort
void mergeSort(int arr[], int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

//finds intersection point of two singly linked lists
//O(n+m) time, n and m are sizes of the linked lists
template<class N>
int findIntersection(listNode* h1, listNode* h2){
	if(h1 == nullptr || h2 == nullptr)
		return -1;

	set<listNode*> visited;
	listNode* temp = h1;
	//add traversed nodes of h1 to set
	while(temp != nullptr){
		visited.insert(temp);
		temp = temp->next;
	}

	temp = h2;
	//if found node of h2 in set then we found intersection
	while(temp != nullptr){
		if(visited.find(temp) != set::end)
			return temp->data;
		temp = temp->next;
	}
	return -1;
}

//finds longest increasing subsequence of arr
//b holds predecessor of arr[k] in longest subsequence
//c[i] holds index of last element of longest increasing subsequence of length i in arr
int* longestIncSeq(int arr[], int size){
	int* b = new int[size];
	int* c = new int[size+1];

	//binary search to find largest index <= len such that arr[c[index]] < arr[i]
	int len = 0;
	for(int i = 0; i < size; i++){
		int lo = 1;
		int hi = len;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			if(arr[c[mid]] < arr[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		//save values of predecessor and new ending element
		int newLen = lo;
		b[i] = c[newLen-1];
		c[newLen] = i;

		//found longer length
		if(newLen > len)
			len = newLen;
	}
	
	//construct longest increasing subsequence
	int* res = new int[len];
	int k = c[len];
	for(int n = len-1; n >= 0; n--){
		res[n] = arr[k];
		k = b[k];
	}
	delete b;
	delete c;
	return res;
}

//returns a random number from a list
//uses reservoir sampling technique
template<class N>
int findRandom(listNode* head){
	if(head == nullptr)
		return -1;

	//different seed each program
	srand(time(0));

	int res = head->data;
	listNode* temp = head;
	for(int i = 2; temp != nullptr; i++){
		//change res with probability of 1/i
		if(rand() % i == 0)
			res = temp->data;
		//move to next node
		temp = temp->next;
	}
	return res;
}

//finds the maximum path sum in a binary tree
template<class V>
int maxPathSum(treeNode* root, int& maxSum){
	//base case
	if(root == nullptr)
		return 0;

	//recur for left and right children
	left = maxPathSum(root->left, maxSum);
	right = maxPathSum(root->right, maxSum);

	//max for parent call, can only include at most 1 child
	int singleMax = max(max(left, right) + root->data, root->data);

	//max with this node as the root and no ancestor
	int max = max(singleMax, left + right + root->data);

	//save max result
	maxSum = max(maxSum, max);

	return singleMax;
}

//convert distinct elements in arr into zigzag format where a < b > c < d > e...
//O(n) time
void zigZag(int arr[], int size){
	for(int i = 0; i < size-1; i++){
		// i % 2 == 0 means relation is '<'
		if(i % 2 == 0){
			if(arr[i] > arr[i+1]){
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
		// relation is '>'
		else{
			if(arr[i] < arr[i+1]){
				int tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
	}
}

//finds starting index of maximum average subarray of length k
//O(n) time
int maxAvg(int arr[], int size, int k){
	//k is not valid
	if(k > size)
		return -1;

	//find sum of first k elements
	int sum = arr[1];
	for(int i = 1; i < k; i++)
		sum += arr[i];

	int maxSum = sum;
	int maxEnd = k-1;

	//find sum of remaining subarrays to find max
	for(int j = k; j < size; j++){
		int tmp = sum + arr[j] - arr[j-k];
		if(tmp > maxSum){
			maxSum = tmp;
			maxEnd = j;
		}
	}

	//return starting index
	return maxEnd - k + 1;
}

// countNDigitSum helper
int countNDigitSumHelper(int n, int sum, unsigned long long int arr[][50000]){
	// base case
	if(n == 0)
		return (sum == 0);

	// answer has already been computed
	if(arr[n][sum] != -1)
		return arr[n][sum];

	unsigned long long int ans = 0;

	// test all digits for each placeholder
	for(int i = 0; i < 10; i++)
		if(sum - i >= 0)
			ans += countNDigitSumHelper(n-1, sum-i, arr);

	arr[n][sum] = ans;
	return ans;
}

// count how many n-digit numbers whose digits add up to sum
// arr is the lookup memoization array to reduce time complexity of recursion
// 1 <= n <= 100 and 1 <= sum <= 50000
int countNDigitSum(int n, int sum){
	unsigned long long int lookup[100][50000];
	memset(lookup, -1, sizeof(lookup));

	unsigned long long int ans = 0;

	// ignores leading 0
	for(int i = 1; i < 10; i++)
		if(sum - i >= 0)
			ans += countNDigitSumHelper(n-1, sum-i, lookup);

	return ans;
}

//prints union of two sorted arrays
//O(n+m) time
void unionOfSortedArrays(int a[], int b[], int m, int n){
	int i = 0;
	int j = 0;

	// traverse both arrays until end of one array
	while(i < m && j < n){
		if(a[i] < b[j]){
			cout << a[i];
			i++;
		}
		else if(a[i] > b[j]){
			cout << b[j];
			j++;
		}
		else{
			cout << b[j];
			i++; j++;
		}
	}

	// print remaining elements of bigger array
	while(i < m)
		cout << a[i++];
	while(j < n)
		cout << b[j++];
}

//prints intersection of two sorted arrays
//O(n+m) time
void intersectionOfSortedArrays(int a[], int b[], int m, int n){
	int i = 0;
	int j = 0;
	
	while(i < m && j < n){
		if(a[i] < b[j])
			i++;
		else if(a[i] > b[j])
			j++;
		else{
			cout << a[i];
			i++;
			j++;
		}
	}
}

//prints the common nodes in two binary search trees
//O(h1 + h2) space, O(n) time
template<class V>
void commonNodesBSTs(treeNode* r1, treeNode* r2){
	// two stacks for inorder traversal of trees
	stack<treeNode*> s1, s2;

	while(true){
		if(r1){
			s1.push(r1);
			r1 = r1->left;
		}
		else if(r2){
			s2.push(r2);
			r2 = r2->left;
		}
		// both roots are null
		else if(!s1.empty() && !s2.empty()){
			r1 = s1.top();
			r2 = s2.top();

			// same keys
			if(r1->data == r2->data){
				cout << r1->data;
				s1.pop();
				s2.pop();

				// move to inorder successor
				r1 = r1->right;
				r2 = r2->right;
			}
			else if(r1->data < r2->data){
				// go to inorder successor of r1 tree to find match
				s1.pop();
				r1 = r1->right;
				r2 = nullptr;
			}
			else if(r1->data > r2->data){
				// go to inorder successor of r2 tree to find match
				s2.pop();
				r2 = r2->right;
				r1 = nullptr;
			}
		}
		// both roots and stacks are null/empty
		else
			break;
	}
}

//returns the next lexicographically greater string than s
string nextPermutation(string s){
	int size = s.size();
	int suffix = size - 1;
	// find beginning of latest suffix (sequence of non-increasing chars)
	while(suffix > 0 && s[suffix] <= s[suffix-1])
		suffix--;

	// greatest lexicographically ordered string
	if(suffix == 0)
		return "no such string exists";

	// find smallest order char that is greater than pivot (suffix-1) to swap
	int i = size - 1;
	while(s[i] <= s[suffix-1])
		i--;

	// swap pivot and s[i]
	char tmp = s[i];
	s[i] = s[suffix-1];
	s[suffix-1] = tmp;

	// reverse suffix and return string
	i = size - 1;
	while(suffix < i){
		tmp = s[suffix];
		s[suffix] = s[i];
		s[i] = tmp;
		i--;
		suffix++;
	}
	return s;
}

//returns the size of the largest subarray of a with sum of 0
//O(n) time using hashed table
int largestZeroSumSubarray(int a[], int n){
	map<int, int> prevSums;

	int sum = 0;
	int maxLen = 0;

	// traverse through array
	for(int i = 0; i < n; i++){
		sum += a[i];

		if(sum == 0)
			maxLen = i+1;

		// if sum is seen before then update maxLen if neccessary
		map<int, int>::iterator it = prevSums.find(sum);
		if(it != prevSums.end())
			maxLen = max(maxLen, i - it->second);
		else
			prevSums[sum] = i;
	}
	return maxLen;
}

// return the length of the longest common subsequence of two strings
// O(m + n)
// assuming m and n < 100
int longestCommonSubsequence(string x, string y, int m, const int n){
	int opt[100][100];
	
	// opt[i][j] contains LCS length of x[0...i-1] and y[0...j-1]
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				opt[i][j] = 0;
			else if(x[i-1] == y[j-1])
				opt[i][j] = opt[i-1][j-1] + 1;
			else
				opt[i][j] = max(opt[i-1][j], opt[i][j-1]);
		}
	}

	// LCS length for x[0...m-1] and y[0...n-1]
	return opt[m][n];
}

//returns maximum sum of a[i]*i with only rotations allowed on the array
//O(n) time
//if you write out equation for sum of each rotation (R(x) represents x rotations), you get
// R(x) - R(x-1) = total sum - (n * a[n-x])
int maxRotatedSum(int a[], int n){
	// compute sum of all array elements
	// and compute R(0)
	int aSum = 0;
	int curSum = 0;
	for(int i = 0; i < n; i++){
		aSum += a[i];
		curSum += i * a[i];
	}

	// initialize maxSum to R(0)
	int maxSum = curSum;

	// compute each rotation using prev R(x) and get maxSum
	for(int j = 1; j < n; j++){
		curSum = aSum + curSum - (n * a[n-j]);
		if(curSum > maxSum)
			maxSum = curSum;
	}
	return maxSum;
}
