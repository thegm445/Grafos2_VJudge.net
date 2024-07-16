# Grafos2_VJudge

**Número da Lista**: 2
**Conteúdo da Disciplina**: Grafos 2

## Alunos
|Matrícula | Aluno |
| -- | -- |
| 21/1039439  |  Gabriel Campello Marques |
| 22/1008060  |  Gabriel Moura dos Santos |

## Sobre 
O projeto foi baseado em resoluções de exercícios de juiz online que aplicassem os algoritmos que foram ensinados durante o módulo de Grafos 2, Dijkstra, Prim, Kruskal e SCC.

## Screenshots

1584. Min Cost to Connect All Points
      
![image](https://github.com/user-attachments/assets/31da6245-3685-4eb7-86cc-0a86c37f18dc)

332. Reconstruct Itinerary
     
![image](https://github.com/user-attachments/assets/04a4d3cc-0b51-4fdf-a1d2-9de4f77a1115)

## Outros 
Os problemas "Cai fora Lag" e "Caminho das pontes" foram tirados de listas de exercicios de EDA2. Portanto aqui estão os contextos:


## Caminho das Pontes

### Problema

Pedrinho está em uma aventura e precisa atravessar um desfiladeiro usando pontes suspensas. As pontes são antigas e têm tábuas faltando. O desafio é ajudar Pedrinho a encontrar o caminho que exige pular o menor número de buracos possível.

### Solução

Este código implementa o algoritmo de Dijkstra para encontrar o caminho mais curto em um grafo ponderado, onde:

* **Vértices:** Representam os pilares e as bordas do desfiladeiro.
* **Arestas:** Representam as pontes entre os pilares.
* **Pesos:** Representam o número de buracos em cada ponte.

**Estruturas de Dados:**

* `AdjListNode`: Representa um nó na lista de adjacência, armazenando o vértice adjacente e o peso da aresta.
* `AdjList`: Representa a lista de adjacência de um vértice.
* `Graph`: Representa o grafo, contendo um array de listas de adjacência.
* `MinHeapNode`: Representa um nó na heap mínima, armazenando o vértice e sua distância atual da origem.
* `MinHeap`: Representa a heap mínima usada no algoritmo de Dijkstra.

**Funções:**

* `newAdjListNode`, `createGraph`, `addEdge`: Funções auxiliares para criar e manipular o grafo.
* `newMinHeapNode`, `createMinHeap`, `swapMinHeapNode`, `minHeapify`, `isEmpty`, `extractMin`, `decreaseKey`, `isInMinHeap`: Funções auxiliares para manipular a heap mínima.
* `dijkstra`: Implementa o algoritmo de Dijkstra para encontrar a menor distância da origem a todos os outros vértices.

**Entrada:**

* Número de pilares (N) e número de pontes (M).
* M linhas, cada uma contendo três inteiros: pilar de origem (S), pilar de destino (T) e número de buracos na ponte (B).

**Saída:**

* Um número inteiro representando o menor número de buracos que Pedrinho precisa pular para chegar ao outro lado do desfiladeiro.

**Complexidade:**

* A complexidade de tempo do algoritmo de Dijkstra usando uma heap binária é O((V + E) * log V), onde V é o número de vértices e E é o número de arestas.

### Exemplo de Uso

```
Exemplo de entrada:
2 5
0 1 1
0 2 3
0 3 9
1 3 2
2 3 2

Saída para o exemplo acima:
3
```

### Observações

* O código assume que os pilares são numerados de 0 a N+1, onde 0 é a borda inicial e N+1 é a borda final.

### Autor

* OBI 2009, Nível 2 fase 1


## Cai Fora LAG

### Problema

O problema "Cai Fora LAG" envolve encontrar o menor custo para enviar pacotes de dados em uma rede de fibra óptica, considerando a possibilidade de usar uma "Super Conexão" direcional de baixo custo (aresta negativa). 

Inicialmente, tentei resolver com Dijkstra, mas a presença de arestas com peso negativo (representando o baixo custo da Super Conexão) tornou o algoritmo inadequado. O algoritmo de Floyd-Warshall se mostrou a solução ideal para calcular as menores distâncias em um grafo com arestas de peso negativo, desde que não haja ciclos negativos.

### Solução

Este código utiliza o algoritmo de Floyd-Warshall para calcular o menor custo de envio de pacotes em uma rede de fibra óptica. 

**Estruturas de Dados:**

* `graph[MAXN][MAXN]`: Matriz de adjacência que armazena o custo das conexões bidirecionais entre os switches.
* `graph_with_super[MAXN][MAXN]`: Matriz de adjacência que armazena o custo das conexões, incluindo as conexões "Super Conexão" direcionais.
* `dist[MAXN][MAXN]`: Matriz que armazena as menores distâncias entre os switches, calculadas pelo algoritmo de Floyd-Warshall sem considerar a "Super Conexão".
* `dist_with_super[MAXN][MAXN]`: Matriz que armazena as menores distâncias entre os switches, calculadas pelo algoritmo de Floyd-Warshall considerando a "Super Conexão".

**Funções:**

* `min(a, b)`: Retorna o menor valor entre `a` e `b`.
* `add_edge(graph[MAXN][MAXN], from, to, cost)`: Adiciona uma aresta (conexão) ao grafo representado pela matriz `graph`.
* `floyd_warshall(graph[MAXN][MAXN], dist[MAXN][MAXN])`: Implementa o algoritmo de Floyd-Warshall para calcular as menores distâncias entre todos os pares de vértices no grafo representado pela matriz `graph`, armazenando os resultados na matriz `dist`.
* `detect_negative_cycles(dist[MAXN][MAXN])`: Detecta a presença de ciclos negativos no grafo. Se um ciclo negativo for encontrado, define a distância entre os vértices afetados como infinito (`INF`).

**Entrada:**

* Um inteiro `V` representando o número de switches na rede.
* Várias linhas, cada uma contendo quatro inteiros: 
    * `v`: Switch de origem da conexão.
    * `w`: Switch de destino da conexão.
    * `c`: Custo da conexão.
    * `t`: Tipo de conexão (0 para bidirecional, 1 para "Super Conexão" direcional).
* A entrada de conexões termina com uma linha contendo `0 0 0 0`.
* Em seguida, várias linhas, cada uma contendo dois inteiros:
    * `o`: Switch de origem do pacote.
    * `x`: Switch de destino do pacote.
* A entrada termina com `EOF`.

**Saída:**

* Para cada consulta de rota, imprime uma única linha contendo:
    * O custo mínimo para enviar um pacote de `o` para `x` sem usar a "Super Conexão".
    * O custo mínimo para enviar um pacote de `o` para `x` usando a "Super Conexão".
* Se não houver um caminho possível, imprime "Impossibru".

### Observações

* O código assume que os switches são numerados de 0 a V-1.
* A constante `INF` representa um valor infinito (1000000000), usado para inicializar as distâncias e indicar a ausência de um caminho.

### Autor

* Bruno Ribas


