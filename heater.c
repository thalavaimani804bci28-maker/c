#include <stdlib.h>
#include <math.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    if (valA < valB) return -1;
    if (valA > valB) return 1;
    return 0;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    // Step 1: Sort both houses and heaters positions
    qsort(houses, housesSize, sizeof(int), compare);
    qsort(heaters, heatersSize, sizeof(int), compare);

    int maxRadius = 0;
    int heaterPtr = 0;

    // Step 2: For each house, find the closest heater
    for (int i = 0; i < housesSize; i++) {
        // Move the heater pointer forward if the next heater is closer to the current house
        while (heaterPtr < heatersSize - 1 && 
               abs(heaters[heaterPtr + 1] - houses[i]) <= abs(heaters[heaterPtr] - houses[i])) {
            heaterPtr++;
        }

        // Calculate the absolute distance from the house to its closest heater
        int currentDistance = abs(heaters[heaterPtr] - houses[i]);

        // The global radius standard must be at least this distance to cover this house
        if (currentDistance > maxRadius) {
            maxRadius = currentDistance;
        }
    }

    return maxRadius;
}
