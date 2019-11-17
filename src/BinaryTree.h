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

			// the most left node
			// this could also be the node in the middle
			current = stack.peek();//check the top
			stack.pop();//take the top
			result.push_back(current->val);//push the current
			
			// move to the right side
			current = current->right;//move right
		}//end while
	return result;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
	//Homework also teken from geekforgeeks
		std::vector<T> result;

		if (root == nullptr) {
			return result;
		}//end if 
		// make two stacks 
		LinkedStack<TreeNode<T>*> s1, s2;

		//  
		s1.push(root);
		TreeNode<T>* node;

		// make sure that it not empty 
		while (!s1.isEmpty()) {
			// Pop an item from s1 and push it to s2 
			node = s1.peek();
			s1.pop();
			s2.push(node);

			// Push left and right children 
			// of removed item to s1 
			if (node->left)
				s1.push(node->left);
			if (node->right)
				s1.push(node->right);
		}


		while (!s2.isEmpty()) {
			node = s2.peek();
			s2.pop();
			result.push_back( node->val);
		}//end while
		return result;
    }

    virtual ~BinaryTree() {
        // homework
	node_delete(root);
    }
	
    TreeNode<T>* LowestCommonAncestor(TreeNode<T>* node, T value1, T value2) {
		if (node == nullptr) {
			return nullptr;
		}
		// check root
		if (node->val == value1 || node->val == value2) {
			return node;
		}
		// check both childrens
		TreeNode<T>* left = LowestCommonAncestor(node->left, value1, value2);
		TreeNode<T>* right = LowestCommonAncestor(node->right, value1, value2);		if (left != nullptr && right != nullptr) {
			return node;
		}
		if (left == nullptr && right == nullptr) {
			return nullptr;
		}
		return left == nullptr ? right : left;
    }

    T LCA(T node1, T node2) {
        // homework
	TreeNode<T>* node = LowestCommonAncestor(root, node1, node2);
	return node == nullptr ? -1 : node->val;
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
