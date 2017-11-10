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
    
    Menu a_r_customer;
    Menu a_r_driver;
    Menu a_r_place;
    
    In_box c_name_account;
    
    void hide_main_menu(){
        //function that hides the main menu
        main_menu.hide();
        main_menu_button.show();
    }
    
    
    //functions for adding or removing customers
    void add_remove_customer();
    void add_customer();
    void remove_customer();
    
    void add_remove_customer_pressed(){
        hide_main_menu();
        a_r_customer.show();
    }
    
    void hide_add_remove_customer(){
        a_r_customer.hide();
        main_menu_pressed();
    }
    
    //functions for adding or removing drivers
    void add_remove_driver();
    void add_driver();
    void remove_driver();
    
    void add_remove_driver_pressed(){
        hide_main_menu();
        a_r_driver.show();
    }
    
    void hide_add_remove_driver(){
        a_r_driver.hide();
        main_menu_pressed();
    }
    
    
    
    //functions for adding or removing places
    void add_remove_place();
    void add_place();
    void remove_place();
    
    void add_remove_place_pressed(){
        hide_main_menu();
        a_r_place.show();
    }
    
    void hide_add_remove_place(){
        a_r_place.hide();
        main_menu_pressed();
    }
    
    
    void main_menu_pressed() {
        //Back to main menu button pressed
        main_menu_button.hide();
        a_r_customer.hide();
        main_menu.show();
    }
    
    void payment();
    
    void quit(); //defined below
    //buton to end the program
    
  
    static void cb_quit(Address, Address);

    static void cb_main_menu(Address, Address);
    //call back functions for buttons on main menu
    static void cb_add_remove_customer(Address, Address);
    static void cb_add_remove_driver(Address, Address);
    static void cb_add_remove_place(Address, Address);
    static void cb_payment(Address, Address);
    static void cb_request_ride(Address, Address);
    static void cb_display_customers(Address, Address);
    static void cb_display_drivers(Address, Address);
    static void cb_display_places(Address, Address);
    
    
    //call back functions for customer menu
    static void cb_add_customer(Address, Address);
    static void cb_remove_customer(Address, Address);
    
    //call back functions for driver menu
    static void cb_add_driver(Address, Address);
    static void cb_remove_driver(Address, Address);
    
    //call back functions for place menu
    static void cb_add_place(Address, Address);
    static void cb_remove_place(Address, Address);
    
   //call back functions for make payment
    
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
a_r_place(
           Point(30, 10),
           100, 100,
           Menu::vertical,
           "Add/Remove Driver"),
c_name_account( Point(200, 30), 100, 75, "Name Place A: ")

{
    attach(quit_button);
    attach(c_name_account);
    c_name_account.hide();
    
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Customer", cb_add_remove_customer));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Driver", cb_add_remove_driver));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Place", cb_add_remove_place));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Make a Payment", cb_payment));
    /*
     main_menu.attach(new Button(Point(0,0), 0, 0, "Request a Ride", cb_request_ride));
     main_menu.attach(new Button(Point(0,0), 0, 0, "Display Photos Places", cb_display_places));
     main_menu.attach(new Button(Point(0,0), 0, 0, "Displays Photos Drivers", cb_display_drivers));
     main_menu.attach(new Button(Point(0,0), 0, 0, "Display Photos Customers", cb_display_customers));
     */
    attach(main_menu);
    attach(main_menu_button);
    main_menu_button.hide();
    
    ///Add Remove Customer Menu
    a_r_customer.attach(new Button(Point(0,0), 0,0, "Add Customer", cb_add_customer));
    a_r_customer.attach(new Button(Point(0,0), 0,0, "Remove Customer", cb_remove_customer));
    attach(a_r_customer);
    a_r_customer.hide();
    
    ///Add Remove Driver Menu
    a_r_driver.attach(new Button(Point(0,0), 0,0, "Add Driver", cb_add_driver));
    a_r_driver.attach(new Button(Point(0,0), 0,0, "Remove Driver", cb_remove_driver));
    attach(a_r_driver);
    a_r_driver.hide();
    
    ///Add Remove Place Menu
    a_r_place.attach(new Button(Point(0,0), 0,0, "Add Place", cb_add_place));
    a_r_place.attach(new Button(Point(0,0), 0,0, "Remove Place", cb_remove_place));
    attach(a_r_place);
    a_r_place.hide();
    
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
    reference_to<Lines_window>(pw).add_remove_customer();  // next is defined next
}
void Lines_window::add_remove_customer() {
    add_remove_customer_pressed();
    
}

void Lines_window::cb_add_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).add_customer();  // next is defined next
}

void Lines_window::add_customer() {
    hide_add_remove_customer();
    cout<<"Add customer";
}

void Lines_window::cb_remove_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_customer();  // next is defined next
}
void Lines_window::remove_customer() {
    hide_add_remove_customer();
    cout<<"Remove customer";
}


///ADD/REMOVE DRIVER
void Lines_window::cb_add_remove_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).add_remove_driver();  // next is defined next
}
void Lines_window::add_remove_driver() {
    add_remove_driver_pressed();
    
}

void Lines_window::cb_add_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).add_driver();  // next is defined next
}

void Lines_window::add_driver() {
    hide_add_remove_driver();
    cout<<"Add driver";
}

void Lines_window::cb_remove_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_driver();  // next is defined next
}
void Lines_window::remove_driver() {
    hide_add_remove_driver();
    cout<<"Remove driver";
}


///ADD/REMOVE PLACE
void Lines_window::cb_add_remove_place(Address, Address pw) {
    reference_to<Lines_window>(pw).add_remove_place();  // next is defined next
}
void Lines_window::add_remove_place() {
    add_remove_place_pressed();
    
}

void Lines_window::cb_add_place(Address, Address pw) {
    reference_to<Lines_window>(pw).add_place();  // next is defined next
}

void Lines_window::add_place() {
    hide_add_remove_place();
    cout<<"Add place";
}

void Lines_window::cb_remove_place(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_place();  // next is defined next
}

void Lines_window::remove_place() {
    hide_add_remove_place();
    cout<<"Remove place";
}

//MAKE PAYMENT
void Lines_window::cb_payment(Address, Address pw) {
    reference_to<Lines_window>(pw).payment();  // next is defined next
}
void Lines_window::payment() {
    hide_main_menu();
    c_name_account.show();
    
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
    
  
