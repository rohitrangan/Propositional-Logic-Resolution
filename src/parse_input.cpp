/* Parsing the input file and creating the set structure for our resolution
 * procedure.
 */

#include "common.hpp"
#include "parse_input.hpp"
#include "string_util.hpp"

namespace parse
{

int parse_inpfile_line (string line, set <string> &t)
{
    str_util::rtrim ('.', line);
    str_util::trim ('\n', line);
    if (line.length () == 0)
        return -1;
    
    vector <string> split_str;
    str_util::split (line, ' ', split_str);
    if (split_str.size () == 0)
    {
        t.insert (line);
        return 0;
    }
    for (int i = 0; i < split_str.size (); ++i)
    {
        if (split_str[i].length () != 0)
            t.insert (split_str[i]);
    }
    return 0;
}

void create_main_set (string f_name, set <set <string> > &s)
{
    ifstream inp (f_name.c_str (), ios::in);
    string cur_line;

    while (inp.good ())
    {
        set <string> cur_set;
        std::getline (inp, cur_line, '.');
        if (parse_inpfile_line (cur_line, cur_set) != -1)
            s.insert (cur_set);
    }

#if PARSE_DEBUG == 1
    cout << "\n\nPARSE_DEBUG\n\n";
    set <set <string> >::iterator i;
    for (i = s.begin (); i != s.end (); ++i)
    {
        set <string> t = *i;
        set <string>::iterator j;
        cout << "Subset:- ";
        for (j = t.begin (); j != t.end (); ++j)
        {
            cout << *j << ", ";
        }
        cout << "\n\n";
    }
    cout << "\n\nPARSE_DEBUG END\n\n";
#endif
}

int parse_inp_line (string line, set <string> &t)
{
    str_util::rtrim ('.', line);
    str_util::trim ('\n', line);
    if (line.length () == 0)
        return -1;

    vector <string> split_str;
    str_util::split (line, ',', split_str);
    if (split_str.size () == 0)
    {
        str_util::trim (' ', line);
        t.insert (line);
        return 0;
    }
    for (int i = 0; i < split_str.size (); ++i)
    {
        str_util::trim (' ', split_str[i]);
        if (split_str[i].length () != 0)
            t.insert (split_str[i]);
    }
    return 0;
}

}
