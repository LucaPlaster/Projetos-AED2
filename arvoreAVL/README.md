# Projeto-ArvoreAVL

Disciplina
Algoritmos e Estrutura de Dados 2 - [Semestre Letivo: 2022/1]
Nome dos(as) acadêmicos(as)

1 – Iury Alexandre Alves Bo
2 – Luca Mascarenhas Plaster
3 – Maria Rafaela dos Anjos


Números de matrícula:

1 – 202103735
2 – 202014610
3 – 202108525
Turma: INF0287C
Professor(a): Wanderley de Souza Alencar


TEMA: ÁRVORE AVL 

I - INTRODUÇÃO
Se não houver um cuidado com o balanceamento, uma árvore binária pode ficar degenerada (desbalanceada), quando algumas subárvores ficam desproporcionais em relação às outras. Isso pode dificultar certas tarefas, como o aumento de tempo na busca de algum nó. Dessa forma, as árvores balanceadas procuram deixar suas subárvores o mais equilibradas possível. 

A árvore AVL (originalmente chamada de árvore admissível) foi a primeira árvore balanceada criada e sua primeira referência está em “Algoritmos para organização da informação”, de 1962, tendo como criadores os soviéticos Adel’son-Vel’skii e Landis, motivo para o nome da árvore. Seu objetivo era inserir e buscar um elemento com o custo de tempo de O(log n) e as alturas das subárvores esquerda e direita de cada nó são diferentes por no máximo um.
Dessa forma, apesar de todas as adversidades vividas durante a Guerra Fria, foi um momento de grande desenvolvimento científico e tecnológico, principalmente por parte da União Soviética, origem da AVL, e dos Estados Unidos.

II - DESCRIÇÃO
Assim como os outros tipos de árvore, as operações e funções que tangem a árvore AVL não possuem um intuito diferente das demais, mantemos as ideias das implementações de criação, inserção, remoção, impressão, busca, tamanho e destruição. O que a AVL traz de novo e que é a chave do entendimento deste tipo de árvore são as operações de rebalanceamento, que serão devidamente apresentadas no decorrer do documento. 

Vantagens
Toda árvore AVL é balanceada, sua altura é O(log n). A principal vantagem da AVL é a sua capacidade em realizar buscas pela árvore de forma muito eficiente tendo em vista que já está balanceada. Para aplicações em que precisa-se de realizar muitas buscas, a árvore AVL é a ideal.

Desvantagens
Para garantir o balanceamento da árvore, cada inserção ou remoção exige o cálculo do fator de balanceamento e o balanceamento quando necessário

Os tipos e estrutura de dados utilizados vão da preferência do leitor, iremos abordar este assunto na próxima seção. Agora, ao que se refere às funções da aplicação:
 
Operações
Criação
Segue o padrão de criação de uma Árvore Binária de Busca (ABB). É importante ter claro em mente os processos de alocação de memória. Criamos nossa árvore, reservando memória para a mesma.

Inserção
Dado a informação (nome, matrícula, valor, etc.) que deseja manipular, inserimos de acordo com a ordem de inserção que preferir.
Ao final do processo, precisamos calcular a altura da árvore, que é feito através de um processo simples, é o valor da maior altura entre os nós da esquerda e da direita + 1. 


Balanceamento da árvore
Esta operação é composta de várias funções auxiliares, tais como descobrir a altura de um nó, calcular o fator de balanceamento e as rotações dos nós que são de fato a alteração da ordem dos elementos na árvore. 

3.1   Altura de um nó
A função retorna a altura do nó em questão, essencial para o fator de balanceamento já que ele depende inteiramente disso.

3.2   Fator de balanceamento
Vejamos, nossa árvore previne os casos em que há uma degeneração, que é identificada quando há uma diferença de 2 ou mais entre a altura do nó da esquerda e da altura do nó da direita, esta diferença é o que chamamos de fator de balanceamento.



Sendo degenerada, precisamos balanceá-la, se não, segue a aplicação.

3.3   Rotações
No caso da árvore estar desbalanceada, será necessário executar rotações dos nós, no exemplo da figura 2 vemos que ela está desbalanceada à esquerda (fator de balanceamento = 2), para balanceá-la, guardaremos o 3 em uma variável auxiliar e subiremos o 2, ligando-o à esquerda do 4, e depois colocaremos o 3 à direita do 2.  



Este é um exemplo de rotação do nó à esquerda e filho à esquerda. Temos 4 casos:

Rotação de nó à esquerda com filho à esquerda, chamada de “Rotação à direita” (fator de balanceamento >= 2 e fator de balanceamento do nó desbalanceado >= 1);
Rotação de nó à direita com filho à direita, chamada de “Rotação à esquerda” (fator de balanceamento <= -2 e fator de balanceamento do nó desbalanceado <= -1);
Rotação de nó à esquerda com filho à direita, chamada de “Rotação dupla direita-esquerda” (fator de balanceamento >= 2 e fator de balanceamento do nó desbalanceado <= -1);
Rotação de nó à direita com filho à esquerda, chamada de “Rotação dupla esquerda-direita” (fator de balanceamento <= -2 e fator de balanceamento do nó desbalanceado >= 1).

Para um bom entendimento, perceba que sempre rotaciona para o lado contrário do último filho desbalanceado, ou seja, se está desbalanceado à direita, teremos que rotacionar para esquerda e vice-versa. O mesmo vale para os casos de rotações duplas, se está desbalanceado à direita-esquerda, a rotação será esquerda-direita.
Por exemplo, vamos analisar logicamente um caso para esclarecermos a ideia:

1º passo: Identifica-se um desbalanceamento na altura de um nó, -2 para direita ou 2 para esquerda.
2º passo: Verificamos a altura dos filhos do nó desbalanceado, dado que no passo anterior tivemos -2, sabemos que é o nó à direita, se for um caso de rotação dupla, teremos que o fator de balanceamento do nó desbalanceado será 1 (se fosse uma rotação simples seria -1).

3º passo: Dado que no passo anterior tivemos um fator de balanceamento = -1 para o nó desbalanceado, podemos começar nossa rotação.



		Figura 9 - Representação animada das rotações


Remoção
No processo de remoção, ainda há a preocupação com os casos padrões da ABB (remoção de nó sem filho, com um filho e com dois filhos), dado que conhecemos esses processos, a incrementação deste modelo é recalcular a altura da árvore e executar o seu balanceamento se necessário.
Da mesma forma que balanceamos a árvore ao inserir um elemento, fazer isto na remoção segue a mesma linha de entendimento. Identificamos o nó a ser removido, removemos e verificamos se há necessidade de rebalanceamento da árvore com nossa função de fator de balanceamento, já explicada no caso de inserção.




Impressão
Conhecendo os mecanismos da ABB e os novos recursos aprendidos até aqui, podemos imprimir nossa árvore balanceada! Será implementada de um jeito que possamos visualizar os ramos da árvore.

III - REPRESENTAÇÃO COMPUTACIONAL
Funções utilizadas no código:


void menu();
Objetivo Principal- 
Função que exibe o menu de opções.

ArvAVL *criarArvoreVazia_AVL(ArvAVL *arv);
Objetivo Principal- 
Função que cria árvore vazia (arv->raiz = NULL). Recebe uma árvore como
parâmetro e retorna a raiz da árvore NULL.
Passo-a-passo-
	Árvore recebe null, prevenindo possível lixo de memória, aloca memória dinamicamente para árvore, raiz da árvore recebe null, também prevenindo possível lixo de memória e retorna a árvore.
						
No *novoNo (int valor);
Objetivo Principal- 
Função que cria um novo nó. Recebe um valor inteiro como parâmetro e retorna um
novo nó.
Passo-a-passo-
Caso o novo espaço tenha sido alocado corretamente, a árvore recebe o valor a ser inserido no elemento da árvore; tem um ponteiro que aponta para o elemento à esquerda da árvore, que o faz receber null, e outro que aponta para o elemento à direita da árvore, que o faz receber null; e tem uma altura que inicializa com o valor “0”. Ao fim, há uma impressão de sucesso.
Caso o nó alocado esteja em uso, ou seja, já esteja alocado previamente, há uma impressão de erro de alocação do nó.
Retorna um novo nó.

No *inserir_AVL(No *raiz, int valor);
Objetivo Principal-
Função recursiva que insere elementos na árvore AVL. Recebe como parâmetro uma raiz do tipo nó (a árvore) e um valor.
Passo-a-passo-
Situação de segurança, verifica se existe uma raiz alocada. Caso não exista, cria um novo nó.
Faz uma verificação de valores dos elementos quanto ao último valor do elemento do nó raiz. Se o valor for menor que o valor já existente da raiz, acontece uma inserção desse valor à esquerda da árvore. Se o valor for maior que o valor já existente da raiz, acontece uma inserção desse valor à direita da árvore. Já se for igual, mostra uma impressão de que o elemento já está na árvore e retorna null.
Entra em uma função de procurar o lado maior da árvore (direito ou esquerdo) e acrescenta na variável tamanho + 1.

short maior (short a, short b);
	Objetivo Principal-
	Verifica se existe um nó de uma árvore e saber qual é o maior valor dentre dois valores. Recebe dois valores short como parâmetro e retorna o maior entre eles. 
	Passo-a-passo:
		Caso não exista nó, retorna 0.						

short alturaNo(No *no);
	Objetivo Principal-
		Função que retorna a altura de um nó. Recebe como parâmetro um nó de árvore e    retorna a altura desse nó
	Passo-a-passo-
		Abre uma condição, caso o nó seja null, retorna -1. se não existe no->dir ou no->esq, então retornamos -1 porque não há filho desse lado
	Caso outro valor diferente de -1, retorna a altura desse nó.

short fatorDeBalanceamento_AVL(No *no);
Objetivo Principal:  	
	Função que calcula o fator de balanceamento da árvore. Recebe como parâmetro um nó de uma árvore e retorna a diferença de altura da subárvore à esquerda menos a subárvore à direita.
	Passo-a-passo:
		Se não existir nó, retorna 0.

void imprimirRepresentacao_ARV(No *raiz, int nivel);
Objetivo Principal-   	
Função que imprime a representação visual da árvore. Recebe como parâmetro a raiz de um nó e uma variável inteira chamada nível.
	Passo-a-passo-
		Se existir uma raiz: Imprime a representação dessa árvore para a direita (de forma horizontal), com base no nível da árvore.
		Imprime a representação dessa árvore para a esquerda (de forma horizontal),  utilizando a ideia de um contador de tabulações chamado “nivel”.


void imprimirPrefix_ARV(No *raiz);
Objetivo Principal-   	
	Função que imprime os itens da árvore de forma pré-fixada. Recebe como parâmetro uma raiz de um nó.
	Passo-a-passo-
		Verifica se a raiz não é nula e imprime recursivamente os valores da raiz, a partir de seu prefixo.

void imprimirInfix_ARV(No *raiz);
	Objetivo Principal-   	
	Função que imprime os itens da árvore de forma meio-fixada. Recebe como parâmetro uma raiz de um nó.
	Passo-a-passo-
		Verifica se a raiz não é nula e imprime recursivamente os valores da raiz a partir de seu meio-fixo.

void imprimirPostfix_ARV(No *raiz);
	Objetivo Principal-   	
	 Função que imprime os itens da árvore de forma pós-fixada. Recebe como parâmetro uma raiz de um nó.
	Passo-a-passo-
		Verifica se a raiz não é nula e imprime recursivamente os valores da raiz a partir de seu pós-fixo.

No *balancear_AVL(No *no);
	Objetivo Principal-
Função que faz o balanceamento da árvore AVL à medida que insere os nós. Recebe como parâmetro um nó e também retorna um nó.
	Passo-a-passo-
		Verifica se o fator de balanceamento do nó é menor que 1 e realiza rotações do lado direito verificando se há necessidade de rotação dupla, se o da esquerda estiver desbalanceado. Confere se o fator de balanceamento do nó é maior ou igual a 1 e se a árvore estiver completamente desbalanceada à direita o fator de balanceamento fica menor que -1 e o fator de balanceamento do direito fica menor ou igual a 0.
		Caso contrário, o nó entra na função de rotação para a esquerda.
		Verifica se o fator de balanceamento do nó é maior que 1 e realiza rotações do lado esquerdo verificando se há necessidade de rotação dupla do lado esquerdo. Confere se o fator de balanceamento do nó é menor ou igual a 1 e se a árvore estiver completamente desbalanceada à esquerda, o fator de balanceamento fica maior que 1 e o fator de balanceamento do direito fica maior ou igual a 0.
		Caso contrário, o nó entra na função de rotação para a direita.		

No *rotacaoEsquerda_AVL(No *r);
	Objetivo Principal-   
Função que rotaciona a árvore à esquerda. Recebe como parâmetro um nó e retorna o nó rotacionado à esquerda.
	Passo-a-passo- 
Criamos nós auxiliares “up” e “up_esq” dentro da função e igualamos a NULL. O nó up é o nó que será elevado para o lugar do nó que foi passado (o nó *r), por isso ele recebe o valor de r->dir. O nó up_esq recebe os possíveis valores existentes em up->esq. 
Agora podemos iniciar as rotações, o up->esq recebe r e o r->dir recebe o up_esq. Feito isso, já rotacionamos o up e armazenamos o r à direita do up sem perder os antigos valores de up->esq.

No *rotacaoDireita_AVL(No *r);
	Objetivo Principal-   	
Função que rotaciona a árvore à direita. Recebe como parâmetro um nó e retorna o nó rotacionado à direita.
	Passo-a-passo-
Criamos nós auxiliares “up” e “up_dir” dentro da função e igualamos a NULL. O nó up é o nó que será elevado para o lugar do nó que foi passado (o nó *r), por isso ele recebe o valor de r->esq. O nó up_dir recebe os possíveis valores existentes em up->dir. 
Agora podemos iniciar as rotações, o up->dir recebe r e o r->esq recebe o up_dir Feito isso, já rotacionamos o up e armazenamos o r à esquerda do up sem perder os antigos valores de up->dir.

No *rotacaoDuplaDE_AVL(No *r);
	Objetivo Principal-
Função que rotaciona a árvore à direita e depois à esquerda. Recebe como parâmetro um nó e retorna o nó rotacionado à direita-esquerda.
	Passo-a-passo-
Sabendo implementar as funções de rotação à direita e esquerda, basta chamá-las uma seguida da outra, passando o nó a ser rotacionado.

No *rotacaoDuplaED_AVL(No *r);
	Objetivo Principal- 
Função que rotaciona a árvore à esquerda e depois à direita. Recebe como parâmetro um nó e retorna o nó rotacionado à esquerda-direita.
	Passo-a-passo-
Sabendo implementar as funções de rotação à esquerda e direita, basta chamá-las uma seguida da outra, passando o nó a ser rotacionado.

int buscar_ARV(No * raiz, int valor);
	Objetivo Principal-   
Função que retorna se o elemento está ou não na árvore. Recebe como parâmetro uma raiz de um nó e um valor, e retorna o valor da raiz.	
	Passo-a-passo-
	Se a raiz for null, retorna falso. Caso não, verifica se o valor de input é igual ao da busca, se for igual retorna o valor.
	Se o valor de input for menor, busca novamente recursivamente à esquerda da árvore. Se o valor de input for maior, busca novamente recursivamente à direita da árvore.
			
int tamanho_ARV(No *raiz);
	Objetivo Principal-
Função que retorna o tamanho da árvore (recursivo). Recebe como parâmetro a raiz de um nó e retorna o tamanho da árvore de direita + tamanho da árvore da esquerda + 1.
	Passo-a-passo-
		Caso a raiz seja null, retorna 0. Retorna o tamanho da árvore da direita + tamanho da árvore da esquerda + 1.
		
No *remover_AVL(No *raiz, int valor);
	Objetivo Principal-   
Função que remove um nó da árvore. Recebe como parâmetro a raiz de um nó e um valor e retorna a raiz com o nó removido.
	Passo-a-passo-
		Verifica se a raiz é null e printa que não encontrado caso seja null.
		Caso não seja null, verifica se o valor da raiz é igual ao valor digitado e se tanto a raiz da esquerda quanto a raiz da direita é null, ou seja, não têm filhos. Limpa a memória alocada e imprime que o elemento foi removido.
		Se a raiz da esquerda ou da direita for null, remove nós que possuem apenas um (1) filho com ajuda de uma variável auxiliar, limpa a memória alocada e imprime que o elemento foi removido.
		Quando ambas não são null, remove nós que possuem dois (2) filhos, substituindo por um nó da esquerda, este, substituído pelo nó mais à direita do nó à esquerda. Troca os conteúdos dos nós para remover um nó do final, remove o elemento da raiz da esquerda e, por fim, retorna a raiz modificada.
		Se o valor da raiz for maior que o valor digitado, retornamos raiz->esq pois se o valor digitado estiver na árvore, ele está no espectro menor e vice-versa.
		Recalcula a altura da árvore e balanceia, se necessário. Por fim, retorna a nova raiz.

void liberarNos_ARV(No *raiz);
	Objetivo Principal-   	
Liberação dos nós pós fixada para não perdermos nenhum valor. Recebe como parâmetro a raiz de um nó.
	Passo-a-passo-
		Confere se a raiz não é nula e libera os nós recursivamente da raiz à esquerda da árvore e à direita da árvore. Por fim, libera o espaço da memória alocada dinamicamente.

void liberarArvore_ARV(No *raiz);
	Objetivo Principal-   	
Função que libera os nós alocados. Recebe como parâmetro a árvore.
	Passo-a-passo-
		Libera espaço da memória alocada dinamicamente à árvore.

void clear_screen();
	Objetivo Principal-   
Função que dá "cls" ou “clear” na tela do terminal.

IV - IMPLEMENTAÇÃO
Função de criação







Funções auxiliares: maior, alturaNo, fatordeBalanceamento


Função de balancear













Funções de rotações













Função de inserção





















Função de remoção












Função de impressão



V – PROCESSO DE INSTALAÇÃO DO PROGRAMA DE COMPUTADOR
Compilador utilizado: GCC 9.4.0 (opcional).
Sistema operacional utilizado: Ubuntu 20.04.4 LTS (opcional).
Instalação da aplicação (padrão):
	Linkando a biblioteca .c com a .h
		> gcc -c AVL.c -o AVL. o
	Compilando a aplicação
		> gcc AVL.o main.c -o AVL.exe
	Executando a aplicação
		> ./AVL.exe

VI - REFERÊNCIAS
DROZDEK, Adam. Estrutura de Dados e Algoritmos em C++. 1ª edição. São Paulo: Pioneira Thomson Learning, 2005;

GASPAR, Wagner. O que é uma Árvore AVL - Árvore Binária de Busca Balanceada?. Wagner Gaspar, 2021. Disponível em: <https://wagnergaspar.com/o-que-e-uma-arvore-avl-arvore-binaria-de-
busca-balanceada/>. Acesso em: 9 de agosto de 2022;

SCHALCH, Bruno. AVL Tree Example GIF, via Wikimedia Commons, 2017. Disponível em: <https://commons.wikimedia.org/wiki/File:AVL_Tree_Example.gif>. Acesso em: 9 de agosto de 2022;

TOFFOLO, Túlio. Árvores de Pesquisa (Parte II). Prof. Túlio Toffolo- Departamento de Computação UFOP. Disponível em: <http://www3.decom.ufop.br/toffolo/site_media/uploads/2013-1/bcc202/slides/
22._arvores_(parte_2).pdf>. Acesso em: 9 de agosto de 2022; 

