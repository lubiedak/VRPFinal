/*
 * ProgressLogger.cpp
 *
 *  Created on: 24 Feb 2016
 *      Author: lubiedak
 */

#include "ProgressLogger.h"
#include <string>
#include <iostream>


ProgressLogger::ProgressLogger(int problemSize, int steps): problemSize(problemSize), steps(steps), nextLevel(0) {
}

ProgressLogger::ProgressLogger(int problemSize): ProgressLogger(problemSize, 10) {
}


ProgressLogger::~ProgressLogger() {
}

void ProgressLogger::startLog() {
  std::string header = "\n|";
  for(int i = 0; i < steps; ++i){
    header+=" ";
  }
  header+=" |\n ";
  std::cout<<header;
}

void ProgressLogger::logProgress(int progress) {
  if(progress>nextLevel){
    std::cout<<"*"<<std::flush;
    nextLevel+=problemSize/steps;
  }
}
