/*
 * ProgressLogger.h
 *
 *  Created on: 24 Feb 2016
 *      Author: lubiedak
 */

#ifndef SOLVER_PROGRESSLOGGER_H_
#define SOLVER_PROGRESSLOGGER_H_

class ProgressLogger {
public:
  ProgressLogger(int problemSize);
  ProgressLogger(int problemSize, int steps);
  virtual ~ProgressLogger();
  void startLog();
  void logProgress(int progress);

private:
  int problemSize;
  int steps;
  int nextLevel;
};

#endif /* SOLVER_PROGRESSLOGGER_H_ */
