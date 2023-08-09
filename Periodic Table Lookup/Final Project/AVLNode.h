//################################################## 
// File: AVLNode.h
// Author: Christian Salazar
// Description: This file contains the function prototypes and code for the AVL Node class.
// Date: 12/8/2022
//##################################################

#ifndef AVLNODE
#define AVLNODE

template<class T>
class AVLNode
{
	T mElement;
	int mCount;
	AVLNode* mpLeft;
	AVLNode* mpRight;

	AVLNode(const T& theElement, AVLNode* lt, AVLNode* rt, int h = 0);
	int mHeight;

	template<class T>
	friend class AVLTree;
};

//#################################################
// @par Name
// - AVLNode
// @purpose
// - Constructor that in initializes private member variables
// @param [in] : const T& theElement
// - Data that the node holds
// @param [in] : AVLNode* lt
// - Node pointer to left subtree
// @param [in] : AVLNode* rt
// - Node pointer to right subtree
// @param [in] : int h
// - Contains the height of the tree at this node
// @return
// - None
// @par References
// - Unit 6 Lecture
// @par Notes
// - None
//#################################################
template<class T>
AVLNode<T>::AVLNode(const T& theElement, AVLNode* lt, AVLNode* rt, int h)
	: mElement(theElement), mpLeft(lt), mpRight(rt), mHeight(h), mCount(1)
{

}



#endif