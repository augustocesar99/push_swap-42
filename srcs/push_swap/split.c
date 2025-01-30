/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:20:43 by acesar-m          #+#    #+#             */
/*   Updated: 2025/01/30 10:52:39 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c) //Define uma função que retorna a contagem de substrings em uma string separada por um delimitador
{
	int		count; //Para armazenar a contagem de substrings
	t_bool	inside_word; //Uma flag para indicar se estamos dentro de uma substring ou de um delimitador

	count = 0;
	while (*s) //Loop até que o final da string seja alcançado
	{
		inside_word = FALSE; //Define o bool como falso para iniciar o loop
		while (*s == c) //Enquanto o caractere atual for o delimitador
			++s; //Avança para o próximo caractere
		while (*s != c && *s) //Enquanto o caractere atual não for um delimitador e o final da string não for alcançado, 
		{
			if (!inside_word) //Se não estivermos dentro da substring
			{
				++count; //Incrementa a contagem ao começar a entrar em uma substring
				inside_word = TRUE; //Define o bool como verdadeiro, indicando que encontramos uma substring
			}
			++s; //Avança para o próximo caractere da string
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c) //Define uma função que retorna a nova substring encontrada dentro de uma string
{
	static int	cursor = 0; //Para controlar a posição dentro da string `s` em múltiplas chamadas da função, necessário para continuar processando a string de onde paramos nas chamadas anteriores, essencial para tokenizar uma string
	char		*next_word; //Para armazenar um ponteiro para a nova substring
	int			len; //Para armazenar o comprimento da substring que está sendo extraída
	int			i; //Usado para indexar caracteres na nova substring

	len = 0;
	i = 0;
	while (s[cursor] == c) //Pula quaisquer caracteres consecutivos de delimitador na posição atual da string
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len]) //Calcula o comprimento da substring contando os caracteres até encontrar um delimitador ou o final da string
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1); //Aloca memória para a nova substring com base em seu comprimento mais um byte para o terminador nulo
	if (!next_word) //Verifica se houve falha na alocação de memória
		return (NULL);
	while ((s[cursor] != c) && s[cursor]) //Loop até que um delimitador seja encontrado ou o final da string seja alcançado
		next_word[i++] = s[cursor++]; //Copia cada caractere da string para a nova substring e incrementa `i` e `cursor` após cada caractere
	next_word[i] = '\0'; //Finaliza corretamente a nova substring com o terminador nulo
	return (next_word);
}

char **split(char *s, char c) //Define uma função que retorna as substrings em uma string separadas por um delimitador
{
	int		words_count; //Usado para controlar o número de substrings na string
	char	**result_array; //Para armazenar um ponteiro para ponteiros, o array de todas as substrings
	int		i; //Usado para iterar pelo array

	i = 0;
	words_count = count_words(s, c);
	if (!words_count) //Verifica se há `0` palavras
		exit(1);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); //Aloca memória para o result_array com base no número de palavras (words_count) mais duas posições adicionais para o terminador nulo no final da última string, e para terminar o array com nulo
	if (!result_array) //Verifica se houve falha na alocação de memória
		return (NULL);
	while (words_count-- >= 0) //Itera pelas palavras a serem divididas até que todas as palavras tenham sido processadas
	{
		if (i == 0) //Verifica se o primeiro caractere da string de entrada é o delimitador
		{
			result_array[i] = malloc(sizeof(char)); //Aloca memória para uma string vazia (um único terminador nulo)
			if (!result_array[i]) ////Verifica se houve falha na alocação de memória
				return (NULL);
			result_array[i++][0] = '\0'; //Inclui no array de resultados como elementos distintos
			continue ;
		}
		result_array[i++] = get_next_word(s, c); //Se o primeiro caractere da string não for um delimitador, extrai a substring e copia para o array de resultados
	}
	result_array[i] = NULL; //Finaliza corretamente o array com o terminador nulo
	return (result_array);
}
