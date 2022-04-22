#pragma once

#include <string_view>


namespace psqlxx {

[[nodiscard]]
std::string_view GetVersion() noexcept;

[[nodiscard]]
std::string_view GetGitDescribe() noexcept;

}//namespace psqlxx
