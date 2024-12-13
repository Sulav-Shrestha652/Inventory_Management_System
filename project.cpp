#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<fstream>
#include<ctime>
#include <iomanip>

using namespace std;

void gotoxy(int x,int y);
void topic();
void welcome();
void front_inter_face();
void backss();
void backs();

void owners();
void owner_front_face(char name[20]);
void display(char name[20]);
void displayss(char usname[20]);

int n,i,j,num;
char dublicate[20];

class owner
{
	private:
		char username[20];
		char password[20];
		char staff_password[20];
	public:
		void owner_register_check();
		void owner_register(char uname[20]);
		void owner_login();
		void staff_login();
		
}o;

class inventory
{
	private:
		char product_name[50];
		int quantity;
		int price;
		char temp_productname[50];
		int temp_quantity;
		int temp_price;
		int temp_rate;
		string temp_date;
	public:
		void owner_input(char storename[20]);
		void sales_of_product(char name[20]);
		void stock_of_product(char name[20]);
		void edit(char name[20]);
		void search(char name[20],int number);
		void deleted(char dlt[20]);
	
		void staffinterface(char uname[20]);
		void sale(char uname[20]);
		void stock_of_product_display(char name[20]);		
}in;

int main()
{
	welcome();
	front_inter_face();
	return 0;	
}

void gotoxy(int x,int y)
{
	COORD w;
	w.X=x;
	w.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),w);
}

void topic()
{
	system("cls");
	system("color 0e");
	time_t currentTime = time(0);
    string dateTimeString = ctime(&currentTime);
    gotoxy(65,3);
    cout<< dateTimeString << endl;
	gotoxy(47,5);
	cout<<"+------------------------------------------------------------------+";
	gotoxy(47,6);
	cout<<"|                                                                  |";
	gotoxy(47,7);
	cout<<"|                    INVENTORY MANAGEMENT SYSTEM                   |";
	gotoxy(47,8);
	cout<<"|                                                                  |";
	gotoxy(47,9);
	cout<<"+------------------------------------------------------------------+\n\n\n\n\n\n";
}

void backs()
{
	cout<<endl<<endl<<endl<<"Press 1 to go back to the front page"<<endl<<"Press any key to Exit"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			system("cls");
			topic();
		    owners();
			break;
			
		default:
			exit(0);		
	}
}

void welcome()
{
	int i,j;
	topic();
	
	SetConsoleCP(437);
	SetConsoleOutputCP(437);//ask
	int bar=219;
	cout<<"\t\t\t\t\t\t\t\t\tLoading...";
	cout<<"\n\t\t\t\t\t\t";

	for(i=0;i<6;i++)
		{
			for(j=0;j<11;j++)
			{
				cout<<(char)bar;            
			}
			sleep(1);
		
		}
		cout<<"\n\t\t\t\t\t\t"<<"!";
		system("pause");
		
		system("cls");	
		gotoxy(77,16);
		cout<<"WELCOME";
		sleep(1);
		gotoxy(80,17);
		cout<<"TO";
		sleep(1);
		gotoxy(67,18);
		cout<<"INVENTORY";
		sleep(1);
		cout<<" MANAGEMENT";
		sleep(1);
		cout<<" SYSTEM";
		sleep(2);		
}

void front_inter_face()
{
	topic();
	gotoxy(67,14);
	cout<<"________________________";
	gotoxy(67,15);
	cout<<"|                      |";
	gotoxy(67,16);
	cout<<"| 1 |  Owner           |";
	gotoxy(67,17);
	cout<<"|   |                  |";
	gotoxy(67,18);
	cout<<"| 2 |  Staff           |";
	gotoxy(67,19);
	cout<<"|   |                  |";
	gotoxy(67,20);
	cout<<"| 3 |  Exit            |";
	gotoxy(67,21);
	cout<<"|______________________|";
	gotoxy(67,24);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			owners();
			break;
			
		case 2:
			owner o;
			topic();
			o.staff_login();
			break;
			
		case 3:
			exit(0);
			break;
			
		default:
			cout<<"Invalid Choice\n";
			system("pause");
			system("cls");
			break;	
	}
}

void owners()
{
	topic();
	owner o;
	int n;
	gotoxy(67,14);
	cout<<"________________________";
	gotoxy(67,15);
	cout<<"|                      |";
	gotoxy(67,16);
	cout<<"| 1 |  Register        |";
	gotoxy(67,17);
	cout<<"|   |                  |";
	gotoxy(67,18);
	cout<<"| 2 |  Login           |";
	gotoxy(67,19);
	cout<<"|   |                  |";
	gotoxy(67,20);
	cout<<"| 3 |  Back            |";
	gotoxy(67,21);
	cout<<"|______________________|";
	gotoxy(67,24);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			o.owner_register_check();
			break;
			
		case 2:
			topic();
			o.owner_login();
			break;
		
		case 3:
			front_inter_face();
			break;		
			
		default:
			exit(0);
	}
}

void owner::owner_register_check()
{
	int flag=0;
	owner o;
	char owner_username[20];
	ofstream onfile;
	onfile.open("owner_register_file.bin",ios::app|ios::binary);
	onfile.close();
	//-------------
	ifstream infile;
	infile.open("owner_register_file.bin",ios::in|ios::binary);
	gotoxy(0,14);
	cout<<"Enter the Username=";
	cin>>owner_username;
	while ((infile.read((char*)&o, sizeof(o)))>0) 
	{
        if (strcmp(owner_username,o.username) == 0) 
		{
			gotoxy(59,20);
	        cout<<"***********USER ID ALREADY EXIST***********";
	        flag++;
            getch();
		    backs();
            break;  
        }
    }
    infile.close();
    if(flag==0)
	{
		o.owner_register(owner_username);
	}   
}

void owner::owner_register(char uname[20])
{
	owner o;
	ofstream onfile;
	onfile.open("owner_register_file.bin",ios::app|ios::binary);
	strcpy(o.username,uname);
	gotoxy(0,15);
	cout<<endl<<"Enter the Admin Password=";
	cin>>o.password;
	cout<<endl<<"Enter the Staff Password=";
	cin>>o.staff_password;
	onfile.write((char*)&o,sizeof(o));
	onfile.close();
	gotoxy(59,20);
	cout<<"***********ID REGISTER SUCESSFULLY***********";		
	getch();
	backs();
}

void owner::owner_login()
{
	int flag=0;
	owner o;
	char owner_username[20];
	char owner_password[20];
	ifstream infile;
	infile.open("owner_register_file.bin",ios::in|ios::binary);
	cout<<"Enter the Username=";
	cin>>owner_username;
	cout<<endl<<"Enter the Admin Password=";
	cin>>owner_password;
	
	while ((infile.read((char*)&o, sizeof(o)))>0) 
	{
        if (strcmp(owner_username,o.username) == 0 && strcmp(owner_password,o.password) == 0) 
		{
			topic();
			owner_front_face(owner_username);
            flag++;
            break;  
        }
    }
    infile.close();
    if(flag==0)
	{
		cout<<"invalid";
		getch();
		backs();
	}  
}

void owner_front_face(char name[20])
{
	inventory in;
	char dublicate[20];
	strcpy(dublicate,name);
	topic();
	gotoxy(67,14);
	cout<<"________________________";
	gotoxy(67,15);
	cout<<"|                      |";
	gotoxy(67,16);
	cout<<"| 1    Add Product     |";
	gotoxy(67,17);
	cout<<"|                      |";
	gotoxy(67,18);
	cout<<"| 2    Display Product |";
	gotoxy(67,19);
	cout<<"|                      |";
	gotoxy(67,20);
	cout<<"| 3    Edit Product    |";
	gotoxy(67,21);
	cout<<"|                      |";
	gotoxy(67,22);
	cout<<"| 4    Search Product  |";
	gotoxy(67,23);
	cout<<"|                      |";
	gotoxy(67,24);
	cout<<"| 5    Delete Product  |";
	gotoxy(67,25);
	cout<<"|                      |";
	gotoxy(67,26);
	cout<<"| 6    Back            |";
	gotoxy(67,27);
	cout<<"|                      |";
	gotoxy(67,28);
	cout<<"| 7    Exit            |";
	gotoxy(67,29);
	cout<<"|                      |";
	gotoxy(67,30);
	cout<<"|______________________|";
	gotoxy(67,32);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			in.owner_input(name);
			break;
			
		case 2:
			topic();
			display(name);
			break;
			
		case 3:
			topic();
			in.edit(name);
			break;
			
		case 4:
			topic();
			num=1;
			in.search(name,num);
			backs();
			break;
			
		case 5:
			topic();
			in.deleted(name);
			break;
			
		case 6:
			topic();
			owners();
			break;
			
		case 7:
			exit(0);
			
		default:
			cout<<"INVALID CHOICE"<<endl;
			backs();			
	}	
}

void inventory::owner_input(char storename[20])
{
	int redflag=0;
	inventory in;
	strcat(storename,".bin");
	ofstream onfile;
	onfile.open(storename,ios::app|ios::binary);
	onfile.close();
	cout<<"\nEnter the Number of Product=";
	cin>>n;
	cout<<"\n\n***********************************************************************************************";
	for(i=1;i<=n;i++)
	{
	int flag=0;
	char product[20];
	cout<<"\n\nEnter the name of the product=";
	cin>>product;
	ifstream display;
	display.open(storename,ios::in|ios::binary);
	while ((display.read((char*)&in, sizeof(in)))>0) 
	{
		if(strcmp(product,in.product_name)==0)
		{
			cout<<endl<<setw(80)<<"PRODUCT ALREADY EXIST";
			flag++;
			redflag++;
		}
	}
	display.close();
	if(flag!=1)
	{
		ofstream onfile;
	    onfile.open(storename,ios::app|ios::binary);
		strcpy(in.product_name,product);
		cout<<endl<<"Enter the Quantity=";
        cin>>in.quantity;
	    cout<<endl<<"Enter the Price=";
	    cin>>in.price;
	    onfile.write((char*)&in,sizeof(in));
		onfile.close();		
	}	
    
	cout<<"\n\n***********************************************************************************************";
    }
	cout<<endl<<endl<<setw(80)<<"Product Added Sucessfully";
	if(redflag!=0)
	{
		cout<<endl<<setw(70)<<"EXCEPT ."<<redflag<<". Product";
	}
	getch();
	backs();	
}

void display(char name[20])
{
	char dublicate[20];
	strcpy(dublicate,name);
	inventory in;
	gotoxy(67,16);
	cout<<"1    Sales of Product.";
	gotoxy(67,18);
	cout<<"2    Stock of Product";
	gotoxy(67,20);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			gotoxy(0,0);
			cout<<"Back = 1";
			in.sales_of_product(dublicate);
			break;
			
		case 2:
			topic();
			gotoxy(0,0);
			cout<<"Back = 1";
			in.stock_of_product(name);
			backs();
			break;
			
		default:
			cout<<endl<<endl<<"Invalid Choice"<<endl;
		    owners();	
	}	
}

void inventory::sales_of_product(char name[20])
{
	int i=1;
	int total=0;
	inventory in;
	ifstream show_display;
	show_display.open("salesreport.bin",ios::in|ios::binary);
	if (!show_display.is_open())
	{
    perror("Error opening file");
    cerr << "Failed to open file: " << endl;
    getch();
    exit(0);
    }
    gotoxy(25,13);
	cout<<"_______________________________________________________________________________________________";
    gotoxy(30,14);
	cout<<"S.N";
	gotoxy(50,14);
	cout<<"Product";
	gotoxy(70,14);
	cout<<"Quantity";
	gotoxy(90,14);
	cout<<"Rate";
	gotoxy(110,14);
	cout<<"Price";
	gotoxy(25,15);
	cout<<"_______________________________________________________________________________________________";
	while ((show_display.read((char*)&in, sizeof(in)))>0) 
	{
		gotoxy(30,15+i);
		cout<<i;
		gotoxy(50,15+i);
		cout<<in.temp_productname;
		gotoxy(70,15+i);
		cout<<in.temp_quantity;
		gotoxy(90,15+i);
		cout<<in.temp_rate;
		gotoxy(110,15+i);
		cout<<in.temp_price;
		total+=in.temp_price;
		i++;
	}
	gotoxy(25,16+i);
	cout<<"_______________________________________________________________________________________________";
	gotoxy(90,17+i);
	cout<<"Net Total   ="<<total;
	gotoxy(25,18+i);
	cout<<"_______________________________________________________________________________________________";
	show_display.close();
	gotoxy(90,20+i);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			owners();
			break;
				
		case 2:
			topic();
			o.staff_login();
			break;
			
		default:
			exit(0);			
	}
}

void inventory::stock_of_product(char name[20])
{
	int i=1;
	inventory in;
	ifstream display;
	display.open(strcat(name,".bin"),ios::in|ios::binary);
	if(!display.is_open())
	{
		 perror("*"); 
       
        if (errno == ENOENT) {
            cerr << "File does not exist." << endl;
        } else if (errno == EACCES) 
		{
            cerr << "Permission denied." << endl;
        }
		getch();
		exit(0);		
	}
	gotoxy(40,13);
	cout<<"________________________________________________________________________________________";
	gotoxy(45,14);
	cout<<"S.N";
	gotoxy(75,14);
	cout<<"Product";
	gotoxy(115,14);
	cout<<"Quantity";
	gotoxy(40,15);
	cout<<"________________________________________________________________________________________";
	while ((display.read((char*)&in, sizeof(in)))>0) 
	{
		gotoxy(45,15+i);
		cout<<i;
		gotoxy(75,15+i);
		cout<<in.product_name;
		gotoxy(115,15+i);
		cout<<in.quantity;
		i++;
	}
	display.close();
	gotoxy(40,16+i);
	cout<<"________________________________________________________________________________________";
	cout<<"\n\n "<<setw(85)<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			owners();
			break;
				
		case 2:
			topic();
			o.staff_login();
			break;
			
		default:
			exit(0);			
	}	
}

void inventory::edit(char name[20])
{
	inventory in;
	int i=j=0;
	char productname[20];
	fstream display;
	display.open(strcat(name,".bin"),ios::out|ios::in|ios::ate|ios::binary);
	cout<<"\nEnter the name of the product=";
	cin>>productname;
	display.seekg(0,ios::beg);
	while(display.read((char *)&in,sizeof(in)))
	{
		++i;
		if(strcmp(in.product_name,productname)==0)
		{
			j=1;
			int location;
			location=(i-1)*sizeof(in);
			display.seekp(location,ios::beg);
			cout<<"\n________________________________________________________________________________________";
			cout<<"\nEnter New data";
			cout<<"\n\nEnter the name of the product=";
	        cin>>in.product_name;
	        cout<<endl<<"\nEnter the Quantity=";
	        cin>>in.quantity;
	        cout<<endl<<"\nEnter the Price=";
            cin>>in.price;
            display.write((char *)&in,sizeof(in))<<flush;
			cout<<"\n________________________________________________________________________________________"; 
			gotoxy(75,31);
            cout<<"Record Modified!!!"<<endl;
            break;
		}
	}
	if(j==0)
    cout<<"The record is notfound!"<<endl; 
    display.close();
    backs();	
}

void inventory::search(char name[20],int number)
{
	int i=1;
	inventory in;
	ifstream display;
	display.open(strcat(name,".bin"),ios::in|ios::binary);
	if(!display.is_open())
	{
		cout<<"Failed to open";
		getch();
		exit(0);		
	}
	cout<<"Enter the name of the product=";
	cin>>dublicate;
	while ((display.read((char*)&in, sizeof(in)))>0) 
	{
		if(strcmp(dublicate,in.product_name)==0)
		{
		topic();
		gotoxy(30,14);
	    cout<<"S.N";
	    gotoxy(60,14);
	    cout<<"Product";
	    gotoxy(100,14);
	    cout<<"Quantity";
		gotoxy(30,15+i);
		cout<<i;
		gotoxy(60,15+i);
		cout<<in.product_name;
		gotoxy(100,15+i);
		cout<<in.quantity;
		i++;
	}
	}
    if(i==1)
    {
    	cout<<"No Product is available with that name";
	}
	display.close();
	switch(number)
	{
		case 1:
			cout<<"\n\n\n"<<setw(95)<<"Press any key to Continue....";
			getch();
			topic();
			owners();
			break;
				
		case 2:
			cout<<"\n\n\n"<<setw(95)<<"Press any key to Continue....";
			getch();
			topic();
			o.staff_login();
			break;			
}
}

void inventory::deleted(char dlt[20]) 
{
    inventory in; 
    int flag = 0;
    ifstream display;
    ofstream del;
    char product[20];
    display.open(strcat(dlt,".bin"),ios::in|ios::binary);
    del.open(("temp.bin"),ios::out|ios::binary);
    cout << "Enter the name of the product: ";
    cin >> product;
    display.seekg(0,ios::beg);
    while ((display.read((char*)&in, sizeof(in)))) 
	{
		if(strcmp(product,in.product_name)!=0)
		{
			del.write((char*)&in,sizeof(in));
			
		}
		else
		{
			flag++;			
		}
	}
	if(flag>=1)
	{
		gotoxy(59,20);
	    cout<<"***********RECORD DELETED***********";		
		
	}

    display.close();
    del.close();
    const char* filename =dlt;
    if (remove(filename) == 0)
	{
        cout <<"*"<< endl;
    } 
	else 
	{
        perror("Error removing file"); 
       
        if (errno == ENOENT) {
            cerr << "File does not exist." << endl;
        } else if (errno == EACCES) {
            cerr << "Permission denied." << endl;
        }
    }
    
    const char* oldFilename = "temp.bin";
    const char* newFilename = dlt;
    if (rename(oldFilename, newFilename) == 0) {
        cout << "**" << endl;
    } else {
        perror("Error renaming file");
    }
    getch();
	backs();
	}
    
//---------------------------------------------------------

void owner::staff_login()
{
	int flag=0;
	owner o;
	inventory in;
	char staff_username[20];
	char staff_password[20];
	ifstream infile;
	infile.open("owner_register_file.bin",ios::in|ios::binary);
	cout<<"Enter the Username=";
	cin>>staff_username;
	cout<<endl<<"Enter the Staff Password=";
	cin>>staff_password;
	
	while ((infile.read((char*)&o, sizeof(o)))>0) 
	{
        if (strcmp(staff_username,o.username) == 0 && strcmp(staff_password,o.staff_password) == 0) 
		{
        cout<< endl;
        in.staffinterface(staff_username);
        flag++;
        break; 
        }
    }
    if(flag==0)
	{
		cout<<"invalid";
		getch();
		owners();
	}
    infile.close();
}

void inventory::staffinterface(char uname[20])
{
	topic();
	strcpy(dublicate,uname);
	gotoxy(67,14);
	cout<<"__________________________";
	gotoxy(67,15);
	cout<<"|                        |";
	gotoxy(67,16);
	cout<<"| 1   Sale Product       |";
	gotoxy(67,17);
	cout<<"|                        |";
	gotoxy(67,18);
	cout<<"| 2   Display Product    |";
	gotoxy(67,19);
	cout<<"|                        |";
	gotoxy(67,20);
	cout<<"| 3   Search Product     |";;
	gotoxy(67,21);
	cout<<"|                        |";
	gotoxy(67,22);
	cout<<"| 4   Back to the start  |";
	gotoxy(67,23);
	cout<<"|                        |";
	gotoxy(67,24);
	cout<<"| 5   Exit               |";
	gotoxy(67,25);
	cout<<"|                        |";
	gotoxy(67,26);
	cout<<"|________________________|";
	gotoxy(67,28);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			in.stock_of_product_display(dublicate);
			break;
			
		case 2:
			topic();
			displayss(uname);
			backss();
			break;
			
		case 3:
			topic();
			num=2;
			in.search(uname,num);
			backss();
			break;
			
		case 4:
			topic();
			front_inter_face();
			break;
			
		case 5:
			exit(0);
			break;
			
		default:
		    cout<<"INVALID CHOICE";
			cout<<endl;
			system("pause");
			front_inter_face();			
}
}

void inventory::stock_of_product_display(char name[20])
{
	int i=1;
	inventory in;
	strcpy(dublicate,name);
	ifstream display;
	display.open(strcat(name,".bin"),ios::in|ios::binary);
	if(!display.is_open())
	{
		 perror("*"); 
       
        if (errno == ENOENT) {
            cerr << "File does not exist." << endl;
        } else if (errno == EACCES) 
		{
            cerr << "Permission denied." << endl;
        }
		getch();
		exit(0);		
	}
	gotoxy(45,14);
	cout<<"S.N";
	gotoxy(75,14);
	cout<<"Product";
	gotoxy(115,14);
	cout<<"Quantity";
	while ((display.read((char*)&in, sizeof(in)))>0) 
	{
		gotoxy(45,15+i);
		cout<<i;
		gotoxy(75,15+i);
		cout<<in.product_name;
		gotoxy(115,15+i);
		cout<<in.quantity;
		i++;
	}
	display.close();
	in.sale(dublicate);	
}

void inventory::sale(char uname[20])
{
	inventory in;
	int total=0;
	int i=j=0;
	int k;
	char productname[20];
	int quantity;
	int rates;
	int price;
	int n;
	cout<<"\n\nEnter the Number of product=";
	cin>>n;
	cout<<"\n\n***********************************************************************************************";
	for(k=1;k<=n;k++)
	{
	fstream display;
	display.open(uname,ios::out|ios::in|ios::ate|ios::binary);
	cout<<"\n\nEnter the name of the product=";
	cin>>productname;
	cout<<"\nEnter the Quantity=";
	cin>>quantity;
	display.seekg(0,ios::beg);
	while(display.read((char *)&in,sizeof(in)))
	{
		++i;
		if(strcmp(in.product_name,productname)==0)
		{
			j=1;
			int location;
			location=(i-1)*sizeof(in);
			display.seekp(location,ios::beg);
	        in.quantity-=quantity;
	        rates=in.price;
            display.write((char *)&in,sizeof(in))<<flush; 
            break;
		}
	}
	if(j==0)
    {
		cout<<"\nThe record is notfound!"<<endl;
    }
    display.close();
    if(j==1)
    {	
        ofstream onfile;
	    onfile.open("salesreport.bin",ios::app|ios::binary);
	    strcpy(in.temp_productname,productname);
	    in.temp_quantity=quantity;
	    in.temp_rate=rates;
	    in.temp_price=rates*quantity;
	    total+=in.temp_price;
	    cout<<"\nRate="<<in.temp_rate<<"\t\t\t\t\t\t\t\t\t\tTotal="<<in.temp_price;
	    onfile.write((char*)&in,sizeof(in));
	    onfile.close();	
    }
    cout<<"\n\n***********************************************************************************************";
}
    cout<<"\n\n\n";
    cout<<setw(90)<<"Total="<<total;
	getch();                                                            
    backss();	
}

void backss()
{
	owner o;
	cout<<endl<<endl<<endl<<"Press 1 to go back to the front page"<<endl<<"Press any key to Exit"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			system("cls");
			topic();
		    o.staff_login();
			break;
			
		default:
			exit(0);		
	}	
}

void displayss(char usname[20])
{
	char dublicate[20];
	strcpy(dublicate,usname);
	inventory in;
	gotoxy(67,16);
	cout<<"1    Sales of Product.";
	gotoxy(67,18);
	cout<<"2    Stock of Product";
	gotoxy(67,20);
	cout<<"=";
	cin>>n;
	switch(n)
	{
		case 1:
			topic();
			gotoxy(0,0);
			cout<<"back = 2";
			in.sales_of_product(dublicate);
			break;
			
		case 2:
			topic();
			gotoxy(0,0);
			cout<<"back = 2";
			in.stock_of_product(usname);
			break;
			
		default:
			cout<<endl<<endl<<"Invalid Choice"<<endl;
		    front_inter_face();	
	}
	
}
