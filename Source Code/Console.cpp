#include "Console.hpp"
using namespace std;

void show_Session_List(list<Session*> l){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"|               Sessions               |"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<endl;
	
	if(l.empty()){
		cout<<endl<<"There are currently no Sessions!"<<endl;
		return;
	}
	
	int counter=1;
	
	for (list<Session*>::iterator i=l.begin(); i!=l.end(); i++) {
		cout<<counter<<") " <<(*i)->get_Name()<<endl;			
		counter++;		
	}	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void show_Task_List(list<Task*> l){
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"|                 Tasks                |"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<endl;
	
	if(l.empty()){
		cout<<endl<<"There are currently no Tasks in this Session"<<endl;
		return;
	}
	
	int counter=1;
	
	for (list<Task*>::iterator i=l.begin(); i!=l.end(); i++) {
		cout<<counter<<") " <<(*i)->get_Name()<<endl;	
		counter++;				
	}	
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void Session_Console(Session *s){
	
	while(1){
		cout<<endl<< "---------Session: "<<s->get_Name()<<"-----------"<<endl<<endl;
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
				s->start_Session();
			break;
			
			case 2:
				show_Task_List(s->return_Tasks());
			break;
     		 
     		case 3:{
				string name;
				string location;
			 
			 	/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
				cout<< "Enter Task Name     : ";
				getline(cin, name); 
				
			
				cout<< "Enter Task Location : ";
				getline(cin, location); 
				
				s->add_Task(name.c_str(),location.c_str());
				
     			break;	
			}
			
			case 4:{
				show_Task_List(s->return_Tasks());
    			if(s->return_Tasks().empty())break;
				
				cout<<"Chose a Task to delete (type a number) :";	
    			int input;
    			cin >> input;
    			s->remove_Task(input);	
    			
				break;
			}
			
			case 5:{
				cout<<"Chose a Task to update (type a number) :";	
    			int input;
    			cin >> input;
    			
    			if(s->return_Task(input)==NULL){
    				cout<<endl<<"There is not such Task!"<<endl;
    				break;
				}
    			
    			string name;
    			string location;
    			
    			/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
    			cout<< "Enter New Task Name     : ";
				getline(cin, name); 
				
				cout<< "Enter New Task Location : ";
				getline(cin, location); 
				
				s->return_Task(input)->update_Name(name.c_str());
				s->return_Task(input)->update_Location(location.c_str());
				break;
			}
			
			case 6:{
				string name;
    			
    			/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
    			cout<< "Enter New Session Name     : ";
				getline(cin, name); 
				
				s->update_Name(name.c_str());
				break;
			}
			
			case 7:{
				s->Clear();
				break;
			}
			
			case 8:{
				return;
				break;
			}
			
		}
		cout<<"-------------------------------------------------"<<endl;
	}
}

void Main_Console(Management *m){
	
	while(1){
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	    cout<<"|                Main Window               |"<<endl;
	    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	    cout<<endl;
		cout<<"1)Enter Session"<<endl;
		cout<<"2)Show Sessions"<<endl;
		cout<<"3)Add Session"<<endl;
		cout<<"4)Delete Session"<<endl;
		cout<<"5)Delete All Sessions"<<endl;
		cout<<"6)Exit & Save Changes"<<endl<<endl;
		
		
		cout<<"Type a number between 1-6:";
		short int input;
		cin>>input;
		
		if(input<1 || input>6){
			cout<<endl<<"Please Enter a Valid Input!" << endl <<endl;
			continue;
		}
	
			
		switch (input){
    		
    		case 1:{
    				
    			show_Session_List(m->return_Sessions());
    			if(m->return_Sessions().empty())break;
				
				cout<<"Chose a Session (type a number):";
    			
    			
				int counter=1;
    			int input;
    			cin >> input;
    			
    			if(m->return_Session(input)!=NULL)Session_Console(m->return_Session(input));
				else cout<<endl<<"There is not such a Session!"<<endl;	
    			
				break;
			}
    		
			case 2:
				show_Session_List(m->return_Sessions());	
			break;
     		
			case 3:{
     			/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				string name;
				cout<< "Enter Session Name     : ";
				getline(cin, name); 
				cout<<endl;
				m->add_Session(name.c_str());
				cout<<endl<<"New Session Added!"<<endl;
				break;
			} 
     		
			case 4:{
    			show_Session_List(m->return_Sessions());
    			if(m->return_Sessions().empty())break;
				
				cout<<"Chose a Session to delete (type a number) :";	
    			int counter=1;
    			int input;
    			cin >> input;
    			m->remove_Session(input);	
    			
				break;
			}
			
			case 5:{
				m->Clear();
				cout<<endl<<"All Existing Sessions Deleted!" <<endl<<endl;;	
				break;
			} 
     		 
			case 6:
				return;
			break;	
		}
		
		cout<<"--------------------------------------------"<<endl;
	}
}
