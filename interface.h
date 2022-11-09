#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

class Interface
{
public:
   virtual void exportNoExtensionCollection(std::string fileName) = 0;
   virtual std::string importNoExtensionCollection(std::string fileName) = 0;
   virtual void exportExtensionCollection (std::string fileName) = 0;
   virtual std::string importExtensionCollection (std::string fileName) = 0;
};

#endif // INTERFACE_H
