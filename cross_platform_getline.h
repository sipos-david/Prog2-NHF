#ifndef CROSS_PLATFORM_GETLINE_H
#define CROSS_PLATFORM_GETLINE_H

#include <iostream>
#include <string>

namespace cp {	    //cross-platform getline

std::istream& getline(std::istream& is, std::string& str) {
    std::getline(is, str);
    if (str.size() && *str.rbegin() == '\r')
        str.erase(str.size()-1);
    return is;
}

} // namespace cp
#endif // CROSS_PLATFORM_GETLINE_H