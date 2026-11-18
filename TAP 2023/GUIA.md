# TAP 2023 — Torneo Argentino de Programación (Gym 104603)

Contest: <https://codeforces.com/gym/104603> · Enunciados oficiales en español: [enunciados/TAP_2023_es.pdf](enunciados/TAP_2023_es.pdf)

Cada problema tiene su archivo `<Letra> - <Nombre>.cpp` con la plantilla vacía, listo para resolver.

Cada sección tiene la misma estructura:
- **Resumen**: qué piden, en pocas palabras.
- **Observaciones**: las ideas que llevan a la solución, en el orden en que conviene descubrirlas.
- **Algoritmo**: los pasos concretos (pseudocódigo, sin código C++).
- **Por qué funciona**: el argumento de correctitud.
- **Traza del ejemplo**: el algoritmo corrido a mano sobre un ejemplo del enunciado.
- **Complejidad y trampas**.

Si quieres pensar el problema solo, lee primero las observaciones de una en una y para cuando tengas una idea.

## Orden sugerido (de más fácil a más difícil)

| # | Problema | Tema | Complejidad |
|---|----------|------|-------------|
| L | Game series | implementación | O(1) |
| F | Cold day at the beach | implementación, distancias | O(N) |
| B | Black and white | greedy por filas | O(N²) |
| D | Assigning problems | greedy / condición de Hall en prefijos | O(K) |
| C | Chromatic | ordenamiento + exchange argument | O(N log N) |
| A | Alfajores | observación del módulo + mínimos de prefijo | O(N log A log M) |
| M | Multiple Downloads | simulación por eventos | O(N²) |
| N | Lucky Number | greedy sobre restos mod 5 | O(N) |
| E | Finding progressions | fuerza bruta acotada (suma armónica) | O((R−L) log(R−L)) |
| H | Robotic Skills | DP en orden de valores | O(N²) |
| J | Jester in danger | BFS, DAG de caminos mínimos, procesar al revés | O(N + M) |
| K | Kitties | conteo 2D dinámico (BIT 2D offline) | O((N+Q) log²) |
| G | Great Heights | MST + rotación 45° + sweep | O(N log N) |
| I | Regional Integration | geometría + Dijkstra denso | O((Q+C)(T+C)) |

---

## L — Game series

**Resumen.** Dos equipos juegan dos partidos. Gana la serie quien hizo más goles en total; si empatan en total, hay desempate.

**Algoritmo.**
1. `a = A1 + A2`, `p = P1 + P2`.
2. Si `a > p` imprime `A`; si `a < p` imprime `P`; si no, `D`.

**Traza.** Ejemplo 3: `2 4` y `2 0` → `a = 4`, `p = 4` → `D`.

**Trampas.** No hay regla de gol de visitante ni nada parecido: solo cuenta el total.

---

## F — Cold day at the beach

**Resumen.** Hay un tejín en `(Tx, Ty)`, y cada equipo tira N tejos. Gana el equipo que tiene el tejo más cercano. El ganador suma un punto por cada tejo suyo que esté **más cerca que el mejor tejo del rival**.

**Observaciones.**
1. Para comparar distancias euclídeas no hace falta la raíz: `d₁ < d₂ ⇔ d₁² < d₂²`. Con distancias al cuadrado todo es entero y no hay problemas de precisión.
2. Lo único que necesitas del perdedor es su distancia mínima.

**Algoritmo.**
1. Para cada tejo calcula `(x−Tx)² + (y−Ty)²`.
2. `ma` = mínimo del equipo A, `mr` = mínimo del equipo R.
3. Si `ma < mr`, gana A y sus puntos son `#{tejos de A con distancia < mr}`. Si no, simétrico para R.

**Traza (ejemplo 1).** Tejín `(1,2)`. A: `(1,3)` → 1, `(4,2)` → 9. R: `(3,2)` → 4, `(5,5)` → 16+9 = 25.
`ma = 1 < mr = 4` → gana A. Tejos de A con distancia `< 4`: solo el de distancia 1 → `A 1`.

**Complejidad.** O(N). **Trampas:** ninguna. El enunciado garantiza que no hay dos tejos a la misma distancia, así que no hay empates.

---

## B — Black and white

**Resumen.** En un tablero N×N con casillas negras (`N`) y blancas (`B`), poner la mayor cantidad de dominós **horizontales** 1×2, cada uno sobre dos casillas negras y sin solaparse.

**Observaciones.**
1. Un dominó horizontal ocupa dos casillas de la **misma fila**, así que las filas no interactúan: la respuesta es la suma de lo que cabe en cada fila.
2. Dentro de una fila, una casilla blanca corta todo: un dominó no puede cruzarla. La fila se parte en **bloques de casillas negras consecutivas**, también independientes entre sí.
3. En un bloque de largo `L` caben exactamente `⌊L/2⌋` dominós.

**Por qué funciona.** Cota superior: cada dominó usa 2 casillas del bloque, así que no caben más de `⌊L/2⌋`. Alcanzable: poner dominós desde la izquierda, en las casillas (1,2), (3,4), …

**Algoritmo.** Recorre cada fila con un contador `run` de negras consecutivas. Al ver una blanca, suma `run/2` y resetea `run = 0`. Al terminar la fila, suma el último `run/2`.

**Traza.**
```
BNBNB → bloques 1,1     → 0
BBNNN → bloque 3        → 1
NNNNN → bloque 5        → 2
BNNNN → bloque 4        → 2
NNBNN → bloques 2,2     → 2
                     total 7 ✓
```

---

## D — Assigning problems

**Resumen.** Cada concurso necesita `C_i` problemas de nivel `i` (i = 1..K). Un problema de dificultad `d` puede usarse en cualquier nivel `≥ d`. Hay `P_d` problemas de dificultad `d`, y cada problema se usa una sola vez. ¿Cuántos concursos se pueden armar como máximo?

**Observaciones.**
1. Fija una cantidad `X` de concursos. Ahora hay que llenar `X·C_i` lugares del nivel `i` para cada `i`, y lo único que importa es cuántos lugares hay por nivel.
2. Mira los niveles `1..i`: necesitan `X·(C_1+…+C_i)` problemas, y **todos** tienen que tener dificultad `≤ i`. Solo hay `P_1+…+P_i` problemas así. Entonces una condición necesaria es:
   `X · prefC_i ≤ prefP_i` para todo `i`.
3. Esa condición también es suficiente (ver abajo). Por eso ni siquiera hace falta búsqueda binaria: el mayor `X` que la cumple es
   **`respuesta = min_i ⌊prefP_i / prefC_i⌋`**.

**Por qué es suficiente (greedy).** Recorre los niveles de 1 a K con un "pozo" de problemas disponibles. Al llegar al nivel `i` mete los `P_i` problemas nuevos y saca `X·C_i`. Cualquier problema del pozo sirve igual para todos los niveles futuros, así que no importa cuáles saques. Al llegar al nivel `i`, el pozo tiene `prefP_i − X·prefC_{i−1}` problemas, que es `≥ X·C_i` justamente por la condición en `i`.

**Traza (ejemplo 2).** `C = 2 3 2 2 2`, `P = 10 0 9 3 1`.
```
i      : 1   2   3   4   5
prefC  : 2   5   7   9   11
prefP  : 10  10  19  22  23
cociente: 5   2   2   2   2    → mínimo = 2 ✓
```

**Complejidad.** O(K). **Trampas:** las sumas llegan a 10⁵·10⁹ = 10¹⁴, así que hay que usar `long long`. Si haces búsqueda binaria sobre `X`, el producto `X·prefC` puede desbordar incluso en `long long`; la fórmula directa evita ese problema.

---

## C — Chromatic

**Resumen.** Hay N latas rojas (`A`) y N azules (`B`). Cada persona recibe una de cada color. Hay que minimizar (lo que recibe el que más recibe) − (lo que recibe el que menos recibe).

**Observaciones.**
1. Intuición: para que las sumas queden parejas, al rojo más grande le toca el azul más chico.
2. Concretamente: ordena `A` creciente y `B` decreciente, y empareja `A[i]` con `B[i]`.

**Por qué funciona (exchange argument).** Toma dos parejas con `a₁ ≤ a₂` y `b₁ ≤ b₂` emparejadas "en el mismo orden": `(a₁,b₁)` y `(a₂,b₂)`. Intercambiarlas a `(a₁,b₂)` y `(a₂,b₁)`:
- el **máximo** no sube: las dos nuevas sumas son `≤ a₂ + b₂`, que era la mayor;
- el **mínimo** no baja: las dos nuevas sumas son `≥ a₁ + b₁`, que era la menor.

Así que la diferencia nunca empeora. Partiendo de cualquier solución óptima y aplicando intercambios hasta que no queden parejas "en el mismo orden", llegas al emparejamiento A creciente / B decreciente sin empeorar. Por lo tanto ese emparejamiento es óptimo.

**Algoritmo.** Ordenar, emparejar, y calcular `max(A[i]+B[i]) − min(A[i]+B[i])`.

**Traza (ejemplo 2).** `A` ordenado `[1, 10⁹, 10⁹]`, `B` decreciente `[10⁹, 10⁹, 1]` → sumas `10⁹+1, 2·10⁹, 10⁹+1` → `999999999` ✓.

**Complejidad.** O(N log N). **Trampas:** las sumas llegan a 2·10⁹, que no entra en `int`.

---

## A — Alfajores

**Resumen.** Para cada `A_i` hay que calcular `A_i mod E_1 mod E_2 … mod E_M` (en ese orden).

**Observaciones.**
1. Simular directamente cuesta O(N·M) = 10¹⁰: demasiado.
2. **`x mod e` solo cambia `x` si `e ≤ x`, y cuando lo cambia lo reduce al menos a la mitad.**
   - Si `e ≤ x/2`: `x mod e < e ≤ x/2`.
   - Si `x/2 < e ≤ x`: `x mod e = x − e < x/2`.

   Entonces cada `A_i` cambia a lo sumo ~30 veces (log₂ 10⁹). El costo está en *encontrar* rápido la próxima oficina que lo cambia.
3. **Solo importan las oficinas que son mínimo estricto de prefijo.** Después de pasar por la oficina `j`, siempre queda `x < E_j`: si no la cambió, era porque `x < E_j`; si la cambió, `x mod E_j < E_j`. Además `x` nunca sube. Entonces una oficina posterior `k` con `E_k ≥ E_j` no puede cambiar nada. Las oficinas útiles son las que tienen `E` **menor que todas las anteriores**.
4. Esas oficinas forman una lista **estrictamente decreciente**. "La próxima oficina con `E ≤ x`" es el primer elemento `≤ x` de esa lista a partir de la posición actual, y en una lista decreciente eso se encuentra con **búsqueda binaria**.

**Algoritmo.**
```
pm = []                        // mínimos estrictos de prefijo
para cada E_j: si pm vacío o E_j < pm.back(): pm.push(E_j)
para cada A_i:
    x = A_i, pos = 0
    repetir:
        k = primer índice >= pos con pm[k] <= x     (búsqueda binaria)
        si no existe: cortar
        x = x mod pm[k];  pos = k + 1
    imprimir x
```

**Traza (ejemplo 1).** `E = 90 42 5` → `pm = [90, 42, 5]`.
- `140`: primer `≤ 140` es 90 → `50`; desde ahí, primer `≤ 50` es 42 → `8`; primer `≤ 8` es 5 → `3`. ✓
- `79`: 90 no; 42 → `37`; 5 → `2`. ✓
- `5`: 5 → `0`. ✓

**Complejidad.** O(M + N · log A · log M).

**Alternativa.** Sin la observación 3, puedes usar un segment tree o sparse table de mínimos y "bajar" para encontrar el primer `E_j ≤ x` a partir de una posición. La complejidad es la misma, con más código.

---

## M — Multiple Downloads

**Resumen.** Se descargan N archivos a la vez. Si hay de los dos tipos, los prioritarios se reparten en partes iguales el 75 % de `T` y los no prioritarios el 25 %. Si solo hay de un tipo, se reparten el 100 %. ¿Cuánto tarda todo?

**Observaciones.**
1. Las velocidades solo cambian cuando **termina un archivo**. Entre dos de esos eventos todo es lineal.
2. Por lo tanto se puede simular "por eventos": en cada fase calculas cuándo termina el próximo archivo y saltas directo ahí. Hay como mucho N fases.

**Algoritmo.**
```
t = 0
mientras queden archivos:
    cp, cn = cantidad de prioritarios / no prioritarios restantes
    si cp > 0 y cn > 0: vp = 0.75·T/cp ; vn = 0.25·T/cn
    si no:               vp = vn = T/(cp+cn)
    dt = min sobre archivos restantes de (restante_i / velocidad_i)
    t += dt
    a cada archivo restante: restante_i -= dt · velocidad_i
    quitar el archivo que terminó (el del mínimo)
imprimir t
```

**Traza (ejemplo 1, `T = 40`).**
- Fase 1: prioritarios A, C, D a 10 MB/s; B y E a 5 MB/s. A (10 MB) termina en `dt = 1`.
- Fase 2: C y D a 15 MB/s (restan 10 y 190); B y E a 5 MB/s (restan 95 y 295). C termina en `dt = 10/15`.
- Así sigue. Al final, cuando solo queda E, va a 40 MB/s. Total `15.75` ✓.

**Complejidad.** O(N²) con N ≤ 50.

**Trampas.**
- Si dos archivos terminan a la vez, en la fase siguiente uno de ellos tendrá `dt = 0`. No pasa nada, pero no borres dos archivos en la misma fase sin recalcular.
- Imprime con varios decimales: la tolerancia es 10⁻⁴.

---

## N — Lucky Number

**Resumen.** Formar la mayor cantidad de grupos disjuntos de cartas cuya suma sea múltiplo de 5. No hace falta usar todas las cartas.

**Observaciones.**
1. Solo importa el resto de cada carta mod 5. Sea `c[r]` la cantidad de cartas con resto `r`.
2. **Grupos más chicos = más grupos.** Usar pocas cartas por grupo deja más cartas para otros grupos, así que conviene armar primero los grupos más chicos.
   - Tamaño 1: cada carta con resto 0 es un grupo por sí sola → `c[0]` grupos.
   - Tamaño 2: solo `1+4` y `2+3` → `min(c1,c4)` + `min(c2,c3)` grupos.
3. Después de las parejas, de `{1,4}` queda solo un tipo (el que sobró) y lo mismo de `{2,3}`. Hay 4 casos posibles: (1,2), (1,3), (4,2), (4,3).
4. **Truco para unificar los 4 casos.** Multiplicar todos los restos por `k ∈ {2,3,4}` es una biyección de Z₅ que preserva "suma ≡ 0" (si `s ≡ 0`, entonces `k·s ≡ 0`, y `k` es invertible). Así que los grupos válidos se corresponden uno a uno y la respuesta no cambia. Con eso todos los casos se convierten en "`x` cartas de resto 1 e `y` cartas de resto 2":

   | quedan | multiplicar por | x = cantidad de | y = cantidad de |
   |---|---|---|---|
   | 1 y 2 | 1 | 1s | 2s |
   | 1 y 3 | 2 | 3s (3·2=6≡1) | 1s (1·2=2) |
   | 4 y 2 | 3 | 2s (2·3=6≡1) | 4s (4·3=12≡2) |
   | 4 y 3 | 4 | 4s (4·4=16≡1) | 3s (3·4=12≡2) |

5. Con 1s y 2s, los grupos mínimos son, por tamaño:
   - `1+2+2` (3 cartas)
   - `1+1+1+2` (4 cartas)
   - `1+1+1+1+1` o `2+2+2+2+2` (5 cartas)

   Se arman greedy en ese orden: primero todos los `1+2+2` posibles (`min(x, y/2)`), después los `1+1+1+2` (`min(x/3, y)`), y al final `x/5 + y/5`.

**Por qué funciona.** La idea es un intercambio: si una solución usa un grupo grande donde se podía armar uno más chico con las mismas cartas, cambiarlo libera cartas sin perder grupos. No es una prueba completa, pero se comprobó con una DP exhaustiva (todas las particiones posibles) para todos los conteos `c[r] ≤ 5`, y el greedy coincide siempre.

**Traza (ejemplo 2).** Cartas `1 6 7 10 16 18 41 42 77` → restos `1 1 2 0 1 3 1 2 2`.
- `c = [1, 4, 3, 1, 0]`.
- Restos 0: 1 grupo. Parejas (1,4): 0. Parejas (2,3): 1 → quedan `c1 = 4`, `c2 = 2`.
- Caso (1,2): `x = 4`, `y = 2`. `1+2+2`: 1 grupo → `x = 3`, `y = 0`. `1+1+1+2`: 0. Quintetos: 0.
- Total `1 + 1 + 1 = 3` ✓.

**Complejidad.** O(N).

---

## E — Finding progressions

**Resumen.** Contar las progresiones aritméticas crecientes de enteros (razón `D > 0`) que contienen a `A`, suman `S` y tienen todos sus términos en `[L, R]`.

**Observaciones.**
1. Los números son enormes (hasta 10¹⁸), pero hay una restricción chica: **`R − L ≤ 10⁵`**. Ahí está la clave.
2. Una progresión de `n` términos y razón `D` va de `x₁` a `x₁ + (n−1)·D`, así que necesita `(n−1)·D ≤ R − L`.
3. ¿Cuántos pares `(n, D)` cumplen eso? Para cada `n` hay `⌊(R−L)/(n−1)⌋` valores de `D`. Sumando es una **suma armónica**: `(R−L)·(1 + 1/2 + 1/3 + …) ≈ (R−L)·ln(R−L) ≈ 1.2·10⁶`. Se pueden recorrer todos.
4. Con `n` y `D` fijos, **la suma determina el primer término**:
   `S = n·x₁ + D·(0+1+…+(n−1)) = n·x₁ + D·n(n−1)/2` ⟹ `x₁ = (S − D·n(n−1)/2) / n`.
   Cada `(n, D)` da como mucho **una** progresión.

**Algoritmo.**
```
ans = (A == S) ? 1 : 0                    // n = 1: la progresión [A]
para n = 2 .. (R−L)+1:
  para D = 1 .. mientras (n−1)·D <= R−L:
     resto = S − D·n(n−1)/2               // = n·x₁
     si resto < n·L: cortar el bucle de D (x₁ < L, y al subir D resto solo baja)
     si resto % n != 0: seguir
     x₁ = resto / n ;  xₙ = x₁ + (n−1)·D
     si xₙ > R: seguir
     si A < x₁ o A > xₙ o (A − x₁) % D != 0: seguir
     ans++
```

**Traza (ejemplo 1: `A=5, S=15, [1,10]`).**
- `n=1`: `5 ≠ 15` → 0.
- `n=2`: `x₁ = (15 − D)/2`, entero solo con `D` impar. `D=1` → `[7,8]` sin 5; `D=3` → `[6,9]` sin 5; **`D=5` → `[5,10]` ✓**; `D=7` → `[4,11]` fuera de rango.
- `n=3`: `x₁ = 5 − D` → `[5−D, 5, 5+D]` para `D = 1..4` → **4 progresiones ✓**.
- `n=4`: `15 − 6D` es impar, nunca divisible por 4.
- `n=5`: `x₁ = 3 − 2D`, con `D = 1` → **`[1,2,3,4,5]` ✓**.
- Total **6** ✓.

**Complejidad.** O((R−L) · log(R−L)).

**Trampas.**
- `D·n(n−1)/2 ≤ (R−L)·n/2 ≈ 5·10⁹` y `n·L` llega a 10¹⁷: todo entra en `long long`, pero en `int` no.
- No olvides el caso `n = 1`.

---

## H — Robotic Skills

**Resumen.** El robot entra al tablero desde afuera, se mueve en línea recta y puede girar 90° dentro de las casillas (a lo sumo una vez por casilla). Al final sale del tablero. Los valores de las casillas donde gira deben ser estrictamente crecientes. Hay que maximizar la cantidad de giros.

**Observaciones (modelado).**
1. Entre dos giros consecutivos el robot va en línea recta, así que **dos casillas de giro consecutivas comparten fila o columna**.
2. Cada giro cambia horizontal ↔ vertical. Si llegó a `c_k` moviéndose horizontal (por su fila), sale vertical (por su columna), y entonces `c_{k+1}` está **en la columna** de `c_k`. Las relaciones se **alternan**: fila, columna, fila, columna…
3. Puede pasar por casillas sin girar, entrar desde cualquier borde, y después del último giro simplemente salir. Girar 180° nunca hace falta. Entonces cualquier secuencia creciente de casillas que se alterne fila/columna es un recorrido válido.
4. Queda una especie de "subsecuencia creciente más larga" en el tablero. Como los valores son una permutación de `1..N²`, se procesan las casillas **en orden creciente de valor** y cada una solo mira las ya procesadas (todas menores).

**DP.** Para cada casilla `c = (r, col)`:
- `dpH[c]` = la cadena más larga que termina en `c` **llegando por la fila** (así sale vertical).
  `dpH[c] = 1 + max{ dpV[c'] : c' ya procesada en la fila r }`. La anterior tuvo que llegar vertical para salir horizontal por la fila.
- `dpV[c]` = igual pero **llegando por la columna**:
  `dpV[c] = 1 + max{ dpH[c'] : c' ya procesada en la columna col }`.
- Si no hay ninguna anterior, vale 1: es el primer giro y el robot entró desde afuera.

No hace falta guardar todo: alcanza con `bestRowV[r]` (máximo `dpV` visto en la fila `r`) y `bestColH[col]` (máximo `dpH` visto en la columna `col`).

**Algoritmo.**
```
pos[v] = (fila, col) de la casilla con valor v
para v = 1 .. N²:
    (r, c) = pos[v]
    h = 1 + bestRowV[r]
    w = 1 + bestColH[c]
    bestColH[c] = max(bestColH[c], h)    // llegó por fila → sale por columna c
    bestRowV[r] = max(bestRowV[r], w)    // llegó por columna → sale por fila r
    ans = max(ans, h, w)
```
Calcula `h` y `w` **antes** de actualizar: si no, la casilla se usaría a sí misma como anterior.

**Traza (ejemplo 1).** Tablero `1 2 / 3 4`.
```
v=1 (0,0): h=1, w=1 → bestColH[0]=1, bestRowV[0]=1
v=2 (0,1): h=1+bestRowV[0]=2, w=1+bestColH[1]=1 → bestColH[1]=2
v=3 (1,0): h=1+bestRowV[1]=1, w=1+bestColH[0]=2 → bestRowV[1]=2
v=4 (1,1): h=1+bestRowV[1]=3, w=1+bestColH[1]=3 → ans = 3 ✓
```
(Por ejemplo, `1 → 2` por la fila, `2 → 4` por la columna.)

**Complejidad.** O(N²) tiempo y memoria. **Trampas:** son hasta 10⁶ números, así que usa entrada rápida (`ios::sync_with_stdio(false)`).

---

## J — Jester in danger

**Resumen.** Se borran ciudades de a una (`G_0, G_1, …, G_K`). Para cada `G_i`: si la distancia mínima 1→N es mayor que en `G_0` (o no hay camino), imprime −1. Si no, imprime cuántas ciudades son **críticas**: borrarla haría que la distancia aumente.

**Observaciones.**
1. Sea `d` la distancia en `G_0`. Como `G_i ⊆ G_0`, las distancias solo pueden subir. `G_i` "no está roto" sii todavía existe un camino de largo exactamente `d`.
2. Un camino de largo `d` en `G_i` también es un camino mínimo de `G_0`. Entonces **todo lo que importa vive en el DAG de caminos mínimos de `G_0`**:
   - BFS desde 1 (`d1`) y desde N (`dN`) en `G_0`.
   - `v` está en el DAG si `d1[v] + dN[v] = d`.
   - Arista `u → w` del DAG si es arista del grafo, ambos están en el DAG y `d1[w] = d1[u] + 1`.
3. El DAG está en **capas** según `d1` (capa 0 = {1}, capa d = {N}), y todo camino 1→N del DAG pasa por **exactamente una ciudad de cada capa**.
4. Llama **útil** (en el estado actual) a una ciudad presente que es alcanzable desde 1 y llega a N dentro del DAG, sin pasar por borradas. Entonces:
   **una ciudad es crítica ⇔ es la única útil de su capa.**
   - Si es la única útil de su capa, todo camino de largo `d` pasa por ella → crítica.
   - Si hay otra útil `u` en la misma capa, sigue existiendo un camino 1 → u → N de largo `d` sin la primera → no es crítica.
   - Las ciudades que no son útiles no están en ningún camino de largo `d`, así que no son críticas.
5. Borrar vértices y mantener alcanzabilidad es difícil. **Agregarlos es fácil**: procesa al revés, desde `G_K` agregando `C_K, C_{K−1}, …, C_1`. Al agregar, las marcas "alcanzable desde 1" (`fr`) y "llega a N" (`br`) solo pueden **prenderse**, nunca apagarse. Cada vértice se marca una sola vez en cada dirección, así que el trabajo total es O(N + M).

**Algoritmo.**
```
BFS d1, dN; construir DAG (aristas hacia adelante fw y hacia atrás bw)
present[v] = false para v en C ; true el resto
cnt[capa] = 0 ; unos = 0           // unos = cantidad de capas con cnt == 1

marcarUtil(v):  // cuando v pasa a tener fr y br
    si cnt[d1[v]] == 1: unos--
    cnt[d1[v]]++
    si cnt[d1[v]] == 1: unos++

propagar(s, dirección):  // DFS/BFS marcando fr (con fw) o br (con bw)
    marca s; si tiene la otra marca → marcarUtil(s)
    para cada vecino w presente y sin marcar en esa dirección: idem

propagar(1, adelante); propagar(N, atrás)           // estado G_K
ans[K] = (fr[N] ? unos − 2 : −1)
para i = K−1 .. 0:
    agregar C_{i+1}: present = true
        si algún predecesor en el DAG tiene fr → propagar(v, adelante)
        si algún sucesor en el DAG tiene br    → propagar(v, atrás)
    ans[i] = (fr[N] ? unos − 2 : −1)
```
El `− 2` descuenta las capas 0 y `d`, que siempre tienen una sola ciudad (1 y N) y no cuentan como críticas.

**Traza (ejemplo 1).** Aristas `1-2, 2-4, 2-3, 1-3, 3-4`, `d = 2`. DAG: `1→2→4`, `1→3→4`; capas `{1}`, `{2,3}`, `{4}`. Borrados: 3, luego 2.
- `G_2` (sin 2 ni 3): 4 no es alcanzable → **−1**.
- Agrego 2 → `G_1`: útiles por capa 1, 1, 1 → `unos = 3` → **1**.
- Agrego 3 → `G_0`: la capa 1 tiene `{2,3}` → `unos = 2` → **0**.
- Salida `0 1 −1` ✓.

**Complejidad.** O(N + M).

**Trampas.**
- Recalcular todo en cada estado cuesta O(K·(N+M)): demasiado lento.
- Las ciudades que no están en el DAG se ignoran por completo.

---

## K — Kitties

**Resumen.** Hay un panel con fotos (rectángulos que no se solapan) y una ventana visible de alto `H1` que ocupa todo el ancho. Llegan operaciones: agregar foto, borrar foto, mover el scroll a `x`. Para cada una, responde cuántas fotos **pasaron a ser visibles** y cuántas **dejaron de serlo**.

**Observaciones.**
1. La ventana ocupa todo el ancho, así que **solo importa la coordenada vertical**. Cada foto es un intervalo `[U, D]`.
2. Una foto es visible con scroll `x` (ventana `[x, x+H1]`) sii **`U < x + H1` y `D > x`**. Las desigualdades son estrictas: en el ejemplo, la foto `[1,3]` no es visible con la ventana `[3,5]`.
3. **Agregar / borrar** solo afecta a esa foto: la respuesta es `(1,0)` / `(0,1)` si es visible con el scroll actual, y `(0,0)` si no.
4. **Scroll de `a` a `b`.** Si `ambas` = fotos visibles tanto en `a` como en `b`:
   `nuevas = vis(b) − ambas` y `perdidas = vis(a) − ambas`.
5. **Contar `vis(x)`.** Una foto no es visible si `D ≤ x` (está arriba) o `U ≥ x + H1` (está abajo). Esos dos casos son **disjuntos**: no se puede tener `D ≤ x < x+H1 ≤ U` con `U < D`. Entonces
   `vis(x) = total − #{D ≤ x} − #{U ≥ x+H1}`.
6. **Contar `ambas`.** Con `lo = min(a,b)` y `hi = max(a,b)`, una foto es visible en las dos sii `U < lo + H1` y `D > hi`. Por complemento e inclusión–exclusión:
   `ambas = total − #{U ≥ lo+H1} − #{D ≤ hi} + #{U ≥ lo+H1 y D ≤ hi}`.
   Aquí los conjuntos **no** son disjuntos: el último término cuenta las fotos que caen enteras dentro de `[lo+H1, hi]`, lo que puede pasar si el salto es grande.
7. Todo se reduce a una sola consulta: **`f(p, q) = #{fotos presentes con U ≥ p y D ≤ q}`**, con inserciones y borrados. Es un conteo 2D dinámico (`#{D ≤ x}` es `f(−∞, x)` y `#{U ≥ p}` es `f(p, +∞)`).

**Estructura: BIT 2D offline.** Todas las fotos (las iniciales y las que se agregan) aparecen en el input, así que se conocen todos los puntos `(U, D)` de antemano.
1. Comprime los `U` y ordénalos de **mayor a menor**. Así "U ≥ p" es un **prefijo** del BIT externo.
2. Para cada nodo `i` del BIT externo, guarda la lista ordenada de los `D` de todas las fotos cuyo update pasa por `i`. Sobre esa lista, un BIT interno.
3. `update(U, D, ±1)`: recorre los nodos externos de `U` y, en cada uno, busca `D` en su lista (`lower_bound`) y actualiza el BIT interno.
4. `query(p, q)`: recorre el prefijo externo de los `U ≥ p` y, en cada nodo, suma el prefijo interno de los `D ≤ q` (`upper_bound`).

Memoria O(P log P) y O(log² P) por operación, con P = N + K ≤ 2·10⁵.

**Traza (ejemplo, primera operación `M 3`).** `H1 = 2`. Fotos: `[1,2]`, `[1,3]`, `[0,3]`, `[4,5]`. Scroll de 0 a 3.
- `vis(3)`: fotos con `U < 5` y `D > 3` → solo `[4,5]` → 1.
- `vis(0)`: fotos con `U < 2` y `D > 0` → `[1,2]`, `[1,3]`, `[0,3]` → 3.
- `ambas` (`lo = 0`, `hi = 3`): `U < 2` y `D > 3` → ninguna → 0.
- Respuesta `1 3` ✓.

**Complejidad.** O((N + Q) log²(N + K)).

**Alternativas.** CDQ divide & conquer sobre el tiempo, o un merge-sort tree con BIT.

---

## G — Great Heights

**Resumen.** Hay andamios horizontales (altura `H`, rango `[L, R]`). Se ponen escaleras a 45° que conectan el suelo o un andamio con otro andamio más alto, y su costo es la diferencia de alturas. Hay que llegar a todos los andamios desde el suelo con costo total mínimo.

**Observaciones.**
1. **Es un MST.** Nodos = andamios + suelo. Arista `i–j` con costo `|H_i − H_j|` si se puede poner una escalera entre ellos. El suelo conecta con todos (costo `H_i`), porque es infinito. Queremos todo conectado con costo mínimo, y como los costos son positivos, eso es un árbol generador mínimo.
2. **El problema son las aristas:** puede haber O(N²) pares conectables.
3. **Truco: rotar 45°.** Sobre una escalera que sube hacia la derecha, los puntos son `(x+t, h+t)`, así que **`u = x − h` es constante**. Sobre una que sube hacia la izquierda, **`v = x + h` es constante**. El andamio `i` ocupa:
   - `u ∈ [L_i − H_i, R_i − H_i]`
   - `v ∈ [L_i + H_i, R_i + H_i]`

   Hay una escalera hacia la derecha entre `i` y `j` sii sus intervalos `u` comparten algún valor (ese valor fija el punto de base y el de llegada). Lo mismo con `v` hacia la izquierda.
   ⟹ **`i` y `j` se conectan ⇔ sus intervalos en `u` se cortan, o sus intervalos en `v` se cortan.** Quedan dos problemas 1D de intervalos.
4. **Cliques.** Todos los intervalos que contienen un mismo punto `p` se conectan entre sí. Para una clique con pesos `|H_a − H_b|`, el MST es simplemente el **camino ordenado por altura**: cada arista `(a, b)` de la clique se reemplaza por los pasos consecutivos entre ellas, y cada paso cuesta `≤ |H_a − H_b|`.
5. **Sweep.** Recorre la coordenada de izquierda a derecha manteniendo un `set` de intervalos activos **ordenado por altura**. Las aristas candidatas son los pares que en algún momento son **vecinos** en el set:
   - al **insertar** un intervalo: arista con su predecesor y con su sucesor;
   - al **borrar** uno: arista entre su predecesor y su sucesor, que pasan a ser vecinos.

   Cada evento agrega ≤ 2 aristas → O(N) candidatas en total.

**Por qué alcanza.** Toma dos intervalos `i`, `j` que se cortan, y sea `p = max(lo_i, lo_j)`, donde los dos están activos. En el set en ese momento, entre `i` y `j` hay una cadena de vecinos consecutivos por altura. Cada eslabón de la cadena fue vecino en algún momento, así que es candidato, y cuesta `≤ |H_i − H_j|`. Por la **propiedad del ciclo** del MST, la arista `(i, j)` se puede descartar sin cambiar el costo óptimo.

**Algoritmo.**
```
aristas = { (H_i, i, suelo) para cada i }
para cada sistema de coordenadas (u y v):
    eventos = (lo_i, INSERTAR, i), (hi_i, BORRAR, i)
    ordenar por coordenada; a igual coordenada, INSERTAR antes que BORRAR
    set ordenado por (H, id):
       insertar → arista con pred y con succ
       borrar   → arista pred–succ; luego borrar
Kruskal (ordenar aristas por costo + DSU)
```

**Complejidad.** O(N log N).

**Trampas.**
- Los extremos son cerrados: dos intervalos que solo se tocan en un punto **sí** se conectan. Por eso, a igual coordenada, hay que insertar antes de borrar.
- El costo total llega a 10⁵·10⁹: usa `long long`.
- Usa `(H, id)` como clave del set, porque puede haber alturas repetidas.

---

## I — Regional Integration

**Resumen.** En el plano hay edificios con forma de círculo, cuadrado (no necesariamente alineado con los ejes) o triángulo, y ninguno toca a otro. Dentro de los edificios se camina a la sombra. Hay que elegir un cuadrado y un triángulo de forma que la distancia caminada **al sol** entre ellos sea mínima.

**Observaciones.**
1. **Modelo de grafo.** Nodos = edificios. Peso de una arista = distancia mínima entre las dos figuras: dentro de una figura convexa te mueves gratis, y entre figuras conviene ir en línea recta. Buscamos el camino mínimo desde algún cuadrado hasta algún triángulo.
2. **El camino óptimo nunca pasa por otro cuadrado ni por otro triángulo.** Si pasa por un cuadrado intermedio, empezar en ese cuadrado es igual o mejor; si pasa por un triángulo intermedio, terminar ahí es igual o mejor. Entonces el camino es:
   `cuadrado → (círculo → … → círculo) → triángulo`
   o directamente `cuadrado → triángulo`.
3. Las aristas necesarias son `Q·C` (cuadrado–círculo) + `C²` (círculo–círculo) + `C·T` (círculo–triángulo) + `Q·T` (cuadrado–triángulo) = **`(Q+C)·(T+C) ≤ 10⁶`**. Justo la cota del enunciado, lo que confirma la idea.
4. **Multi-source.** En vez de un Dijkstra por cada cuadrado, todos los cuadrados son fuentes a la vez: `dist[c] = min_q d(q, c)` para cada círculo. Después, un **Dijkstra denso O(C²)** (sin heap, eligiendo el mínimo no visitado con un for) entre círculos, porque el grafo de círculos es completo.

**Distancias entre figuras** (como no se cortan, la distancia se alcanza en los bordes):
- **punto–segmento:** proyectar el punto sobre la recta, `t = (p−a)·(b−a) / |b−a|²`, limitar `t` a `[0,1]` y medir hasta `a + t·(b−a)`.
- **polígono–polígono:** el mínimo de la distancia de cada vértice de uno a cada lado del otro, y viceversa. Para cuadrado–triángulo son 4·3 + 3·4 = 24 cálculos.
- **círculo–polígono:** `dist(centro, borde del polígono) − r`. El centro no puede estar adentro del polígono porque las figuras no se tocan.
- **círculo–círculo:** `|c₁ − c₂| − r₁ − r₂`.

**Vértices del cuadrado.** Te dan dos vértices opuestos `a` y `b`. El centro es `m = (a+b)/2` y el medio-diagonal `h = (b−a)/2`; la otra diagonal es `h` rotado 90°: `rot(h) = (−h.y, h.x)`. Los vértices en orden son `a, m + rot(h), b, m − rot(h)`.

**Algoritmo.**
```
dist[c] = min sobre cuadrados q de d(q, c)            O(Q·C)
Dijkstra denso entre círculos con peso d(c1, c2)      O(C²)
ans = min sobre triángulos t de:
        min_q d(q, t)                                 O(Q·T)
        min_c dist[c] + d(c, t)                       O(C·T)
```

**Traza (ejemplo 2).** El cuadrado de `(1,1)` a `(4,4)` es `[1,4]×[1,4]`, y el triángulo tiene vértices `(5,1)`, `(5,10)`, `(10,1)`. El lado `x = 5` del triángulo está a distancia 1 del lado `x = 4` del cuadrado → `1.0` ✓.

En el ejemplo 1 conviene pasar por los dos círculos: el camino cuadrado → círculo → círculo → triángulo es más corto que ir directo.

**Complejidad.** O((Q+C)(T+C)) ≈ 2.4·10⁷ cálculos punto–segmento en el peor caso (el límite es 7.5 s).

**Trampas.**
- Las coordenadas llegan a 10⁹ y los productos a 10¹⁸, y la tolerancia es 10⁻⁶ absoluta: usa `long double`.
- Los vértices del cuadrado pueden tener coordenadas `.5`; trabaja en punto flotante (o multiplica todo por 2).
- Si `C = 0`, el Dijkstra no hace nada y la respuesta sale solo de los pares cuadrado–triángulo.
