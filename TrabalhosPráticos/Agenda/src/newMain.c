#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
UpdatePointers

  Atualiza os ponteiros internos para variáveis no buffer de memória
====================
*/
void UpdatePointers( void **pBuffer, void **userOption, void **counterPeoples, void **bufferSize, void **peoplesBuffer, void **name, void **email, void **age ) {
	*userOption = *pBuffer;
	*counterPeoples = *pBuffer + sizeof( int );
	*bufferSize = *pBuffer + 2 * sizeof( int );
	*peoplesBuffer = *pBuffer + 3 * sizeof( int ) + sizeof( size_t ) + 100 * sizeof( char );
	*name = *pBuffer + 2 * sizeof( int ) + sizeof( size_t );
	*email = *pBuffer + 2 * sizeof( int ) + sizeof( size_t ) + 50 * sizeof( char );
	*age = *pBuffer + 2 * sizeof( int ) + sizeof( size_t ) + 100 * sizeof( char );
}

/*
====================
GetPerson

  Retorna o endereço inicial de um registro no buffer
====================
*/
int GetPerson( void **pBuffer, void **userOption, void **counterPeoples, void **bufferSize, void **peoplesBuffer, void **currentPerson, void **name, void **email, void **age ) {
	void *tempBuffer, *endBuffer, *offset, *counter, *position;

	tempBuffer = realloc( *pBuffer, *(size_t *)*(bufferSize) + 2 * sizeof( int ) );
	if ( tempBuffer == NULL ) {
		printf( "\nErro ao alocar memória! Get.1\n" );
		return 1;
	}

	*pBuffer = tempBuffer;
	tempBuffer = NULL;
	UpdatePointers( pBuffer, userOption, counterPeoples, bufferSize, peoplesBuffer, name, email, age );
	endBuffer = *pBuffer + (*(size_t *)*(bufferSize)) + 2 * sizeof( int );
	*(size_t *)*(bufferSize) = (size_t)( endBuffer - *pBuffer );

	counter = endBuffer - sizeof( int );
	position = counter - sizeof( int );
	offset = *age;

	if ( *(int *)*(counterPeoples) == 0 ) {
		*currentPerson = NULL;
		return 1;
	}

	*(int *)offset = 0;
	if ( *(int *)*(userOption) == 1 ) {
		for ( *(int *)counter = 0; *(int *)counter < ((*(int *)*(counterPeoples)) - 1); (*(int *)counter)++ ) {
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += sizeof( int );
		}
	} else if ( *(int *)*(userOption) == 2 ) {
		printf( "\nDigite o nº de registro para remover (1 a %d): ", *(int *)*(counterPeoples) );
		scanf( "%d", (int *)position );
		if ( *(int *)position <= 0 || *(int *)position > *(int *)*(counterPeoples) ) {
			system( "clear" );
			printf( "\nPosição Inválida!\n" );
			return 1;
		}
		for ( *(int *)counter = 0; *(int *)counter < (*(int *)position) - 1; (*(int *)counter)++ ) {
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += sizeof( int );
		}
	} else if ( *(int *)*(userOption) == 3 ) {
		printf( "Digite o nome que deseja buscar: " );
		scanf( " %50[^\n]", (char *)name );
		getchar();

		for ( *(int *)counter = 0; *(int *)counter < *(int *)*(counterPeoples); (*(int *)counter)++ ) {
			if ( strcmp( (char *)(*peoplesBuffer + *(int *)offset), (char *)name ) == 0 ) {
				*currentPerson = *peoplesBuffer + *(int *)offset;
				return 0;
			}
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += strlen( (char *)(*peoplesBuffer) + *(int *)offset ) + 1;
			*(int *)offset += sizeof( int );
		}
		*currentPerson = NULL;
		return 0;
	}
	return 0;
}


/*
====================
ShowMenu

  Exibe o menu de opções
====================
*/
void ShowMenu( void ) {
	printf( "\n-------------------- MENU --------------------\n" );
	printf( "1 - Adicionar Pessoa (Nome, Idade, E-Mail)\n" );
	printf( "2 - Remover Pessoa\n" );
	printf( "3 - Buscar Pessoa\n" );
	printf( "4 - Listar Todos\n" );
	printf( "5 - Sair\n" );
	printf( "----------------------------------------------\n" );
}


/*
====================
Main

  Função principal que gerencia o fluxo do programa
====================
*/
int main( int argc, char const *argv[] ) {
	void *pBuffer, *endBuffer, *bufferSize, *tempBuffer, *userOption, *counterPeoples, *peoplesBuffer, *currentPerson, *name, *email, *age, *counter, *auxPerson, *offset;

	pBuffer = malloc( 3 * sizeof( int ) + sizeof( size_t ) + 100 * sizeof( char ) );
	if ( pBuffer == NULL ) {
		printf( "\nErro ao alocar memória! 0.0\n" );
		return 1;
	}

	UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );
	endBuffer = pBuffer + 3 * sizeof( int ) + sizeof( size_t ) + 100 * sizeof( char );

	*(size_t *)bufferSize = (size_t)( endBuffer - pBuffer );
	*(int *)counterPeoples = 0;

	do {
		ShowMenu();
		printf( "Digite uma opção: " );
		scanf( "%d", (int *)userOption );
		getchar();

		switch ( *(int *)userOption ) {
			// Adiciona um novo registro ao buffer
			case 1: {
				(*(int *)counterPeoples)++;
				system( "clear" );
				printf( "\n-------------- Adicionar Pessoa --------------\n" );
				printf( "Informe o nome: " );
				scanf( " %50[^\n]", (char *)name );
				getchar();
				printf( "Informe o e-mail: " );
				scanf( " %50[^\n]", (char *)email );
				getchar();

				tempBuffer = realloc( pBuffer, *(size_t *)bufferSize + (strlen( (char *)name ) + 1) * sizeof( char ) + (strlen( (char *)email ) + 1) * sizeof( char ) + sizeof( int ) );
				if ( tempBuffer == NULL ) {
					printf( "\nErro ao alocar memória! 1.1\n" );
					free( pBuffer );
					return 1;
				}

				pBuffer = tempBuffer;
				tempBuffer = NULL;
				UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );
				endBuffer = pBuffer + (*(size_t *)bufferSize) + (strlen( (char *)name ) + 1) * sizeof( char ) + (strlen( (char *)email ) + 1) * sizeof( char ) + sizeof( int );
				*(size_t *)bufferSize = (size_t)( endBuffer - pBuffer );

				if ( GetPerson( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age ) ) {
					free( pBuffer );
					return 1;
				}

				printf( "Informe a idade: " );
				scanf( "%d", (int *)age );
				memcpy( currentPerson, name, (strlen( (char *)name ) + 1) * sizeof( char ) );
				currentPerson += (strlen( (char *)name ) + 1) * sizeof( char );

				memcpy( currentPerson, email, (strlen( (char *)email ) + 1) * sizeof( char ) );
				currentPerson += (strlen( (char *)email ) + 1) * sizeof( char );

				memcpy( currentPerson, age, sizeof( int ) );
				currentPerson += sizeof( int );

				system( "clear" );
				printf( "\nRegistro adicionado com sucesso!\n" );
				break;
			}
			// Remove um registro do buffer através de index
			case 2: {
				if ( *(int *)counterPeoples != 0 ) {
					tempBuffer = realloc( pBuffer, *(size_t *)bufferSize + sizeof( int ) );
					if ( tempBuffer == NULL ) {
						printf( "\nErro ao alocar memória! 2.1\n" );
						free( pBuffer );
						return 1;
					}

					pBuffer = tempBuffer;
					tempBuffer = NULL;
					UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );
					endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof( int );
					*(size_t *)bufferSize = (size_t)( endBuffer - pBuffer );

					currentPerson = peoplesBuffer;
					system( "clear" );
					printf( "\n-------------- Remover Pessoa --------------\n\n" );

					for ( int i = 0; i < *(int *)counterPeoples; i++ ) {
						printf( "----------------- Registro %d ---------------\n", i + 1 );
						printf( "Nome: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "E-Mail: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "Idade: %d\n", *(int *)currentPerson );
						currentPerson += sizeof( int );
					}

					if ( GetPerson( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age ) ) {
						free( pBuffer );
						return 1;
					}

					auxPerson = currentPerson;
					printf( "\nRegistro removido:\n" );
					printf( "Nome: %s\n", (char *)auxPerson );
					auxPerson += (strlen( (char *)auxPerson ) + 1) * sizeof( char );
					printf( "E-Mail: %s\n", (char *)auxPerson );
					auxPerson += (strlen( (char *)auxPerson ) + 1) * sizeof( char );
					printf( "Idade: %d\n", *(int *)auxPerson );

					memmove( currentPerson, currentPerson + *(int *)age, *(size_t *)bufferSize - ((currentPerson - pBuffer) + *(int *)age) );
					(*(int *)counterPeoples)--;

					tempBuffer = realloc( pBuffer, *(size_t *)bufferSize - *(int *)age - sizeof( int ) );
					if ( tempBuffer == NULL ) {
						printf( "\nErro ao alocar memória! 2.2\n" );
						free( pBuffer );
						return 1;
					}

					pBuffer = tempBuffer;
					tempBuffer = NULL;
					UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );

					system( "clear" );
					printf( "\nRegistro removido com sucesso!\n" );
				} else {
					system( "clear" );
					printf( "\nAgenda Vazia!\n" );
				}
				break;
			}
			// Buscar um registro através do campo "name"
			case 3: {
				if ( *(int *)counterPeoples != 0 ) {
					system( "clear" );
					printf( "\n-------------- Buscar Pessoa --------------\n" );

					currentPerson = NULL;

					if ( GetPerson( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &currentPerson, &name, &email, &age ) ) {
						free( pBuffer );
						return 1;
					}

					if ( currentPerson != NULL ) {
						system( "clear" );
						printf( "\n----------- Registro Encontrado -----------\n" );
						printf( "Nome: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "E-Mail: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "Idade: %d\n", *(int *)currentPerson );
						printf( "-------------------------------------------\n" );
					} else {
						system( "clear" );
						printf( "\nRegistro Não Encontrado!\n" );
					}
				} else {
					system( "clear" );
					printf( "\nAgenda Vazia!\n" );
				}
				break;
			}
			// Listar todos os registros do buffer
			case 4: {
				if ( *(int *)counterPeoples != 0 ) {
					tempBuffer = realloc( pBuffer, *(size_t *)bufferSize + sizeof( int ) );
					if ( tempBuffer == NULL ) {
						printf( "\nErro ao alocar memória! 4.1\n" );
						free( pBuffer );
						return 1;
					}

					pBuffer = tempBuffer;
					tempBuffer = NULL;
					UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );
					endBuffer = pBuffer + (*(size_t *)bufferSize) + sizeof( int );
					*(size_t *)bufferSize = (size_t)( endBuffer - pBuffer );

					currentPerson = peoplesBuffer;
					system( "clear" );
					printf( "\n--------------- Listar Agenda ---------------\n" );

					for ( int i = 0; i < *(int *)counterPeoples; i++ ) {
						printf( "Nome: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "E-Mail: %s\n", (char *)currentPerson );
						currentPerson += (strlen( (char *)currentPerson ) + 1) * sizeof( char );
						printf( "Idade: %d\n", *(int *)currentPerson );
						currentPerson += sizeof( int );
						printf( "----------------------------------------------\n" );
					}

					tempBuffer = realloc( pBuffer, *(size_t *)bufferSize - sizeof( int ) );
					if ( tempBuffer == NULL ) {
						printf( "\nErro ao alocar memória! 4.2\n" );
						free( pBuffer );
						return 1;
					}

					pBuffer = tempBuffer;
					tempBuffer = NULL;
					UpdatePointers( &pBuffer, &userOption, &counterPeoples, &bufferSize, &peoplesBuffer, &name, &email, &age );
					endBuffer = pBuffer + (*(size_t *)bufferSize) - sizeof( int );
					*(size_t *)bufferSize = (size_t)( endBuffer - pBuffer );
				} else {
					system( "clear" );
					printf( "\nAgenda Vazia!\n" );
				}
				break;
			}
			// Saída do programa
			case 5:
				printf( "\nSaindo...\n\n" );
				break;
			default:
				printf( "\nOpção Inválida!\n" );
				break;
		}
	} while ( *(int *)userOption != 5 );

	free( pBuffer );
	return 0;
}