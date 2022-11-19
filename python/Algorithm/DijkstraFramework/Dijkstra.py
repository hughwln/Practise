#DO NOT CHANGE ANY EXISTING CODE IN THIS FILE
class Dijkstra:

    def Dijkstra_alg(self, n, e, mat, s):
        #Write your code here to calculate shortest paths and usp values from source to all vertices
        #This method will have four inputs (Please see testcase file)
        #This method should return a two dimensional array as output (Please see testcase file)

        # Initialize
        S = []
        d = []
        p = []
        usp = []
        Q = []
        m = sum(mat[i][2] for i in range(e)) + 1
        for i in range(n+1):
            d.append(m)
            p.append(0)
            usp.append(1)
            Q.append(i)
        d[s] = 0

        while(len(Q)>1):
            # EXTRACT-MIN
            min_d = m
            u = 0
            for v in Q:
                if d[v] < min_d:
                    min_d = d[v]
                    u = v

            # add u to S
            S.append(u)
            Q.remove(u)

            for i in range(e):
                if mat[i][0] == u:
                    v = mat[i][1]
                elif mat[i][1] == u:
                    v = mat[i][0]
                else:
                    continue

                if v in Q:
                    if d[u] + mat[i][2] == d[v]:
                        usp[v] = 0
                    elif d[u] + mat[i][2] < d[v]:
                        d[v] = d[u] + mat[i][2]
                        p[v] = u

        Res = []
        for i in range(n):
            Res.append([d[i+1], usp[i+1]])
        return Res
