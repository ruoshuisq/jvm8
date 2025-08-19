//
// Created by stephensdesktop on 2025/8/1.
//

#ifndef MATHUTIL_HPP
#define MATHUTIL_HPP
#include <sstream>

std::string ftoa(float value) {
    std::ostringstream o;
    if (!(o << value))
        return "";
    return o.str();
}

std::string dtoa(double value) {
    std::ostringstream o;
    if (!(o << value))
        return "";
    return o.str();
}

class MathUtil {

};



#endif //MATHUTIL_HPP
