public class Secrets {

    /**
     * 1. desloca os bits para a direita inserindo zeros à esquerda.
     * usamos o operador >>> (unsigned right shift) para garantir que,
     * mesmo que o número seja negativo, o preenchimento seja com 0s.
     */
    public static int shiftBack(int value, int amount) {
        return value >>> amount;
    }

    /**
     * 2. define bits específicos como 1.
     * utilizamos o operador OR (|), que resulta em 1 se qualquer bit for 1.
     */
    public static int setBits(int value, int mask) {
        return value | mask;
    }

    /**
     * 3. inverte bits específicos.
     * O operador XOR (^) é a ferramenta perfeita aqui: ele inverte o bit original
     * apenas onde o bit da máscara for 1.
     */
    public static int flipBits(int value, int mask) {
        return value ^ mask;
    }

    /**
     * 4. limpa bits específicos (força-os a serem 0).
     * técnica "fora da curva": Invertemos a máscara com NOT (~) e usamos AND (&).
     * isso preserva os bits onde a máscara era 0 e zera onde a máscara era 1.
     */
    public static int clearBits(int value, int mask) {
        return value & ~mask;
    }
}