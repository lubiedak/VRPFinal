#pragma once

#include <fstream>
#include "../io/optionparser.h"

struct Arg: public option::Arg
{
  static void printError(const char* msg1, const option::Option& opt, const char* msg2)
  {
    fprintf(stderr, "%s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
  }

  static option::ArgStatus Unknown(const option::Option& option, bool msg)
  {
    if (msg) printError("Unknown option '", option, "'\n");
    	return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Required(const option::Option& option, bool msg)
  {
    if (option.arg != 0)
       return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires an argument\n");
    	return option::ARG_ILLEGAL;
  }
};

enum  optionIndex { UNKNOWN, HELP, INPUT, OUTPUT, RANDOM, TEST, MICRO, DEBUG };
const option::Descriptor usage[] =
{
    {UNKNOWN,  0,"" , ""    ,       option::Arg::None,     "USAGE: VRPCore [options]\n\nOptions:" },
    {HELP,     0,"h", "help",       option::Arg::Optional, "  --help       -h  \tPrint usage and exit" },
    {INPUT,    0,"i", "inputFile",  option::Arg::Optional, "  --inputFile, -i  \tProblem file path" },
    {OUTPUT,   0,"o", "outputDir",  option::Arg::Optional, "  --outputDir, -o  \tDirectory, where output would be produced" },
    {RANDOM,   0,"r", "random",     option::Arg::Optional, "  --random,    -r  \tRunning VRP in Random mode. Solving n problems" },
    {TEST,     0,"t", "test",       option::Arg::Optional, "  --test,      -t  \tRunning VRP in test mode - running all tests" },
	  {MICRO,    0,"m", "micro",      option::Arg::Optional, "  --micro,     -m  \tRunning VRP in microservice mode - REST API available" },
    {DEBUG,    0,"d", "debug",      option::Arg::Optional, "  --debug,     -d  \tSetup file path" },
    {UNKNOWN,  0,"" ,  ""   ,       option::Arg::None, "\nExamples:\n"
                                            "  VRPCore2.0 --inputFile=input_file --outputDir=some_dir\n"
                                            "  VRPCore2.0 --random=20\n"
                                            "  VRPCore2.0 --test=true"},
    {0,0,0,0,0,0}
};

class ArgParser
{
public:

    ArgParser(void);
    ArgParser(int argc, char** argv);
    ~ArgParser(void);

    bool parse();
    option::Option* getOptions();
private:
    bool isParsingSuccessful();
    bool checkArgumentsCorrectness();
    bool checkIfFilesExists();

    int argc_;
    option::Option* options_;
    option::Parser parser_;
    option::Stats  stats_;
    option::Option* buffer_;
};

