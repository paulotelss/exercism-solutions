import java.util.ArrayList;
import java.util.List;

public class IntergalacticTransmission {

    public static List<Integer> getTransmitSequence(List<Integer> message) {
        List<Integer> transmission = new ArrayList<>();
        int currentByte = 0;
        int bitsCount = 0;
        int onesCount = 0;

        for (int b : message) {
            for (int i = 7; i >= 0; i--) {
                int bit = (b >> i) & 1;
                currentByte = (currentByte << 1) | bit;
                if (bit == 1) onesCount++;
                bitsCount++;

                if (bitsCount == 7) {
                    int parityBit = (onesCount % 2 == 0) ? 0 : 1;
                    transmission.add((currentByte << 1) | parityBit);
                    currentByte = 0;
                    bitsCount = 0;
                    onesCount = 0;
                }
            }
        }

        if (bitsCount > 0) {
            while (bitsCount < 7) {
                currentByte <<= 1;
                bitsCount++;
            }
            int parityBit = (onesCount % 2 == 0) ? 0 : 1;
            transmission.add((currentByte << 1) | parityBit);
        }
        return transmission;
    }

    public static List<Integer> decodeSequence(List<Integer> sequence) {
        List<Integer> result = new ArrayList<>();
        StringBuilder bits = new StringBuilder();

        for (int b : sequence) {
            // Verifica se o número de bits 1 é par
            if (Integer.bitCount(b) % 2 != 0) {
                // Em transmissões espaciais, se a paridade falha, algo deu errado
                throw new IllegalArgumentException("Parity error detected");
            }
            // Extrai os 7 bits de dados (ignora o bit de paridade na posição 0)
            for (int i = 7; i >= 1; i--) {
                bits.append((b >> i) & 1);
            }
        }

        // Reconstrói os bytes originais de 8 bits
        for (int i = 0; i + 8 <= bits.length(); i += 8) {
            result.add(Integer.parseInt(bits.substring(i, i + 8), 2));
        }
        return result;
    }
}