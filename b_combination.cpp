   #include "libraries.h"
   
pair<int, vector<string>> best_combinations(const vector<string>& cards) {
    multimap<int, vector<string>> best_combo;
    int best_score = 0;

    vector<int> combination(cards.size(), 0);
    fill(combination.begin(), combination.begin() + 5, 1);

    do {
        vector<string> hand;
        for (size_t i = 0; i < combination.size(); ++i) {
            if (combination[i]) {
                hand.push_back(cards[i]);
            }
        }

        if (is_royal_flush(hand)) {
            best_score = 10;
            best_combo.insert({best_score, hand});
            break;
        }
        if (is_straight_flush(hand) && best_score <= 9) {
            best_score = 9;
            best_combo.insert({best_score, hand});
        }
        if (is_care(hand) && best_score <= 8) {
            best_score = 8;
            best_combo.insert({best_score, hand});
        }
        if (is_full_house(hand) && best_score <= 7) {
            best_score = 7;
            best_combo.insert({best_score, hand});
        }
        if (is_flush(hand) && best_score <= 6) {
            best_score = 6;
            best_combo.insert({best_score, hand});
        }
        if (is_straight(hand) && best_score <= 5) {
            best_score = 5;
            best_combo.insert({best_score, hand});
        }
        if (is_set(hand) && best_score <= 4) {
            best_score = 4;
            best_combo.insert({best_score, hand});
        }
        if (is_two_pair(hand) && best_score <= 3) {
            best_score = 3;
            best_combo.insert({best_score, hand});
        }
        if (is_pair(hand) && best_score <= 2) {
            best_score = 2;
            best_combo.insert({best_score, hand});
        }

    } while (prev_permutation(combination.begin(), combination.end()));

    if (best_combo.empty())
    {
        map<string, int> card_values = {
            {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7},
            {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14}
        };

        auto card_value = [&card_values](const string& card)
        {
            return card_values.at(card.substr(0, card.size() - 1));
        };

        vector<string> sorted_cards = cards;

        sort(sorted_cards.begin(), sorted_cards.end(), [&card_value](const string& a, const string& b) {
            return card_value(a) > card_value(b);
        });

        best_combo.insert({1, sorted_cards});
    }

    // auto max_key = prev(best_combo.end())->first;
    auto max_key = best_combo.rbegin()->first;
    auto range = best_combo.equal_range(max_key);
    
    vector<vector<string>> best_combos_for_max_key;
    
    for (auto it = range.first; it != range.second; ++it) {
        best_combos_for_max_key.push_back(it->second);
    }

    return {best_score, strongest_hand(best_combos_for_max_key)};
}