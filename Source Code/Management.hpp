#include "Session.hpp"

class Management{
	private:
		std::list <Session*> Sessions; //Sessions (created by the users) are put in this list
	public:
		Management();			  //Constructor used when there is no already saved data 	
		Management(const char*);  //Constructor used when reading saved data from a file	
		~Management(); 
		
		void Console();     
		
		void Show_Sessions();
		
		void Add_Session();
		
		void Clear();
		
		/*Convert to string for saving purposes*/
		std::string toString();
};
