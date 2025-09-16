class MedianFinder {
private:
    priority_queue<int> left; // max-heap
    priority_queue<int, vector<int>, greater<int>> right; // min-heap

public:
    MedianFinder() {}

    void addNum(int num) {
        left.push(num);

        // Balance heaps
        right.push(left.top());
        left.pop();

        // Maintain size property
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }
};
