class SegmentTree:

    def _init_(self, A, comparision):
        self.maxSize = len(A)
        self.A = A
        self.maxSizeSeg = self.maxSize * 4
        self.segTree = [-1] * self.maxSizeSeg
        self.func = comparision
        self.__build_segTree(1, 0, self.maxSize - 1)

    def __build_segTree(self, treeIndex, left, right):
        if left == right:
            self.segTree[treeIndex] = self.A[left]
        else:
            mid = left + (right - left) // 2
            self.__build_segTree(treeIndex * 2, left, mid)
            self.__build_segTree(treeIndex * 2 + 1, mid + 1, right)
            self.segTree[treeIndex] = self.func(self.segTree[treeIndex * 2], self.segTree[treeIndex * 2 + 1])

    def updateValue(self, updateIndex, value):
        self.__update_segTree(1, 0, self.maxSize - 1, updateIndex, value)

    def __update_segTree(self, treeIndex, left, right, updateIndex, value):
        if left == right:
            self.segTree[treeIndex] = value
        else:
            mid = left + (right - left) // 2
            if updateIndex <= mid:
                self.__update_segTree(treeIndex * 2, left, mid, updateIndex, value)
            else:
                self.__update_segTree(treeIndex * 2 + 1, mid + 1, right, updateIndex, value)
            self.segTree[treeIndex] = self.func(self.segTree[treeIndex * 2], self.segTree[treeIndex * 2 + 1])

    def query(self, leftR, rightR):
        return self.__query_segTree(leftR, rightR, 1, 0, self.maxSize - 1)

    def __query_segTree(self, leftR, rightR, treeIndex, left, right):
        if left == right:
            return self.segTree[treeIndex]
        else:
            mid = left + (right - left) // 2
            if left >= leftR and right <= rightR:
                return self.segTree[treeIndex]
            if leftR <= mid and rightR > mid:
                return self.func(self.__query_segTree(leftR, mid, treeIndex * 2, left, mid),
                                 self.__query_segTree(mid + 1, rightR, treeIndex * 2 + 1, mid + 1, right))
            elif rightR <= mid:
                return self.__query_segTree(leftR, rightR, treeIndex * 2, left, mid)
            else:
                return self.__query_segTree(leftR, rightR, treeIndex * 2 + 1, mid + 1, right)


class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return a list of integers
    def solve(self, A, B):
        A = [0] * A
        seg = SegmentTree(A, lambda a, b: a + b)

        queries = len(B)
        out = []
        for i in range(queries):
            query = B[i]
            queryType = query[0]
            if queryType == 1:
                index = query[1] - 1
                A[index] += 1
                seg.updateValue(index, A[index])
            elif queryType == 2:
                index = query[1] - 1
                if A[index] != 0:
                    A[index] -= 1
                    seg.updateValue(index, A[index])
            else:
                L = query[1] - 1
                R = query[2] - 1
                out.append(seg.query(L, R))
        return out