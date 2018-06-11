#ifndef _HASH_TBL_
#define _HASH_TBL_

// includes

namespace hash{
    template < typename KeyType, typename DataType >
    class HashTbl {
    public:
        using Entry = Hash < KeyType, DataType >; //!< Alias

        HashTbl (size_t tbl_size = DEFAULT_SIZE);

        virtual ~HashTbl();

        bool insert (const KeyType & k_, const DataType & d_);
        bool remove (const KeyType & k_);
        bool retrieve (const KeyType & k_, const DataType & d_) const;
        void clear (void);
        bool empty (void);

        unsigned long int count (void) const;
        void print () const;

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
