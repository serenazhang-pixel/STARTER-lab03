// tests for intbst.cpp

#include <iostream>
#include "intbst.h"
using namespace std;

int main(){

    IntBST one, two;

    one.insert(50);
    one.insert(30);
    one.insert(20);
    one.insert(40);
    one.insert(70);
    one.insert(60);
    one.insert(80);

    two.insert(1);
    two.insert(2);

    // tests
    
    cout << "preorder:" << endl; 
        cout << "bst one: ";
        one.printPreOrder();
        cout << endl;
        cout << "bst two: ";
        two.printPreOrder();
        cout << endl;
        cout << "postorder" << endl;
        cout << "bst one: ";
        one.printPostOrder();
        cout << endl;
        cout << "bst two: ";
        two.printPostOrder();
        cout << endl;
    cout << "inorder: " << endl;
        cout << "bst one: ";
        one.printInOrder();
        cout << endl;
        cout << "bst two: ";
        two.printInOrder();
        cout << endl;

    cout << "sum one: " << one.sum() << endl;
    cout << "sum two: " << two.sum() << endl;

    cout << "count one: " << one.count() << endl;
    cout << "count two: " << two.count() << endl;
    cout << "bst one contains 30? " << (one.contains(30) ? "Y" : "N") << endl;
    cout << "bst one contains 10? " << (one.contains(10) ? "Y" : "N") << endl;
    cout << "bst two contains 2? " << (two.contains(2) ? "Y" : "N") << endl;

    cout << "bst one: predecessor of 80 is: " <<
	    one.getPredecessor(80) << endl;
    cout << "bst one: successor of 20 is: " <<
	    one.getSuccessor(20) << endl;
        
    one.remove(60);
    one.remove(30);

    cout << "bst one contains 30? " << (one.contains(30) ? "Y" : "N") << endl;
    cout << "bst one contains 60? " << (one.contains(60) ? "Y" : "N") << endl;
    
    return 0;
}
