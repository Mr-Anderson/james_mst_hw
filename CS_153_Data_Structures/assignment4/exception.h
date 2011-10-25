#ifndef EXCEPTION_H
#define EXCEPTION_H
//////////////////////////////////////////////////////////////////////
/// @file exception.h
/// @author James Anderson  Section A
/// @brief Heder file for exception class for assignment 4
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @class exception
/// @brief Used to handel exceptions thrown in the code
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Exception::Exception (Error_Type _error_code, string _error_message)
/// @brief stores the exception name and an error message
/// @pre error code must be previously defined and the message must be a string
/// @post will store the parameters given to it
/// @param Error_Type _error_code stores the error code 
/// @param string _error_message holds a string with a message for the user
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Error_Type Exception::error_code ()
/// @brief gives back the Exception error code
/// @pre error code must be previously stored
/// @post feeds back error code
/// @return returns the Error code it has stored
////////////////////////////////////////////////////////////////////// 
//////////////////////////////////////////////////////////////////////
/// @fn Error_Type Exception::error_message ()
/// @brief gives back the Exception error message
/// @pre error message must be previously stored
/// @post feeds back error message
/// @return returns the Error message it has stored
////////////////////////////////////////////////////////////////////// 
#include <string>
using std::string;

enum Error_Type { CONTAINER_FULL, CONTAINER_EMPTY, OUT_OF_BOUNDS };

class Exception
{
  public:
    Exception (Error_Type, string);
    Error_Type error_code ();
    string error_message ();

  private:
    Error_Type m_error_code;
    string m_error_message;
};

#endif
