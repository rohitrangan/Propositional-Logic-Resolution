/* Parsing the input file and creating the set structure for our resolution
 * procedure.
 */

#include "../include/parse_input.hpp"
#include "../include/string_util.hpp"

namespace parse
{

int parse_line (string line, set <string> &t)
{
    if (line.length () == 0)
        return -1;

    str_util::rtrim ('.', line);
    
    vector <string> split_str;
    str_util::split (line, ' ', split_str);
    for (int i = 0; i < split_str.size (); i++)
    {
        t.insert (split_str[i]);
    }
    return 0;
}

void create_set (string f_name, set <set <string> > &s)
{
    ifstream inp (f_name.c_str (), ios::in);
    char cur_line[MAX_LINE_LENGTH];

    while (inp.good ())
    {
        set <string> cur_set;
        inp.getline (cur_line, MAX_LINE_LENGTH);
        string x (cur_line);
        if (parse_line (x, cur_set) != -1)
            s.insert (cur_set);
    }

    set <set <string> >::iterator i;
    for (i = s.begin (); i != s.end (); i++)
    {
        set <string> t = *i;
        set <string>::iterator j;
        cout << "Subset:- ";
        for (j = t.begin (); j != t.end (); j++)
        {
            cout << *j << ", ";
        }
        cout << "\n\n";
    }
}

}
