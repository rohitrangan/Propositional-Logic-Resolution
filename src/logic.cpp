/* Logic helper functions and the resolution procedure function.
 */

#include "logic.hpp"

namespace logic
{

void de_morgan_and2or (const set <string> &inp, set <string> &op)
{
    set <string>::iterator it;
    for (it = inp.begin (); it != inp.end (); ++it)
    {
        string chk = *it;
        string mod;
        if (chk[0] == '!')
            mod = chk.substr (1, string::npos);
        else
            mod = "!" + chk;
        op.insert (mod);
    }
}

class Resolution
{
}

}
