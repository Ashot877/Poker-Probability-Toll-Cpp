#ifndef LIBRARIES_H
#define LIBRARIES_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>
#include <unordered_map>
#include <map>
#include <chrono>
#include <set>
#include <future>

using namespace std;

std::vector<string> create_deck();
std::vector<string> delete_card(const string& card, vector<string>& deck);
std::vector<string> burn_card(vector<string>& deck);
std::pair<int, vector<string>> best_combinations(const vector<string>& cards);
std::vector<string> strongest_hand(vector<vector<string>>& hands);
int card_value(const std::string& card);
int compare_hands_and_return_winner(const pair<int, vector<string>>& my_hand, const pair<int, vector<string>>& opponent_hand);
int check_all_opponents(const vector<pair<int, vector<string>>>& best_others_comb, const pair<int, vector<string>>& my_best_comb);
int m_carlo (const string& card1, const string& card2,
            int players_count, int game_round,
            vector<string> community_cards, vector<string> deck);
bool is_royal_flush(const vector<string>& hand);
bool is_straight_flush(const vector<string>& hand);
bool is_care(const vector<string>& hand);
bool is_full_house(const vector<string>& hand);
bool is_flush(const vector<string>& hand);
bool is_straight(const vector<string>& hand);
bool is_set(const vector<string>& hand);
bool is_two_pair(const vector<string>& hand);
bool is_pair(const vector<string>& hand);
bool compare_hands(const std::vector<std::string>& hand1, const std::vector<std::string>& hand2);

#endif