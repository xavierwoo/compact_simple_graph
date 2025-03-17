//
// Created by 吴 歆韵 on 2025/3/17.
//

#ifndef COMPACT_SIMPLE_GRAPH_CORE_H
#define COMPACT_SIMPLE_GRAPH_CORE_H

#include <unordered_map>
#include <vector>
#include <cstdint>
#include <cassert>

namespace csg{
    using std::vector, std::unordered_map;
    template<typename K, typename U = uint32_t>
    struct Graph{
        unordered_map<K, U> vertices_name_id_map;
        vector<vector<U>> edge_lists;

        auto get_v_id(const K&) -> U;
        void add_di_edge(const K&, const K&);
        void add_bdi_edge(const K&, const K&);

        auto get_neighbors_id(U v_id) -> const vector<U>&;
    };

    /***
     * Get the id of a vertex.
     * if it does not exist, then add it
     */
    template<typename K, typename U>
    auto Graph<K, U>::get_v_id(const K &v) -> U {
        auto id_iter {vertices_name_id_map.find(v)};
        if(id_iter != vertices_name_id_map.end()){
            return id_iter->second;
        }

        U id {(U)vertices_name_id_map.size()};
        vertices_name_id_map[v] = id;
        edge_lists.emplace_back();
        return id;
    }

    /***
     * Add a direct edge
     */
    template<typename K, typename U>
    void Graph<K, U>::add_di_edge(const K& source, const K& target) {
        auto s_id {get_v_id(source)};
        auto t_id {get_v_id(target)};

        edge_lists[s_id].push_back(t_id);
    }

    /***
     * Add a bi-direct edge
     */
    template<typename K, typename U>
    void Graph<K, U>::add_bdi_edge(const K& source, const K& target) {
        auto s_id {get_v_id(source)};
        auto t_id {get_v_id(target)};

        edge_lists[s_id].push_back(t_id);
        edge_lists[t_id].push_back(s_id);
    }

    template<typename K, typename U>
    auto Graph<K, U>::get_neighbors_id(U v_id) -> const vector<U> & {
        return edge_lists[v_id];
    }

    [[maybe_unused]]void it_works();
}

#endif //COMPACT_SIMPLE_GRAPH_CORE_H
