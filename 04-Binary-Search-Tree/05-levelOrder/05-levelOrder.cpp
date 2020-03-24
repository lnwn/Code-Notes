﻿// 05-levelOrder.cpp : 层序遍历
// 2020/03/23

#include <iostream>

using namespace std;

// binary search tree
template<typename Key, typename Value>
class BST {

private:
	struct Node {
		Key key;
		Value value;
		Node *left;
		Node *right;

		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node *root;// 根节点
	int count;// 树中节点个数

public:
	// 构造函数，默认构造一棵空树
	BST() {
		root = NULL;
		count = 0;
	}
	// 析构函数
	~BST() {
		// x todo ~BST()
		destroy(root);
	}
	// 返回节点个数
	int size() {
		return count;
	}

	// 向树中插入一个新（key，value）
	void insert(Ke.y key, Value value) {
		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}
	// serach 的返回值类型可以有多种，但 value* 更优
	// 直接返回 node 没有将定义的数据结构进行隐藏
	// 返回 value 则前提是这个 value 已存在
	// 返回 value* ，node空时则返回空，否则返回 value
	Value* search(Node* node, Key key) {
		if (node == NULL)
			return NULL;
		if (key == node->key)
			return &(node->value);// 返回 vlaue 对应的地址
		else if (key < node->value)
			return search(node->left, key);
		else
			return search(node->right, key);
	}
	// 前序遍历
	void preOrder() {
		preOrder(root);
	}
	// 中序遍历
	void inOrder() {
		inOrder(root);
	}
	// 后序遍历
	void postOrder() {
		postOrder(root);
	}
	// 层序遍历
	void levelOrder() {
		queue<Node*> q;
		q.push(root);// 入队根节点
		while (!q.empty()) {
			Node *node = q.front();// 取队首元素
			q.pop();// 出队

			cout << node->key << endl;// 这里可对当前节点执行其他操作
			
			// 将其子节点入队
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
private:
	// 使用递归算法
	// 返回插入新节点后二叉搜索树的根
	Node* insert(Node *node, Key key, Value value) {
		if (node == null) {
			count++;
			return new Node(key, value);
		}
		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else
			node->right = insert(node->right, key, value);
		return node;
	}
	bool contain(Node* node, Key key) {
		if (node == NULL)
			return false;
		if (key == node->key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}
	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	void inOrder(Node* node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->key << endl;
			inOrder(node->right);
		}
	}
	void postOrder(Node* node) {
		if (node != NULL) {
			postOrder(node->left);
			postOrder(node->right);
			cout << node->key << endl;
		}
	}
	void destroy(Node* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
};
int main() {
	return 0;
}
