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


    [[maybe_unused]]
    void it_works() {
        test_get_v_id();
    }
}

