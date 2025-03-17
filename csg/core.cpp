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
        assert(graph.get_edge_lists()[a_id][0] == b_id);
        assert(graph.get_edge_lists()[b_id].empty());

        cout<<"add_di_edge() works"<<endl;
    }

    void test_add_bdi_edge(){
        Graph<string> graph;
        graph.add_bdi_edge("A", "B");

        auto a_id {graph.get_v_id("A")};
        auto b_id {graph.get_v_id("B")};
        assert(graph.get_edge_lists()[a_id][0] == b_id);
        assert(graph.get_edge_lists()[b_id][0] == a_id);

        cout<<"add_bdi_edge() works"<<endl;
    }

    void test_get_neighbors_id(){
        Graph<string> graph;
        graph.add_bdi_edge("A", "B");
        graph.add_bdi_edge("A", "C");
        graph.add_bdi_edge("A", "D");

        uint32_t a_id {graph.get_v_id("A")};
        uint32_t id {graph.get_v_id("B")};
        for (auto u : graph.get_neighbors_id(a_id)){
            assert(u == id);
            id++;
        }

        cout<<"get_neighbors_id() works"<<endl;
    }

    void test_compile(){
        Graph<string> graph;
        graph.get_v_id("D");
        graph.add_bdi_edge("A", "B");
        graph.add_bdi_edge("A", "C");
        graph.add_bdi_edge("A", "D");

        graph.compile();

        auto id {graph.get_v_id("A")};
        assert(graph.get_neighbors_id(id).capacity() == 3);
        auto d_id {graph.get_v_id("D")};
        assert(graph.get_neighbors_id(id)[0] == d_id);

        cout<<"compile() works"<<endl;
    }

    void test_has_edge_id(){
        Graph<string> graph;
        auto d_id {graph.get_v_id("D")};
        graph.add_bdi_edge("A", "B");
        graph.add_bdi_edge("A", "C");
        graph.add_bdi_edge("A", "D");

        auto a_id {graph.get_v_id("A")};
        auto b_id {graph.get_v_id("B")};

        assert(graph.has_edge_id(a_id, d_id));
        assert(!graph.has_edge_id(b_id, d_id));

        graph.compile();
        assert(graph.has_edge_id(a_id, d_id));
        assert(!graph.has_edge_id(b_id, d_id));

        cout<<"has_edge_id() works"<<endl;
    }

    void test_get_vertex_num(){
        Graph<string> graph;
        graph.add_bdi_edge("A", "B");
        graph.add_bdi_edge("A", "C");
        graph.add_bdi_edge("A", "D");

        assert(graph.get_vertex_num() == 4);

        cout<<"get_vertex_num() works"<<endl;
    }

    [[maybe_unused]]
    void it_works() {
        test_get_v_id();
        test_add_di_edge();
        test_add_bdi_edge();
        test_get_neighbors_id();
        test_compile();
        test_has_edge_id();
        test_get_vertex_num();
    }
}

