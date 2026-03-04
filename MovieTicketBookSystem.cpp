#include<iostream>
using namespace std;

struct booking
{
int booking_id;
string customer_name;
string movie_name;
int number_of_tickets;
float ticket_price;
};

void display_bookings(booking booking_list[], int size)
{
float total_revenue = 0;

cout << "\n------ Booking Details ------\n" << endl;

for (int i = 0; i < size; i++)
{
    float total_amount = booking_list[i].number_of_tickets * booking_list[i].ticket_price;

    cout << "Booking ID: " << booking_list[i].booking_id << endl;
    cout << "Customer: " << booking_list[i].customer_name << endl;
    cout << "Movie: " << booking_list[i].movie_name << endl;
    cout << "Tickets: " << booking_list[i].number_of_tickets << endl;
    cout << "Total Amount: " << total_amount << endl;
    cout << "------------------------------" << endl;

    total_revenue += total_amount;
}

cout << "Total Theatre Revenue: " << total_revenue << endl;
}

int main()
{
const int size = 3;
booking booking_list[size];

for (int i = 0; i < size; i++)
{
    cout << "\nEnter details for Booking " << i + 1 << endl;

    cout << "Booking ID: ";
    cin >> booking_list[i].booking_id;

    cout << "Customer Name: ";
    cin >> booking_list[i].customer_name;

    cout << "Movie Name: ";
    cin >> booking_list[i].movie_name;

    cout << "Number of Tickets: ";
    cin >> booking_list[i].number_of_tickets;

    cout << "Ticket Price: ";
    cin >> booking_list[i].ticket_price;
}

display_bookings(booking_list, size);

return 0;
}
