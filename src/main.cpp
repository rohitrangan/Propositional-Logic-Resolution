/* Program starts execution from here.
 */

#include "parse_input.hpp"

int main ()
{
    set <set <string> > s;
    parse::create_set ("data.txt", s);

    return 0;
}
