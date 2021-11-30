#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MapReadsPlugin.h"

void MapReadsPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key;
   ifile >> key;
   if (key.length() > 0)
   files.push_back(key);
   }
 }


void MapReadsPlugin::run() {
   
}

void MapReadsPlugin::output(std::string file) {
 // spades.py -o 02_MapReads -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
 // bwa mem -t 4 Assembly.fasta shortreads1.fastq shortread2.fastq | samtools sort > assembly_map_short-reads.bam
	std::string command = "bwa mem -t 4 ";
	for (int i = 0; i < files.size(); i++) {
		command += std::string(PluginManager::prefix())+"/"+files[i];
	        command += " ";
	}
	command += "| samtools sort > ";
	command += file;
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<MapReadsPlugin> MapReadsPluginProxy = PluginProxy<MapReadsPlugin>("MapReads", PluginManager::getInstance());
