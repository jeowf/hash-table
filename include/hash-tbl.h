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
        using Entry = HashEntry< KeyType, DataType >; 
        /**
         * @brief  Hash Constructor
         *
         * @param  tbl_size   table size
         *
         */
        HashTbl( size_t tbl_size = DEFAULT_SIZE) : m_size( tbl_size ), m_count(0){
            prime( tbl_size ) ? : tbl_size = nextPrime(tbl_size);
            m_data_table = new std::forward_list < Entry > [tbl_size];
        }

        /**
         * @brief  Hash Destructor
         *
         */
        virtual ~HashTbl(){
            clear();
            delete [] m_data_table;
        }

        /**
         * @brief  A function to insert or modify a value in the hash table.
         *
         * @param  k_   The key of the item.
         * @param  d_   The data to be stored.
         *
         * @return Returns true if the data was inserted, false if it was modified.
         */
        bool insert (const KeyType & k_, const DataType & d_);

        /**
         * @brief  A function to delete a value in the hash table.
         *
         * @param  k_   The key of the item.
         *
         * @return Returns true if the item was deleted, false if it was failed.
         */
        bool remove (const KeyType & k_);

        /**
         * @brief  A function to rescue the data to a object
         *
         * @param  k_   The key of the item.
         * @param  d_   The data to be stored.
         *
         * @return Returns true if the item was copy, false if it was failed.
         */
        bool retrieve (const KeyType & k_, DataType & d_) const;

        /**
         * @brief  A function to remove all elements on Hash Table
         *
         */
        void clear (void);

        /**
         * @brief  A function to verify if the Hash Table is empty
         *
         * @return Returns true if the table is empty.
         */
        bool empty (void);

        /**
         * @brief  A function to count the elements in Table
         *
         * @return Returns the number of elements
         */
        unsigned long int count (void) const;

        /**
         * @brief  A function to verify the table size
         *
         * @return Returns the table size
         */
        unsigned long int size (void) const;

        /**
         * @brief  A function to print the elements in table
         *
         */
        void print () const;

        /**
         * @brief  A function to verify if table size is prime
         *
         * @param  n the table size             
         * @return Returns true if the size is prime.
         */
        bool prime(size_t);

        /**
         * @brief  A function to search the next prime after n
         *
         * @param  n the table size
         *   
         * @return Returns the next prime number.
         */
        size_t nextPrime( size_t );

    private:

        /**
         * @brief When load factor is greater than 1.0 this funtion is called, 
         * changing the Hash table size to the next prime number after 2*size+1.
         */
        void rehash();
        unsigned int m_size; //!< Stores the size of tables.
        unsigned int m_count; //!< Stores the number of elements in table.
        std::forward_list < Entry > * m_data_table; //!< Dynamic List.

        static const short DEFAULT_SIZE = 11; //!< Default size to hash table.
    };

}

#include "hash-tbl.inl"

#endif
