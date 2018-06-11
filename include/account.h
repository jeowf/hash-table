#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>

namespace client{
    struct Account {
        std::string name;
        int bank_cod;
        int agency_n;
        int account_n;
        float money;

        Account (std::string n, int b, int ag, int ac, float m )  :
            name(n), bank_cod(b), agency_n(ag), account_n(ac), money(m)
            { /* Empty */ }

        int get_key();
    };
}

#endif
