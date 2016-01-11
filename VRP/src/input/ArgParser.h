#pragma once

#include "optionparser.h"
#include <fstream>

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

enum  optionIndex { UNKNOWN, HELP, INPUT, RANDOM, TEST, DEBUG, WORKSPACE };
const option::Descriptor usage[] =
{
    {UNKNOWN,  0,"" , ""    ,  option::Arg::None, "USAGE: VRPCore [options]\n\nOptions:" },
    {HELP,     0,"h", "help",  option::Arg::Optional, "  --help       -h  \tPrint usage and exit." },
    {INPUT,    0,"i", "input", option::Arg::Optional, "  --input,     -i  \tPoints file path. (MANDATORY)" },
    {RANDOM,   0,"r", "random",option::Arg::Optional, "  --random,    -r  \tCost file path." },
    {TEST,     0,"t", "test",  option::Arg::Optional, "  --test,      -t  \tCities file path." },
    {DEBUG,    0,"d", "debug", option::Arg::Optional, "  --debug,     -d  \tSetup file path." },
    {WORKSPACE,0,"w", "workspace",option::Arg::Optional,     "  --workspace, -w  \tWorkspace dir path." },
    {UNKNOWN,  0,"" ,  ""   ,  option::Arg::None, "\nExamples:\n"
                                            "  VRPCore2.0 --input=input_file --workspace=workspace_dir\n"
                                            "  VRPCore -ppoints_file -wworkspace_dir\n" },
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

