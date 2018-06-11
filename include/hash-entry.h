#ifndef _HASH_ENTRY_
#define _HASH_ENTRY_

namespace hash{
    class HashEntry {
    public:
        HashEntry (Keytype k_, DataType d_) : m_key (k_), m_data (d_)
        { /* Empty */ }

        KeyType m_key;   //!< Stores the key for an entry.
        DataType m_data; //!< Stores the data for an entry.

    };
}

#endif
