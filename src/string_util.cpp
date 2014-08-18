/*
    pseudo2code - string_util.cpp
    Author :- Rohit Rangan

    This file is part of pseudo2code.

    pseudo2code is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pseudo2code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with pseudo2code.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 *  @file string_util.cpp
 *  @author Rohit Rangan
 *  @date 23/02/2013
 *  @brief Utility funtions needed to manipulate strings.
 */

/**
 *  @defgroup str_util String Utilities
 *  @brief Contains utility functions required to modify strings.
 *  @{
 */

#include "string_util.hpp"

#include <algorithm>

/**
 * @brief String Utilities Implementation.
 * @details All functions inside this namespace are used to implement various
 *          useful string manipulations.
 */
namespace str_util {

/**
 *  @brief Removes comments in a given line.
 *  @detils Finds the position of the first '#' in the string and erases
 *          all the characters that come after it.
 *
 *  @param  line    The line from which we remove the comment.
 */
void removeComment (std::string& line)
{
    size_t found = line.find ("#");
    if (found == std::string::npos)
        return;
    else
        line = line.erase (found, std::string::npos);
}

/**
 *  @brief Trims the character c from the right of the string.
 *
 *  @param[in]  c       The character to trim.
 *  @param[out] line    The line which we trim.
 */
void rtrim (char c, std::string& line)
{
    if (line.empty ())
        return;
    std::string::iterator p;

    for (p = line.end () ; (p != line.begin ()) && (*(--p) == c) ;);

    if (*p != c)
        p++;
    line.erase (p, line.end ());
}

/**
 *  @brief Trims the character c from the left of the string.
 *
 *  @param[in]  c       The character to trim.
 *  @param[out] line    The line which we trim.
 */
void ltrim (char c, std::string& line)
{
    if (line.empty ())
        return;

    int i = 0;
    
    while (line[i] == c)
        ++i;
    
    //if (i)
        line.erase (0, i);
}

/**
 *  @brief Splits the line using the given delimiter.
 *
 *  @param[in]  line    The line which we split.
 *  @param[in]  delim   The delimiter.
 *  @param[out] val     A vector containing the split substrings.
 */
void split (const std::string& line, char delim, std::vector<std::string>& val)
{
    std::string::size_type i = 0;
    std::string::size_type j = line.find (delim);

    while (j != std::string::npos)
    {
        val.push_back (line.substr (i, j-i));
        i = ++j;
        j = line.find (delim, j);

        if (j == std::string::npos)
            val.push_back (line.substr (i, line.length ()));
    }
}

/**
 *  @brief Removes double quotes from the line.
 *
 *  @param[out] line    The line from which we remove the quotes.
 */
void removeQuotes (std::string& line)
{
    if (line.empty () || (line.find ('\"') == std::string::npos))
        return;

    line.erase (std::remove (line.begin (), line.end (), '\"'), line.end ());
}

} /*namespace str_util */

/** @} */
