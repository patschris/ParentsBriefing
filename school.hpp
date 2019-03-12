#ifndef _school_
#define _school_

class Parent {
    private:
        int id;             // parent's id
        int *array;         // indicates which teacher wants the parent to see
        int totalTeachers;  // total amount of teachers == size of the array
    public:
        Parent(int, int);
        ~Parent(void);
        void subscribe(void);
        void print(void);
        int getID(void);
        bool finished(void);
        bool wantsToSeeTeacher (int);
        void informedByTeacher (int);
};

class Teacher {
    private:
        int id;             // teacher's id
        Parent *parent;     // indicates the parent that the teacher is briefing at the moment  
    public:
        Teacher(int);
        ~Teacher(void);
        bool isAvailable(void);
        int getID(void);
        void setParent(Parent *);
        Parent * getParent(void);
        void informParent(void);
};

struct ListNode {
    Parent *parent;
    ListNode *next;
};

class List {
    private:
        ListNode *first;        // first node of the list
        ListNode *last;         // last node of the list
    public:
        List(void);
        ~List(void);
        void tryToInsertStart (Parent *);
        void insertEnd (Parent *, bool);
        void removeFirst(void);
        void print(void);
        bool isEmpty(void);
        bool nextParentForBriefing(Teacher *);
};

#endif