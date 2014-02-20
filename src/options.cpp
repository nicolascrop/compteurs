#include "include/options.h"

namespace cpt{

  Options::Options(int argc, char** argv)
  {
    this->error_ = SUCCESS;
    try
    {
      /** Define and parse the program options*/
      namespace po = boost::program_options;
      po::options_description desc("Options");
      desc.add_options()
        ("infile,i", po::value<std::string>(&this->infile_)->required(), "Fichier d'entrée")
        ("configfile,c", po::value<std::string>(&this->cfgfile_)->required(), "Fichier de config")
        ("outfile,o", po::value<std::string>(&this->outfile_)->required(), "Fichier de sortie");

      po::variables_map vm;
      try
      {
        po::store(po::parse_command_line(argc, argv, desc), vm); // can throw

        po::notify(vm);
      }
      catch(po::error& e)
      {
        std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
        std::cerr << desc << std::endl;
        this->error_ = ERROR_IN_COMMAND_LINE;
      }
    }
    catch(std::exception& e)
    {
      std::cerr << "Unhandled Exception reached the top of main: " 
              << e.what() << ", application will now exit" << std::endl; 
      this->error_ = ERROR_UNHANDLED_EXCEPTION; 
    }
  }

  size_t
  Options::getError()
  {
    return this->error_;
  }

  Options::~Options()
  {

  }
}
