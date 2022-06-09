#include <iostream>
#include <fstream>
#include <string>
// Abdul wahab
using namespace std;

class Encryption
{
	
public:
	string text;
	ifstream ifile;
	ofstream ofile;
	
void encryption()

{
		ifile.open("data.txt");
	
	if(!ifile.is_open())
{
	cout<<"Error data.txt file is missing! "<<endl;   //Abdul Wahab
	
	//return 0;
	}
	
cout<<"Do you want to encrypt or decrypt"<<endl;
cout<<" 1) Encrpt"<<endl<<endl;;
cout<<" 2) Decrypt"<<endl<<endl;

	string choice;
	cin>>choice;
	while(choice!= "1" && choice!= "2")
	{
		cout<<"Invalid Input Enter Again"<<endl;
		cin>>choice;
		cout<<endl;
	}
	cin.ignore();
	
	
	ofile.open("Ceaser_data.txt");
	if(!ofile.is_open()){
		
		cout<<"Error opening the output file! "<<endl;
		
	}
	 // cout<<"Enter the text"<<endl;
	
	
	// cin.ignore();
	
  //	getline(cin,text);
   getline(ifile,text);
   ifile>>text;
     ofile<<"Input Text :"<<text<<endl;
	cout<<"Enter the key"<<endl;
	
	int key;
	
	cin>>key;
	ofile<<"Key :"<<key<<endl;
	
	if(choice=="1")
	{
	                                               // Abdul Wahab
	cout<<"\t\t\t\t Encryption "<<endl;
	
	
	key = key;
}
	else if(choice=="2")
{
  cout<<"\t\t\t\t Decryption "<<endl;
	key = 26-key;
}
	ofile<<"Output Text: ";
// traverse text
    for (int i=0;i<text.length();i++)
    {
    	if(isalpha(text[i]))
    	{
    		// lets assume by default character is upper case ASCI 65= A
    		int offset =65;
    		
    		//  if character is lowercase ofset it by 97
    		if(islower(text[i]))
    		offset=97;
    		
      char  result = char(int(text[i]+key-offset)%26 +offset);
      
      cout<<result;
      ofile<<result;
		}
		else  // if character is not a-z or A-Z just output as it is
    {
		
   	cout<<text[i];
   	ofile<<text[i];
   
		
}

    }
    	ofile.close();
    	ifile.close();
}

 void bruteforce()
 {
 		ifile.open("data.txt");
	
	if(!ifile.is_open())
{
	cout<<"Error data.txt file is missing! "<<endl;
	
	//return 0;
	}
 	// string text in public
 	cin.ignore();	
//	getline(cin,text);
   getline(ifile,text);
   
   	ofile.open("brute_force.txt");
	if(!ofile.is_open()){
		
		cout<<"Error opening the output file! "<<endl;
		
	}
 	
 	cout<<"Applying all possible Keys:"<<endl;
 	for(int j=26,i=0; j>=0,i<26; j--,i++)
 
 	{
	 
	 // Abdul Wahab
     cout<<"Key used: "<<i<<"  ";
     ofile<<"Key used: "<<i<<" ";
 
 	for(int i=0; i<text.length(); i++)
 	{
 		
 		if(isalpha(text[i])) {
		 
 		int offset =65;	
   	//  if character is lowercase ofset it by 97
    	if(islower(text[i]))
    	
		
    	offset=97;
    		
      char  result = char(int(text[i]+j-offset)%26 +offset);

 	  cout<<result;
      ofile<<result;
		}
		else  // if character is not a-z or A-Z just output as it is
    {
		
   	cout<<text[i];
   	ofile<<text[i];
   
		
}

	 }
	 ofile<<endl;
	 cout<<endl;
 }

}

};

int main()
{



	
	
	Encryption obj,obj2;
	string menu;
	
         // cin>>menu;
	string restart;


	
	do{
		
	cout<<"\t\t\t\t Ceaser Cipher Tool "<<endl;
	cout<<"\t\t\t\t Created by ( Abdul Wahab Naveed khurram )"<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t Which Operation do you want to perfrom"<<endl;
	cout<<"1) Encrypt/Decrypt file"<<endl;
	cout<<"2) Brute Force Attack (You must have encrypted data in data.txt)"<<endl;
		cout<<endl;
		cout<<"Enter Valid Choice "<<endl;
	cin>>menu;
	
while(menu!="1" && menu!="2")
{
  cout<<"invalid input Enter Again"<<endl;
  
  cin>>menu;

}


	if (menu =="1")
	{
		obj.encryption();
	}
   else if(menu =="2")
   {
   
	obj.bruteforce();
}

cout<<endl;
cout<<"Do you want to  Restart Program 'y' or 'Y' "<<endl;
cin>>restart;

}
while(restart=="y"|| restart =="Y");
	return 0;
  

}

