/*
* AP Estrutura de Dados - Exercicio 1 - Player de Musicas
* Autor: Guilherme Quadros da Silva (RU = 3282910)
* Implementacao utilizando Lista Encadeada Simples
*/

#include<stdio.h>							   
#include<stdlib.h>

void draw_menu();
int read_int_input();
void clear_keyboard_buffer();
void insert_new_song();
void list_all_songs();

struct SongNode
{
	char song_name[50] = "";
	char author[50] = "";
	int duration = 0;
	SongNode* next = NULL;
} *Head; // declara o tipo da struct com os dados de cada musica e o ponteiro para head (primeira musica)

int main()
{
	int option = -1;

	do
	{
		// desenha o menu
		draw_menu();

		// le a opcao que o usuario selecionou
		option = read_int_input();

		// limpa a tela apos o usuario selecionar a opcao para destacar a saida
		system("cls");

		// decide a acao com base na opcao selecionada
		switch (option)
		{
			// insere uma nova musica
		case 1:
			insert_new_song();
			printf("\nMusica inserida com sucesso! Pressione qualquer tecla para voltar ao menu principal.\n\n");
			system("pause");
			break;

			// lista todas as musicas da playlist
		case 2:
			list_all_songs();
			printf("\nPressione qualquer tecla para voltar ao menu principal.\n\n");
			system("pause");
			break;

			// sai do programa
		case 3:
			printf("O programa sera encerrado e os dados serao limpos!\n\n");
			break;

			// usuario digitou uma opacao invalida
		default:
			printf("OPCAO INVALIDA! Pressione uma tecla para reiniciar o menu.\n\n");
			system("pause");
			break;
		}
	} while (option != 3); // o menu e desenhado ate o usuario decidir fechar informando a opcao '3'

	printf("\n");

	// pausa, esperando o usuario pressionar alguma tecla para encerrar o programa 
	system("pause");

	return 0;
}

void draw_menu()
{
	// limpa a tela
	system("cls");

	// opcoes do menu
	printf("MENU:\n");
	printf("1 - Inserir nova musica no fim da playlist.\n");
	printf("2 - Lista todas as musicas da playlist.\n");
	printf("3 - Fechar o programa\n");
	printf("\n");
	printf("Selecione uma opcao: ");
}

int read_int_input()
{
	int value;

	// le a opcao como um numero inteiro
	scanf_s("%d", &value);

	// limpa o buffer do teclado para evitar problemas na leitura do input
	clear_keyboard_buffer();

	return value;
}

void clear_keyboard_buffer()
{
	char c;

	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

void insert_new_song()
{
	// aloca espaco para nova musica na memoria
	SongNode* new_song = (SongNode*)malloc(sizeof(SongNode));

	// nome
	printf("Informe o nome da musica: ");
	fgets(new_song->song_name, sizeof(new_song->song_name), stdin);

	// autor
	printf("Informe o nome do artista/banda: ");
	fgets(new_song->author, sizeof(new_song->author), stdin);

	// duracao
	printf("Informe a duracao da faixa (em minutos): ");
	scanf_s("%d", &new_song->duration);

	// novo item da lista vai sempre para o fim, logo o proximo elemento depois dele vai ser sempre NULL
	// setar NULL aqui evita setar dentro do if da lista vazia e no final dessa rotina
	new_song->next = NULL;

	// ponteiro para encontrar final da lista
	SongNode* item = Head;

	// lista vazia
	if (item == NULL)
	{
		Head = new_song;
		return;
	}

	// procura pelo último item da lista
	while (item->next != NULL)
	{
		item = item->next;
	}

	// aponta o atual ultimo item da lista para o item novo (que sera o ultimo)
	item->next = new_song;
}

void list_all_songs()
{
	// lista vazia
	if (Head == NULL)
	{
		printf("Lista de reproducao vazia! Nao ha musica cadastrada. Por favor, retorne ao menu principal para cadastrar uma musica.\n");
		return;
	}

	// seta o ponteiro para a primeira musica 
	SongNode* item = Head;

	// numero da musica (indice + 1)
	int song_number = 0;

	// percorre todas as musicas da lista
	while (item != NULL)
	{
		// imprime dados da musica com um contador representando o numero do cadastro da musica (indice + 1)
		// ++song_number vai incrementar antes de escrever na tela (diferente de song_number++)
		printf("#%d\n", ++song_number);
		printf("Nome: %s", item->song_name);
		printf("Artista/banda: %s", item->author);
		printf("Duracao (em minutos): %d\n\n", item->duration);

		// seta o ponteiro para a proxima musica
		item = item->next;
	} 
}
