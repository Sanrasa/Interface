#ifndef COLLECTION_H
#define COLLECTION_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <interface.h>

using namespace std;

class Collection : public Interface
{
private:
    vector<string> movies;


public:
    Collection();
    string getMovie(long pos);
    void AdditionalInfo();
    vector<string> getMovieVector();
    void setMovie(string movieName);
    void setAuthorInfo(string authorName, long pos);
    void setYearInfo(string yearName, long pos);
    void setGenreInfo(string genreName, long pos);
    int numberOfMovies();
    void listMovies();
    string delMovie(long pos);
    void exportNoExtensionCollection(string fileName) override;
    void exportExtensionCollection(string fileName) override;
    string importNoExtensionCollection(string fileName) override;
    string importExtensionCollection(string fileName) override;
    void replace(long pos);
};

#endif // COLLECTION_H
