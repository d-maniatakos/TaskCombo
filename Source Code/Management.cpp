#include "Management.hpp"
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
		tmp=new Session(temp.c_str());
		Sessions.push_back(tmp);
		i++;
	}
}

Management::~Management(){
	this->Clear();
}

void Management::Console(){
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
			cout<<endl<<"Please Enter a Valid Input" << endl <<endl;
			continue;
		}
	
	
		switch (input){
    		case 1:{
				/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
				this->Show_Sessions();
				if(Sessions.empty())break;
				int choice;
				cout<<endl<<"Choose Session(Type A Number):";
				cin >> choice;
				int counter=1;
				for (list<Session*>::iterator i=Sessions.begin(); i!=Sessions.end(); i++) {
					if(choice==counter){
						(*i)->Console();
						break;
					} 
       				counter++;
				}				
     		 break;
			}
			case 2:
				this->Show_Sessions();
     		break;
     		 
     		case 3:
     			this->Add_Session();
     			cout<<"!Session Added!"<<endl<<endl;
     		break;	
			
			case 4:{
				/*Clear Input Buffer*/
				cin.clear();
				cin.ignore();
				
				this->Show_Sessions();
				if(Sessions.empty())break;
				
				int choice;
				cout<<endl<<"Which Session do you want to remove(Type A Number)?";
				cin >> choice;
				int counter=1;
				for (list<Session*>::iterator i=Sessions.begin(); i!=Sessions.end(); i++) {
					if(choice==counter){
						Sessions.erase(i);
						break;
					} 
       				counter++;
				}	
			break;
			}
			
			case 5:{
				this->Clear();
				cout<<"!All Sessions Deleted!"<<endl<<endl;
				break;
			}
			
			case 6:{
				return;
				break;
			}
		}
		cout<<"--------------------------------------------"<<endl;
	}
}


void Management::Show_Sessions(){
	list <Session*> :: iterator it; 
	int counter=0;
    
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"|               Sessions               |"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<endl;
    
    if(Sessions.empty()){
    	cout<<"There are currently no Sessions"<<endl;
    	return;
	}
    
	for(it = Sessions.begin(); it != Sessions.end(); ++it){
		cout << counter+1 << ")" <<  (*it)->get_Name() << endl;;
		counter++;
	}
 	
 	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void Management::Add_Session(){
	Session* temp;
	temp=new Session();
	Sessions.push_back(temp); 
}

void Management::Clear(){
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
