#include <iostream>
#include <limits>
#include <string>
#include <cmath>

const double salesTax = 0.06;

namespace console
{


    // Utility function declarations
    void discardRemainingChars();
    void handleInvalidNumber();
    bool checkRange(double num, double min, double max);



     // Data retrieval function definitions
    double getDouble(std::string prompt, double min, double max)
    {
        double entry = 1.00;
        bool is_valid = false;

        while(!is_valid)
        {
            std::cout << prompt;
            if(!(std::cin >> entry))
            {
                handleInvalidNumber();
            } else
            {
                discardRemainingChars();
                if(entry == 0)
                {
                    return 0;
                    break;
                }
                is_valid = checkRange(entry, min, max);
            }
        }
        entry = round(entry * 100.00) / 100.00;
        return entry;
    }

    char getChar(std::string prompt, bool add_blank_line = true)
    {
        char choice = 'n';
        bool run = true;
        
        while(run)
        {
            std::cout << prompt;
            if(!(std::cin >> choice))
            {
                handleInvalidNumber();
            } else
            {
                if (choice == 'y' || choice == 'n')
                {
                    break;
                } else
                {
                    handleInvalidNumber();
                }
            }
        }
        return choice;
    }

    // Calculation and rounding utility function definitions
    double getTaxAmount(double total)
    {
        total *= salesTax;
        return round(total*100.00)/100.00;
    }

    double getTotalWithTaxes(double total)
    {
        total += total*salesTax;
        return (round(total*100.00)/100.00);
    }



    // Other utility functions definitions
    void discardRemainingChars()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void handleInvalidNumber()
    {
        std::cout << "Error! Invalid entry. Try again\n";
        std::cin.clear();
        discardRemainingChars();
    }

    bool checkRange(double num, double min, double max)
    {
        if (num < min)
        {
            std::cout << "Error! Number must be greater than 0.00! Try again.\n";
            return false;
        } else if (num > max)
        {
            std::cout << "Error! Number must be less than " << max << ". Try again.\n";
            return false;
        } else
        {
            return true;
        }
    }
}
