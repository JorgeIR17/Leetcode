#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.') continue;

                int offset = board[r][c] - '1';

                if(rows[r] & (1 << offset) || cols[c] & (1 << offset) || squares[(r/3)*3+(c/3)] & (1 << offset))
                    return false;

                rows[r] |= (1 << offset);
                cols[c] |= (1 << offset);
                squares[(r/3)*3+(c/3)] |= (1 << offset);
            }
        }
        return true;
    }
};

// Eficiencia temporal: O(n^2) donde n es el tamaño del tablero (9)
// Eficiencia espacial: O(n) donde n es el tamaño del tablero (9)

/*Explicacion del codigo:

Al tener un tablero de 9x9, podemos representar la posicion con un entero usando 9 bits.
Dado que tenemos valores del 1 al 9, restamos '1' al valor para obtener un desplazamiento, y colocar el 1 en la posicion del valor.
El '&' es un AND bit a bit, y (1 << offset) es un desplazamiento a la izquierda de 1, que nos da un valor con un solo bit en la posicion del valor.
Ejemplo: Valor = '5', offset = 4, (1 << offset) = 00010000
Al aplicar el AND bit a bit, si alguno de los bits ya estaba a 1, devolverá 1, por lo que sera false.
Si no está, aplicamos el OR bit a bit (operador '|') para poner el bit en 1, y asi sucesivamente.

*/

