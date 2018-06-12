#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>

namespace client{
    struct Account {
        using AcctKey = int; //!< alias.

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
        int get_key(){
            return (AcctKey) account_n;
        }
    };
}

#endif
