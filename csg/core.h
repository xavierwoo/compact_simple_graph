//
// Created by 吴 歆韵 on 2025/3/17.
//

#ifndef COMPACT_SIMPLE_GRAPH_CORE_H
#define COMPACT_SIMPLE_GRAPH_CORE_H

#include <unordered_map>
#include <vector>
#include <cstdint>

namespace csg{
    using std::vector, std::unordered_map;
    template<typename K, typename U = uint32_t>
    struct Graph{
        unordered_map<K, U> vertices_name_id_map;
        vector<vector<U>> edge_lists;

        auto get_v_id(const K &v) -> U;
    };

    template<typename K, typename U>
    auto Graph<K, U>::get_v_id(const K &v) -> U {
        auto id_iter {vertices_name_id_map.find(v)};
        if(id_iter != vertices_name_id_map.end()){
            return id_iter->second;
        }

        U id {(U)vertices_name_id_map.size()};
        vertices_name_id_map[v] = id;
        return id;
    }

    [[maybe_unused]]void it_works();
}

#endif //COMPACT_SIMPLE_GRAPH_CORE_H
