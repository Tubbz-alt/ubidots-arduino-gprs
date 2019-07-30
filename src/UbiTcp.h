/*
Copyright (c) 2013-2019 Ubidots.
Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:
The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Developed and maintained by Jose Garcia for IoT Services Inc
@jotathebest at github: https://github.com/jotathebest
*/

#ifndef _UbiTcp_H_
#define _UbiTcp_H_

#include <Stream.h>
#include "UbiProtocol.h"
#include "UbiTypes.h"

class UbiTcp : public UbiProtocol {
 public:
  UbiTcp(const char* token);
  UbiTcp(const int port, const char* user_agent, const char* token);
  UbiTcp(const char* user_agent, const char* token);
  UbiTcp(const char* host, const int port, const char* user_agent,
         const char* token);
  void add(char* variable_label, float value);
  void add(char* variable_label, float value, char* context);
  void add(char* variable_label, float value, char* context,
           unsigned long dot_timestamp_seconds);
  void add(char* variable_label, float value, char* context,
           unsigned long dot_timestamp_seconds,
           unsigned int dot_timestamp_millis);
  void addContext(char* key_label, char* key_value);
  void getContext(char* context_result);
  /* Abstract methods */
  bool sendData(const char* device_label, const char* device_name,
                const char* payload);
  float get(const char* device_label, const char* variable_label);
  ~UbiTcp();

 private:
  const char* _host;
  const char* _user_agent;
  const char* _token;
  int _port;
  uint8_t _currentDotValue = 0;
  uint8_t _currentContextValue = 0;
  void _buildTcpPayload(Dot* dot);
};

#endif