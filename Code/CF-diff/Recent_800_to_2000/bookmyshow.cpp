implement a simple class bookmyshow screen

one movie one show, booking

seats, available occupied,

block seat for sometime if payment is succefull then seat is booked else available for others

booking function(list seat_no) -> return true or false whether booked or not

states of seat :-
block
booked
available

same seats can be entered but only one should be given access

class BookMyShow {
public:
int booking_id = 0;
unordered_set<string> available, booked, blocked;
BookMyShow (list<int> seats) {
//intialize all seats to available
//add them to available set
//update booking_id
    for (int seat : seats) {
        available.insert(seat);
    }
}

int get_booking_id() {
    mutex.lock();
    booking_id++;
    mutex.unlock();
    return booking_id;
}

pair<bool, string> check_booked_then_block(vector<string> &seat_nos) {
    mutex.lock();
    for (string seat_no : seat_nos) {0
        if (booked.find(seat_no) != booked.end()) {
            mutex.unlock();
            return {false, "booked"};
        } else if (blocked.find(seat_no) != blocked.end()) {
            mutex.unlock();
            return {false, "blocked"};
        }
    }

    for (string seat_no : seat_nos) {
        blocked.insert(seat_no);
    }

    mutex.unlock();
    return {true, "can be booked"};
}

pair<bool, string> check_blocked_then_book(vector<string> &seat_nos, int current_booking_id) {
    mutex.lock();
    for (string seat_no : seat_nos) {
        if (available.find(seat_no) != available.end()) {
            mutex.unlock();
            return {false, "not blocked"};
        } else if (booked.find(seat_no) != booked.end()) {
            mutex.unlock();
            return {false, "booked"};
        }
    }

    for (string seat_no : seat_nos) {
        booked.insert(seat_no);
    }

    mutex.unlock();
    return {true, current_booking_id};
}

pair<bool, string> check_blocked_then_available(vector<string> &seat_nos) {
    mutex.lock();
    for (string seat_no : seat_nos) {
        if (available.find(seat_no) != available.end()) {
            mutex.unlock();
            return {false, "not blocked"};
        } else if (blocked.find(seat_no) != blocked.end()) {
            mutex.unlock();
            return {false, "blocked"};
        }
    }

    for (string seat_no : seat_nos) {
        available.insert(seat_no);
    }

    mutex.unlock();
    return {true, "are now available"};
}

pair<bool, string> booking(vector<string> &seat_nos) {
//check if a seat_no is booked or not

    pair<bool, string> check_booking = check_booked_then_block(seat_nos);
    
    if (check_booking.first == false) {
        return check_booking;
    }

    int current_booking_id = get_booking_id();


    //wait for a min for payment if nothing happens
    //then make seats available again
    int time = 0;
    while (payement_status(current_booking_id) == "processing") { //waits for minute, return true if payment is done
        if (payement_status(current_booking_id) == "successfull") {
            return check_blocked_then_book(seat_nos, current_booking_id);
        }
        sleep(1000);
        time++;
        if (time >= 60) {
            break;
        }
    }
    check_blocked_then_available(seat_nos);
    return {false, "payment unsuccessfull"};
}

class Movie {
public:
string name;
string release_date;
}

class Seats {
public:
string number; //seat number
int price;
string state; //available, booked or blocked
}