#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>

namespace client{
    struct Account {
        using AcctKey = int;

        std::string name;
        int bank_cod;
        int agency_n;
        int account_n;
        float money;

        Account (std::string n, int b, int ag, int ac, float m )  :
            name(n), bank_cod(b), agency_n(ag), account_n(ac), money(m)
            { /* Empty */ }

        int get_key(){
            return (AcctKey) account_n;
        }
    };

    struct KeyHash {
        std::size_t operator()( const Account::AcctKey & k_ ) const{
            return std::hash <int>()( k_ ) ;
        }
    };

        struct KeyEqual {
        std::size_t operator()( const Account::AcctKey & lhs_ , const Account::AcctKey & rhs_ ) const{
            return lhs_ == rhs_ ;
        }
    };
}

#endif
