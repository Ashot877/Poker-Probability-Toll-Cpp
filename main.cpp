#include "libraries.h"

#include "libraries.h"
#include <limits>

int main() {

    vector<string> deck = create_deck();
    int players_count;
    int game_round;

    while (true) {
        cout << "How many players are in the game without you: ";
        cin >> players_count;
        if (cin.fail() || players_count < 1 || players_count > 10) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Players count must be in [1, 10]\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Which round: ";
        cin >> game_round;
        if (cin.fail() || game_round < 0 || game_round > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Game round must be in [0, 3]\n";
        } else {
            break;
        }
    }

    string first_card;
    while (true) {
        cout << "What is your first card (example - 3h): ";
        cin >> first_card;
        if (cin.fail() || find(deck.begin(), deck.end(), first_card) == deck.end()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong first card\n";
        } else {
            deck = delete_card(first_card, deck);
            break;
        }
    }

    string second_card;
    while (true) {
        cout << "What is your second card: ";
        cin >> second_card;
        if (cin.fail() || find(deck.begin(), deck.end(), second_card) == deck.end() || second_card == first_card) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wrong second card\n";
        } else {
            deck = delete_card(second_card, deck);
            break;
        }
    }

    vector<string> community_cards;

    if (game_round >= 1) {
        string pub_first_card;
        while (true) {
            cout << "What is the public first card (example - 3h): ";
            cin >> pub_first_card;
            if (cin.fail() || find(deck.begin(), deck.end(), pub_first_card) == deck.end()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wrong first public card\n";
            } else {
                deck = delete_card(pub_first_card, deck);
                community_cards.push_back(pub_first_card);
                break;
            }
        }

        string pub_second_card;
        while (true) {
            cout << "What is the public second card: ";
            cin >> pub_second_card;
            if (cin.fail() || find(deck.begin(), deck.end(), pub_second_card) == deck.end()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wrong second public card\n";
            } else {
                deck = delete_card(pub_second_card, deck);
                community_cards.push_back(pub_second_card);
                break;
            }
        }

        string pub_third_card;
        while (true) {
            cout << "What is the public third card: ";
            cin >> pub_third_card;
            if (cin.fail() || find(deck.begin(), deck.end(), pub_third_card) == deck.end()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wrong third public card\n";
            } else {
                deck = delete_card(pub_third_card, deck);
                community_cards.push_back(pub_third_card);
                break;
            }
        }

        if (game_round >= 2) {
            string pub_fourth_card;
            while (true) {
                cout << "What is the public fourth card: ";
                cin >> pub_fourth_card;
                if (cin.fail() || find(deck.begin(), deck.end(), pub_fourth_card) == deck.end()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Wrong fourth public card\n";
                } else {
                    deck = delete_card(pub_fourth_card, deck);
                    community_cards.push_back(pub_fourth_card);
                    break;
                }
            }
        }

        if (game_round == 3) {
            string pub_fifth_card;
            while (true) {
                cout << "What is the public fifth card: ";
                cin >> pub_fifth_card;
                if (cin.fail() || find(deck.begin(), deck.end(), pub_fifth_card) == deck.end()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Wrong fifth public card\n";
                } else {
                    deck = delete_card(pub_fifth_card, deck);
                    community_cards.push_back(pub_fifth_card);
                    break;
                }
            }
        }
    }

    int count = 0;

    for (int i = 0; i < 2; ++i) {
        cout << i << "\n";
        count += m_carlo(first_card, second_card, players_count, game_round, community_cards, deck);
    }

    cout << "Average result: " << static_cast<double>(count) / 1.0 << endl;
    return 0;
}
