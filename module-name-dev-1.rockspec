package = "module-name"
version = "dev-1"
local is_dev = version:match("dev%-(%d+)")
source = {
   url = "git+https://github.com/MyUser/MyRepo.git",
   tag = is_dev and nil or version:gsub("%-.*$", ""),
}
description = {
   homepage = "https://github.com/MyUser/MyRepo",
   license = "MIT/X11"
}
dependencies = {
   "lua >= 5.1, < 5.5"
}
build = {
   type = "cmake",
   variables = {
      BUILD_SHARED_LIBS = "ON",
      CMAKE_INSTALL_PREFIX = "$(PREFIX)",
      LUA_INCLUDE_DIR = "$(LUA_INCDIR)",
      MODULE_IS_DEV = is_dev and "ON" or "OFF",
      MODULE_NAME = "mymodule"
   },
}
