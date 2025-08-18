class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> result(n, 0);

        for (auto &booking : bookings) {
            int first = booking[0], last = booking[1], seats = booking[2];
            for (int i = first - 1; i <= last - 1; i++) {
                result[i] += seats;
            }
        }
        return result;
    }
};
