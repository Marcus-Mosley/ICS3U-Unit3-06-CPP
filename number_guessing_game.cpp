// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on September 2020
// This program is a Number Guessing Game with
//   Random Numbers and Try Catch

#include <iostream>
#include <random>

int main() {
    // This function creates a random number and checks if the user's guess
    //   is equal to the generated number
    std::string guess_str;
    int guess_int;
    int random_number;

    // Input
    std::cout << "Enter a number between 0 and 9: ";
    std::cin >> guess_str;
    std::cout << "" << std::endl;

    // Process
    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<> dist(0, 9);
    random_number = dist(engine);

    try {
        // Output
        guess_int = std::stoi(guess_str);
        if (guess_int == random_number) {
            std::cout << "That is correct, the right number was "
            << std::fixed << guess_int << "!" << std::endl;
        } else {
            std::cout << "That is incorrect, the right number was "
            << std::fixed << random_number << "!" << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "That is not an integer, please input a number between "
            "0 and 9!" << std::endl;
    }
    std::cout << "" << std::endl;
    std::cout << "Thanks for Playing!" << std::endl;
}
