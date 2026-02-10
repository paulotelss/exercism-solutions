import java.util.Map;

public class SqueakyClean {

    // Constante para mapeamento de leetspeak (evita magic numbers e melhora performance)
    private static final Map<Character, Character> LEET_MAP = Map.of(
        '4', 'a',
        '3', 'e',
        '0', 'o',
        '1', 'l',
        '7', 't'
    );

    public static String clean(String identifier) {
        StringBuilder result = new StringBuilder();
        boolean upperNext = false;

        for (char ch : identifier.toCharArray()) {
            // 1. Substitui espaços por underscores
            if (Character.isWhitespace(ch)) {
                result.append('_');
            } 
            // 2. Lógica para kebab-case -> camelCase
            else if (ch == '-') {
                upperNext = true;
            } 
            // 3. Converte leetspeak para texto normal
            else if (LEET_MAP.containsKey(ch)) {
                appendChar(result, LEET_MAP.get(ch), upperNext);
                upperNext = false;
            } 
            // 4. Mantém apenas letras, omitindo símbolos e números restantes
            else if (Character.isLetter(ch)) {
                appendChar(result, ch, upperNext);
                upperNext = false;
            }
        }

        return result.toString();
    }

    /**
     * Método auxiliar para lidar com a capitalização do camelCase.
     * Isolar essa lógica evita repetição de código (DRY).
     */
    private static void appendChar(StringBuilder builder, char ch, boolean upper) {
        builder.append(upper ? Character.toUpperCase(ch) : ch);
    }
}