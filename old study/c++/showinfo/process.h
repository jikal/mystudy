#ifndef _PROCESS_H_
#define _PROCESS_H_

namespace iotek{

bool process_command_line(int argc, char *argv[]);
void output_information(bool has_name,char *name);
int get_age();

}
#endif
