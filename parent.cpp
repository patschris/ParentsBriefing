#include <iostream>
#include <cstdlib>
#include <ctime>
#include "parent.hpp"

using namespace std;

Parent::Parent (int identity, int count)  {
    id = identity;
    totalTeachers = count;
}

Parent::~Parent (void) {
    if (array) 
        delete[] array;
}

/* 
 * Random generation of which teachers a parent wants to see 
 */
void Parent::subscribe(void) {
    array = new int[totalTeachers];
    for (int i=0; i<totalTeachers; i++) 
        array[i] = rand()%2;
    // each parent wants to see at least one teacher
    int sum = 0;
    for (int i=0; i<totalTeachers; i++) 
        sum += array[i];
    if (!sum) 
        array[rand()%totalTeachers] = 1;
}

void Parent::print(void) {
    cout << "Parent " << id << ": [";
    for (int i=0; i<totalTeachers; i++) {
        cout << array[i];
        if (i < totalTeachers-1) cout << " ";
    }
    cout << "]" << endl;
}

int Parent::getID(void) {
    return id;
}

/* 
 * Check if the briefing of a parent is finished 
 */
bool Parent::finished(void) {
    for (int i=0; i<totalTeachers; i++)
        if (array[i] == 1) 
            return false;
    cout << "Parent " << id << " finished the briefing" << endl;
    return true;
}

/* 
 * Check if a parent wants to be informed by the teacher tid 
 */
bool Parent::wantsToSeeTeacher (int tid) {
    return array[tid-1] == 1;
}

void Parent::informedByTeacher (int tid) {
    cout << "Parent " << id << " informed by Teacher " << tid << endl;
    array[tid-1]=0;
}