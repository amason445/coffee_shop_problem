/***
CoffeeShopProblem.cpp : This file contains the 'main' function for the simulation. 
It checks possible grade sequence outcomes for a degree program and measures the outcomes that produce a GPA between 3.6 and 3.7.
***/

#include <iostream>
#include <cmath>
#include <fstream> 

//creates a namespace constaining an enum and array for US letter grades and their standard weight
namespace letterGrade {
    enum letterGrade { A = 4, B = 3, C = 2, D = 1, F = 0 };
    static const int All[] = { A, B, C, D, F };
}

int main()
{
    // creates an output file and checks if it's open
    std::ofstream outFile("output.txt");
    if (!outFile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    //sets the total number of classes and largest degree of freedom to iterate through
    int number_of_classes = 24;
    int maximum_degrees_of_freedom = 9;

    for (int i = 1; i <= maximum_degrees_of_freedom; i++) {

        // sets the minimum number of classes completed with an A
        int classes_completed_with_As = number_of_classes - i;
        if (classes_completed_with_As < (number_of_classes - maximum_degrees_of_freedom) || classes_completed_with_As >= number_of_classes) {
            std::cout << "Invalid number of classes. Please iterate between 0 and 4 degrees of freedom" << std::endl;
            return 1;
        }

        // sets sequence ceiling, calculates theoretical possible combinations and initializes viable outcome counter
        int remaining_classes = number_of_classes - classes_completed_with_As;
        int possible_combinations = std::pow(5, remaining_classes);
        int number_of_viable_outcomes = 0;

        // iterates over all combinations for the remaining classes and tests for GPA
        for (int i = 0; i < possible_combinations; ++i) {
            double cumulative_gpa = 4 * classes_completed_with_As;
            int temp = i;

            for (int j = 0; j < remaining_classes; ++j) {
                int grade_index = temp % 5;
                cumulative_gpa += letterGrade::All[grade_index];
                temp /= 5;  
            }

            cumulative_gpa /= number_of_classes;  // Calculate the average GPA

            if (cumulative_gpa > 3.6 && cumulative_gpa < 3.7) {
                number_of_viable_outcomes++;
            }
        }

        // calculates odds of achieving the target GPA
        double final_odds = (static_cast<double>(number_of_viable_outcomes) / possible_combinations) * 100;

        // writes to final outputs to output.txt
        outFile << "For " << i << " degrees of freedom, the number of viable outcomes is: "
            << number_of_viable_outcomes << " over " << possible_combinations
            << " possible combinations. Therefore, you have a percent chance of: "
            << final_odds << std::endl;
    }

    outFile.close();
    return 0;
}