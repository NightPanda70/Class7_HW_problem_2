#include "BinaryTree.h"
#include "gtest/gtest.h"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree, traverseInOrder) {
	TreeNode<int>* root = new TreeNode<int>(3);
	root->setLeft(new TreeNode<int>(1));
	root->setRight(new TreeNode<int>(5));

	root->getLeft()->setLeft(new TreeNode<int>(2));
	root->getLeft()->setRight(new TreeNode<int>(7));

	root->getRight()->setLeft(new TreeNode<int>(5));

	//BinaryTree<int>* tree = new BinaryTree<int>(root);
	BinaryTree<int> tree(root);
	std::vector<int> answer{ 2, 1, 7, 3, 5, 5 };
	std::vector<int> makeOrder;
	makeOrder = tree.traverseInOrder();
	ASSERT_EQ(makeOrder, answer);
}//end TEST

TEST(tree, traversePostOrder) {
	//make tree
	TreeNode<int>* root = new TreeNode<int>(3);
	root->setLeft(new TreeNode<int>(1));
	root->setRight(new TreeNode<int>(5));

	root->getLeft()->setLeft(new TreeNode<int>(2));
	root->getLeft()->setRight(new TreeNode<int>(7));

	root->getRight()->setLeft(new TreeNode<int>(5));

	BinaryTree<int> t2(root);

	//check if the the tree is an the right order
	std::vector<int> answer{ 2,7,1,5,5,3 };
	std::vector<int> order;
	order = t2.traversePostOrder();
	ASSERT_EQ(order, answer);
}//end TEST

TEST(tree, LCA) {
	TreeNode<int>* root = new TreeNode<int>(4);
	root->setLeft(new TreeNode<int>(8));
	root->setRight(new TreeNode<int>(6));

	root->getLeft()->setLeft(new TreeNode<int>(7));
	root->getLeft()->setRight(new TreeNode<int>(3));

	root->getRight()->setLeft(new TreeNode<int>(2));
	root->getRight()->setRight(new TreeNode<int>(9));
	BinaryTree<int> tree(root);

	//test the return value
	ASSERT_EQ(tree.LCA(4, 4), 4);
	ASSERT_EQ(tree.LCA(7, 7), 7);
	ASSERT_EQ(tree.LCA(7, 3), 8);
	ASSERT_EQ(tree.LCA(8, 6), 4);
	ASSERT_EQ(tree.LCA(3, 2), 4);
}//end test