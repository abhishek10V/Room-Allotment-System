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