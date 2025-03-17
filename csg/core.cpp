//
// Created by 吴 歆韵 on 2025/3/17.
//
#include "core.h"
#include <string>
#include <cassert>
#include <iostream>

namespace csg{
    using std::string, std::cout, std::endl;

    void test_get_v_id(){
        Graph<string> graph;
        auto id {graph.get_v_id("A")};
        assert(id == 0);
        id = graph.get_v_id("B");
        assert(id == 1);
        id = graph.get_v_id("A");
        assert(id == 0);

        cout<<"get_v_id() works"<<endl;
    }

    void test_add_di_edge(){
        Graph<string> graph;
        graph.add_di_edge("A", "B");

        auto a_id {graph.get_v_id("A")};
        auto b_id {graph.get_v_id("B")};
        assert(graph.edge_lists[0][0] == 1);
        assert(graph.edge_lists[1].empty());

        cout<<"add_di_edge() works"<<endl;
    }

    void test_add_bdi_edge(){
        Graph<string> graph;
        graph.add_bdi_edge("A", "B");

        auto a_id {graph.get_v_id("A")};
        auto b_id {graph.get_v_id("B")};
        assert(graph.edge_lists[0][0] == 1);
        assert(graph.edge_lists[1][0] == 0);

        cout<<"add_bdi_edge() works"<<endl;
    }

    [[maybe_unused]]
    void it_works() {
        test_get_v_id();
        test_add_di_edge();
        test_add_bdi_edge();
    }
}

