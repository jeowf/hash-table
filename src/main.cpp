#include "../include/hash-tbl.h"
#include "../include/account.h"
#include "../include/hash-entry.h"
#include <iostream>

struct KeyHash {
	std::size_t operator()( const client::Account::AcctKey & k_ ) const{
        return std::hash <int>()( k_ ) ;
    }
};

struct KeyEqual {
    std::size_t operator()( const client::Account::AcctKey & lhs_ , const client::Account::AcctKey & rhs_ ) const{
        return lhs_ == rhs_ ;
    }
};

int main(){
	hash::HashTbl<int, client::Account, KeyHash, KeyEqual> bank_table;
	const unsigned long int a =  bank_table.size();
	std::cout << a << std::endl;

	std::cout << ">>> Inserindo as contas <<< \n";
	client::Account conta_1 = { "Glen Glen   ",    1, 3404, 29157, 3578.99 };
	client::Account conta_2 = { "Gegeo       ",    7, 6512, 54982, 8895.89 };
	client::Account conta_3 = { "Roberto     ",    6, 1658, 34897, 4782.73 };
	client::Account conta_4 = { "Mossoró     ",    5, 7985, 16589, 1025.26 };
	client::Account conta_5 = { "Confuzo     ",    2, 4462, 76538, 7985.41 };
	client::Account conta_6 = { "Dattebayo   ",    3, 5678, 76538, 3000.19 };

	bank_table.insert( conta_1.get_key(), conta_1 );
	bank_table.insert( conta_2.get_key(), conta_2 );
	bank_table.insert( conta_3.get_key(), conta_3 );
	bank_table.insert( conta_4.get_key(), conta_4 );
	bank_table.insert( conta_5.get_key(), conta_5 );
	bank_table.insert( conta_6.get_key(), conta_6 );

	bank_table.print();

	std::cout << std::endl;

	std::cout << ">>> Removendo usuários : " << conta_3.name << " , " << conta_6.name << " <<< \n";
	bank_table.remove( conta_3.get_key() );
	bank_table.remove( conta_6.get_key() );
	bank_table.print();
	std::cout << std::endl;

	std::cout << ">>> Recuperando dados do usuário 2 <<< \n";
	
	client::Account conta("Default   ",    0,0, 0, 0.0);

	bank_table.retrieve( conta_2.get_key(), conta );
	std::cout << ">>> Usuario 2 <<< \nNome : " << conta.name << "\n";
	std::cout << "Banco : " << conta.bank_cod << "\n";
	std::cout << "Agencia : " << conta.agency_n << "\n";
	std::cout << "Account Nº : " << conta.account_n << "\n";
	std::cout << "Money : " << conta.money << "\n";

	std::cout << std::endl;

	std::cout << ">>> Redimensionando a tabela <<< \n";
	hash::HashTbl<int, client::Account, KeyHash, KeyEqual> bank_table2(5);

	client::Account c_conta_1 = { "Glen Glen   ",    1, 3404, 29157, 3578.99 };
	client::Account c_conta_2 = { "Gegeo       ",    7, 6512, 54982, 8895.89 };
	client::Account c_conta_3 = { "Roberto     ",    6, 1658, 34897, 4782.73 };
	client::Account c_conta_4 = { "Mossoró     ",    5, 7985, 16589, 1025.26 };
	client::Account c_conta_5 = { "Confuzo     ",    2, 4462, 76538, 7985.41 };
	client::Account c_conta_6 = { "Dattebayo   ",    3, 5678, 76538, 3000.19 };


	bank_table2.insert( c_conta_1.get_key(), c_conta_1 );
	bank_table2.insert( c_conta_2.get_key(), c_conta_2 );
	bank_table2.insert( c_conta_3.get_key(), c_conta_3 );
	bank_table2.insert( c_conta_4.get_key(), c_conta_4 );
	bank_table2.insert( c_conta_5.get_key(), c_conta_5 );


	std::cout << std::endl;

	std::cout << "Tamanho com as primeiras inserções de usuarios: " << bank_table2.size() << "\n";
	std::cout << "Quantidade de usuarios: " << bank_table2.count() << "\n";
	bank_table2.print();
	std::cout << std::endl;


	bank_table2.insert( c_conta_6.get_key(), c_conta_6 );
	std::cout << "Novo tamanho após inserção de mais um usuario: " << bank_table2.size() << "\n";
	std::cout << "Quantidade de usuarios: " << bank_table2.count() << "\n";
	bank_table2.print();


}