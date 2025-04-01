#include <cstdint>
#include <string>

#include <hdf5.h>

#include "test.hpp"

namespace hdf5_static_linking_test
{

std::size_t get_size(const std::string &file_name,
                     const std::string &dataset_name)
{
    const auto file = H5Fopen(file_name.c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
    const auto dataset = H5Dopen(file, dataset_name.c_str(), H5P_DEFAULT);
    const auto dataspace = H5Dget_space(dataset);

    hsize_t size;
    H5Sget_simple_extent_dims(dataspace, &size, nullptr);

    H5Sclose(dataspace);
    H5Dclose(dataset);
    H5Fclose(file);

    return size;
}

} // namespace hdf5_static_linking_test
