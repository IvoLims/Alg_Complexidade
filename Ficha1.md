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

(d) A função `int maxPOrd (int v[], int N)` que calcula o comprimento do maior
prefixo ordenado de um array.

pré: N >= 0

pós: `(N == 0 && r == 0) || (forall_{1 <= i < r} v[i-1] < v[i] && v[r] > v[r-1])`  

(e) A função `int isSorted (int v[], int N)` que testa se um array está ordenado
por ordem crescente.

pré: N >= 0

pós: `forall_{1 <= i < N} v[i-1] < v[i]` 

# 2 Correção
## 1. Para cada um dos seguintes triplos de Hoare, apresente um contra-exemplo que mostre a sua não validade.
(a) `{T rue} r = x+y; {r ≥ x}`
R.: `x = 3, y = -1`

(b) `{True} x = x+y; y = x-y; x = x-y; {x == y}
R.: `x = 3, y = 2` 

(c)
`{True} x = x+y; y = x-y; x = x-y; {x 6= y}
R.: `x = 3, y = 3`

(d)
`{True} if (x>y) r = x-y; else r = y-x; {r > 0}
R.: `x = 3, y = 3`

(e)
`{True} while (x>0) { y=y+1; x = x-1;} {y > x}
R.: `x = 0, y = -1` 

## 2. Modifique a pré-condição de cada um dos triplos de Hoare da alínea anterior de forma a obter um triplo válido.

a) `x > 0 && y > 0`  
b) `x == y`  
c) `x != y`  
d) `x != y`  
e) `(x <= 0 && y > x) || (x > 0 && y > -x)` ou `y > -|x|`

# 3 Invariantes
## 1.Considere as seguintes implementações de uma função que calcula o produto de dois números.
```c
int mult1 (int x, int y){      |     int mult2 (int x, int y){
// pre: x>=0                   |     // pre: x>=0
int a, b, r;                   |     int a, b, r;
a=x; b=y; r=0;                 |     a=x; b=y; r=0;
while (a>0){                   |     while (a>0) {
r = r+b;                       |     if (a%2 == 1) r = r+b;
a = a-1;                       |     a=a/2; b=b*2;
}                              |     }
// pos: r == x * y             |     // pos: r == x * y
return r;                      |     return r;
}                              |     }
```
(a) Para cada um dos predicados, indique se são verdadeiros no início (Init) e preservados pelos ciclos destas duas funções

| Predicado | Init | Pres | Init | Pres |
|---|---|---|---|---|
| r == a * b | &#x274C; | &#x274C; | &#x274C; | &#x274C; |
| a >= 0 | &#10004; | &#10004; | &#10004; | &#10004; |
| b >= 0 | &#x274C; | &#x274C; | &#x274C; | &#x274C; |
| r >= 0 | &#10004; | &#x274C; | &#10004; | &#x274C; |
| a == x | &#10004; | &#x274C; | &#10004; | &#x274C; |
| b == y | &#10004; | &#10004; | &#10004; | &#x274C; |
| a * b == x * y | &#10004; | &#x274C; | &#10004; | &#x274C; |
| a * b + r == x * y | &#10004; | &#10004; | &#10004; | &#10004; |

(b) Apresente invariantes dos ciclos destas duas funções que lhe permitam provar a
sua correção (parcial).

R.: `a * b + r == x * y && a >= 0`   

