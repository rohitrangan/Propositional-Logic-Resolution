/* Logic helper functions and the resolution procedure function.
 */

#ifndef LOGIC_HPP_
#define LOGIC_HPP_

#include "common.hpp"
#include "parse_input.hpp"

#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

namespace logic
{

void de_morgan_and2or (const set <string> &inp, set <string> &op);

class Resolution
{
  private:
    set <string> literals;
    map <string, set <string> > checked_pairs;
    set <set <string> > clauses;

    void populate_literals ();
    void concat_clauses (const set <string> &c1, const set <string> &c2,
                         string &res);
    void resolve (const set <string> &c1, const set <string> &c2,
                  const string &literal, set <string> &resolvent);
    bool is_clashing (const set <string> &c1, const set <string> &c2,
                      const string &literal);
    bool is_tautology (const string& l1, const string& l2);
    bool is_tautology (const set <string> &c);

  public:
    Resolution ();
    Resolution (const set <set <string> > &original_set, string derivable);

    /* Returns true if unsatisfiable, false if satisfiable.
     */
    bool start ();
};

}

#endif  /* LOGIC_HPP_ */
