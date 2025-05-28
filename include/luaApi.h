#ifndef LUA_H
#define LUA_H

#include <functional>

void initLua();
void setLuaFunc(const char* string);
std::function<float(float)> getLuaFunc();

#endif