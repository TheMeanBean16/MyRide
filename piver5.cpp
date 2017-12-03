//Project ver 2

///NOTE TO SELF HIDE AND REATTACH BOXES SO INPUT IS CLEARED FOR NEXT CUSTOMER for back to main menu too!!!
//CSCE 121 Project Interface

//Katherine Ruff


#include <iostream>    // for i/o
#include <sstream>     // for string streams
#include "Graph.h"     // next 3 are for graphics library
#include "GUI.h"
#include "Window.h"
#include "hw5pr1_j.h"

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
                 const string& title,  // label
                 const string& file_name);   //file name
    
protected:
    MyRide my_ride;     // Object to call all of our myride functionalities
    
    
    Menu main_menu;     //menu for all of the main options of the program
    Button main_menu_button;
    Button quit_button;
    
    Button add_customer;
    Button remove_customer;
    
    Button add_driver;
    Button remove_driver;
    
    Button add_place;
    Button remove_place;
    
    Button change_account;
    
    Button request_ride;
    
    Button display_places;
    Button display_drivers;
    Button display_customers;
    
    Button next_button;
    Button prev_button;
    
    Menu how_to_display_places;
    Menu how_to_display_drivers;
    Menu how_to_display_customers;
    
    Menu screen_dim;
    
    int page=0;
    int last_page=0;
    
    Menu a_r_customer;
    Menu a_r_driver;
    Menu a_r_place;

    Button place_B_tags;
    Button place_B_name;
    
    char type_photos;
    char type_B='n';
    char type_place_disp='a';
    char type_screen_disp='1';
    
    char type_driver_disp='a';
    char type_customer_disp='a';
    char middle_page='y';
    
    string tag="";
    double dist=0;
    
    vector<Image*> imgs;
    vector<Text*> info;
    
   
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
    
    //Add new place boxes
    In_box p_name;
    In_box p_photo_name;
    In_box p_address;
    In_box p_tags;
    In_box p_latitude;
    In_box p_longitude;
    
    //Make Payment Boxes
    In_box c_name;
    In_box amount_money;
    
    //Request Ride Boxes
    In_box place_A_name;
    In_box place_B;
    
    //Display photos driver
    In_box d_no_miles;
    
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
    
    //functions for adding or removing places
    void add_remove_place_pressed(){
        hide_main_menu();
        a_r_place.show();
    }
    
    void add_place_option(){
        a_r_place.hide();
        p_name.show();
        p_photo_name.show();
        p_address.show();
        p_tags.show();
        p_latitude.show();
        p_longitude.show();
        add_place.show();
    }
    
    void Add_Place();
    
    void Add_Place_pressed(){
        main_menu_pressed();
        
    }
    
    void remove_place_option(){
        a_r_place.hide();
        p_name.show();
        remove_place.show();
    }
    
    void Remove_Place();
    
    void Remove_Place_pressed(){
        main_menu_pressed();
        
    }
    
    //Make Payment
    void make_payment_pressed(){
        hide_main_menu();
        
        c_name.show();
        amount_money.show();
        change_account.show();
    }
    
    void change_account_pressed(){
        main_menu_pressed();
    }
    void Make_Payment();
    
    //Request Ride
    
    //functions for adding or removing customers
    void request_ride_pressed(){
        hide_main_menu();
        c_name.show();
        place_A_name.show();
        place_B.show();
        place_B_name.show();
        place_B_tags.show();
        request_ride.show();
    }
    
    void Request_a_Ride();
    
    void Request_a_Ride_pressed(){
        c_name.hide();
        place_A_name.hide();
        place_B.hide();
        place_B_name.hide();
        place_B_tags.hide();
        request_ride.hide();
        
    }
    
   
    
    
    void tags_pressed(){
        type_B='t';
        
    }
    
    void name_pressed(){
        type_B='n';
        
    }
    
    void two_by_two_pressed(){
        type_screen_disp='1';
    }
    
    void three_by_three_pressed(){
        type_screen_disp='2';
        
    }
    
    void two_by_three_pressed(){
        type_screen_disp='3';
        
    }
    
    //functions for displaying window
    void display_photos_of_places_pressed(){
        hide_main_menu();
        display_places.show();
        screen_dim.show();
        how_to_display_places.show();
    }
    
    void Display_Places();
    
    void Display_Places_Pressed(){
        main_menu_pressed();
    }
    
    
    void all_places_pressed(){
        p_tags.hide();
        type_place_disp='a';
        
    }
    
    void a_places_certain_tag_pressed(){
        p_tags.show();
        type_place_disp='t';
        
    }
    
    //functions for displaying drivers
    
    void display_photos_of_drivers_pressed(){
        hide_main_menu();
        display_drivers.show();
        screen_dim.show();
        how_to_display_drivers.show();
    }
    
    void Display_Drivers();
    
    void Display_Drivers_Pressed(){
        main_menu_pressed();
    }
    
    
    void all_drivers_pressed(){
        d_no_miles.hide();
        p_tags.hide();
        
        type_driver_disp='a';
        
    }
    
    void a_drivers_certain_tag_pressed(){
        p_tags.show();
        d_no_miles.show();
        type_driver_disp='t';
        
    }
    
    
    
    
    void display_photos_of_customers_pressed(){
        hide_main_menu();
        display_customers.show();
        screen_dim.show();
        how_to_display_customers.show();
    }
    
    void Display_Customers();
    
    void Display_Customers_Pressed(){
        main_menu_pressed();
    }
    
    
    void all_customers_pressed(){
        type_customer_disp='a';
        
    }
    
    void a_customers_neg_balance_pressed(){
        
        type_customer_disp='n';
        
    }
    
    void quit(); //defined below
    //buton to end the program
    
    void next();
    
    void prev();
    
    void main_menu_pressed() {
        //Back to main menu button pressed
        page=0;
        main_menu_button.hide();
        a_r_customer.hide();
        add_customer.hide();
        
        remove_customer.hide();
        
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
        
        remove_driver.hide();
        
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
        
        a_r_place.hide();
        add_place.hide();
        remove_place.hide();
        
        p_name.hide();
        attach(p_name);
        p_name.hide();
        
        p_photo_name.hide();
        attach(p_photo_name);
        p_photo_name.hide();
        
        p_tags.hide();
        attach(p_tags);
        p_tags.hide();
        
        p_address.hide();
        attach(p_address);
        p_address.hide();
        
        p_longitude.hide();
        attach(p_longitude);
        p_longitude.hide();
        
        p_latitude.hide();
        attach(p_latitude);
        p_latitude.hide();
        
        c_name.hide();
        attach(c_name);
        c_name.hide();
        
        amount_money.hide();
        attach(amount_money);
        amount_money.hide();
        
        change_account.hide();
        
        
        place_B.hide();
        attach(place_B);
        place_B.hide();
        
        place_A_name.hide();
        attach(place_A_name);
        place_A_name.hide();
        
        place_B_name.hide();
        place_B_tags.hide();
        
        attach(place_B_name);
        attach(place_B_tags);
        place_B_name.hide();
        place_B_tags.hide();
        
        request_ride.hide();
        main_menu.show();
        
        how_to_display_places.hide();
        attach(how_to_display_places);
        how_to_display_places.hide();
        
        how_to_display_customers.hide();
        attach(how_to_display_customers);
        how_to_display_customers.hide();
        
        how_to_display_drivers.hide();
        attach(how_to_display_drivers);
        how_to_display_drivers.hide();
        
        screen_dim.hide();
        attach(screen_dim);
        screen_dim.hide();
        
        d_no_miles.hide();
        attach(d_no_miles);
        d_no_miles.hide();
        
        display_places.hide();
        display_customers.hide();
        display_drivers.hide();
        
        
        for(Image* i : imgs)  {
            detach(*i);
            delete i;
        }
        
        imgs.clear();
        
        for(Text* t : info)  {
            detach(*t);
            delete t;
        }
        
        info.clear();
        
        next_button.hide();
        prev_button.hide();
        
        
    }
    
    
    
    static void cb_next(Address, Address);
    static void cb_prev(Address, Address);
    static void cb_quit(Address, Address);
    
    static void cb_main_menu(Address, Address);
    
    //call back functions for buttons on main menu
    static void cb_add_remove_customer(Address, Address);
    static void cb_add_remove_driver(Address, Address);
    static void cb_add_remove_place(Address, Address);
    static void cb_make_payment(Address, Address);
    static void cb_request_ride(Address, Address);
    static void cb_display_photos_places(Address, Address);
    static void cb_display_photos_drivers(Address, Address);
    static void cb_display_photos_customers(Address, Address);
    
    
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
    
    //call back functions for place menu
    static void cb_add_place_option(Address, Address);
    static void cb_add_place(Address, Address);
    static void cb_remove_place_option(Address, Address);
    static void cb_remove_place(Address, Address);
    
    //callback functions for make payment menu
    static void cb_change_account(Address, Address);
    
    //callback functions for requesting a ride
    static void cb_request_a_ride(Address, Address);
    static void cb_type_B_menu(Address, Address);
    static void cb_tags_B(Address, Address);
    static void cb_name_B(Address, Address);
    
    //callback functions for displaying places
    static void cb_display_places(Address, Address);
    static void cb_how_to_display_places_menu(Address, Address);
    static void cb_a_places(Address, Address);
    static void cb_places_tag(Address, Address);
    
    //callback functions for displaying drivers
    static void cb_display_drivers(Address, Address);
    static void cb_how_to_display_drivers_menu(Address, Address);
    static void cb_a_drivers(Address, Address);
    static void cb_drivers_tag(Address, Address);
    
    //callback functions for displaying places
    static void cb_display_customers(Address, Address);
    static void cb_how_to_display_customers_menu(Address, Address);
    static void cb_a_customers(Address, Address);
    static void cb_customers_neg(Address, Address);
    
    //callback functions for screen display
    static void cb_two_by_two(Address, Address);
    static void cb_three_by_three(Address, Address);
    static void cb_two_by_three(Address, Address);
    
private:
    void my_error(string err) {
        my_ride.writeFile();
        
        error(err);
    }
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title,
                           const string& file_name):
// initialization - start by calling constructor of base class
Window(xy,w,h,title),

my_ride(file_name),                       //initialize MyRide Object

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
add_place(
          Point(200, 300), 100, 75, "Add Place", cb_add_place),


remove_customer(
                Point(200, 300), 100, 75, "Remove Customer", cb_remove_customer),

remove_driver(
              Point(200, 300), 100, 100, "Remove Driver", cb_remove_driver),

remove_place(
             Point(200, 300), 100, 100, "Remove Place", cb_remove_place),

change_account(
               Point(200, 300), 100, 75, "Change Account", cb_change_account),
request_ride(
             Point(200, 300), 100, 75, "Request Ride", cb_request_a_ride),
display_places(Point(200, 300), 100, 75, " Display Places", cb_display_places),
display_drivers(Point(200, 300), 100, 75, " Display Drivers", cb_display_drivers),
display_customers(Point(200, 300), 100, 75, " Display Customers", cb_display_customers),

a_r_customer(
             Point(100, 100),
             200, 200,
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
          "Add/Remove Place"),


how_to_display_places(
                      Point(30, 10),
                      35, 35,
                      Menu::vertical,
                      "How to Display Places"),
how_to_display_drivers(
                       Point(30, 10),
                       35, 35,
                       Menu::vertical,
                       "How to Display Drivers"),

how_to_display_customers(
                         Point(30, 10),
                         35, 35,
                         Menu::vertical,
                         "How to Display Customers"),

screen_dim(
           Point(30, 210),
           35, 35,
           Menu::vertical,
           "How to Display Places on the Screen"),



c_name_account( Point(200, 30), 100, 75, "Customer Name: "),
c_account_balance( Point(200, 100), 100, 75, "Account Balance: "),
c_photo_name(   Point(200, 170), 100, 75, "Customer Photo Name: "),


d_name_account( Point(200, 30), 100, 50, "Driver Name: "),
d_account_balance( Point(200, 80), 100, 50, "Driver Balance: "),
d_photo_name(    Point(200, 130), 100, 50, "Driver Photo Name: "),
d_latitude( Point(200, 180), 100, 50, "Driver latitude: "),
d_longitude(  Point(200, 220), 100, 50, "Driver longitude: "),
p_address(Point(200, 280), 150, 50, "Place Address: "),

p_name( Point(200, 30), 100, 50, "Place Name: "),
p_tags( Point(200, 130), 100, 50, "P-tags: "),
p_photo_name(   Point(200, 80), 100, 50, "Place Photo Name: "),
p_latitude( Point(200, 180), 100, 50, "Driver latitude: "),
p_longitude(  Point(200, 220), 100, 50, "Driver longitude: "),

c_name( Point(200, 30), 100, 50, "Customer Name: "),
amount_money( Point(200, 80), 100, 50, "Amount of Money" ),

place_A_name( Point(200, 80), 100, 50, "Name Place A: " ),
place_B      ( Point(200, 130), 100, 50,  " Place B: " ),

place_B_name(Point(200, 185),
             35, 35, "Name", cb_name_B),
place_B_tags(Point(245, 185),
             35, 35, "Tags", cb_tags_B),

next_button( Point(200, 350), 50, 50, "Next: " , cb_next),
prev_button( Point (50, 350), 50, 50, "Prev:", cb_prev),
d_no_miles( Point(200, 200), 100, 50, "Number of miles: ")

{
    attach(quit_button);
    
    attach(next_button);
    attach(prev_button);
    next_button.hide();
    prev_button.hide();
    
    main_menu.attach(new Button(Point(0,0), 100, 100, "Add/Remove Customer", cb_add_remove_customer));
    
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Driver", cb_add_remove_driver));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Add/Remove Place", cb_add_remove_place));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Make a Payment", cb_make_payment));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Request a Ride", cb_request_ride));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Display Photos of Places", cb_display_photos_places));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Display Photos of Drivers", cb_display_photos_drivers));
    main_menu.attach(new Button(Point(0,0), 0, 0, "Display Photos of Customers", cb_display_photos_customers));
    
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
    
    ///Add Remove Place Menu
    a_r_place.attach(new Button(Point(0,0), 0,0, "Add Place", cb_add_place_option));
    a_r_place.attach(new Button(Point(0,0), 0,0, "Remove Place", cb_remove_place_option));
    attach(a_r_place);
    a_r_place.hide();
    
    attach(p_name);
    p_name.hide();
    
    attach(p_tags);
    p_tags.hide();
    
    attach(p_address);
    p_address.hide();
    
    attach(p_photo_name);
    p_photo_name.hide();
    
    attach(add_place);
    add_place.hide();
    
    attach(remove_place);
    remove_place.hide();
    
    attach(p_longitude);
    p_longitude.hide();
    
    attach(p_latitude);
    p_latitude.hide();
    
    attach(d_no_miles);
    d_no_miles.hide();
    
    attach(c_name);
    c_name.hide();
    attach(amount_money);
    amount_money.hide();
    
    
    attach(change_account);
    change_account.hide();
    
    ///Request a ride
    attach(place_A_name);
    place_A_name.hide();
    
    attach(place_B_name);
    attach(place_B_tags);
    place_B_name.hide();
    place_B_tags.hide();
    
    
    attach(place_B);
    place_B.hide();
    
    attach(request_ride);
    request_ride.hide();
    
    
    ///How to Display Places Menu
    how_to_display_places.attach(new Button(Point(0,0), 0, 0, "All Places", cb_a_places));
    how_to_display_places.attach(new Button(Point(0,0), 0, 0, "All Places with a Tag", cb_places_tag));
    
    ///How to Display Places Menu
    how_to_display_drivers.attach(new Button(Point(0,0), 0, 0, "All Drivers", cb_a_drivers));
    how_to_display_drivers.attach(new Button(Point(0,0), 0, 0, "All Drivers with a certain Tag within a certain no. miles", cb_drivers_tag));
    
    ///How to Display Customers Menu
    how_to_display_customers.attach(new Button(Point(0,0), 0, 0, "All Customers", cb_a_customers));
    how_to_display_customers.attach(new Button(Point(0,0), 0, 0, "All Customers with a negative balance", cb_customers_neg));
    ///Screen Display Menu
    screen_dim.attach(new Button(Point(0,0), 0, 0, "2x2", cb_two_by_two));
    screen_dim.attach(new Button(Point(0,0), 0, 0, "3x3", cb_three_by_three));
    screen_dim.attach(new Button(Point(0,0), 0, 0, "2x3", cb_two_by_three));
    
    attach(d_no_miles);
    d_no_miles.hide();
    attach(how_to_display_places);
    attach(how_to_display_drivers);
    attach(how_to_display_customers);
    
    
    how_to_display_places.hide();
    how_to_display_drivers.hide();
    how_to_display_customers.hide();
    
    attach(screen_dim);
    screen_dim.hide();
    attach(display_places);
    attach(display_customers);
    attach(display_drivers);
    
    display_places.hide();
    display_customers.hide();
    display_drivers.hide();
    
}

///QUIT BUTTON
void Lines_window::cb_quit(Address, Address pw) {
    reference_to<Lines_window>(pw).quit();   // quit is defined next
}

void Lines_window::quit() {
    my_ride.writeFile();
    hide();                   // FLTK idiom for delete window
}

///NEXT BUTTON
void Lines_window::cb_next(Address, Address pw) {
    reference_to<Lines_window>(pw).next();   // quit is defined next
}

void Lines_window::next() {
  
    
    page++;
    
    for(Image* i : imgs)  {
        detach(*i);
        delete i;
        
    }
    imgs.clear();
    
    
    for(Text* t : info)  {
        detach(*t);
        delete t;
    }
    
    info.clear();
    
    if (type_photos=='d'){
        Display_Drivers(); }
    
    if(type_photos=='c'){
        Display_Customers();}
    
    if(type_photos=='p'){
        Display_Places();}
}

///PREV BUTTON
void Lines_window::cb_prev(Address, Address pw) {
    reference_to<Lines_window>(pw).prev();   // quit is defined next
}

void Lines_window::prev() {
    
    page--;
    
    for(Image* i : imgs)  {
        detach(*i);
        delete i;
        
    }
    
    for(Text* t : info)  {
        detach(*t);
        delete t;
        
    }
    imgs.clear();
    info.clear();
    
    cout<<imgs.size();
    
    if (type_photos=='d'){
        Display_Drivers(); }
    
    if(type_photos=='c'){
        Display_Customers();}
    
    if(type_photos=='p'){
        Display_Places();}

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
    
    //recieve information from the GUI
    stringstream ss;
    
    ss << c_name_account.get_string() << " "
    << c_account_balance.get_string() << " "
    << c_photo_name.get_string() << " " ;
    
    Customer c;
    
    ss >> c;
    
    if(!ss) {
        my_error("Invalid customer information");
    }
    
    my_ride.addCustomer(c);
    Add_Customer_pressed();
    
    cout<<"ADD NEW CUSTOMER" << endl;
}


///Remove Customer option
void Lines_window::cb_remove_customer_option(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_customer_option();  // next is defined next
}

void Lines_window::cb_remove_customer(Address, Address pw) {
    reference_to<Lines_window>(pw).Remove_Customer();
}

void Lines_window::Remove_Customer() {
    
    stringstream ss;
    
    ss << c_name_account.get_string() << " ";
    
    bool decision;
    decision = my_ride.removeCustomer(c_name_account.get_string());
    
    Remove_Customer_pressed();
    
    if (decision)
    {
        cout << "CUSTOMER REMOVED" << endl;
    }
    else
    {
        cout << "CUSTOMER NOT FOUND" << endl;
    }
    
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
    
    stringstream ss;
    
    ss << d_name_account.get_string() << " "
    << d_account_balance.get_string() << " "
    << d_latitude.get_string() << " "
    << d_longitude.get_string() << " "
    << d_photo_name.get_string() << " ";
    
    Driver d;
    
    ss >> d;
    
    if (!ss) {
        my_error("Invalid driver information");
    }
    
    my_ride.addDriver(d);
    
    Add_Driver_pressed();
    
}


///Remove Driver option
void Lines_window::cb_remove_driver_option(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_driver_option();  // next is defined next
}

void Lines_window::cb_remove_driver(Address, Address pw) {
    reference_to<Lines_window>(pw).Remove_Driver();
}

void Lines_window::Remove_Driver() {
    
    stringstream ss;
    
    ss << d_name_account.get_string() << " ";
    
    bool decision;
    decision = my_ride.removeDriver(d_name_account.get_string());
    
    Remove_Driver_pressed();
    
    if (decision)
    {
        cout << "DRIVER REMOVED" << endl;
    }
    else
    {
        cout << "DRIVER NOT FOUND" << endl;
    }
}



///ADD/REMOVE PLACE
void Lines_window::cb_add_remove_place(Address, Address pw) {
    reference_to<Lines_window>(pw).add_remove_place_pressed();  // next is defined next
    
}


///Add Place option
void Lines_window::cb_add_place_option(Address, Address pw) {
    reference_to<Lines_window>(pw).add_place_option();  // next is defined next
}

void Lines_window::cb_add_place(Address, Address pw) {
    reference_to<Lines_window>(pw).Add_Place();
}

void Lines_window::Add_Place() {
    
    stringstream ss1;
    
    string name = p_name.get_string();                          //name of location
    string address = p_address.get_string();                       //name of address
    vector<string> tags;                  //tags of the location
    Geo_loc location;                                //location (lat and lon)
    String photo = p_photo_name.get_string();
    
    ss1 << p_latitude.get_string() << " "
    << p_longitude.get_string();
    
    ss1 >> location;
    
    if (!ss1)
    {
        my_error("Invalid latitude and longitude");
    }
    
    stringstream ss;
    
    ss << p_tags.get_string();
    
    string tag;

    while (ss >> tag)
    {
        if (!ss)
        {
            my_error("Invalid tags");
        }
        
        tags.push_back(tag);
        
        if (ss.peek() == ',' || ss.peek() == ' ')
        {
            ss.ignore();
        }
    }
    Place_info p;
    
    p = Place_info(name, address, tags, location, photo);
    
    my_ride.addPlace(p);
    
    
    Add_Place_pressed();
    
    cout<<"ADD NEW PLACE" << endl;
     
}

///Remove Place option
void Lines_window::cb_remove_place_option(Address, Address pw) {
    reference_to<Lines_window>(pw).remove_place_option();  // next is defined next
}

void Lines_window::cb_remove_place(Address, Address pw) {
    reference_to<Lines_window>(pw).Remove_Place();
}

void Lines_window::Remove_Place() {
    
    String place_name= p_name.get_string();
    
    
    bool decision;
    decision = my_ride.removePlace(place_name);
    
    
    Remove_Place_pressed();
    
    if (decision)
    {
        cout << "PLACE REMOVED" << endl;
    }
    else
    {
        cout << "PLACE NOT FOUND" << endl;
    }
    
    
    
    cout<<"REMOVED PLACE" << endl;
    
}



///ADD/REMOVE DRIVER
void Lines_window::cb_make_payment(Address, Address pw) {
    reference_to<Lines_window>(pw).make_payment_pressed();  // next is defined next
}

void Lines_window::cb_change_account(Address, Address pw) {
    reference_to<Lines_window>(pw).Make_Payment();  // next is defined next
}

void Lines_window::Make_Payment(){
    
    stringstream ss;
    double pay;
    
    ss << amount_money.get_string() << " ";
    ss >> pay;
    if (!pay)
    {
        my_error("Pay must be a double");
    }
    
    bool decision;
    
    decision = my_ride.makePayment(c_name.get_string(), pay);
    
    change_account_pressed();
    
    if (decision)
    {
        cout << "PAYMENT CREDITED" << endl;
    }
    else
    {
        my_error("COULD NOT FIND CUSTOMER/ INVALID AMOUNT");
    }
    
    
}


///REQUEST A RIDE
void Lines_window::cb_request_ride(Address, Address pw) {
    reference_to<Lines_window>(pw).request_ride_pressed();  // next is defined next
}

void Lines_window::cb_request_a_ride(Address, Address pw){
    reference_to<Lines_window>(pw).Request_a_Ride();  // next is defined next
    
}

void Lines_window::Request_a_Ride(){
    
    
        String customer_name = c_name.get_string();
        String place_A_info = place_A_name.get_string();
        String tag="";
        String place_B_info = "";
    
        vector<Customer> customers = my_ride.customers;
        vector<Driver> drivers = my_ride.drivers;
        vector<Place_info> places = my_ride.locations;
    
        if (drivers.size() == 0) {
            //if there are no drivers return to menu
            cout << "\nThere must be one driver in the system\nReturning you to the menu\n";
            main_menu_pressed();
            return;
        }
        else if (customers.size() == 0) {
            //if there are no customers return to menu
            cout << "\nThere must be one customer in the system\nReturning you to the menu\n";
            main_menu_pressed();
            return;
        }
    
        int customer_index = -1;    //start index as invalid
        //iterate through customers
        for (size_t i = 0; i < customers.size(); i++) {
            if (customers[i].getName() == customer_name) {
                //when we found the customer the user was talking about
                customer_index = i;
                break;
            }
        }
    
        if (customer_index == -1) {
            //customer index was not found
            cout << "CUSTOMER NOT FOUND" << endl;
            main_menu_pressed();
            return;
        }
    
        //the customer recieving the drive
        Customer& customer = customers[customer_index];
    
        Place_info starting_location;
    
        int start_index = -1;    //start index as invalid
        //iterate through places
        for (size_t i = 0; i < places.size(); i++) {
            if (places[i].getName() == place_A_info) {
                //when we found the place the user was talking about
                start_index = i;
                break;
            }
        }
    

        if (start_index == -1) {
            //start index was not found
            cout << "PLACE NOT FOUND" << endl;
            main_menu_pressed();
            return;
        }
    
    starting_location= places[start_index];
    
        Place_info destination;
    
        if (type_B == 't')
        {
            tag = place_B.get_string();
            
            
            for (int i = 0; i < places.size(); i++) {
                bool contain = false;
                for (String t : places[i].getTags()){
                    contain |= (tag == t);
                }
                if (!contain)
                {
                    places.erase(places.begin() + i--);
                }
            }
            int index = 0;
            if (places.size() == 0)
            {
                cout << "NO PLACE WITH GIVEN TAG" << endl;
                main_menu_pressed();
                return;
            }
            double min_dist = distance(starting_location.getLocation(), places[0].getLocation());
            double dist = 0;
            for (int i = 1; i < places.size(); i++)
            {
                dist = distance(starting_location.getLocation(), places[i].getLocation());
                if (min_dist > dist){
                    min_dist=dist;
                    index = i;
                }
            }
            destination = places[index];
        }
        else
        {
            place_B_info = place_B.get_string();
            
            int index = -1;
            for (int i = 0; i < places.size(); i++)
            {
                if (places[i].getName() == place_B_info)
                {
                    index = i;
                    break;
                }
            }
            
            if (index != -1)
            {
                destination = places[index];
            }
            else
            {
                cout << "PLACE NOT FOUND" << endl;
                main_menu_pressed();
                return;
            }
            
        }
    
        //find closest driver
        int closest_driver_index = 0;     //assume first is the closest
        double min_distance = distance(drivers[0].getGeoLocation(), starting_location.getLocation());
    
        //iterate list trying to find a driver closer
        for (size_t i = 1; i < drivers.size(); i++) {
            if (min_distance > distance(drivers[i].getGeoLocation(), starting_location.getLocation())) {
                //if this driver is closer update variables
                min_distance = distance(drivers[i].getGeoLocation(), starting_location.getLocation());
                closest_driver_index = i;
            }
        }
    
        //Driver driving the customer has been found
        Driver closest_driver = drivers[closest_driver_index];
    
        //move driver to destination
        closest_driver.setLocation(destination.getLocation());
    
        //calculate consts
        double trip_distance = distance(starting_location.getLocation(), destination.getLocation());
    
        //confirm the users
        cout << "The trip from " << starting_location.getName()
        << " to " << destination.getName() << " was " << trip_distance << " miles away.\n";
    
        //Add credit to the driver
        closest_driver.addCredit(trip_distance*0.5);
        //charge the customer
        customer.charge(trip_distance);
    
        //print out travel information to the user
        cout << "Driver " << closest_driver.getName();
        printf(" recieved $%.2f.\n", trip_distance*0.5);
        cout << "Customer " << customer.getName();
        printf(" was charged $%.2f.\n", trip_distance);
    
    
        Request_a_Ride_pressed();
    
    int l = x_max()-50;   //length of screen
    int w = y_max();    //width of screen
    int r=2;
    int c=2;
    
    imgs.push_back(new Image(Point(5, 5), customer.getPhoto()+".jpg"));
    info.push_back(new Text(Point(5, 20+w/r-60), "Customer: "+customer.getName()));
    
    imgs.push_back(new Image(Point(5+l/c, 5), closest_driver.getPhoto()+".jpg"));
    info.push_back(new Text(Point(5+l/c, 20+w/r-60), "Driver: "+closest_driver.getName()));
    
    imgs.push_back(new Image(Point(5, 5+w/r), starting_location.getPhoto()+".jpg"));
    info.push_back(new Text(Point(5, 20+2*w/r-60), "Place A:"+starting_location.getName()));
    
    imgs.push_back(new Image(Point(5+l/c, 5+w/r), destination.getPhoto()+".jpg"));
    info.push_back(new Text(Point(5+l/c, 20+2*w/r-60),"Place B:"+ destination.getName()));
    


    for(Image* i : imgs)  {
        i->resize(l/c-100, w/r-60);
        attach(*i);
    }
    
    for(Text* t: info){
        attach(*t);
    }
    
    
    

}

void Lines_window::cb_name_B(Address, Address pw) {
    reference_to<Lines_window>(pw).name_pressed();  // next is defined next
}

void Lines_window::cb_tags_B(Address, Address pw) {
    reference_to<Lines_window>(pw).tags_pressed();  // next is defined next
}

///Display Photos of Places
void Lines_window::cb_display_photos_places(Address, Address pw) {
    reference_to<Lines_window>(pw).display_photos_of_places_pressed();  // next is defined next
    
}

void Lines_window::cb_display_places(Address, Address pw) {
    reference_to<Lines_window>(pw).Display_Places();
    // next is defined next
    
}

void Lines_window::Display_Places(){
    type_photos='p';
    vector<Place_info> places = my_ride.locations;
    cout<<"Places size"<<places.size();
    
    if(type_place_disp == 't')  {
        //display all places with this tag
        tag = p_tags.get_string();
      
        for(int i = 0; i < places.size(); i++)  {
            bool contain = false;
            for(String t : places[i].getTags()) {
                contain |= (tag == t);
            }
            if(!contain)
            { places.erase(places.begin()+i--);}
        }
        
        if(places.size()==0){
        info.push_back(new  Text(Point(100, 100),"There are no places like that in our system" ));
        }
        p_tags.hide();
    }
    
    int l = x_max()-50;   //length of screen
    int w = y_max();    //width of screen
    double r = -1;
    double c = -1;
    int last_page;
    if(type_screen_disp == '1') {
        //print 2x2
        r = 2;
        c = 2;
        
        last_page=ceil(places.size()/4.0)-1;
    }
    else if(type_screen_disp == '2')  {
        //print 3x3
        r = 3;
        c = 3;
        last_page=ceil(places.size()/9.0)-1;
    }
    else if(type_screen_disp == '3')  {
        //print 2x3
        r = 2;
        c = 3;
        last_page=ceil(places.size()/6.0)-1;
    }
    else {
        error("type_screen_disp was not 1, 2 or 3");
    }
    
    next_button.hide();
    prev_button.hide();
    
    next_button.show();
    prev_button.show();
    
    
    if (page==0){
        prev_button.hide();
    }
    
    
    if( (page==last_page)|| (places.size()==0)){
        next_button.hide();
    }
    
    int index = page*r*c;
    how_to_display_places.hide();
    screen_dim.hide();
    display_places.hide();
    
    
    for(int i = 0; i < r; i++)  {
        for(int j = 0; j < c; j++)  {
            if(index< places.size()){
                string tags;
                for(auto i : places[index].getTags()){
                    tags+=" "+i;
                    
                }
                imgs.push_back(new Image(Point(5+ j*l/c, 5 + i*w/r), places[index].getPhoto()+".jpg"));
                info.push_back(new Text(Point(5+ j*l/c, 16 + i*w/r+w/r-60),
                                        "Name: "+places[index].getName() ));
                info.push_back(new Text(Point(5+ j*l/c, 26 + i*w/r+w/r-60),
                                        "Location: "+(places[index].getLocation()).print() ));
                info.push_back(new Text(Point(5+ j*l/c, 36 + i*w/r+w/r-60), "Tags: "+tags));
                index++;
            }
        }
    }
    
    
    for(Image* i : imgs)  {
        i->resize(l/c-100, w/r-60);
        attach(*i);
    }
    
    for(Text* t: info){
        attach(*t);
    }
    
    places.clear();
}
    



void Lines_window::cb_a_places(Address, Address pw) {
    reference_to<Lines_window>(pw).all_places_pressed();  // next is defined next
}

void Lines_window::cb_places_tag(Address, Address pw) {
    reference_to<Lines_window>(pw).a_places_certain_tag_pressed();  // next is defined next
}





///Diplay photos of drivers
void Lines_window::cb_display_photos_drivers(Address, Address pw) {
    reference_to<Lines_window>(pw).display_photos_of_drivers_pressed();  // next is defined next
    
}

void Lines_window::cb_display_drivers(Address, Address pw) {
    reference_to<Lines_window>(pw).Display_Drivers();
    // next is defined next
    
}

void Lines_window::Display_Drivers(){
    type_photos='d';
    //get the Drivers from my_ride
    vector<Driver> drivers = my_ride.getDrivers();
    
    if(type_driver_disp == 't') {
        
        //display all drivers within a certain location of a place with a tag
        tag = p_tags.get_string();
        vector<Place_info> places = my_ride.locations;
        
        vector<Place_info> places_w_tags;
        
        //prune list
        for(int i = 0; i < places.size(); i++)  {
            for(String t : places[i].getTags()) {
                if(t == tag)  {
                    places_w_tags.push_back(places[i]);
                }
            }
        }
        
        dist= d_no_miles.get_int();
        //prune Drivers
        cout<<"Num places that have tag"<<places_w_tags.size()<<endl;
        ///cout<<places_w_tags.size();
        ///cout<<places_w_tags[0].getName();
        
        if(places_w_tags.size()==0){
            drivers.clear();
        }
       
        else {
            for(int i = 0; i < drivers.size(); i++) {
                bool close = false;
                for(int j = 0; j < places_w_tags.size(); j++){
                    close |= distance(drivers[i].getGeoLocation(), places_w_tags[j].getLocation()) <= dist;
                }
                if(!close)  {
                    drivers.erase(drivers.begin()+i--);
                }
            }
        }
        
        cout<<"Drivers that qualify"<<drivers.size()<<endl;
        
        
        
        p_tags.hide();
        d_no_miles.hide();
        
        next_button.hide();
        prev_button.hide();
        
        if (drivers.size()==0 ){
            info.push_back(new  Text(Point(100, 100),"There are no drivers like that in our system" ));
        }
        
        if (places_w_tags.size()==0 ){
            info.push_back(new  Text(Point(100, 120),"There are no places with that tag   in our system" ));
        }
        
       
    }
    int l = x_max()-50;   //length of screen
    int w = y_max();    //width of screen
    int r = -1;
    int c = -1;
    int last_page;
    if(type_screen_disp == '1') {
        //print 2x2
        r = 2;
        c = 2;
        
        last_page=ceil(drivers.size()/4.0)-1;
    }
    else if(type_screen_disp == '2')  {
        //print 3x3
        r = 3;
        c = 3;
        last_page=ceil(drivers.size()/9.0)-1;
    }
    else if(type_screen_disp == '3')  {
        //print 2x3
        r = 2;
        c = 3;
        last_page=ceil(drivers.size()/6.0)-1;
    }
    else {
        error("type_screen_disp was not 1, 2 or 3");
    }
    
    next_button.hide();
    prev_button.hide();
    
    next_button.show();
    prev_button.show();
    

    
    if (page==0){
        prev_button.hide();
    }
    
    
    if( (page==last_page) || (drivers.size()==0)){
        next_button.hide();
    }
    
    

    int index = page*r*c;
    how_to_display_drivers.hide();
    screen_dim.hide();
    display_drivers.hide();
    
    
    
    for(int i = 0; i < r; i++)  {
        for(int j = 0; j < c; j++)  {
            if(index< drivers.size()){
                 stringstream ss;
                 ss<<drivers[index].getAccount();
                
                imgs.push_back(new Image(Point(5+ j*l/c, 5 + i*w/r), drivers[index].getPhoto()+".jpg"));
                info.push_back(new Text(Point(5+ j*l/c, 16 + i*w/r+w/r-60),
                                        "Name: "+drivers[index].getName() ));
                info.push_back(new Text(Point(5+ j*l/c, 26 + i*w/r+w/r-60),
                                        "Location: "+(drivers[index].getGeoLocation()).print() ));
                info.push_back(new Text(Point(5+ j*l/c, 36 + i*w/r+w/r-60), "Account: "+ss.str()));
                index++;
            }
        }
        
    }
    
    
    
     for(Image* i : imgs)  {
     i->resize(l/c-100, w/r-60);
     attach(*i);
     }
    
    for(Text* t: info){
        attach(*t);
    }
   
    //Display_Drivers_Pressed();
}

void Lines_window::cb_a_drivers(Address, Address pw) {
    reference_to<Lines_window>(pw).all_drivers_pressed();  // next is defined next
}

void Lines_window::cb_drivers_tag(Address, Address pw) {
    reference_to<Lines_window>(pw).a_drivers_certain_tag_pressed();  // next is defined next
}


///Display photos of customers
void Lines_window::cb_display_photos_customers(Address, Address pw) {
    reference_to<Lines_window>(pw).display_photos_of_customers_pressed();  // next is defined next
}

void Lines_window::cb_display_customers(Address, Address pw) {
    reference_to<Lines_window>(pw).Display_Customers();
    // next is defined next
    
}

void Lines_window::Display_Customers(){
    vector<Customer> customers = my_ride.getCustomers();
    
    type_photos='c';
    if(type_customer_disp == 'n')   {
        //prune negative customers
        for(int i = 0; i < customers.size(); i++)
        {
            if(customers[i].getAccount() >= 0)   {
                customers.erase(customers.begin() + i--);
            }
        }
        
       
        
        if (customers.size()==0){
            info.push_back(new  Text(Point(100, 100),"There are no customers like that in our system" ));
            
        }
    }
    
    int l = x_max()-50;   //length of screen
    int w = y_max();    //width of screen
    int r = -1;
    int c = -1;
    int last_page;
    if(type_screen_disp == '1') {
        //print 2x2
        r = 2;
        c = 2;
        
        last_page=ceil(customers.size()/4.0)-1;
    }
    else if(type_screen_disp == '2')  {
        //print 3x3
        r = 3;
        c = 3;
        last_page=ceil(customers.size()/9.0)-1;
    }
    else if(type_screen_disp == '3')  {
        //print 2x3
        r = 2;
        c = 3;
        last_page=ceil(customers.size()/6.0)-1;
    }
    else {
        error("type_screen_disp was not 1, 2 or 3");
    }
    
    next_button.hide();
    prev_button.hide();
    
    next_button.show();
    prev_button.show();
    
    
    if (page==0){
        prev_button.hide();
    }
    
    
    if( (page==last_page) || (customers.size()==0)){
        next_button.hide();
    }
    cout<<"Page: "<<page;
    
    int index = page*r*c;
    how_to_display_customers.hide();
    screen_dim.hide();
    display_customers.hide();
    
    
    for(int i = 0; i < r; i++)  {
        for(int j = 0; j < c; j++)  {
            if(index< customers.size()){
                cout<<"Index of photo: "<<index<<endl;

                stringstream ss;

                imgs.push_back(new Image(Point(5+ j*l/c, 5 + i*w/r), customers[index].getPhoto()+".jpg"));
                info.push_back(new Text(Point(5+ j*l/c, 16 + i*w/r+w/r-60), "Name: "+customers[index].getName() ));
                
                ss<<customers[index].getAccount();
                
                info.push_back(new Text(Point(5+ j*l/c, 26 + i*w/r+w/r-60), "Account: "+ss.str()));
                index++;

            }
        }
        
    }
    
    
    
    for(Image* i : imgs)  {
        i->resize(l/c-100, w/r-60);
        attach(*i);
    }
    
    for(Text* t: info){
        attach(*t);
       
    }
    
}

void Lines_window::cb_a_customers(Address, Address pw) {
    reference_to<Lines_window>(pw).all_customers_pressed();  // next is defined next
}

void Lines_window::cb_customers_neg(Address, Address pw) {
    reference_to<Lines_window>(pw).a_customers_neg_balance_pressed();  // next is defined next
}

///display dimensions window
void Lines_window::cb_two_by_two(Address, Address pw) {
    reference_to<Lines_window>(pw).two_by_two_pressed();  // next is defined next
}

void Lines_window::cb_two_by_three(Address, Address pw) {
    reference_to<Lines_window>(pw).two_by_three_pressed();  // next is defined next
}

void Lines_window::cb_three_by_three(Address, Address pw) {
    reference_to<Lines_window>(pw).three_by_three_pressed();  // next is defined next
}



int main()
try {
    // construct the GUI window
    Lines_window win(Point(100,100),600,400,"lines", "testdoc.txt");
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

