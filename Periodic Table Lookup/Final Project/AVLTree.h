//################################################## 
// File: AVLTree.h
// Author: Christian Salazar
// Description: This file contains the function prototypes and code for the AVL Tree class.
// Date: 12/8/2022
//##################################################

#ifndef AVLTREE
#define AVLTREE
#include "AVLNode.h"
#include <iostream>

using std::cout;
using std::endl;

template<class T>
class AVLTree
{
public:
	explicit AVLTree(const T& notFound);
	AVLTree(const AVLTree& rhs);
	~AVLTree();

	const T& findMin() const;
	const T& findMax() const;
	const T& contains(const T& data) const; // equivalent to find; returns the data
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T& data);
	void remove(const T& data);

	bool incrementCount(const T& data) const;

	const AVLTree& operator=(const AVLTree& rhs);

private:
	AVLNode<T>* mpRoot;
	const T mITEM_NOT_FOUND;

	const T& elementAt(AVLNode<T>* rt) const;
	void insert(const T& data, AVLNode<T>*& root) const;
	void remove(T data, AVLNode<T>*& root);
	AVLNode<T>* findMin(AVLNode<T>* t) const;
	AVLNode<T>* findMax(AVLNode<T>* t) const;
	AVLNode<T>* contains(const T& data, AVLNode<T>* t) const;
	void makeEmpty(AVLNode<T>*& t) const;
	void printTree(AVLNode<T>* t) const;
	AVLNode<T>* clone(AVLNode<T>* t) const;

	// AVL Manipulations
	int height(AVLNode<T>* t) const;
	int max(int lhs, int rhs) const;
	void rotateWithLeftChild(AVLNode<T>*& k2) const;
	void rotateWithRightChild(AVLNode<T>*& k1) const;
	void doubleWithLeftChild(AVLNode<T>*& k3) const;
	void doubleWithRightChild(AVLNode<T>*& k1) const;

};

//#################################################
// @par Name
// - AVLTree
// @purpose
// - Explicit constructor that sets mITEM_NOT_FOUND to argument
// @param [in] : const T& notFound
// - Value that mITEM_NOT_FOUND is set to
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLTree<T>::AVLTree(const T& notFound) :
	mITEM_NOT_FOUND(notFound), mpRoot(NULL)
{

}

//#################################################
// @par Name
// - AVLTree(const AVLTree &rhs)
// @purpose
// - Constructor that sets the reference to this object to the argument passed
// @param [in] : const AVLTree& rhs
// - Address of AVL Tree that the reference to this AVLTree will be set to
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLTree<T>::AVLTree(const AVLTree& rhs) :
	mITEM_NOT_FOUND(rhs.mITEM_NOT_FOUND), mpRoot(NULL)
{
	*this = rhs;
}

//#################################################
// @par Name
// - ~AVLTree()
// @purpose
// - Destructor that empties the tree.
// @param [in] :
// - None
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLTree<T>::~AVLTree()
{
	this->makeEmpty();
}

//#################################################
// @par Name
// - insert
// @purpose
// - Public function that calls the private function insert
// @param [in] : const T& data
// - Data to insert within the AVL Tree
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::insert(const T& data)
{
	this->insert(data, this->mpRoot);
}

//#################################################
// @par Name
// - remove
// @purpose
// - Public function that calls the private function remove
// @param [in] : const T &data
// - Data to remove from AVL Tree
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::remove(const T& data)
{
	this->remove(data, this->mpRoot);
}

//#################################################
// @par Name
// - remove
// @purpose
// - Removes the argument Tdata from the AVL Tree
// @param [in] : T data
// - Data to remove
// @param [in] : AVLNode<T>*& root
// - Node pointer being passed by reference used to traverse the tree
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::remove(T data, AVLNode<T>*& root)
{
	if (root == NULL)
	{
		return;
	}
	else if (data < root->mElement)
	{
		this->remove(data, root->mpLeft);
		if (height(root->mpRight) - height(root->mpLeft) > 1)
		{
			if (height(root->mpRight->mpRight) >= height(root->mpRight->mpLeft))
			{
				rotateWithRightChild(root);
			}
			else
			{
				doubleWithRightChild(root);
			}
		}
	}
	else if (data > root->mElement)
	{
		remove(data, root->mpRight);
		if (height(root->mpLeft) - height(root->mpRight) > 1)
		{
			if (height(root->mpLeft->mpLeft) >= height(root->mpLeft->mpRight))
			{
				rotateWithLeftChild(root);
			}
			else
			{
				doubleWithLeftChild(root);
			}
		}
	}
	else
	{
		if (root->mpLeft == NULL || root->mpRight == NULL) // Node with one or no children
		{
			AVLNode<T>* temp = root->mpLeft ? root->mpLeft : root->mpRight;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
			{
				*root = *temp;
			};
			delete temp;

		}
		else
		{
			AVLNode<T>* temp = findMin(root->mpRight);
			root->mElement = temp->mElement;
			remove(temp->mElement, root->mpRight);
		}
		if (root != NULL)
		{
			root->mHeight = max(height(root->mpLeft), height(root->mpRight)) + 1;
		}
	}
}

//#################################################
// @par Name
// - incrementCount
// @purpose
// - Inrements the mCount variable in the AVLNode
// @param [in] : const T& data
// - Used to search for particular Node to increment
// @return
// - bool
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
bool AVLTree<T>::incrementCount(const T& data) const
{
	return incrementCount(data, this->mpRoot);
}

//#################################################
// @par Name
// - findMin
// @purpose
// - Public function that calls the private function findMin
// @param [in] :
// - None
// @return
// - const T&
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
const T& AVLTree<T>::findMin() const
{
	return elementAt(findMin(this->mpRoot));
}

//#################################################
// @par Name
// - findMax
// @purpose
// - Public function that calls the private function findMax
// @param [in] :
// - None
// @return
// - const T&
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
const T& AVLTree<T>::findMax() const
{
	return elementAt(findMax(this->mpRoot));
}

//#################################################
// @par Name
// - contains
// @purpose
// - Public function that calls the private function contains
// @param [in] : const T& data
// - Data searched for in AVL Tree
// @return
// - const T&
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
const T& AVLTree<T>::contains(const T& data) const
{
	return elementAt(contains(data, this->mpRoot));
}

//#################################################
// @par Name
// - makeEmpty
// @purpose
// - Public function that calls the private function makeEmpty
// @param [in] :
// - None
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::makeEmpty()
{
	this->makeEmpty(this->mpRoot);
}

//#################################################
// @par Name
// - isEmpty
// @purpose
// - Checks to see if the AVLTree is empty
// @param [in] :
// - None
// @return
// - bool
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
bool AVLTree<T>::isEmpty() const
{
	return this->mpRoot == NULL;
}

//#################################################
// @par Name
// - printTree
// @purpose
// - Public function used to print values in the tree
// @param [in] :
// - None
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::printTree() const
{
	if (this->isEmpty())
	{
		cout << "The tree is currently empty." << endl;
	}
	else
	{
		printTree(this->mpRoot);
	}
}

// this begins the private section

//#################################################
// @par Name
// - operator=
// @purpose
// - Used to assign one AVL Tree to another
// @param [in] : const AVLTree& rhs
// - AVL Tree that is being assigned
// @return
// - bool
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
const AVLTree<T>& AVLTree<T>::operator=(const AVLTree& rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		this->mpRoot = clone(rhs.mpRoot);
	}
	return *this;
}

//#################################################
// @par Name
// - elementAt
// @purpose
// - Returns the mElement variable at Node passed in
// @param [in] : AVLNode<T>* t
// - Specific Node that function will return mElement of
// @return
// - const T&
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
const T& AVLTree<T>::elementAt(AVLNode<T>* t) const
{
	if (t == NULL)
	{
		return mITEM_NOT_FOUND;
	}
	else
	{
		return t->mElement;
	}
}

//#################################################
// @par Name
// - insert
// @purpose
// - Function used to insert values into the AVL Tree
// @param [in] : const T& data
// - Data to be inserted into AVL Tree
// @param [in] : AVLNode<T>*& root
// - Node pointer passed by reference used to traverse the AVL Tree to insert at proper location
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::insert(const T& data, AVLNode<T>*& root) const
{
	if (root == NULL)
	{
		root = new AVLNode<T>(data, NULL, NULL);
	}
	else if (data < root->mElement)
	{
		insert(data, root->mpLeft);
		if (height(root->mpLeft) - height(root->mpRight) == 2)
		{
			if (data < root->mpLeft->mElement)
			{
				rotateWithLeftChild(root);
			}
			else
			{
				doubleWithLeftChild(root);
			}
		}
	}
	else if (root->mElement < data)
	{
		insert(data, root->mpRight);
		if (height(root->mpRight) - height(root->mpLeft) == 2)
		{
			if (root->mpRight->mElement < data)
			{
				rotateWithRightChild(root);
			}
			else
			{
				doubleWithRightChild(root);
			}
		}
	}
	if (root != NULL)
	{
		root->mHeight = max(height(root->mpLeft), height(root->mpRight)) + 1;
	}
}

//#################################################
// @par Name
// - findMin
// @purpose
// - Returns the minimum value in the AVL Tree
// @param [in] : AVLNode<T>* t
// - Node pointer used to traverse down left subtree
// @return
// - AVLNode<T>*
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLNode<T>* AVLTree<T>::findMin(AVLNode<T>* t) const
{
	if (t == NULL)
	{
		return t;
	}

	while (t->mpLeft != NULL)
	{
		t = t->mpLeft;
	}
	return t;
}

//#################################################
// @par Name
// - findMax
// @purpose
// - Returns the maximum value in the AVL Tree
// @param [in] : AVLNode<T>* t
// - Node pointer used to traverse down right subtree
// @return
// - AVLNode<T>*
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLNode<T>* AVLTree<T>::findMax(AVLNode<T>* t) const
{
	if (t == NULL)
	{
		return t;
	}

	while (t->mpRight != NULL)
	{
		t = t->mpRight;
	}
	return t;
}

//#################################################
// @par Name
// - contains
// @purpose
// - Determines whether or not data is contained within AVL Tree
// @param [in] : const T& data
// - Data to be searched for in AVL Tree
// @param [in] : AVLNode<T>* t
// - Node pointer used to traverse AVL Tree recursively
// @return
// - AVLNode<T>*
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLNode<T>* AVLTree<T>::contains(const T& data, AVLNode<T>* t) const
{
	while (t != NULL)
	{
		if (data < t->mElement)
		{
			t = t->mpLeft;
		}
		else if (t->mElement < data)
		{
			t = t->mpRight;
		}
		else
		{
			return t;
		}
	}
	return NULL;
}

//#################################################
// @par Name
// - makeEmpty
// @purpose
// - Function that deletes all values in the tree, making the tree empty.
// @param [in] : AVLNode<T>*& t
// - Used to recursively traverse through AVL Tree to delete the Nodes
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::makeEmpty(AVLNode<T>*& t) const
{
	if (t != NULL)
	{
		makeEmpty(t->mpLeft);
		makeEmpty(t->mpRight);
		delete t;
	}
	t = NULL;
}

//#################################################
// @par Name
// - clone
// @purpose
// - Clones a particular Node, including its values
// @param [in] : AVLNode<T>* t
// - Node pointer that is going to be cloned
// @return
// - AVLNode<T>*
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLNode<T>* AVLTree<T>::clone(AVLNode<T>* t) const
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		return new AVLNode(t->mElement, clone(t->mpLeft), clone(t->mpRight), t->mHeight);
	}
}

//#################################################
// @par Name
// - height
// @purpose
// - Returns the height of the tree at a particular node
// @param [in] : AVLNode<T>* root
// - Node whose height is returned
// @return
// - int
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
int AVLTree<T>::height(AVLNode<T>* root) const
{
	return root == NULL ? -1 : root->mHeight;
}

//#################################################
// @par Name
// - max
// @purpose
// - Determines the maximum height between the height of two trees passed as arguments
// @param [in] : int lhs
// - Height of the left subtree
// @param [in] : int rhs
// - Height of right subtree
// @return
// - int
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
int AVLTree<T>::max(int lhs, int rhs) const
{
	return lhs > rhs ? lhs : rhs;
}

//#################################################
// @par Name
// - rotateWithLeftChild
// @purpose
// - Rotates AVL Tree Node with left child
// @param [in] : AVLNode<T>*& k2
// - Node that will get rotated with its left child
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& k2) const
{
	AVLNode<T>* k1 = k2->mpLeft;
	k2->mpLeft = k1->mpRight;
	k1->mpRight = k2;
	k2->mHeight = max(height(k2->mpLeft), height(k2->mpRight)) + 1;
	k1->mHeight = max(height(k1->mpLeft), k2->mHeight) + 1;
	k2 = k1;
}

//#################################################
// @par Name
// - rotateWithRightChild
// @purpose
// - Rotates AVL Tree Node with right child
// @param [in] : AVLNode<T>*& k1
// - Node that will get rotated with its right child
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& k1) const
{
	AVLNode<T>* k2 = k1->mpRight;
	k1->mpRight = k2->mpLeft;
	k2->mpLeft = k1;
	k1->mHeight = max(height(k1->mpLeft), height(k1->mpRight)) + 1;
	k2->mHeight = max(height(k2->mpRight), k1->mHeight) + 1;
	k1 = k2;
}

//#################################################
// @par Name
// - doubleWithLeftChild
// @purpose
// - First rotates its left child with its right child, then node k3 with the new left child
// @param [in] : AVLNode<T>*& k3
// - Node that rotations are based off of
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T>*& k3) const
{
	rotateWithRightChild(k3->mpLeft);
	rotateWithLeftChild(k3);
}

//#################################################
// @par Name
// - doubleWithRightChild
// @purpose
// - First rotates its right child with its left child, then node k1 with the new right child
// @param [in] : AVLNode<T>*& k1
// - Node that rotations are based off of
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T>*& k1) const
{
	rotateWithLeftChild(k1->mpRight);
	rotateWithRightChild(k1);
}

//#################################################
// @par Name
// - printTree
// @purpose
// - Prints all the values in the tree, including the mCount
// @param [in] : AVLNode<T>* t
// - Node pointer whose values are printed
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
void AVLTree<T>::printTree(AVLNode<T>* t) const
{
	if (t != NULL)
	{
		printTree(t->mpLeft);
		cout << t->mElement << " - " << t->mCount << endl;
		printTree(t->mpRight);
	}
}

#endif