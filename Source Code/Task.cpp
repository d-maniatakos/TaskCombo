#include "Task.hpp"

#ifdef _WIN32
	#include <windows.h>          //Used when starting a Windows Task calling ShellExecute function from Windows API
#endif

#ifdef linux
	#include <stdlib.h>           //Used when starting a Linux Task calling system() function
#endif

using namespace std;


Task::Task(const char* nam,const char* loc){
	Name=nam;
	Location=loc;
}	

Task::Task(const char* obj){
	char c=0;
	int i=0;
	
	/*Read Name*/
	while(obj[i]!='|'){
		Name=Name+obj[i];
		i++;
	}
	i++;
	
	/*Read Location*/
	while(obj[i]!=']'){
		Location=Location+obj[i];
		i++;
	}
}

void Task::start(){
	const char * c = Location.c_str();
	#ifdef _WIN32
		ShellExecute(NULL, "open",c, NULL, NULL, SW_SHOWDEFAULT);
	#endif	
	
	#ifdef linux
		system(c);          
	#endif
}

void Task::update_Name(const char* nam){
	Name=nam;
}
		
void Task::update_Location(const char* loc){
	Location=loc;
}

std::string Task::get_Name(){
	return Name;
}
		
std::string Task::get_Location(){
	return Location;
}

std::string Task::toString(){
	return Name+"|"+Location+"]";
}
