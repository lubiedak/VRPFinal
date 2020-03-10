#include "../io/FileUtils.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <fstream>
#include <iostream>

FileUtils::FileUtils(void) {
}

FileUtils::~FileUtils(void) {
}

bool FileUtils::isFileEnabled(const char * name) {
  std::ifstream f(name);
  return f.good();
}

bool FileUtils::isDirEnabled(const char * pathname) {
  struct stat info;
  bool success = false;
  if (stat(pathname, &info) != 0) {
    std::cout << "cannot access " << pathname << std::endl;
  } else if (info.st_mode & S_IFDIR)  // S_ISDIR() doesn't exist on my windows
  {
    std::cout << pathname << " is a directory" << std::endl;
    success = true;
  } else {
    std::cout << pathname << " is not a directory" << std::endl;
  }
  return success;
}

void FileUtils::saveToFile(const std::string& fullName, std::string what){
  std::ofstream file;
  file.open((fullName).c_str());
  file << what;
  file.close();
}
