#pragma once
#include <string>
class FileUtils {
public:

  FileUtils(void);
  ~FileUtils(void);

  bool isFileEnabled(const char * name);
  bool isDirEnabled(const char * pathname);
  void saveToFile(const std::string& fullName, std::string what);
};

