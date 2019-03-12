#include <iostream>
#include "parent.hpp"
#include "teacher.hpp"
#include "list.hpp"

using namespace std;

/* 
 * List's constructor
 */
List::List(void) {
	first = NULL;   // there is no node in the list
}

/* 
 *  List's destructor
 *  Destroying list by removing the first node, until the list is empty
 */
List::~List(void) {
    while (first) removeFirst();
}

/*
 * Try to insert a parent at the start of the list, but the other parents ask him to go back.
 * Then, the parent will be inserted at the end of the list.
 */
void List::tryToInsertStart (Parent *p) {
    ListNode *newNode = new ListNode;
    newNode->parent = p;
    newNode->next = first;
    first = newNode; // place the newnode at the first place of the queue
    cout << "Parent " << p->getID() << " is going to wrong position in the queue." << endl;
    cout << "Crowd: Hey parent " << p->getID() << ". You have to go back at the end of the queue." << endl;
    first = first->next; // after arguing, we remove the first node
    delete newNode;
    insertEnd(p, false); // and we place it at the end of the queue
}

/* Insert a new node at the end of the list */
void List::insertEnd (Parent *p, bool flag) {
    ListNode *newNode = new ListNode;
    newNode->parent = p;
    newNode->next = NULL;
    if (!first) {
        first = newNode;
        last = newNode;
    }
    else {
        last->next = newNode;
        last = newNode;
    }
    if (flag) cout << "Parent " << p->getID() << " is patient." << endl;
}

/* Remove the first node of the list, if the list isn't empty */
void  List::removeFirst(void) {
    if (first) {
        ListNode *todel = first;
        first = first->next;
        delete todel->parent;
        delete todel;
    }
}

/* Print list contents */
void List::print(void) {
    ListNode *n = first;
    while (n != NULL) {
        n->parent->print();
        n = n->next;
    }
}

bool List::isEmpty(void) {
    return (first==NULL);
}

/* Find which parent is the one that should be informed by the teacher given as argument */
bool List::nextParentForBriefing(Teacher *t) {
    ListNode *temp = first;
    while (temp != NULL) {
        Parent *p = temp->parent;
        if (p->wantsToSeeTeacher(t->getID())) { // check if this parent wants to see teacher t
            cout << "Parent " << p->getID() << " will see teacher " << t->getID() << endl;
            // remove the parent from the queue and send it to the teacher
            t->setParent(p);
            if (temp == first) {
                first = first->next;
            }
            else {
                ListNode *prev = first;
                while (prev->next != temp) prev = prev->next;
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        temp = temp->next;
    }
    cout << "Noone is waiting for the teacher " << t->getID() << " for the moment" << endl;
    return false;
}