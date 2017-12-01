/*
Diego Ruvalcaba
Fall Semester 2017 (Sept 27)
Solution for hw5 problem 1.
*/


/*
  A fully functioning MyRide share.
  People can become drivers and drive customers around
  Drivers get commision and Customers pay for the sevices.

  Now able to read input from files and output driver and
  customer info upon exiting
*/

#include "std_lib_facilities_4.h"

class Geo_loc {
//Geo_loc class stores a location as a latitude and longitude
public:

  double lat; //stores latitude
  double lon; //stores longitude

  //constructor (initializes member variables)
  Geo_loc(): lat(0), lon(0) {};
  Geo_loc(double latt, double lonn) : lat(latt), lon(lonn){};

  vector<double> getLocation()  const {
    //returns a vector containing latitude and logitude
    vector<double> location;
    location.push_back(lat);
    location.push_back(lon);
    return location;
  }

  double getLatitude()  const {
    //returns latitude
    return lat;
  }

  double getLongitude() const {
    //returns longitude
    return lon;
  }

  void print()  {
    //Prints out the location as latituede and longitude
    cout << "Location: \t"
         << lat << ", " << lon << endl;
  }

};
//END OF GEO_LOC CLASS
ostream& operator<<(ostream& os, const Geo_loc& location)  {
  //prints out location as latitude and longitude
  os << "Location: \t" << location.getLatitude() << ", " << location.getLongitude() << endl;
  return os;
}

//for taking in input of Geo_loc
istream& operator>>(istream& is, Geo_loc& location) {

  //format should be two doubles

  double lat, lon;      //storing latitude and longitude

  is >> lat >> lon;

  //if bad state return
  if(!is)
    return is;

  //initialize Geo_loc
  location = Geo_loc(lat, lon);
  return is;
}

double rad (double degree) {
  //Converts degree to radians
  constexpr double PI = 3.14159265359;
  return degree * (PI / 180);
}

double distance (Geo_loc loc1, Geo_loc loc2) {
  //computes distance given two Geo_locs, 2 latitudes and 2 longitude

  constexpr double earth_radius = 3963.1676;       //radius of the earth

  //access location variables for first location
  double lat1 = loc1.getLatitude();
  double lon1 = loc1.getLongitude();

  //access location variables for second location
  double lat2 = loc2.getLatitude();
  double lon2 = loc2.getLongitude();

  //compute distance
  return acos(sin(rad(lat1)) * sin(rad(lat2)) + cos(rad(lat1)) * cos(rad(lat2)) *
        cos(rad(lon1 - lon2))) * earth_radius;
}

class Place_info  {
//Place_info is a class that stores a Geo_location but also has location variables like name and addresses as well as tags pertaining to the location
public:

  string name;          //the name of the place
  string address;       //the address of the place
  vector<string> tags;  //tags associated with the place (e.g. bar, gym..)
  Geo_loc location;     //the location (latitude and longitude represented as a Geo_loc)
  String photo;         //the file location of the photo

  //constructors

  //default
  Place_info() : name(""), address(""), location(Geo_loc(0,0)), photo("") {};

  //regular constructor
  Place_info(string location_name, string address_, vector<string> tags_,
    Geo_loc locationn, string ph) : name(location_name), address(address_), tags(tags_),
    location(locationn), photo(ph) {};

  //accessor functions

  string getPhoto() const {
    //returns the file path for the photo
    return photo;
  }

  string getName()  const {
    //returns the name of the location
    return name;
  }

  string getAddress() const {
    //returns the name of the address
    return address;
  }

  vector<string> getTags()  const {
    //returns the tags associated with the Place_info
    return tags;
  }

  Geo_loc getLocation() const {
    //returns the locations represented as a Geo_loc
    return location;
  }


  void print() {
    //prints out all of the member functions in a nice format
    cout << name << endl
         << "Address :\t"<< address << endl
         << "Tags :\t\t";

    //print tags as a list
    for(size_t i = 0; i < tags.size(); i++) {
      if(i == tags.size() - 1)
        cout << "and " << tags[i] << endl;
      else
        cout << tags[i] << ", ";
    }
    cout << "Photo:\t" << photo << endl;
    //print location
    location.print();
    cout << endl;
  }
};
//END OF PLACE_INFO CLASS

//printing function
ostream& operator<<(ostream& os, const Place_info& place)  {
  //prints out all of the member functions in a nice format
  os << place.getName() << endl
       << "Address :\t"<< place.getAddress() << endl
       << "Tags :\t\t";

  //print tags as a list
  vector<String> tags = place.getTags();
  for(size_t i = 0; i < tags.size(); i++) {
    if(i == tags.size() - 1)
      os << "and " << tags[i] << endl;
    else
      os << tags[i] << ", ";
  }

  //print location
  os << "Photo:\t" << place.getPhoto() << endl;
  os << place.getLocation();
  os << endl;
  return os;
}

istream& operator>>(istream& is, Place_info& place)  {
  //format should be name, address, latitude and longitude, a number of tangs (n) followed by n tags.

  string name;                          //name of location
  string address;                       //name of address
  vector<string> tags;                  //tags of the location
  Geo_loc location;                     //location (lat and lon)
  String photo;                          //file location of the photo

  is >> name >> address >> location;    //read in variables

  //if in bad state return is
  if(!is) {
    return is;
  }

  int num_tags;                         //stores number of tags

  is >> num_tags;                       //read in variable

  //if in bad stat return is
  if(!is) {
    return is;
  }

  for(int i = 0; i < num_tags; i++) {
    string curr_tag;        //storing current tag

    is >> curr_tag;         //read from file

    //if in bad state return
    if(!is) {
      return is;
    }

    tags.push_back(curr_tag); //add to tags
  }

  is >> photo;

  ifstream p{photo};
  if(!p)  {
    is.setstate(std::ios::failbit);
  }

  if(!is) {
    return is;
  }

  //initialize place
  place = Place_info(name, address, tags, location, photo);
  //return good state of istream
  return is;
}


class Driver {
  //Driver class is used to store information of a driver such as name, location, and account value
public:

  string name;          //Name of the driver
  double account;       //amount of money driver has
  Geo_loc location;  //current location
  string photo;       //file location of their photo

  //constructor
  Driver(): name(""), account(0), location(Geo_loc()), photo("") {};

  Driver(string d_name, Geo_loc d_location, string ph) :
          name(d_name), account(0), location(d_location), photo(ph) {};

  Driver(string d_name, double acc, Geo_loc d_location, string ph) :
          name(d_name), account(acc), location(d_location), photo(ph) {};

  //accessor functions
  string getPhoto() const {
    //returns file location of Photo
    return photo;
  }
  string getName() const  {
    //accesor to get name of the driver
    return name;
  }

  double getAccount() const {
    //accesor to get the amount of money the driver has
    return account;
  }

  Geo_loc getGeoLocation() const  {
    //returns the Geo_location (latitude and longitude)
    return location;
  }

  //setting methods
  void addCredit(double credit) {
    //adds credit to the account
    account += credit;
  }

  void setLocation(Geo_loc l)  {
    //updates location of the driver
    location = l;
  }

  //printing
  void print()  {
    //Prints out everything in a nice format
    cout << "Name:\t\t" << name << endl
          << "Account:\t$";
    //prints account value to 2 digits
    printf("%.2f\n", account);
    cout << "Photo:\t" << photo << endl;
    cout << location;
  }

};
//END OF DRIVER CLASS

//print function
ostream& operator<<(ostream& os, const Driver& d) {
  //Prints out everything in a nice format
  os << "Name:\t\t" << d.getName() << endl
        << "Account:\t$";
  //prints account value to 2 digits
  os << d.getAccount() << endl;
  os << "Photo:\t" << d.getPhoto() << endl;
  os << d.getGeoLocation();
  return os;
}

//input function override
istream& operator>>(istream& is, Driver& d)  {
  //format should be name, balance, latitude and longitude.

  string name;    //storing Driver's Name
  double bal;     //Starting balance for diver account
  double lat, lon; //starting location
  string photo;   //photo info

  is >> name >> bal >> lat >> lon >> photo;

  ifstream p{photo};
  if(!p)  {
    is.setstate(std::ios::failbit);
  }

  //if wrong format return bad istream
  if(!is) {
    return is;
  }


  //initializes driver
  d = Driver(name, bal, Geo_loc(lat, lon), photo);
  //returns good istream
  return is;
}

class Customer  {

public:

  string name;          //Name of the customer
  double account;       //amount of money customer
  string photo;         //file name of the photo

  //constructors

  //default
  Customer() : name(""), account(0), photo("") {};

  //constuctor that initializes members
  Customer(string c_name, string ph) :
            name(c_name), account(0), photo(ph) {};

  Customer(string c_name, double bal, string ph) :
            name(c_name), account(bal), photo(ph) {};

  //accessor functions

  string getPhoto() const {
    return photo;
  }

  string getName() const  {
    //accesor to get name of the customer
    return name;
  }

  double getAccount() const {
    //accesor to get the amount of money the customer has
    return account;
  }

  void addCredit(double credit) {
    //adds credit to the account
    account += credit;
  }

  void charge(double debit) {
    //charges account
    account -= debit;
  }

  //print function
  void print()  {
    //prints out in a nice format
    cout << "Name:\t\t" << name << endl
          << "Account:\t$";
    //Prints accout in 2 decimal format
    printf("%.2f\n", account);
    cout << "Photo\t" << photo << endl;
  }

};
//END OF CUSTOMER CLASS
//print Customer
ostream& operator<<(ostream& os, const Customer& c) {
  //prints out in a nice format
  os << "Name:\t\t" << c.getName() << endl
        << "Account:\t$";
  //Prints accout in 2 decimal format
  os << c.getAccount() << endl;
  os << "Photo:\t" << c.getPhoto() << endl;
  return os;
}
//override >> for customers
istream& operator>>(istream& is, Customer& c) {
  //format should be name and balance

  string name;      //storing customers name
  double bal;       //starting balance for customers
  string photo;     //file name for the photo


  is >> name >> bal >> photo;

  ifstream p{photo};
  if(!p)  {
    is.setstate(std::ios::failbit);
  }

  //if wrong format return bad istream
  if(!is) {
    return is;
  }

  //initialize custoemer
  c = Customer(name, bal, photo);
  //return good istream
  return is;
}

class MyRide  {
  //MYRide class contians all of its members like drivers and customers
public:
  vector<Driver> drivers;       //keeps track of employees
  vector<Customer> customers;   //keeps track of customers
  vector<Place_info> locations; //keeps track of loctions
  string file_name;             //keeps track of input/ouptut file

  MyRide()  { /*initLoc();*/ }; //default constructor

    MyRide(string file) : file_name(file) {readFile();} //with file
  //accesor functions
  vector<Driver> getDrivers() const {
    //returns drivers in the system
    return drivers;
  }

  vector<Customer> getCustomers() const {
    //returns customers in the system
    return customers;
  }

  void addCustomer(const Customer &c)  {
    //adds a new customer to the system

    customers.push_back(c);

    //comfirm to the user
    cout << endl << c.getName() << " has been added into the system" << endl << endl;
  }

  //returns true if customer was found and removes, false if the name wasnt found
  bool removeCustomer(string name)  {
    for(int i = 0; i < customers.size(); i++) {
      if(customers[i].getName() == name) {
        customers.erase(customers.begin()+i);
        return true;
      }
    }
    return false;
  }

  void addDriver(const Driver &d)  {

    drivers.push_back(d);       //adds driver to the system

    //confirms to the user
    cout << endl << d.getName() << " has been added to the system.\n" << endl;

  }

  //returns true if driver was found and removes, false if the name wasnt found
  bool removeDriver(string name)  {
    for(int i = 0; i < drivers.size(); i++) {
      if(drivers[i].getName() == name) {
        drivers.erase(drivers.begin()+i);
        return true;
      }
    }
    return false;
  }

  void printLocations() {
    //prints out a menu of all locations
    for(size_t i = 1; i <= locations.size(); i++) {
      cout << "(" << i << ") " << locations[i-1].getName() << endl;
    }
  }

  void printLocationsInfo() {
    //prints out locations and info
    for(size_t i = 0; i < locations.size(); i++)  {
      locations[i].print();
    }
  }

  void printCustomers()  {
    //prints out a menu of all the Customers
    for(size_t i = 1; i <= customers.size(); i++) {
      cout << "(" << i << ") " << customers[i-1].getName() << endl;
    }
  }

  void makePayment()  {
    //add credit to a user
    if(customers.size() == 0) {
      //if there are no users, then no one can add to an account
      cout << "There are no customers to account for!" << endl;
      return;
    }

    //add credit to a customer
    string input;   //input of the user
    //customer_index will stay -1 with bad input
    int customer_index = -1;
    bool cont = true;       //loop to continue asking user for correct input

    while(cont)  {
      //prompt the user
      cout << "Which customer is making a payment? (Type their name exactly as shown)" << endl;

      //prints the customer list
      printCustomers();

      cout << "Response: ";
      cin >> input;

      if(!cin)  {
        //invalid input check
        //save what we can
        writeFile();
        error("invalid input");
      }
      else  {
        //input is valid
          customer_index = -1;      //customer hasnt been found yet

          //search for the customer
          for(size_t i = 0; i < customers.size(); i++)  {
            //update the index when the customer has been found
            if(customers[i].getName() == input) {
              customer_index = i;
            }
          }
          if(customer_index != -1) {
            //customer has been found from valid input
            cont = false;
          }
          else  {
            //continue until valid input is found
            cout << "Please enter a valid customer name\n";
          }
      }
    }

    //customer chosen by user
    Customer& c = customers[customer_index];

    //a customer has been selected (c)
    double credit = -1;       //set credit to be invalid initially
    while(credit == -1) {
      //continue while we have invalid input

      //prompt user
      cout << "How much credit would you like to put into " << c.getName() << "'s account? " << endl
            << "Your response: ";

      cin >> credit;

      if(!cin)  {
        //invalid input check
        //save what we can
        writeFile();
        error("Invalid Credit Amout, must be a double");
      }

      if(credit >= 0)  {
        //if credit is valid
        //confirm to the user
        cout << "Adding $" << credit << " to " << c.getName() << "'s account."
             << endl << "Returning you to menu\n";
        //add money to c's account
        c.addCredit(credit);
      }
      else if(credit < 0) {
        //catch case if input is negative
        cout << "Credit cannot be less than 0!\n";
        //reset invalid input to continue
        credit = -1;
      }

    }
  }

  void requestRide()  {
    //requests a ride from a driver from place a to place b
    if(drivers.size() == 0) {
      //if there are no drivers return to menu
      cout << "\nThere must be one driver in the system\nReturning you to the menu\n";
      return;
    }
    else if(customers.size() == 0) {
      //if there are no customers return to menu
      cout << "\nThere must be one customer in the system\nReturning you to the menu\n";
      return;
    }

    //At this point in the code there is at least one customer and one driver
    string input;   //input of the user
    //customer_index will stay -1 with bad input
    int customer_index = -1;
    bool cont = true;     //bool to continue loop until input is valid

    while(cont)  {
      //continue until we found valid input (a customer)

      //promp user
      cout << "Which customer is requesting the drive? (Type their name exactly as shown)" << endl;

      //print a list of customers
      printCustomers();

      cout << "Response: ";
      cin >> input;

      if(!cin)  {
        //invalid input catch
        //save what we can
        writeFile();
        error("Invalid input");
      }
      else  {
        //at this point we have valid input

        //search for the customer that the user inputted
        customer_index = -1;    //start index as invalid
        //iterate through customers
        for(size_t i = 0; i < customers.size(); i++)  {
          if(customers[i].getName() == input) {
            //when we found the customer the user was talking about
            customer_index = i;
          }
        }

        if(customer_index != -1) {
          //customer index has been found, stop looping
          cont = false;
        }
        else  {
          //continue looping until valid input has been found
          cout << "Please enter a valid customer name\n";
        }
      }
    }

    //the customer recieving the drive
    Customer& customer = customers[customer_index];

    //ask user and set the starting location
    Place_info starting_location = askLocation("Where are you currently at?");

    cont = true;            //boolean to continue looping until valid input has been found
    bool search_by_name;    //to see whether or not they want by tag or by name

    while(cont) {
      //while input is invalid

      //prompt user
      cout << "Would you like to search through destinations by name or by tag? (Enter the number corresponding to the choice)\n"
           << "(1) Name\n"
           << "(2) Tag\n"
           << "Response: ";
      cin >> input;

      if(!cin)  {
        //invalid input catch
        //save what we can
        writeFile();
        error("Invalid Input");
      }
      else  {
        //At this point we have valid input
        if(input == "1")  {
          //Search by name
          search_by_name = true;
          //end loop, valid input
          cont = false;
        }
        else if (input == "2")  {
          //search by tag
          search_by_name = false;
          //end loop, valid input
          cont = false;
        }
        else  {
          //tell user they inputted invalid input
          cout << "Please enter a valid number 1 - 2\n";
        }
      }
    }

    Place_info destination;       //to store destination

    if(search_by_name)  {
      //searching by name
      destination = askLocation("Where would you like to go?");
    }
    else  {
      //searching by tag
      destination = searchByTag();
    }

    //find closest driver
    int closest_driver_index = 0;     //assume first is the closest
    double min_distance = distance(drivers[0].getGeoLocation(), starting_location.getLocation());

    //iterate list trying to find a driver closer
    for(size_t i = 1; i < drivers.size(); i++)  {
      if(min_distance > distance(drivers[i].getGeoLocation(), starting_location.getLocation()))  {
        //if this driver is closer update variables
        min_distance = distance(drivers[i].getGeoLocation(), starting_location.getLocation());
        closest_driver_index = i;
      }
    }

    //Driver driving the customer has been found
    Driver& closest_driver = drivers[closest_driver_index];

    //confirm the user
    cout << "\nThank you! " << closest_driver.getName() << " will be your driver today!\n";

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


  }

  void printCustomersInfo() {
    //Prints all of the customers and their info
    if(customers.size() == 0) {
      cout << "No customers in our system\n\n";
      return;
    }
    for(Customer c : customers) {
      cout << c;
      cout << endl;
    }
  }

  void printDriversInfo() {
    //Prints all of the drivers and their info
    if(drivers.size() == 0) {
      cout << "No drivers in our system\n\n";
      return;
    }
    for(Driver d : drivers) {
      cout << d;
      cout << endl;
    }
  }

  void readFile() {
    //function to read myride input from a file
    try {

      ifstream file{file_name};     //open the file

      int num_drivers;              //number of drivers to read

      if(!file) {
        error("File doesn't exist");
      }

      file >> num_drivers;

      //checking state of file stream
      if(!file) {
        error("Parsing error : number of drivers");
      }

      //iterate through number of drivers
      for(int i = 0; i < num_drivers; i++)  {
        //read and add the driver to our list
        Driver d;
        file >> d;
        //checking state of file stream
        if(!file) {
          error("Parsing error : Reading Driver");
        }
        drivers.push_back(d);
      }

      int num_customers;          //number of customers to read

      file >> num_customers;

      //checking state of file stream
      if(!file) {
        error("Parsing error : number of customers");
      }

      //iterate through number of customers
      for(int i = 0; i < num_customers; i++)  {
        //read and add the customer to our list
        Customer c;
        file >> c;
        //checking state of file stream
        if(!file) {
          error("Parsing error : Reading Customer");
        }
        customers.push_back(c);
      }

      int num_locations;          //number of locations to read

      file >> num_locations;

      //checking state of file stream
      if(!file) {
        error("Parsing error : number of locations");
      }

      //iterate through number of locations
      for(int i = 0; i < num_locations; i++)  {
        //read and add the location to our list
        Place_info place;
        file >> place;
        //checking state of file stream
        if(!file) {
          error("Parsing error : reading place");
        }
        locations.push_back(place);
      }

    }
    catch(runtime_error e)  {
      string m = e.what();
      string message = "Caught exception: " + m + "\n";
      error(message);
    }
  }

  void writeFile()  {
    //file to store all information of my_ride
    try {

      ofstream file{file_name};

      //output number of drivers
      file << drivers.size();
      file << endl;

      //print drivers to the file
      for(size_t i = 0; i < drivers.size(); i++)  {
        //format is name, balance, and location (lat and lon)
        Driver d = drivers[i];  //stores current driver
        file << d.getName() + " ";
        file << d.getAccount();
        file << " ";
        file << d.getGeoLocation().getLatitude();
        file << " ";
        file << d.getGeoLocation().getLongitude();
        file << " ";
        file << d.getPhoto();
        file << "\n";
      }

      //output number of customers
      file << customers.size() << endl;

      //print customers to the file
      for(size_t i = 0; i < customers.size(); i++) {
        //format is name then account balance
        Customer c = customers[i];
        file << c.getName() + " ";
        file << c.getAccount();
        file << " ";
        file << c.getPhoto();
        file << "\n";
      }

      //output number of locations
      file << locations.size();
      file << endl;

      for(size_t i = 0; i < locations.size(); i++) {
        //format is name, address, location (lat and lon)
        Place_info p = locations[i];
        file << p.getName() + " ";
        file << p.getAddress() + " ";

        Geo_loc location = p.getLocation();    //temp store location
        file << location.getLatitude();
        file << " ";
        file << location.getLongitude();
        file << " ";

        vector<string> t = p.getTags();          //temp store tags

        file << t.size();                        //print num tags
        //print tags
        for(size_t i = 0; i < t.size(); i++) {
          file << " " + t[i];
        }

        file << " ";
        file << p.getPhoto();
        file << "\n";
      }

    }
    catch(...) {
      error("Input file \"" + file_name + "\" not found : or error in parsing");
    }
  }

private:

  void initLoc()  {
    /*
    //Add 6 locations to the vector

    //Kyle Field
    string kyle_name = "Kyle Field";
    string kyle_address = "756 Houston St, College Station, TX 77843";
    vector<string> kyle_tags = {"Football Stadium", "12th Man", "Aggies", "Aggie Football"};
    Geo_loc kyle_loc = Geo_loc(30.610329, -96.339860);
    Place_info kyle_field = Place_info(kyle_name, kyle_address, kyle_tags, kyle_loc);

    //add Kyle Field to the brazos locations
    locations.push_back(kyle_field);

    //Bright Building
    string bright_name = "Bright Building";
    string bright_address = "Harvey R. \"Bum\" Bright Building, College Station, TX 77840";
    vector<string> bright_tags = {"Computer Science", "Aerospace Engineering", "Offices", "TAMU"};
    Geo_loc bright_loc = Geo_loc(30.619002, -96.338820);
    Place_info bright_building = Place_info(bright_name, bright_address, bright_tags, bright_loc);

    //add Bright Building to brazos locations
    locations.push_back(bright_building);

    //Bryan Police Department
    string police_name = "Bryan Police Department";
    string police_address = "303 E 29th St, Bryan, TX 77803";
    vector<string> police_tags = {"Police", "Police Department", "Law Enforcement"};
    Geo_loc police_loc = Geo_loc(30.669974, -96.371081);
    Place_info police_department = Place_info(police_name, police_address, police_tags, police_loc);

    //add Bryan Police Department to brazos locations
    locations.push_back(police_department);

    //Field House Sports BCS
    string field_name = "Field House Sports BCS";
    string field_address = "21930 Kathy Fleming Rd, Millican, TX 77866";
    vector<string> field_tags = {"Indoor Sports", "Batting Cage", "Bubble Soccer"};
    Geo_loc field_loc = Geo_loc(30.470832, -96.208249);
    Place_info field_house = Place_info(field_name, field_address, field_tags, field_loc);

    //add field house to brazos locations
    locations.push_back(field_house);

    //Sweet Eugene's
    string sweet_name = "Sweet Eugene's";
    string sweet_address = "1702 George Bush Dr E, College Station, TX 77840";
    vector<string> sweet_tags = {"Coffee","Coffee House","Fresh Brew"};
    Geo_loc sweet_loc = Geo_loc(30.617657, -96.317453);
    Place_info sweet_eugenes = Place_info(sweet_name, sweet_address, sweet_tags, sweet_loc);

    //add Sweet Eugene's to brazos locations
    locations.push_back(sweet_eugenes);

    //Terrell Farms
    string terrell_name = "Terrell Farms";
    string terrell_address = "7855 Terrell St, College Station, TX 77845";
    vector<string> terrell_tags = {"Farm","Fresh","Produce"};
    Geo_loc terrell_loc = Geo_loc(30.400377, -96.241552);
    Place_info terrell_farms = Place_info(terrell_name, terrell_address, terrell_tags, terrell_loc);

    //add Terrell to brazos locations
    locations.push_back(terrell_farms);
    */
  }

  Place_info askLocation(string prompt) {
    //promps the user with 'promp' and returns the location that the user asked for

    string input;         //input of the user
    bool cont = true;     //boolean to continue the loop until input is valid
    int loc = -1;         //set loc as invalid until a valid location has been found

    while(cont)  {
      //loop until valid input

      //prompt user
      cout << prompt << endl;

      //print locations as a list
      printLocations();

      cout << "Response : ";

      cin >> input;


      if(!cin)  {
        //invalid input catch
        cout << "Please enter a valid location from 1 - " << locations.size() << endl;
      }
      else  {
        //at this point we have valid input

        //maps the string location to the index of the location in the vector
        if (input == "1")  {
          loc = 0;
        }
        else if (input == "2")  {
          loc = 1;
        }
        else if (input == "3")  {
          loc = 2;
        }
        else if (input == "4")  {
          loc = 3;
        }
        else if (input == "5")  {
          loc = 4;
        }
        else if (input == "6")  {
          loc = 5;
        }
        else  {
          //if invalid input, we will set to invalid index
          loc = -1;
        }
        if (loc != -1) {
          //if valid location recieved return user location
          return locations[loc];
        }
        else  {
          //invalid menu selection
          cout << "Please enter a valid location from 1 - " << locations.size() << endl;
        }
      }
    }
    return Place_info();
  }


  Place_info searchByTag()  {
    //ask the user to choose a tag by name

    string input;         //user input
    bool cont = true;     //boolean to continue until valid input

    while(cont) {
      //continue until valid input found

      //prompt user
      cout << "Where would you like to go?" << endl;

      //print location tags as a list
      printLocationTags();

      cout << "Response : ";

      cin >> input;

      if(!cin)  {
        //invalid input case
        //save what we can
        writeFile();
        error("Invalid Input");
      }
      else  {
        //coverting a string to an int

        int in = atoi(input.c_str());   //input as an integer to compare
        int k = 1;                      //counting as i iterate through the list

        //iterate the tags until we find the number the user inputted
        for(size_t i = 0; i < locations.size(); i++) {
          vector<string> tags = locations[i].getTags();
          for(size_t j = 0; j < tags.size(); j++) {
            if(in == k++)
              //if user == count, we found the correct tag, return the location of that tag.
              return locations[i];
          }
        }
        //if we reached this point, we assume invalid input
        cout << "Please enter a valid tag\n";
      }
    }
    return Place_info();
  }

  void printLocationTags()  {
    //prints out a menu of all location tags

    cout << "Here are the possible tags:\n\n";

    size_t count = 1;     //prints number of tag for user response to choose

    //iterate through locations and their tags and print the tags
    for(size_t i = 0; i < locations.size(); i++) {
      vector<string> tags = locations[i].getTags();
      for(size_t j = 0; j < tags.size(); j++) {
        cout << "(" << count++ << ") " << tags[j] << endl;
      }
    }
  }
};

/*
int main()  {

  //allows the program to continue until something exits it
  bool cont = true;
  //thank the user for using your program
  cout << endl << "Welcome and thank you for using MyRide!" << endl;
  //creates a new instance of MyRide
  MyRide my_ride;

  //read from the input files

  cout << "Please enter the file to read from : ";

  string file_name;
  cin >> file_name;

  if(!cin)  {
    error("Invalid Input");
  }

  my_ride = MyRide(file_name);

  my_ride.readFile();

  //exucutes until somewhere you set cont to false
  while(cont) {
    //Promt the menu
    cout << "Please select one of the choices below" << endl;
    cout << "(1) Add a new customer" << endl
         << "(2) Add a new driver" << endl
         << "(3) Make a payment (for customers only)" << endl
         << "(4) Request a ride" << endl
         << "(5) Print out all customers" << endl
         << "(6) Print out all drivers" << endl
         << "(7) Print out all locations" << endl
         << "(8) Exit" << endl;

    //record response
    cout << "Response: ";
    string resp;
    cin >> resp;

    //invalid response catch case
    if(!cin)  {
      error("Invalid Response");
    }

    if(resp == "1") {
      //Add a new customer to the system
      my_ride.addCustomer();
    }
    else if(resp == "2")  {
      //Add a new driver to the system
      my_ride.addDriver();
    }
    else if(resp == "3")  {
      //Make a payment
      my_ride.makePayment();
    }
    else if(resp == "4")  {
      //Request a ride
      my_ride.requestRide();
    }
    else if(resp == "5")  {
      //Print out all the customers
      cout << endl << "Customers in our system:" << endl;
      my_ride.printCustomersInfo();
    }
    else if(resp == "6")  {
      //Print out all the drivers
      cout << endl << "Drivers in our system:" << endl;
      my_ride.printDriversInfo();
    }
    else if(resp == "7")  {
      //print all known locations
      cout << endl << "Locatins in our system: " << endl;
      my_ride.printLocationsInfo();
    }
    else if(resp == "8")  {
      //Exit the program
      cout << "Thanks for using MyRide!" << endl;
      cont = false;
    }
    else  {
      //invalid input catch
      cout << "Please enter a valid response 1 - 7" << endl;;
    }
  }

  //store all information to the files
  my_ride.writeFile();
}
//END OF PROGRAM
*/
