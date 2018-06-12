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

        std::string name;//!< Stores the name in account.
        int bank_cod;//!< Stores the bank code in account.
        int agency_n;//!< Stores the agency number in account.
        int account_n;//!< Stores the number of account.
        float money;//!< Stores the money i account.

        /**
         * @brief  Account Constructor
         *
         * @param  n   name
         * @param  b   bank code
         * @param  ag  agency
         * @param  ac  account number
         * @param  m   money
         *
         */
        Account (std::string n, int b, int ag, int ac, float m )  :
            name(n), bank_cod(b), agency_n(ag), account_n(ac), money(m)
            { /* Empty */ }


         /**
         * @brief  get unique key in account
         *
         * @return Return the key
         */
        AcctKey get_key(){
            // return (AcctKey) account_n;                          //versão 1
            // return std::make_pair( name, account_n );            //versão 2
            return std::make_tuple(name, bank_cod, agency_n, account_n); //versão 3
        }
    };
}

#endif
