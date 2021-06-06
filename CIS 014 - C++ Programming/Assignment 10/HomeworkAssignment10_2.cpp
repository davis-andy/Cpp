/**
 * Assignment #10.2
 * DUE: 11/17
 * NAME: Andy Davis
 * PURPOSE: Write the following program that outputs the closest common waypoint 
 *          from any given two path input
*/

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int v) : value(v), next(NULL) {}
};

class CIS14 {
public:
    Node* getClosestCommonWaypoint(Node* A, Node* B);
};

/**
 * FUNCTION NAME: 
 *      getClosestCommonWaypoint
 * PURPOSE: 
 *      Determine if two paths share a common path or not, and return that common path
 * PARAMETER:
 * 		Node* A: path of linked list
 *      Node* B: path of linked list
 * RETURN VALUE:
 * 		Node*: pointer address
*/

Node* CIS14::getClosestCommonWaypoint(Node* A, Node* B){
    Node* AA = A;
    Node* BB = B;
    int countA = 0;
    int countB = 0;
    int traverse;

    while (AA != nullptr){
        countA++;
        AA = AA -> next;
    }
    while (BB != nullptr){
        countB++;
        BB = BB -> next;
    }

    if (countA > countB){
        traverse = countA - countB;
        for (int i = 0; i < traverse; i++){
            if (A == nullptr) return NULL;
            A = A -> next;
        }
    }
    else {
        traverse = countB - countA;
        for (int j = 0; j < traverse; j++){
            if (B == nullptr) return NULL;
            B = B -> next;
        }
    }

    while (A != nullptr && B != nullptr){
        if (A == B) return A;
        A = A -> next;
        B = B -> next;
    }

}


int main() {
    Node a(1), a1(2), a2(3), a3(4), a4(5), a5(6);
    Node b(1), b1(2), b2(3), b3(4);
    a.next=&a1; a1.next=&a2; a2.next=&a3; a3.next=&a4; a4.next=&a5; a5.next=nullptr;
    b.next=&b1; b1.next=&b2; b2.next=&a4; b3.next=nullptr;

    CIS14 cis;
    cout << cis.getClosestCommonWaypoint(&a, &b) << endl; 
}