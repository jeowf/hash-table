#include "hash-tbl.h"
#include "account.h"

namespace hash{
	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	//método para ver se o tamanho da tabela é primo
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::prime(size_t n){
        //se for par
        if (n % 2 == 0){
            return false;
        }
        //se for impar
        for( size_t i = 3; i < sqrt( n ); i++ ){
            if(n % i == 0){
                return false;
            }
        }
        //retorna true se for primo
        return true;
    }
    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    //achar o próximo primo depois de n
    size_t HashTbl<KeyType, DataType, KeyHash, KeyEqual>::nextPrime( size_t n ){
    	//enquanto não for primo...
        while ( prime( n ) == false ){
        	n++;
        }
        //retorna o primeiro primo encontrado
        return n;
    }

    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    //insere uma conta na tabela
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::insert (const KeyType & k_, const DataType & d_){
    	// se estiver cheia aumenta o tamanho
    	if ( m_size == m_count ){
            rehash();         
        }
        //instancias dos functors
    	KeyHash funcHash;
		KeyEqual funcEqual;
		//função de dispersão
 		size_t end = ( funcHash(k_) % m_size );
 		std::forward_list < Entry >  * objects = &(m_data_table[end]);

 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++){
 			//se for igual substitui
            if ( funcEqual( (*i).m_key, k_ ) ){
                (*i).m_data = (d_);
                return false;
            }
        }
        //se não for insere na tabela
 		Entry data( k_, d_);
        objects->push_front( data );
        m_count++;
        return true;

    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	//deleta um elemento da tabela
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::remove (const KeyType & k_){

    	KeyHash funcHash;
		KeyEqual funcEqual;

     	size_t end = ( funcHash(k_) % m_size );
 		std::forward_list < Entry >  * objects = &(m_data_table[end]);
 		//elemento antes do primeiro válido
 		auto pointer_before = m_data_table[ end ].before_begin(); 
 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++, pointer_before++){
 			//se as keys forem iguais deleta o item
            if ( funcEqual( (*i).m_key, k_ ) ){
                objects->erase_after(pointer_before);
                m_count--;
                return true;
            }
        }

 		return false;
     }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
     //recupera os dados de uma conta e salva em d_
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::retrieve (const KeyType & k_, DataType & d_) const{
    	KeyHash funcHash;
		KeyEqual funcEqual;

		size_t end = ( funcHash(k_) % m_size );

 		for (auto i = m_data_table[ end ].begin(); i !=m_data_table[ end ].end(); i++){
 			//se as keys forem iguais salva os dados em d_
            if ( funcEqual( (*i).m_key, k_ ) ){
                d_ = (*i).m_data;
                return true;
            }
        }
    	return false;
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	//limpa os dados da tabela
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear (){
    	//percorre a tabela e limpa cada lista encadeada
    	for (size_t i = 0; i < m_size; i++){
            m_data_table[ i ].clear();
        }
        m_count = 0;
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	//verifica se a tabela está vazia
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::empty(){
        return ( m_count == 0 );
    }

	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
	//verifica quantos elementos estão na tabela
    unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::count () const{
        return m_count; 
    }
    //DEBUG
    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    //retorna o tamanho da tabela
    unsigned long int HashTbl<KeyType, DataType, KeyHash, KeyEqual>::size () const{
        return m_size; 
    }

   	template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
   	//se a tabela estiver lotada cria uma tabela com o primeiro primo maior que dobro do tamanho antigo
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::rehash() {
        auto old_size = m_size;
        m_size = (m_size * 2) + 1; 
        //pega o proximo primo maior que o dobro do tamanho antigo        
        m_size = nextPrime(m_size);
        auto temp = m_data_table;
        m_data_table = new std::forward_list < Entry > [ m_size ];
                
        m_count = 0; 
        //copia os elementos da tabela antiga para a nova        
        for ( size_t i = 0; i < old_size; i++ ){
            std::forward_list < Entry > * objects = &(temp[i]);
            for (auto i = objects->begin(); i != objects->end(); i++){
                insert( (*i).m_key, (*i).m_data );
            }
        }
        //deleta a tabela antiga
        delete[] temp;
    }

    template<typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    //printa os elementos presentes a tabela
	void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::print() const{

		//Cabeçalho
		std::cout << "======================= Accounts ===========================\n";
		std::cout << "| Key |      Name      | Bank | Agency | Account |  Money  |\n";
		std::cout << "------------------------------------------------------------\n";

		for( auto i(0ul); i < m_size; ++i ){

			for (auto j = m_data_table[ i ].begin(); j !=m_data_table[ i ].end(); j++){
				auto data = (*j).m_data;
				std::cout << "|  " << i;
				std::cout << "  |  " << data.name;
				std::cout << "  |   " << data.bank_cod;
				std::cout << "  |  " << data.agency_n;
				std::cout << "  |  " << data.account_n;
				std::cout << "  | " << data.money << " |\n";
			}
		}

	}
}
