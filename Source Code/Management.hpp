#include "Session.hpp"

class Management{
	private:
		std::list <Session*> Sessions; //Sessions (created by the users) are put in this list
	public:
		Management();			  //Constructor used when there is no already saved data 	
		Management(const char*);  //Constructor used when reading saved data from a file	
		~Management(); 
		   
		std::list<Session*>	return_Sessions();
		Session* return_Session(int);
		
		void add_Session(const char*);
		void remove_Session(int);
		
		void Clear();
		
		/*Convert to string for saving purposes*/
		std::string toString();
};
