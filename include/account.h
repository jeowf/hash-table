#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>
#include <tuple>
#include <utility>

namespace client{
    struct Account {
        //using AcctKey = int;                                  //versão 1
        //using AcctKey = std::pair<std::string, int>;          //versão 2
        using AcctKey = std::tuple<std::string, int, int, int>; //versão 3

        std::string name;
        int bank_cod;
        int agency_n;
        int account_n;
        float money;

        Account (std::string n, int b, int ag, int ac, float m )  :
            name(n), bank_cod(b), agency_n(ag), account_n(ac), money(m)
            { /* Empty */ }

        AcctKey get_key(){
            // return (AcctKey) account_n;                          //versão 1
            // return std::make_pair( name, account_n );            //versão 2
            return std::make_tuple(name, bank_cod, agency_n, account_n); //versão 3
        }
    };
}

#endif
