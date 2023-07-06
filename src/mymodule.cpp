#include <lua.hpp>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <iostream>

namespace mymodule
{
    void say_hello_to(std::string name)
    {
        std::cout << "Hello, " << name << "!\n";
    }

    sol::table open_mymodule(sol::this_state L)
    {
        auto lua = sol::state_view(L);
        sol::table module = lua.create_table();

        module["say_hello_to"] = say_hello_to;

        return module;
    }
}

extern "C" int luaopen_mymodule(lua_State *L)
{
    return sol::stack::call_lua(L, 1, mymodule::open_mymodule);
}
