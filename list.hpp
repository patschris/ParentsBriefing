#ifndef _list_
#define _list_

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