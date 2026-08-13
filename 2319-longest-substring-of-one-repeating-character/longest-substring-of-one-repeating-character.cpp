class Solution {
public:
    struct Node {
        int max_len;
        int pref;
        int suff;
        char leftchar;
        char rightchar;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R, int leftlen, int rightlen) {
        Node res;
        res.leftchar = L.leftchar;
        res.rightchar = R.rightchar;

        res.pref = L.pref;

        if (L.pref == leftlen && L.rightchar == R.leftchar) {
            res.pref = L.pref + R.pref;
        }
        res.suff = R.suff;

        if (R.suff == rightlen && L.rightchar == R.leftchar) {
            res.suff = L.suff + R.suff;
        }
        res.max_len = max(L.max_len, R.max_len);

        if (L.rightchar == R.leftchar) {
            res.max_len = max(res.max_len, L.suff + R.pref);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {

        if (l == r) {
            segTree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, s);

        buildSegmentTree(2 * i + 2, mid + 1, r, s);

        segTree[i] =
            merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {

        if (l == r) {
            segTree[i] = {1, 1, 1, ch, ch};
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        }

        else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }

        segTree[i] =
            merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        n = s.size();
        segTree.assign(4 * n, Node());

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();

        vector<int> result(k);

        for (int i = 0; i < k; i++) {

            int pos = queryIndices[i];
            char ch = queryCharacters[i];

            update(0, 0, n - 1, pos, ch);

            result[i] = segTree[0].max_len;
        }

        return result;
    }
};