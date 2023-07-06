#include <lua.hpp>

#include <iostream>

namespace mymodule
{
    int say_hello(lua_State *L)
    {
        const char *name = luaL_checkstring(L, 1);

        std::cout << "Hello, " << name << "!" << std::endl;

        return 0;
    }
}

static const luaL_Reg mymodule_lib[] = {
    { "say_hello", &mymodule::say_hello },
    { nullptr, nullptr }
};


extern "C" int luaopen_mymodule(lua_State *L)
{
    luaL_newlib(L, mymodule_lib);

    return 1;
}
