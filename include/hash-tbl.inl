#include "hash-tbl.h"
#include "account.h"

namespace hash{
	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::prime(size_t n){
        if (n % 2 == 0){
            return false;
        }
        for( size_t i = 3; i <= sqrt( n ); i+=2 ){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    size_t HashTbl<KeyType, DataType, KeyHash, KeyEqual>::nextPrime( size_t n ){

        while ( prime( n ) == false ){
        	n += 2;
        }
        return n;
    }

   	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    HashTbl<KeyType, DataType, KeyHash, KeyEqual>::HashTbl( size_t tbl_size) : m_size( tbl_size ), m_count(0){
        prime( tbl_size ) ? : tbl_size = nextPrime(tbl_size);
        m_data_table = new std::forward_list < Entry > [tbl_size];
    }

   	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    HashTbl<KeyType, DataType, KeyHash, KeyEqual>::~HashTbl(){
    	while(m_size > 0){
        	delete (m_data_table + m_size - 1);
        	m_size--;
    	}
    	m_count = 0;
    }

    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::insert (const KeyType & k_, const DataType & d_){

    	if ( m_size == m_count ){
            rehash();
        }

    	KeyHash funcHash;
		KeyEqual funcEqual;

 		size_t end = ( funcHash(k_) % m_size );
 		std::forward_list < Entry >  * objects = &(m_data_table[end]);

 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++){

            if ( funcEqual( (*i).m_key, k_ ) ){
                (*i).m_data = (d_);
                return false;
            }
        }

 		Entry data( k_, d_);
        objects->push_front( data );
        m_count++;
        return true;

    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::remove (const KeyType & k_){
     	size_t end = ( funcHash(k_) % m_size );
 		std::forward_list < Entry >  * objects = &(m_data_table[end]);

 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++){

            if ( funcEqual( (*i).m_key, k_ ) ){
                objects.erase_after(i-1);
                return true;
            }
        }


 		return false;
     }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::retrieve (const KeyType & k_, const DataType & d_) const{
		size_t end = ( funcHash(k_) % m_size );
 		std::forward_list < Entry >  * objects = &(m_data_table[end]);


 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++){

            if ( funcEqual( (*i).m_key, k_ ) ){
                d_ = (*i).m_data;
                return true;
            }
        }
    	return true;
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear (){
    	for (size_t i = 0; i < m_size; i++){
            std::forward_list < Entry > * objects = &(m_data_table[i]);
            objects.clear();
        }
        m_count = 0;
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::empty(){
        return ( m_count == 0 );
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::count () const{
        return m_count; 
    }

   	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::rehash() {
        auto old_size = m_size;
        m_size = (m_size * 2) + 1; 
                
        m_size = nextPrime(m_size);
        auto temp = m_data_table;
        m_data_table = new std::forward_list < Entry > [ m_size ];
                
        m_count = 0; 
                
        for ( size_t i = 0; i < old_size; i++ ){
            std::forward_list < Entry > * objects = &(temp[i]);
            for (auto i = objects->begin(); i != objects->end(); i++){
                insert( (*i).m_key, (*i).m_data );
            }
        }
        delete[] temp;
    }

    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::print() const{

		//Cabeçalho
		std::cout << "======================= Accounts =======================\n";
		std::cout << "| Key |    Name    | Bank | Agency | Account | Money |\n";
		std::cout << "--------------------------------------------------------\n";

		for( auto i(0ul); i < m_size; ++i ){

			for (auto j = m_data_table[ i ].begin(); j !=m_data_table[ i ].end(); j++){
				auto data = (*j).m_data;
				std::cout << "  |  " << i;
				std::cout << "  |  " << data.name;
				std::cout << "  |   " << data.bank_cod;
				std::cout << "  |  " << data.agency_n;
				std::cout << "  |  " << data.account_n;
				std::cout << "  | " << data.money << " |\n";
			}
		}

	}
}
