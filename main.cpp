#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
struct Node
{
	string name, date, room_type;                
	int room_no; 
	Node *next;
	Node *prev;
};
class RoomAllotment
{
	Node *head;
	string x , z, r;
	int y;
	public:
		RoomAllotment()
		{
			head=NULL;
			x="";
			y=0;
			z="";
			r="";
		}
    	void CreateNode()
	    {
	    	if(head==NULL)
	    	{
    	    	Node *newer= new Node;

				cout<<"  Enter the Room Number/ Room ID: ";
	    	    cin>>y;
		        newer->room_no=y;

				string f_name = "" , l_name ="";
	    	    cout<<"  Enter the first name of the Costumer: ";
		        cin>>f_name;
		        cout<<"  Enter the last name of the Costumer: ";
		        cin>>l_name;

				newer->name = f_name + " " + l_name;

    		    cout<<"  Enter the date of Room Allotment (DD/MM/YYYY): ";
	    	    cin>>z;
		        newer->date=z;

				cout<<"  Enter the Room Type(Single , Double , Twin): ";
	    	    cin>>r;
		        newer->room_type=r;

		        newer->next=NULL;
		        newer->prev==NULL;
		        head=newer;
		        
		        cout<<"\n\n--------------------------------------------Room Alloted with Room ID : "<<head->room_no<<" -------------------------------------------------------------\n\n"<<endl;
		    }
		    else
		    {
			
		        Node *newer= new Node;
	    	    cout<<"  Enter the Room Number/ Room ID: ";
	    	    cin>>y;
		        newer->room_no=y;

				string f_name = "" , l_name ="";
	    	    cout<<"  Enter the first name of the Customer: ";
		        cin>>f_name;
		        cout<<"  Enter the last name of the Customer: ";
		        cin>>l_name;

				newer->name = f_name + " " + l_name;

    		    cout<<"  Enter the date of Room Allotment (DD/MM/YYYY): ";
	    	    cin>>z;
		        newer->date=z;

				cout<<"  Enter the Room Type(Single , Double , Twin): ";
	    	    cin>>r;
		        newer->room_type=r;
		        
		        newer->next=NULL;
		        
		    	Node *temp=head;
		    	while(temp->next!=NULL)
		    	{
		    		temp=temp->next;
		    	}
		    	temp->next=newer;
		    	newer->prev=temp;
		    	cout<<"\n\n---------------------------Room Alloted with Room ID : "<<newer->room_no<<" ---------------------------------------\n\n"<<endl;
			}
		}
    	void Display()
    	{
	    	Node *temp=head;
	    	int count=0;
	    	
	    	if(temp==NULL)
	    	{
		    	cout<<"  No Rooms Alloted... Please book first"<<endl;
		    	cout<<"  Thanks"<<endl;
	    	}
	    	else
	    	{
	    		BubbleSort();
	    		cout<<"\t\t| ROOM ID |\t\t"<<"\t\t| NAME |\t\t"<<"\t\t| Date |\t\t"<<"\t\t| ROOM TYPE |"<<endl<<endl;
	        	while(temp!=NULL)
	        	{
	        	    count++;
					cout<<"\t\t| "<<temp->room_no<<" |\n";
		        	cout<<"\t\t| "<<temp->name<<" |\n";
		        	cout<<"\t\t| "<<temp->date<<" |\n";
					cout<<"\t\t| "<<temp->room_type<<" |\n";
    		    	temp=temp->next;		
	        	}
	        	cout<<"\n\n\t\tTotal rooms alloted: "<<count<<endl<<endl;
	    	}
    	}
    	int Search()
    	{
    		bool check=false;
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name."<<endl;
	    	cout<<"  Press 2 if you want to Search By Room ID."<<endl;
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;
	  
	    	if(command==1 && temp!=NULL)
	    	{
	    		cout<<"  Enter the Name to Search: ";
	    		cin>>x;
		    	while(temp!=NULL)
		    	{
		        	if(temp->name==x)
		        	{
		        		cout<<"***********"<<endl;
						cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
		        	temp=temp->next;
	        	}
	        	if(check==false)
	        	{
	        		cout<<"  Name Not Found"<<endl;
				}
	    	}
	    	else if(command==2)
	    	{
	    		cout<<"  Enter the Room ID to Search: ";
	    		cin>>y;
				
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->room_no==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		check=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
				if(check==false)
				{
					cout<<"  Room ID Not Found"<<endl;	
				}	
	    	}
	    }
	    void DeleteAllRecords()
	    {
	    	Node *temp=head;
	    	Node *temp2;
	    	if(head==NULL)
	    	{
	    		cout<<"  No data to delete at the moment"<<endl;
	    		cout<<"***********"<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<"  Successfully Deleted All records"<<endl;
	    		cout<<"***********"<<endl;
			}
		}
		
		int DeleteRecordBySearch()
    	{
    		
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Room ID"<<endl;
	    	int command;
	    	cout<<"  Enter the Command: ";
	    	cin>>command;
	  
	    	if(command==1)
	    	{
	    		bool Dcheck=false;
	    		cout<<"  Enter the Name to Delete: ";
	    		cin>>x;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->name==x)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	            	int command;
	            	cout<<"  Press 1 to Delete the Record: ";
	            	cin>>command;
	            	if(command==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	            		temp=temp->next;
	            		delete temp1;
	        		
	            		temp->prev=NULL;
	            		head=temp;
	            		cout<<"  Record Deleted Successfully"<<endl;
			    	}
			    	else if(command==1 & temp->next==NULL)
			    	{
			    		temp->prev->next=NULL;
			    		delete temp;
			    		cout<<"  Record Deleted Successfully"<<endl;
			    	}
			    	else if(command==1)
			    	{
			    		Node *temp1;
			    		temp1=temp;
			    		temp->prev->next=temp1->next;
			    		temp->next->prev=temp1->prev;
			    		delete temp1;
			    		cout<<"  Record Deleted Successfully"<<endl;	
			    	}
			    	else
			    	{
			    		cout<<"  You Enter Wrong Command ... Try Again"<<endl;
		    		}
	            }
	            else if(Dcheck==false)
				{
					cout<<"  Record of This Name Not Found."<<endl;
			    }  
	    	}
	    	else if(command==2)
	    	{
	    		bool Dcheck=false;
	    		cout<<"  Enter the Room ID to Delete: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->room_no==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		Dcheck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Dcheck==true)
	        	{
	            	int command;
	            	cout<<"  Press 1 to Delete the Record: ";
	        	    cin>>command;
    	        	if(command==1 & temp==head)
	            	{
	            		Node *temp1;
	            		temp1=temp;
	        	    	temp=temp->next;
	        		    delete temp1;
	        		
    	        		temp->prev=NULL;
	            		head=temp;
	            		cout<<"  Record Deleted Successfully"<<endl;
			    	}
				    else if(command==1 & temp->next==NULL)
    				{
	    				temp->prev->next=NULL;
		    			delete temp;
			    		cout<<"  Record Deleted Successfully"<<endl;
				    }
				    else if(command==1)
    				{
	    				Node *temp1;
		    			temp1=temp;
			    		temp->prev->next=temp1->next;
				    	temp->next->prev=temp1->prev;
					    delete temp1;
		    			cout<<"  Record Deleted Success Fully"<<endl;	
			    	}
				    else
				    {
				    	cout<<"  You Enter Wrong Command ... Try Again"<<endl;
				    }
	            }
	            else if(Dcheck==false)
				{
					cout<<"  Record with this Room ID Not Found."<<endl;
				}
	    	}
	    	else
	    	{
	    		cout<<"  You enter wrong Command"<<endl;
			}
	    }
	    void BubbleSort()
        {
        	Node *temp=head;
            Node *i,*j;
            string n;
            int r_no;
            if(temp=NULL)
            {
            	cout<<"  No room is Alloted till now"<<endl;
			}
			else
			{
                for(i=head;i->next!=NULL;i=i->next)
                {
                    for(j=i->next;j!=NULL;j=j->next)
                    {
                        if(i->room_no>j->room_no)
		                {
                            r_no=i->room_no;
                            i->room_no=j->room_no;
                            j->room_no=r_no;
             
			                n=i->name;
                            i->name=j->name;
                            j->name=n;

                            n=i->date;
                            i->date=j->date;
                            j->date=n;

							n=i->room_type;
                            i->room_type=j->room_type;
                            j->room_type;
                        }
                    }
                }
            }
        }
        
        
        int EditRecord()
    	{
	    	Node *temp=head;
	    	cout<<"***********"<<endl;
	    	cout<<"  Press 1 if you want to Search By Name"<<endl;
	    	cout<<"  Press 2 if you want to Search By Room ID"<<endl;
	    	int Ecommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Ecommand;
	  
	    	if(Ecommand==1)
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Name to Edit: ";
	    		cin>>x;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->name==x)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}				
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Record: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {
	        		    cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter current date of allotment: ";
	            		cin>>z;
						cout<<"  Enter new Room Type alloted: ";
	            		cin>>r;
	        		
	            		temp->name=x;
	        	    	temp->date = z;
						temp->room_type = r;
	        		
	        		    cout<<"  Record Edited Successfully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
	    	        }
	    	    }
	    	    else if(Echeck==false)
	    	    {
	    	    	cout<<"  Record Not Found"<<endl;
				}
	        }
	    	else if(Ecommand==2)
	    	{
	    		bool Echeck=false;
	    		cout<<"  Enter the Room ID to Edit: ";
	    		cin>>y;
	    		while(temp!=NULL)
	    		{
	    	    	if(temp->room_no==y)
		        	{
		        		cout<<"***********"<<endl;
		        		cout<<"  Room ID: "<<temp->room_no<<endl;
		        		cout<<"  Name: "<<temp->name<<endl;
		        		cout<<"  Date:"<<temp->date<<endl;
						cout<<"  Room Type:"<<temp->room_type<<endl;
		        		cout<<"***********"<<endl;
		        		Echeck=true;
		        		break;
		        	}
			        temp=temp->next;
	        	}
	        	if(Echeck==true)
	        	{
	            	int command;
	        	    cout<<"  Press 1 to Edit the Record: ";
	            	cin>>command;
	        	    if(command==1)
	        	    {   
						cout<<"  Enter New Name: ";
    	        		cin>>x;
	            		cout<<"  Enter current date of allotment: ";
	            		cin>>z;
						cout<<"  Enter new Room Type alloted: ";
	            		cin>>r;
	        		
	            		temp->name=x;
	        	    	temp->date = z;
						temp->room_type = r;
	        		
	        		    cout<<"  Record Edited Successfully"<<endl;
			    	}
			    	else
			    	{
					    cout<<"  You Enter Wrong Command"<<endl;
	    	        }
	        	}
	        	else if(Echeck==false)
	        	{
	        	    cout<<"  There is No Record with this Room ID."<<endl;
	            }
	        }
	        else
			{
			    cout<<"  You Enter Wrong Command ... Try Again"<<endl;
			}
	    }
	
    	
    	void OflineSave()
    	{
    		Node *temp=head;
    		ofstream myfile ("RoomAllotment.txt");
            if (myfile.is_open())
            {
            	while(temp!=NULL)
	        	{
					myfile<<temp->room_no<<endl;
	        	    myfile<<temp->name<<endl;
		        	myfile<<temp->date<<endl;
					myfile<<temp->room_type<<endl;
    		    	temp=temp->next;		
	        	}
                myfile.close();
                Structure();
            }
            else
            {
            	cout<<"  Thanks file is empty."<<endl;
			}
		}
		
		void reopenroom()
		{
			bool isEmpty;
			ifstream myfile ("RoomAllotment.txt");
            if (myfile.is_open() & myfile.peek() != EOF)
            {
                int i=0;
                while(getline(myfile,x))
                {	
                    if(i % 2 == 0)
					{
						if(head==NULL)
	                    {
    	                  Node *newer= new Node;
                          newer->name=x;
		         
	                      newer->next=NULL;
	                      newer->prev==NULL;
	                      head=newer;
		                }
						else
						{
							Node *newer= new Node;
							
							newer->name=x;
							newer->next=NULL;
							
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	temp->next=newer;
		                	newer->prev=temp;		
						} 
                    }
                   else
                    {
                    	Node *temp=head;
                    	if(temp->room_no==0)
                    	{
                    		
                    		 stringstream convert(x);
			       	         convert>>y;
                             temp->room_no=y;
						}
						else
						{
							Node *temp=head;
		                	while(temp->next!=NULL)
		                	{
		                		temp=temp->next;
		                	}
		                	
		                	stringstream convert(x);
			       	        convert>>y;
		                	temp->room_no=y;
							
						}
                       
				    }
                    i++;
                }
            	myfile.close();
            }
            else
            {
            	cout<<"  File is Empty so Cannot open...Sorry"<<endl;
			}
		}
		void Structure()
    	{
			cout<<endl<<endl;
	    	cout<<"***********"<<endl;
	    	cout<<"  1. Allot a Room"<<endl;
	    	cout<<"  2. Edit the Record"<<endl;
	    	cout<<"  3. Delete Record"<<endl;
	    	cout<<"  4. Search Record"<<endl;
	    	cout<<"  5. Display All Records"<<endl;
	    	cout<<"  6. Delete All Records"<<endl;
	    	cout<<"***********"<<endl;
			cout<<endl<<endl;
		
	    	int Scommand;
	    	cout<<"  Enter the Command: ";
	    	cin>>Scommand;
			cout<<"\n\n";
			cout<<"\t\t______________________________ROOM ALLOTMENT SYSTEM________________________________\n\n";
	    	try
	    	{
	    		if(Scommand>=1&&Scommand<=6)
	    		{
	    			if(Scommand==1)
	            	{
						cout<<"\t\tInsert a Room\n\n";
	            		CreateNode();
	            		OflineSave();
	    	        	Structure();
	            	}
	            	else if(Scommand==2)
		        	{
						cout<<"\t\tEdit a Record\n\n";
		        		EditRecord();
		        		OflineSave();
		        		Structure();
			        }
	            	else if(Scommand==3)
	            	{
						cout<<"\t\tDelete a Record\n\n";
	    	        	DeleteRecordBySearch();
	    	        	Structure();
	            	}
	            	else if(Scommand==4)
	            	{
						cout<<"\t\tSearch a Record\n\n";
	            		Search();
	            		Structure();
	            	}
	            	else if(Scommand==5)
	            	{      
						cout<<"\t\tCurrently Alloted Room's Record\n\n";		
	            		Display();
	            		OflineSave();
	            		Structure();
	            	}
	            	else if(Scommand==6)
	            	{
						cout<<"\t\tDelete Records\n\n";
	            		DeleteAllRecords();
	            		OflineSave();
	            		Structure();	
		        	}
				}
				else
				{
					throw(Scommand);
				}
			}
			catch(int Scommand)
			{
				cout<<"  You Enter wrong Command... Run the Code Again\n\n"<<endl;
				Structure();
			}	
	    }
    	
};

int main()
{   
    RoomAllotment room;
    room.reopenroom();
	string n;
	cout<<"  What is Your Name: ";
	cin>>n;
	
    cout<<"***********"<<endl;
	cout<<"  "<<n<<"\n\n  \tWELCOME TO ROOM ALLOTMENT SYSTEM\t      \n\n"<<endl;
	cout<<"***********\n\n"<<endl;
	room.Structure();
	return 0;
}