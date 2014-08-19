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

void Resolution::populate_literals ()
{
    set <set <string> >::iterator it;
    for (it = clauses.begin (); it != clauses.end (); ++it)
    {
        set <string> clause = *it;
        set <string>::iterator c_it;
        for (c_it = clause.begin (); c_it != clause.end (); ++c_it)
        {
            string c_literal = *c_it;
            if (c_literal[0] == '!')
                literals.insert (c_literal.substr (1, string::npos));
            else
                literals.insert (c_literal);
        }
    }
#if LOGIC_DEBUG == 1
    cout << "\n\nLOGIC_DEBUG\n\n";
    set <string>::iterator it1;
    for (it1 = literals.begin (); it1 != literals.end (); ++it1)
    {
        cout << "literal = " << *it1 << endl;
    }
    cout << "\n\nLOGIC_DEBUG END\n\n";
#endif
}

void Resolution::concat_clauses (const set <string> &c1,
                                 const set <string> &c2, string &res)
{
    set <string>::const_iterator it;
    for (it = c1.cbegin (); it != c1.cend (); ++it)
    {
        const string read = *it;
        res += read;
    }
    res += ";";
    for (it = c2.cbegin (); it != c2.cend (); ++it)
    {
        const string read = *it;
        res += read;
    }
}

void Resolution::resolve (const set <string> &c1, const set <string> &c2,
                          const string &literal, set <string> &resolvent)
{
    set <string> diff;
    set <string> tmp_resolvent;
    diff.insert (literal);
    diff.insert ('!' + literal);
    set_union (c1.cbegin (), c1.cend (), c2.cbegin (), c2.cend (),
               inserter (tmp_resolvent, tmp_resolvent.begin ()));
    set_difference (tmp_resolvent.begin (), tmp_resolvent.end (),
                    diff.begin (), diff.end (),
                    inserter (resolvent, resolvent.begin ()));
#if LOGIC_DEBUG == 1
    set <string>::iterator it1;
    for (it1 = resolvent.begin (); it1 != resolvent.end (); ++it1)
    {
        cout << "Resolvent components = " << *it1 << "\n";
    }
#endif
    /*set <string>::const_iterator it;
    for (it = c1.cbegin (); it != c1.cend (); ++it)
    {
        const string cmp = *it;
        if ((cmp != literal) && (cmp != ('!' + literal)))
            resolvent.insert (cmp);
    }
    for (it = c2.cbegin (); it != c2.cend (); ++it)
    {
        const string cmp = *it;
        if ((cmp != literal) && (cmp != ('!' + literal)))
            resolvent.insert (cmp);
    }*/
}

bool Resolution::is_clashing (const set <string> &c1, const set <string> &c2,
                              const string &literal)
{
    const string not_literal = "!" + literal;
    if (c1.find (literal) == c1.cend () && c1.find (not_literal) == c1.cend ())
        return false;
    if (c2.find (literal) == c2.cend () && c2.find (not_literal) == c2.cend ())
        return false;

    if (c1.find (literal) != c1.cend ())
    {
        if (c2.find (not_literal) != c2.cend ())
            return true;
        else
            return false;
    }
    else if (c1.find (not_literal) != c1.cend ())
    {
        if (c2.find (literal) != c2.end ())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Resolution::is_tautology (const string &l1, const string &l2)
{
    if (l1[0] != '!' && l2[0] != '!')
        return false;

    if (l1[0] == '!')
    {
        if (l2 == l1.substr (1, string::npos))
            return true;
        else
            return false;
    }
    if (l2[0] == '!')
    {
        if (l1 == l2.substr (1, string::npos))
            return true;
        else
            return false;
    }
}

bool Resolution::is_tautology (const set <string> &c)
{
    set <string>::const_iterator it_i, it_j;
    for (it_i = c.cbegin (); it_i != c.cend (); ++it_i)
    {
        string literal = *it_i;
        for (it_j = c.cbegin (); it_j != c.cend (); ++it_j)
        {
            string l_cmp = *it_j;
            if (is_tautology (literal, l_cmp))
                return true;
        }
    }
    return false;
}

Resolution::Resolution ()
{
}

Resolution::Resolution (const set <set <string> > &original_set,
                        string derivable)
{
    set <string> g, act_g;
    parse::parse_inp_line (derivable, g);
    de_morgan_and2or (g, act_g);
    clauses = original_set;
    clauses.insert (act_g);
    populate_literals ();
}

bool Resolution::start ()
{
    set <string>::iterator l_it;
    int no_clash_count = 0;
    l_it = literals.begin ();
    while (true)
    {
        string l_use = *l_it;
        set <set <string> > resolved_clauses;
        set <set <string> >::iterator cs_it_i, cs_it_j;
        for (cs_it_i = clauses.begin (); cs_it_i != clauses.end (); ++cs_it_i)
        {
            cs_it_j = cs_it_i;
            ++cs_it_j;
            for (; cs_it_j != clauses.end (); ++cs_it_j)
            {
                set <string> c1 = *cs_it_i;
                set <string> c2 = *cs_it_j;
#if LOGIC_DEBUG == 1
                cout << "\n\nLOGIC_DEBUG\n\n";
                cout << "l_use = " << l_use << "\n\n";
                set <string>::iterator it_tmp;
                for (it_tmp = c1.begin (); it_tmp != c1.end (); ++it_tmp)
                {
                    cout << "ele_i = " << *it_tmp << ", ";
                }
                cout << "\n\n";
                for (it_tmp = c2.begin (); it_tmp != c2.end (); ++it_tmp)
                {
                    cout << "ele_j = " << *it_tmp << ", ";
                }

                cout << "\n\nLOGIC_DEBUG_END\n\n";
#endif
                string concat_pair;
                concat_clauses (c1, c2, concat_pair);
                if ((is_clashing (c1, c2, l_use)) &&
                    (checked_pairs[l_use].find (concat_pair) ==
                     checked_pairs[l_use].end ()))
                {
                    string concat_pair;
                    concat_clauses (c1, c2, concat_pair);
#if LOGIC_DEBUG == 1
                    cout << "\n\nLOGIC_DEBUG\n\n";
                    cout << "l_use = " << l_use << endl;
                    cout << "Resolved pair = " << concat_pair << endl;
                    cout << "\n\nLOGIC_DEBUG_END\n\n";
#endif
                    checked_pairs[l_use].insert (concat_pair);
                    set <string> resolvent;
                    resolve (c1, c2, l_use, resolvent);
                    if (resolvent.size () == 0)
                        return true;
                    if (clauses.find (resolvent) == clauses.end () &&
                        !is_tautology (resolvent))
                    {
                        resolved_clauses.insert (resolvent);
                        no_clash_count = 0;
                    }
                }
            }
        }
        if (resolved_clauses.size () == 0)
            ++no_clash_count;
        else
        {
            set <set <string> > replace_clauses;
            set_union (clauses.begin (), clauses.end (),
                       resolved_clauses.begin (), resolved_clauses.end (),
                       inserter (replace_clauses, replace_clauses.begin ()));
            clauses = replace_clauses;
        }
        if (no_clash_count == literals.size ())
            return false;

        ++l_it;
        if (l_it == literals.end ())
            l_it = literals.begin ();
    }
}

}
