/* Parsing the input file and creating the set structure for our resolution
 * procedure.
 */

#ifndef PARSE_INPUT_HPP_
#define PARSE_INPUT_HPP_

#include <set>
#include <string>
#include <fstream>
#include <iostream>

#define MAX_LINE_LENGTH 256

using namespace std;

namespace parse
{

int parse_line (string line, set <string> &t);

void create_set (string f_name, set <set <string> > &s);

}

#endif  /* PARSE_INPUT_HPP_ */
