#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to store user information
class User {
public:
    string name;
    string email;
    string password;
    
    User(string name, string email, string password) : name(name), email(email), password(password) {}
};

// Class to store trip information
class Trip {
public:
    string destination;
    string date;
    double price;
    
    Trip(string destination, string date, double price) : destination(destination), date(date), price(price) {}
};

// Class to handle booking
class Booking {
public:
    User user;
    Trip trip;
    
    Booking(User user, Trip trip) : user(user), trip(trip) {}
    
    void displayBooking() {
        cout << "Booking Details:" << endl;
        cout << "Name: " << user.name << endl;
        cout << "Email: " << user.email << endl;
        cout << "Destination: " << trip.destination << endl;
        cout << "Date: " << trip.date << endl;
        cout << "Price: " << trip.price << endl;
    }
};

// Class to manage the system
class TripBookingSystem {
private:
    vector<User> users;
    vector<Trip> trips;
    vector<Booking> bookings;
    
public:
    // Register a new user
    void registerUser(string name, string email, string password) {
        users.push_back(User(name, email, password));
        cout << "User registered successfully!" << endl;
    }
    
    // Add available trips
    void addTrip(string destination, string date, double price) {
        trips.push_back(Trip(destination, date, price));
    }
    
    // Display available trips
    void displayTrips() {
        cout << "Available Trips:" << endl;
        for (size_t i = 0; i < trips.size(); i++) {
            cout << i+1 << ". Destination: " << trips[i].destination << ", Date: " << trips[i].date << ", Price: " << trips[i].price << endl;
        }
    }
    
    // Book a trip
    void bookTrip(string email, int tripIndex) {
        User* user = nullptr;
        for (size_t i = 0; i < users.size(); i++) {
            if (users[i].email == email) {
                user = &users[i];
                break;
            }
        }
        
        if (user != nullptr && tripIndex > 0 && tripIndex <= trips.size()) {
            bookings.push_back(Booking(*user, trips[tripIndex-1]));
            cout << "Trip booked successfully!" << endl;
        } else {
            cout << "Booking failed. Invalid user or trip selection." << endl;
        }
    }
    
    // Display all bookings
    void displayBookings() {
        for (size_t i = 0; i < bookings.size(); i++) {
            bookings[i].displayBooking();
        }
    }
};

int main() {
    TripBookingSystem system;

    // Adding some trips
    system.addTrip("New York", "2024-09-12", 350.00);
    system.addTrip("London", "2024-10-05", 550.00);
    system.addTrip("Tokyo", "2024-11-20", 650.00);
    
    int choice;
    do {
        cout << "\nMenu:\n1. Register User\n2. Display Trips\n3. Book Trip\n4. Display Bookings\n5. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string name, email, password;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;
                system.registerUser(name, email, password);
                break;
            }
            case 2:
                system.displayTrips();
                break;
            case 3: {
                string email;
                int tripIndex;
                cout << "Enter your email: ";
                cin >> email;
                system.displayTrips();
                cout << "Enter the trip number to book: ";
                cin >> tripIndex;
                system.bookTrip(email, tripIndex);
                break;
            }
            case 4:
                system.displayBookings();
                break;
            case 5:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}


