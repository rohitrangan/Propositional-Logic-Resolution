/* Program starts execution from here.
 */

#include "logic.hpp"
#include "common.hpp"
#include "parse_input.hpp"

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Usage - ./resolution filename\n\n";
        return 1;
    }
    set <set <string> > clauses;
    parse::create_main_set (argv[1], clauses);

#if MAIN_DEBUG == 1
    cout << "\n\nMAIN_DEBUG\n\n";
    set <string> t1, t2;
    parse::parse_inp_line ("t.", t1);
    logic::de_morgan_and2or (t1, t2);
    set <string>::iterator it;
    for (it = t2.begin (); it != t2.end (); ++it)
    {
        cout << "ele = " << *it << endl;
    }
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
    cout << "\n\nMAIN_DEBUG END\n\n";
#endif

    while (true)
    {
        cout << "? ";
        string inp;
        getline (cin, inp);
        logic::Resolution r1 (clauses, inp);
        bool tmp = r1.start ();
        if (tmp)
            cout << "Yes.\n";
        else
            cout << "No.\n";
    }

    return 0;
}
