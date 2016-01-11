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
  ;    return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires an argument\n");
    return option::ARG_ILLEGAL;
  }
};

enum  optionIndex { UNKNOWN, HELP, POINTS, COST, FLEET, SETUP, WORKSPACE };
const option::Descriptor usage[] =
{
    {UNKNOWN,  0,"" , ""    ,option::Arg::None, "USAGE: VRPCore [options]\n\nOptions:" },
    {HELP,     0,"" , "help",option::Arg::Optional,  "  --help           \tPrint usage and exit." },
    {POINTS,   0,"p", "points",option::Arg::Optional,        "  --points,    -p  \tPoints file path. (MANDATORY)" },
    {COST,     0,"c", "cost",option::Arg::Optional,  "  --cost,      -c  \tCost file path." },
    {FLEET,    0,"f", "fleet",option::Arg::Optional, "  --fleet,     -f  \tCities file path." },
    {SETUP,    0,"s", "setup",option::Arg::Optional, "  --setup,     -s  \tSetup file path." },
    {WORKSPACE,0,"w", "workspace",option::Arg::Optional,     "  --workspace, -w  \tWorkspace dir path." },
    {UNKNOWN,  0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
                                            "  VRPCore --points=points_file --workspace=workspace_dir\n"
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

