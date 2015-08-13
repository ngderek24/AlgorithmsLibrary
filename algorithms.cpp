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
