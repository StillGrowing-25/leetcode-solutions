class Solution {
public:

    long long solve(vector<int>& startTime,
                    vector<int>& duration,
                    vector<int>& otherStartTime,
                    vector<int>& otherDuration) {

        int m = otherStartTime.size();

        vector<pair<int,int>> rides;

        for(int i = 0; i < m; i++) {
            rides.push_back({otherStartTime[i], otherDuration[i]});
        }

        sort(rides.begin(), rides.end());

        vector<int> starts(m);
        vector<long long> prefMinDuration(m);
        vector<long long> suffMinFinish(m);

        for(int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDuration[0] = rides[0].second;

        for(int i = 1; i < m; i++) {
            prefMinDuration[i] =
                min(prefMinDuration[i-1],
                    (long long)rides[i].second);
        }

        suffMinFinish[m-1] =
            (long long)rides[m-1].first +
            rides[m-1].second;

        for(int i = m-2; i >= 0; i--) {

            suffMinFinish[i] =
                min(suffMinFinish[i+1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        long long minimum = LLONG_MAX;

        for(int i = 0; i < startTime.size(); i++) {

            long long finishFirst =
                (long long)startTime[i] +
                duration[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishFirst)
                - starts.begin();

            long long best = LLONG_MAX;

            if(pos > 0) {
                best =
                    min(best,
                        finishFirst +
                        prefMinDuration[pos-1]);
            }

            if(pos < m) {
                best =
                    min(best,
                        suffMinFinish[pos]);
            }

            minimum = min(minimum, best);
        }

        return minimum;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long landToWater =
            solve(landStartTime,
                  landDuration,
                  waterStartTime,
                  waterDuration);

        long long waterToLand =
            solve(waterStartTime,
                  waterDuration,
                  landStartTime,
                  landDuration);

        return (int)min(landToWater, waterToLand);
    }
};
