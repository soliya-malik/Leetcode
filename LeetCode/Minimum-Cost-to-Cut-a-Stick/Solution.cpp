class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cut_points = [0] + sorted(cuts) + [n]

        @cache
        def get_optimal_cost(s, e):
            return min(get_optimal_cost(s, m) + get_optimal_cost(m, e) for m in range(s + 1, e)) + \
                cut_points[e] - cut_points[s] if s + 1 < e else 0
        
        return get_optimal_cost(0, len(cut_points) - 1)