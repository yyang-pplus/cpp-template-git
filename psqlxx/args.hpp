#pragma once

#include <cxxopts.hpp>


namespace psqlxx {

[[nodiscard]] cxxopts::Options CreateBaseOptions() noexcept;

void HandleBaseOptions(const cxxopts::Options &options,
                       const cxxopts::ParseResult &parsed_options) noexcept;

} //namespace psqlxx
