#include <iostream>
#include "parent.hpp"
#include "teacher.hpp"

using namespace std;

/*
 * Teacher's constructor
 */
Teacher::Teacher (int identity) : parent(NULL) {
    id = identity;
}

/*
 * Teacher's destructor
 */
Teacher::~Teacher (void) {}

/* 
 * Check if a parent is available to inform a parent 
 */
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
    if (parent) 
        parent->informedByTeacher(id);
}