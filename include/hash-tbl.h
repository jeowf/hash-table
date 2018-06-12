#ifndef _HASH_TBL_
#define _HASH_TBL_

// includes
#include <forward_list>
#include <iostream>
#include <cmath>

#include "hash-entry.h"

namespace hash{

    template<typename KeyType, 
             typename DataType, 
             typename KeyHash = std::hash<KeyType>,
             typename KeyEqual = std::equal_to<KeyType>>

    class HashTbl {
    public:
        using Entry = HashEntry< KeyType, DataType >; //!< Alias

        HashTbl (size_t tbl_size = DEFAULT_SIZE);

        virtual ~HashTbl();

        bool insert (const KeyType & k_, const DataType & d_);
        bool remove (const KeyType & k_);
        bool retrieve (const KeyType & k_, const DataType & d_) const;
        void clear (void);
        bool empty (void);

        unsigned long int count (void) const;
        void print () const;
        bool prime(size_t);
        size_t nextPrime( size_t );

    private:
        void rehash();
        unsigned int m_size;
        unsigned int m_count;
        std::forward_list < Entry > * m_data_table;

        static const short DEFAULT_SIZE = 11;
    };



}

#include "hash-tbl.inl"

#endif
