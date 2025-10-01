#pragma once

#include <iostream>

class Sale
{
private:
    int date;
    double total;

public:
    Sale(int date, double total) : date(date), total(total) {}

    int getDate() const
    {
        return date;
    }

    double getTotal() const
    {
        return total;
    }

    bool operator<(const Sale &other) const
    {
        return this->date < other.date;
    }

    bool operator>(const Sale &other) const
    {
        return this->date > other.date;
    }

    bool operator==(const Sale &other) const
    {
        return this->date == other.date;
    }

    bool operator!=(const Sale &other) const
    {
        return this->date != other.date;
    }
};

inline std::ostream &operator<<(std::ostream &os, const Sale &sale)
{
    os << "Sale(Date: " << sale.getDate() << ", Total: " << sale.getTotal() << ")";
    return os;
}