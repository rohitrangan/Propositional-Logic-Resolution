/*
    pseudo2code - string_util.h
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
 *  @file string_util.h
 *  @author Rohit Rangan
 *  @date 23/02/2013
 *  @brief Utility funtions needed to manipulate strings.
 *  
 *  @addtogroup str_util
 *  @{
 */

#ifndef SRC_INCLUDE_STRING_UTIL_H_
#define SRC_INCLUDE_STRING_UTIL_H_

#include <string>
#include <vector>

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
 *  @param[out]  line    The line from which we remove the comment.
 */
void removeComment (std::string& line);

/**
 *  @brief Trims the character c from the right of the string.
 *
 *  @param[in]  c       The character to trim.
 *  @param[out] line    The line which we trim.
 */
void rtrim (char c, std::string& line);

/**
 *  @brief Trims the character c from the left of the string.
 *
 *  @param[in]  c       The character to trim.
 *  @param[out] line    The line which we trim.
 */
void ltrim (char c, std::string& line);

/**
 *  @brief Trims the character c from the left and right of the string.
 *
 *  @param[in]  c       The character to trim.
 *  @param[out] line    The line which we trim.
 */
inline void trim (char c, std::string& line) {
    rtrim (c, line);
    ltrim (c, line);
}

/**
 *  @brief Splits the line using the given delimiter.
 *
 *  @param[in]  line    The line which we split.
 *  @param[in]  delim   The delimiter.
 *  @param[out] val     A vector containing the split substrings.
 */
void split (const std::string& line, char delim,
            std::vector<std::string>& val);

/**
 *  @brief Removes double quotes from the line.
 *
 *  @param[out] line    The line from which we remove the quotes.
 */
void removeQuotes (std::string& line);

} /*namespace str_util */

#endif  /*SRC_INCLUDE_STRING_UTIL_H_ */

/** @} */
