#ifndef MAPREADSPLUGIN_H
#define MAPREADSPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class MapReadsPlugin : public Plugin
{
public: 
 std::string toString() {return "MapReads";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::vector<std::string> files;
};

#endif
