#include <iostream>
#include "Console.hpp"
#include <fstream>
using namespace std;


int main() {
	
	ofstream myfile;
	
	/*Open save_info.txt file to read stored information*/
	ifstream ifs("save_info.txt");
	string content((istreambuf_iterator<char>(ifs)),(istreambuf_iterator<char>()));  //Gets saved information in string format
	
	/*If there is no saved information on "save_info.txt" file(the user has not already used the application or has deleted the save_info file)*/
	if (content.empty()){
		
		/*Welcome Message*/
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"Welcome ! For Instructions plese see README file ! Don't forget to use Exit & Save option to save your changes ! "<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
		
		Management a; 
		Main_Console(&a);
		
		/*Save changes*/
		myfile.open ("save_info.txt");
		myfile << a.toString();
		myfile.close();	
	}
	
	else{
		
		Management a(content.c_str());     //Call constructor importing the saved information
		Main_Console(&a);
		
		/*Save changes*/
		myfile.open ("save_info.txt");
		myfile << a.toString();
		myfile.close();
	}

	return 0;
}
