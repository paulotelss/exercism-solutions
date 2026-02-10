public class Lasagna {

    // 1. Define o tempo esperado no forno em minutos
    public int expectedMinutesInOven() {
        return 40; // De acordo com o livro de receitas
    }

    // 2. Calcula o tempo restante no forno em minutos
    public int remainingMinutesInOven(int actualMinutes) {
        // Subtrai o tempo atual do tempo esperado definido na tarefa anterior
        return expectedMinutesInOven() - actualMinutes;
    }

    // 3. Calcula o tempo de preparação em minutos
    public int preparationTimeInMinutes(int numberOfLayers) {
        // Cada camada leva 2 minutos para preparar
        return numberOfLayers * 2;
    }

    // 4. Calcula o tempo total de trabalho em minutos
    public int totalTimeInMinutes(int numberOfLayers, int minutesInOven) {
        // Soma o tempo de preparo das camadas com o tempo que já passou no forno
        return preparationTimeInMinutes(numberOfLayers) + minutesInOven;
    }
}