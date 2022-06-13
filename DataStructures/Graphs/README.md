# Graphs
Flexible data structures typically used to model problems defined in terms of relationships or connections between objects. Objects are represented by verti-ces, and the relationships or connections between the objects are represented by edges between the vertices.
## Search methods
Techniques for visiting the vertices of a graph in a specific order. Generally, either breadth-first or depth-first searches are used. Many graph algorithms are based on these basic methods of systematically exploring a graph’s vertices.
## Graph Example: Counting Network Hops
Graphs play an important part in solving many networking problems. One problem, for example, is determining the best way to get from one node to another in an internet, a network of gateways into other networks. One way to model an internet is using an undirected graph in which vertices represent nodes, and edges represent connections between the nodes. With this model, we can use breadthfirst search to help determine the smallest number of traversals, or hops, between various nodes.
