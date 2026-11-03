class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] track = new int[1001];
        for (int i = 0; i < trips.length; i++) {
            track[trips[i][1]] = track[trips[i][1]] + trips[i][0];
            track[trips[i][2]] = track[trips[i][2]] - trips[i][0];
        }
        int a = 0;
        for (int i = 0; i < 1001; i++) {
            
            if (i != 0)
                a = track[i - 1];
            track[i] += a;
            if (track[i] > capacity)
                return false;
        }
        return true;
    }
}