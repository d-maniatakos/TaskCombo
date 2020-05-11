#include "Session.hpp"
#include <iterator>
using namespace std;

Session::Session(const char * nam){
	Name=nam;
}

Session::Session(const char* obj,bool saved){    //bool saved is used to  differentiate this constructor from the main one
	int i=0;
	int counter=0;
	string temp;
	Task* tmp;
	
	while(obj[i]!='!'){
		Name=Name+obj[i];
		i++;
	}
	
	i++;
	
	while(obj[i]!='}'){
		temp.clear();
		
		/*Create next Task from saved data*/
		while(obj[i]!=']'){
			temp=temp+obj[i];
			i++;
			
		}
		temp=temp+obj[i];
		tmp=new Task(temp.c_str());
		Tasks.push_back(tmp);
		i++;
		
	}
}

Session::~Session(){
	this->Clear();	
}

void Session::start_Session(){
	list <Task*> :: iterator it; 
    
    for(it = Tasks.begin(); it != Tasks.end(); ++it){
		(*it)->start();
	}
}

std::list<Task*> Session::return_Tasks(){
	return Tasks;
}

void Session::add_Task(const char* nam,const char* loc){
	Task* temp;
	temp=new Task(nam,loc);
	Tasks.push_back(temp); 
}

Task* Session::return_Task(int indicator){
	int counter=1;

	for (list<Task*>::iterator i=Tasks.begin(); i!=Tasks.end(); i++) {
		if(indicator==counter){
			return *i;
		} 
    	counter++;
	}	
	return NULL;
}

void Session::remove_Task(int indicator){
	int counter=1;

	for (list<Task*>::iterator i=Tasks.begin(); i!=Tasks.end(); i++) {
		if(indicator==counter){
			delete *i;             //Deletes space allocated for the Task to be deleted
			Tasks.erase(i);
			break;
		} 
    	counter++;
	}	
}

std::string Session::get_Name(){
	return Name;
}

void Session::update_Name(const char* nam){
	Name=nam;
}

void Session::Clear(){
	list <Task*> :: iterator it; 
	
	for(it = Tasks.begin(); it !=Tasks.end(); ++it){
		delete *it; 	//Deletes space allocated for the Task to be deleted
	}

	Tasks.clear();
}

string Session::toString(){
	string ret;
	list <Task*> :: iterator it; 
	ret=Name+"!";
	for(it = Tasks.begin(); it != Tasks.end(); ++it){
		ret=ret+(*it)->toString();
	}
	
	ret=ret+"}";
	
	return ret;
}
