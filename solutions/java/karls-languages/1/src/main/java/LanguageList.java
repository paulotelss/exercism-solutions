import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class LanguageList {
    // Constante para evitar "Magic Strings" e facilitar a manutenção [cite: 2026-02-10]
    // Usamos um Set para busca O(1), uma técnica mais eficiente que percorrer a lista
    private static final Set<String> EXCITING_LANGUAGES = Set.of("Java", "Kotlin");

    private final List<String> languages = new ArrayList<>();

    // 1. Verifica se a lista está vazia usando o método nativo de List
    public boolean isEmpty() {
        return languages.isEmpty();
    }

    // 2. Adiciona uma nova língua à lista
    public void addLanguage(String language) {
        languages.add(language);
    }

    // 3. Remove uma língua específica da lista
    public void removeLanguage(String language) {
        languages.remove(language);
    }

    // 4. Retorna o primeiro item (índice 0) da lista
    public String firstLanguage() {
        if (isEmpty()) {
            return null; // Ou lance uma exceção dependendo do requisito do teste
        }
        return languages.get(0);
    }

    // 5. Retorna o tamanho atual da coleção
    public int count() {
        return languages.size();
    }

    // 6. Verifica a presença de uma língua na lista
    public boolean containsLanguage(String language) {
        return languages.contains(language);
    }

    /**
     * 7. Verifica se a lista é excitante.
     * Abordagem "Fora da Curva": Uso de Stream API com predicado de conjunto.
     * Isso evita múltiplos "if" ou "||" manuais. [cite: 7, 2026-02-10]
     */
    public boolean isExciting() {
        return languages.stream()
                        .anyMatch(EXCITING_LANGUAGES::contains);
    }
}