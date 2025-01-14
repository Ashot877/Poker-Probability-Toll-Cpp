#include "libraries.h"

int m_carlo (const string& card1, const string& card2,
            int players_count, int game_round,
            vector<string> community_cards, vector<string> deck)
{
    vector<vector<string>> players(players_count);

    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < players_count; ++j)
        {
            if (!deck.empty())
            {
                uniform_int_distribution<> dis(0, deck.size() - 1);
                int index = dis(gen);
                players[j].push_back(deck[index]);
                deck = delete_card(deck[index], deck);
            }
        }
    }

    vector<int> stages = {5, 2, 1, 0};
    int pub_cards_to_draw = stages[game_round];

    if (pub_cards_to_draw == 5)
    {
        deck = burn_card(deck);
        for (int i = 0; i < pub_cards_to_draw; ++i)
        {
            if (i >= 3)
            {
                deck = burn_card(deck);
            }
            if (!deck.empty())
            {
                uniform_int_distribution<> dis(0, deck.size() - 1);
                int index = dis(gen);
                community_cards.push_back(deck[index]);
                deck = delete_card(deck[index], deck);
            }
        }
    }

    else if (pub_cards_to_draw == 1 || pub_cards_to_draw == 2)
    {
        for (int i = 0; i < pub_cards_to_draw; ++i)
        {
            burn_card(deck);
            if (!deck.empty())
            {
                uniform_int_distribution<> dis(0, deck.size() - 1);
                int index = dis(gen);
                community_cards.push_back(deck[index]);
                deck = delete_card(deck[index], deck);
            }
        }
    }

    // cout << "com. card: ";
    // for (const string& card_: community_cards)
    // {
    //     cout << card_ << " ";

    // }
    // cout << "\n";

    // for (size_t i = 0; i < players.size(); i++)
    // {
    //     cout << "Player" << i + 1 << ": ";
    //     for (const string& card : players[i])
    //     {
    //         cout << card << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int, vector<string>>> best_others_comb;

    for (size_t i = 0; i < players.size(); i++)
    {
        vector<string> all_cards = players[i];
        all_cards.insert(all_cards.end(), community_cards.begin(), community_cards.end());
        best_others_comb.push_back(best_combinations(all_cards));
    }

    vector<string> my_comb = {card1, card2};
    my_comb.insert(my_comb.end(), community_cards.begin(), community_cards.end());

    pair<int, vector<string>> my_best_comb;
    my_best_comb = best_combinations(my_comb);

    // cout << "Best combinations of other players:" << endl;
    // for (size_t i = 0; i < best_others_comb.size(); i++)
    // {
    //     cout << "Player " << i + 1 << " Best Hand: ";
    //     for (const auto& card : best_others_comb[i].second)
    //     {
    //         cout << card << " ";
    //     }
    //     cout << "(Rating: " << best_others_comb[i].first << ")" << endl;
    // }

    // cout << "Your Best Hand: ";
    // for (const auto& card : my_best_comb.second)
    // {
    //     cout << card << " ";
    // }
    // cout << "(Rating: " << my_best_comb.first << ")" << endl;

    int result = check_all_opponents(best_others_comb, my_best_comb);
    return result;
}