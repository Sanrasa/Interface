#include "genre.h"

Genre::Genre()
{
    this->setMovie("The terminator 1");
    this->setAuthorInfo("James", 1);
    this->setYearInfo("1984", 1);
    this->setGenreInfo("Action", 1);
    this->setMovie("The terminator 2");
    this->setAuthorInfo("James", 2);
    this->setYearInfo("1991", 2);
    this->setGenreInfo("Action", 2);
}

void Genre::AdditionalInfo()
{
    vector<string> movies = this->getMovieVector();
    if (movies.size() == 0)
    {
        cout << endl << "list is empty(" << endl << endl;
    }
    else
    for(string movie : movies)
        cout << movie << endl;
    system ("PAUSE");
    return;
}
