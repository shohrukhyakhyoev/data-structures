

// Created by Shohrukhbek Yakhyoev. Date: 01/11/2022


#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

class BinarySearchTree {
public:

	void inorder(Node* current)
	{
		if (current) {
			inorder(current->left);
			cout << current->data << " ";
			inorder(current->right);
		}	
		return;
	}

	void postorder(Node* current)
	{
		if (current) {
			inorder(current->left);
			inorder(current->right);
			cout << current->data << " ";
		}
		return;
	}

	void preorder(Node* current)
	{
		if (current) {
			cout << current->data << " ";
			inorder(current->left);
			inorder(current->right);
		}
		return;
	}
    

	void reverse(Node* current)
	{
		if (current) {
			inorder(current->right);
			cout << current->data << " ";
			inorder(current-> left);
		}
		return;
	}


	void insert(Node*& root, int value) {
        Node* tree = root;
		if (tree == nullptr) {
            // once we reach null node, we allocate memory for it
            // and set its data to value (here using constructor)
            // also we set its right & left ptr to their children
            // to nullptr as they are new nodes & thus, don't
            // have children yet!
            tree =  new Node(value);
            tree->right = tree->left = nullptr;
            root = tree;
		}
		else if (value >= tree->data) {
            // if value is bigger or equal than data of current node, then we
            // search null node in right subtree because bigger values
            // are inserted in the right subtree (same nodes too, but it
            // depends on implementation requirements. If it is ok to have
            // duplications, then go to the right if value == tree->data)!
            insert(tree->right, value);
		}
		else {
            // if value is smaller than data of current node, then we
            // search null node in left subtree because smaller values
            // are inserted in the right subtree!
            insert(tree->left, value);
		}
	}

	string search(Node* current, int target) {
		if (current == nullptr) {
            // current is null means we meet null pointer while searching target
            // without finding target. Thus, func execution stops & returns "False".
			return "False";
		}
		else if (current->data == target) {
            // If data of node is target that means we found the node successfully.
            // thus, we return "True".
			return "True";
		}
		else if (current->data > target) {
            // if data of current node is bigger than target, there is no reason to
            // search in right subtree (side) of current, as values of nodes in right
            // side is bigger than current itself. Thus, we go to left subtree, where
            // values of nodes are smaller than current.
			return search(current->left, target);
		}
		else {
            // else block is executed when data < target. So we go to right side (subtree)
            // because in the left subtree values are even smaller than data and so, than target.
            // In the right subtree we can get the node with data target. In the left, never!
			return search(current->right, target);
		}
	}

	void deleteNode(Node*& root, int value) {

        Node* parent = nullptr;

        Node* cur = root;

        // find node with given value and its parent
        searchTheNode(cur, value, parent);

        if (!cur) {
            // if node with given key is not found: then node DNE.
            return;
        }

        // Case 1: node to be deleted has no children (leaf node)
        if (!cur->left && !cur->right)
        {
            if (cur != root)
            {
                // we set parent's left to nullptr if node was left child
                // if right child, then set parent's right to nullptr.
                if (parent->left == cur) {
                    parent->left = nullptr;
                } else {
                    parent->right = nullptr;
                }
            } else {
                // if the tree has only a root node, set it to null
                root = nullptr;
            }

            // deallocate the memory
            delete(cur);
        }

        // Case 2: node to be deleted has two children
        else if (cur->left && cur->right) {

            // find its inorder predecessor node
            Node* predecessor = findMaxNode(cur->left);

            // store predecessor value
            int val = predecessor->data;

            // recursively delete the predecessor
            deleteNode(cur->left, val);

            // copy value of the predecessor to the current node
            cur->data = val;
        }

        // Case 3: node to be deleted has only one child
        else {
            // choose a child node
            Node* child = (cur->left) ? cur->left : cur->right;

            // if the node to be deleted is not a root node, set its parent
            // to its child
            if (cur != root)
            {
                if (parent->left == cur) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }

            // if the node to be deleted is a root node, then set the root to the child
            else {
                root = child;
            }

            // deallocate the memory
            delete(cur);
        }
    }

    Node* findMaxNode(Node* cur) {
        while (cur->right != nullptr) {
            cur = cur->right;
        }
        return cur;
    }

    void searchTheNode(Node*& cur, int value, Node*& parent) {

        while (cur != nullptr && cur->data != value) {

            parent = cur;

            if (value < cur->data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }
};

int main()
{
	int value;
	BinarySearchTree tree;
	Node* _root = new Node(6);

	tree.insert(_root, 9);
	tree.insert(_root, 1);
    tree.insert(_root, 4);
    tree.insert(_root, 3);

	cout << "\nInorder traverse:  ";
	tree.inorder(_root);
	cout << endl;

	cout << "\nValue to search: ";
	cin >> value;
	cout << "Value is in the list: " << tree.search(_root, value);
	cout << endl;

	cout << "\nValue to delete: ";
	cin >> value;
    tree.deleteNode(_root, value);

	cout << "\nInorder traverse after deletion:  ";
	tree.inorder(_root);
	cout << endl << endl;

	return 0;
}