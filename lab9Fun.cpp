//@author: Ashlyn Hanson
// Rock Paper Scissors

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>

using namespace std;



//Function 1. Gets the human choice (r, p, or s); uses input validation
string get_human_choice();
// Function 2. Uses function 6 to obtain computer choice;
string get_computer_choice();
// Function 3. This function determines the winner based on the given rules of the RPS game
string calculate_winner(string human_move, string computer_move);
// Function 4. Final output of the game, shows the statistics of the game
void print_report(unsigned total_games, unsigned human_win, unsigned draw);
// Function 5. Prompts the user to determine whether to continue the main game loop
bool play_again();
// Function 6. Returns a random number within the range low and high
unsigned get_rand_in_range(unsigned low, unsigned high);

int main()
{
    srand(time(0)); // in order to generate random numbers

    cout<<"Welcome to Rock, Paper, Scissors!"<<endl;
    cout<<endl;

    unsigned total = 0;
    unsigned human_score = 0;
    unsigned computer_score = 0;
    unsigned draws = 0;
    do {


        string human_choice = get_human_choice();
        string computer_choice = get_computer_choice();

        string winner = calculate_winner(human_choice,computer_choice);
        if(winner == "computer")
        {
            computer_score++;
            cout<<"): Computer wins. Best of luck the next time"<<endl;
        }
        else if (winner == "human") {
            human_score++;
            cout<<"(: You won! Congratulations!"<<endl;
        }
        else if (winner == "draw") {
                draws++;
            cout << ":: Draw. There was no winner." <<endl;
        }
        total++;
    } while (play_again());
    print_report(total, human_score,draws);

    cout<< "\nThanks for playing!";

    return 0;
}




// Function 1. Gets the human choice (r, p, or s); uses input validation
string get_human_choice()
{
    bool valid = false;
    string choice;

    while (!valid) {
        cout<<"\nChoose (r)ock, (p)aper, or (s)cissors: ";
        cin>>choice;
        if (choice == "r" || choice == "p" || choice == "s") {
            valid = true;
        }
        else {
            cout << "Invalid Choice"<<endl;
        }
    }
    if (choice == "r") {
        cout<<"> You have chosen rock"<<endl;
        return "rock";
    }
    else if(choice == "p") {
        cout<<"> You have chosen paper"<<endl;
        return "paper";
    }
    cout<<"> You have chosen scissors"<<endl;
    return "scissors";
}

// Function 2. Uses function 6 to obtain computer choice;
string get_computer_choice()
{
    unsigned num = get_rand_in_range(1,3);
    if( num == 1) {
        cout<<"> The computer has chosen rock."<<endl;
        return "rock";
    }
    else if (num==2) {
        cout<<"> The computer has chosen paper."<<endl;
        return "paper";
    }
    cout<<"> The computer has chosen scissors."<<endl;
    return "scissors";
}

// Function 3. This function determines the winner based on the given rules of the RPS game
string calculate_winner(string human_move, string computer_move)
{
    if (human_move == "rock" && computer_move == "scissors" ) {
        return "human";
    }
    else if (human_move == "scissors" && computer_move == "paper" ) {
        return "human";
    }
    else if (human_move == "paper" && computer_move == "rock" ) {
        return "human";
    }
    else if (human_move == "scissors" && computer_move == "rock" ) {
        return "computer";
    }
    else if (human_move == "paper" && computer_move == "scissors" ) {
        return "computer";
    }
    else if (human_move == "rock" && computer_move == "paper" ) {
        return "computer";
    }
    return "draw";
}

// Function 4. Final output of the game, shows the statistics of the game
void print_report(unsigned total_games, unsigned human_win, unsigned draw)
{
    cout<<setw(18) <<left <<"Total games: "<<total_games<<endl;
    cout << setw(19) <<right << "#" <<endl;
    cout << setw(18) << left<<"Human:" << setw(4)<<left << human_win<<endl;
    unsigned computerTotal = total_games - (human_win+draw);
    cout << setw(18) << left<<"Computer:" << setw(4)<<left <<computerTotal <<endl;
    cout << setw(18) << left<<"Draws:" << setw(4)<<left <<draw <<endl;
}

// Function 5. Prompts the user to determine whether to continue the main game loop
bool play_again()
{
    string again;
    cout << "\nPress n to exit or any other key to continue: ";
    cin>>again;

    if (again == "n") {
        return false;
    }
    return true;
}


// Function 6. Returns a random number within the range low and high
unsigned get_rand_in_range(unsigned low, unsigned high)
{
    int random_number=0;
    // generate the random number
    random_number = low + rand() % (high - low + 1);
    return random_number;
}
