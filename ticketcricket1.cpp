    #include <iostream> 
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// =================== Player Class ===================
class Player {
public:
    static int player_count;
    string name, shirt_no, average, icc_ranking;
    string total_runs, match_played, total_wickets, Team_name;

    Player();
    void set_details();
    void display() const;
};

int Player::player_count = 0;

Player::Player() {
    name = shirt_no = average = icc_ranking = total_runs = match_played = total_wickets = Team_name = "";
    player_count++;
}

void Player::set_details() {
    cout << "Enter team name: "; cin >> Team_name;
    cout << "Enter player name: "; cin >> name;
    cout << "Enter shirt number: "; cin >> shirt_no;
    cout << "Enter ICC ranking: "; cin >> icc_ranking;
    cout << "Enter batting average: "; cin >> average;
    cout << "Enter total runs: "; cin >> total_runs;
    cout << "Enter matches played: "; cin >> match_played;
    cout << "Enter total wickets: "; cin >> total_wickets;
}

void Player::display() const {
    cout << "\n--- Player Info ---\n";
    cout << "Team: " << Team_name << "\nName: " << name << "\nShirt No: " << shirt_no;
    cout << "\nICC Ranking: " << icc_ranking << "\nAverage: " << average;
    cout << "\nTotal Runs: " << total_runs << "\nMatches Played: " << match_played;
    cout << "\nTotal Wickets: " << total_wickets << endl;
}

// =================== Team Class ===================
class Team {
public:
    string team_name, team_captain, team_coach;
    int team_icc_ranking, no_of_players, total_matches_won, total_matches_lost;

    void set_details();
    void display() const;
};

void Team::set_details() {
    cout << "Enter team name: "; cin >> team_name;
    cout << "Enter ICC ranking: "; cin >> team_icc_ranking;
    cout << "Enter number of players: "; cin >> no_of_players;
    cout << "Enter total matches won: "; cin >> total_matches_won;
    cout << "Enter total matches lost: "; cin >> total_matches_lost;
    cout << "Enter team captain: "; cin >> team_captain;
    cout << "Enter team coach: "; cin >> team_coach;
}

void Team::display() const {
    cout << "\n--- Team Info ---\n";
    cout << "Name: " << team_name << "\nICC Ranking: " << team_icc_ranking;
    cout << "\nPlayers: " << no_of_players << "\nWon: " << total_matches_won;
    cout << "\nLost: " << total_matches_lost << "\nCaptain: " << team_captain;
    cout << "\nCoach: " << team_coach << endl;
}

// =================== Ticket Class ===================
class Ticket {
    string ticketID;
    string seatType;
    string bookingStatus;

public:
    Ticket() {}
    Ticket(string id, string type) {
        ticketID = id;
        seatType = type;
        bookingStatus = "Available";
    }

    void displayTicket() {
        cout << "Ticket ID: " << ticketID << ", Seat Type: " << seatType << ", Status: " << bookingStatus << endl;
    }

    string bookTicket() {
        if (bookingStatus == "Available") {
            bookingStatus = "Booked";
            return "Booked";
        }
        return "Failed";
    }

    string cancelTicket() {
        if (bookingStatus == "Booked") {
            bookingStatus = "Available";
            return "Cancelled";
        }
        return "Failed";
    }

    string status() { return bookingStatus; }
    string getTicketID() { return ticketID; }
};

// =================== Match Class ===================
class Match {
public:
    string matchID, team1, team2, match_type, venue, date;
    Ticket tickets[50];
    int ticketCount;

    Match() { ticketCount = 0; }

    void schedule();
    void displayMatch();
    void showAvailableSeats();
    string bookSeat(string id);
    string cancelSeat(string id);
};

void Match::schedule() {
    cout << "Enter Match ID: "; cin >> matchID;
    cout << "Enter Team 1: "; cin >> team1;
    cout << "Enter Team 2: "; cin >> team2;
    cout << "Enter Match Type: "; cin >> match_type;
    cout << "Enter Venue: "; cin >> venue;
    cout << "Enter Date: "; cin >> date;

    ticketCount = 0;
    for (int i = 1; i <= 5; i++) {
        stringstream ss;
        ss << "VIP" << i;
        tickets[ticketCount++] = Ticket(ss.str(), "VIP");
    }
    for (int i = 1; i <= 10; i++) {
        stringstream ss;
        ss << "PREM" << i;
        tickets[ticketCount++] = Ticket(ss.str(), "Premium");
    }
    for (int i = 1; i <= 20; i++) {
        stringstream ss;
        ss << "GEN" << i;
        tickets[ticketCount++] = Ticket(ss.str(), "General");
    }
}

void Match::displayMatch() {
    cout << "\nMatch ID: " << matchID << " - " << team1 << " vs " << team2
         << "\nType: " << match_type << ", Date: " << date << ", Venue: " << venue << endl;
}

void Match::showAvailableSeats() {
    cout << "\nAvailable Seats:\n";
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].status() == "Available")
            tickets[i].displayTicket();
    }
}

string Match::bookSeat(string id) {
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketID() == id)
            return tickets[i].bookTicket();
    }
    return "Failed";
}

string Match::cancelSeat(string id) {
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].getTicketID() == id)
            return tickets[i].cancelTicket();
    }
    return "Failed";
}

// =================== Main Program ===================
int main() {
    const int MAX_PLAYERS = 11;
    Player players[MAX_PLAYERS];
    Team teams[5];
    Match match;
    int acchoice,achoice,cchoice; 
	int pIndex = 0;
	int tIndex = 0;
    string seatID;

    do {
        cout << "\n======= Cricket PSL Management system =======\n";
        cout<<"1:admin"<<endl;
        cout<<"2:customer"<<endl;
        cout<<"0:exist"<<endl;
        cout<<"ENTER CHOICE"<<endl;
        cin>>acchoice;
        switch(acchoice){
       	case 1:
       	do{
		   	cout<<"admin detail"<<endl;
        	 cout << "1. Add Player\n2. Show Players\n3. Add Team\n4. Show Teams";
             cout << "\n5. Schedule Match \n6 View Match Info \n 0:exit";
             cout << "\nEnter choice: ";
             cin >> achoice;
              switch (achoice) {
        case 1:
            if (pIndex < MAX_PLAYERS) players[pIndex++].set_details();
            else cout << "Max players reached!\n";
            break;
        case 2:
            for (int i = 0; i < pIndex; ++i) players[i].display();
            break;
        case 3:
            if (tIndex < 5) teams[tIndex++].set_details();
            else cout << "Max teams reached!\n";
            break;
        case 4:
            for (int i = 0; i < tIndex; ++i) teams[i].display();
            break;
        case 5:
            match.schedule();
            break;
        case 6:
            match.displayMatch();
            break;
        case 0:
		cout<<"goodby admin portion"<<endl;    
        default:
		cout<<"invalid"<<endl;} 
        }while(achoice !=0);
        break;
             
        case 2:
        	do{
			
        	 cout<<"customer portion"<<endl;
		     cout<<"1:View Available Seats\n2:Book Ticket";
             cout << "\n3:Cancel Ticket\n";
             cout<<"0:exit"<<endl;
             cout<<"ENTER CHOICE:"<<endl;
             cin>>cchoice;
              switch (cchoice) {
        
        case 1:
            match.showAvailableSeats();
            break;
        case 2:
            cout << "Enter Seat ID to book: "; cin >> seatID;
            if (match.bookSeat(seatID) == "Booked")
                cout << "Seat Booked Successfully!\n";
            else
                cout << "Booking Failed!\n";
            break;
        case 3:
            cout << "Enter Seat ID to cancel: "; cin >> seatID;
            if (match.cancelSeat(seatID) == "Cancelled")
                cout << "Seat Cancelled Successfully!\n";
            else
                cout << "Cancellation Failed!\n";
            break;
        
        case 0:
            cout << "Goodbye custumer portion!\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
             
        }while(cchoice !=0);
             break;
         case 0:
            cout << "Goodbye management system!\n";
            break;
        default:
            cout << "Invalid option!\n"; }    
		}while(acchoice !=0);
      
       
       
    

    return 0;
}

