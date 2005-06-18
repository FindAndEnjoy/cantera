/**
 * @file global.h
 *
 * These functions handle various utility functions, and store 
 * some parameters in 
 * global storage that are accessible at all times. 
 *  
 */

/* $Author$
 * $Revision$
 * $Date$
 */

// Copyright 2001  California Institute of Technology

#ifndef CT_GLOBAL_H
#define CT_GLOBAL_H

#include <string>
#include "ct_defs.h"

namespace Cantera {

    class XML_Node;
    class Logger;

    /// Number of errors that have been encountered so far
    int nErrors();

    /// The last error message
    string lastErrorMessage();

    /// Add an error message
    void setError(string r, string msg);

    /// Print the error messages to stream f
    void showErrors(ostream& f);

    /// Print the error messages using function writelog.
    void showErrors();

    /// Discard the last error message
    void popError();

    /// Find an input file.
    string findInputFile(string name);

    void addDirectory(string dir);

    void appdelete();

    /// The root directory where Cantera is installed
    string canteraRoot();

    /// Set the temporary file directory. The default is to use the 
    /// directory specified by enviroment variable TMP or TEMP. If neither 
    /// of these are defined, then the current working directory will be 
    /// used for temporary files. Call this function to specify some other
    /// place to put temporary files.
    void setTmpDir(string tmp);

    /// The directory where temporary files may be created
    string tmpDir();

    /// Delay time in seconds.
    string sleep();

    void writelog(const string& msg);

    void writelog(const char* msg);

    void error(const string& msg);

    // returns 1 for MATLAB, 2 for Python, and 0 for C++ or Fortran.
    int userInterface();

    void setLogger(Logger* logwriter);

    /// Return the conversion factor to convert unit string 'unit' to
    /// SI units.
    doublereal toSI(string unit);

    /// Return the conversion factor to convert activation energy unit
    /// string 'unit' to Kelvin.
    doublereal actEnergyToSI(string unit);

    /// Return a pointer to the XML tree for a Cantera input file. 
    XML_Node* get_XML_File(string file);

    /// Close a Cantera input file.
    void close_XML_File(string file);

    void beginLogGroup(string title, int loglevel=1);
    void addLogEntry(string tag, string value, int loglevel=1);
    void endLogGroup(int loglevel=1);
    void write_logfile(string file = "log.html");
}

#endif
