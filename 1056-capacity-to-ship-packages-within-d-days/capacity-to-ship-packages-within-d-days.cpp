class Solution {
public:
   int calculateDays(vector<int>& weights, int capacity) {

    int days = 1;
    int currentWeight = 0;

    for(int i = 0; i < weights.size(); i++) {

        if(currentWeight + weights[i] <= capacity) {
            currentWeight = currentWeight + weights[i];
        }
        else {
            days++;
            currentWeight = weights[i];
        }
    }

    return days;
}

int shipWithinDays(vector<int>& weights, int days) {

    // low = maximum weight
    int low = weights[0];

    for(int i = 1; i < weights.size(); i++) {
        if(weights[i] > low) {
            low = weights[i];
        }
    }

    // high = total weight
    int high = 0;

    for(int i = 0; i < weights.size(); i++) {
        high = high + weights[i];
    }

    int ans = high;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int requiredDays = calculateDays(weights, mid);

        if(requiredDays <= days) {

            // Capacity works
            // We need minimum capacity
            ans = mid;
            high = mid - 1;
        }
        else {

            // Capacity is too small
            low = mid + 1;
        }
    }

    return ans;
}
};