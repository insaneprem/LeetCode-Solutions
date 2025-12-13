class FrontMiddleBackQueue {
public:
    list<int> queue;
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        queue.push_front(val);
    }

    void pushMiddle(int val) {
        int sz = queue.size();

        int idx = (sz) / 2;

        auto it = queue.begin();
        advance(it, idx);
        queue.insert(it, val);
    }

    void pushBack(int val) {
        queue.push_back(val);
    }

    int popFront() {
        if (queue.empty())
            return -1;
        int v = queue.front();
        queue.pop_front();
        return v;
    }

    int popMiddle() {
        if (queue.empty())
            return -1;
        int sz = queue.size();

        int idx = (sz - 1) / 2;
        auto it = queue.begin();
        advance(it, idx);
        int v = *it;
        queue.erase(it);

        return v;
    }

    int popBack() {
        if (queue.empty())
            return -1;
        int v = queue.back();
        queue.pop_back();

        return v;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */