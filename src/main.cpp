/* Program starts execution from here.
 */

#include "logic.hpp"
#include "common.hpp"
#include "parse_input.hpp"

int main ()
{
    set <set <string> > s;
    parse::create_main_set ("data.txt", s);

#if DEBUG == 1
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
#endif

    return 0;
}
