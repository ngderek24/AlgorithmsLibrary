#include "algorithms.h"
#include <queue>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>
#include <set>
using namespace std;

//Level order traversal using queue
//O(n) time complexity, n = number of nodes in tree
//visits node at each level and add children to queue similar to BFS
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
 
    while( *temp )
    {
        /*make sure that the string start with
          valid character (not space) only*/
        if (( word_begin == NULL ) && (*temp != ' ')){
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
	leftHeight = isBalanced(root->left, height);
	rightHeight = isBalanced(root->right, height);

	height = max(leftHeight, rightHeight) + 1;

	//not balanced
	if((leftHeight - rightHeight > 1) || (rightHeight - leftHeight > 1))
		return false;
	//balanced if subtrees and current tree are balanced
	else
		return (leftBal && rightBal);
}

//determines whether n1 and n2 are connected within the graph
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
	
	if(level == 0){
		listNode* temp = new listNode();
		temp->next = head->next;
		temp->data = root->data;
		head->next = temp;
	}

	createLevelLinkedList(root->right, head, level-1);
	createLevelLinkedList(root->left, head, level-1);
}

//determines whether a binary tree is a binary search tree using min/max algorithm
//O(n) time
template<class V>
bool isBST(treeNode* root, int min, int max){
	if(root == nullptr)
		return true;

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
	if(root->right != nullptr)
		return leftMostChild(root->right);
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
	if(node->right != nullptr)
		return leftMostChild(node->right);
	
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

	if(root->data == n1->data || root->data == n2->data)
		return root;

	treeNode* left = BT_LCA(root->left, n1, n2);
	treeNode* right = BT_LCA(root->right, n1, n2);

	if(left && right)
		return root;

	if(left != nullptr)
		return left;
	else
		return right;
}

//finds the lowest common ancestor of n1 and n2 in a binary search tree
//O(h) time
template<class V>
treeNode* BST_LCA(treeNode* root, treeNode* n1, treeNode* n2){
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
	if(t1 == nullptr && t2 == nullptr)
		return true;

	if(t1 == nullptr || t2 == nullptr)
		return false;

	if(t1->data != t2->data)
		return false;
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
	if(t1->data == t2->data){
		if(treeMatch(t1, t2))
			return true;
	}
	return (containsTree(t1->left, t2) || containsTree(t1->right, t2));
}
