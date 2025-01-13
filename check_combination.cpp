#include "libraries.h"

bool is_royal_flush(const vector<string>& hand)
{
    set<char> suits;
    set<string> ranks;

    for (const auto& card : hand)
    {
        suits.insert(card.back()); 
        ranks.insert(card.substr(0, card.size() - 1));
    }

    set<string> royal_ranks = {"10", "J", "Q", "K", "A"};
    return (suits.size() == 1 && ranks == royal_ranks);
}

bool is_straight_flush(const vector<string>& hand)
{
    set<char> suits;
    vector<int> numeric_ranks;

    unordered_map<string, int> rank_values = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
        {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11},
        {"Q", 12}, {"K", 13}, {"A", 14}};

    for (const auto& card : hand)
    {
        suits.insert(card.back());
        numeric_ranks.push_back(rank_values[card.substr(0, card.size() - 1)]);
    }

    sort(numeric_ranks.begin(), numeric_ranks.end());
    if (suits.size() > 1 || numeric_ranks[0] == 10) return false;

    for (size_t i = 1; i < numeric_ranks.size(); ++i)
    {
        if (numeric_ranks[i] != numeric_ranks[i - 1] + 1)
        {
            return false;
        }
    }

    return true;
}

bool is_care(const vector<string>& hand)
{
    unordered_map<string, int> rank_counts;
    for (const auto& card : hand)
    {
        rank_counts[card.substr(0, card.size() - 1)]++;
    }

    for (const auto& pair : rank_counts)
    {
        if (pair.second == 4) return true;
    }

    return false;
}

bool is_full_house(const vector<string>& hand)
{
    unordered_map<string, int> rank_counts;
    for (const auto& card : hand)
    {
        rank_counts[card.substr(0, card.size() - 1)]++;
    }

    vector<int> counts;
    for (const auto& pair : rank_counts)
    {
        counts.push_back(pair.second);
    }

    sort(counts.begin(), counts.end());
    return (counts == vector<int>{2, 3});
}

bool is_flush(const vector<string>& hand)
{
    set<char> suits;
    for (const auto& card : hand)
    {
        suits.insert(card.back());
    }

    return suits.size() == 1;
}

bool is_straight(const vector<string>& hand)
{
    unordered_map<string, int> rank_values = {
        {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6},
        {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11},
        {"Q", 12}, {"K", 13}, {"A", 14}};
    
    vector<int> ranks;
    for(const auto& card : hand)
    {
        ranks.push_back(rank_values[card.substr(0, card.size() - 1)]);
    }

    sort(ranks.begin(), ranks.end());

    for (size_t i = 1; i < ranks.size(); ++i)
    {
        if (ranks[i] != ranks[i - 1] + 1) return false;
    }

    return true;
}

bool is_set(const vector<string>& hand)
{
    unordered_map<string, int> rank_counts;
    for (const auto& card : hand)
    {
        rank_counts[card.substr(0, card.size() - 1)]++;
    }

    for (const auto& pair : rank_counts)
    {
        if (pair.second == 3) return true;
    }

    return false;
}

bool is_two_pair(const vector<string>& hand)
{
    unordered_map<string, int> rank_counts;
    for (const auto& card : hand)
    {
        rank_counts[card.substr(0, card.size() - 1)]++;
    }

    vector<int> counts;
    for (const auto& pair : rank_counts)
    {
        counts.push_back(pair.second);
    }

    sort(counts.begin(), counts.end());
    return (counts == vector<int>{1, 2, 2});
}

bool is_pair(const vector<string>& hand)
{
    unordered_map<string, int> rank_counts;
    for (const auto& card : hand)
    {
        rank_counts[card.substr(0, card.size() - 1)]++;
    }

    for (const auto& pair : rank_counts)
    {
        if (pair.second == 2) return true;
    }

    return false;
}