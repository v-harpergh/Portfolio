module;

#include <string>

export module constants;

export namespace constants {

constexpr std::string_view title = "Submarine Adventure";

namespace window {

constexpr int x = 640;
constexpr int y = 360;

} // namespace window

constexpr int tile_size = 40;


} // namespace constants