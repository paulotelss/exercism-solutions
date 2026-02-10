public class CarsAssemble {

    // Constantes para evitar "Magic Numbers" e alertas do mentor
    private static final int BASE_PRODUCTION_PER_HOUR = 221;
    private static final int MINUTES_IN_HOUR = 60;

    /**
     * Abordagem "Fora da Curva": Lookup Table para taxas de sucesso.
     * Em vez de uma cadeia de if/else, usamos um array onde o índice é a velocidade.
     * Isso elimina a complexidade ciclomática e possíveis avisos de "complexidade excessiva".
     */
    private static final double[] SUCCESS_RATES = {
        0.00, // Velocidade 0: 0%
        1.00, // Velocidade 1: 100%
        1.00, // Velocidade 2: 100%
        1.00, // Velocidade 3: 100%
        1.00, // Velocidade 4: 100%
        0.90, // Velocidade 5: 90%
        0.90, // Velocidade 6: 90%
        0.90, // Velocidade 7: 90%
        0.90, // Velocidade 8: 90%
        0.80, // Velocidade 9: 80%
        0.77  // Velocidade 10: 77%
    };

    public double productionRatePerHour(int speed) {
        // Cálculo linear baseado na velocidade e na taxa de sucesso da nossa tabela
        return speed * BASE_PRODUCTION_PER_HOUR * SUCCESS_RATES[speed];
    }

    public int workingItemsPerMinute(int speed) {
        // Conversão explícita (cast) de double para int conforme exigido pelo Java
        // Dividimos a produção horária pelos minutos da hora
        return (int) (productionRatePerHour(speed) / MINUTES_IN_HOUR);
    }
}