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

void Room::sort(){
   if(head == NULL){
    cout<<"\n\n No data available currently!!!\n";
    menu();
   }
   int count = 0, t_date = 0, t_id = 0;
   string t_name , t_roomType;
   Node * ptr = head;
   while(ptr != NULL){
    count++;
    ptr = ptr->next;
   }

   for(int i=1 ; i<=count; i++){
    Node * ptr = head;
    for(int j=1 ; j < count ; j++){
      if(ptr->id > ptr->next->id){
         t_id = ptr->id;
         t_date = ptr->date;
         t_roomType = ptr->roomType;
         t_name = ptr->name;

         ptr->id = ptr->next->id;
         ptr->name = ptr->next->name;
         ptr->date = ptr->next->date;
         ptr->roomType = ptr->next->roomType;

         ptr->next->id = t_id;
         ptr->next->name = t_name;
         ptr->next->date = t_date;
         ptr->next->roomType = t_roomType;
    }
    ptr = ptr->next;
   }
   }
}

void Room::show(){
    if(head == NULL) cout<<"\n\n No data to show currently!!!\n";

    Node * ptr = head;

    while(ptr != NULL){
        cout << "\n\n Room ID : "<<ptr->id<<endl;
        cout << "\n Customer Name : "<<ptr->name<<endl;
        cout << "\n Room Allotment date : "<<ptr->date<<endl;
        cout << "\n Room Type : "<<ptr->roomType<<endl;
        
        ptr = ptr->next;
    }
}

void Room::del(){
    cout<<"\n\t _____________Room Allotment System_____________\n"<<endl;
    int delete_id;

    if(head == NULL){
       cout<<"\nNo Room available for deleting, please first book a Room!!!"<<endl;
    }else{
        cout<<"\nEnter the ID of the Room you want to delete the records for :"<<endl;
        cin>>delete_id;

        
            if(head->id == delete_id){
               
                 Node * ptr = head;
                 head = head->next;
                 delete ptr;

                cout<<"\n\n Deleted Room record Successfully!!!"<<endl;
            }else{
                Node * pre = head;
                Node * ptr = head;

                while(ptr != NULL){
                    if(ptr->id == delete_id){
                        pre->next = ptr->next;
                        delete ptr;
                        cout<<"\n\n Deleted Room record Successfully!!!"<<endl;
                        break;
                    }
                    pre = ptr;
                    ptr = ptr->next;
                }
            } 
    }
}

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
            }
                ptr = ptr->next;
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
    cout<<"\n\n5. \t\t Show Records \t\t Show the current available room records"<<endl<<endl;
    cout<<"\n\n6. \t\t Exit"<<endl<<endl;

    cout<<"\n Enter your Choice"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
        insert();
        menu();
        

        case 2:
        search();
        menu();

        case 3:
        update();
        menu();

        case 4:
        del();
        menu();

        case 5:
        sort();
        show();
        menu();

        case 6:
        exit(0);
        
        default:
        cout<<"INVALID CHOICE"<<endl;
    }
}

int main(){
    Room r;

    r.menu();
}