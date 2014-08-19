/* Parsing the input file and creating the set structure for our resolution
 * procedure.
 */

#ifndef PARSE_INPUT_HPP_
#define PARSE_INPUT_HPP_

#include <set>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

namespace parse
{

int parse_inpfile_line (string line, set <string> &t);

void create_main_set (string f_name, set <set <string> > &s);

int parse_inp_line (string line, set <string> &t);

}

#endif  /* PARSE_INPUT_HPP_ */
