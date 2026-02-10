import java.util.Arrays;

class BirdWatcher {
    // Constante para evitar "Magic Numbers" no retorno de dados históricos
    private static final int[] LAST_WEEK_COUNTS = {0, 2, 5, 3, 7, 8, 4};
    private static final int BUSY_DAY_THRESHOLD = 5;

    private final int[] birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay.clone();
    }

    // 1. Retorna os dados da última semana usando a constante definida
    public static int[] getLastWeek() {
        return LAST_WEEK_COUNTS;
    }

    // 2. Acesso direto ao último elemento do array (hoje)
    public int getToday() {
        return birdsPerDay.length == 0 ? 0 : birdsPerDay[birdsPerDay.length - 1];
    }

    // 3. Incrementa o valor do último índice
    public void incrementTodaysCount() {
        int todayIndex = birdsPerDay.length - 1;
        birdsPerDay[todayIndex]++;
    }

    /** * 4. Verifica dia sem pássaros.
     * Abordagem "Fora da Curva": Uso de Java Streams para busca declarativa.
     */
    public boolean hasDayWithoutBirds() {
        return Arrays.stream(birdsPerDay).anyMatch(count -> count == 0);
    }

    /** * 5. Soma dos primeiros N dias.
     * Abordagem "Fora da Curva": Limitação de fluxo (limit) e redução por soma.
     */
    public int getCountForFirstDays(int numberOfDays) {
        return Arrays.stream(birdsPerDay)
                     .limit(numberOfDays)
                     .sum();
    }

    /** * 6. Contador de dias ocupados (5+ pássaros).
     * Abordagem "Fora da Curva": Filtro funcional e contagem via stream.
     */
    public int getBusyDays() {
        return (int) Arrays.stream(birdsPerDay)
                           .filter(count -> count >= BUSY_DAY_THRESHOLD)
                           .count();
    }
}