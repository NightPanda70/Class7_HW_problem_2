#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }
	//helper to destructor
	void node_delete(TreeNode<T>* node) {
		if (node) {//check if it is a node
		//go to left side of tree
		if (node->getLeft() != nullptr) {
			node_delete(node->getLeft());
		}//end if
		if (node->getRight() != nullptr) {//move write
			node_delete(node->getRight());
		}//end if
	     delete node;//delete node at the end
	    } //end if	
	}//end 
	
public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
	//homework, to be done iteratively
		//left root right is in order
		LinkedStack<TreeNode<T>*> stack; //make a new stack
		std::vector<T> result;//make a vector
		TreeNode<T>* current = root;//pointer to the root

		while (current != nullptr || !stack.isEmpty()) {

			// travel as left as possible
			while (current != nullptr) {
				stack.push(current); //push the current in stack
				current = current->left;//move to the left
			}//end inner while

			current = stack.peek();//go to the last  node oon stack
			stack.pop();//take the top
			result.push_back(current->val);//push stack val to result
			
			// move to the right side
			current = current->right;//move right
		}//end while
	return result;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
	//Homework also credit geekforgeeks
	//I changed it more on visual studio but I got a bug so kept this one
		std::vector<T> result;
		//check of root is not empty
		if (root == nullptr) {
			return result;
		}//end if 
		// make two stacks 
		LinkedStack<TreeNode<T>*> s1, s2;

		// push the current value of root
	    	//should be the root of tree
		s1.push(root);
		TreeNode<T>* node;

		// make sure that it not empty 
		while (!s1.isEmpty()) {
			// get value from stack1 and put it to two
			node = s1.peek();
			s1.pop();
			s2.push(node);

			// check node has value L || R 
			// put them in stack1 
			if (node->left)
				s1.push(node->left);
			if (node->right)
				s1.push(node->right);
		}

		//get values in stack2 and out them in result
		while (!s2.isEmpty()) {
			node = s2.peek();
			s2.pop();
			result.push_back( node->val);
		}//end while
		return result;
    }

    virtual ~BinaryTree() {
        // homework
	node_delete(root);//call helper method
    }
	
    TreeNode<T>* LowestCommonAncestor(TreeNode<T>* node, T value1, T value2) {
		if (node == nullptr) {
			return nullptr;
		}//end if
		// check base case if root is already LCA
		if (node->val == value1 || node->val == value2) {
			return node;
		}//end if
		// check the possable paths
		TreeNode<T>* left = LowestCommonAncestor(node->left, value1, value2);
		TreeNode<T>* right = LowestCommonAncestor(node->right, value1, value2);		if (left != nullptr && right != nullptr) {
			return node;
		}//end if
		if (left == nullptr && right == nullptr) {
			return nullptr;
		}//end if
		return left == nullptr ? right : left;
    }

    T LCA(T node1, T node2) {
        // homework
	TreeNode<T>* node = LowestCommonAncestor(root, node1, node2);
	return node == nullptr ? -1 : node->val;//return node value if found
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
