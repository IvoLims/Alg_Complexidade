/* 1. Min-heaps

Uma min-heap é uma árvore binária em que cada nodo é menor ou igual a todos os seus sucessores.
Por outro lado, uma árvore diz-se semi-completa se todos os níveis da árvore estão completos, com a possível excepção 
do último, que pode estar parcialmente preenchido (da esquerda para a direita).
As árvores semi-completas têm uma representação ”económica” em array: os nodos são armazenados por nível, sempre da esquerda 
para a direita.

Por exemplo, a árvore (que é uma min-heap)

                   10    
              /           \       
            15             11
           /   \         /   \
         16     22     35     20
         /\     /\     /\     /\
       21  23 34  37 80  43 22  25
       /\
     24  28

pode ser armazenada no array (de tamanho 17)

0 : 10 | 1 : 15 | 2 : 11 | 3 : 16 | 4 : 22 | 5 : 35 | 6 : 20 | 7 : 21 | 8 : 23 | 

9 : 34 | 10 : 37 | 11 : 80 | 12 : 43 | 13 : 22 | 14 : 25 | 15 : 24 | 16 : 28 |

Nota: posArray : folha

O índice onde se encontra a sub-árvore esquerda do nodo da posição i. */

// Todas as sub-árvores esquerdas encontram-se em posições ímpares logo fica 2 x i + 1.  

// (b) O índice onde se encontra a sub-árvore direita do nodo da posição i.

//// Todas as sub-árvores direitas encontram-se em posições pares logo fica 2 x i + 2.

// (c) O índice onde se encontra o pai do nodo da posição i.

// Os pais de todo o nodo encontram-se nas posições dadas por (i-1) / 2

/* (d) O índice onde se encontra a primeira folha, i.e., o primeiro nodo que não tem
sucessores. */

// Temos de ir ao pai do nodo e descer até à sua folha, ou seja pai(i) + (i + 1) e pai(i) + (i + 2) 

/* 2. Defina a função void bubbleUp (int i, int h[]) que (por sucessivas trocas com o
pai) puxa o elemento que está na posição i da min-heap h até que satisfaça a propriedade das min-heaps.
Identifique o pior caso desta função e calcule o número de comparações/trocas efectuadas nesse caso. */

void swap(int* ar, int i, int j){
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

void bubbleUp (int i, int h[]){
    while(i > 0 && h[i] > h[(i-1)/2])
        swap(h,i,(i-1)/2), i = (i-1)/2;
}

// Pior Caso: O i é o maior valor e temos de comparar todos os pais dos nodos, tendo complexidade T(N) = Nodos.

/* 3. Defina a função void bubbleDown (int i, int h[], int N) que (por sucessivas trocas com um dos filhos) empura o elemento
que está na posição i da min-heap h até que satisfaça a propriedade das min-heaps. Identifique o pior caso desta função e 
calcule o número de comparações/trocas efectuadas nesse caso. */

void bubbleDown1 (int i, int h[], int N){
    int p,control = 1;
    while( (2*i+2) < N && control){
        
        if(h[2*i+1] > h[2*i+2]) p = h[2*i+1];
        else p = h[2*i+2]

        if(h[i] > h[p]) swap(h,i,p),i=p;
        else control = 0;
    }
    if( (2*i+1) < N && h[2*i+1] < h[i] ) swap(h,i,2*i+1);
}

//Or

#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

void bubbleDown2 (int i, int h[], int N) {
  int p;
  while(LEFT(i) < N) {
    p = (RIGHT(i) < N && h[RIGHT(i)] < h[LEFT(i)]) ? RIGHT(i) : LEFT(i);
    
    if (h[p] > h[i]) break;
    
    swap(h, i, p);
    i = p;
  }
}

// Pior Caso: O i implica que todos os filhos da heap sejam reorganizados, tendo complexidade T(N) = N + 1 = N.

/* 4. Considere agora o problema de implementar uma fila com prioridades, i.e., uma fila em que o próximo elemento a retirar 
da fila é o menor que lá estiver. Uma possível implementação desta estrutura de dados consiste em usar uma min-heap. */

#define Max 100

typedef struct pQueue {
int valores [Max];
int tamanho;
} PriorityQueue;

/* Apresente as definições das operações habituais sobre este género de tipos (buffers).

   void empty (PriorityQueue *q) que inicializa q com a fila vazia. */

void empty (PriorityQueue *q){
    q->tamanho = 0;
}

// int isEmpty (PriorityQueue *q) que testa se está vazia.

int isEmpty (PriorityQueue *q){
    if( q->tamanho == 0 ) return 1;
    return 0;
}

/* int add (int x, PriorityQueue *q) que adiciona um elemento à fila (retornando 0 se a operação for possível). */

int add (int x, PriorityQueue *q){
    if (q->tamanho == Max) return 1;
    q->valores[q->tamanho] = x;
    bubbleUp(q->tamanho, q->valores)
    q->tamanho++;
    return 0; 
}

/* int remove (PriorityQueue *q, int *rem) que remove o próximo elemento
(devolvendo-o em *rem) e retornando 0 se a operação for possível. */

int remove (PriorityQueue *q, int *rem){
    if( q->tamanho == 0 ) return 1;
    rem = q->valores[0];
    q->valores[0] = q->valores[q->tamanho-1];
    q->tamanho--;
    bubbleDown2(0,q->valores,q->tamanho)
    return 0;
}

// Para testes:

PriorityQueue init(){
    PriorityQueue q = (PriorityQueue) malloc(sizeof(struct(PriorityQueue)));
    q->tamanho = 0;
    return q;
}

void printMinHeap (PriorityQueue *q){
    for(int i = 0; i < q->tamanho; i++) print("Val[%d] = %d\n",i, q->valores[i]);
    print("\n");
}


int main(){
	PriorityQueue q = init();
	printMinHeap(q);
	add(20,q);
	add(23,q);
	add(2,q);
	add(12,q);
	add(32,q);
	printMinHeap(q);
	int a = 2;
	remover(q,&a);
	printMinHeap(q);
	return 0;
}

/* 5. A operação void heapify (int v[], int N) consiste em obter uma permutação do
array que seja uma min-heap.

Duas estratégias para implementar esta função são:

top-down: Assumindo que as primeiras p posições do array constituem uma min-heap (de tamanho p) efectuar a invocação 
bubbleUp (p, v, N) de forma a obtermos uma min-heap de tamanho p+1.

bottom-up: Para cada nodo da árvore, desde o mais profundo até à raiz, aplicar a função bubbleDown. Note-se que a invocação 
para as folhas é desnecessária, uma vez que não têm sucessores.

Implemente a função heapify usando estas duas estratégias. Para cada uma delas, identifique a complexidade dessa função no 
caso em que o array original está ordenado por ordem decrescente. */

void heapifyUp(int v[], int N){

}

void heapifyDown(int v[], int N){

}

/* 6. Defina uma função void ordenaHeap (int h[], int N) que, usando a função bubbleDown definida acima, transforma a min-heap h, 
num array ordenado por ordem decrescente. */

void ordenaHeap (int h[], int N){

}

/* 7. Considere o problema de ler uma sequência de N números e seleccionar os k maiores, com k < N, (tipicamente, k muito menor 
do que N). Uma solução possível consiste em começar por ler os k primeiros elementos e organizálos numa min-heap. Para cada um 
dos N−k seguintes, caso seja maior do que o menor dos números organizados, insere-se esse elemento na min-heap, removendo o menos 
dos que lá estão.
Analise o custo desta solução (no pior caso) comparando-o com outra solução alternativa de, por exemplo, armazenar os k maiores 
números lidos numa lista ligada ordenada por ordem crescente. */

/* 2 Tabelas de Hash

Nos exercícios seguintes pretende-se usar uma tabela de Hash para implementar multi-conjuntos de strings. Para cada string deve 
ser guardado o número de vezes que ela ocorre no multiconjunto. As operações em causa são por isso:

• inicialização de um multi-conjunto a vazio
• adição de um elemento a um multi-conjunto
• teste de pertença (saber qual a multplicidade de um elemento num multi-conjunto)
• remoção de uma ocorrência de um elemento de um multi-conjunto

Vamos por isso assumir a existência de uma funçãoo unsigned hash (char *chave), como
por exemplo a seguinte (http://www.cse.yorku.ca/~oz/hash.html) */

unsigned hash(char *str){
unsigned hash = 5381;
int c;
while (c = *str++)
hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
return hash;
}

/* 2.1 Chaining
Vamos usar o seguinte tipo. */

#define Size ...
typedef struct nodo {
char *chave; int ocorr;
struct nodo *prox;
} Nodo, *THash [Size];

/* Defina as funções
1. void initEmpty (THash t) que inicializa um multi-conjunto a vazio */

void initEmpty (THash t){

}

/*2. void add (char *s, THash t) que regista mais uma ocorrência de um elemento a um
multi-conjunto */

void add (char *s, THash t){

}

/*3. int lookup (char *s, THash t) que calcula a multiplicidade de um elemento num
multi-conjunto */

int lookup (char *s, THash t){

}

/*4. int remove (char *s, THash t) que remove uma ocorrência de um elemento de um
multi-conjunto. */

int remove (char *s, THash t){

}

/*2.2 Open Addressing
Vamos usar o seguinte tipo. */

#define Size ...
#define Free 0
#define Used 1
#define Del 2
typedef struct bucket {
int status; // Free | Used | Del
char *chave; int ocorr;
} THash [Size]; 

/* 1. Comece por definir a função int where (char *s, THash t) que calcula o índice de
t onde s está (ou devia estar) armazenada. */

int where (char *s, THash t){

}

/* 2. Defina as funções usuais sobre multi-conjuntos:

(a) void initEmpty (THash t) que inicializa um multi-conjunto a vazio */

void initEmpty (THash t){

}

/* (b) void add (char *s, THash t) que regista mais uma ocorrência de um elemento
a um multi-conjunto */

void add (char *s, THash t){

}

/* (c) int lookup (char *s, THash t) que calcula a multiplicidade de um elemento
num multi-conjunto */

int lookup (char *s, THash t){

}

/* (d) int remove (char *s, THash t) que remove uma ocorrência de um elemento de
um multi-conjunto. */

int remove (char *s, THash t){

}

/* 3. Defina a função int garb_collection (THash t) que reconstrói a tabela t de forma
a não haver chaves apagadas (status==Del). */

int garb_collection (THash t){

}

/* 4. Uma forma de diagnosticar a qualidade da tabela de hash consiste em acrescentar,em cada célula (bucket), a informação do 
número de colisões que a inserção dessa chave teve que resolver.
Modifique a definição da função de inserção apresentada acima de forma a armazenar também essa informação. */

typedef struct bucket {
int probC;
int status; // Free | Used | Del
char *chave; int ocorr;
} THash [Size];
