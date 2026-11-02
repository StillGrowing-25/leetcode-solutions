class Solution {
    public int maximumPopulation(int[][] logs) {
        int[] populationChanges = new int[101];
        
        for (int[] log : logs) {
            populationChanges[log[0] - 1950]++;
            populationChanges[log[1] - 1950]--;
        }
        
        int maxPopulation = 0;
        int maxYear = 1950;
        int currentPopulation = 0;
        
        for (int i = 0; i < 101; i++) {
            currentPopulation += populationChanges[i];
            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                maxYear = 1950 + i;
            }
        }
        
        return maxYear;
    }
}