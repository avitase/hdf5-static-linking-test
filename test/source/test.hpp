#pragma once

#include <cstdint>
#include <string>

namespace hdf5_static_linking_test
{

[[nodiscard]] std::size_t get_size(const std::string &file_name,
                                   const std::string &dataset_name);

} // namespace hdf5_static_linking_test
