#include "Session.hpp"
using namespace std;

Session::Session(){
	/*Clear Input Buffer*/
	cin.clear();
	cin.ignore();
	
	cout<< "Enter Session Name     : ";
	getline(cin, Name); 
	cout<<endl;
}

Session::Session(const char* obj){
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

void Session::Console(){
	while(1){
		cout<<endl<< "-----------------Session: "<<Name<<"---------------------------"<<endl<<endl;
		cout<<"1)Start Session"<<endl;
		cout<<"2)Show Tasks"<<endl;
		cout<<"3)Add Task"<<endl;
		cout<<"4)Delete Task"<<endl;
		cout<<"5)Update Task"<<endl;
		cout<<"6)Rename Session"<<endl;
		cout<<"7)Clear Session"<<endl;
		cout<<"8)Exit Session"<<endl<<endl;
		
		
		cout<<"Type a number between 1-8:";
		short int input;
		cin>>input;
		
		if(input<1 || input>8){
			cout<<endl<<"Please Enter a Valid Input" << endl <<endl;
			continue;
		}
	
	
		switch (input){
    		case 1:
				Session::Start_Session();
     		 break;
			
			case 2:
				Session::Show_Tasks();
     		 break;
     		 
     		 case 3:
     			Session::Add_Task();
     			cout<<"!Task Added!"<<endl<<endl;
     		 break;	

			case 4:{
				/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
				this->Show_Tasks();
				
				int choice;
				cout<<endl<<"Which Task do you want to remove(Type A Number)?";
				cin >> choice;
				int counter=1;
				for (list<Task*>::iterator i=Tasks.begin(); i!=Tasks.end(); i++) {
					if(choice==counter){
						Task* tmp=*i;
						delete tmp;
						Tasks.erase(i);
						break;
					} 
       				counter++;
				}	
			break;
			}
			
			case 5:{
				/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
				this->Show_Tasks();
				
				int choice;
				cout<<endl<<"Which Task do you want to update(Type A Number)?";
				cin >> choice;
				int counter=1;
				for (list<Task*>::iterator i=Tasks.begin(); i!=Tasks.end(); i++) {
					if(choice==counter){
						(*i)->update();
						break;
					} 
       				counter++;
				}
			
			break;
			
					
			}
			
			case 6:{
				this->update_Name(); 
				break;
			}
			
			case 7:{
				Tasks.clear(); 
				cout<<"!All Tasks Deleted!"<<endl<<endl;
				break;
			}
			
			case 8:{
				return;
			}
			
		}
		cout<<"----------------------------------------"<<endl;
	}
	
	cout<<endl<<endl;
}

void Session::Start_Session(){
	list <Task*> :: iterator it; 
    
    for(it = Tasks.begin(); it != Tasks.end(); ++it){
		(*it)->start();
	}
}

void Session::Show_Tasks(){
	list <Task*> :: iterator it; 
	int counter=0;
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"|            	  Task     	          |"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<endl;
    
    if(Tasks.empty()){
    	cout<<"There are currently no Tasks"<<endl;
    	return;
	}
    
	for(it = Tasks.begin(); it != Tasks.end(); ++it){
		cout << counter+1 << ")" <<  (*it)->get_Name() << endl;;
		counter++;
	}
 	
 	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void Session::Add_Task(){
	Task* temp;
	temp=new Task();
	Tasks.push_back(temp); 
}

std::string Session::get_Name(){
	return Name;
}

void Session::update_Name(){
	/*Clear Input Buffer*/
	cin.clear();
	cin.ignore();
	
	cout<< "Enter New Session Name     : ";
	getline(cin, Name);  
	cout<<endl;	
}

void Session::Clear(){
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
