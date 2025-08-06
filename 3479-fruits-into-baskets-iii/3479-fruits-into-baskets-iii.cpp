struct NodeMax {
    int maxval;
    NodeMax() : maxval(-1) {}
    NodeMax(int val) : maxval(val) {}
    void merge(NodeMax &l, NodeMax &r) {
        maxval = max(l.maxval, r.maxval);
    }
};

struct UpdateSet {
    int newval;
    UpdateSet(int val) : newval(val) {}
    void apply(NodeMax &node) {
        node.maxval = newval;
    }
};

template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<int> arr;
    int n;
    int s;
    SegTree(int a_len, vector<int> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n) {
            s = s << 1;
        }
        tree.resize(s);
        fill(tree.begin(), tree.end(), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) {
        if (start == end) {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l = query(start, mid, 2 * index, left, right);
        Node r = query(mid + 1, end, 2 * index + 1, left, right);
        Node ans;
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, int val) {
        Update new_update = Update(val);
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        SegTree<NodeMax, UpdateSet> st(n, baskets);

        int ans = 0;
        for (auto it : fruits) {
            if (st.tree[1].maxval < it) {
                ans++;
            } else {
                int curridx = 1;
                int left = 0, right = n - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (st.tree[2 * curridx].maxval >= it) {
                        curridx = 2 * curridx;
                        right = mid;
                    } else {
                        curridx = 2 * curridx + 1;
                        left = mid + 1;
                    }
                }
                st.make_update(left, -1);
            }
        }
        return ans;
    }
};
