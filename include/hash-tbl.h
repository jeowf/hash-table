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

        HashTbl( size_t tbl_size = DEFAULT_SIZE) : m_size( tbl_size ), m_count(0){
            prime( tbl_size ) ? : tbl_size = nextPrime(tbl_size);
            m_data_table = new std::forward_list < Entry > [tbl_size];
        }


        virtual ~HashTbl(){
            clear();
            delete [] m_data_table;
        }


        bool insert (const KeyType & k_, const DataType & d_);
        bool remove (const KeyType & k_);
        bool retrieve (const KeyType & k_, DataType & d_) const;
        void clear (void);
        bool empty (void);

        unsigned long int count (void) const;
        unsigned long int size (void) const;
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
