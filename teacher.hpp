#ifndef _teacher_
#define _teacher_

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

#endif