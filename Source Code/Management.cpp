#include "Management.hpp"
#include <iterator>
using namespace std;

Management::Management(){
}

Management::Management(const char* obj){
	int i=0;   
	string temp;
	Session* tmp;
	
	while(obj[i]!='%'){
		temp.clear();
		
		
		/*Create next Session from saved data*/
		while(obj[i]!='}'){
			temp=temp+obj[i];
			i++;
			
		}
		temp=temp+obj[i];
		tmp=new Session(temp.c_str(),1);
		Sessions.push_back(tmp);
		i++;
	}
}

Management::~Management(){
	this->Clear();
}


list<Session*>	Management::return_Sessions(){
	return Sessions;
}

Session* Management::return_Session(int indicator){
	std::list<Session*>::iterator it;
	int counter=1;
	
	
	for(it = Sessions.begin(); it != Sessions.end(); it++){
    	if(indicator==counter)return *it;
    	counter++;
	}	
	
	return NULL;
}

void Management::add_Session(const char* nam){
	Session* temp;
	temp=new Session(nam);
	Sessions.push_back(temp); 
}

void Management::remove_Session(int indicator){
	int counter=1;
	
	for (list<Session*>::iterator i=Sessions.begin(); i!=Sessions.end(); i++) {
		if(indicator==counter){
			delete *it;        //De-Allocates space allocated for Session
			Sessions.erase(i);
			break;
		} 
    	counter++;
	}	
}

void Management::Clear(){
	list <Session*> :: iterator it; 
	
	for(it = Sessions.begin(); it != Sessions.end(); ++it){
		delete *it;        //De-Allocates space allocated for this Session
	}

	Sessions.clear();
}

string Management::toString(){
	string ret;
	list <Session*> :: iterator it; 
	for(it = Sessions.begin(); it != Sessions.end(); ++it){
		ret=ret+(*it)->toString();
	}
	
	return ret+"%";
}
