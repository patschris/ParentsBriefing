# ParentsBriefing

## Description
Simulation of a parent's briefing in secondary education. 
The briefing is done in a room where N teachers are waiting for parents. 
Parents want to be informed by some (not necessarily all) of the teachers. 
Parents are waiting at the entrance of the room to form a queue.
When a parent comes, is added at the end of the queue.
When a briefing is completed by a teacher, the teacher is re-available and the parent returns to the end of the queue or 
leaves if he don't wish to be informed by other teachers.
Accidentally, a parent may misunderstand and try to return to the beginning of the queue.
Then, the other parents complain and the parent returns to the end of the queue.
<br/> <br/>

![Briefing](https://github.com/patschris/ParentsBriefing/blob/master/Briefing.PNG)

## Makefile
 - `make` to compile
 - `make clean` to delete the object files and the executable
 - `make run` to execute the program
 - `make check` to run valgrind to check for memory leaks
