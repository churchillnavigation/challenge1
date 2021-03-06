#include "dll-main.hpp"
#include "result_queue.hpp"

search_structure* __stdcall create(identified_ranked_2d_point* points_begin, identified_ranked_2d_point* points_end)
{
    search_structure* data_structure = new(std::nothrow) search_structure(points_begin, points_end);
    return data_structure;
}

std::int32_t __stdcall search(search_structure* data_structure, bounding_box query_rectangle, std::int32_t count,
                              identified_ranked_2d_point* out_points) {
    result_queue results(count);
    data_structure->collect_points_in_rectangle(results, query_rectangle);
    std::size_t num_points = results.move_sorted_contents_to(out_points);
    return num_points;
}

search_structure* __stdcall destroy(search_structure* data_structure)
{
    delete data_structure;
    return nullptr;
}
