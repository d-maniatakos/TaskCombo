#include <iostream>

class Task{
	private:
		std::string Name;
		std::string Location;
		
	public:
		Task(const char* ,const char* );   
		Task(const char*);                //Constructor used when reading saved data from a file       
		
		void start();       //Start Task               
		
		/*Update Name/Location*/
		void update_Name(const char*);
		void update_Location(const char*);
		
		/*Getters*/
		std::string get_Name();
		std::string get_Location();
		
		/*Convert to string for saving purposes*/
		std::string toString();
};
