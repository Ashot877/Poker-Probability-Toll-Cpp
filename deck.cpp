#include "libraries.h"

vector<string> create_deck()
{
    vector<string> suits = {"h", "d", "c", "s"};
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    vector<string> deck;
    
    for (const string& rank : ranks) {
        for (const string& suit : suits) {
            deck.push_back(rank + suit);
        }
    }

    return deck;
}

vector<string> delete_card(const string& card, vector<string>& deck) 
{
    deck.erase(remove(deck.begin(), deck.end(), card), deck.end());

    return deck;
}

vector<string> burn_card(vector<string>& deck)
{
    if (deck.empty()) return deck;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, deck.size() - 1);

    int index = dis(gen);

    deck.erase(deck.begin() + index);

    return deck;
}