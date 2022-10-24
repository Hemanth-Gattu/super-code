# Python program to find bridges in a given undirected graph
#Complexity : O(V+E)

# Watch Jenny's lecture

from collections import defaultdict

# This class represents an undirected graph using adjacency list representation


class Graph:

    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph
        self.Time = 0

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    '''A recursive function that finds and prints bridges
	using DFS traversal
	u --> The vertex to be visited next
	visited[] --> keeps track of visited vertices
	disc[] --> Stores discovery times of visited vertices
	parent[] --> Stores parent vertices in DFS tree'''

    def bridgeUtil(self, u, visited, parent, low, disc):

        # Mark the current node as visited and print it
        visited[u] = True

        # Initialize discovery time and low value
        disc[u] = self.Time
        low[u] = self.Time
        self.Time += 1

        # Recur for all the vertices adjacent to this vertex
        for v in self.graph[u]:
            # If v is not visited yet, then make it a child of u
            # in DFS tree and recur for it
            if visited[v] == False:
                parent[v] = u
                print('forward', u,v)
                self.bridgeUtil(v, visited, parent, low, disc)

                print('backward', u,v)
                # Check if the subtree rooted with v has a connection to
                # one of the ancestors of u
                low[u] = min(low[u], low[v])

                # ''' If the lowest vertex reachable from subtree
                # under v is below u in DFS tree, then u-v is
                # a bridge'''
                if low[v] > disc[u]:
                    print("Bridges %d %d" % (u, v))
   
            # Update low value of u for parent function calls.
            elif v != parent[u]:
                low[u] = min(low[u], disc[v])

        # DFS based function to find all bridges. It uses recursive
        # function bridgeUtil()

    def bridge(self):

        # Mark all the vertices as not visited and Initialize parent and visited,
        # and ap(articulation point) arrays
        visited = [False] * (self.V)
        disc = [float("Inf")] * (self.V)
        low = [float("Inf")] * (self.V)
        parent = [-1] * (self.V)
        # Call the recursive helper function to find bridges
        # in DFS tree rooted with vertex 'i'
        for i in range(self.V):
            if visited[i] == False:
                self.bridgeUtil(i, visited, parent, low, disc)


# Create a graph given in the above diagram
# g1 = Graph(5)
# g1.addEdge(1, 0)
# g1.addEdge(0, 2)
# g1.addEdge(2, 1)
# g1.addEdge(0, 3)
# g1.addEdge(3, 4)

g1 = Graph(12)
g1.addEdge(1, 0)
g1.addEdge(2, 1)
g1.addEdge(2, 3)
g1.addEdge(0, 3)
g1.addEdge(3, 4)
g1.addEdge(4, 5)
g1.addEdge(8, 5)
g1.addEdge(6, 5)
g1.addEdge(7, 8)
g1.addEdge(7, 6)
g1.addEdge(7, 9)
g1.addEdge(10, 9)
g1.addEdge(11, 9)
g1.addEdge(11, 10)


print("Bridges in first graph ")
g1.bridge()

# g2 = Graph(4)
# g2.addEdge(0, 1)
# g2.addEdge(1, 2)
# g2.addEdge(2, 3)
# print ("\nBridges in second graph ")
# g2.bridge()


# g3 = Graph (7)
# g3.addEdge(0, 1)
# g3.addEdge(1, 2)
# g3.addEdge(2, 0)
# g3.addEdge(1, 3)
# g3.addEdge(1, 4)
# g3.addEdge(1, 6)
# g3.addEdge(3, 5)
# g3.addEdge(4, 5)
# print ("\nBridges in third graph ")
# g3.bridge()

# Time Complexity: O(E*(V+E)) for a graph represented using adjacency list.

# Efficient Approach:  The idea is similar to O(V+E) algorithm for Articulation Points. We do DFS traversal of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v.

# Auxiliary Space: O(B^M) where B is the maximum branching factor of the search tree and M is the maximum depth of the state space.
