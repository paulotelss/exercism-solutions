public class SquareRoot {

    /**
     * calcula a raiz quadrada usando o método de extração bit a bit.
     * este método é altamente eficiente para sistemas embarcados e naves espaciais
     * pois não utiliza multiplicações ou divisões pesadas.
     */
    public int squareRoot(int number) {
        // 'res' armazenará o resultado final
        int res = 0;
        
        // 'bit' começa na maior potência de 4 menor ou igual ao número.
        // usamos potências de 4 porque (2^n)^2 = 4^n.
        int bit = 1 << 30; // O maior bit de potência de 4 em um int de 32 bits (2^30)

        // localiza a maior potência de 4 inicial
        while (bit > number) {
            bit >>= 2;
        }

        // processa os bits do número para extrair a raiz
        while (bit != 0) {
            if (number >= res + bit) {
                number -= res + bit;
                res = (res >> 1) + bit;
            } else {
                res >>= 1;
            }
            bit >>= 2;
        }

        return res;
    }
}