#include "libraries.h"

vector<string> strongest_hand(vector<vector<string>>& hands)
{
    sort(hands.begin(), hands.end(), compare_hands);
    
    return hands[0];
}

bool compare_hands(const std::vector<std::string>& hand1, const std::vector<std::string>& hand2)
{
    vector<int> values1, values2;
    
    for (const auto& card : hand1) values1.push_back(card_value(card));
    for (const auto& card : hand2) values2.push_back(card_value(card));
    
    sort(values1.rbegin(), values1.rend());
    sort(values2.rbegin(), values2.rend());
    
    for (size_t i = 0; i < 5; ++i) {
        if (values1[i] > values2[i]) return true;
        if (values1[i] < values2[i]) return false;
    }
    
    return false;
}

int compare_hands_and_return_winner(const pair<int, vector<string>>& my_hand, const pair<int, vector<string>>& opponent_hand)
{
    if (my_hand.first > opponent_hand.first) return 1;
    if (my_hand.first < opponent_hand.first) return 0;
    
    vector<int> my_hand_values, opponent_hand_values;
    
    for (const auto& card : my_hand.second) my_hand_values.push_back(card_value(card));
    for (const auto& card : opponent_hand.second) opponent_hand_values.push_back(card_value(card));
    
    sort(my_hand_values.rbegin(), my_hand_values.rend());
    sort(opponent_hand_values.rbegin(), opponent_hand_values.rend());
    
    for (size_t i = 0; i < 5; ++i) {
        if (my_hand_values[i] > opponent_hand_values[i]) return 1;
        if (my_hand_values[i] < opponent_hand_values[i]) return 0;
    }
    
    return 1;
}

int check_all_opponents(const vector<pair<int, vector<string>>>& best_others_comb, const pair<int, vector<string>>& my_best_comb)
{
    for (const auto& opponent_comb : best_others_comb)
    {
        int result = compare_hands_and_return_winner(my_best_comb, opponent_comb);
        if (result == 0)
        {
            return 0;
        }
    }
    return 1;
}

int card_value(const std::string& card)
{
    if (card[0] == '1' && card[1] == '0')
    {
        return 10;
    }
    char rank = card[0];
    if (rank == 'A') return 14;
    if (rank == 'K') return 13;
    if (rank == 'Q') return 12;
    if (rank == 'J') return 11;
    return rank - '0';
}