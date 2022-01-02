# 1 Especificações

## 1. Descreva o que faz cada uma das seguintes funções.

(a) 
```c
int fa (int x, int y){
// pre: True
...
// pos: (m == x || m == y) && (m >= x && m >= y)
return m;
}
```
R.: Retorna o maior elemento.

(b) 
```c
int fb (int x, int y){
// pre: x >= 0 && y >= 0
...
// pos: x % r == 0 && y % r == 0
return r;
}
``` 
R.: Retorna o divisor comum de `x` e `y`.

(c) 
```c
int fc (int x, int y){
// pre: x > 0 && y > 0
...
// pos: r % x == 0 && r % y == 0
return r;
}
```
R.: Retorna o múltiplo comum de `x` e `y`.
 
(d) 
```c 
int fd (int a[], int N){
// pre: N>0
...
// pos: 0 <= p< N && forall_{0 <= i< N} a[p] <= a[i]
return p;
}
```
R.: Retorna um índice da lista onde está um elemento menor ou igual a todos os outros.  

(e) 
```c 
int fe (int a[], int N){
// pre: N>0
...
// pos: forall_{0 <= i< N} x <= a[i]
return x;
}
```
R.: Retorna um `x` que é menor ou igual a todos os restantes elementos da lista.

(f)
```c 
int ff (int a[], int N){
// pre: N>0
...
// pos: (forall_{0 <= i< N} x <= a[i]) &&
// (exists_{0 <= i <N} x == a[i])
return x;
}
```
R.: Retorna um `x` que pertence à lista e é menor ou igual a todos os elementos da lista.

(g) 
```c
int fg (int x, int a[], int N){
// pre: N>=0
...
// pos: (p == -1 && forall_{0 <= i < N} a[i] != x) ||
// ( (0 <= p < N ) && x == a[p])
return p;
}
```
R.: retorna -1 caso o elemento `x` não exista na lista o ou seu indice caso exista.

## 2. Escreva as pré e pós-condições para as seguintes funções.

(a) A função `int prod (int x, int y)` que calcula o produto de dois inteiros.

pré: True  
pós: `r == x*y` 

(b) A função `int mdc (int x, int y)` que calcula o maior divisor comum de dois
números inteiros positivos.

pré: True

pós: `(x % r == 0 && y % r == 0) && nexists_{r < i < inf} x % i == 0 && y % i == 0`  

(c) A função `int sum (int v[], int N)` que calcula a soma dos elementos de um
array.

pré: N >= 0  
pós: `r == sum_{0 <= i < N} v[i]` 

(d) A função int maxPOrd (int v[], int N) que calcula o comprimento do maior
prefixo ordenado de um array.

pré: N >= 0
pós: `(N == 0 && r == 0) || (forall_{1 <= i < r} v[i-1] < v[i] && v[r] > v[r-1])`  

(e) A função int isSorted (int v[], int N) que testa se um array está ordenado
por ordem crescente.

pré: N >= 0
pós: `forall_{1 <= i < N} v[i-1] < v[i]` 
