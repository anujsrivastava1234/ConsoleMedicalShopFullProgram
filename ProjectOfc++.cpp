/////////////////////////////////////////////////MEDICAL SHOP PROJECT////////////////////////////////////////////////////////
/*Created By:-
Subhabam Burman Sir  &
Anuj Srivastava
*/
//header files

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstring>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//Funtion Declaration

void startUp();
void welcomeScreen();

void stocksRec();
void salesRec();
void employeeRec();

//MedicineFunctions
void showStocks();
void addStocks();
void updateStocks();
void deleteStocks();
void searchMedicine();

//Customerfunctionns
void customerRecords();
void addcustomer();
void viewcustomer();
void updatecustomer();
void deletecustomer();
void searchcustomer();

class Register{
    string username;
    string emailId;
    string password;
    string conPassword;

    public:
        void getData()
        {
            cout<<"\nUsername: ";
            cin>>username;

            cout<<"\nEmail ID: ";
            cin>>emailId;

            cout<<"\nPassword: ";
            cin>>password;

            cout<<"\nConfirm Password: ";
            cin>>conPassword;

            checkPasswordAndConPassword();
        }
        int checkPasswordAndConPassword(){
            if (password == conPassword){
                return 0;
            }else
            {
                return 1;
            }
        }
        void proceedFurther(){
            int temp;
            temp = checkPasswordAndConPassword();
            if(temp == 0){
                system("cls");
                char choice;
                cout<<"Do you want to save your user info? (Y/N)";
                cin>>choice;
                switch (choice)
                {
                case 'Y':
                    saveRegisterInfo();
                    break;
                
                default:
                    getData();
                    break;
                }
                getch();
            }
            else{
                cout<<"Password didn't match. Try Again.";
                getData();
            }
        }
        int saveRegisterInfo(){
            ofstream save, saveUsername, savePassword;

            save.open("Register Info.txt", ios::app);
            save<<"\nUsername: "<<username;
            save<<"\nEmail ID: "<<emailId;
            save<<"\nPassword: "<<password;
            save.close();

            saveUsername.open("Username Info.txt", ios::app);
            saveUsername<<username<<endl;
            saveUsername.close();

            savePassword.open("Password Info.txt", ios::app);
            savePassword<<password<<endl;
            savePassword.close();

            cout<<"\nInformation have been saved successfully."<<endl
                <<"Press enter to Login."<<endl;
            getch();
            startUp();

            return 0;
        }
};
class customerInfo{
	string CustomerName;
	string CustemailId;
	string CustphoneNo;
	string Custaddress;
	string Medicine;
	string price;
	
	public:
		void getData(){
			cout<<"\nCustomer Name : ";
			cin>>CustomerName;
			
			cout<<"\nCustomer Email Id : ";
			cin>>CustemailId;
			
			cout<<"\nCustomer Phone Number : ";
			cin>>CustphoneNo;
			
			cout<<"\nCustomer Address : ";
			cin>>Custaddress;
			
			cout<<"\nMedicine purchased by customer : ";
			cin>>Medicine;
			
			cout<<"Medicine price: ";
			cin>>price;
			
			
		}
		void proceedFurther(){
			int temp;
			system("cls");
			char choice;
			cout<<"Do you want to save this info ? (Y/N)";
			cin>>choice;
			switch(choice)
			{
				case 'Y':
					saveRegisterInfo();
					break;
				case 'y':
					saveRegisterInfo();
					break;
				default:
					getData();
					break;
			}
		}
			// getch();
			
			int saveRegisterInfo(){
				ofstream save;
				
				save.open("Customer Resister Info.txt",ios::app);
				save<<"\nCustomerName: "<<CustomerName;
				save<<"\nCustomerPhoneNumber: "<<CustphoneNo;
				save<<"\nCustomerAddress: "<<Custaddress;
				save<<"\nMedicineName: "<<Medicine;
				save<<"\nMedicinePrice: "<<price;
				save.close();
				
				cout<<"\nInformation Have been saved successfully."<<endl
				   <<"Press Enter to Continue..."<<endl;
				getch();
				startUp();
				
				return 0;
			}
		
};

class Login{
    string username;
    string password;

    public:
        void getData()
        {
            cout<<"\nUsername: ";
            cin>>username;

            cout<<"\nPassword: ";
            cin>>password;
        }

        bool validateUsername(){
            string temp;
            int flag = 0;
            ifstream read;
            read.open("Username Info.txt");
            while (read.eof() == 0)
            {
                getline(read, temp);
                flag = flag +1;             //1     2       3
                if (temp == username)
                    return true;
            }
            return false;
        }
        bool validatePassword(){
            string temp;
            ifstream read;
            read.open("Password Info.txt");
            while (read.eof()==0)
            {
                getline(read, temp);
                if (temp == password)
                    return true;
            }
            return false;
        }
};

void startUp(){
    system("cls");
    char choice;
    cout<<"\t\t\t----------------------- WELCOME TO THE MEDICAL SHOP ---------------------------"<<endl;
    cout<<"\t\t\t\t||\t1. Register a new account.\t\t\t\t||"<<endl
        <<"\t\t\t\t||\t2. Login to a existing account.\t\t\t\t||"<<endl
        <<"\t\t\t\t||\t3. Create a New Customer account.\t\t\t||"<<endl
        <<"\t\t\t\t||\t4. Exit.\t\t\t\t\t\t||"<<endl
        <<"Enter your choice:  "<<endl;
    cin>>choice;

    switch (choice)
    {
    case '1':
        {
        system("cls");
        Register reg;
        reg.getData();
        reg.proceedFurther();
        }
        break;
    case '2':
        {
        system("cls");
        bool checkUsername, checkPassword;
        Login login;
        login.getData();
        checkUsername = login.validateUsername();
        checkPassword = login.validatePassword();

        if (checkUsername)
        {
            if (checkPassword)
            {
                system("cls");
                cout<<"\nLogged In Successfully..!!";
                cout<<"\nPress ENTER to continue.";
                getch();
                welcomeScreen();
            }
            
        }
        else{
            system("cls");
            cout<<"\nInvaild Credentials";
            getch();
            startUp();
        }

        }
        break;
    case '3':
    {
        system("cls");
        customerInfo cust;
        cust.getData();
        cust.proceedFurther();

    }
    break;
        
    
    case '4':
        exit(0);


    default:
        cout<<"Invaild choice. Press enter to continue.";
        getch();
        system("cls");
        startUp();
        break;
    }
}

void welcomeScreen(){
    system("cls");
    int choice;
    cout<<"------------------------------------ WELCOME TO THE MEDICAL SHOP ------------------------------------"<<endl;
    cout<<"\n\n\t\tSelect the your desired category:"<<endl;
    cout<<"\n\t\t\t\t1. Stocks Records"<<endl
        <<"\n\t\t\t\t2. Sales Records"<<endl
        <<"\n\t\t\t\t3. Employee Records"<<endl
        <<"\n\t\t\t\t4.Customer Records"<<endl
        <<"\n\t\t\t\t5. Exit"<<endl
        <<"\n\n\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        stocksRec();
        break;
    case 2:
        // salesRec();
        break;
    
    case 3:
         customerRecords();
         break;

    case 4:
        exit(0);
        break;
    
    default:
        system("cls");
        cout<<"Invaild choice, press enter to try again.";
        getch();
        welcomeScreen();
        break;
    }
}


void stocksRec(){
    system("cls");
    int choice;
    cout<<"------------------------------------ WELCOME TO THE MEDICAL SHOP ------------------------------------"<<endl;
    cout<<"\n\n\t\tSelect operation you want to perform:"<<endl;
    cout<<"\n\t\t\t\t1. Add to existing stock."<<endl
        <<"\n\t\t\t\t2. View the existing stock."<<endl
        <<"\n\t\t\t\t3. Update stocks."<<endl
        <<"\n\t\t\t\t4. Delete stocks."<<endl
        <<"\n\t\t\t\t5. Search Medicine"<<endl
        <<"\n\t\t\t\t6. Exit"<<endl
        <<"\n\n\nEnter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        system("cls");
        addStocks();
        break;
    case 2:
        system("cls");
        showStocks();
        break;
    case 3:
        system("cls");
        updateStocks();
        break;
    case 4:
        system("cls");
        deleteStocks();
        break;
    case 5:
        system("cls");
        searchMedicine();
    case 6:
        exit(0);
        break;
    
    default:
        system("cls");
        cout<<"Invaild choice, press enter to try again.";
        getch();
        welcomeScreen();
        break;
    }
}

typedef struct Stocks
{
    int id, quantity;
    string medicineName;
    float rate;
}Stocks;

class Stock{
    Stocks s;   //data member of the following class.

    public:
    void getData(){     //initializing object-> s
        cout<<"\nEnter medicine id: ";
        cin>>s.id;
        fflush(stdin);      //clearing buffer memory.
        cout<<"\nEnter medicine name: ";
        getline(cin, s.medicineName);
        cout<<"\nEnter quantity: ";
        cin>>s.quantity;
        cout<<"\nEnter rate: ";
        cin>>s.rate;
    }
    void putData(){
        cout<<setw(5)<<s.id
            <<setw(25)<<s.medicineName
            <<setw(35)<<s.quantity
            <<setw(40)<<s.rate<<endl;
    }
    int getId(){
        return s.id;
    }
    string getMedicineName(){
        return s.medicineName;
    }
    void updateQuantity(int quant){
        s.quantity = quant;
    }
};

Stock stockObj;
fstream file;

void showStocks(){
    cout<<"-------------------------------------------- WELCOME TO THE MEDICAL SHOP --------------------------------------------"<<endl;
    file.open("stocks.dat", ios::binary | ios::in);
    if (!file)      //if no entry have been added to the file
    {
        cout<<"\nFile not found.";
        cout<<"\n\n\nPress ENTER to go back to Welcome page.";
        getch();
        welcomeScreen();
    }
    else
    {
        file.read((char*)&stockObj, sizeof(stockObj));
        // cout<<setw(5)<<"Sl. ID"
        //     <<setw(25)<<"Medicine Name"
        //     <<setw(35)<<"Quantity"
        //     <<setw(40)<<"Rate"<<endl;
        while (!file.eof())
        {
            stockObj.putData();
            file.read((char*)&stockObj, sizeof(stockObj));
        }
    }
    file.close();
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}
void addStocks(){
    char choice = 'y';
    file.open("stocks.dat", ios::binary | ios::app);
    while (choice == 'y' || choice == 'Y')
    {
        cout<<"------------------------------------ WELCOME TO THE MEDICAL SHOP ------------------------------------"<<endl;
        system("cls");
        stockObj.getData();     //temporary memory (eg. memory address- 1024)
        file.write((char*)&stockObj, sizeof(stockObj));
        cout<<"\nDo you want to enter another record. (Y/N) : ";
        cin>>choice;
    }
    file.close();
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}
void deleteStocks(){
    int delRec;
    cout<<"\nEnter the id of the record you want to delete: ";
    cin>>delRec;

    fstream newFile;

    newFile.open("temp.dat", ios::binary | ios::out);
    file.open("stocks.dat", ios::binary | ios::in);

    file.read((char*)&stockObj, sizeof(stockObj));
    while (!file.eof())
    {
        if (delRec != stockObj.getId())
        {
            newFile.write((char*)&stockObj, sizeof(stockObj));
        }
        file.read((char*)&stockObj, sizeof(stockObj));
    }
    
    newFile.close();
    file.close();

    remove("stocks.dat");
    rename("temp.dat", "stocks.dat");

    cout<<"\n\nRequired record has been deleted.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}
void updateStocks(){
    int updRec;
    int updQuantity;
    cout<<"\nEnter the id of the record you want to update: ";
    cin>>updRec;
    cout<<"\nEnter new quantity: ";
    cin>>updQuantity;

    file.open("stocks.dat", ios::in | ios::out | ios::binary);      //step 1-> opening the file

    while (file.read((char*)&stockObj, sizeof(stockObj))) //step 2->gives set of data one by one
    {
        if (stockObj.getId() == updRec)
        {
            stockObj.updateQuantity(updQuantity);
            int pos = sizeof(stockObj);
            file.seekp(-pos, ios::cur);
            file.write((char*)&stockObj, sizeof(stockObj));
        }
    }
    file.close();

    cout<<"\n\nRequired record has been updated.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}
void searchMedicine(){
    string medName;
    int flag = 1;
    cout<<"\nEnter name of the medicine: ";
    cin>>medName;

    file.open("stocks.dat", ios::in | ios::binary);
    file.read((char*)&stockObj, sizeof(stockObj));
    while (!file.eof()){
        if (medName == stockObj.getMedicineName())
        {
            stockObj.putData();
            cout<<"\nMedicine Found";
            flag = 0;
        }
        file.read((char*)&stockObj, sizeof(stockObj));   
    }
    if (flag)
    {
        cout<<"\nNo search result found.";
    }
    
    file.close();

    // cout<<"\n\nRequired record has been updated.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();    
}

void customerRecords(){
    system("cls");
    int choice;
    cout<<"----------------------------------------Welcome To The Medical Shop-----------------------------------"<<endl;
    cout<<"\n\t\t\tSelect the operations You want to perform: "<<endl;
    cout<<"\n\t\t\t1. Add A Record Of New Customer."<<endl
        <<"\n\t\t\t2. View The existing customer Records."<<endl
        <<"\n\t\t\t3. Update The Customer Records."<<endl
        <<"\n\t\t\t4. Delete A customer Record."<<endl
        <<"\n\t\t\t5. Search Medicine."<<endl
        <<"\n\t\t\t6. Exit."<<endl
        <<"\n\n\nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                system("cls");
                addcustomer();
                break;
            case 2:
                    system("cls");
                    viewcustomer();
                    // ~viewcustomer();
                    break;
            case 3:
                system("cls");
                updatecustomer();
                break;
            case 4:
                    system("cls");
                    deletecustomer();
                    break;
            case 5:
                system("cls");
                searchcustomer();
                break;
            case 6:
                    exit(0);
                    break;
            
            default:
                    system("cls");
                    cout<<"Invalid Choice , press enter to try again.";
                    getch();
                    welcomeScreen();
                    break;

        }
}

typedef struct CustInfo
{
    int id, quantity;
    string CustomerName;
    float price;
}ci;

class Customer_detail{
    CustInfo c;   //data member of the following class.

    public:
    void getData(){     //initializing object-> s
        cout<<"\nEnter Customer id: ";
        cin>>c.id;
        fflush(stdin);      //clearing buffer memory.
        cout<<"\nEnter Customer name: ";
        getline(cin, c.CustomerName);
        cout<<"\nEnter quantity of medicne pusrcashed : ";
        cin>>c.quantity;
        cout<<"\nEnter rate: ";
        cin>>c.price;
    }
    void putData2(){
        cout<<setw(5)<<c.id
            <<setw(25)<<c.CustomerName
            <<setw(35)<<c.quantity
            <<setw(40)<<c.price<<endl;
    }
    int getCustomerId(){
        return c.id;
    }
    string getCustomerName(){
        return c.CustomerName;
    }
    void updateMedicineQuantity(int quant){
        c.quantity = quant;
    }
};
Customer_detail Custdel;
fstream file2;

void viewcustomer(){
    cout<<"-------------------------------------------- WELCOME TO THE MEDICAL SHOP --------------------------------------------"<<endl;
    file2.open("StoreCustomerRecords.dat", ios::binary | ios::in);
    if (!file2)      //if no entry have been added to the file
    {
        cout<<"\nFile not found.";
        cout<<"\n\n\nPress ENTER to go back to Welcome page.";
        getch();
        welcomeScreen();
    }
    else
    {
        file2.read((char*)&Custdel, sizeof(Custdel));
        // cout<<setw(5)<<"Sl. ID"
        //     <<setw(25)<<"Medicine Name"
        //     <<setw(35)<<"Quantity"
        //     <<setw(40)<<"Rate"<<endl;
        while (!file2.eof())
        {
            Custdel.putData2();
            file2.read((char*)&Custdel, sizeof(Custdel));
        }
    }
    file2.close();
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}

void addcustomer(){
    char choice = 'y';
    file2.open("StoreCustomerRecords.dat", ios::binary | ios::app);
    while (choice == 'y' || choice == 'Y')
    {
        cout<<"------------------------------------ WELCOME TO THE MEDICAL SHOP ------------------------------------"<<endl;
        system("cls");
        Custdel.getData();     //temporary memory (eg. memory address- 1024)
        file2.write((char*)&Custdel, sizeof(Custdel));
        cout<<"\nDo you want to enter another record. (Y/N) : ";
        cin>>choice;
    }
    file2.close();
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}

void updatecustomer(){
    int updRec;
    int updQuantity;
    // char updname;
    cout<<"\nEnter the id of the record you want to update: ";
    cin>>updRec;
    cout<<"\nEnter new quantity: ";
    cin>>updQuantity;

    file.open("StoreCustomerRecords.dat", ios::in | ios::out | ios::binary);      //step 1-> opening the file

    while (file.read((char*)&Custdel, sizeof(Custdel))) //step 2->gives set of data one by one
    {
        if (Custdel.getCustomerId() == updRec)
        {
            Custdel.updateMedicineQuantity(updQuantity);
            int pos = sizeof(Custdel);
            file.seekp(-pos, ios::cur);
            file.write((char*)&Custdel, sizeof(Custdel));
        }
    }
    file.close();

    cout<<"\n\nRequired record has been updated.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}

void deletecustomer(){
    int delRec;
    cout<<"\nEnter the id of the record you want to delete: ";
    cin>>delRec;

    fstream newFile2;

    newFile2.open("temp2.dat", ios::binary | ios::out);
    file2.open("StoreCustomerRecords.dat", ios::binary | ios::in);

    file2.read((char*)&Custdel, sizeof(Custdel));
    while (!file2.eof())
    {
        if (delRec != Custdel.getCustomerId())
        {
            newFile2.write((char*)&Custdel, sizeof(Custdel));
        }
        file2.read((char*)&Custdel, sizeof(Custdel));
    }
    
    newFile2.close();
    file2.close();

    remove("StoreCustomerRecords.dat");
    rename("temp2.dat", "StoreCustomerRecords.dat");

    cout<<"\n\nRequired record has been deleted.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();
}

void searchcustomer(){
    string CustomerName;
    int flag = 1;
    cout<<"\nEnter name of the Customer: ";
    cin>>CustomerName;

    file2.open("StoreCustomerRecords.dat", ios::in | ios::binary);
    file2.read((char*)&Custdel, sizeof(Custdel));
    while (!file.eof()){
        if (CustomerName == Custdel.getCustomerName())
        {
                Custdel.putData2();
                cout<<"\nCustomer  Found";
                flag = 0;
        }
        file2.read((char*)&Custdel, sizeof(Custdel));   

    }
    if (flag)
    {
        cout<<"\nNo search result found.";
    }
    
    file2.close();

    // cout<<"\n\nRequired record has been updated.";
    cout<<"\n\n\nPress ENTER to go back to Welcome page.";
    getch();
    welcomeScreen();    
}

int main(){
    startUp();
    return 0;
}