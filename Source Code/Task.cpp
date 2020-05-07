#include "Task.hpp"
using namespace std;


Task::Task(){
	/*Clear Input Buffer*/
	cin.clear();
	cin.ignore();
	
	cout<< "Enter Task Name     : ";
	getline(cin, Name); 
	cout<<endl;
	
	cout<< "Enter Task Location : ";
	getline(cin, Location); 
	cout<<endl;
}

Task::Task(const char* nam,const char* loc){
	Name=nam;
	Location=loc;
}	

Task::Task(const char* obj){
	char c;
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
}

void Task::update(){
	/*Clear Input Buffer*/
	cin.clear();
	cin.ignore();
	
	cout<< "Enter New Task Name     : ";
	getline(cin, Name);  
	cout<<endl;
	
	cout<< "Enter New Task Location : ";
	getline(cin, Location); 
	cout<<endl;
}

void Task::update_Name(const char* nam){
	Name=nam;
}
		
void Task::update_Location(const char* loc){
	Location=loc;
}

std::string Task::get_Name(void){
	return Name;
}
		
std::string Task::get_Location(void){
	return Location;
}

std::string Task::toString(){
	return Name+"|"+Location+"]";
}
		

