/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var neighbors: [Node?]
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.neighbors = []
 *     }
 * }
 */

class Solution {
        private var visited = [ObjectIdentifier: Node]()
 
    func cloneGraph(_ node: Node?) -> Node? {
         guard let node = node else { return nil }
        
        let id = ObjectIdentifier(node)
        if let existing = visited[id] { return existing }
        
        let clone = Node(node.val)
        visited[id] = clone
        
        for neighbor in node.neighbors {
            if let clonedNeighbor = cloneGraph(neighbor) {
                clone.neighbors.append(clonedNeighbor)
            }
        }
        return clone
    }
}