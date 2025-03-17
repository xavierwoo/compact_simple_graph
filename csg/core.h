//
// Created by 吴 歆韵 on 2025/3/17.
//

#ifndef COMPACT_SIMPLE_GRAPH_CORE_H
#define COMPACT_SIMPLE_GRAPH_CORE_H

#include <unordered_map>
#include <vector>
#include <string>

namespace csg{
    using std::vector, std::unordered_map, std::string;
    template<typename U>
    struct graph{
        unordered_map<string, U> vertices_name_id_map;
        vector<vector<U>> edge_lists;
    };
}

#endif //COMPACT_SIMPLE_GRAPH_CORE_H
