#include <iostream>
using namespace std;

class Room{
    private:
     struct Node
     {
      int id , date;
      string name , roomType;
      Node * next;
     };

    public:
      Node * head = NULL;
      void menu();
      void insert();
      void update(); 
      void search(); 
      void del(); 
      void sort(); 
      void show(); 
};

void Room::update(){
    cout<<"\n\t _____________Room Allotment System_____________\n"<<endl;
    int update_id;

    if(head == NULL){
       cout<<"\nNo Room available for updating, please first book a Room!!!"<<endl;
    }else{
        cout<<"\nEnter the ID of the Room you want to update the details of :"<<endl;
        cin>>update_id;

        Node * ptr = head;
        bool flag = false;
        while(ptr != NULL){
            if(ptr->id == update_id){
                flag = true;
                cout<<"\n\n Enter Room ID : "<<endl;
                cin>>ptr->id;
                cout<<"\n Enter Customer Name : "<<endl; 
                cin>>ptr->name;
                cout<<"\n Enter Room Allocated Date : "<<endl; 
                cin>>ptr->date;
                cout<<"\n Enter Room Type : "<<endl; 
                cin>>ptr->roomType;

                cout<<"\n\n Room Details Updated Successfully!!!"<<endl;
            }else{
                ptr = ptr->next;
            }
        }
        if(flag == false) cout<<"\n\nNo room available for the entered Room ID\n"<<endl;
        
    }
}

void Room::search(){
    cout<<"\n\t _____________Room Allotment System_____________\n"<<endl;
    int search_id;

    if(head == NULL){
       cout<<"\nNo Room available for searching, please first book a Room!!!"<<endl;
    }else{
        cout<<"\nEnter the ID of the Room you want to find the details of :"<<endl;
        cin>>search_id;

        Node * ptr = head;
        bool flag = false;
        while(ptr != NULL){
            if(ptr->id == search_id){
                flag = true;
                cout<<"\n\n Room ID : "<<ptr->id<<endl;
                cout<<"\n Customer Name : "<<ptr->name<<endl; 
                cout<<"\n Room Allocated Date : "<<ptr->date<<endl; 
                cout<<"\n Room Type : "<<ptr->roomType<<endl; 
            }else{
                ptr = ptr->next;
            }
        }
        if(flag == false) cout<<"\n\nNo room available for the entered Room ID\n"<<endl;
        
    }
}

void Room::insert(){
    cout<<"\n\t _____________Room Allotment System_____________\n"<<endl;
    Node * newNode = new Node;
    cout<<"Enter Room ID"<<endl;
    cin>>newNode->id;
    cout<<"Enter Customer Name"<<endl;
    cin>>newNode->name;
    cout<<"Enter Allocated Date"<<endl;
    cin>>newNode->date;
    cout<<"Enter Room Type(Single , Double, Twin)"<<endl;
    cin>>newNode->roomType;

    if(head == NULL){
        head = newNode;
    }else{
        Node * ptr = head;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = head;
    }

    cout<<"\n\n\t\tNew Room Inserted with RoomID " <<newNode->id<<endl;
}
void Room::menu(){
    int choice;

    cout<<"\n";
    cout<<"\t Welcome to Room Allotment System Application\n"<<endl;
    cout<<"\t _____________Room Allotment System_____________"<<endl;
    cout<<"\n\nS.No. \t\t Fuctions \t\t Description"<<endl<<endl;
    cout<<"\n\n1. \t\t Allocate Room \t\t Insert new room"<<endl<<endl;
    cout<<"\n\n2. \t\t Search Room \t\t Search room with RoomID"<<endl<<endl;
    cout<<"\n\n3. \t\t Update Room \t\t Update room record"<<endl<<endl;
    cout<<"\n\n4. \t\t Delete Room \t\t Delete room with RoomID"<<endl<<endl;
    cout<<"\n\n5. \t\t Show Room Records \t\t Show the current available room records"<<endl<<endl;
    cout<<"\n\n6. \t\t Exit"<<endl<<endl;

    cout<<"\n Enter your Choice"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
        insert();
        break;

        case 2:
        search();
        break;

        case 3:
        update();
        break;

         case 4:
        del();
        break;

         case 5:
        show();
        break;

        case 6:
        exit(0);
        
        default:
        cout<<"INVALID CHOICE"<<endl;
    }
}