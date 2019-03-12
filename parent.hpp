#ifndef _parent_
#define _parent_

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

#endif