#ifndef XLY_MAIN_HPP
#define XLY_MAIN_HPP
#include <map>
#include <string>
typedef int fmain();
struct smain
{
    static std::map<std::string, fmain *> menu;
    smain(const std::string &name, fmain *prog) { menu[name] = prog; }
};
std::map<std::string, fmain *> smain::menu = std::map<std::string, fmain *>();
#endif
