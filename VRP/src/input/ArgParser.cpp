#include "ArgParser.h"
#include "FileDirChecker.h"

#include <iostream>

ArgParser::ArgParser(void)
{
}

ArgParser::ArgParser(int argc, char** argv):
    argc_(argc)
{
    argc_-=(argc_>0);
    argv+=(argc_>0);

    option::Stats stats_(usage, argc_, argv);
    options_ = new option::Option[stats_.options_max];
    buffer_  = new option::Option[stats_.buffer_max];
    option::Parser parser_(usage, argc_, argv, options_, buffer_);
}

ArgParser::~ArgParser(void)
{
    delete[] options_;
    delete[] buffer_;
}

bool ArgParser::isParsingSuccessful()
{
    if (parser_.error())
    {
        std::cout<<"Parsing failed"<<std::endl;
        return false;
    }
    else
    {
    	std::cout<<"Parsing passed"<<std::endl;
    }

    if (options_[HELP] || argc_ == 0)
    {
        option::printUsage(std::cout, usage);
        return false;
    }
    return true;
}

bool ArgParser::checkArgumentsCorrectness()
{
    bool success = true;
    for (option::Option* opt = options_[UNKNOWN]; opt; opt = opt->next())
        std::cout << "Unknown option: " << std::string(opt->name,opt->namelen) << "\n";

    for (int i = 0; i < parser_.nonOptionsCount(); ++i)
        std::cout << "Non-option #" << i << ": " << parser_.nonOption(i) << "\n";


    for(int type = POINTS; type <= WORKSPACE; type++)
    {
        option::Option* opt = options_[type];
        if(!opt)
        {
        	std::cout<<"Missing argument type: "<<usage[type].help<<std::endl;
            if(type == POINTS) //required arguments
            {
                success = false;
                std::cout<<"ERROR: missing required arguments to run application"<<std::endl;
            }
        }
    }
    return success;
}

bool ArgParser::checkIfFilesExists()
{
    bool success = true;
    std::cout<<"Start checking arguments ..."<<std::endl;

    FileDirChecker fileDirChecker;
    for(int type = POINTS; type < WORKSPACE; type++)
    {
        for( option::Option* opt = options_[type]; opt; opt = opt->next())
        {
        	std::cout<<"Checking: "<<opt->name<<std::endl;
            if (!fileDirChecker.isFileEnabled(opt->arg))
            {
            	std::cout<<"ERROR: file path: "<<opt->arg<<" for argument: "<<opt->name<<" not exist"<<std::endl;
                success = false;
            }
        }
    }

    option::Option* opt = options_[WORKSPACE];
    if(!fileDirChecker.isDirEnabled(opt->arg))
    {
    	std::cout<<"ERROR: dir path: "<<opt->arg<<" for argument: "<<opt->name<<" not exist"<<std::endl;
        success = false;
    }

    return success;
}

bool ArgParser::parse()
{
    bool success = false;
    if( isParsingSuccessful() )
    {
        if( checkArgumentsCorrectness() )
        {
            success = checkIfFilesExists();
        }
    }
    return success;
}


option::Option* ArgParser::getOptions()
{
    return options_;
}
