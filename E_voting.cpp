#include<iostream>                     //{
#include<fstream>                     // {        
#include<vector>                      // {       HERE I HAVE USE THE LIBRARIES 
#include<string>                      // {    
#include<sstream>                     // {

using namespace std;                       

vector<string> ID; // Initialised string vector ID


void read_file(string fname) //Function to read file with name = fname and store in ID
{
    string word, line;
    fstream file(fname, ios::in); //Creates fstream object named file by taking data from fname in 'in' mode

    vector<string> row_data; //Initialises string vector row_data

    while(getline(file,line)) //Picks a line from the file and stores it in line
    {
        stringstream row(line); //Creates stringstream object named row which takes data from line

        while(getline(row, word, ',')) //Gets a word from row and stores it in word delimited by a ','
        {
            row_data.push_back(word); //appends word to row_datat
        }
        ID.push_back(row_data[0]); //appends the first column (ID) of row_data to ID

		row_data.clear(); //Clears row_data
    }
}

int main()
{
	cout<<"\n\tVOTING MANAGEMENT SYSTEM\n";
	string name;
	int i,j,id;
	bool Id_exist=0;

	fstream file; //creates fstream object named file


	cout<<"\n\nEnter Your Name : ";
	getline(cin,name); //takes cin as whole line and stores it in name
    cout << endl;

	cout<<"\nEnter Your ID : ";
	cin>>id; 
	
    cout << endl;

    read_file("ID's.txt");

//checks whether inputted id exists in the file or not (i.e has voted or not)
    for (int i = 0; i < ID.size(); i++)
    {
        if(ID[i]==to_string(id))
        {
            Id_exist=1;
        }
    }

	if(Id_exist==1)
	{
		cout<<"\nYou are not allowed to vote again you have voted already ";
		return 0;
	}
    else
    {
        file.open("ID's.txt",ios::app|ios::in); //opens ID's.txt file to append
        
		file << "\n" << id << "," << name << endl; //adds id and name to the file`
        file.close();
    }

	int c=0,party;
	do
	{
        c++;

        cout<<"\nChoose a Party to cast your Vote \n\n";

        cout<<"1-PTI"<<endl;

        cout<<"2-PMLN"<<endl;

        cout<<"3-PPP"<<endl;
        
        cin>>party;
	}while((party<1 || party>3));

	int count;
    int votes;
//opens party file and reads votes and adds 1 to it
	if(party==1)
	{
		file.open("PTI.txt",ios::in);
		file>>count;
		file.close();

		file.open("PTI.txt",ios::out);
		file<<count+1;
		file.close();
	}
	else if(party==2)
	{
		file.open("PMLN.txt",ios::in);
		file>>count;
		file.close();

		file.open("PMLN.txt",ios::out);
		file<<count+1;
		file.close();
	}
	else if(party==3)
	{
		file.open("PPP.txt",ios::in);
		file>>count;
		file.close();

		file.open("PPP.txt",ios::out);
		file<<count+1;
		file.close();
	}
	cout<<"\nYour vote has been casted successfully :) "<<endl;
//asks whether to show the results or not
	char res;
	cout<<"\nDo you want to see the results (y/n)\n";
	cin>>res;

	int pti,pmln,ppp;
//reads results from file and checks which party has won
	if(res=='y'|| res=='Y')
	{
		file.open("PTI.txt",ios::in);
		file>>pti;
		file.close();

		file.open("PMLN.txt",ios::in);
		file>>pmln;
		file.close();

		file.open("PPP.txt",ios::in);
		file>>ppp;
		file.close();

		cout<<"\nNumber of votes casted to each party "<<endl<<endl;
		cout<<"PTI = "<<pti<<endl;
		cout<<"PMLN = "<<pmln<<endl;
		cout<<"PPP = "<<ppp<<endl;

        if(pti>pmln && pti>ppp)
        {
            cout << "PTI has "<<pti<< " votes and are the winners." << endl;
        }
        else if(pti>pmln && pti==ppp)
        {
            cout << "PTI and PPP have "<<pti<< " votes and are tied as winners." << endl;
        }
        else if(pti==pmln && pti>ppp)
        {
            cout << "PTI and PMLN have "<<pti<< " votes and are tied as winners." << endl;
        }
        else if(pmln>pti && pmln>ppp)
        {
            cout << "PMLN has "<<pmln<< " votes and are the winners." << endl;
        }
        else if(pmln>pti && pmln==ppp)
        {
            cout << "PMLN and PPP have "<<pmln<< " votes and are tied as winners." << endl;
        }
        else if(ppp>pti && ppp>pmln)
        {
            cout << "PPP has "<<ppp<< " votes and are the winners." << endl;
        }

        if (ppp==pmln && pmln==pti)
        {
            cout << "PPP, PMLN and PTI are tied as winners with " <<pmln<< " votes."<<endl;
        }
		return 0;
	}
	else
	cout<<"\nThank You for casting Vote "<<endl;
}
//run program again to vote again and it will be casted.
//show results  to end and get the result of election
//show result can be used to know the result after every vote as well