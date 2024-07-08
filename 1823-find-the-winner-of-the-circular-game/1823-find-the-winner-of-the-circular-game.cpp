class Solution {
public:
  int findWinner(int n, int k) {
    if (n == 1) {
        return 0;
    } else {
        return (findWinner(n - 1, k) + k) % n;
    }
}
int findTheWinner(int n, int k) {
    int res = findWinner(n, k) + 1;
    return res;
}
};