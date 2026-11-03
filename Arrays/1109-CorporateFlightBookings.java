class Solution {
    public int[] corpFlightBookings(int[][] bookings, int n) {
        // Create difference array of size n + 2 to avoid out-of-bounds errors
        int[] a = new int[n + 2];

        // Apply range updates to the difference array
        for (int i = 0; i < bookings.length; i++) {
            a[bookings[i][0]] += bookings[i][2];
            a[bookings[i][1] + 1] -= bookings[i][2];
        }

        // Reconstruct the actual values using running prefix sums
        int[] ans = new int[n];
        for (int i = 1; i <= n; i++) {
            a[i] += a[i - 1];
            ans[i - 1] = a[i];
        }

        return ans;
    }
}