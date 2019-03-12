#include <iostream>
#include "school.hpp"

using namespace std;

Teacher::Teacher (int identity) : id (identity), parent(NULL) {
    cout << "Teacher " << id << " constructed" << endl;
}

Teacher::~Teacher (void) {
    cout << "Teacher " << id << " destructed" << endl;
}

/* check if a parent is available to inform a parent */
bool Teacher::isAvailable (void) {
    return parent==NULL;
}

int Teacher::getID (void) {
    return id;
}

void Teacher::setParent (Parent *p) {
    parent = p;
}

Parent * Teacher::getParent (void) {
    return parent;
}

void Teacher::informParent (void) {
    if (parent) parent->informedByTeacher(id);
}