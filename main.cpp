/* Name: Brandon Mullis
   Date: 06/19/2021
   Purpose: User enters in a list of items, the program adds up the list, calculates the tax on it (6%), and displays the total, tax total, and the total plus tax.
 */

#include "console.h"
#include <iostream>
#include <cmath>

using namespace console;

int main()
{
    double total = 0.00, entry = 1.00, salesTax;
    std::string itemPrompt = "Cost of item: ", againPrompt = "Again? (y, n): ";
    char again;
    
    std::cout << "Sales Tax Calculator" << std::endl << std::endl;
    std::cout << "ENTER ITEMS (ENTER 0 TO END)" << std::endl;
    
    
    // The progam's main loop, which gathers the total of the items entered, checks if value is valid and prompts the user to re-enter a value if needed.
    while(true)
    {
        entry = getDouble(itemPrompt);
        if(entry == 0)
        {
            break;
        }
        total += entry;
    }
    
    // Round the total to two decimal places, and calculate the sales tax total
    total = round(total * 100.00)/100.00;
    salesTax = round(getTaxAmount(total)*100.00)/100.00;
    
    
    // Display the total, tax total, and the grand total all in monetary like values (Have two decimal places). The "to_string" function converts the double to a string, and the "substr" function finds the decimal ('.') in the string and extends the string only far enough to expose the hundredths decimal spot, this makes the number look like a real cash amount and doesnt throw the rounding off at all. The '\t' line the "total", "sale tax", "total after tax" up in the console.
    std::cout << std::endl << "Total: \t\t\t\t" << std::to_string(total).substr(0, std::to_string(total).find('.')+3) << std::endl;
    std::cout << "Sales tax: \t\t\t" << std::to_string(salesTax).substr(0, std::to_string(salesTax).find('.')+3) << std::endl;
    std::cout << "Total after tax: \t" << std::to_string(getTotalWithTaxes(total)) .substr(0, std::to_string(getTotalWithTaxes(total)).find('.')+3) << std::endl << std::endl;
    
    // Prompt the user to use the program again
    again = getChar(againPrompt);
    
    if(again == 'n')
    {
        // User has indicated that they are done using the program
        ;
    } else if(again == 'y')
    {
        // User has indicated that they want to use the program again, and another session will be started
        std::cout << std::endl;
        main();
    }
    
}
