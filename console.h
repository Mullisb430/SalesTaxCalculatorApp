#ifndef MULLIS_TAX_H
#define MULLIS_TAX_H

#include <string>
#include <limits>


// Retrieval function declarations
namespace console
{
    // Only doubles between 0 > double < 100_000_000_000 are accepted
    double getDouble(std::string prompt, double min = 0.00, double max = 100000000000.00);
    char getChar(std::string prompt, bool add_blank_line = true);
    double getTaxAmount(double total);
    double getTotalWithTaxes(double total);
}
#endif


