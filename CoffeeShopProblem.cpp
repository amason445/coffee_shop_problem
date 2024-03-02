// CoffeeShopProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream> 

namespace letterGrade {

    enum letterGrade { A = 4, B = 3, C = 2, D = 1, F = 0 };

    static const int All[] = { A, B, C, D, F };
}

int main()
{
    std::ofstream outFile("output.txt");  // Open a file for writing

    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    int number_of_classes = 24;
    int degrees_of_freedom = 7;

    for (int i = 1; i <= degrees_of_freedom; i++) {

        int classes_completed_with_As = number_of_classes - i;

        if (classes_completed_with_As < 17 || classes_completed_with_As >= number_of_classes) {
            std::cout << "Invalid number of classes. Please iterate between 0 and 4 degrees of freedom" << std::endl;
            return 1;
        }

        int number_of_viable_outcomes = 0;
        int remaining_classes = number_of_classes - classes_completed_with_As;
        int possible_combinations = std::pow(5, remaining_classes);

        // Iterate over all combinations for the remaining classes
        for (int i = 0; i < possible_combinations; ++i) {
            double cumulative_gpa = 4 * classes_completed_with_As;  // Start with GPA from 'A's
            int temp = i;

            for (int j = 0; j < remaining_classes; ++j) {
                int grade_index = temp % 5;  // Get the current grade index
                cumulative_gpa += letterGrade::All[grade_index];  // Add grade to GPA
                temp /= 5;  // Move to the next grade
            }

            cumulative_gpa /= number_of_classes;  // Calculate the average GPA

            if (cumulative_gpa > 3.6 && cumulative_gpa < 3.7) {
                number_of_viable_outcomes++;
            }
        }

        double final_odds = (static_cast<double>(number_of_viable_outcomes) / possible_combinations) * 100;

        // Write to file instead of cout
        outFile << "For " << i << " degrees of freedom, the number of viable outcomes is: "
            << number_of_viable_outcomes << " over " << possible_combinations
            << " possible combinations. Therefore, you have a percent chance of: "
            << final_odds << std::endl;
    }

    outFile.close();
    return 0;
}