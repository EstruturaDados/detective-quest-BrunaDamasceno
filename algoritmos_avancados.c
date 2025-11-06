

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.


    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== Estrutura do nó da árvore =====
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// ===== Cria uma nova sala =====
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ===== Cria o mapa da mansão =====
Sala* montarMansao() {
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca Antiga");
    Sala *salaJantar = criarSala("Sala de Jantar");
    Sala *laboratorio = criarSala("Laboratório Secreto");
    Sala *jardim = criarSala("Jardim dos Mistérios");
    Sala *porao = criarSala("Porão Escuro");
    Sala *torre = criarSala("Torre do Relógio");

    // Conexões entre as salas (árvore binária)
    hall->esquerda = biblioteca;
    hall->direita = salaJantar;

    biblioteca->esquerda = laboratorio;
    biblioteca->direita = jardim;

    salaJantar->esquerda = porao;
    salaJantar->direita = torre;

    // Raiz da árvore
    return hall;
}

// ===== Função de exploração =====
void explorarSalas(Sala *atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está em: **%s**\n", atual->nome);

        // Verifica se é nó-folha (fim do caminho)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Você chegou ao fim desse caminho da mansão.\n");
            break;
        }

        printf("Deseja ir para (e) esquerda, (d) direita ou (s) sair? ");
        scanf(" %c", &escolha);

        if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não há passagem à esquerda!\n");
        } 
        else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não há passagem à direita!\n");
        } 
        else if (escolha == 's' || escolha == 'S') {
            printf("Você decidiu encerrar a exploração.\n");
            break;
        } 
        else {
            printf("Opção inválida.\n");
        }
    }
}

// ===== Função principal =====
int main() {
    printf("=== Detective Quest: Mapa da Mansão ===\n");
    printf("Você é um detetive investigando uma antiga mansão misteriosa...\n");

    Sala *inicio = montarMansao();
    explorarSalas(inicio);

    printf("\nFim da exploração. Até a próxima investigação!\n");
    return 0;
}
