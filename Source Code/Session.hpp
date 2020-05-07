#include <iostream> 
#include <list> 
#include <iterator>
#include "Task.hpp"

class Session{
	private:
		std::string Name;
		std::list <Task*> Tasks;
		
	public:
		Session();	
		Session(const char*);		//Constructor used when reading saved data from a file	
		~Session();
		
		void Console();
		
		void Start_Session();
		void Show_Tasks();
		
		void Add_Task();
		
		std::string get_Name();
		void update_Name();
		
		void Clear();
		
		/*Convert to string for saving purposes*/
		std::string toString();
		
};
	
