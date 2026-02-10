class AnnalynsInfiltration {

    // 1. ataque rápido: possível se o cavaleiro estiver dormindo.
    public static boolean canFastAttack(boolean knightIsAwake) {
        return !knightIsAwake;
    }

    // 2. espionar: possível se pelo menos um deles estiver acordado.
    public static boolean canSpy(boolean knightIsAwake, boolean archerIsAwake, boolean prisonerIsAwake) {
        return knightIsAwake || archerIsAwake || prisonerIsAwake;
    }

    // 3. sinalizar prisioneiro: prisioneiro acordado e arqueiro dormindo.
    public static boolean canSignalPrisoner(boolean archerIsAwake, boolean prisonerIsAwake) {
        return prisonerIsAwake && !archerIsAwake;
    }

    // 4. libertar prisioneiro: a lógica mais complexa do rpg.
    public static boolean canFreePrisoner(boolean knightIsAwake, boolean archerIsAwake, boolean prisonerIsAwake, boolean petDogIsPresent) {
        if (petDogIsPresent) {
            // Com o cachorro: só precisa que o arqueiro esteja dormindo.
            return !archerIsAwake;
        } else {
            // Sem o cachorro: prisioneiro acordado E ambos os sequestradores dormindo.
            return prisonerIsAwake && !knightIsAwake && !archerIsAwake;
        }
    }
}