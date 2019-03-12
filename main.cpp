#include <iostream>
#include <cstdlib>
#include <ctime>
#include "parent.hpp"
#include "teacher.hpp"
#include "list.hpp"
#include "array.hpp"

using namespace std;

int main (void) {
    
    int i, j, N, K, L;
    List *l;
    Teacher **teachArray;
    Parent **parArray;

    /* Read from stdin */
    cout << "Please insert the amount of teachers: ";
    cin >> N;
    cout << "Please insert the amount of parents: ";
    cin >> K;

    srand (time(NULL));
    L = rand() % (K-1) + 1; // random L

    /* Create N teachers */
    teachArray = new Teacher*[N];
    for (i=0; i<N; i++) teachArray[i] = new Teacher(i+1);
    
    /* Create K parents */
    l = new List;
    parArray = new Parent*[K-L];
    for (i=0; i<K; i++) {
        Parent *p = new Parent (i+1, N);
        p->subscribe();
        if (i<L) l->insertEnd(p, false); // first L in the queue
        else parArray[i-L] = p; // rest K-L will placed in the queue later
    }
    cout << "Initial queue of parents" << endl;
    l->print();
    cout << "\nParents will come later" << endl;
    printArray(parArray, K-L);
    /* Simulation */
    int rest = K-L;
    while (!l->isEmpty()) {
        // each available teacher will serve a parent in the queue
        int counter = 0;
        for (i=0; i<N; i++) {
            if (teachArray[i]->isAvailable()) {
                cout << "Teacher " << teachArray[i]->getID() << " is available. ";
                bool flag = l->nextParentForBriefing(teachArray[i]);
                if (!flag) counter++;
            }
        }
        if (counter == N) {
            cout << "Break condition" << endl;
            break;
        }
        // if other parents is waiting (parArray), add some of them in the queue
        if (rest>0) {
            int num = rand()%rest+1;
            cout << num << " more parents added to queue" << endl;
            for (j=0; j<num; j++) l->insertEnd(parArray[j], false);
            leftRotate(parArray, num, K-L);
            rest = rest-num;
        }
        /* if a parent is informed by a teacher, check if he wants to see another teacher
         * Yes : put him back in the queue 
         * No  : send him home
         */
        for (i=0; i<N; i++) {
            teachArray[i]->informParent();
            Parent *p = teachArray[i]->getParent();
            teachArray[i]->setParent(NULL);
            if (p) {
                if (!p->finished()) {
                    if (rand()%10==0) l->tryToInsertStart(p);
                    else l->insertEnd(p, true);
                }
                else { 
                    delete p;
                }
            }
        }
    }

    /* free memory */
    for (i=0; i<N; i++) 
        if (teachArray[i]) delete teachArray[i];
    delete[] teachArray;
    for (i=0; i<K-L; i++) 
        if (parArray[i]) delete parArray[i];
    delete[] parArray;
    delete l;
    return 0;
}