#ifndef STRINGUTILS_H_9OMRNF85
#define STRINGUTILS_H_9OMRNF85

#include <vector>
#include <string>


namespace msgl { namespace core {

//vector<string> splitString(string input, string delimiters);
extern std::vector<std::string> splitString(std::string, std::string delimiters);
extern std::vector<std::string> splitString(unsigned char* input, std::string delimiters);
	
}} //NAMESPACE

#endif /* end of include guard: STRINGUTILS_H_9OMRNF85 */
