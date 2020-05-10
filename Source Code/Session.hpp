#include <iostream> 
#include <list> 
#include "Task.hpp"

class Session{
	private:
		std::string Name;
		std::list <Task*> Tasks;
		
	public:
		Session(const char*);	
		Session(const char*,bool);		//Constructor used when reading saved data from a file	
		~Session();
		
		void start_Session();
		std::list<Task*> return_Tasks();
		Task * return_Task(int);
		
		void add_Task(const char*,const char*);
		void remove_Task(int);
		
		std::string get_Name();
		void update_Name(const char*);
		
		void Clear();
		
		/*Convert to string for saving purposes*/
		std::string toString();
		
};	
