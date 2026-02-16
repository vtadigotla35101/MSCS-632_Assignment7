class StatisticsCalculator:
    def __init__(self, data):
        self.data = sorted(data)

    def calculate_mean(self):
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        n = len(self.data)
        mid = n // 2
        if n % 2 == 0:
            return (self.data[mid - 1] + self.data[mid]) / 2
        return self.data[mid]

    def calculate_mode(self):
        from collections import Counter
        counts = Counter(self.data)
        max_freq = max(counts.values())
        return [k for k, v in counts.items() if v == max_freq]

# Usage
my_stats = StatisticsCalculator([4, 1, 2, 2, 3])
print(f"Mean: {my_stats.calculate_mean()}")
print(f"Median: {my_stats.calculate_median()}")
print(f"Mode: {my_stats.calculate_mode()}")