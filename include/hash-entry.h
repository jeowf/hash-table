#ifndef _HASH_ENTRY_
#define _HASH_ENTRY_

namespace hash{
	template < typename KeyType, typename DataType >
    class HashEntry {
    public:
        /**
         * @brief  HashEntry Constructor
         *
         * @param  k_   The key of the item.
         * @param  d_   The data to be stored.
         *
         */
        HashEntry (KeyType k_, DataType d_) : m_key (k_), m_data (d_)
        { /* Empty */ }

        KeyType m_key;   //!< Stores the key for an entry.
        DataType m_data; //!< Stores the data for an entry.

    };
}

#endif
