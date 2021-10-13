#include <iostream>

int getNumberOfRounds() {
    int numRounds;
    while (true) {
        std::cin >> numRounds;
        if ( numRounds > 0) {
            break;
        }
        std::cout << "Rounds must be > 0" << std::endl;
    }
    return numRounds;
}

std::string convertRollToName(int roll) {
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    switch ( roll ) {
        case ROCK:
            return "rock";
        case PAPER:
            return "paper";
        case SCISSORS:
            return "scissors";
        default:
            std::cerr << "Invalid role: " << roll << std::endl;
            exit(1);
    }
}

/*
 * Decide if player 1 or player 2 wins
 * True==player 1 wins
 */
bool determineWinner(int player1Roll,
                     int player2Roll) {
    // Player 1 wins if EITHER they get player2's role +1 (paper over rock or
    // scissors over paper) OR they get player2's role -2 (rock over scissors)
    if ( (player1Roll == (player2Roll+1)) ||
         (player1Roll == (player2Roll-2)) ) {
        return true;
    }
    // Player 2 wins
    return false;
}

int main() {

    int seed;
    std::cin >> seed;
    srand(seed);

    std::string player1;
    std::string player2;

    std::cin >> player1;
    std::cin >> player2;

    /*Another way to get the number of rounds...
    int numRounds;
    std::cin >> numRounds;
    while ( numRounds < 1 ) {
        std::cout << "Rounds must be > 0" << std::endl;
        std::cin >> numRounds;
    }*/

    int numRounds = getNumberOfRounds();
    std::cout << player1 << " vs " << player2 <<
                 " for " << numRounds << " rounds" << std::endl;

    for ( int i=0; i<10; i++) {
        std::cout << "Outer!" << std::endl;
        for ( int j=0; j<3; j++) {
            std::cout << "Inner!" << std::endl;
            if ( true ) {
                break;
            }
        }
        std::cout << "Outer end!" << std::endl;
    }

    // Time to play!
    int player1Wins = 0;
    int player2Wins = 0;
    const int POSSIBLE_PLAYS = 3;
    for ( int i=0; i<numRounds; i++) {
        int player1Roll;
        int player2Roll;
        while ( true) {
            player1Roll = rand() % POSSIBLE_PLAYS;
            player2Roll = rand() % POSSIBLE_PLAYS;
            if ( player1Roll != player2Roll) {
                break;
            }
            std::cout << "Tie" << std::endl;
        }

        // We now know that someone won
        if (determineWinner(player1Roll, player2Roll)) {
            std::cout << player1 << " wins with " << convertRollToName(player1Roll) << std::endl;
            player1Wins++;
        } else {
            std::cout << player2 << " wins with " << convertRollToName(player2Roll) << std::endl;
            player2Wins++;
        }
    }

    std::cout << player1 << " wins " << player1Wins << " and " <<
                 player2 << " wins " << player2Wins << std::endl;

    return 0;
}
