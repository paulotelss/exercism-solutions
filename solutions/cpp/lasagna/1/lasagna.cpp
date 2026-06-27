// ovenTime returns the expected oven time in minutes.
int ovenTime() {
    return 40;
}

// remainingOvenTime calculates the remaining minutes based on the expected time.
int remainingOvenTime(int actualMinutesInOven) {
    return ovenTime() - actualMinutesInOven;
}

// preparationTime calculates the preparation time based on the number of layers.
int preparationTime(int numberOfLayers) {
    const int minutes_per_layer = 2;
    return numberOfLayers * minutes_per_layer;
}

// elapsedTime calculates the total time spent so far (preparation + oven time).
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
    return preparationTime(numberOfLayers) + actualMinutesInOven;
}