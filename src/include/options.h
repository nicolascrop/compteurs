/**
 * \file options.h
 * \brief Permet de parser les options à l'aide de boost program Option
 * \author Nicolas Crop
 * \version 0.1
 */

#ifndef OPTIONS_H
  #define OPTIONS_H

  #include <iostream>
  #include <string>
  #include <boost/program_options.hpp>

  namespace cpt{

    const size_t ERROR_IN_COMMAND_LINE = 1; 
    const size_t SUCCESS = 0; 
    const size_t ERROR_UNHANDLED_EXCEPTION = 2; 

/**
 * \class Options
 * \brief Permet de parser les options
 * La classe se charge de lire la ligne de commande et de répartir en fonction
 */
    class Options{

      public:
      /**
       * \brief Constructeur
       * \param argc: Nombre de paramètres
       * \param argv: Tableaux des paramètres
       */
      Options(int argc, char** argv);
      /**
       * \brief Récup-re le code de l'erreur
       */
      size_t getError();
      /**
       * \brief Destructeur
       */
      ~Options();
      private:
        std::string infile_;
        std::string outfile_;
        std::string cfgfile_;
        size_t error_;
    };

  }
#endif
