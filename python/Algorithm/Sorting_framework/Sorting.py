class Sorting:
    def __init__(self, input_array):
        self.sorting_array = input_array
        self.comparison_count = 0

    def merge_sort(self, p, r):
        if p >= r:
            return
        q = (p + r) // 2
        self.merge_sort(p, q)
        self.merge_sort(q + 1, r)
        self.merge(p, q, r)

    def merge(self, p, q, r):
        len_L = q - p + 1
        len_R = r - q
        L = self.sorting_array[p: q + 1]
        R = self.sorting_array[q + 1: r + 1]
        
        i, j, k = 0, 0, p
        while i < len_L and j < len_R:
            if L[i] <= R[j]:
                self.sorting_array[k] = L[i]
                i += 1
            else:
                self.sorting_array[k] = R[j]
                j += 1
            self.comparison_count += 1
            k += 1

        while i < len_L:
            self.sorting_array[k] = L[i]
            i += 1
            k +=1
        while j < len_R:
            self.sorting_array[k] = R[j]
            j += 1
            k += 1

    def heap_sort(self):
        self.build_max_heap()
        print(self.sorting_array)
        n = len(self.sorting_array)
        for i in range(n-1, 0, -1):
            value = self.sorting_array[i]
            self.sorting_array[i] = self.sorting_array[0]
            self.sorting_array[0] = value
            n = n - 1
            self.max_heapify(0, n)

    def build_max_heap(self):
        heap_size = len(self.sorting_array)
        for i in range(heap_size//2 - 1, -1, -1):
            self.max_heapify(i, heap_size)

    def max_heapify(self, i, heap_size):
        l =  2 * i + 1
        r =  2 * i + 2
        if l < heap_size and self.sorting_array[l] > self.sorting_array[i]:
            largest = l
        else:
            largest = i
        if l < heap_size:
            self.comparison_count += 1

        if r < heap_size and self.sorting_array[r] > self.sorting_array[largest]:
            largest = r
        if r < heap_size:
            self.comparison_count += 1

        if largest != i:
            value = self.sorting_array[i]
            self.sorting_array[i] = self.sorting_array[largest]
            self.sorting_array[largest] = value
            self.max_heapify(largest, heap_size)

    def insertion_sort(self):
        if len(self.sorting_array) < 2:
            return
        for i in range(1, len(self.sorting_array)):
            key = self.sorting_array[i]
            j = i - 1
            while j > -1 and self.sorting_array[j] > key:
                self.comparison_count += 1
                self.sorting_array[j+1] = self.sorting_array[j]
                j = j - 1
            if j > -1:
                self.comparison_count += 1
            self.sorting_array[j + 1] = key
