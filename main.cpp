#include "Boot.h"

int main(int argc, char *argv[]) {
    boot::Main* m= new boot::Main();
    return  m->main(stoi(argv[1]));
}
