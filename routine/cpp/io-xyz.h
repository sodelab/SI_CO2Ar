#ifndef IO_XYZ_H
#define IO_XYZ_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

namespace kit { namespace io {

void load_xyz(std::istream&             is,
              std::string&              comment,
              std::vector<std::string>& elements, // clears the original
              std::vector<double>&      xyz);     // clears the original

void save_xyz(std::ostream&                   os,
              const std::string&              comment,
              const std::vector<std::string>& elements,
              const std::vector<double>&      xyz);

}

void loadxyz(std::istream&             is,
	      size_t&                   natoms,
              std::string&              comment,
              std::vector<std::string>& elements,
              std::vector<double>&      xyz) 
{
    comment.clear();
    elements.clear();
    xyz.clear();

    std::string line;
    std::getline(is, line);

    if (is.eof())
        return;

    std::istringstream iss(line);
    iss >> natoms;

    xyz.reserve(3*natoms);
    elements.reserve(natoms);

    std::getline(is, comment);

    size_t lineno(2), n(0);
    while (!is.eof()) {
        std::getline(is, line);
        ++lineno;

        if (line.length() == 0)
            continue;

        std::string element;
        double x, y, z;

        iss.clear();
        iss.str(line);
        iss >> element >> x >> y >> z;
        if (iss.fail()) {
            std::ostringstream oss;
            oss << "unexpected text at line " << lineno << " of the XYZ stream";
            throw std::runtime_error(oss.str());
        }

        elements.push_back(element);

        xyz.push_back(x);
        xyz.push_back(y);
        xyz.push_back(z);
	
        if (++n == natoms)
            break;
    }

    if (n != natoms) {
        std::ostringstream oss;
        oss << "wrong number of atoms ("
            << n << " instead of " << natoms
            << ") in the XYZ stream";
        throw std::runtime_error(oss.str());
    }
}
} // namespace kit::io

#endif // IO_XYZ_H
