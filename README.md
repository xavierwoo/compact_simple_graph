# Compact Simple Graph lib

This is an adjacency list implementation for simple direct graph.

This is an auxiliary lib for my other projects

## Usage

```c++
#include <csg/core.h> //header file for Compact Simple Graph
#include <cassert>
#include <iostream>

int main(){
    csg::Graph<string> graph;
    
    //Use add_di_edge() to add a directed edge between two vertices
    //Vertices added automatically when adding an edge
    graph.add_di_edge("A", "B");
    
    //Use get_v_id to get the ID of a vertex
    auto a_id {graph.get_v_id("A")};
    auto b_id {graph.get_v_id("B")};
    
    //If the vertex does not exist, get_v_id will add it
    auto c_id {graph.get_v_id("C")};
    
    //Use has_edge_id to check if a directed edge exists
    assert(graph.has_edge_id(a_id, b_id));
    
    //Use get_neighbors to obtain IDs of all adjacent vertices
    for (auto u : graph.get_neighbors_id(a_id)){
        std::cout<<u<<" ";
    }
    
    //add_bdi_edge adds two edges of both direction bewteen two vertices
    graph.add_bdi_edge("B", "C");
    assert(graph.has_edge_id(b_id, c_id));
    assert(graph.has_edge_id(c_id, b_id));
    return 0;
}
```

## Add CSG to your project using CMake

Consult the following CMakeLists.txt to see how to include the lib to your project using CMake.

```cmake
cmake_minimum_required(VERSION 3.29)
project(your_project)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        compact_simple_graph
        GIT_REPOSITORY https://github.com/xavierwoo/compact_simple_graph.git
        GIT_TAG v0.1.0  # Specify the Git tag here
)

FetchContent_MakeAvailable(compact_simple_graph)

add_executable(your_project main.cpp)

target_link_libraries(your_project compact_simple_graph)
```

## More Compact Adjacency list

If you are sure that the number of vertices are within a small range.
You can specify the second template parameter when declare the graph.
For example:

```c++
csg::Graph<string, uint8_t> graph
```

