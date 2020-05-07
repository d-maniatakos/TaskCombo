#include <iostream>
#include <sstream>

#ifdef _WIN32
#include <windows.h>          //Used when starting a Windows Task calling ShellExecute function from Windows API
#endif



class Task{
	private:
		std::string Name;
		std::string Location;
	
		
	public:
		Task();
		Task(const char* ,const char* );  
		Task(const char*);                //Constructor used when reading saved data from a file       
		
		void start();       //Start Application               
		
		/*Update Name/Location*/
		void update();
		
		void update_Name(const char* );
		void update_Location(const char* );
		
		/*Getters*/
		std::string get_Name(void);
		std::string get_Location(void);
		
		/*Convert to string for saving purposes*/
		std::string toString(void);
};
