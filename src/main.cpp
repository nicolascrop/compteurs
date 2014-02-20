#include "include/options.h"

int main(int argc, char** argv)
{
  cpt::Options opt(argc, argv);
  if (opt.getError() > 0)
    return opt.getError();
}
