//
// Created by 吴 歆韵 on 2025/3/17.
//
#include "core.h"
#include <string>
#include <cassert>

namespace csg{
    using std::string;

    void test_get_v_id(){
        Graph<string> graph;
        auto id {graph.get_v_id("A")};
        assert(id == 0);
        id = graph.get_v_id("B");
        assert(id == 1);
        id = graph.get_v_id("A");
        assert(id == 0);
    }


    [[maybe_unused]]
    void it_works() {
        test_get_v_id();
    }
}

