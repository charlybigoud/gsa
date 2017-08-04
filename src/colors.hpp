#pragma once

#include <string.h>

#include "utils.hpp"

namespace gsa
{
    struct Default{ const std::string value = "39"; };

    struct Black{ const std::string value = "30"; };
    struct Red{ const std::string value = "31"; };
    struct Green{ const std::string value = "32"; };
    struct Yellow{ const std::string value = "33"; };
    struct Blue{ const std::string value = "34"; };
    struct Magenta{ const std::string value = "35"; };
    struct Cyan{ const std::string value = "36"; };
    struct LightGray{ const std::string value = "37"; };

    struct DarkGray{ const std::string value = "90"; };

    struct LightRed{ const std::string value = "91"; };
    struct LightGreen{ const std::string value = "92"; };
    struct LightYellow{ const std::string value = "93"; };
    struct LightBlue{ const std::string value = "94"; };
    struct LightMagenta{ const std::string value = "95"; };
    struct LightCyan{ const std::string value = "96"; };

    template<typename Color>
    std::string color(const std::string& s)
    {
        return "\033[" + Color{}.value + "m" + s + "\033[0m";
    }

    template<typename Color, typename T>
    std::string color(const T& t)
    {
        return color<Color>( to_string(t) );
    }
}
