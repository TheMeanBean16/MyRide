//Project ver 2

///NOTE TO SELF HIDE AND REATTACH BOXES SO INPUT IS CLEARED FOR NEXT CUSTOMER for back to main menu too!!!
//CSCE 121 Project Interface

//Katherine Ruff


#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//----------------------------------------------------------
// define a struct that is a window in which lines can be
// entered via a GUI

struct Lines_window : Graph_lib::Window {       // inherits from Window
    
    // constructor
    Lines_window(Point xy,             // top lefthand corner
                 int w,                // width
                 int h,                // height
                 const string& title); // label
private:
    Menu main_menu;     //menu for all of the main options of the program
    Button main_menu_button;
    Button quit_button;
    
    Button add_customer;
    Button remove_customer;
    Button add_driver;
    Button remove_driver;
    
    Menu a_r_customer;
    Menu a_r_driver;
    
    
    //Add new customer boxes
    In_box c_name_account;
    In_box c_account_balance;
    In_box c_photo_name;
    
    //Add new driver boxes
    In_box d_name_account ;
    In_box d_account_balance;
    In_box d_photo_name;
    In_box d_latitude;
    In_box d_longitude;
    
    ///Text location(Point(100,100), // lower left corner of baseline
    ///“Hello, graphical world!”);
    
    void hide_main_menu(){
        //function that hides the main menu
        main_menu.hide();
        main_menu_button.show();
    }
    
    //functions for adding or removing customers
    void add_remove_customer_pressed(){
        hide_main_menu();
        a_r_customer.show();
    }
    
    void add_customer_option(){
        a_r_customer.hide();
        c_name_account.show();
        c_account_balance.show();
        c_photo_name.show();
        add_customer.show();
    }
    
    void Add_Customer();
    
    void Add_Customer_pressed(){
        main_menu_pressed();
        
    }
    
    void remove_customer_option(){
        a_r_customer.hide();
        c_name_account.show();
        remove_customer.show();
    }
    
    void Remove_Customer();
    
    void Remove_Customer_pressed(){
        main_menu_pressed();
      
    }
    
    
    
    
    
    //functions for adding or removing drivers
    void add_remove_driver_pressed(){
        hide_main_menu();
        a_r_driver.show();
    }
    
    void add_driver_option(){
        a_r_driver.hide();
        d_name_account.show();
        d_account_balance.show();
        d_photo_name.show();
        d_latitude.show();
        d_longitude.show();
        add_driver.show();
    }
    
    void Add_Driver();
    
    void Add_Driver_pressed(){
        main_menu_pressed();
        
    }
    
    void remove_driver_option(){
        a_r_driver.hide();
        d_name_account.show();
        remove_driver.show();
    }
    
    void Remove_Driver();
    
    void Remove_Driver_pressed(){
        main_menu_pressed();
        
    }
    
    
    
    void main_menu_pressed() {
        //Back to main menu button pressed
        main_menu_button.hide();
        a_r_customer.hide();
        add_customer.hide();
        
        c_name_account.hide();
        attach(c_name_account);
        c_name_account.hide();
        
        c_account_balance.hide();
        attach(c_account_balance);
        c_account_balance.hide();
        
        c_photo_name.hide();
        attach(c_photo_name);
        c_photo_name.hide();
        
        a_r_driver.hide();
        add_driver.hide();
        
        d_name_account.hide();
        attach(d_name_account);
        d_name_account.hide();
        
        d_account_balance.hide();
        attach(d_account_balance);
        d_account_balance.hide();
        
        d_photo_name.hide();
        attach(d_photo_name);
        d_photo_name.hide();
        
        
        d_longitude.hide();
        attach(d_longitude);
        d_longitude.hide();
        
        d_latitude.hide();
        attach(d_latitude);
        d_latitude.hide();
        main_menu.show();
        
    }
    
    void quit(); //defined below
    //buton to end the program
    
    static void cb_quit(Address, Address);
    
    static void cb_main_menu(Address, Address);
    //call back functions for buttons on main menu
    static void cb_add_remove_customer(Address, Address);
    static void cb_add_remove_driver(Address, Address);
    
    //call back functions for customer menu
    static void cb_add_customer_option(Address, Address);
    static void cb_add_customer(Address, Address);
    static void cb_remove_customer_option(Address, Address);
    static void cb_remove_customer(Address, Address);
    
    //call back functions for driver menu
    static void cb_add_driver_option(Address, Address);
    static void cb_add_driver(Address, Address);
    static void cb_remove_driver_option(Address, Address);
    static void cb_remove_driver(Address, Address);
    
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title):
// initialization - start by calling constructor of base class
Window(xy,w,h,title),

quit_button(
            Point(x_max()-100,0),    // location of button
            100, 50,                 // dimensions of button
            "Quit",                 // label of button
            cb_quit),

main_menu(
          Point(10,10),   // location of menu
          200, 30,                 // dimensions of menu
          Menu::vertical,         // list menu items vertically
          "Main Menu"),               // label of menu
// initialize the menu button
main_menu_button(
                 Point(x_max()-100, 75),  // location of menu button
                 100, 50,                // dimensions of button
                 "Back to Main Menu",          // label of button
                 cb_main_menu),

add_customer(
             Point(200, 300), 100, 75, "Add Customer", cb_add_customer),

add_driver(
           Point(200, 300), 100, 75, "Add Driver", cb_add_driver),

remove_customer(
                Point(200, 300), 100, 75, "Remove Customer", cb_remove_customer),
remove_driver(
              Point(200, 300), 100, 100, "Remove Driver", cb_remove_driver),
a_r_customer(
             Point(30, 10),
             100, 100,
             Menu::vertical,
             "Add/Remove Customer"),
a_r_driver(
           Point(30, 10),
           100, 100,
           Menu::vertical,
           "Add/Remove Driver"),

c_name_account( Point(200, 30), 100, 75, "Customer Name: "),
c_account_balance( Point(200, 100), 100, 75, "Account Balance: "),
c_photo_name(   Point(200, 170), 100, 75, "Customer Photo: "),


d_name_account( Point(200, 30), 100, 50, "Driver Name: "),
d_account_balance( Point(200, 80), 100, 50, "Driver Balance: "),
d_photo_name(    Point(200, 130), 100, 50, "Driver Photo: "),
d_latitude( Point(200, 180), 100, 50, "Driver latitude: "),
d_longitude(  Point(200, 220), 100, 50, "Driver longitude: ")

{
    attach(quit_button);
    
    
    
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Customer", cb_add_remove_customer));
  main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Driver", cb_add_remove_driver));
    
    attach(main_menu);
    attach(main_menu_button);
    main_menu_button.hide();
    
    ///Add Remove Customer Menu
    a_r_customer.attach(new Button(Point(0,0), 0,0, "Add Customer", cb_add_customer_option));
    a_r_customer.attach(new Button(Point(0,0), 0,0, "Remove Customer", cb_remove_customer_option));
    attach(a_r_customer);
    a_r_customer.hide();
    
    attach(c_name_account);
    c_name_account.hide();
    
    attach(c_account_balance);
    c_account_balance.hide();
    
    attach(c_photo_name);
    c_photo_name.hide();
    
    attach(add_customer);
    add_customer.hide();
    
    attach(remove_customer);
    remove_customer.hide();
    
    ///Add Remove Driver Menu
    a_r_driver.attach(new Button(Point(0,0), 0,0, "Add Driver", cb_add_driver_option));
    a_r_driver.attach(new Button(Point(0,0), 0,0, "Remove Driver", cb_remove_driver_option));
    attach(a_r_driver);
    a_r_driver.hide();
    
    attach(d_name_account);
    d_name_account.hide();
    
    attach(d_account_balance);
    d_account_balance.hide();
    
    attach(d_photo_name);
    d_photo_name.hide();
    
    attach(add_driver);
    add_driver.hide();
    
    attach(remove_driver);
    remove_driver.hide();
    
    attach(d_longitude);
    d_longitude.hide();
    
    attach(d_latitude);
    d_latitude.hide();
    
    
    
    
}
///QUIT BUTTON
void Lines_window::cb_quit(Address, Address pw) {
    reference_to<Lines_window>(pw).quit();   // quit is defined next
}

void Lines_window::quit() {
    hide();                   // FLTK idiom for delete window
}


///MAIN MENU
void Lines_window::cb_main_menu(Address, Address pw)
{
    reference_to<Lines_window>(pw).main_menu_pressed();
    // menu_pressed defined in Lines_window class as part of declaration
}

///ADD/REMOVE CUSTOMER
void Lines_window::cb_add_remove_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).add_remove_customer_pressed();  // next is defined next
    
}


///Add Customer option
void Lines_window::cb_add_customer_option(Address, Address pw) {
    reference_to<Lines_window>(pw).add_customer_option();  // next is defined next
}

void Lines_window::cb_add_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).Add_Customer();
}

void Lines_window::Add_Customer() {
    Add_Customer_pressed();
    
    cout<<"ADD NEW CUSTOMER";
}


///Remove Customer option
void Lines_window::cb_remove_customer_option(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_customer_option();  // next is defined next
}

void Lines_window::cb_remove_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).Remove_Customer();
}

void Lines_window::Remove_Customer() {
    Remove_Customer_pressed();
    
    cout<<"ADD NEW CUSTOMER";
}




///ADD/REMOVE DRIVER
void Lines_window::cb_add_remove_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).add_remove_driver_pressed();  // next is defined next
    
}


///Add Driver option
void Lines_window::cb_add_driver_option(Address, Address pw) {
    reference_to<Lines_window>(pw).add_driver_option();  // next is defined next
}

void Lines_window::cb_add_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).Add_Driver();
}

void Lines_window::Add_Driver() {
    Add_Driver_pressed();
    
    cout<<"ADD NEW CUSTOMER";
}


///Remove Driver option
void Lines_window::cb_remove_driver_option(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_driver_option();  // next is defined next
}

void Lines_window::cb_remove_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).Remove_Driver();
}

void Lines_window::Remove_Driver() {
    Remove_Driver_pressed();
    
    cout<<"ADD NEW DRIVER";
}




int main()
try {
    // construct the GUI window
    Lines_window win(Point(100,100),600,400,"lines");
    return gui_main();  // inherited from Window; calls FLTK's run
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
    catch(...) {
        cerr << "some exception\n";
        return 2;
    }
    
    

    
    
    
    
